// Component-script DSL shared by every adapter.
//
// A ComponentSpec is pure data. Both the reference model (an executable copy
// of the calculus of §4) and the real Cordis runtime interpret the same spec,
// so a test written once runs against both. Each step is one *iteration* of
// the component's effect iterator (Definition 51): the paper's L-Iter fires
// once per step, and the iteration boundary between two steps is where
// L-Divert may abort a transition.
//
// Steps:
//   { do: 'provide', key, value }        set(k, v): provision owned by the fiber
//   { do: 'track', tag }                 a revertible effect; applying traces
//                                        `apply:<name>:<tag>`, its inverse traces
//                                        `revert:<name>:<tag>`
//   { do: 'read', key }                  proxy read through the committed view
//                                        (Algorithm 6); traces `read:<name>:<key>=<v>`
//                                        or `readfail:<name>:<key>:<code>`
//   { do: 'set', key, value }            in-place overwrite of the fiber's own
//                                        provision (an A_k value operation)
//   { do: 'register', spec, config? }    registration primitive (Definition 47)
//   { do: 'raise', message }             the iteration raises (§4.3.4)
//   { do: 'trace', text }                pure observation marker
//
// Traces are the observable vocabulary: every assertion in the suite is over
// the trace log, quiescent lifecycle states, quiescent store contents, and
// thrown/recorded errors — the observables the calculus itself is stated over
// (Definition 53 fields read at quiescence, plus step order).

/** Create a component spec; `name` must be unique within a scenario. */
export function component(name, { inject = [], steps = [], provide: declared = [] } = {}) {
  return { name, inject, steps, provide: declared }
}

export const provide = (key, value) => ({ do: 'provide', key, value })
export const track = (tag) => ({ do: 'track', tag })
export const read = (key) => ({ do: 'read', key })
export const setValue = (key, value) => ({ do: 'set', key, value })
export const register = (spec, config) => ({ do: 'register', spec, config })
export const raise = (message) => ({ do: 'raise', message })
export const mark = (text) => ({ do: 'trace', text })

/** Stable state vocabulary shared by adapters (maps Θ of Definition 49). */
export const STATES = Object.freeze({
  PENDING: 'pending', // Inactive(⊥) with target ⊥ or awaiting deps
  LOADING: 'loading', // Reloading
  ACTIVE: 'active', // Active
  FAILED: 'failed', // Inactive(ξ)
  UNLOADING: 'unloading', // Unloading
  DISPOSED: 'disposed', // removed from the registry (O-Remove)
})

/** Subsequence check: do `expected` entries appear in `trace` in order? */
export function inOrder(trace, expected) {
  let i = 0
  for (const entry of trace) {
    if (entry === expected[i]) i += 1
    if (i === expected.length) return true
  }
  return i === expected.length
}

/** Index of first occurrence, or -1. */
export function at(trace, entry) {
  return trace.indexOf(entry)
}

/** Count occurrences of an entry. */
export function count(trace, entry) {
  return trace.filter(x => x === entry).length
}

/**
 * Trace log with synchronous one-shot watchers.
 *
 * `when(marker, action)` runs `action` synchronously the moment `marker` is
 * pushed. This is the deterministic device for mid-transition orchestration:
 * both adapters push trace entries synchronously from inside an iteration, so
 * an action armed on a marker takes effect before the *next* iteration — the
 * exact boundary at which the calculus lets L-Divert observe a target change.
 */
export function createTrace() {
  const watchers = []
  const trace = []
  const push = trace.push.bind(trace)
  trace.push = (...entries) => {
    for (const entry of entries) {
      push(entry)
      for (let i = 0; i < watchers.length; i++) {
        if (watchers[i].marker === entry) {
          const [{ action }] = watchers.splice(i, 1)
          i -= 1
          action()
        }
      }
    }
    return trace.length
  }
  trace.when = (marker, action) => {
    watchers.push({ marker, action })
  }
  return trace
}
