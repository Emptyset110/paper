// The finite orchestration-input generator (D3 item 2b).
//
// Finiteness argument (details in explorer-report.md): the component-shape
// catalog below is a FIXED FINITE LIST; every insert action draws its spec
// from this list (names uniquified per uid, which normalization erases), so
// the orchestration alphabet available at any state is bounded by
//   |CATALOG| * |ctx classes| + 4 * (retire + update + setown) + internal.
// Together with the fiber cap this makes every field of a configuration
// range over a finite set, hence the normalized state space is finite.
//
// Shape design: signatures are equality patterns and guard atoms — they do
// not count steps — so the catalog needs one representative per step-class
// x key-relation pattern, not all step sequences. Each shape is <= 3 steps
// (bound N_s = 5 respected), register depth <= 2 (bound N_d), keys within
// {k1, k2} (N_k = 2), values within {v1, v2}.

const K1 = 'k1'
const K2 = 'k2'
const V1 = 'v1'
const V2 = 'v2'

const provide = (key, value) => ({ do: 'provide', key, value })
const track = (tag) => ({ do: 'track', tag })
const read = (key) => ({ do: 'read', key })
const setValue = (key, value) => ({ do: 'set', key, value })
const rrev = (tag, key) => ({ do: 'trackReadOnRevert', tag, key })
const register = (spec) => ({ do: 'register', spec })
const raise = (message) => ({ do: 'raise', message })
const raiseUnless = (flag, message) => ({ do: 'raiseUnless', flag, message })

// Each entry: id, weight (fibers eventually created), build(uid) -> spec.
export const CATALOG = [
  { id: 'P', weight: 1, why: 'plain provider of one key' },
  { id: 'PT', weight: 1, why: 'provider with a tracked effect (acc {provide,track})' },
  { id: 'C', weight: 1, why: 'consumer with tracked effect' },
  { id: 'CR', weight: 1, why: 'consumer reading its committed key (Alg-6 self)' },
  { id: 'CRR', weight: 1, why: 'consumer with read-on-revert inverse' },
  { id: 'CC', weight: 1, why: 'two-key consumer (per-key satisfaction classes)' },
  { id: 'U', weight: 1, why: 'undeclared reader (Alg-6 UNDECLARED)' },
  { id: 'F', weight: 1, why: 'raise with nonempty track accumulator' },
  { id: 'FP', weight: 1, why: 'raise with provide in accumulator' },
  { id: 'G', weight: 1, why: 'raiseUnless flag latch (config/update interplay)' },
  { id: 'S', weight: 1, why: 'setval own, unequal value' },
  { id: 'SE', weight: 1, why: 'setval own, equal value' },
  { id: 'SF', weight: 1, why: 'setval foreign (raises)' },
  { id: 'M', weight: 1, why: 'chain middle: consumes k1, provides k2' },
  { id: 'A', weight: 2, why: 'registrar whose child reads the parent-committed key (Alg-6 ancestor)' },
  { id: 'RGT', weight: 2, why: 'plain registration cascade' },
  { id: 'DP', weight: 1, why: 'declared provider (O-Insert disjointness premise)' },
  { id: 'T', weight: 1, why: 'pure tracked effect (also the child-insert probe shape)' },
  { id: 'T2', weight: 1, why: 'two tracked effects: observable inverse ORDER pattern (binary composition witness)' },
]

export function buildSpec(shapeId, uid) {
  const name = `${shapeId}_${uid}`
  const child = (steps, inject = []) => ({ name: `${name}c`, inject, steps, provide: [] })
  const spec = (inject, steps, declared = []) => ({ name, inject, steps, provide: declared })
  switch (shapeId) {
    case 'P': return spec([], [provide(K1, V1)])
    case 'PT': return spec([], [provide(K1, V1), track('a')])
    case 'C': return spec([K1], [track('a')])
    case 'CR': return spec([K1], [read(K1)])
    case 'CRR': return spec([K1], [rrev('a', K1)])
    case 'CC': return spec([K1, K2], [track('a')])
    case 'U': return spec([], [read(K1)])
    case 'F': return spec([], [track('a'), raise('x')])
    case 'FP': return spec([], [provide(K1, V1), raise('x')])
    case 'G': return spec([], [raiseUnless('ok', 'x')])
    case 'S': return spec([], [provide(K1, V1), setValue(K1, V2)])
    case 'SE': return spec([], [provide(K1, V1), setValue(K1, V1)])
    case 'SF': return spec([], [setValue(K1, V2)])
    case 'M': return spec([K1], [provide(K2, V1), track('a')])
    case 'A': return spec([K1], [register(child([read(K1)]))])
    case 'RGT': return spec([], [register(child([track('a')]))])
    case 'DP': return spec([], [provide(K1, V1)], [K1])
    case 'T': return spec([], [track('a')])
    case 'T2': return spec([], [track('a'), track('b')])
    default: throw new Error(`unknown shape ${shapeId}`)
  }
}

export const ISO_SHAPES = ['P', 'CR'] // shapes also offered under the isolated ctx
export const CHILD_SHAPE = 'T' // shape offered for insertion under a live fiber
export const UPDATE_CFG = { ok: true }
export const SETOWN = { key: K1, value: V2 }
