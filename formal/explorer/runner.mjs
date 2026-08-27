// T_B script runner (D3 items 4 and 6).
//
// A generated test is (script, observation): the script is the shortest
// access sequence the explorer found — a list of orchestration inputs and
// scheduler-resolved lifecycle micro-steps — and the observation is
//   * the per-action record (refusals + emitted events + certificates), and
//   * the complete settle-outcome set from the final state: the set of
//     normalized quiescent reports over ALL schedules (true successor
//     enumeration of internal transitions), plus a divergence flag.
//
// The same runner executes a script against any mutant; a kill is any
// difference from the baseline observation.
//
// Fiber references inside actions are canonical positions of the state the
// action was generated at; the runner re-canonicalizes its concrete state
// before each action to resolve them (χ-invariant by construction).

import { snapshot, canonicalize, materialize } from './norm.mjs'
import { Model } from './model.mjs'
import { sigKey } from './sig.mjs'
import { buildSpec, UPDATE_CFG, SETOWN } from './catalog.mjs'

function resolveFiber(model, pos) {
  const rec = snapshot(model)
  const { perm } = canonicalize(rec)
  const recIdx = perm[pos]
  if (recIdx === undefined) return null
  return model.fibers.get(rec.uids[recIdx]) ?? null
}

/**
 * Replay a script; returns { perAction, final } where perAction[i] =
 * { refused, emissions, certs } and final is the live model.
 */
export function replayScript(actions, { mutant = null } = {}) {
  const m = new Model({ mutant })
  const perAction = []
  for (const action of actions) {
    const certs = []
    m.cert = c => { if (c.decision !== 'disabled') certs.push(sigKey(c)) }
    const t0 = m.trace.length
    let refused = false
    let note = null
    try {
      switch (action.t) {
        case 'insert': {
          let ctx = m.rootCtx
          if (action.ctx === 'iso') ctx = m.rootCtx.isolated('k1', 'r1')
          if (action.ctx === 'child') {
            const f = resolveFiber(m, action.f)
            if (!f) { refused = true; note = 'no-such-fiber'; break }
            ctx = f.ctx
          }
          if (action.ctx === 'child-uid') {
            // Coda-test form: address a fiber by raw uid so a REMOVED parent
            // (dropped from the canonical state) can still be targeted.
            const f = m.fibers.get(action.uid)
            if (!f) { refused = true; note = 'no-such-fiber'; break }
            ctx = f.ctx
          }
          m.insert(ctx, buildSpec(action.shape, m.nextUid))
          break
        }
        case 'iprobe': {
          // Coda action (pure coeffect operation, not part of the explored
          // LTS): evaluate a depth-2 intercept chain — Definition 31's
          // nearest-wins resolution — and record the merged result as an
          // observation.
          const ctx = m.rootCtx.intercepted('k1', { a: 1, b: 1 }).intercepted('k1', { b: 2, c: 2 })
          const f = m.insert(ctx, buildSpec('T', m.nextUid))
          const merged = m.interceptMerged(f, 'k1', { a: 0, base: true })
          m.trace.push(`intercept:${JSON.stringify(merged)}`)
          break
        }
        case 'rprobe': {
          // Coda action: the EXTERNAL Def.-23 read through a fiber's context
          // (Algorithm 6 invoked by the environment — the adapters' readVia).
          // The inactive-declared access class is only reachable this way in
          // the baseline: in-lifecycle reads always run under a committed
          // view that contains every declared key, and a registered child is
          // retired (hence diverted) before it can read a torn-down parent.
          const f = resolveFiber(m, action.f)
          if (!f) { refused = true; note = 'no-such-fiber'; break }
          try {
            const value = m.readCommitted(f, action.key)
            m.trace.push(`xread:${f.spec.name}:${action.key}=${JSON.stringify(value)}`)
          } catch (error) {
            m.trace.push(`xreadfail:${f.spec.name}:${action.key}:${error.code ?? 'ERR'}`)
          }
          break
        }
        case 'retire': case 'update': case 'setown': case 'life': case 'remove': {
          const f = resolveFiber(m, action.f)
          if (!f) { refused = true; note = 'no-such-fiber'; break }
          if (action.t === 'retire') m.retire(f)
          else if (action.t === 'update') m.update(f, { ...UPDATE_CFG })
          else if (action.t === 'setown') m.setOwn(f, SETOWN.key, SETOWN.value)
          else if (action.t === 'remove') {
            if (!m.removeEligible(f)) { refused = true; note = 'remove-ineligible'; break }
            m.removeOne(f)
          } else {
            const rule = m.ruleFor(f)
            if (!rule) { refused = true; note = 'rule-disabled'; break }
            if (rule.ruleName !== action.rule) { refused = true; note = `rule-mismatch:${rule.ruleName}`; break }
            rule()
          }
          break
        }
        default: throw new Error(`unknown action ${action.t}`)
      }
    } catch (error) {
      refused = true
      note = String(error.message ?? error)
    }
    m.cert = null
    perAction.push({ refused, note, emissions: m.trace.slice(t0), certs })
  }
  return { perAction, final: m }
}

// ---- settle-outcome sets ------------------------------------------------

function probeAll(model) {
  // Mirror sweep's per-iteration scan: ruleFor on every live fiber (this is
  // where the refresh-misses-pending latch is set in the reference).
  for (const f of model.fibers.values()) {
    if (!f.removed) model.ruleFor(f)
  }
}

function concreteKey(record) {
  // CONCRETE identity within one settle exploration: fixed fiber order and
  // raw atoms (no χ-renaming) — quiescent reports are keyed by concrete
  // uids/keys, so collapsing χ-equivalent-but-distinct assignments here
  // would lose outcomes. everUnsat included (mutant-relevant, monotone).
  return JSON.stringify(record.fibers.map(f => ({ ...f, spec: f.spec.name })))
}

function report(model) {
  const fibers = {}
  for (const [uid, f] of model.fibers.entries()) {
    fibers[uid] = `${model.stateOf(f)}${f.outcome ? '!' : ''}`
  }
  const store = {}
  for (const key of ['k1', 'k2']) {
    const p = model.providerOf(model.rootCtx, key)
    store[`root:${key}`] = p ? JSON.stringify(p.table.get(model.labelOf(model.rootCtx, key))?.value) : null
  }
  const isoCtx = model.rootCtx.isolated('k1', 'r1')
  const pIso = model.providerOf(isoCtx, 'k1')
  store['r1:k1'] = pIso ? JSON.stringify(pIso.table.get(model.labelOf(isoCtx, 'k1'))?.value) : null
  // Lenient view (adapter readKeyLenient): ANY non-removed fiber's binding,
  // Active or not — this is how recovery-exactness leaks are observed.
  for (const key of ['k1', 'k2']) {
    let found = null
    for (const f of model.fibers.values()) {
      if (f.removed) continue
      const entry = f.table.get(model.labelOf(model.rootCtx, key))
      if (entry) { found = JSON.stringify(entry.value); break }
    }
    store[`lenient:${key}`] = found
  }
  return JSON.stringify({ fibers, store })
}

/**
 * Explore every internal schedule from `model` to quiescence.
 * Returns { reports, diverged, truncated, settleEvents, settleCerts }.
 * `settleEvents` is the set of events observable on some schedule (order
 * abstracted — see report's scoping decisions); `settleCerts` is the set of
 * certificate signatures (fired AND disabled) met on some schedule — the
 * cert(r, ŝ, â) observable of PAPER_REWRITE §2.3.
 */
export function settleOutcomes(model, { maxStates = 20_000 } = {}) {
  const settleCerts = new Set()
  model.cert = c => settleCerts.add(sigKey(c))
  probeAll(model)
  const rootRec = snapshot(model)
  model.cert = null
  const idOf = new Map()
  const recs = []
  const internal = []
  const reports = new Set()
  const settleEvents = new Set()
  let truncated = false

  const intern = (rec) => {
    const k = concreteKey(rec)
    let id = idOf.get(k)
    if (id === undefined) {
      id = recs.length
      idOf.set(k, id)
      recs.push(rec)
      internal.push([])
      queue.push(id)
    }
    return id
  }
  const queue = []
  intern(rootRec)

  for (let qhead = 0; qhead < queue.length; qhead++) {
    if (recs.length > maxStates) { truncated = true; break }
    const id = queue[qhead]
    const rec = recs[id]
    const m = materialize(rec)
    m.cert = c => settleCerts.add(sigKey(c))
    // enumerate internal actions
    const enabled = []
    const n = rec.fibers.length
    for (let i = 0; i < n; i++) {
      const f = m.fibers.get(i + 1)
      if (f.removed) continue
      const rule = m.ruleFor(f)
      if (rule) enabled.push({ t: 'life', f: i })
    }
    for (let i = 0; i < n; i++) {
      const f = m.fibers.get(i + 1)
      if (f.removed || !f.retired) continue
      if (m.removeEligible(f)) enabled.push({ t: 'remove', f: i })
    }
    if (enabled.length === 0) {
      reports.add(report(m))
      continue
    }
    for (const action of enabled) {
      const m2 = materialize(rec)
      m2.cert = c => settleCerts.add(sigKey(c))
      const t0 = m2.trace.length
      const f2 = m2.fibers.get(action.f + 1)
      if (action.t === 'life') {
        const rule = m2.ruleFor(f2)
        if (rule) rule()
      } else {
        m2.removeOne(f2)
      }
      for (const e of m2.trace.slice(t0)) settleEvents.add(e)
      probeAll(m2)
      const succ = snapshot(m2)
      const succId = intern(succ)
      internal[id].push(succId)
    }
  }

  // Divergence: any internal cycle reachable in this closure.
  let diverged = truncated
  const color = new Uint8Array(recs.length)
  const stack = []
  outer: for (let s = 0; s < recs.length; s++) {
    if (color[s]) continue
    stack.push([s, 0])
    color[s] = 1
    while (stack.length) {
      const top = stack[stack.length - 1]
      const [v] = top
      if (top[1] < internal[v].length) {
        const w = internal[v][top[1]++]
        if (color[w] === 1) { diverged = true; break outer }
        if (color[w] === 0) { color[w] = 1; stack.push([w, 0]) }
      } else {
        color[v] = 2
        stack.pop()
      }
    }
    stack.length = 0
  }

  return {
    reports: [...reports].sort(),
    diverged,
    truncated,
    settleEvents: [...settleEvents].sort(),
    settleCerts: [...settleCerts].sort(),
  }
}

/** Full observation of a test on one target: replay + settle outcome set. */
export function observe(actions, { mutant = null } = {}) {
  const { perAction, final } = replayScript(actions, { mutant })
  const settle = settleOutcomes(final)
  return {
    perAction: perAction.map(pa => ({
      refused: pa.refused,
      note: pa.refused ? pa.note : null,
      emissions: pa.emissions,
      certs: pa.certs,
    })),
    settle,
  }
}

export function observationsEqual(a, b) {
  return JSON.stringify(a) === JSON.stringify(b)
}
