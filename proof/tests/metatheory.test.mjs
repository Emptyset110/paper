// Composition witnesses: the §4.4 metatheory read as observables.
import test from 'node:test'
import assert from 'node:assert/strict'
import { component, provide, track, inOrder, count } from '../src/dsl.mjs'
import { withSystem } from './helpers.mjs'
import { createSystem } from '../src/target.mjs'

test('M1 interleaved-recovery-independence', () => withSystem(async (sys) => {
  // Theorem 61 / Corollary 21: with independent components, one fiber's
  // accumulator withdraws its own contribution and nothing else — in any
  // withdrawal order, not just LIFO across components.
  const a = sys.insert(null, component('A', { steps: [provide('ka', 1), track('a1')] }))
  const b = sys.insert(null, component('B', { steps: [provide('kb', 2), track('b1')] }))
  await sys.settle()
  sys.retire(a) // A applied first, withdrawn first: out of cross-component LIFO
  await sys.settle()
  assert.equal(sys.state(a), 'disposed')
  assert.equal(sys.state(b), 'active', 'withdrawing A must not disturb B')
  assert.equal(sys.provided('ka'), false)
  assert.equal(sys.readKey('kb'), 2)
  assert.equal(count(sys.trace, 'revert:B:b1'), 0)
  sys.retire(b)
  await sys.settle()
  assert.equal(sys.provided('kb'), false)
}))

test('M2 dependency-ordering-chain', () => withSystem(async (sys) => {
  // Theorem 63 in the large: activation follows the provider order and the
  // guarded deactivation runs in exactly the reverse order along a chain.
  const specs = {
    A: component('A', { steps: [provide('x', 1), track('a1')] }),
    B: component('B', { inject: ['x'], steps: [provide('y', 2), track('b1')] }),
    C: component('C', { inject: ['y'], steps: [track('c1')] }),
  }
  // Insert in reverse dependency order: activation must still sort itself.
  const c = sys.insert(null, specs.C)
  const b = sys.insert(null, specs.B)
  const a = sys.insert(null, specs.A)
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  assert.ok(inOrder(sys.trace, ['active:A', 'active:B', 'active:C']),
    `activation follows dependencies; trace: ${sys.trace.join(' | ')}`)
  sys.retire(a)
  await sys.settle()
  assert.equal(sys.state(a), 'disposed')
  assert.ok(inOrder(sys.trace, ['deactivated:C', 'deactivated:B', 'revert:A:a1']),
    `the guard unwinds consumers before the provider's inverses; trace: ${sys.trace.join(' | ')}`)
}))

test('M3 provider-identity-coherence', () => withSystem(async (sys) => {
  // §5.1.3 / Theorem 64: the committed view records the provider, not the
  // value, so replacing a provider with one carrying an EQUAL value still
  // reloads the dependent against the fresh resolution.
  const p1 = sys.insert(null, component('P1', { steps: [provide('k', 'same')] }))
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1'), { do: 'read', key: 'k' }] }))
  await sys.settle()
  assert.equal(count(sys.trace, 'apply:C:c1'), 1)
  // Replacement staged as the calculus stages it: O-Retire drains the old
  // provider's episode to removal, and only then may O-Insert admit the new
  // declarer (its disjointness premise reads the registry, not the σ of the
  // moment). The paper's own loader (Algorithm 10) instead relies on the
  // dynamic-conflict path racing the disposal; the staged form is the one
  // whose premises hold at every step.
  sys.retire(p1)
  await sys.settle()
  sys.insert(null, component('P2', { steps: [provide('k', 'same')] }))
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  assert.equal(count(sys.trace, 'apply:C:c1'), 2,
    `an equal value from a different fiber is a different resolution; trace: ${sys.trace.join(' | ')}`)
  assert.equal(count(sys.trace, 'revert:C:c1'), 1)
}))

test('M4 quiescence-on-unsatisfiable', () => withSystem(async (sys) => {
  // Theorem 66: the system quiesces. A mutual-inject cycle violates the
  // acyclicity hypothesis of activation, and the conforming outcome is a
  // quiescent state with both fibers Inactive(⊥) — no spin, no failure.
  const a = sys.insert(null, component('A', { inject: ['kb'], steps: [provide('ka', 1), track('a1')] }))
  const b = sys.insert(null, component('B', { inject: ['ka'], steps: [provide('kb', 2), track('b1')] }))
  await sys.settle()
  assert.equal(sys.state(a), 'pending')
  assert.equal(sys.state(b), 'pending')
  assert.equal(count(sys.trace, 'apply:A:a1'), 0)
  assert.equal(count(sys.trace, 'apply:B:b1'), 0)
}))

test('M5 confluence-across-histories', async () => {
  // Theorem 73: the quiescent state is a function of the final configuration
  // alone. Three histories with the same final component set must agree on
  // every quiescent observable (states, provisions, values).
  const build = () => ({
    A: component('A', { steps: [provide('a', 'va')] }),
    B: component('B', { inject: ['a'], steps: [provide('b', 'vb')] }),
    C: component('C', { inject: ['b'], steps: [track('c1')] }),
  })

  const observe = async (sys, handles) => ({
    states: Object.fromEntries(Object.entries(handles).map(([k, h]) => [k, sys.state(h)])),
    a: sys.readKey('a'),
    b: sys.readKey('b'),
    providedA: sys.provided('a'),
    providedB: sys.provided('b'),
  })

  // h1: dependency order.
  const s1 = await createSystem()
  const c1 = build()
  const h1 = { A: s1.insert(null, c1.A), B: s1.insert(null, c1.B), C: s1.insert(null, c1.C) }
  await s1.settle()
  const o1 = await observe(s1, h1)
  await s1.dispose()

  // h2: reverse order.
  const s2 = await createSystem()
  const c2 = build()
  const h2 = { C: s2.insert(null, c2.C), B: s2.insert(null, c2.B), A: s2.insert(null, c2.A) }
  await s2.settle()
  const o2 = await observe(s2, h2)
  await s2.dispose()

  // h3: same final set reached through a replacement round-trip of B.
  const s3 = await createSystem()
  const c3 = build()
  const h3 = { A: s3.insert(null, c3.A), B: s3.insert(null, c3.B), C: s3.insert(null, c3.C) }
  await s3.settle()
  s3.retire(h3.B)
  await s3.settle()
  h3.B = s3.insert(null, component('B', { inject: ['a'], steps: [provide('b', 'vb')] }))
  await s3.settle()
  const o3 = await observe(s3, h3)
  await s3.dispose()

  assert.deepEqual(o2, o1, 'insertion order must not change the quiescent state')
  assert.deepEqual(o3, o1, 'a replacement round-trip must land on the statically assembled state')
})
