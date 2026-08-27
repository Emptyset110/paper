// Module-resolution hook: transparently substitute the INSTRUMENTED copy of
// the reference model for the original when the untouched proof suite runs.
// paper/proof/ is never modified; the substitution happens at load time.

const INSTRUMENTED = new URL('./model.mjs', import.meta.url).href

export async function resolve(specifier, context, nextResolve) {
  const resolved = await nextResolve(specifier, context)
  if (resolved.url.endsWith('/paper/proof/src/model.mjs')) {
    return { ...resolved, url: INSTRUMENTED }
  }
  return resolved
}
