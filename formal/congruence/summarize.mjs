// Union the congruence portfolio.
//
// Each run of `run-congruence.mjs` checks κ-congruence over the windows ITS
// bound reaches.  A class can be singleton in every run and still split across
// runs, so the verdict is taken over the union: for each (rule, κ) the set of
// level-1 results is unioned over all runs, and a class is a counterexample if
// that union has more than one element.
//
//   node summarize.mjs out/cong-*.json   →  out/SUMMARY.md

import { readFileSync, writeFileSync, readdirSync } from 'node:fs'

let files = process.argv.slice(2)
if (!files.length) {
  files = readdirSync(new URL('./out/', import.meta.url))
    .filter(f => f.startsWith('cong-') && f.endsWith('.json'))
    .map(f => `out/${f}`)
}

const runs = files.map(f => ({ file: f, j: JSON.parse(readFileSync(f, 'utf8')) }))

const union = new Map() // "rule {κ}" -> { rule, kappa, windows, results: Map(r -> {run, witness}) }
for (const { j } of runs) {
  for (const c of j.classList) {
    const k = `${c.rule} {${c.kappa}}`
    let u = union.get(k)
    if (!u) { u = { rule: c.rule, kappa: c.kappa, windows: 0, results: new Map(), l2max: 0 }; union.set(k, u) }
    u.windows += c.windows
    u.l2max = Math.max(u.l2max, c.l2)
    for (const r of c.l1) if (!u.results.has(r.r)) u.results.set(r.r, { run: j.tag, witness: r.witness })
  }
}

const rules = [...new Set([...union.values()].map(u => u.rule))]
const ORDER = ['O-Insert', 'O-Retire', 'O-Remove', 'O-Update', 'L-Begin', 'L-Iter', 'L-Raise',
  'L-Finish', 'L-Divert', 'L-Leave', 'L-Unload', 'CO-Prov', 'CO-Acc']
rules.sort((a, b) => (ORDER.indexOf(a) + 99 * (ORDER.indexOf(a) < 0)) - (ORDER.indexOf(b) + 99 * (ORDER.indexOf(b) < 0)))

let md = '# κ_r-congruence — portfolio union\n\n'
md += '| run | bound | states | windows | κ-classes | wall |\n|---|---|---:|---:|---:|---:|\n'
let totWindows = 0
let totFaults = 0
for (const { j } of runs) {
  const o = j.options
  const b = `${o.maxFibers} fibers, shapes=${o.shapes.split(',').length === 19 ? 'ALL' : o.shapes}`
    + `${o.updates ? '' : ', no update'}${o.setowns ? '' : ', no setval'}`
    + `${o.childInserts ? '' : ', no child-insert'}${o.isolate ? '' : ', no isolate'}`
  md += `| ${j.tag} | ${b} | ${j.stats.normalizedStates}${j.stats.truncated ? ' (trunc.)' : ''}`
    + ` | ${j.stats.windows} | ${j.stats.classes} | ${(j.stats.wallClockMs / 1000).toFixed(1)}s |\n`
  totWindows += j.stats.windows
  totFaults += Object.values(j.stats.harnessFaults ?? {}).reduce((a, b2) => a + b2, 0)
}

md += '\n## Per rule, over the union\n\n'
md += '| rule | reachable windows | κ-classes | non-singleton result classes | classes split by frame only (L2) |\n'
md += '|---|---:|---:|---:|---:|\n'
let bad = 0
const splits = []
for (const r of rules) {
  const cs = [...union.values()].filter(u => u.rule === r)
  const w = cs.reduce((a, c) => a + c.windows, 0)
  const nb = cs.filter(c => c.results.size > 1)
  const nf = cs.filter(c => c.l2max > 1)
  bad += nb.length
  splits.push(...nb)
  md += `| ${r} | ${w} | ${cs.length} | ${nb.length === 0 ? '**0**' : `**${nb.length}**`} | ${nf.length} |\n`
}
md += `| **total** | **${totWindows}** | **${union.size}** | **${bad}** | ${[...union.values()].filter(c => c.l2max > 1).length} |\n`

md += `\nExcluded harness faults (explorer state-encoding artifact, see REPORT.md §2.4): ${totFaults}\n`

if (splits.length) {
  md += '\n## Non-singleton classes (counterexamples to κ-congruence)\n\n'
  for (const s of splits) {
    md += `### ${s.rule} — κ = {${s.kappa}} — ${s.results.size} distinct results over ${s.windows} windows\n\n`
    for (const [r, v] of s.results) {
      md += `- run \`${v.run}\`, window ${JSON.stringify(v.witness.window)}\n`
      md += `  - result: \`${r}\`\n`
      md += `  - access: \`${JSON.stringify(v.witness.script)}\`\n`
    }
    md += '\n'
  }
} else {
  md += '\n## Non-singleton classes\n\nNone: every κ-class in the union carries a single level-1 result.\n'
}

writeFileSync(new URL('./out/SUMMARY.md', import.meta.url), md)
console.log(md.split('\n## Non-singleton classes')[0])
console.log(`non-singleton (level 1) over the union: ${bad}`)
