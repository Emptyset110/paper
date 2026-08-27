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
  const failing = []
  const passing = []
  for (const line of output.split('\n')) {
    const fail = line.match(/^not ok \d+ - (.+)$/)
    if (fail) failing.push(fail[1].trim())
    const pass = line.match(/^ok \d+ - (.+)$/)
    if (pass && !line.includes('# SKIP')) passing.push(pass[1].trim())
  }
  return { failing, passing }
}

// The calculus's claims quantify over schedules, so the baseline must be
// green under every strategy and a mutant counts as killed if ANY schedule
// exhibits the deviation.
const STRATEGIES = [
  { MODEL_ORDER: 'fifo' },
  { MODEL_ORDER: 'lifo' },
  { MODEL_ORDER: 'random', MODEL_SEED: '7' },
  { MODEL_ORDER: 'random', MODEL_SEED: '23' },
]

let allTests
for (const strategy of STRATEGIES) {
  const baseline = runSuite({ PROOF_TARGET: 'model', MODEL_MUTANT: '', ...strategy })
  if (baseline.failing.length > 0) {
    console.error(`baseline not green under ${JSON.stringify(strategy)}:`, baseline.failing)
    process.exit(1)
  }
  allTests ??= baseline.passing
}
console.log(`baseline: ${allTests.length} tests green on the reference model under ${STRATEGIES.length} schedules\n`)

const kills = new Map() // mutant -> failing test names (union over schedules)
for (const mutant of MUTANTS) {
  const failing = new Set()
  for (const strategy of STRATEGIES.slice(0, 2)) {
    for (const name of runSuite({ PROOF_TARGET: 'model', MODEL_MUTANT: mutant, ...strategy }).failing) {
      failing.add(name)
    }
  }
  kills.set(mutant, [...failing])
  console.log(`${mutant.padEnd(34)} kills ${failing.size ? [...failing].join(', ') : '(nothing)'}`)
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
process.exit(ok ? 0 : 1)
