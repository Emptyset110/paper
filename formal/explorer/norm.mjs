// Normalization (D3 item 1) — canonical form for model configurations.
//
// A configuration is snapshotted into a plain-data record (snapshot), and its
// χ-equivalence class is named by a canonical string (canonicalize): fibers
// are re-ordered by trying every permutation of the (≤ 4 by bound B) kept
// fibers, atoms (component names, keys, values, tags, realm labels) are
// renamed to canonical atoms in first-encounter order along the deterministic
// serialization walk of that permutation, and the lexicographically smallest
// serialization wins. Because the atom renaming is a function of the
// permutation and the walk is deterministic, this computes a true canonical
// representative of the orbit under fiber-renaming x atom-renaming — the
// χ-equivalence of MASTER.md.
//
// A record can be materialized back into a live Model (materialize):
// accumulator inverses are rebuilt from their `.data` payloads by
// buildInverse, reproducing exactly the closures Model.execute creates.
//
// Scoping notes (logged in explorer-report.md):
//  * removed fibers are dropped from the record unless they are still
//    referenced by a kept fiber's committed view, parent link, or a
//    registration inverse (baseline semantics never leaves such references;
//    some mutants do, and the T_B runner relies on keeping them);
//  * the trace is history, not state — never part of the record;
//  * `everUnsatisfied` is a mutant-only latch (refresh-misses-pending): it is
//    carried in the record but excluded from the canonical string unless the
//    model runs that mutant;
//  * config objects are serialized structurally; the raiseUnless flag name
//    (`ok`) is a reserved constant, not a renameable atom.

import { Model, FiberM, Ctx } from './model.mjs'

// ---- snapshot -----------------------------------------------------------

export function snapshot(model) {
  const all = [...model.fibers.values()]
  const uidOf = new Map() // FiberM -> stable uid (removed fibers have uid null)
  const uids = [...model.fibers.keys()]
  all.forEach((f, i) => uidOf.set(f, uids[i]))

  // Keep set: live fibers + removed fibers referenced from kept ones.
  const keep = new Set(all.filter(f => !f.removed))
  let grew = true
  while (grew) {
    grew = false
    for (const f of keep) {
      const refs = []
      if (f.parent) refs.push(f.parent)
      if (f.committed) {
        for (const uid of f.committed.values()) {
          const target = model.fibers.get(uid)
          if (target) refs.push(target)
        }
      }
      for (const inv of f.accumulator) {
        if (inv.data?.kind === 'retire') {
          const child = model.fibers.get(inv.data.childUid)
          if (child) refs.push(child)
        }
      }
      for (const r of refs) {
        if (!keep.has(r)) { keep.add(r); grew = true }
      }
    }
  }

  const kept = all.filter(f => keep.has(f))
  const indexOf = new Map(kept.map((f, i) => [f, i]))
  const uidToIndex = new Map()
  kept.forEach((f, i) => uidToIndex.set(uidOf.get(f), i))

  const fibers = kept.map(f => ({
    spec: f.spec,
    config: f.config === undefined ? null : f.config,
    parent: f.parent && indexOf.has(f.parent) ? indexOf.get(f.parent) : -1,
    ctxIso: flattenIso(f.ctx.isolate),
    retired: f.retired,
    removed: f.removed,
    state: f.state,
    outcome: f.outcome === null ? null : 'xi',
    committed: f.committed === null
      ? null
      : [...f.committed.entries()].map(([k, uid]) => [k, uidToIndex.get(uid) ?? -1]),
    stepIndex: f.remaining === null ? -1 : f.spec.steps.length - f.remaining.length,
    acc: f.accumulator.map(inv => normAccEntry(inv.data, uidToIndex)),
    table: [...f.table.entries()].map(([label, e]) => [label, e.key, e.value]),
    stale: f.stale,
    everUnsat: !!f.everUnsatisfied,
  }))
  // `uids` (map keys of the kept fibers, in record order) lets the T_B
  // runner resolve canonical fiber positions back to live-model fibers; it
  // is never part of the canonical string.
  return { mutant: model.mutant, fibers, uids: kept.map(f => uidOf.get(f)) }
}

function flattenIso(iso) {
  const out = []
  for (const key in iso) out.push([key, iso[key]]) // for-in walks the chain
  out.sort()
  return out
}

function normAccEntry(data, uidToIndex) {
  if (!data) return { kind: 'other' }
  if (data.kind === 'retire') return { kind: 'retire', child: uidToIndex.get(data.childUid) ?? -1 }
  return { ...data }
}

// ---- canonicalization ---------------------------------------------------

const PERMS = [[]]
for (let n = 1; n <= 8; n++) PERMS[n] = permutations(n)
function permutations(n) {
  if (n === 1) return [[0]]
  const out = []
  for (const p of permutations(n - 1)) {
    for (let i = 0; i <= p.length; i++) {
      out.push([...p.slice(0, i), n - 1, ...p.slice(i)])
    }
  }
  return out
}

class Renamer {
  constructor() {
    this.keys = new Map()
    this.vals = new Map()
    this.tags = new Map()
    this.realms = new Map()
  }
  key(k) { return ref(this.keys, k, 'K') }
  val(v) {
    if (v === undefined) return 'U'
    return ref(this.vals, typeof v === 'object' ? JSON.stringify(v) : `${typeof v}:${v}`, 'V')
  }
  tag(t) { return ref(this.tags, t, 'T') }
  realm(r) { return ref(this.realms, r, 'R') }
  label(label) {
    // A store label is either the shared realm of a key ('realm#root:<key>')
    // or an explicit realm label; represent both through the renamer.
    if (typeof label === 'string' && label.startsWith('realm#root:')) {
      return `root.${this.key(label.slice('realm#root:'.length))}`
    }
    return this.realm(label)
  }
}
function ref(map, x, prefix) {
  if (!map.has(x)) map.set(x, `${prefix}${map.size}`)
  return map.get(x)
}

function serializeSpec(spec, rn) {
  const parts = []
  parts.push('i[' + spec.inject.map(k => rn.key(k)).join(',') + ']')
  parts.push('p[' + (spec.provide ?? []).map(k => rn.key(k)).join(',') + ']')
  parts.push('s[' + spec.steps.map(s => serializeStep(s, rn)).join(';') + ']')
  return parts.join('')
}

function serializeStep(s, rn) {
  switch (s.do) {
    case 'provide': return `pr(${rn.key(s.key)},${rn.val(s.value)})`
    case 'track': return `tk(${rn.tag(s.tag)})`
    case 'trackMutate': return `tm(${rn.key(s.key)},${rn.tag(s.tag)})`
    case 'trackReadOnRevert': return `tr(${rn.key(s.key)},${rn.tag(s.tag)})`
    case 'read': return `rd(${rn.key(s.key)}${s.strict ? ',!' : ''})`
    case 'set': return `sv(${rn.key(s.key)},${rn.val(s.value)})`
    case 'register': return `rg(${serializeSpec(s.spec, rn)})`
    case 'raise': return 'rz'
    case 'raiseUnless': return `ru(${s.flag})` // flag names: reserved constants
    case 'trace': return 'mk'
    default: return `??${s.do}`
  }
}

function serializeFiber(f, rn, posOf) {
  const parts = []
  parts.push(serializeSpec(f.spec, rn))
  parts.push('cfg:' + (f.config === null ? '-' : JSON.stringify(f.config)))
  parts.push('par:' + (f.parent < 0 ? '-' : posOf[f.parent]))
  parts.push('iso:' + f.ctxIso.map(([k, r]) => `${rn.key(k)}=${rn.realm(r)}`).join(','))
  parts.push(`st:${f.state}${f.retired ? 'R' : ''}${f.removed ? 'X' : ''}${f.stale ? 'S' : ''}${f.outcome ? 'E' : ''}`)
  parts.push('ix:' + f.stepIndex)
  if (f.committed === null) {
    parts.push('cm:-')
  } else {
    const entries = f.committed.map(([k, idx]) => `${rn.key(k)}>${idx < 0 ? 'X' : posOf[idx]}`)
    entries.sort()
    parts.push('cm:' + entries.join(','))
  }
  parts.push('ac:' + f.acc.map(a => serializeAcc(a, rn, posOf)).join(','))
  const tbl = f.table.map(([label, key, value]) => `${rn.label(label)}~${rn.key(key)}=${rn.val(value)}`)
  tbl.sort()
  parts.push('tb:' + tbl.join(','))
  return parts.join('|')
}

function serializeAcc(a, rn, posOf) {
  switch (a.kind) {
    case 'provide': return `P(${rn.label(a.label)})`
    case 'track': return `T(${rn.tag(a.tag)})`
    case 'mutate': return `M(${rn.label(a.label)},${rn.tag(a.tag)})`
    case 'rrev': return `R(${rn.key(a.key)},${rn.tag(a.tag)})`
    case 'retire': return `D(${a.child < 0 ? 'X' : posOf[a.child]})`
    default: return 'O'
  }
}

/**
 * Canonical string + the permutation that realizes it.
 * perm[i] = index (in record.fibers) of the fiber at canonical position i.
 */
export function canonicalize(record, { includeEverUnsat = false } = {}) {
  const n = record.fibers.length
  if (n === 0) return { key: 'empty', perm: [] }
  let best = null
  let bestPerm = null
  for (const perm of PERMS[n]) {
    const posOf = new Array(n) // record index -> canonical position
    perm.forEach((recIdx, pos) => { posOf[recIdx] = pos })
    const rn = new Renamer()
    const parts = []
    for (const recIdx of perm) {
      const f = record.fibers[recIdx]
      let s = serializeFiber(f, rn, posOf)
      if (includeEverUnsat) s += `|ev:${f.everUnsat ? 1 : 0}`
      parts.push(s)
    }
    const str = parts.join('\n')
    if (best === null || str < best) { best = str; bestPerm = perm }
  }
  return { key: best, perm: bestPerm }
}

/** Reorder a record into canonical order (fiber indices remapped). */
export function reorder(record, perm) {
  const posOf = new Array(record.fibers.length)
  perm.forEach((recIdx, pos) => { posOf[recIdx] = pos })
  const fibers = perm.map(recIdx => {
    const f = record.fibers[recIdx]
    return {
      ...f,
      parent: f.parent < 0 ? -1 : posOf[f.parent],
      committed: f.committed === null ? null : f.committed.map(([k, idx]) => [k, idx < 0 ? -1 : posOf[idx]]),
      acc: f.acc.map(a => a.kind === 'retire' ? { ...a, child: a.child < 0 ? -1 : posOf[a.child] } : a),
    }
  })
  const out = { mutant: record.mutant, fibers }
  if (record.uids) out.uids = perm.map(recIdx => record.uids[recIdx])
  return out
}

// ---- materialization ----------------------------------------------------

export function buildInverse(model, fiber, data) {
  switch (data.kind) {
    case 'provide': {
      const label = data.label
      const inverse = () => fiber.table.delete(label)
      inverse.kind = 'provide'
      inverse.data = { kind: 'provide', label }
      return inverse
    }
    case 'track': {
      const inverse = () => model.trace.push(`revert:${fiber.spec.name}:${data.tag}`)
      inverse.data = { ...data }
      return inverse
    }
    case 'mutate': {
      const inverse = () => {
        const entry = fiber.table.get(data.label)
        if (entry && entry.value && typeof entry.value === 'object') entry.value[data.field] = data.to
        model.trace.push(`revert:${fiber.spec.name}:${data.tag}`)
      }
      inverse.data = { ...data }
      return inverse
    }
    case 'rrev': {
      const inverse = () => {
        try {
          const value = model.readCommitted(fiber, data.key)
          model.trace.push(`revertread:${fiber.spec.name}:${data.key}=${JSON.stringify(data.field ? value?.[data.field] : value)}`)
        } catch (error) {
          model.trace.push(`revertreadfail:${fiber.spec.name}:${data.key}:${error.code ?? 'ERR'}`)
        }
      }
      inverse.data = { ...data }
      return inverse
    }
    case 'retire': {
      const child = data.childFiber // resolved by materialize
      const inverse = () => model.retire(child)
      inverse.data = { kind: 'retire', childUid: child?.uid ?? null }
      return inverse
    }
    default: {
      const inverse = () => {}
      inverse.data = { ...data }
      return inverse
    }
  }
}

/**
 * Rebuild a live Model from a record. Fiber at record index i receives
 * uid i+1; nextUid continues after them, so freshly inserted fibers get
 * deterministic uids and names per state.
 */
export function materialize(record, { mutant = record.mutant ?? null } = {}) {
  const model = new Model({ mutant })
  const fibers = record.fibers.map((f, i) =>
    new FiberM(model, f.removed ? null : i + 1, f.spec, f.config === null ? undefined : f.config, null, null))
  record.fibers.forEach((f, i) => {
    const fiber = fibers[i]
    fiber.parent = f.parent < 0 ? null : fibers[f.parent]
    const iso = Object.create(null)
    for (const [k, r] of f.ctxIso) iso[k] = r
    fiber.ctx = new Ctx(fiber, iso, Object.create(null))
    fiber.retired = f.retired
    fiber.removed = f.removed
    fiber.state = f.state
    fiber.outcome = f.outcome === null ? null : new Error('xi')
    fiber.committed = f.committed === null
      ? null
      : new Map(f.committed.map(([k, idx]) => [k, idx < 0 ? -999 : idx + 1]))
    fiber.remaining = f.stepIndex < 0 ? null : f.spec.steps.slice(f.stepIndex)
    fiber.table = new Map(f.table.map(([label, key, value]) => [label, { key, value }]))
    fiber.stale = f.stale
    fiber.everUnsatisfied = f.everUnsat
    fiber.accumulator = f.acc.map(a => {
      if (a.kind === 'retire') {
        return buildInverse(model, fiber, { kind: 'retire', childFiber: a.child < 0 ? null : fibers[a.child] })
      }
      return buildInverse(model, fiber, a)
    })
    model.fibers.set(i + 1, fiber)
  })
  model.nextUid = record.fibers.length + 1
  return model
}
