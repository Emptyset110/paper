// All-successor exploration (D3 item 2): BFS from the empty registry over
// both dimensions of nondeterminism — every enabled lifecycle/removal rule
// at every fiber, and every orchestration input the finite generator
// (catalog.mjs) offers. States are deduplicated on their canonical form
// (norm.mjs); the labeled transition graph records emissions, refusals,
// certificates, quiescence, and internal-cycle (divergence lasso) data.

import { createHash } from 'node:crypto'
import { snapshot, canonicalize, reorder, materialize } from './norm.mjs'
import { sigKey } from './sig.mjs'
import { CATALOG, buildSpec, ISO_SHAPES, CHILD_SHAPE, UPDATE_CFG, SETOWN } from './catalog.mjs'

const hash = s => createHash('md5').update(s).digest('base64')

/** Enumerate the actions available at a state; also collects disabled certs. */
export function enumerateActions(record, opts, disabledCollector) {
  const m = materialize(record)
  if (disabledCollector) m.cert = c => { if (c.decision === 'disabled') disabledCollector.push(c) }
  const actions = []
  const n = record.fibers.length
  const liveCount = record.fibers.filter(f => !f.removed).length

  // Internal: lifecycle rules and removals (certs for disabled ones emitted).
  for (let i = 0; i < n; i++) {
    const f = m.fibers.get(i + 1)
    if (f.removed) continue
    const rule = m.ruleFor(f)
    if (rule) actions.push({ t: 'life', f: i, rule: rule.ruleName })
  }
  for (let i = 0; i < n; i++) {
    const f = m.fibers.get(i + 1)
    if (f.removed || !f.retired) continue
    if (m.removeEligible(f)) actions.push({ t: 'remove', f: i })
  }

  // Orchestration inputs from the finite generator.
  const catalog = CATALOG.filter(s => opts.shapes.includes(s.id))
  for (const shape of catalog) {
    if (liveCount + shape.weight <= opts.maxFibers) {
      actions.push({ t: 'insert', shape: shape.id, ctx: 'root' })
    }
  }
  if (opts.isolate) {
    for (const id of ISO_SHAPES) {
      if (!opts.shapes.includes(id)) continue
      const shape = catalog.find(s => s.id === id)
      if (shape && liveCount + shape.weight <= opts.maxFibers) {
        actions.push({ t: 'insert', shape: id, ctx: 'iso' })
      }
    }
  }
  if (opts.childInserts && opts.shapes.includes(CHILD_SHAPE) && liveCount + 1 <= opts.maxFibers) {
    for (let i = 0; i < n; i++) {
      if (!record.fibers[i].removed) actions.push({ t: 'insert', shape: CHILD_SHAPE, ctx: 'child', f: i })
    }
  }
  for (let i = 0; i < n; i++) {
    const f = record.fibers[i]
    if (f.removed) continue
    if (!f.retired) actions.push({ t: 'retire', f: i })
    if (opts.updates) actions.push({ t: 'update', f: i })
    if (opts.setowns) actions.push({ t: 'setown', f: i })
  }
  return actions
}

/** Apply one action to a fresh materialization of `record`. */
export function applyAction(record, action, mutantOverride) {
  const m = materialize(record, mutantOverride !== undefined ? { mutant: mutantOverride } : {})
  const certs = []
  m.cert = c => certs.push(c)
  const t0 = m.trace.length
  let refused = false
  let refusalMessage = null
  try {
    switch (action.t) {
      case 'life': {
        const f = m.fibers.get(action.f + 1)
        const rule = m.ruleFor(f)
        if (!rule) { refused = true; refusalMessage = 'rule-disabled'; break }
        if (rule.ruleName !== action.rule) { refused = true; refusalMessage = `rule-mismatch:${rule.ruleName}`; break }
        rule()
        break
      }
      case 'remove': {
        const f = m.fibers.get(action.f + 1)
        if (!m.removeEligible(f)) { refused = true; refusalMessage = 'remove-ineligible'; break }
        m.removeOne(f)
        break
      }
      case 'insert': {
        let ctx = m.rootCtx
        if (action.ctx === 'iso') ctx = m.rootCtx.isolated('k1', 'r1')
        if (action.ctx === 'child') ctx = m.fibers.get(action.f + 1).ctx
        m.insert(ctx, buildSpec(action.shape, m.nextUid))
        break
      }
      case 'retire': m.retire(m.fibers.get(action.f + 1)); break
      case 'update': m.update(m.fibers.get(action.f + 1), { ...UPDATE_CFG }); break
      case 'setown': m.setOwn(m.fibers.get(action.f + 1), SETOWN.key, SETOWN.value); break
      default: throw new Error(`unknown action ${action.t}`)
    }
  } catch (error) {
    refused = true
    refusalMessage = String(error.message ?? error)
  }
  m.cert = null
  return { model: m, certs, emissions: m.trace.slice(t0), refused, refusalMessage }
}

const INTERNAL = new Set(['life', 'remove'])

export function explore(opts) {
  const started = Date.now()
  const options = {
    maxFibers: 4,
    shapes: CATALOG.map(s => s.id),
    isolate: true,
    childInserts: true,
    updates: true,
    setowns: true,
    maxStates: 400_000,
    timeBudgetMs: 15 * 60_000,
    ...opts,
  }

  const emptyRecord = { mutant: null, fibers: [] }
  const states = [] // id -> { depth, parent: {from, action} | null, internal: int[] }
  const records = new Map() // id -> canonical record (dropped after expansion)
  const idOf = new Map() // hash(canonKey) -> id
  const sigFirst = new Map() // sigKey -> { state, action, depth, decision }
  const sigCount = new Map() // sigKey -> occurrences over distinct edges
  let edgeCount = 0
  let refusalEdges = 0
  let quiescentCount = 0
  let truncated = false

  const intern = (record, depth, parent) => {
    const { key, perm } = canonicalize(record)
    const h = hash(key)
    let id = idOf.get(h)
    if (id === undefined) {
      id = states.length
      idOf.set(h, id)
      states.push({ depth, parent, internal: [], quiescent: false })
      records.set(id, reorder(record, perm))
      queue.push(id)
    }
    return id
  }

  const queue = []
  intern(emptyRecord, 0, null)
  let qhead = 0

  const noteCert = (cert, stateId, action, depth) => {
    const k = sigKey(cert)
    sigCount.set(k, (sigCount.get(k) ?? 0) + 1)
    if (!sigFirst.has(k)) {
      sigFirst.set(k, { state: stateId, action, depth, cert })
    }
  }

  while (qhead < queue.length) {
    if (states.length >= options.maxStates || Date.now() - started > options.timeBudgetMs) {
      truncated = true
      break
    }
    const id = queue[qhead++]
    const record = records.get(id)
    const depth = states[id].depth

    const disabled = []
    const actions = enumerateActions(record, options, disabled)
    for (const cert of disabled) noteCert(cert, id, null, depth)

    const hasInternal = actions.some(a => INTERNAL.has(a.t))
    if (!hasInternal) { states[id].quiescent = true; quiescentCount += 1 }

    for (const action of actions) {
      const { model, certs, refused } = applyAction(record, action)
      edgeCount += 1
      if (refused) refusalEdges += 1
      const succRecord = snapshot(model)
      delete succRecord.uids
      const succId = intern(succRecord, depth + 1, { from: id, action })
      for (const cert of certs) noteCert(cert, id, action, depth)
      if (INTERNAL.has(action.t) && !refused) states[id].internal.push(succId)
    }
    records.delete(id)
  }
  // States left in queue unexpanded (on truncation) keep their records dropped.
  records.clear()

  // Divergence: cycle detection on the internal-transition subgraph.
  const color = new Uint8Array(states.length)
  let internalCycle = false
  const stack = []
  for (let s = 0; s < states.length && !internalCycle; s++) {
    if (color[s]) continue
    stack.push([s, 0])
    color[s] = 1
    while (stack.length) {
      const top = stack[stack.length - 1]
      const [v] = top
      if (top[1] < states[v].internal.length) {
        const w = states[v].internal[top[1]++]
        if (color[w] === 1) { internalCycle = true; break }
        if (color[w] === 0) { color[w] = 1; stack.push([w, 0]) }
      } else {
        color[v] = 2
        stack.pop()
      }
    }
    stack.length = 0
  }

  return {
    options,
    stats: {
      normalizedStates: states.length,
      expandedStates: qhead,
      edges: edgeCount,
      refusalEdges,
      quiescentStates: quiescentCount,
      internalCycle,
      truncated,
      wallClockMs: Date.now() - started,
    },
    states,
    sigFirst,
    sigCount,
  }
}

/** Reconstruct the shortest access sequence (action list) to a state. */
export function pathTo(states, stateId) {
  const actions = []
  let cur = states[stateId]
  while (cur.parent) {
    actions.unshift(cur.parent.action)
    cur = states[cur.parent.from]
  }
  return actions
}
