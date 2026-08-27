// Activation rules: L-Begin, L-Iter, L-Finish, L-Divert, L-Raise (§4.3).
import test from 'node:test'
import assert from 'node:assert/strict'
import { component, provide, track, raise, inOrder, count } from '../src/dsl.mjs'
import { withSystem } from './helpers.mjs'

test('R4.1 begin-requires-satisfaction', () => withSystem(async (sys) => {
  // L-Begin premise ω = target ≠ ⊥: a declared key with no Active provider
  // keeps the fiber Inactive(⊥) and runs none of its effects.
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(sys.state(c), 'pending')
  assert.equal(count(sys.trace, 'apply:C:c1'), 0)
}))

test('R4.2 provider-arrival-wakes-pending', () => withSystem(async (sys) => {
  // Reactivity: satisfaction arriving later triggers L-Begin unprompted.
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(sys.state(c), 'pending')
  sys.insert(null, component('P', { steps: [provide('k', 1)] }))
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  assert.equal(count(sys.trace, 'apply:C:c1'), 1)
}))

test('R4.3 satisfaction-counts-active-only', () => withSystem(async (sys) => {
  // σ_γ unions the tables of Active fibers alone (Definition 45/49): a key
  // already written by a still-Reloading provider satisfies nobody, so the
  // dependent's first effect runs only after the provider reached Active.
  const p = sys.insert(null, component('P', { steps: [provide('k', 1), track('slow1'), track('slow2')] }))
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(sys.state(p), 'active')
  assert.equal(sys.state(c), 'active')
  assert.ok(inOrder(sys.trace, ['active:P', 'apply:C:c1']),
    `dependent must not begin before the provider is Active; trace: ${sys.trace.join(' | ')}`)
}))

test('R4.4 failure-latch-unchanged-env', () => withSystem(async (sys) => {
  // Inactive(ξ) is not re-entered by L-Begin: with its target unchanged, a
  // failed fiber is not retried, and the system still quiesces.
  const f = sys.insert(null, component('F', { steps: [track('f1'), raise('boom')] }))
  await sys.settle()
  assert.equal(sys.state(f), 'failed')
  const error = await sys.error(f)
  assert.match(String(error?.message ?? error), /boom/)
  assert.equal(count(sys.trace, 'apply:F:f1'), 1, 'no automatic retry against an unchanged environment')
}))

test('R5.1 iteration-order-and-lifo-recovery', () => withSystem(async (sys) => {
  // L-Iter applies iterations in order, composing each inverse onto the
  // accumulator so recovery runs last-in-first-out (Theorem 16).
  const p = sys.insert(null, component('P', { steps: [track('a'), track('b'), track('c')] }))
  await sys.settle()
  assert.ok(inOrder(sys.trace, ['apply:P:a', 'apply:P:b', 'apply:P:c']))
  sys.retire(p)
  await sys.settle()
  assert.ok(inOrder(sys.trace, ['revert:P:c', 'revert:P:b', 'revert:P:a']),
    `inverses must run in LIFO order; trace: ${sys.trace.join(' | ')}`)
}))

test('R6.1 divert-honors-target-change', () => withSystem(async (sys) => {
  // Theorem 64's dichotomy: a transition whose target view turned either
  // aborts at an iteration boundary (inverses so far recovered, no further
  // iteration runs) or — under inertia — lands and deactivates afterwards.
  // What may never happen: quiescing Active on the stale resolution, or an
  // applied iteration left unrecovered.
  const p = sys.insert(null, component('P', { steps: [provide('k', 1)] }))
  await sys.settle()
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1'), track('c2'), track('c3')] }))
  sys.trace.when('apply:C:c1', () => sys.retire(p))
  await sys.settle()
  assert.equal(sys.state(p), 'disposed')
  assert.equal(sys.state(c), 'pending', 'the dependent must not stay Active on a stale committed view')
  for (const tag of ['c1', 'c2', 'c3']) {
    assert.equal(count(sys.trace, `apply:C:${tag}`), count(sys.trace, `revert:C:${tag}`),
      `every applied iteration is recovered (${tag}); trace: ${sys.trace.join(' | ')}`)
  }
  assert.ok(count(sys.trace, 'apply:C:c1') >= 1)
}))

test('R7.1 raise-recovers-then-latches', () => withSystem(async (sys) => {
  // L-Raise routes through Unloading: the accumulator built so far runs, the
  // error is the recorded outcome, and nothing of the fiber remains provided.
  const f = sys.insert(null, component('F', {
    steps: [provide('k', 'partial'), track('f1'), raise('kaput'), track('never')],
  }))
  await sys.settle()
  assert.equal(sys.state(f), 'failed')
  assert.ok(sys.trace.includes('revert:F:f1'), 'effects applied before the raise are recovered')
  assert.equal(count(sys.trace, 'apply:F:never'), 0, 'no iteration runs after a raise')
  assert.equal(sys.provided('k'), false, 'a failed fiber provides nothing')
  const error = await sys.error(f)
  assert.match(String(error?.message ?? error), /kaput/)
}))

test('RU.1 update-restarts-with-new-config', () => withSystem(async (sys) => {
  // The orchestrator's entry update (§5.2.1 "config"): the fiber re-runs its
  // transition against the new config, recovering the previous episode; a
  // failure latch is cleared because the environment (the entry) changed.
  const f = sys.insert(null, component('F', {
    steps: [track('f1'), { do: 'raiseUnless', flag: 'ok', message: 'not yet' }],
  }))
  await sys.settle()
  assert.equal(sys.state(f), 'failed')
  sys.update(f, { ok: true })
  await sys.settle()
  assert.equal(sys.state(f), 'active', 'an updated entry retries against the new config')
  assert.equal(count(sys.trace, 'apply:F:f1'), 2)
  assert.ok(sys.trace.includes('flagged:F:ok'))
  // The active half: updating an active fiber re-runs its episode.
  sys.update(f, { ok: true })
  await sys.settle()
  assert.equal(sys.state(f), 'active')
  assert.equal(count(sys.trace, 'apply:F:f1'), 3, 'an update of an Active fiber restarts it')
  assert.equal(count(sys.trace, 'revert:F:f1'), 2)
}))
