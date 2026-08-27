// `--import` entry that installs `cordis-lib-hook.mjs`.
//
//   CORDIS_LIB=<path|file: URL>   the build to pin to; a bare path is resolved
//                                 relative to `../../proof/src/` exactly as
//                                 `../../proof/src/target.mjs` resolves it.
//                                 Default: the calculus-aligned (fixed) build,
//                                 `deepseek-harness/vendor/cordis/lib/index.js`.
//   TSTAR_LIB_LOG=<path>          append one JSON line per redirect / leak.
//
// Usage:
//
//   PROOF_TARGET=cordis-node node --import ./use-cordis-lib.mjs run-tstar.mjs
//
// This is the *only* thing needed to re-point the distributed target: nothing
// under `paper/proof/` is modified, and `@rebuilding/cordis-node` needs no
// rebuild, because its compiled `lib/*.js` imports Cordis by bare specifier and
// the hook answers that specifier.

import { register } from 'node:module'
import { MessageChannel } from 'node:worker_threads'
import { appendFileSync } from 'node:fs'

const DEFAULT_LIB = new URL('../../../deepseek-harness/vendor/cordis/lib/index.js', import.meta.url).href

function resolveLib(value) {
  if (!value) return DEFAULT_LIB
  if (value.startsWith('file:')) return value
  // `target.mjs` documents CORDIS_LIB as "a path relative to ../../proof/src/".
  return new URL(value, new URL('../../proof/src/', import.meta.url)).href
}

export const PINNED_LIB = resolveLib(process.env.CORDIS_LIB)

const log = process.env.TSTAR_LIB_LOG
const { port1, port2 } = new MessageChannel()
/** @type {{redirects: number, leaks: string[]}} */
export const tally = { redirects: 0, leaks: [] }
port1.on('message', (message) => {
  if (message.kind === 'redirect') tally.redirects += 1
  else tally.leaks.push(message.url)
  if (log) appendFileSync(log, JSON.stringify(message) + '\n')
})
port1.unref()

// TSTAR_PLACEMENT=colocated — the degenerate single-block partition of the
// equivalence contract's placement space: cordis-node is installed, both nodes
// exist and are connected, but every root insert goes to node A's partition
// host so nothing crosses a link. It is the control that separates "distributed
// placement broke this" from "installing cordis-node broke this".
const placed = process.env.TSTAR_PLACEMENT === 'colocated'
  ? new URL('./adapter-distributed-placed.mjs', import.meta.url).href
  : null

register('./cordis-lib-hook.mjs', import.meta.url, {
  data: { target: PINNED_LIB, port: port2, adapterOverride: placed },
  transferList: [port2],
})
