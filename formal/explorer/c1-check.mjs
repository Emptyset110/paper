// D1 correction C1 (explorer-report.md §11.6).
//
// signatures.md §7.4 gives S-Div-3 as the canonical script for occurrence D3
// (L-Divert with ViewRel = target-⊥-retired):
//
//   Q  := (∅, {k2}, [provide(k2,v2)])
//   Q2 := (∅, {k2}, [provide(k2,v2)])
//   G  := (∅, ∅, [register(C), track(a)])
//   C  := ({k2}, ∅, [track(b), track(c)])
//   ρ = insert(root,Q); insert(root,G); settle; retire(Q); retire(G);
//       insert(root,Q2); settle
//
// The claim under test: `insert(root, Q2)` is REFUSED, because retire() does
// not remove Q from the registry and O-Insert's declared-disjointness premise
// quantifies over all registered (non-removed) fibers — so Q still declares
// k2 when Q2 arrives.
//
// Usage: node c1-check.mjs   (exits 0 iff C1 reproduces)

import { Model } from './model.mjs'

const provide = (key, value) => ({ do: 'provide', key, value })
const track = (tag) => ({ do: 'track', tag })
const register = (spec) => ({ do: 'register', spec })

const C = { name: 'C', inject: ['k2'], steps: [track('b'), track('c')], provide: [] }
const Q = { name: 'Q', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const Q2 = { name: 'Q2', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const G = { name: 'G', inject: [], steps: [register(C), track('a')], provide: [] }

let ok = true

// --- the script exactly as written in signatures.md §7.4 ------------------
const m = new Model({})
const certs = []
m.cert = c => certs.push(`${c.rule} ${c.decision} ${JSON.stringify(c.fields)}`)

const q = m.insert(m.rootCtx, Q)
const g = m.insert(m.rootCtx, G)
m.sweep()
console.log('settle 1:', [...m.fibers.values()].map(f => `${f.spec.name}:${f.state}`).join(' '))

m.retire(q)
m.retire(g)
console.log(`after retire(Q): registered=${!q.removed} retired=${q.retired} state=${q.state}`)

certs.length = 0
try {
  m.insert(m.rootCtx, Q2)
  console.log('FAIL: insert(root, Q2) was ACCEPTED — C1 does not reproduce')
  ok = false
} catch (error) {
  console.log('OK  : insert(root, Q2) REFUSED —', error.message)
  console.log('      certificate:', certs.join(' | '))
}

// --- control: once Q is settled to Inactive and O-Removed, Q2 is admitted --
const m2 = new Model({})
const q_ = m2.insert(m2.rootCtx, Q)
const g_ = m2.insert(m2.rootCtx, G)
m2.sweep()
m2.retire(q_); m2.retire(g_)
m2.sweep()
const left = [...m2.fibers.values()].filter(f => !f.removed)
console.log(`control: after settling the retires, live fibers = ${left.length} (C is gone too)`)
try {
  m2.insert(m2.rootCtx, Q2)
  console.log('OK  : insert(root, Q2) ACCEPTED once Q is removed')
} catch (error) {
  console.log('FAIL: still refused after removal —', error.message)
  ok = false
}

console.log(ok ? '\nC1 REPRODUCES' : '\nC1 DID NOT REPRODUCE')
process.exit(ok ? 0 : 1)
