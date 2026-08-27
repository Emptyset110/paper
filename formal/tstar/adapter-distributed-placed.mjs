// The distributed adapter with its PLACEMENT pinned — the control run.
//
// `../../proof/src/adapter-distributed.mjs` sends successive root inserts to
// alternating partition hosts, so in a two-component script the two components
// always land on different nodes. That is the right default (it maximises what
// crosses a link), but it conflates two questions when a script fails:
//
//   (i)  does installing cordis-node change the semantics at all?
//   (ii) does *placing the components apart* change them?
//
// This module answers (i). It is the equivalence contract's own degenerate
// case: the single-block set partition (docs/equivalence.md §(b) — "the
// single-block partition is included and is the degenerate case where
// cordis-node is installed but nothing crosses a link"). Both nodes still boot,
// publish, mount each other and stay connected; only the placement changes.
//
// It is installed by resolution override from `use-cordis-lib.mjs`
// (`TSTAR_PLACEMENT=colocated`), so `paper/proof/src/target.mjs` and the runner
// are untouched and pick it up as if it were the adapter.

import { createDistributedSystem as createReal } from '../../proof/src/adapter-distributed.mjs?real'

export async function createDistributedSystem() {
  const system = await createReal()
  const insert = system.insert.bind(system)
  let host = null
  return {
    ...system,
    kind: 'cordis-node',
    insert(ctx, spec, config) {
      if (ctx) return insert(ctx, spec, config)
      const handle = insert(host, spec, config)
      // The first implicit insert defines the host every later one reuses.
      // `Fiber.parent` is the Context the fiber was planted in, i.e. node A's
      // partition host (the alternation starts at index 0).
      host ??= Object.getPrototypeOf(handle).parent
      return handle
    },
  }
}
