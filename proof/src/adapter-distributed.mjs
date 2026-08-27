// Distributed adapter: the same suite over TWO Cordis nodes joined by
// `@rebuilding/cordis-node` (loopback transports, mutual partition mounts).
//
// The corollary the user-facing document states: once the single-process
// obligations hold and cordis-node's Distribution Equivalence Contract holds
// (cordis-node/docs/equivalence.md), running the same obligation set with the
// components placed across nodes must verify the distributed system. This
// adapter realizes the placement: inserts at the shared root alternate
// between node A's and node B's partition hosts, every other surface stays
// per-fiber local, and all σ_γ observations read node A — a provider placed
// on B is visible there only through projection.
//
// Deliberately node-local: isolation/interception contexts (realm labels are
// per-node vocabulary), so C3.x/C4.x place on node A. The report classifies
// them as node-local rather than distributed obligations.

import { createTrace } from './dsl.mjs'

const CORDIS_NODE_LIB = new URL('../../../cordis-plugins/cordis-node/lib/index.js', import.meta.url).href
const CORDIS_FOR_NODE = new URL('../../../cordis-plugins/cordis-node/node_modules/@deepseek-ai/cordis/lib/index.js', import.meta.url).href

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

/** Create a two-node distributed system. */
export async function createDistributedSystem() {
  const [{ Context, Service }, cordisNode] = await Promise.all([
    import(CORDIS_FOR_NODE),
    import(CORDIS_NODE_LIB),
  ])
  const { NodeService, connectLoopbackNodes, ExportId, NodeId } = cordisNode

  const { mkdtempSync, writeFileSync, rmSync } = await import('node:fs')
  const { join } = await import('node:path')
  const { tmpdir } = await import('node:os')
  const dir = mkdtempSync(join(tmpdir(), 'proof-dist-'))
  const nodeYaml = (name) => {
    const path = join(dir, `${name}.yml`)
    writeFileSync(path, `version: 1\nnode: ${name}\ntokenEnv: PROOF_UNUSED_TOKEN\n`)
    return path
  }

  const trace = createTrace()
  const nameOf = new WeakMap()
  const nodes = []

  const makeNode = async (name) => {
    const root = new Context()
    root.on('internal/status', (fiber, oldState) => {
      const label = nameOf.get(fiber)
      if (!label) return
      if (fiber.state === 2) trace.push(`active:${label}`)
      if (oldState === 5 && fiber.state !== 2) trace.push(`deactivated:${label}`)
    })
    await root.plugin(cordisNode, { path: nodeYaml(name) })
    // Partition host: the fiber whose subtree the peer mounts.
    const host = root.plugin(function host() {})
    await host
    const service = root.get('node')
    if (!service) throw new Error(`node service missing on ${name}`)
    return { name, root, host, service }
  }

  const a = await makeNode('paper-a')
  const b = await makeNode('paper-b')
  nodes.push(a, b)
  const disconnect = connectLoopbackNodes(a.service, b.service)
  const unpublishA = a.service.publish(ExportId('part'), a.host)
  const unpublishB = b.service.publish(ExportId('part'), b.host)
  const mountBonA = a.service.mount({ source: { node: NodeId('paper-b'), export: ExportId('part') }, parent: a.root })
  const mountAonB = b.service.mount({ source: { node: NodeId('paper-a'), export: ExportId('part') }, parent: b.root })

  const pluginOf = new Map() // per-node: spec -> plugin
  const makePlugin = (spec) => {
    let plugin = pluginOf.get(spec)
    if (plugin) return plugin
    plugin = async function* (ctx, config) {
      for (const step of spec.steps) {
        switch (step.do) {
          case 'provide':
            ctx.provide(step.key, step.value)
            yield () => {}
            break
          case 'track':
            trace.push(`apply:${spec.name}:${step.tag}`)
            yield () => trace.push(`revert:${spec.name}:${step.tag}`)
            break
          case 'trackMutate':
            trace.push(`apply:${spec.name}:${step.tag}`)
            yield () => {
              const value = ctx.get(step.key, false)
              if (value && typeof value === 'object') value[step.field] = step.to
              trace.push(`revert:${spec.name}:${step.tag}`)
            }
            break
          case 'trackReadOnRevert':
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
          case 'read':
            try {
              const value = ctx[step.key]
              trace.push(`read:${spec.name}:${step.key}=${render(value)}`)
            } catch (error) {
              trace.push(`readfail:${spec.name}:${step.key}:${accessCode(error)}`)
              if (step.strict) throw error
            }
            yield () => {}
            break
          case 'set':
            ctx.set(step.key, step.value)
            trace.push(`setvalue:${spec.name}:${step.key}`)
            yield () => {}
            break
          case 'register': {
            const child = ctx.plugin(makePlugin(step.spec), step.config)
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

  let placement = 0
  const allFibers = () => {
    const fibers = []
    for (const node of nodes) {
      for (const runtime of node.root.registry.values()) {
        for (const fiber of runtime.fibers) fibers.push(fiber)
      }
    }
    return fibers
  }

  return {
    kind: 'cordis-node',
    trace,
    root: null,

    insert(ctx, spec, config) {
      // Explicit contexts (isolation, nesting) stay where they are; root
      // inserts alternate across the two partition hosts.
      const target = ctx ?? nodes[placement++ % 2].host.ctx
      const wrapped = target.plugin(makePlugin(spec), config)
      nameOf.set(Object.getPrototypeOf(wrapped), spec.name)
      nameOf.set(wrapped, spec.name)
      return wrapped
    },
    retire(handle) {
      void Promise.resolve(handle.dispose()).catch(() => {})
    },
    async settle() {
      let quiet = 0
      for (let i = 0; i < 1000; i++) {
        await new Promise(resolve => setImmediate(resolve))
        const busy = allFibers().some(fiber => fiber.inertia)
        if (busy) {
          quiet = 0
        } else if (++quiet >= 6) {
          return
        }
      }
      throw new Error('distributed system failed to settle')
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
      return a.root.get(key) !== undefined
    },
    readKey(key) {
      return a.root.get(key)
    },
    readKeyLenient(key) {
      return a.root.get(key, false) ?? b.root.get(key, false)
    },
    childCtx(handle) {
      return handle.ctx
    },
    isolateCtx(ctx, key, label) {
      const target = ctx ?? a.root
      return target.isolate(key, label === undefined ? undefined : Symbol.for(`proof:${label}`))
    },
    interceptCtx(ctx, key, config) {
      return (ctx ?? a.root).intercept(key, config)
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
    readVia(handle, key) {
      return handle.ctx[key]
    },
    async dispose() {
      try {
        await mountBonA.dispose?.()
        await mountAonB.dispose?.()
        await unpublishA()
        await unpublishB()
        await disconnect()
      } catch {
        // teardown best-effort; the process exits after the test file anyway
      }
      for (const fiber of allFibers()) {
        void Promise.resolve(fiber.dispose()).catch(() => {})
      }
      await new Promise(resolve => setImmediate(resolve))
      rmSync(dir, { recursive: true, force: true })
    },
  }
}
