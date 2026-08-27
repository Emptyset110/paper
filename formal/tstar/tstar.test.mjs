// T* as a node:test suite — one test per canonical experiment, plus the
// structural obligations D1 §15 and Appendix E §E.99 state about the suite
// itself. Run with `node --test tstar.test.mjs`; the target is chosen by the
// same PROOF_TARGET / CORDIS_LIB environment as `../../proof/`.
//
// The narrative runner is `run-tstar.mjs` (coverage, per-letter reporting);
// this wrapper exists so T* participates in an ordinary test run and so the
// suite's own well-formedness is checked, not assumed.

import test from 'node:test'
import assert from 'node:assert/strict'
import { TSTAR_SCRIPTS, SCRIPT_BY_ID, REACHABLE_ALPHABET, UNREALIZABLE } from './scripts.mjs'
import { TSTAR_VERDICTS } from './verdicts.mjs'
import { runSuite } from './run-tstar.mjs'

const ALL_LETTERS = Object.values(REACHABLE_ALPHABET).flat()

test('T* has exactly 60 canonical scripts with unique ids (D1 §15)', () => {
  assert.equal(TSTAR_SCRIPTS.length, 60)
  assert.equal(new Set(TSTAR_SCRIPTS.map(s => s.id)).size, 60)
})

test('every script carries its traceability chain: rule, letters, Appendix E item', () => {
  for (const script of TSTAR_SCRIPTS) {
    assert.ok(REACHABLE_ALPHABET[script.rule], `${script.id}: unknown rule ${script.rule}`)
    assert.ok(script.letters.length > 0, `${script.id}: no target occurrence`)
    assert.match(script.source, /^E\.[A-Z]{2}\.[A-Z]?\w+\(/, `${script.id}: no Appendix E citation`)
    assert.equal(typeof script.components, 'function', `${script.id}: components must be a factory`)
    assert.ok(Array.isArray(script.program) && script.program.length > 0, `${script.id}: empty ρ`)
  }
})

test('no script claims an occurrence D1 proves interface-unrealizable', () => {
  for (const script of TSTAR_SCRIPTS) {
    for (const letter of [...script.letters, ...(script.alsoRealizes ?? [])]) {
      assert.ok(!(letter in UNREALIZABLE),
        `${script.id} claims ${letter}, which D1 §15 excludes: ${UNREALIZABLE[letter]}`)
    }
  }
})

test('every target letter belongs to its rule\'s reachable alphabet', () => {
  for (const script of TSTAR_SCRIPTS) {
    for (const letter of script.letters) {
      assert.ok(REACHABLE_ALPHABET[script.rule].includes(letter),
        `${script.id}: ${letter} is not in Σ_${script.rule}^reach`)
    }
  }
})

test('the 60 scripts index all 86 reachable occurrences (CF5 / obligation (D-C))', () => {
  const realized = new Set()
  for (const script of TSTAR_SCRIPTS) {
    for (const letter of [...script.letters, ...(script.alsoRealizes ?? [])]) realized.add(letter)
  }
  const uncovered = ALL_LETTERS.filter(l => !realized.has(l))
  assert.deepEqual(uncovered, [], `occurrences with no canonical experiment: ${uncovered.join(', ')}`)
  assert.equal(ALL_LETTERS.length, 86)
})

test('every script has a verdict V_{r,s} with at least one load-bearing clause', () => {
  for (const script of TSTAR_SCRIPTS) {
    const clauses = TSTAR_VERDICTS[script.id]
    assert.ok(clauses && clauses.length > 0, `${script.id}: no verdict`)
    for (const clause of clauses) {
      assert.ok(['verdict', 'certificate', 'branch'].includes(clause.kind), `${script.id}: bad clause kind`)
      assert.equal(typeof clause.check, 'function')
      assert.ok(clause.why.length > 20, `${script.id}: a clause must say what it convicts`)
    }
  }
  assert.equal(Object.keys(TSTAR_VERDICTS).length, TSTAR_SCRIPTS.length)
})

test('every schedule pin and every non-invariant word is justified in writing', () => {
  for (const script of TSTAR_SCRIPTS) {
    // A `pin` whose action is a mid-settle `snapshot` only reads the report; a
    // `pin` whose action is an orchestration input SELECTS a schedule, and must
    // say which branch of Appendix E's schedule note it selects and why.
    const steers = script.program.some(a => a.do === 'pin' && a.then.do !== 'snapshot')
    if (steers) {
      assert.ok(script.schedulePin, `${script.id}: pins a schedule without saying why`)
    }
    if (script.wordInvariant === false) {
      assert.ok(script.scheduleNote || script.schedulePin,
        `${script.id}: waives word ≡-equality without citing Appendix E's schedule note`)
    }
  }
})

// ---- the experiments themselves -------------------------------------------

const run = await runSuite()

for (const result of run.results) {
  test(`T* ${result.id} — ${result.rule} [${result.letters.join(',')}] (${result.source})`, () => {
    for (const violation of result.violations) {
      assert.fail(`${violation.kind}: ${violation.why}${violation.error ? ` [threw: ${violation.error}]` : ''}`)
    }
  })
}

test(`T* summary on PROOF_TARGET=${run.target}`, () => {
  const passed = run.results.filter(r => r.status === 'pass').length
  const unrealized = run.results.filter(r => r.unrealized.length).map(r => r.id)
  console.log(`  ${passed}/${run.results.length} canonical experiments passed`)
  if (unrealized.length) {
    console.log(`  canonical-branch letters not realized on this schedule: ${unrealized.join(', ')}`)
  }
  // The soundness gate of Theorem 2: the specification satisfies its own suite.
  if (run.target === 'model') assert.equal(passed, run.results.length)
})

void SCRIPT_BY_ID
