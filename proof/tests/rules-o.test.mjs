// Orchestration rules: O-Insert, O-Retire, O-Remove (Table 1, §4.2).
import test from 'node:test'
import assert from 'node:assert/strict'
import { component, provide, track, register, inOrder, count } from '../src/dsl.mjs'
import { withSystem } from './helpers.mjs'

test('R1.1 insert-activates-fresh', () => withSystem(async (sys) => {
  // O-Insert creates a fresh Inactive(⊥) fiber; with no declared coeffects the
  // lifecycle carries it to Active and its provisions enter σ_γ.
  const spec = component('P', { steps: [provide('k1', 'v1'), track('p1')] })
  const handle = sys.insert(null, spec)
  await sys.settle()
  assert.equal(sys.state(handle), 'active')
  assert.equal(sys.provided('k1'), true)
  assert.equal(sys.readKey('k1'), 'v1')
  assert.ok(sys.trace.includes('apply:P:p1'))
}))

test('R1.2 insert-under-removed-parent-rejected', () => withSystem(async (sys) => {
  // O-Insert premise π ∈ dom(F_γ) ∪ {root}: a removed fiber is no parent.
  const parent = sys.insert(null, component('P', { steps: [track('p1')] }))
  await sys.settle()
  const ctx = sys.childCtx(parent)
  sys.retire(parent)
  await sys.settle()
  assert.equal(sys.state(parent), 'disposed')
  assert.throws(() => sys.insert(ctx, component('C', { steps: [] })))
}))

test('R1.3 dynamic-provision-conflict-fails-offender', () => withSystem(async (sys) => {
  // A component whose effect function writes a key OUTSIDE its declared p
  // violates the Definition 43 containment premise, which the runtime cannot
  // check statically (paper-review GAP-6's deliberate residue). The fail-safe
  // the calculus's single-provider discipline still requires: the conflicting
  // write fails the OFFENDER and leaves the standing provider untouched —
  // never a silent overwrite.
  const a = sys.insert(null, component('A', { steps: [provide('k', 'from-a')] }))
  await sys.settle()
  const b = sys.insert(null, component('B', { steps: [provide('k', 'from-b'), track('b1')] }))
  await sys.settle()
  assert.equal(sys.state(a), 'active')
  assert.equal(sys.state(b), 'failed')
  assert.equal(sys.readKey('k'), 'from-a')
  // The failed insertion left no partial contribution.
  assert.equal(count(sys.trace, 'apply:B:b1'), 0)
}))

test('R1.4 declared-provision-disjointness-at-insert', () => withSystem(async (sys) => {
  // O-Insert premise ∀m. p ∩ p_m = ∅ over DECLARED provisions: inserting a
  // second component declaring an already-declared key is refused up front —
  // removal, not retirement, is what frees the declaration.
  const a = sys.insert(null, component('DA', { provide: ['dk'], steps: [provide('dk', 1)] }))
  await sys.settle()
  assert.equal(sys.state(a), 'active')
  assert.throws(
    () => sys.insert(null, component('DB', { provide: ['dk'], steps: [provide('dk', 2)] })),
    /dk/,
    'the orchestrator may not admit a second declarer of a provided key',
  )
  assert.equal(sys.readKey('dk'), 1)
}))

test('R2.1 retire-runs-recovery', () => withSystem(async (sys) => {
  // O-Retire is a request; the lifecycle rules carry it out through L-Leave
  // and L-Unload, so the accumulator runs — retirement never discards effects.
  const p = sys.insert(null, component('P', { steps: [provide('k', 1), track('p1'), track('p2')] }))
  await sys.settle()
  sys.retire(p)
  await sys.settle()
  assert.equal(sys.state(p), 'disposed')
  assert.equal(sys.provided('k'), false)
  assert.ok(sys.trace.includes('revert:P:p1'))
  assert.ok(sys.trace.includes('revert:P:p2'))
}))

test('R2.2 retire-pending-clean', () => withSystem(async (sys) => {
  // Retiring a fiber that never activated applies an empty accumulator.
  const c = sys.insert(null, component('C', { inject: ['missing'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(sys.state(c), 'pending')
  sys.retire(c)
  await sys.settle()
  assert.equal(sys.state(c), 'disposed')
  assert.equal(count(sys.trace, 'apply:C:c1'), 0)
  assert.equal(count(sys.trace, 'revert:C:c1'), 0)
}))

test('R3.1 removal-follows-inactivity', () => withSystem(async (sys) => {
  // O-Remove requires Inactive: while a dependent's guarded teardown is still
  // running, the provider entry must survive so committed reads stay served.
  const p = sys.insert(null, component('P', { steps: [provide('k', 'held'), track('p1')] }))
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [{ do: 'trackReadOnRevert', tag: 'c1', key: 'k' }] }))
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  sys.retire(p)
  await sys.settle()
  assert.equal(sys.state(p), 'disposed')
  assert.ok(sys.trace.includes('revertread:C:k="held"'),
    `dependent teardown read must be served; trace: ${sys.trace.join(' | ')}`)
}))

test('R3.2 registration-cascade-recovers-children', () => withSystem(async (sys) => {
  // Registration (Definition 47): the inverse of registering a child retires
  // it, and the ordinary rules then carry the child all the way back — the
  // cascade leaves neither the child's fiber nor its effects behind.
  //
  // Deliberately NOT asserted: any order between the child's unload and the
  // parent's other inverses. The calculus orders deactivations along
  // coeffects, not along the fiber tree ("a parent may run its inverse while
  // a child of it is still Unloading", §4.3.1); an implementation may
  // sequence the two more strongly, and Cordis does.
  const child = component('Child', { steps: [track('c1')] })
  const parent = sys.insert(null, component('Parent', { steps: [track('early'), register(child)] }))
  await sys.settle()
  assert.ok(inOrder(sys.trace, ['apply:Parent:early', 'apply:Child:c1']))
  sys.retire(parent)
  await sys.settle()
  assert.equal(sys.state(parent), 'disposed')
  assert.ok(sys.trace.includes('revert:Child:c1'), 'child effects must be recovered by the cascade')
  assert.ok(sys.trace.includes('revert:Parent:early'))
}))
