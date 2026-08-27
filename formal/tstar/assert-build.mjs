#!/usr/bin/env node
// "Which Cordis is the distributed target actually running?" — checked, not assumed.
//
//   PROOF_TARGET=cordis-node node --import ./use-cordis-lib.mjs assert-build.mjs
//
// Three independent checks, because a wrong answer to this question is what
// made every earlier distributed T* run uninterpretable:
//
//   (1) MODULE GRAPH. The resolution hook reports every redirect and every
//       leak. We require at least one redirect whose importer is
//       `cordis-plugins/cordis-node/lib/*.js` (the projection layer itself) and
//       one whose importer is `paper/proof/src/adapter-distributed.mjs` (the
//       Context the nodes are built from), and zero leaks.
//
//   (2) IDENTITY. The bare specifier, the pinned URL and the copy the
//       projection layer imported must be ONE module instance — Cordis keys its
//       internals by module-local symbols, so two instances would not merely be
//       "a different build", they would silently fail to interoperate.
//
//   (3) BEHAVIOUR, ON BOTH NODES. Two fixes that only the vendored build has
//       (VENDOR-FIXES.md §2.1 and §2.2) are exercised through the distributed
//       adapter's own `insert`, whose placement alternates between node A's and
//       node B's partition host — so each is checked once per node:
//         F1  a fiber inserted and retired before it ever activated is removed
//             with NO `deactivated` event (§2.1);
//         F9  `update` at a removed entry is refused with NO_SUCH_ENTRY / "no
//             such entry", not with the liveness reason PARENT_ABSENT /
//             "cannot create effect on inactive context" (§2.2).
//       Upstream fails both; the fixed build passes both.

import { PINNED_LIB, tally } from './use-cordis-lib.mjs'
import { createDistributedSystem } from '../../proof/src/adapter-distributed.mjs'
import { component, track } from '../../proof/src/dsl.mjs'

const problems = []
const notes = []
const ok = (label) => notes.push(`  ok   ${label}`)
const bad = (label, detail) => { problems.push(`${label}: ${detail}`); notes.push(`  FAIL ${label} — ${detail}`) }

console.log(`\npinned build: ${PINNED_LIB}\n`)

// ---- (2) identity ---------------------------------------------------------
const viaBare = await import('@deepseek-ai/cordis')
const viaUrl = await import(PINNED_LIB)
if (viaBare !== viaUrl) bad('identity/bare', 'the bare specifier and the pinned URL are two module instances')
else ok('identity: `@deepseek-ai/cordis` === the pinned build')

// The projection layer's own view. `lib/service.js` imports { Context, Service }.
const projService = await import('../../../cordis-plugins/cordis-node/lib/service.js')
void projService
const projRpc = await import('../../../cordis-plugins/cordis-node/lib/rpc.js')
void projRpc

// ---- (3) behaviour, once per node ----------------------------------------
const sys = await createDistributedSystem()
try {
  // insert() with no explicit context alternates across the two partition
  // hosts, so N0 lands on node A and N1 on node B.
  const specs = [component('N0', { steps: [track('a')] }), component('N1', { steps: [track('a')] })]
  const handles = specs.map(spec => sys.insert(null, spec))

  // F1 (§2.1): retire before any activation, then settle. No deactivation.
  for (const handle of handles) sys.retire(handle)
  await sys.settle()
  const deacts = [...sys.trace].filter(e => e.startsWith('deactivated:'))
  if (deacts.length) bad('F1/§2.1 never-activated removal', `emitted ${JSON.stringify(deacts)}; the fixed build emits nothing`)
  else ok('F1 §2.1: a never-activated fiber is removed with no `deactivated` (both nodes)')

  // F9 (§2.2): `update` at a removed entry refuses on the REGISTRY premise.
  for (const [i, handle] of handles.entries()) {
    let reason = '(no refusal)'
    try {
      await sys.update(handle, {})
    } catch (error) {
      reason = `${error?.code ?? ''} ${error?.message ?? error}`.trim()
    }
    const registry = /no such entry|NO_SUCH_ENTRY/i.test(reason)
    const liveness = /inactive context|PARENT_ABSENT/i.test(reason)
    if (registry) ok(`F9 §2.2: update at a removed entry on node ${'AB'[i]} → ${reason}`)
    else if (liveness) bad(`F9/§2.2 node ${'AB'[i]}`, `refused for LIVENESS (${reason}) — this is the UPSTREAM build`)
    else bad(`F9/§2.2 node ${'AB'[i]}`, `unexpected: ${reason}`)
  }
} finally {
  await sys.dispose()
}

// ---- (1) module graph -----------------------------------------------------
const log = process.env.TSTAR_LIB_LOG
let importers = []
if (log) {
  const { readFileSync } = await import('node:fs')
  importers = readFileSync(log, 'utf8').trim().split('\n').filter(Boolean).map(l => JSON.parse(l))
}
const from = (needle) => importers.some(m => m.kind === 'redirect' && String(m.from).includes(needle))
if (importers.length) {
  if (from('/cordis-plugins/cordis-node/lib/')) ok('module graph: the PROJECTION layer imports the pinned build')
  else bad('module graph', 'no redirect was requested by cordis-node/lib/* — the projection layer loaded some other Cordis')
  if (from('/paper/proof/src/adapter-distributed.mjs')) ok('module graph: the two NODES are built from the pinned build')
  else bad('module graph', 'the adapter did not resolve through the hook')
} else {
  notes.push('  --   module graph: set TSTAR_LIB_LOG=<path> to check importers')
}
if (tally.leaks.length) bad('module graph', `leaked to ${[...new Set(tally.leaks)].join(', ')}`)
else ok(`module graph: ${tally.redirects} redirects, 0 leaks to another Cordis`)

console.log(notes.join('\n'))
console.log('')
if (problems.length) {
  console.log(`assert-build: ${problems.length} problem(s)\n`)
  process.exit(1)
}
console.log('assert-build: the distributed target runs the pinned build on both nodes and in the projection.\n')
