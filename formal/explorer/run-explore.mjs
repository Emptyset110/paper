// D3 driver: run the all-successor exploration, extract per-rule reachable
// signature sets, and generate the bounded suite T_B.
//
// Usage: node run-explore.mjs [--maxFibers=N] [--shapes=P,C,...] [--maxStates=N]
//        [--timeBudgetMs=N] [--tag=name]
// Outputs (out/): exploration-<tag>.json (stats), signatures-<tag>.json,
// signatures-<tag>.md, tb-<tag>.json.

import { writeFileSync } from 'node:fs'
import { explore, pathTo } from './explore.mjs'
import { sigKey, RULE_ORDER } from './sig.mjs'
import { observe } from './runner.mjs'
import { CATALOG } from './catalog.mjs'

const args = Object.fromEntries(process.argv.slice(2).map(a => {
  const m = a.match(/^--([^=]+)(?:=(.*))?$/)
  return m ? [m[1], m[2] ?? true] : [a, true]
}))

const tag = args.tag ?? 'B'
const opts = {}
if (args.maxFibers) opts.maxFibers = Number(args.maxFibers)
if (args.shapes) opts.shapes = args.shapes.split(',')
if (args.maxStates) opts.maxStates = Number(args.maxStates)
if (args.timeBudgetMs) opts.timeBudgetMs = Number(args.timeBudgetMs)
if (args.noChildInserts) opts.childInserts = false
if (args.noIsolate) opts.isolate = false
if (args.noUpdates) opts.updates = false
if (args.noSetowns) opts.setowns = false

console.log(`[explore:${tag}] options`, { ...opts, shapes: opts.shapes?.join(',') ?? 'ALL' })
const result = explore(opts)
console.log(`[explore:${tag}] stats`, result.stats)

// ---- signature tables ---------------------------------------------------

const byRule = new Map()
for (const [key, first] of result.sigFirst.entries()) {
  const rule = first.cert.rule
  if (!byRule.has(rule)) byRule.set(rule, [])
  byRule.get(rule).push({
    sig: key,
    decision: first.cert.decision,
    fields: first.cert.fields,
    depth: first.depth,
    count: result.sigCount.get(key),
    state: first.state,
    action: first.action,
  })
}
for (const list of byRule.values()) list.sort((a, b) => a.sig < b.sig ? -1 : 1)

const rules = [...byRule.keys()].sort(
  (a, b) => (RULE_ORDER.indexOf(a) + 100 * (RULE_ORDER.indexOf(a) < 0)) - (RULE_ORDER.indexOf(b) + 100 * (RULE_ORDER.indexOf(b) < 0)))

const sigJson = {
  tag,
  options: { ...result.options, shapes: result.options.shapes.join(',') },
  stats: result.stats,
  rules: Object.fromEntries(rules.map(r => [r, byRule.get(r).map(({ sig, decision, fields, depth, count }) =>
    ({ sig, decision, fields, depth, count }))])),
}
writeFileSync(`out/signatures-${tag}.json`, JSON.stringify(sigJson, null, 1))

let md = `# Reachable occurrence signatures (bound tag: ${tag})\n\n`
md += `States (normalized): ${result.stats.normalizedStates}` +
  ` — expanded: ${result.stats.expandedStates}, edges: ${result.stats.edges}` +
  ` (refusal edges: ${result.stats.refusalEdges}), quiescent: ${result.stats.quiescentStates},` +
  ` internal cycle: ${result.stats.internalCycle}, truncated: ${result.stats.truncated},` +
  ` wall-clock: ${(result.stats.wallClockMs / 1000).toFixed(1)}s\n\n`
for (const rule of rules) {
  const list = byRule.get(rule)
  md += `## ${rule} — ${list.length} reachable signatures\n\n`
  md += '| # | decision | fields | first depth | edge occurrences |\n|---|---|---|---|---|\n'
  list.forEach((s, i) => {
    md += `| ${rule}.${i + 1} | ${s.decision} | \`${JSON.stringify(s.fields)}\` | ${s.depth} | ${s.count} |\n`
  })
  md += '\n'
}
writeFileSync(`out/signatures-${tag}.md`, md)
console.log(`[explore:${tag}] signatures: ${result.sigFirst.size} across ${rules.length} rules`)

// ---- T_B generation -----------------------------------------------------

if (!args.noTb) {
  console.log(`[tb:${tag}] generating tests (one per reachable signature)...`)
  const t0 = Date.now()
  const tests = []
  let idx = 0
  for (const [key, first] of result.sigFirst.entries()) {
    const access = pathTo(result.states, first.state)
    const script = first.action ? [...access, first.action] : access
    // The distinguishing observation is computed by concrete baseline replay
    // (per-action refusals/events/certificates + the full settle-outcome set).
    const expected = observe(script)
    // Self-check: the replay must actually exercise the target occurrence —
    // fired/refused sigs must appear in the final action's certificates;
    // disabled sigs must appear in the settle certificate set.
    const realized = first.action
      ? expected.perAction.at(-1).certs.includes(key)
      : expected.settle.settleCerts.includes(key)
    if (!realized) console.warn(`[tb:${tag}] WARNING: ${key} not realized by its script`)
    tests.push({
      realized,
      id: `TB.${++idx}`,
      sig: key,
      rule: first.cert.rule,
      decision: first.cert.decision,
      script,
      expected,
    })
    if (idx % 100 === 0) console.log(`[tb:${tag}] ${idx}/${result.sigFirst.size}`)
  }

  // Coda test (outside the graph, see report): O-Insert under a REMOVED
  // parent must be refused. The graph cannot host this occurrence because
  // canonical states drop unreferenced removed fibers.
  const coda = [
    { t: 'insert', shape: 'T', ctx: 'root' }, // uid 1, stays pending
    { t: 'retire', f: 0 }, // retired while Inactive(⊥): never begins
    { t: 'remove', f: 0 }, // O-Remove disposes it
    { t: 'insert', shape: 'T', ctx: 'child-uid', uid: 1 }, // refused: removed parent
  ]
  {
    const expected = observe(coda)
    tests.push({
      id: `TB.${++idx}`,
      sig: sigKey({ rule: 'O-Insert', decision: 'refused', fields: { parent: 'removed', declaredConflict: false, realm: 'root' } }),
      rule: 'O-Insert',
      decision: 'refused',
      script: coda,
      coda: true,
      expected,
    })
  }

  // Coda test 2: intercept resolution (Definition 31). interceptMerged is a
  // pure derived operation that no LTS transition invokes, so the graph
  // cannot exercise it; this probe evaluates a depth-2 chain directly.
  {
    const script = [{ t: 'iprobe' }]
    const expected = observe(script)
    tests.push({
      id: `TB.${++idx}`,
      sig: sigKey({ rule: 'A-Intercept', decision: 'fired', fields: { entries: 2 } }),
      rule: 'A-Intercept',
      decision: 'fired',
      script,
      coda: true,
      expected,
    })
  }

  // Coda tests 3/4: the EXTERNAL Def.-23 read (Algorithm 6 driven by the
  // environment) on a declared-but-uncommitted fiber — the inactive-declared
  // access classes, unreachable through in-lifecycle reads (see report §7).
  const rprobes = [
    { name: 'inactive-declared-np', script: [
      { t: 'insert', shape: 'CR', ctx: 'root' }, // pending: k1 unprovided
      { t: 'rprobe', f: 0, key: 'k1' },
    ] },
    { name: 'inactive-declared-p', script: [
      { t: 'insert', shape: 'P', ctx: 'root' },
      { t: 'life', f: 0, rule: 'L-Begin' },
      { t: 'life', f: 0, rule: 'L-Iter' },
      { t: 'life', f: 0, rule: 'L-Finish' }, // P active: k1 provided
      { t: 'insert', shape: 'CC', ctx: 'root' }, // pending: k2 unprovided
      { t: 'rprobe', f: 1, key: 'k1' },
    ] },
  ]
  for (const probe of rprobes) {
    const expected = observe(probe.script)
    tests.push({
      id: `TB.${++idx}`,
      sig: sigKey({ rule: 'A-Read', decision: 'fired', fields: { cls: probe.name } }),
      rule: 'A-Read',
      decision: 'fired',
      script: probe.script,
      coda: true,
      expected,
    })
  }

  writeFileSync(`out/tb-${tag}.json`, JSON.stringify({ tag, tests }, null, 1))
  console.log(`[tb:${tag}] ${tests.length} tests written in ${((Date.now() - t0) / 1000).toFixed(1)}s`)
}
