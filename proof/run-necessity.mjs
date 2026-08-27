// Necessity (injectivity) check: run the suite once per model mutant and
// build the kill matrix. The claims verified here:
//
//   (K1) every mutant is killed by at least one test — the suite covers
//        every cataloged deviation;
//   (K2) every test has at least one *exclusive* killer — a mutant that
//        fails that test and no other — so no test is redundant: dropping
//        it would let a deviating implementation pass.
//
// Output: the matrix (mutant × failing tests) and the two verdicts.

import { spawnSync } from 'node:child_process'
import { MUTANTS } from './src/model.mjs'

const here = new URL('.', import.meta.url).pathname

function runSuite(env) {
  const result = spawnSync(process.execPath, ['--test', 'tests/rules-o.test.mjs',
    'tests/rules-activation.test.mjs', 'tests/rules-deactivation.test.mjs',
    'tests/coeffects.test.mjs', 'tests/metatheory.test.mjs'], {
    cwd: here,
    env: { ...process.env, ...env },
    encoding: 'utf8',
    timeout: 120_000,
  })
  const output = `${result.stdout}\n${result.stderr}`
  // TAP shape varies with node versions and isolation modes: per-test lines
  // may be indented as subtests, and file-level summary lines duplicate them.
  // Parse indentation-tolerantly, keep only obligation-named lines (they all
  // match /^[A-Z]+\d*\.?\d* /), and dedupe, letting a failure override.
  const failing = new Set()
  const passing = new Set()
  for (const line of output.split('\n')) {
    const m = line.match(/^\s*(not )?ok \d+ - (.+?)(?: # .*)?$/)
    if (!m) continue
    const name = m[2].trim()
    if (!/^(R\d|RU|C\d|M\d)/.test(name)) continue
    if (m[1]) {
      failing.add(name)
      passing.delete(name)
    } else if (!failing.has(name)) {
      passing.add(name)
    }
  }
  return { failing: [...failing], passing: [...passing] }
}

// The calculus's claims quantify over schedules, so the baseline must be
// green under every strategy and a mutant counts as killed if ANY schedule
// exhibits the deviation.
// Exhaustive schedule exploration: the model consults a choice oracle at
// every state with more than one applicable rule, and the test driver
// enumerates ALL oracle sequences (tests/helpers.mjs). Every scenario's
// choice tree is finite and fully explored within the budget — the baseline
// run asserts completeness of the exploration for every test.
const EXHAUST = { MODEL_EXHAUST: '5000', MODEL_EXHAUST_REPORT: '1' }

const baseline = runSuite({ PROOF_TARGET: 'model', MODEL_MUTANT: '', ...EXHAUST })
if (baseline.failing.length > 0) {
  console.error('baseline not green under exhaustive schedules:', baseline.failing)
  process.exit(1)
}
const allTests = baseline.passing
if (allTests.length === 0) {
  console.error('harness error: no obligation results parsed from the baseline run')
  process.exit(1)
}
console.log(`baseline: ${allTests.length} tests green under exhaustive schedule enumeration\n`)

const kills = new Map() // mutant -> failing test names, over all schedules
for (const mutant of MUTANTS) {
  const { failing } = runSuite({ PROOF_TARGET: 'model', MODEL_MUTANT: mutant, MODEL_EXHAUST: '2000' })
  kills.set(mutant, failing)
  console.log(`${mutant.padEnd(34)} kills ${failing.length ? failing.join(', ') : '(nothing)'}`)
}

let ok = true

console.log('\n(K1) every mutant killed:')
for (const [mutant, failing] of kills) {
  if (failing.length === 0) {
    console.log(`  UNKILLED MUTANT: ${mutant}`)
    ok = false
  }
}
if (ok) console.log('  all mutants killed')

console.log('\n(K2) exclusive killers per test:')
const exclusive = new Map() // test -> mutants killing only it
for (const [mutant, failing] of kills) {
  if (failing.length === 1) {
    const list = exclusive.get(failing[0]) ?? []
    list.push(mutant)
    exclusive.set(failing[0], list)
  }
}
let covered = 0
for (const test of allTests) {
  const killers = exclusive.get(test) ?? []
  if (killers.length > 0) {
    covered += 1
    console.log(`  ${test}  <=  ${killers.join(', ')}`)
  } else {
    console.log(`  ${test}  <=  (no exclusive killer)`)
  }
}
console.log(`\n${covered}/${allTests.length} tests have an exclusive killer`)

// (K3) suite minimality: removing any one test must leave some mutant
// unkilled — otherwise that test is redundant with respect to the mutant set.
console.log('\n(K3) minimality:')
let minimal = true
for (const test of allTests) {
  const stillKilled = [...kills.entries()].every(([, failing]) =>
    failing.some(name => name !== test))
  if (stillKilled) {
    console.log(`  REDUNDANT (all mutants still killed without it): ${test}`)
    minimal = false
  }
}
if (minimal) console.log('  every test is the last line of defense for some mutant')
// The exit code certifies K1 (adequacy) and baseline soundness; K2/K3 are
// reported data whose interpretation lives in the paper.
process.exit(ok ? 0 : 1)
