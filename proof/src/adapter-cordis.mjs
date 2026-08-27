// Adapter binding the conformance suite to a real Cordis build.
//
// A ComponentSpec is interpreted as an *async generator* plugin: cordis
// checks the epoch before every `await iter.next()` (fiber.ts `_execute`),
// so one yielded disposer per DSL step realizes the paper's effect iterator
// (Definition 51) with an L-Divert opportunity at every step boundary —
// the exact correspondence Table 2 row "L-Begin, L-Iter, L-Finish" names.
//
// Which build to test comes from the caller: the unfixed upstream vendor
// (what `@deepseek-ai/cordis` 4.0.1 resolves to in this workspace) or the
// calculus-aligned build in deepseek-harness/vendor/cordis.

// FiberState is a const enum, erased from the build; ordinals per
// paper-review/README.md ("API pitfalls").
import { createTrace } from './dsl.mjs'

const STATE_BY_ORDINAL = ['pending', 'loading', 'active', 'failed', 'disposed', 'unloading']

function render(value) {
  if (value === undefined) return 'undefined'
  try {
    return JSON.stringify(value)
  } catch {
    return String(value)
  }
}

function accessCode(error) {
  const message = String(error?.message ?? error)
  if (message.includes('in inactive context')) return 'INACTIVE_ACCESS'
  if (message.includes('without inject')) return 'UNDECLARED_ACCESS'
  return 'ERR'
}

/** Create a system bound to the Cordis build at `libPath` (ESM entry). */
export async function createCordisSystem(libPath) {
  const lib = await import(libPath)
  const { Context, Service } = lib
  const root = new Context()
  const trace = createTrace()
  const nameOf = new WeakMap() // Fiber -> spec name
  const pluginOf = new Map() // spec -> plugin function (runtime identity)

  // Shared lifecycle vocabulary: `active:<name>` when a fiber reaches ACTIVE,
  // `deactivated:<name>` when it leaves UNLOADING without returning to ACTIVE.
  root.on('internal/status', (fiber, oldState) => {
    const name = nameOf.get(fiber)
    if (!name) return
    if (fiber.state === 2) trace.push(`active:${name}`)
    if (oldState === 5 && fiber.state !== 2) trace.push(`deactivated:${name}`)
  })

  const makePlugin = (spec) => {
    let plugin = pluginOf.get(spec)
    if (plugin) return plugin
    plugin = async function* (ctx, config) {
      for (const step of spec.steps) {
        switch (step.do) {
          case 'provide': {
            ctx.provide(step.key, step.value)
            yield () => {}
            break
          }
          case 'track': {
            trace.push(`apply:${spec.name}:${step.tag}`)
            yield () => {
              trace.push(`revert:${spec.name}:${step.tag}`)
            }
            break
          }
          case 'trackMutate': {
            trace.push(`apply:${spec.name}:${step.tag}`)
            yield () => {
              const value = ctx.get(step.key, false)
              if (value && typeof value === 'object') value[step.field] = step.to
              trace.push(`revert:${spec.name}:${step.tag}`)
            }
            break
          }
          case 'trackReadOnRevert': {
            trace.push(`apply:${spec.name}:${step.tag}`)
            yield () => {
              try {
                const value = ctx[step.key]
                const shown = step.field ? value?.[step.field] : value
                trace.push(`revertread:${spec.name}:${step.key}=${render(shown)}`)
              } catch (error) {
                trace.push(`revertreadfail:${spec.name}:${step.key}:${accessCode(error)}`)
              }
            }
            break
          }
          case 'read': {
            try {
              const value = ctx[step.key]
              trace.push(`read:${spec.name}:${step.key}=${render(value)}`)
            } catch (error) {
              trace.push(`readfail:${spec.name}:${step.key}:${accessCode(error)}`)
              if (step.strict) throw error
            }
            yield () => {}
            break
          }
          case 'set': {
            ctx.set(step.key, step.value)
            trace.push(`setvalue:${spec.name}:${step.key}`)
            yield () => {}
            break
          }
          case 'register': {
            const child = ctx.plugin(makePlugin(step.spec), step.config)
            // ctx.plugin returns a wrapper prototyped on the fiber; register
            // both so lifecycle tracing resolves whichever object it sees.
            nameOf.set(Object.getPrototypeOf(child), step.spec.name)
            nameOf.set(child, step.spec.name)
            trace.push(`registered:${spec.name}:${step.spec.name}`)
            yield () => {}
            break
          }
          case 'raise':
            throw new Error(step.message)
          case 'raiseUnless':
            if (!config?.[step.flag]) throw new Error(step.message ?? `flag ${step.flag} unset`)
            trace.push(`flagged:${spec.name}:${step.flag}`)
            yield () => {}
            break
          case 'trace':
            trace.push(step.text)
            yield () => {}
            break
          default:
            throw new Error(`unknown step: ${step.do}`)
        }
      }
    }
    Object.defineProperty(plugin, 'name', { value: spec.name })
    plugin.inject = [...spec.inject]
    if (spec.provide?.length) plugin.provide = [...spec.provide]
    pluginOf.set(spec, plugin)
    return plugin
  }

  const allFibers = () => {
    const fibers = []
    for (const runtime of root.registry.values()) {
      for (const fiber of runtime.fibers) fibers.push(fiber)
    }
    return fibers
  }

  return {
    kind: 'cordis',
    trace,
    root,
    lib,

    insert(ctx, spec, config) {
      const context = ctx ?? root
      const wrapped = context.plugin(makePlugin(spec), config)
      // The wrapper prototypes on the fiber; both resolve fields identically.
      nameOf.set(Object.getPrototypeOf(wrapped), spec.name)
      nameOf.set(wrapped, spec.name)
      return wrapped
    },
    retire(handle) {
      void Promise.resolve(handle.dispose()).catch(() => {})
    },
    async settle() {
      let quiet = 0
      for (let i = 0; i < 500; i++) {
        await new Promise(resolve => setImmediate(resolve))
        const busy = allFibers().some(fiber => fiber.inertia)
        if (busy) {
          quiet = 0
        } else if (++quiet >= 3) {
          return
        }
      }
      throw new Error('cordis system failed to settle')
    },
    state(handle) {
      return STATE_BY_ORDINAL[handle.state]
    },
    async error(handle) {
      try {
        await handle.await()
        return undefined
      } catch (error) {
        return error
      }
    },
    provided(key) {
      return root.get(key) !== undefined
    },
    readKey(key) {
      return root.get(key)
    },
    readKeyLenient(key) {
      return root.get(key, false)
    },
    childCtx(handle) {
      return handle.ctx
    },
    isolateCtx(ctx, key, label) {
      const target = ctx ?? root
      return target.isolate(key, label === undefined ? undefined : Symbol.for(`proof:${label}`))
    },
    interceptCtx(ctx, key, config) {
      return (ctx ?? root).intercept(key, config)
    },
    setOwn(handle, key, value) {
      handle.ctx.set(key, value)
    },
    update(handle, config) {
      return handle.update(config)
    },
    interceptMerged(handle, key, base) {
      const resolve = Service.prototype[Service.resolveConfig]
      return resolve.call({ ctx: handle.ctx, name: key, Config: undefined }, base)
    },
    /** External read through a fiber's context (Algorithm 6 discipline). */
    readVia(handle, key) {
      return handle.ctx[key]
    },
    async dispose() {
      for (const fiber of allFibers()) {
        void Promise.resolve(fiber.dispose()).catch(() => {})
      }
      await new Promise(resolve => setImmediate(resolve))
    },
  }
}
