#!/usr/bin/env node
// T* — the runner.
//
//   PROOF_TARGET=model                 (default) the reference model
//   PROOF_TARGET=cordis                a real build; CORDIS_LIB selects it
//   PROOF_TARGET=cordis-node           the two-node distributed target
//   TSTAR_ONLY=S-Div-1,S-Unl-6         run a subset
//   TSTAR_VERBOSE=1                    print the observation of every failure
//
// The conventions are `../../proof/src/target.mjs`'s, unchanged.
//
// What a run does per script:
//
//   1. Executes ρ against the REFERENCE MODEL, producing the specification's
//      observation at the pointed configuration.
//   2. Executes ρ against the target build.
//   3. Half (1) of V_{r,s}: ≡-compares the two observations — report always,
//      ordinary event word too unless Appendix E marks the word
//      schedule-dependent.
//   4. Half (2) of V_{r,s}: evaluates the named clauses of `verdicts.mjs`
//      against the TARGET's observation.
//
// With PROOF_TARGET=model, step 2 is an independent second model run, so
// step 3 additionally checks determinism and step 4 is the soundness gate of
// Theorem 2: the specification must satisfy its own suite.

import { createSystem } from '../../proof/src/target.mjs'
import { createModelSystem } from '../../proof/src/adapter-model.mjs'
import { TSTAR_SCRIPTS, REACHABLE_ALPHABET } from './scripts.mjs'
import { checkClauses } from './verdicts.mjs'
import { observe, report } from './observe.mjs'

const TARGET = process.env.PROOF_TARGET ?? 'model'
const VERBOSE = Boolean(process.env.TSTAR_VERBOSE)

function selected() {
  const only = process.env.TSTAR_ONLY
  if (!only) return TSTAR_SCRIPTS
  const wanted = new Set(only.split(',').map(s => s.trim()))
  return TSTAR_SCRIPTS.filter(s => wanted.has(s.id))
}

async function runOn(makeSystem, script) {
  const sys = await makeSystem()
  try {
    return await observe(sys, script)
  } finally {
    await sys.dispose()
  }
}

const json = (value) => JSON.stringify(value, (_k, v) => (v === undefined ? '⊥' : v))

/** ≡ on the report half: states, recorded outcomes, store, refusal reasons. */
function diffReport(spec, impl, { quiescent = true } = {}) {
  const a = report(spec)
  const b = report(impl)
  const out = []
  // A script that deliberately ends without a settle (its target is a refusal)
  // has no quiescent report: the reference model only takes lifecycle steps
  // inside `settle`, while a real build begins eagerly, so `states` there is
  // mid-flight on one side and not on the other. Both are fair schedules of the
  // specification, so the field is not compared. Finding F4 in README.md.
  const fields = quiescent
    ? ['states', 'errors', 'store', 'storeLenient', 'extras']
    : ['store', 'storeLenient', 'extras']
  for (const field of fields) {
    for (const key of new Set([...Object.keys(a[field]), ...Object.keys(b[field])])) {
      if (json(a[field][key]) !== json(b[field][key])) {
        out.push(`${field}.${key}: spec ${json(a[field][key])} ≠ impl ${json(b[field][key])}`)
      }
    }
  }
  if (json(a.refusals) !== json(b.refusals)) {
    out.push(`refusals: spec ${json(a.refusals)} ≠ impl ${json(b.refusals)}`)
  }
  return out
}

/** ≡ on the ordinary event word: same letters, same order. */
function diffWord(spec, impl) {
  if (json(spec.word) === json(impl.word)) return []
  const n = Math.max(spec.word.length, impl.word.length)
  for (let i = 0; i < n; i++) {
    if (spec.word[i] !== impl.word[i]) {
      return [`word position ${i}: spec ${json(spec.word[i])} ≠ impl ${json(impl.word[i])}`
        + `\n        spec: ${spec.word.join(' | ')}`
        + `\n        impl: ${impl.word.join(' | ')}`]
    }
  }
  return []
}

export async function runSuite({ target = TARGET, scripts = selected() } = {}) {
  const results = []
  for (const script of scripts) {
    const result = {
      id: script.id,
      rule: script.rule,
      letters: script.letters,
      alsoRealizes: script.alsoRealizes ?? [],
      source: script.source,
      status: 'pass',
      violations: [], // clause failures + ≡ differences: conformance verdict
      unrealized: [], // canonical-branch clauses the target's schedule missed
      skipped: 0,
      spec: null,
      impl: null,
    }
    try {
      result.spec = await runOn(() => createModelSystem({}), script)
    } catch (error) {
      result.status = 'fail'
      result.violations.push({ kind: 'harness', why: `specification run threw: ${error?.stack ?? error}` })
      results.push(result)
      continue
    }
    try {
      result.impl = await runOn(createSystem, script)
    } catch (error) {
      result.status = 'fail'
      result.violations.push({ kind: 'harness', why: `target run threw: ${error?.stack ?? error}` })
      results.push(result)
      continue
    }

    // A script whose ρ anchors an input on the rule-certificate channel
    // (audit §3.5's `at cert(r,n) do λ`) cannot be *driven* on a target that
    // has no such channel: the input is never delivered, so no attempt at r is
    // made and there is nothing to compare. §5.4's vocabulary proviso applies
    // to the driving half of an experiment exactly as it does to the observing
    // half. Reported as not-presented, not as a conformance failure.
    if (script.anchorVocabulary === 'certificate' && result.impl.kind !== 'model') {
      result.status = 'not-presented'
      result.violations.push({
        kind: 'not-presentable',
        why: `ρ anchors an input at ${script.program.filter(a => a.do === 'anchor').map(a => a.at).join(', ')}, `
          + 'a rule certificate; this target emits no certificate channel, so the input cannot be '
          + 'placed at the window the occurrence lives in (§5.4 vocabulary proviso; audit §3.5/A16).',
      })
      results.push(result)
      continue
    }

    // Obligation (D-F): the anchor event must be produced on every fair
    // schedule, so that the attempt point is determinate.
    for (const anchor of result.impl.anchors) {
      if (anchor.fired) continue
      result.violations.push({
        kind: 'anchor',
        why: `the anchored input at ε = ${anchor.at} was never delivered — the target never produced `
          + 'the anchor event, so the pointed configuration of the derivation was never reached '
          + '(obligation (D-F): ε must occur on every fair schedule of ρ).',
      })
    }

    // Half (1): ≡-equality with the specification's outcome at the pointed
    // configuration. Report always; word unless Appendix E marks it
    // schedule-dependent (then obligation (D-G)'s invariant subword is carried
    // by the script's own clauses instead).
    for (const line of diffReport(result.spec, result.impl, { quiescent: script.quiescent !== false })) {
      result.violations.push({ kind: 'equiv-report', why: line })
    }
    if (script.wordInvariant !== false) {
      for (const line of diffWord(result.spec, result.impl)) {
        result.violations.push({ kind: 'equiv-word', why: line })
      }
    }

    // Half (2): the load-bearing clauses Appendix E names.
    const certificates = result.impl.kind === 'model'
    for (const outcome of checkClauses(script, result.impl, { certificates })) {
      if (outcome.status === 'skip') { result.skipped += 1; continue }
      if (outcome.status === 'pass') continue
      const entry = { kind: outcome.kind, why: outcome.why, error: outcome.error }
      if (outcome.kind === 'branch' && !certificates) result.unrealized.push(entry)
      else result.violations.push(entry)
    }
    if (result.violations.length) result.status = 'fail'
    results.push(result)
  }
  return { target, results }
}

// ---- reporting ------------------------------------------------------------

function coverage(results) {
  const realized = new Set()
  const notRealized = new Set()
  for (const r of results) {
    // A script only credits its TARGET letters when it passed *and* its
    // canonical branch was taken: a `branch` clause reported unrealized means
    // the target's schedule never presented the occurrence, so the letter is
    // untested on this run even though the script conformed.
    // The same applies to the co-realized letters: they are the letters of the
    // window the derivation points at, and a run that took another branch did
    // not present that window either. (Pre-closure this credited them on any
    // pass, which over-credited exactly the schedule-dependent L-Divert
    // scripts — e.g. D4 on the distributed target, where no divert occurs.)
    if (r.status === 'pass' && !r.unrealized.length) {
      for (const letter of [...r.letters, ...(r.alsoRealizes ?? [])]) realized.add(letter)
    } else {
      for (const letter of r.letters) notRealized.add(letter)
    }
  }
  const all = Object.values(REACHABLE_ALPHABET).flat()
  for (const letter of realized) notRealized.delete(letter)
  return {
    target: [...realized].filter(l => all.includes(l)).sort(),
    uncovered: all.filter(l => !realized.has(l)).sort(),
    total: all.length,
  }
}

export function printReport({ target, results }) {
  const width = Math.max(...results.map(r => r.id.length))
  console.log(`\nT* — ${results.length} canonical experiments against PROOF_TARGET=${target}`)
  if (target === 'cordis') console.log(`     CORDIS_LIB=${process.env.CORDIS_LIB ?? '(default: deepseek-harness/vendor/cordis)'}`)
  console.log('')
  for (const r of results) {
    const mark = r.status === 'pass' ? 'PASS' : r.status === 'not-presented' ? 'N/P ' : 'FAIL'
    const flags = [
      r.unrealized.length ? `${r.unrealized.length} branch-unrealized` : null,
      r.skipped ? `${r.skipped} cert-skipped` : null,
    ].filter(Boolean)
    console.log(`  ${mark}  ${r.id.padEnd(width)}  ${r.rule.padEnd(9)} [${r.letters.join(',')}]`
      + `  ${r.source}${flags.length ? '  (' + flags.join(', ') + ')' : ''}`)
    for (const v of r.violations) {
      console.log(`        ✗ ${v.kind}: ${v.why}${v.error ? ` [threw: ${v.error}]` : ''}`)
    }
    if (VERBOSE && r.status !== 'pass' && r.impl) {
      console.log(`        spec word: ${r.spec.word.join(' | ')}`)
      console.log(`        impl word: ${r.impl.word.join(' | ')}`)
      console.log(`        impl states: ${json(r.impl.states)}  store: ${json(r.impl.store)}`)
    }
    for (const u of r.unrealized) {
      console.log(`        ~ letter-not-realized on this target's schedule: ${u.why.split('.')[0]}.`)
    }
  }
  const passed = results.filter(r => r.status === 'pass').length
  const notPresented = results.filter(r => r.status === 'not-presented')
  const cov = coverage(results)
  console.log('')
  console.log(`  scripts passed : ${passed}/${results.length}`)
  if (notPresented.length) {
    console.log(`  not presentable: ${notPresented.length} (${notPresented.map(r => r.id).join(', ')})`
      + ` — ρ anchors an input on the certificate channel this target lacks`)
  }
  console.log(`  letters covered: ${cov.target.length}/${cov.total} reachable occurrences`)
  if (cov.uncovered.length) console.log(`  uncovered      : ${cov.uncovered.join(', ')}`)
  const failures = results.filter(r => r.status !== 'pass' && r.status !== 'not-presented')
  if (failures.length) {
    console.log('')
    console.log('  failures by rule and clause:')
    for (const r of failures) {
      for (const v of r.violations) {
        console.log(`    ${r.id} (${r.rule} / ${r.letters.join(',')}) — ${v.kind}`)
        console.log(`      ${v.why.split('\n')[0]}`)
      }
    }
  }
  const unrealized = results.filter(r => r.unrealized.length)
  if (unrealized.length) {
    console.log('')
    console.log('  canonical-branch letters not realized on this target\'s schedule')
    console.log('  (the specification\'s own outcome set contains the other branch, so this')
    console.log('   is not a conformance violation — it is a coverage gap of the run):')
    for (const r of unrealized) console.log(`    ${r.id} [${r.letters.join(',')}]`)
  }
  console.log('')
  return passed === results.length
}

if (import.meta.url === `file://${process.argv[1]}`) {
  const run = await runSuite()
  const ok = printReport(run)
  process.exit(ok ? 0 : 1)
}
