// D3 item 5 — audit of the existing 32-test suite.
//
// Each named scenario of paper/proof/tests/ is executed ONCE, in its own
// process, against the INSTRUMENTED reference semantics (redirect-loader
// substitutes explorer/model.mjs for proof/src/model.mjs at load time; the
// proof tree itself is untouched). The certificate hook records every
// (rule, signature) occurrence the scenario exercises — fired, refused, and
// disabled — keyed exactly like the explorer's signature sets, so coverage
// is a set comparison.
//
// Scoping (see explorer-report.md): the audit runs the default fifo
// schedule (the exhaustive-schedule driver is exercised separately by
// run-necessity.mjs); coverage is counted over certificates, which are
// schedule-robust for these deterministic-modulo-confluence scenarios.

import { spawnSync } from 'node:child_process'
import { readFileSync, writeFileSync, mkdtempSync, rmSync } from 'node:fs'
import { tmpdir } from 'node:os'
import { join } from 'node:path'

const here = new URL('.', import.meta.url).pathname
const proofTests = join(here, '../../proof/tests')

const TESTS = {
  'rules-o.test.mjs': ['R1.1 insert-activates-fresh', 'R1.2 insert-under-removed-parent-rejected',
    'R1.3 dynamic-provision-conflict-fails-offender', 'R1.4 declared-provision-disjointness-at-insert',
    'R2.1 retire-runs-recovery', 'R2.2 retire-pending-clean',
    'R3.1 removal-follows-inactivity', 'R3.2 registration-cascade-recovers-children'],
  'rules-activation.test.mjs': ['R4.1 begin-requires-satisfaction', 'R4.2 provider-arrival-wakes-pending',
    'R4.3 satisfaction-counts-active-only', 'R4.4 failure-latch-unchanged-env',
    'R5.1 iteration-order-and-lifo-recovery', 'R6.1 divert-honors-target-change',
    'R7.1 raise-recovers-then-latches', 'RU.1 update-restarts-with-new-config'],
  'rules-deactivation.test.mjs': ['R8.1 leaving-provider-reads-own-deps',
    'R9.1 withdrawal-guard-orders-teardown', 'R9.2 recovery-exactness-on-deactivation'],
  'coeffects.test.mjs': ['C1.1 provision-value-operations', 'C2.1 overwrite-observability-dichotomy',
    'C3.1 isolation-independence', 'C3.2 isolation-label-join', 'C4.1 intercept-nearest-wins',
    'C5.1 undeclared-access-rejected', 'C5.2 ancestry-authorized-access', 'C5.3 declared-inactive-access'],
  'metatheory.test.mjs': ['M1 interleaved-recovery-independence', 'M2 dependency-ordering-chain',
    'M3 provider-identity-coherence', 'M4 quiescence-on-unsatisfiable', 'M5 confluence-across-histories'],
}

const escapeRe = s => s.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')

const tmp = mkdtempSync(join(tmpdir(), 'audit32-'))
const coverage = {}
let failures = 0

for (const [file, names] of Object.entries(TESTS)) {
  for (const name of names) {
    const certOut = join(tmp, 'certs.json')
    const result = spawnSync(process.execPath, [
      '--import', join(here, 'register-audit.mjs'),
      '--test-name-pattern', `^${escapeRe(name)}$`,
      join(proofTests, file),
    ], {
      cwd: here,
      env: { ...process.env, PROOF_TARGET: 'model', MODEL_MUTANT: '', CERT_OUT: certOut },
      encoding: 'utf8',
      timeout: 60_000,
    })
    const out = `${result.stdout}\n${result.stderr}`
    const passed = new RegExp(`^\\s*ok \\d+ - ${escapeRe(name)}`, 'm').test(out)
    const ran = passed || new RegExp(`^\\s*not ok \\d+ - ${escapeRe(name)}`, 'm').test(out)
    if (!ran || !passed) {
      failures += 1
      console.error(`AUDIT PROBLEM: ${name} ran=${ran} passed=${passed}`)
    }
    let certs = []
    try {
      certs = JSON.parse(readFileSync(certOut, 'utf8'))
    } catch { /* no certs written */ }
    rmSync(certOut, { force: true })
    coverage[name] = { passed, sigs: Object.fromEntries(certs) }
    console.log(`${name}: ${certs.length} distinct signatures ${passed ? '' : '(NOT GREEN)'}`)
  }
}
rmSync(tmp, { recursive: true, force: true })

writeFileSync(join(here, 'out/audit-32.json'), JSON.stringify(coverage, null, 1))
console.log(`\naudit written to out/audit-32.json; problems: ${failures}`)
process.exit(failures ? 1 : 0)
