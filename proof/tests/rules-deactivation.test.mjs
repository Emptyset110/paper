// Deactivation rules: L-Leave, the L-Unload guard, recovery exactness (§4.3.1).
import test from 'node:test'
import assert from 'node:assert/strict'
import { component, provide, track, inOrder } from '../src/dsl.mjs'
import { withSystem } from './helpers.mjs'

test('R8.1 leaving-provider-reads-own-deps', () => withSystem(async (sys) => {
  // Theorem 63(3): a fiber reads its declared coeffects through its committed
  // view for as long as it is installed — its own teardown included. Here the
  // middle of a chain deactivates and its inverse still reads upstream.
  sys.insert(null, component('Up', { steps: [provide('j', 'base')] }))
  const mid = sys.insert(null, component('Mid', {
    inject: ['j'],
    steps: [provide('k', 'derived'), { do: 'trackReadOnRevert', tag: 'm1', key: 'j' }],
  }))
  await sys.settle()
  assert.equal(sys.state(mid), 'active')
  sys.retire(mid)
  await sys.settle()
  assert.equal(sys.state(mid), 'disposed')
  assert.ok(sys.trace.includes('revertread:Mid:j="base"'),
    `the leaving fiber's teardown reads its dependencies; trace: ${sys.trace.join(' | ')}`)
}))

test('R9.1 withdrawal-guard-orders-teardown', () => withSystem(async (sys) => {
  // The guard on L-Unload (¬relied): every dependent that resolved a key to
  // the provider completes its own deactivation — committed reads served —
  // before ANY of the provider's inverses run.
  const p = sys.insert(null, component('P', { steps: [provide('k', 'guarded'), track('p1')] }))
  const c = sys.insert(null, component('C', {
    inject: ['k'],
    steps: [{ do: 'trackReadOnRevert', tag: 'c1', key: 'k' }],
  }))
  await sys.settle()
  sys.retire(p)
  await sys.settle()
  assert.equal(sys.state(p), 'disposed')
  assert.ok(sys.trace.includes('revertread:C:k="guarded"'),
    `the dependent's teardown read must be served through its committed view; trace: ${sys.trace.join(' | ')}`)
  assert.ok(inOrder(sys.trace, ['revertread:C:k="guarded"', 'revert:P:p1']),
    `the provider's inverses run only after the dependent finished; trace: ${sys.trace.join(' | ')}`)
}))

test('R9.2 recovery-exactness-on-deactivation', () => withSystem(async (sys) => {
  // Corollary 62: a closed episode leaves nothing behind. The probing case is
  // a NON-retired deactivation — the fiber stays in the registry, so any
  // binding its accumulator failed to withdraw would still be observable
  // (removal would mask the leak by deleting the whole entry).
  const up = sys.insert(null, component('Up', { steps: [provide('j', 'base')] }))
  const mid = sys.insert(null, component('Mid', {
    inject: ['j'],
    steps: [provide('k', 'derived'), track('m1')],
  }))
  await sys.settle()
  assert.equal(sys.readKey('k'), 'derived')
  sys.retire(up)
  await sys.settle()
  assert.equal(sys.state(mid), 'pending', 'the dependent deactivates but stays present')
  assert.equal(sys.provided('k'), false)
  assert.equal(sys.readKeyLenient('k'), undefined, 'no residual binding survives the accumulator')
  // Reinsertion: the freed key and the pending fiber both come back cleanly.
  sys.insert(null, component('Up2', { steps: [provide('j', 'base2')] }))
  await sys.settle()
  assert.equal(sys.state(mid), 'active')
  assert.equal(sys.readKey('k'), 'derived')
}))
