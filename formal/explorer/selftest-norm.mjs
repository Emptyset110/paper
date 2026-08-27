// Normalization self-test (D3 item 1): χ-equivalent renamings of a scenario
// state must normalize identically, and inequivalent states must not.
//
// Renaming here is generative: the same scenario program is rebuilt with a
// renamed atom vocabulary (keys, values, tags, realm labels, component
// names) and with independent inserts permuted; the resulting configurations
// are χ-equivalent by construction, so canonicalize() must agree.

import assert from 'node:assert/strict'
import { Model } from './model.mjs'
import { snapshot, canonicalize, materialize } from './norm.mjs'

let failures = 0
const check = (name, fn) => {
  try {
    fn()
    console.log(`ok   ${name}`)
  } catch (error) {
    failures += 1
    console.log(`FAIL ${name}: ${error.message}`)
  }
}

// Scenario builder parameterized by an atom map and an insert order.
function buildScenario({ keys, vals, tags, realm, names, order }) {
  const m = new Model()
  const spec = {
    P: { name: names[0], inject: [], steps: [{ do: 'provide', key: keys[0], value: vals[0] }], provide: [] },
    C: {
      name: names[1],
      inject: [keys[0]],
      steps: [{ do: 'track', tag: tags[0] }, { do: 'trackReadOnRevert', tag: tags[1], key: keys[0] }],
      provide: [],
    },
    Q: { name: names[2], inject: [], steps: [{ do: 'provide', key: keys[1], value: vals[1] }], provide: [] },
  }
  const handles = {}
  for (const id of order) {
    const ctx = id === 'Q' ? m.rootCtx.isolated(keys[1], realm) : m.rootCtx
    handles[id] = m.insert(ctx, spec[id])
  }
  m.sweep()
  // Drive a partial teardown so mid-flight structure (accumulator, committed
  // views, unloading states) is part of the compared configuration.
  m.retire(handles.P)
  // one lifecycle step only: P leaves (guard holds C first) — use single steps
  for (const f of m.order()) {
    const rule = m.ruleFor(f)
    if (rule) { rule(); break }
  }
  return m
}

const base = {
  keys: ['k1', 'k2'],
  vals: ['v1', 'v2'],
  tags: ['a', 'b'],
  realm: 'r1',
  names: ['P', 'C', 'Q'],
  order: ['P', 'C', 'Q'],
}

const renamings = [
  { ...base, keys: ['zebra', 'yak'], vals: ['w9', 'w8'], tags: ['t42', 't7'], realm: 'other-realm', names: ['X1', 'X2', 'X3'] },
  { ...base, order: ['Q', 'P', 'C'] },
  { ...base, keys: ['k2', 'kX'], names: ['C', 'P', 'Q'], order: ['C', 'Q', 'P'] },
]

// Deterministic pseudo-random renamings.
let seed = 12345
const rnd = () => (seed = (seed * 1103515245 + 12345) & 0x7fffffff) / 0x7fffffff
const shuffle = (xs) => {
  const a = [...xs]
  for (let i = a.length - 1; i > 0; i--) {
    const j = Math.floor(rnd() * (i + 1))
    ;[a[i], a[j]] = [a[j], a[i]]
  }
  return a
}
for (let i = 0; i < 20; i++) {
  renamings.push({
    keys: [`K${Math.floor(rnd() * 1e6)}`, `K${Math.floor(rnd() * 1e6)}`],
    vals: [`V${Math.floor(rnd() * 1e6)}`, `V${Math.floor(rnd() * 1e6)}`],
    tags: [`T${Math.floor(rnd() * 1e6)}`, `T${Math.floor(rnd() * 1e6)}`],
    realm: `R${Math.floor(rnd() * 1e6)}`,
    names: shuffle(['N1', 'N2', 'N3']),
    order: shuffle(['P', 'C', 'Q']),
  })
}

const baseKey = canonicalize(snapshot(buildScenario(base))).key

check('random renamings normalize identically (23 variants)', () => {
  renamings.forEach((r, i) => {
    const key = canonicalize(snapshot(buildScenario(r))).key
    assert.equal(key, baseKey, `variant ${i} diverged`)
  })
})

check('inequivalent state does not collapse', () => {
  const m = buildScenario(base)
  m.sweep() // drive to quiescence — different configuration
  assert.notEqual(canonicalize(snapshot(m)).key, baseKey)
})

check('materialize round-trips the canonical record', () => {
  const m = buildScenario(base)
  const rec = snapshot(m)
  const again = snapshot(materialize(rec))
  assert.equal(canonicalize(again).key, canonicalize(rec).key)
})

check('materialized model behaves identically under sweep', () => {
  const m1 = buildScenario(base)
  const m2 = materialize(snapshot(m1))
  const t1 = m1.trace.length
  const t2 = m2.trace.length
  m1.sweep()
  m2.sweep()
  assert.deepEqual(m2.trace.slice(t2), m1.trace.slice(t1))
  assert.equal(canonicalize(snapshot(m2)).key, canonicalize(snapshot(m1)).key)
})

process.exit(failures === 0 ? 0 : 1)
