// D3 item 5 (analysis half) — coverage matrix of the 32-test suite against
// the explorer's reachable signature sets, and the uncovered-signature
// finding.
//
// Usage: node coverage.mjs out/signatures-A.json [out/signatures-B.json ...]
// Reads out/audit-32.json (produced by audit-32.mjs); writes
// out/coverage.json and out/coverage.md.

import { readFileSync, writeFileSync } from 'node:fs'
import { RULE_ORDER } from './sig.mjs'

const sigFiles = process.argv.slice(2)
if (sigFiles.length === 0) {
  console.error('usage: node coverage.mjs out/signatures-<tag>.json ...')
  process.exit(2)
}

// Reachable set = union over the portfolio of complete bounded runs.
const reachable = new Map() // sig -> { rules, runs: [tag], fields }
for (const file of sigFiles) {
  const data = JSON.parse(readFileSync(file, 'utf8'))
  for (const [rule, sigs] of Object.entries(data.rules)) {
    for (const s of sigs) {
      if (!reachable.has(s.sig)) reachable.set(s.sig, { rule, decision: s.decision, fields: s.fields, runs: [] })
      reachable.get(s.sig).runs.push(data.tag)
    }
  }
}

const audit = JSON.parse(readFileSync('out/audit-32.json', 'utf8'))
const testNames = Object.keys(audit)

// Per-test exercised signatures, restricted to the reachable set and not.
const matrix = {}
const exercisedUnion = new Set()
const outsideBound = new Set()
for (const [test, { sigs }] of Object.entries(audit)) {
  const inSet = []
  const outSet = []
  for (const sig of Object.keys(sigs)) {
    if (reachable.has(sig)) { inSet.push(sig); exercisedUnion.add(sig) } else { outSet.push(sig) }
  }
  matrix[test] = { covered: inSet.sort(), outsideExplorerSet: outSet.sort() }
  for (const s of outSet) outsideBound.add(s)
}

const uncovered = [...reachable.keys()].filter(sig => !exercisedUnion.has(sig)).sort()

const ruleKey = sig => sig.split(' ')[0]
const byRule = (sigs) => {
  const m = new Map()
  for (const s of sigs) {
    const r = ruleKey(s)
    if (!m.has(r)) m.set(r, [])
    m.get(r).push(s)
  }
  return [...m.entries()].sort((a, b) =>
    (RULE_ORDER.indexOf(a[0]) + 100 * (RULE_ORDER.indexOf(a[0]) < 0)) -
    (RULE_ORDER.indexOf(b[0]) + 100 * (RULE_ORDER.indexOf(b[0]) < 0)))
}

let md = '# 32-test coverage against the reachable signature set\n\n'
md += `Reachable signatures (union over runs ${sigFiles.join(', ')}): ${reachable.size}\n\n`
md += `Exercised by at least one of the 32 tests: ${exercisedUnion.size}\n\n`
md += `**UNCOVERED reachable signatures: ${uncovered.length}**\n\n`
for (const [rule, sigs] of byRule(uncovered)) {
  md += `- **${rule}** (${sigs.length}):\n`
  for (const s of sigs) md += `  - \`${s}\`\n`
}
md += `\nSignatures exercised by tests but OUTSIDE the explorer's reachable set (beyond the explored bound/generator): ${outsideBound.size}\n\n`
for (const [rule, sigs] of byRule([...outsideBound].sort())) {
  md += `- **${rule}** (${sigs.length}):\n`
  for (const s of sigs) md += `  - \`${s}\`\n`
}
md += '\n## Per-test coverage matrix\n\n| test | reachable sigs exercised | outside-set sigs |\n|---|---|---|\n'
for (const test of testNames) {
  md += `| ${test} | ${matrix[test].covered.length} | ${matrix[test].outsideExplorerSet.length} |\n`
}

// Reverse direction: which tests exercise each signature (density check).
const perSigTests = {}
for (const sig of reachable.keys()) perSigTests[sig] = []
for (const [test, { covered }] of Object.entries(matrix)) {
  for (const sig of covered) perSigTests[sig].push(test)
}

writeFileSync('out/coverage.json', JSON.stringify({
  sigFiles,
  reachableCount: reachable.size,
  exercisedCount: exercisedUnion.size,
  uncovered,
  outsideBound: [...outsideBound].sort(),
  matrix,
  perSigTests,
}, null, 1))
writeFileSync('out/coverage.md', md)
console.log(`reachable=${reachable.size} exercised=${exercisedUnion.size} UNCOVERED=${uncovered.length} outside-bound=${outsideBound.size}`)
console.log('written out/coverage.json, out/coverage.md')
