// D3 item 6 — deviant check: run the GENERATED suite T_B against the 27
// mutants of the reference model. A test kills a mutant when the mutant's
// full observation differs from the baseline expectation recorded at
// generation time: any per-action refusal/emission/certificate difference,
// or any difference in the settle-outcome set (reports, divergence flag,
// or reachable settle events).
//
// Usage: node kill-tb.mjs out/tb-<tag>.json [more tb files...]

import { readFileSync, writeFileSync } from 'node:fs'
import { MUTANTS } from './model.mjs'
import { observe, observationsEqual } from './runner.mjs'

const files = process.argv.slice(2)
if (files.length === 0) {
  console.error('usage: node kill-tb.mjs out/tb-<tag>.json ...')
  process.exit(2)
}

// Merge suites from all provided runs; dedupe by signature (first wins —
// files should be ordered by preference, shortest-bound first).
const tests = []
const seen = new Set()
for (const file of files) {
  const { tests: ts } = JSON.parse(readFileSync(file, 'utf8'))
  for (const t of ts) {
    if (seen.has(t.sig)) continue
    seen.add(t.sig)
    tests.push(t)
  }
}
console.log(`T_B: ${tests.length} tests (deduped by signature) from ${files.length} run(s)`)

// Sanity: baseline must reproduce its recorded expectation.
let baselineBad = 0
for (const t of tests) {
  const now = observe(t.script)
  if (!observationsEqual(now, t.expected)) {
    baselineBad += 1
    console.error(`BASELINE DRIFT: ${t.id} ${t.sig}`)
  }
}
console.log(`baseline reproduction: ${tests.length - baselineBad}/${tests.length} exact`)

const kills = {} // mutant -> [test ids]
const killedBy = {} // test id -> [mutants]
const t0 = Date.now()
for (const mutant of MUTANTS) {
  kills[mutant] = []
  for (const t of tests) {
    let differs
    try {
      const got = observe(t.script, { mutant })
      differs = !observationsEqual(got, t.expected)
    } catch (error) {
      differs = true // a crash under a mutant is a kill (baseline never crashes)
    }
    if (differs) {
      kills[mutant].push(t.id)
      ;(killedBy[t.id] ??= []).push(mutant)
    }
  }
  console.log(`${mutant.padEnd(34)} killed by ${kills[mutant].length}/${tests.length} generated tests`)
}
console.log(`kill matrix computed in ${((Date.now() - t0) / 1000).toFixed(1)}s`)

const unkilled = MUTANTS.filter(m => kills[m].length === 0)
console.log(`\n(K1) mutants killed by generated T_B: ${MUTANTS.length - unkilled.length}/${MUTANTS.length}`)
if (unkilled.length) console.log(`UNKILLED: ${unkilled.join(', ')}`)

writeFileSync('out/kill-tb.json', JSON.stringify({
  files,
  testCount: tests.length,
  baselineBad,
  kills,
  unkilled,
  perTestKillCounts: Object.fromEntries(tests.map(t => [t.id, (killedBy[t.id] ?? []).length])),
}, null, 1))
console.log('written out/kill-tb.json')
process.exit(unkilled.length || baselineBad ? 1 : 0)
