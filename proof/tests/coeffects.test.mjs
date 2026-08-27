// The coeffect layer: operations, notify classification, isolation,
// interception, and the Algorithm 6 access discipline (§3.2, §5.1.2, §5.1.4).
import test from 'node:test'
import assert from 'node:assert/strict'
import { component, provide, track, register, count } from '../src/dsl.mjs'
import { withSystem } from './helpers.mjs'

test('C1.1 provision-value-operations', () => withSystem(async (sys) => {
  // get/set of Definition 23: the binding is readable, and an A_k operation
  // rewrites the value in place under the same provider.
  const p = sys.insert(null, component('P', { steps: [provide('k', 'v1')] }))
  await sys.settle()
  assert.equal(sys.readKey('k'), 'v1')
  sys.setOwn(p, 'k', 'v2')
  await sys.settle()
  assert.equal(sys.readKey('k'), 'v2')
}))

test('C2.1 overwrite-observability-dichotomy', () => withSystem(async (sys) => {
  // The calculus does not model a value operation performed by an Active
  // provider (its effects occur only inside transitions — the GAP-7 hole),
  // and the paper decides the extension both ways: §5.1.3 says an in-place
  // overwrite is NOT observed, while the Theorem 63(3)-consistent repair
  // (paper-review GAP-3) makes it an observed replacement that restarts
  // dependents. What the calculus DOES require of either extension is that
  // consumer episodes stay well formed: an overwrite is either invisible
  // (Definition 26 neutral) or a complete withdraw-and-reinstall — never a
  // torn episode where the dependent re-runs without its previous effects
  // having been recovered.
  const p = sys.insert(null, component('P', { steps: [provide('k', 'v1')] }))
  const c = sys.insert(null, component('C', { inject: ['k'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(count(sys.trace, 'apply:C:c1'), 1)
  sys.setOwn(p, 'k', 'v2')
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  const applied = count(sys.trace, 'apply:C:c1')
  const reverted = count(sys.trace, 'revert:C:c1')
  assert.ok(
    (applied === 1 && reverted === 0) || (applied === 2 && reverted === 1),
    `overwrite must be neutral or a full replacement, never torn: applied=${applied} reverted=${reverted}`,
  )
  assert.equal(sys.readKey('k'), 'v2')
}))

test('C3.1 isolation-independence', () => withSystem(async (sys) => {
  // Definition 28/29: an isolated realm resolves the same key independently —
  // two providers of one key in two realms coexist, and each consumer reads
  // its own realm's binding.
  const realmA = sys.isolateCtx(null, 'k', 'realm-a')
  const pa = sys.insert(realmA, component('PA', { steps: [provide('k', 'in-a')] }))
  const pRoot = sys.insert(null, component('PRoot', { steps: [provide('k', 'in-root')] }))
  const ca = sys.insert(sys.isolateCtx(null, 'k', 'realm-a'), component('CA', {
    inject: ['k'],
    steps: [{ do: 'read', key: 'k' }],
  }))
  const cRoot = sys.insert(null, component('CRoot', {
    inject: ['k'],
    steps: [{ do: 'read', key: 'k' }],
  }))
  await sys.settle()
  assert.equal(sys.state(pa), 'active')
  assert.equal(sys.state(pRoot), 'active', 'realms do not conflict')
  assert.equal(sys.state(ca), 'active')
  assert.equal(sys.state(cRoot), 'active')
  assert.ok(sys.trace.includes('read:CA:k="in-a"'), `trace: ${sys.trace.join(' | ')}`)
  assert.ok(sys.trace.includes('read:CRoot:k="in-root"'))
}))

test('C3.2 isolation-label-join', () => withSystem(async (sys) => {
  // Passing the same label to two isolate calls joins the scopes: the second
  // provider of the key in the joined realm conflicts.
  const a1 = sys.isolateCtx(null, 'k', 'shared-realm')
  const a2 = sys.isolateCtx(null, 'k', 'shared-realm')
  const p1 = sys.insert(a1, component('P1', { steps: [provide('k', 'first')] }))
  await sys.settle()
  const p2 = sys.insert(a2, component('P2', { steps: [provide('k', 'second')] }))
  await sys.settle()
  assert.equal(sys.state(p1), 'active')
  assert.equal(sys.state(p2), 'failed', 'joined realms share one binding')
}))

test('C4.1 intercept-nearest-wins', () => withSystem(async (sys) => {
  // Definition 31 as §5 realizes it: entries closer to the component apply
  // after (override) entries closer to the root; the base config sits below
  // every intercept entry.
  const outer = sys.interceptCtx(null, 'svc', { a: 1, b: 1 })
  const inner = sys.interceptCtx(outer, 'svc', { b: 2, c: 2 })
  const h = sys.insert(inner, component('C', { steps: [track('c1')] }))
  await sys.settle()
  const merged = sys.interceptMerged(h, 'svc', { a: 0, base: true })
  assert.deepEqual(merged, { base: true, a: 1, b: 2, c: 2 })
}))

test('C5.1 undeclared-access-rejected', () => withSystem(async (sys) => {
  // Algorithm 6: a key neither committed nor declared anywhere on the fiber
  // chain is rejected as undeclared, even though the store holds it.
  sys.insert(null, component('P', { steps: [provide('k', 'present')] }))
  const c = sys.insert(null, component('C', { steps: [{ do: 'read', key: 'k' }] }))
  await sys.settle()
  assert.equal(sys.state(c), 'active')
  assert.ok(sys.trace.includes('readfail:C:k:UNDECLARED_ACCESS'),
    `an undeclared read is refused at the point of use; trace: ${sys.trace.join(' | ')}`)
}))

test('C5.2 ancestry-authorized-access', () => withSystem(async (sys) => {
  // Algorithm 6's walk: the first ancestor whose committed view binds the key
  // authorizes the access, so a child registered by an injector reads it.
  const child = component('Child', { steps: [{ do: 'read', key: 'k' }] })
  sys.insert(null, component('P', { steps: [provide('k', 'inherited')] }))
  sys.insert(null, component('Parent', { inject: ['k'], steps: [register(child)] }))
  await sys.settle()
  assert.ok(sys.trace.includes('read:Child:k="inherited"'),
    `the ancestry walk serves the access; trace: ${sys.trace.join(' | ')}`)
}))

test('C5.3 declared-inactive-access', () => withSystem(async (sys) => {
  // Algorithm 6 line 5: a fiber that declares the key but holds no committed
  // view fails the access as inactive, not as undeclared.
  sys.insert(null, component('P', { steps: [provide('k', 'ready')] }))
  const c = sys.insert(null, component('C', { inject: ['k', 'missing'], steps: [track('c1')] }))
  await sys.settle()
  assert.equal(sys.state(c), 'pending')
  let code = 'none'
  try {
    sys.readVia(c, 'k')
    code = 'served'
  } catch (error) {
    code = /inactive context/.test(String(error?.message ?? error)) || error?.code === 'INACTIVE_ACCESS'
      ? 'INACTIVE_ACCESS'
      : 'other'
  }
  assert.equal(code, 'INACTIVE_ACCESS')
}))
