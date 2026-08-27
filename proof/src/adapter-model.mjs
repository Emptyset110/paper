// Adapter binding the conformance suite to the reference model.
//
// The suite speaks only through this interface; `adapter-cordis.mjs` binds
// the same interface to the real runtime. See conformance.md §"Adapter
// contract" for the obligations on an adapter.

import { Model } from './model.mjs'

/** Create a model-backed system. `opts.mutant` selects a semantic mutant. */
export async function createModelSystem(opts = {}) {
  const model = new Model(opts)
  return {
    kind: 'model',
    trace: model.trace,
    root: model.rootCtx,

    insert(ctx, spec, config) {
      return model.insert(ctx ?? model.rootCtx, spec, config)
    },
    retire(handle) {
      model.retire(handle)
    },
    async settle() {
      model.sweep()
    },
    state(handle) {
      return model.stateOf(handle)
    },
    async error(handle) {
      return handle.outcome ?? undefined
    },
    /** σ_γ read at the root scope: Active providers only. */
    provided(key) {
      return model.providerOf(model.rootCtx, key) !== undefined
    },
    readKey(key) {
      const provider = model.providerOf(model.rootCtx, key)
      if (!provider) return undefined
      return provider.table.get(model.labelOf(model.rootCtx, key))?.value
    },
    /** Any installed fiber's binding, Active or not (lenient observation). */
    readKeyLenient(key) {
      for (const fiber of model.fibers.values()) {
        if (fiber.removed) continue
        const entry = fiber.table.get(model.labelOf(model.rootCtx, key))
        if (entry) return entry.value
      }
      return undefined
    },
    childCtx(handle) {
      return handle.ctx
    },
    isolateCtx(ctx, key, label) {
      return (ctx ?? model.rootCtx).isolated(key, label)
    },
    interceptCtx(ctx, key, config) {
      return (ctx ?? model.rootCtx).intercepted(key, config)
    },
    setOwn(handle, key, value) {
      model.setOwn(handle, key, value)
    },
    update(handle, config) {
      model.update(handle, config)
    },
    interceptMerged(handle, key, base) {
      return model.interceptMerged(handle, key, base)
    },
    /** External read through a fiber's context (Algorithm 6 discipline). */
    readVia(handle, key) {
      return model.readCommitted(handle, key)
    },
    async dispose() {},
  }
}
