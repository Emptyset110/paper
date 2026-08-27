// The κ_r-congruence check at the explorer's bound.
//
//   For each rule r, over the interface-reachable window set:
//       κ_r(W) = κ_r(W')  ⟹  result_r(W) ≡ result_r(W')
//
// This is the property `../alphabet-audit.md` §5 layer 3 names as "the missing
// proof", and Lemma 4 (transport, `../paper.md` §6.2) is what consumes it.
// The check quotients the reachable windows by κ_r and reports every class
// holding two distinct results.
//
// Usage:
//   node run-congruence.mjs [--maxFibers=N] [--shapes=A,B] [--maxStates=N]
//        [--timeBudgetMs=N] [--tag=name] [--noUpdates] [--noSetowns]
//        [--noIsolate] [--noChildInserts]
// Writes out/cong-<tag>.json.

import { writeFileSync, mkdirSync } from 'node:fs'
import { createHash } from 'node:crypto'
import { snapshot, canonicalize, reorder, materialize } from '../explorer/norm.mjs'
import { enumerateActions, applyAction } from '../explorer/explore.mjs'
import { buildSpec, UPDATE_CFG, SETOWN, CATALOG } from '../explorer/catalog.mjs'
import { Model } from './patch-model.mjs'
import { windows, kappaOf, KEYS, inRegistry } from './kappa.mjs'
import { roleTable, absState, buildResult, refusalCode } from './result.mjs'

const hash = s => createHash('md5').update(s).digest('base64')

const args = Object.fromEntries(process.argv.slice(2).map(a => {
  const m = a.match(/^--([^=]+)(?:=(.*))?$/)
  return m ? [m[1], m[2] ?? true] : [a, true]
}))

const tag = args.tag ?? 'C'
const options = {
  maxFibers: args.maxFibers ? Number(args.maxFibers) : 2,
  shapes: args.shapes ? String(args.shapes).split(',') : CATALOG.map(s => s.id),
  isolate: !args.noIsolate,
  childInserts: !args.noChildInserts,
  updates: !args.noUpdates,
  setowns: !args.noSetowns,
  maxStates: args.maxStates ? Number(args.maxStates) : 200_000,
  timeBudgetMs: args.timeBudgetMs ? Number(args.timeBudgetMs) : 20 * 60_000,
}

// ---- window evaluation ---------------------------------------------------

const LIFE_RULES = new Set(['L-Begin', 'L-Iterate', 'L-Finish', 'L-Divert', 'L-Leave', 'L-Unload'])

function hasChild(m, f) {
  return [...m.fibers.values()].some(o => !o.removed && o.parent === f)
}

/**
 * Apply one window's rule to a FRESH materialization and assemble
 * result_r(W) at both levels.  The pre-state role table names every fiber, so
 * the result mentions no fiber name and no value.
 */
function evaluate(makeModel, w) {
  const m = makeModel()
  // Give every fiber a display name unique in THIS materialization.  Canonical
  // records carry the spec objects they were built with and the canonical
  // string does not read the component's name, so two fibers of one record can
  // legitimately share one — which would make the role of an emission's
  // subject ambiguous.  Names are atoms (Lemma 56); renaming them is free.
  let nameSeq = 0
  for (const f of m.fibers.values()) f.spec = { ...f.spec, name: `n${nameSeq++}` }
  // The O-Retire a registration inverse yields (Def. 47) lands on a fiber that
  // is not the subject; record its targets so the write is reported as a write.
  const retiredTargets = new Set()
  const uidKey = new Map()
  for (const [uid, f] of m.fibers) uidKey.set(f, uid)
  const baseRetire = m.retire.bind(m)
  m.retire = f => { if (uidKey.has(f)) retiredTargets.add(uidKey.get(f)); return baseRetire(f) }
  // Re-resolve the window's subject inside this materialization.
  const subject = w.fIdx === undefined ? null : m.fibers.get(w.fIdx + 1)
  const parent = w.parentIdx === undefined || w.parentIdx < 0 ? null : m.fibers.get(w.parentIdx + 1)

  let ctx = m.rootCtx
  if (w.kind === 'insert') {
    if (w.ctxKind === 'iso') ctx = m.rootCtx.isolated('k1', 'r1')
    else if (w.ctxKind === 'child') ctx = parent.ctx
  }

  const spec = w.kind === 'insert' ? buildSpec(w.shape, m.nextUid) : null
  const anchor = w.kind === 'insert' ? (ctx.fiber ?? null) : subject
  const preRoles = roleTable(m, anchor)
  const roleOf = f => preRoles.get(f) ?? 'new'
  const nameOf = new Map()
  for (const f of m.fibers.values()) nameOf.set(f.spec.name, roleOf(f))

  const kappa = w.kind === 'insert'
    ? kappaOf(m, { rule: 'O-Insert', offer: { parentFiber: ctx.fiber, spec, ctx } })
    : kappaOf(m, { ...w, f: subject })

  const pre = absState(m, roleOf)
  const t0 = m.trace.length
  let decision = 'fire'
  let refusal = null
  let observedRule = null
  let extra = null

  try {
    switch (w.kind) {
      case 'insert':
        m.insert(ctx, spec)
        break
      case 'retire':
        m.retire(subject)
        break
      case 'update':
        m.update(subject, { ...UPDATE_CFG })
        break
      case 'setval':
        m.setOwn(subject, SETOWN.key, SETOWN.value)
        break
      case 'read': {
        // The A-Read label writes nothing; its result is the outcome of
        // Algorithm 6.  A served read is reported by the ROLE of the fiber
        // whose table answered it (p. 31: "recording a provider rather than a
        // value is what makes the comparison usable"), never by the value.
        const before = subject && inRegistry(m, subject) ? providerRole(m, subject, w.key, roleOf) : null
        m.readCommitted(subject, w.key)
        extra = `served<-${before ?? '?'}`
        break
      }
      case 'remove': {
        const eligible = subject.retired && subject.state === 'inactive' && !hasChild(m, subject)
        if (!eligible) { decision = 'block'; break }
        m.removeOne(subject)
        break
      }
      case 'life': {
        const fn = m.ruleFor(subject)
        if (!fn) { decision = 'block'; break }
        observedRule = fn.ruleName
        fn()
        if (observedRule === 'L-Iter') {
          observedRule = m.trace.slice(t0).some(e => e.startsWith('raise:')) ? 'L-Raise' : 'L-Iter'
        }
        break
      }
      default:
        throw new Error(`unknown window kind ${w.kind}`)
    }
  } catch (error) {
    decision = 'refuse'
    refusal = refusalCode(error)
  }

  for (const f of m.fibers.values()) if (!nameOf.has(f.spec.name)) nameOf.set(f.spec.name, 'new')
  const post = absState(m, roleOf)
  const events = m.trace.slice(t0)
  const res = buildResult({
    rule: kappa.rule,
    decision,
    refusal,
    note: extra ?? observedRule,
    events,
    pre,
    post,
    subjectUid: w.fIdx === undefined ? -1 : w.fIdx + 1,
    nameRole: n => nameOf.get(n) ?? 'new',
    retired: retiredTargets,
  })
  if (res.l1.includes('HARNESS(')) {
    return { harness: JSON.parse(res.l1).r }
  }
  return { kappa, ...res }
}

function providerRole(m, fiber, key, roleOf) {
  let walk = fiber
  while (walk) {
    if (walk.committed?.has(key)) {
      const p = m.fibers.get(walk.committed.get(key))
      if (p?.table.get(m.labelOf(walk.ctx, key))) return roleOf(p)
      return 'withdrawn'
    }
    if (walk.spec.inject.includes(key)) return 'undecided'
    if (walk.parent && m.labelOf(walk.ctx, key) !== m.labelOf(walk.parent.ctx, key)) return 'isolated'
    walk = walk.parent
  }
  return 'root'
}

/** The window list of a configuration, as plain data (no live fiber refs). */
function windowList(m, actions) {
  const out = []
  for (const a of actions ?? []) {
    if (a.t !== 'insert') continue
    out.push({ rule: 'O-Insert', kind: 'insert', shape: a.shape, ctxKind: a.ctx, parentIdx: a.f ?? -1 })
  }
  const keyOf = new Map()
  for (const [uid, f] of m.fibers) keyOf.set(f, uid)
  for (const w of windows(m, { inserts: [], setvalKey: SETOWN.key })) {
    out.push({ rule: w.rule, kind: w.kind, fIdx: keyOf.get(w.f) - 1, key: w.key })
  }
  return out
}

// ---- BFS ------------------------------------------------------------------

const started = Date.now()
const states = []           // id -> { depth, parent }
const records = new Map()
const idOf = new Map()
const queue = []
let qhead = 0
let truncated = false

const intern = (record, depth, parent) => {
  const { key, perm } = canonicalize(record)
  const h = hash(key)
  let id = idOf.get(h)
  if (id === undefined) {
    id = states.length
    idOf.set(h, id)
    states.push({ depth, parent })
    records.set(id, reorder(record, perm))
    queue.push(id)
  }
  return id
}

intern({ mutant: null, fibers: [] }, 0, null)

// (rule, κ) -> Map(level-1 result -> witness) and Map(level-2 result -> witness)
const classes = new Map()
const perRule = new Map()
let windowCount = 0
let lastNewClassAt = 0
// Windows the normalization round-trip cannot present faithfully: `norm.mjs`
// stores a registration inverse's child by uid, and O-Remove nulls the uid, so
// a record whose registered child has been REMOVED loses the reference and the
// rebuilt inverse retires `null`.  That is an artifact of the explorer's
// state encoding, not a decision of any rule (in a live run the record is
// still there and the O-Retire is a no-op on it), so such windows are counted
// and excluded rather than reported as split classes.
const harnessFaults = new Map()
const MAX_WITNESSES = 4

function note(rule, kappaKey, res, witness) {
  const ck = `${rule} {${kappaKey}}`
  let c = classes.get(ck)
  if (!c) {
    c = { rule, kappa: kappaKey, l1: new Map(), l2: new Map(), n: 0 }
    classes.set(ck, c)
    lastNewClassAt = windowCount
  }
  c.n += 1
  if (!c.l1.has(res.l1) && c.l1.size < MAX_WITNESSES) c.l1.set(res.l1, witness)
  else if (!c.l1.has(res.l1)) c.l1.set(res.l1, witness)
  if (!c.l2.has(res.l2) && c.l2.size < MAX_WITNESSES) c.l2.set(res.l2, witness)
  perRule.set(rule, (perRule.get(rule) ?? 0) + 1)
}

while (qhead < queue.length) {
  if (states.length >= options.maxStates || Date.now() - started > options.timeBudgetMs) {
    truncated = true
    break
  }
  const id = queue[qhead++]
  const record = records.get(id)
  const depth = states[id].depth
  const actions = enumerateActions(record, options, null)

  // --- the congruence check at this configuration ---
  const makeModel = () => materialize(record)
  for (const w of windowList(makeModel(), actions)) {
    let ev
    try {
      ev = evaluate(makeModel, w)
    } catch (error) {
      ev = { harness: `throw:${error.message}` }
    }
    if (ev.harness) { harnessFaults.set(ev.harness, (harnessFaults.get(ev.harness) ?? 0) + 1); continue }
    windowCount += 1
    const kk = [...ev.kappa.letters].sort().join(',')
    note(ev.kappa.rule, kk, ev, { state: id, depth, w })
  }

  // --- successors ---
  for (const action of actions) {
    const { model } = applyAction(record, action)
    const succ = snapshot(model)
    delete succ.uids
    intern(succ, depth + 1, { from: id, action })
  }
  records.delete(id)
  if (qhead % 5000 === 0) {
    process.stderr.write(`[cong:${tag}] expanded ${qhead}/${states.length} states, ${windowCount} windows, ${classes.size} classes, ${((Date.now() - started) / 1000).toFixed(0)}s\n`)
  }
}
records.clear()
const bfsWindows = windowCount
const bfsLastNewClassAt = lastNewClassAt
const bfsClasses = classes.size

// ---- coda windows ---------------------------------------------------------
//
// Normalization drops removed fibers that nothing references (norm.mjs's keep
// set), so no state of the graph can host a window at a name O-Remove has
// taken out of dom(F_γ) — the same structural gap that forced run-explore's
// coda test TB.88.  The letters R4, W6, P7, A8 and I3 live exactly there, so
// they are checked on a family of configurations built outside the graph:
// `insert S; settle; retire S; settle` under three companion configurations,
// over eleven shapes, which gives every one of those classes many windows and
// therefore a real congruence test rather than a vacuous singleton.

const CODA_SHAPES = ['T', 'P', 'PT', 'C', 'CR', 'F', 'RGT', 'DP', 'S', 'G', 'M']
const CODA_COMPANIONS = [
  ['alone', () => {}],
  ['withActiveP', m => { m.insert(m.rootCtx, buildSpec('P', 90)); m.sweep() }],
  ['withPendingCC', m => { m.insert(m.rootCtx, buildSpec('CC', 91)) }],
]

let codaWindows = 0
for (const shape of CODA_SHAPES) {
  for (const [cid, companion] of CODA_COMPANIONS) {
    const name = `coda:${shape}/${cid}`
    const make = () => {
      const m = new Model({})
      companion(m)
      const f = m.insert(m.rootCtx, buildSpec(shape, 1))
      m.sweep()
      m.retire(f)
      m.sweep()
      m.trace.length = 0
      return m
    }
    let probe
    try { probe = make() } catch { continue }
    const ws = windowList(probe, null)
    for (const [uid, f] of probe.fibers) {
      if (f.removed) ws.push({ rule: 'O-Insert', kind: 'insert', shape: 'T', ctxKind: 'child', parentIdx: uid - 1 })
    }
    for (const w of ws) {
      let ev
      try { ev = evaluate(make, w) } catch (error) { ev = { harness: `throw:${error.message}` } }
      if (ev.harness) { harnessFaults.set(ev.harness, (harnessFaults.get(ev.harness) ?? 0) + 1); continue }
      windowCount += 1
      codaWindows += 1
      note(ev.kappa.rule, [...ev.kappa.letters].sort().join(','), ev, { coda: name, depth: -1, w })
    }
  }
}

// ---- report ---------------------------------------------------------------

function pathTo(id) {
  if (typeof id !== 'number') return id
  const acts = []
  let cur = states[id]
  while (cur.parent) { acts.unshift(cur.parent.action); cur = states[cur.parent.from] }
  return acts
}

const ruleNames = [...new Set([...classes.values()].map(c => c.rule))].sort()
const summary = []
const splits1 = []
const splits2 = []

for (const rule of ruleNames) {
  const cs = [...classes.values()].filter(c => c.rule === rule)
  const nWindows = cs.reduce((a, c) => a + c.n, 0)
  const bad1 = cs.filter(c => c.l1.size > 1)
  const bad2 = cs.filter(c => c.l2.size > 1)
  summary.push({ rule, windows: nWindows, classes: cs.length, nonSingletonL1: bad1.length, nonSingletonL2: bad2.length })
  for (const c of bad1) {
    splits1.push({
      rule, kappa: c.kappa, windows: c.n,
      results: [...c.l1.entries()].map(([r, wit]) => ({
        result: JSON.parse(r),
        witness: { depth: wit.depth, window: wit.w, script: wit.coda ? wit.coda : pathTo(wit.state) },
      })),
    })
  }
  for (const c of bad2) {
    splits2.push({
      rule, kappa: c.kappa, windows: c.n, distinct: c.l2.size,
      results: [...c.l2.entries()].map(([r, wit]) => ({
        result: JSON.parse(r),
        witness: { depth: wit.depth, window: wit.w, script: wit.coda ? wit.coda : pathTo(wit.state) },
      })),
    })
  }
}

const wall = Date.now() - started
const out = {
  tag,
  options: { ...options, shapes: options.shapes.join(',') },
  stats: {
    normalizedStates: states.length,
    expandedStates: qhead,
    truncated,
    windows: windowCount,
    codaWindows,
    harnessFaults: Object.fromEntries(harnessFaults),
    classes: classes.size,
    bfsWindows,
    bfsClasses,
    // Saturation is measured over the BFS phase only: the coda family runs
    // last and introduces the absent-entry classes by construction.
    bfsLastNewClassAtWindow: bfsLastNewClassAt,
    bfsWindowsSinceLastNewClass: bfsWindows - bfsLastNewClassAt,
    wallClockMs: wall,
  },
  summary,
  splitsLevel1: splits1,
  splitsLevel2: splits2,
  // Every class with every distinct level-1 result and one witness each, so
  // that `summarize.mjs` can union the portfolio and catch a class that is
  // singleton in each run but splits across runs.
  classList: [...classes.values()].map(c => ({
    rule: c.rule,
    kappa: c.kappa,
    windows: c.n,
    l2: c.l2.size,
    l1: [...c.l1.entries()].map(([r, wit]) => ({
      r,
      witness: { depth: wit.depth, window: wit.w, script: wit.coda ?? pathTo(wit.state) },
    })),
  })),
}

mkdirSync(new URL('./out/', import.meta.url), { recursive: true })
writeFileSync(new URL(`./out/cong-${tag}.json`, import.meta.url), JSON.stringify(out, null, 1))

console.log(`\n[cong:${tag}] states=${states.length}${truncated ? ' (TRUNCATED)' : ''} windows=${windowCount} classes=${classes.size} wall=${(wall / 1000).toFixed(1)}s`)
console.log('| rule | reachable windows | κ-classes | non-singleton (L1) | non-singleton (L2, frame) |')
console.log('|---|---:|---:|---:|---:|')
for (const s of summary) {
  console.log(`| ${s.rule} | ${s.windows} | ${s.classes} | ${s.nonSingletonL1} | ${s.nonSingletonL2} |`)
}
const t1 = summary.reduce((a, s) => a + s.nonSingletonL1, 0)
const t2 = summary.reduce((a, s) => a + s.nonSingletonL2, 0)
console.log(`| **total** | ${windowCount} | ${classes.size} | **${t1}** | ${t2} |`)
if (harnessFaults.size) {
  console.log('excluded harness faults (explorer state-encoding artifact):')
  for (const [k, v] of harnessFaults) console.log(`  ${v} x ${k}`)
}
console.log(`saturation (BFS phase): last new κ-class at window ${bfsLastNewClassAt} of ${bfsWindows} (${bfsWindows - bfsLastNewClassAt} windows with no new class); coda added ${classes.size - bfsClasses} more`)
if (t1) {
  console.log(`\nLEVEL-1 COUNTEREXAMPLES (${t1}):`)
  for (const s of splits1.slice(0, 40)) {
    console.log(`  ${s.rule} {${s.kappa}} — ${s.results.length} distinct results over ${s.windows} windows`)
    for (const r of s.results) console.log(`     ${JSON.stringify(r.result)}`)
  }
}
void KEYS
void LIFE_RULES
