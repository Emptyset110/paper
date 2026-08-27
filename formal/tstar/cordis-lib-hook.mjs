// A module-resolution hook that pins EVERY `@deepseek-ai/cordis` in the process
// to one build.
//
// Why this exists: `../../proof/src/adapter-distributed.mjs` hard-codes the
// Cordis it hands to the two nodes
// (`cordis-plugins/cordis-node/node_modules/@deepseek-ai/cordis`, i.e. the
// published 4.0.1 upstream), and `@rebuilding/cordis-node`'s own compiled
// `lib/*.js` imports the *bare* specifier `@deepseek-ai/cordis`, which resolves
// from its own `node_modules` to the same upstream copy. So the distributed
// target ran on upstream no matter what `CORDIS_LIB` said, and its T* failures
// were inherited from the base rather than contributed by the projection layer.
//
// The hook redirects both forms — the bare specifier and any resolution that
// lands on a `.../node_modules/@deepseek-ai/cordis/lib/index.js` — to a single
// URL. Both nodes' `Context`, the projection layer's `Context`/`Service`/
// `symbols`/`withProps`, and the adapter's own import therefore come from one
// module instance, which is also what Cordis's symbol-keyed internals require.
//
// It reports what it did: every redirect and every *leak* (a resolution that
// reached a different Cordis) is posted to the registrar, so "the fixed build
// is loaded" is checked rather than assumed.

/** @type {string | null} */
let target = null
/** @type {MessagePort | null} */
let port = null
/** @type {string | null} */
let adapterOverride = null

const CORDIS_ENTRY = '/node_modules/@deepseek-ai/cordis/lib/index.js'
const CORDIS_PKG = '/node_modules/@deepseek-ai/cordis/'
const ADAPTER = '/proof/src/adapter-distributed.mjs'

export async function initialize(data) {
  target = data.target
  port = data.port ?? null
  adapterOverride = data.adapterOverride ?? null
}

export async function resolve(specifier, context, nextResolve) {
  if (!target) return nextResolve(specifier, context)

  if (specifier === '@deepseek-ai/cordis') {
    port?.postMessage({ kind: 'redirect', via: 'bare', from: context.parentURL ?? '(entry)' })
    return { url: target, format: 'module', shortCircuit: true }
  }

  const result = await nextResolve(specifier, context)

  // Placement control (see `adapter-distributed-placed.mjs`). The override
  // module reaches the real adapter through the `?real` suffix, which this
  // predicate deliberately does not match. Matched on the RESOLVED url, because
  // `target.mjs` imports the adapter by the relative specifier
  // `./adapter-distributed.mjs`.
  if (adapterOverride && result.url.endsWith(ADAPTER) && result.url !== adapterOverride) {
    port?.postMessage({ kind: 'redirect', via: 'adapter', from: context.parentURL ?? '(entry)' })
    return { url: adapterOverride, format: 'module', shortCircuit: true }
  }

  if (result.url === target) return result

  if (result.url.endsWith(CORDIS_ENTRY)) {
    port?.postMessage({ kind: 'redirect', via: 'path', from: context.parentURL ?? '(entry)', was: result.url })
    return { ...result, url: target, shortCircuit: true }
  }
  if (result.url.includes(CORDIS_PKG)) {
    // A deep import into some *other* Cordis copy: not redirected, and a hole
    // in the pinning if it ever happens.
    port?.postMessage({ kind: 'leak', from: context.parentURL ?? '(entry)', url: result.url })
  }
  return result
}
