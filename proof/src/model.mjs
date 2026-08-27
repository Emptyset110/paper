// Executable reference model of the calculus of §4 (Table 1), with the
// coeffect layer of §3.2 and the §5 access discipline (Algorithm 6).
//
// The model is intentionally synchronous small-step: `sweep()` applies
// lifecycle rules until no rule fires (quiescence, Definition 49), with the
// fiber-visit order supplied by a pluggable strategy — the calculus's
// nondeterminism made explicit so confluence is testable.
//
// Every deliberate semantic deviation is behind a named mutant switch
// (`new Model({ mutant })`). Mutants exist to prove test necessity: each
// obligation's test must fail on its designated mutant and on no other
// grounds. A mutant changes exactly one semantic decision.

import { createTrace } from './dsl.mjs'

export const MUTANTS = [
  'insert-allows-disposed-parent', // O-Insert without the live-parent premise
  'insert-allows-duplicate-provider', // O-Insert's declared-provision
  // disjointness premise unenforced
  'dynamic-conflict-ignored', // an undeclared provision overwrites a standing
  // binding instead of failing the offender
  'retire-discards-accumulator', // O-Retire jumps to Inactive without inverses
  'remove-before-inactive', // removal races the unload instead of following it
  'begin-without-deps', // L-Begin without γ ⊨ d
  'satisfied-by-installed-provider', // σ_γ unions installed tables, not Active
  'begin-from-failed', // lifecycle re-entered from Inactive(ξ)
  'accumulator-fifo', // inverses composed in application order
  'no-commit-view', // reads resolve against the live registry, not ω
  'divert-skips-recovery', // L-Divert discards the accumulator instead of
  // routing the recovery through Unloading
  'raise-skips-recovery', // L-Raise records the error without recovering
  'failed-still-provides', // Inactive(ξ) keeps its table in σ_γ
  'leave-keeps-providing', // Unloading tables stay in σ_γ
  'unload-without-guard', // L-Unload ignores relied_n
  'unload-clears-view-early', // committed view dropped before inverses run
  'unload-skips-child-retire', // registration inverse forgets the child
  'overwrite-tears-episode', // an overwrite re-runs dependents without recovery
  'proxy-no-ancestry', // Algorithm 6 without the fiber-ancestry walk
  'isolate-shared', // isolation resolves every realm to the shared one
  'intercept-outer-wins', // outermost intercept entry takes priority
  'proxy-skips-inactive-check', // Algorithm 6 line 5 dropped
  'proxy-allows-undeclared', // Algorithm 6 line 6 dropped
  'guard-only-direct', // relied_n restricted to first-order dependents? (it
  // already is first-order; this variant skips transitive *wait chains* by
  // releasing the guard when dependents are merely Unloading, not Inactive)
  'recovery-leaves-residue', // one binding survives the accumulator
  'refresh-misses-pending', // a provider becoming Active does not wake PENDING
  'update-keeps-stale-binding', // provider replacement leaves dependents on the
  // old committed provider
]

let nextLabelId = 1

class Ctx {
  constructor(fiber, isolate, intercept) {
    this.fiber = fiber
    this.isolate = isolate // plain object, prototype-chained
    this.intercept = intercept // plain object, prototype-chained
  }

  child(fiber) {
    return new Ctx(fiber, this.isolate, this.intercept)
  }

  isolated(key, label) {
    const iso = Object.create(this.isolate)
    iso[key] = label ?? `realm#${nextLabelId++}`
    return new Ctx(this.fiber, iso, this.intercept)
  }

  intercepted(key, config) {
    const inter = Object.create(this.intercept)
    inter[key] = config
    return new Ctx(this.fiber, this.isolate, inter)
  }
}

class FiberM {
  constructor(model, uid, spec, config, parentFiber, ctx) {
    this.model = model
    this.uid = uid
    this.spec = spec
    this.config = config
    this.parent = parentFiber // FiberM | null (root)
    this.ctx = ctx // resolution context (isolation/interception scope)
    this.retired = false
    this.removed = false
    this.state = 'inactive' // inactive | reloading | active | unloading
    this.outcome = null // null (⊥, fresh/clean) | Error (ξ)
    this.committed = null // Map(key -> provider uid) | null
    this.remaining = null // steps left to iterate
    this.accumulator = [] // inverses in application order; run reversed
    this.table = new Map() // label -> { key, value }
    this.stale = false // orchestrator-forced restart marker
  }

  get installed() {
    return this.committed !== null
  }
}

export class Model {
  constructor({ mutant = null, order = 'fifo', seed = 1, oracle = null } = {}) {
    if (mutant !== null && !MUTANTS.includes(mutant)) {
      throw new Error(`unknown mutant: ${mutant}`)
    }
    this.mutant = mutant
    this.orderStrategy = order
    this.seed = seed
    // Choice oracle: an array of indices consumed at nondeterministic points;
    // `branching` records the branch factor met at each point, so a driver can
    // enumerate all oracle sequences (exhaustive schedule exploration).
    this.oracle = oracle
    this.oracleAt = 0
    this.branching = []
    this.trace = createTrace()
    this.fibers = new Map() // uid -> FiberM
    this.nextUid = 1
    this.rootLabels = Object.create(null) // key -> shared-realm label
    this.rootCtx = new Ctx(null, Object.create(null), Object.create(null))
  }

  // ---- resolution -------------------------------------------------------

  labelOf(ctx, key) {
    if (this.mutant === 'isolate-shared') {
      return (this.rootLabels[key] ??= `realm#root:${key}`)
    }
    return ctx.isolate[key] ?? (this.rootLabels[key] ??= `realm#root:${key}`)
  }

  // σ_γ provider lookup (Definition 45/46): the Active fiber whose table
  // carries the label, or undefined.
  providerOf(ctx, key) {
    const label = this.labelOf(ctx, key)
    for (const fiber of this.fibers.values()) {
      if (fiber.removed) continue
      const providing = this.mutant === 'satisfied-by-installed-provider'
        ? fiber.installed || fiber.state === 'active'
        : this.mutant === 'failed-still-provides'
          ? fiber.state === 'active' || (fiber.state === 'inactive' && fiber.outcome !== null && fiber.table.has(label))
          : this.mutant === 'leave-keeps-providing'
            ? fiber.state === 'active' || fiber.state === 'unloading'
            : fiber.state === 'active'
      if (!providing) continue
      if (fiber.table.has(label)) return fiber
    }
    return undefined
  }

  // target_n(γ), Definition 46: null is ⊥.
  targetOf(fiber) {
    if (fiber.retired || fiber.removed) return null
    const view = new Map()
    for (const key of fiber.spec.inject) {
      const provider = this.providerOf(fiber.ctx, key)
      if (!provider) {
        if (this.mutant === 'begin-without-deps') continue
        return null
      }
      view.set(key, provider.uid)
    }
    return view
  }

  sameView(a, b) {
    if (a === null || b === null) return a === b
    if (a.size !== b.size) return false
    for (const [k, v] of a) {
      if (b.get(k) !== v) return false
    }
    return true
  }

  // n ∈ dom(F_γ) (Definition 45). O-Retire's *only* premise (p. 31, restated
  // p. 32: "O-Retire has n ∈ dom(F_γ) as its only premise"), and by parity the
  // premise every name-taking orchestration input owes: O-Remove writes
  // γ \ n, after which the name denotes no entry and there is nothing for a
  // later input to read or write (Lemma 54(5): π, d, p, e come into existence
  // with the entry and are never written again).
  inRegistry(fiber) {
    return !!fiber && !fiber.removed && fiber.uid !== null && this.fibers.get(fiber.uid) === fiber
  }

  /** The refusal an input owes when its registry premise fails. */
  static noSuchEntry(op) {
    const error = new Error(`NO_SUCH_ENTRY: ${op} at a name not in dom(F)`)
    error.code = 'NO_SUCH_ENTRY'
    return error
  }

  reliedUpon(fiber) {
    for (const other of this.fibers.values()) {
      if (other === fiber || other.removed) continue
      const holds = this.mutant === 'guard-only-direct'
        ? other.installed && other.state !== 'unloading'
        : other.installed
      if (!holds) continue
      for (const uid of other.committed.values()) {
        if (uid === fiber.uid) return true
      }
    }
    return false
  }

  // ---- orchestration (O-rules) -----------------------------------------

  insert(ctx, spec, config) {
    const parentFiber = ctx.fiber
    if (parentFiber && (parentFiber.removed || parentFiber.uid === null)) {
      if (this.mutant !== 'insert-allows-disposed-parent') {
        throw new Error('INACTIVE_EFFECT: cannot insert under a removed fiber')
      }
    }
    // O-Insert premise ∀m. p ∩ p_m = ∅, over DECLARED provisions of fibers
    // still present in the registry (removal, not retirement, frees the keys).
    if (this.mutant !== 'insert-allows-duplicate-provider') {
      for (const key of spec.provide ?? []) {
        for (const other of this.fibers.values()) {
          if (!other.removed && (other.spec.provide ?? []).includes(key)) {
            throw new Error(`provision "${key}" already declared by ${other.spec.name}`)
          }
        }
      }
    }
    const uid = this.nextUid++
    const fiber = new FiberM(this, uid, spec, config, parentFiber, ctx.child(null))
    fiber.ctx.fiber = fiber
    this.fibers.set(uid, fiber)
    return fiber
  }

  retire(fiber) {
    fiber.retired = true
  }

  // ---- lifecycle rules --------------------------------------------------

  ruleFor(fiber) {
    if (fiber.removed) return null
    switch (fiber.state) {
      case 'inactive': {
        if (fiber.outcome !== null && this.mutant !== 'begin-from-failed') return null
        const target = this.targetOf(fiber)
        if (target === null) {
          fiber.everUnsatisfied = true
          return null
        }
        if (this.mutant === 'refresh-misses-pending' && fiber.everUnsatisfied) return null
        return () => { // L-Begin
          fiber.committed = target
          fiber.remaining = [...fiber.spec.steps]
          fiber.accumulator = []
          fiber.state = 'reloading'
          this.trace.push(`begin:${fiber.spec.name}`)
        }
      }
      case 'reloading': {
        const target = fiber.stale ? Symbol.for('stale') : this.targetOf(fiber)
        const matches = !fiber.stale && this.sameView(target, fiber.committed)
        if (!matches) {
          return () => { // L-Divert (abort at the iteration boundary)
            fiber.stale = false
            fiber.remaining = null
            if (this.mutant === 'divert-skips-recovery') fiber.accumulator = []
            fiber.state = 'unloading'
            this.trace.push(`divert:${fiber.spec.name}`)
          }
        }
        if (fiber.remaining.length === 0) {
          return () => { // L-Finish
            fiber.remaining = null
            fiber.state = 'active'
            this.trace.push(`active:${fiber.spec.name}`)
          }
        }
        return () => { // L-Iter / L-Raise
          const step = fiber.remaining.shift()
          try {
            this.execute(fiber, step)
          } catch (error) {
            fiber.outcome = error
            fiber.remaining = null
            fiber.state = 'unloading'
            this.trace.push(`raise:${fiber.spec.name}`)
          }
        }
      }
      case 'active': {
        const target = fiber.stale ? Symbol.for('stale') : this.targetOf(fiber)
        if (!fiber.stale && this.sameView(target, fiber.committed)) return null
        return () => { // L-Leave
          fiber.stale = false
          fiber.state = 'unloading'
          this.trace.push(`leave:${fiber.spec.name}`)
        }
      }
      case 'unloading': {
        if (this.reliedUpon(fiber) && this.mutant !== 'unload-without-guard') return null
        return () => { // L-Unload
          if (this.mutant === 'unload-clears-view-early') fiber.committed = null
          if (this.mutant === 'raise-skips-recovery' && fiber.outcome !== null) {
            // record the error, run nothing
          } else if (this.mutant === 'retire-discards-accumulator' && fiber.retired) {
            fiber.table.clear()
          } else {
            const inverses = this.mutant === 'accumulator-fifo'
              ? [...fiber.accumulator]
              : [...fiber.accumulator].reverse()
            let skipped = false
            for (const inverse of inverses) {
              if (this.mutant === 'recovery-leaves-residue' && !skipped && inverse.kind === 'provide') {
                skipped = true
                continue
              }
              if (this.mutant === 'failed-still-provides' && fiber.outcome !== null && inverse.kind === 'provide') {
                continue
              }
              inverse()
            }
          }
          fiber.accumulator = []
          fiber.committed = null
          // The restart mark is a constituent of θ_n, not a field of the
          // registry: eq. 43's Θ_Γ gives Inactive(ζ) no such component, and
          // L-Unload's row writes θ_n ↦ Inactive(ζ) whole. A mark surviving
          // into the next episode would make L-Divert fire where its premise
          // target_n(γ) ≠ ω is false (and at Inactive there is no ω to compare
          // against at all — Lemma 54(2)).
          fiber.stale = false
          fiber.state = 'inactive'
          this.trace.push(`deactivated:${fiber.spec.name}`)
        }
      }
    }
    return null
  }

  // O-Remove: retired, Inactive, childless entries leave the registry.
  removePass() {
    let changed = false
    for (const fiber of this.fibers.values()) {
      if (fiber.removed || !fiber.retired) continue
      const inactive = fiber.state === 'inactive'
      if (!inactive && this.mutant !== 'remove-before-inactive') continue
      const hasChild = [...this.fibers.values()].some(m => !m.removed && m.parent === fiber)
      if (hasChild) continue
      fiber.removed = true
      fiber.uid = null
      fiber.table.clear()
      changed = true
    }
    return changed
  }

  order() {
    const live = [...this.fibers.values()].filter(f => !f.removed)
    if (this.orderStrategy === 'lifo') return live.reverse()
    if (this.orderStrategy === 'random') {
      let s = this.seed
      const rand = () => (s = (s * 1103515245 + 12345) & 0x7fffffff) / 0x7fffffff
      for (let i = live.length - 1; i > 0; i--) {
        const j = Math.floor(rand() * (i + 1))
        ;[live[i], live[j]] = [live[j], live[i]]
      }
      return live
    }
    return live
  }

  /** Run lifecycle + removal rules to quiescence. */
  sweep() {
    for (let guardCount = 0; guardCount < 10_000; guardCount++) {
      if (this.mutant === 'remove-before-inactive') this.removePass()
      if (this.oracle) {
        // Oracle mode: collect every applicable (fiber, rule) pair and let the
        // oracle choose — the calculus's nondeterminism made enumerable.
        const enabled = []
        for (const fiber of this.order()) {
          const rule = this.ruleFor(fiber)
          if (rule) enabled.push(rule)
        }
        if (enabled.length === 0) {
          if (!this.removePass()) return
          continue
        }
        let pick = 0
        if (enabled.length > 1) {
          this.branching.push(enabled.length)
          pick = this.oracle[this.oracleAt] ?? 0
          this.oracleAt += 1
          if (pick >= enabled.length) pick = enabled.length - 1
        }
        enabled[pick]()
        continue
      }
      let fired = false
      for (const fiber of this.order()) {
        const rule = this.ruleFor(fiber)
        if (rule) {
          rule()
          fired = true
          break // re-read the state space after every step, like the calculus
        }
      }
      if (!fired && !this.removePass()) return
    }
    throw new Error('model failed to quiesce within 10000 steps')
  }

  // ---- step execution ---------------------------------------------------

  execute(fiber, step) {
    const name = fiber.spec.name
    switch (step.do) {
      case 'provide': {
        const label = this.labelOf(fiber.ctx, step.key)
        if (this.mutant !== 'dynamic-conflict-ignored') {
          for (const other of this.fibers.values()) {
            if (other.removed || other === fiber) continue
            if (other.table.has(label)) {
              throw new Error(`service "${step.key}" already provided by ${other.spec.name}`)
            }
          }
        }
        fiber.table.set(label, { key: step.key, value: step.value })
        const inverse = () => fiber.table.delete(label)
        inverse.kind = 'provide'
        fiber.accumulator.push(inverse)
        this.trace.push(`provide:${name}:${step.key}`)
        return
      }
      case 'track': {
        this.trace.push(`apply:${name}:${step.tag}`)
        fiber.accumulator.push(() => this.trace.push(`revert:${name}:${step.tag}`))
        return
      }
      case 'trackMutate': {
        const label = this.labelOf(fiber.ctx, step.key)
        this.trace.push(`apply:${name}:${step.tag}`)
        fiber.accumulator.push(() => {
          const entry = fiber.table.get(label)
          if (entry && entry.value && typeof entry.value === 'object') entry.value[step.field] = step.to
          this.trace.push(`revert:${name}:${step.tag}`)
        })
        return
      }
      case 'trackReadOnRevert': {
        this.trace.push(`apply:${name}:${step.tag}`)
        fiber.accumulator.push(() => {
          try {
            const value = this.readCommitted(fiber, step.key)
            this.trace.push(`revertread:${name}:${step.key}=${render(step.field ? value?.[step.field] : value)}`)
          } catch (error) {
            this.trace.push(`revertreadfail:${name}:${step.key}:${error.code ?? 'ERR'}`)
          }
        })
        return
      }
      case 'read': {
        try {
          const value = this.readCommitted(fiber, step.key)
          this.trace.push(`read:${name}:${step.key}=${render(value)}`)
        } catch (error) {
          this.trace.push(`readfail:${name}:${step.key}:${error.code ?? 'ERR'}`)
          if (step.strict) throw error
        }
        return
      }
      case 'set': {
        const label = this.labelOf(fiber.ctx, step.key)
        const entry = fiber.table.get(label)
        if (!entry) throw new Error(`cannot set "${step.key}" without provide`)
        entry.value = step.value
        this.trace.push(`setvalue:${name}:${step.key}`)
        if (this.mutant === 'overwrite-tears-episode') this.tearDependents(fiber, step.key)
        return
      }
      case 'register': {
        const child = this.insert(fiber.ctx.child(fiber), step.spec, step.config)
        this.trace.push(`registered:${name}:${step.spec.name}`)
        if (this.mutant !== 'unload-skips-child-retire') {
          fiber.accumulator.push(() => this.retire(child))
        }
        return
      }
      case 'raise':
        throw new Error(step.message)
      case 'raiseUnless':
        if (!fiber.config?.[step.flag]) throw new Error(step.message ?? `flag ${step.flag} unset`)
        this.trace.push(`flagged:${name}:${step.flag}`)
        return
      case 'trace':
        this.trace.push(step.text)
        return
      default:
        throw new Error(`unknown step: ${step.do}`)
    }
  }

  // Algorithm 6, over the model state: walk the fiber chain; first committed
  // view binding wins; a declared-but-uncommitted key is INACTIVE_ACCESS;
  // the root rejects as UNDECLARED_ACCESS.
  readCommitted(fiber, key) {
    // Registry premise of the read label (occurrence A8): Algorithm 6 is run
    // from n's resolution context, and a name O-Remove has taken out of
    // dom(F_γ) has none. Without it the walk consults the stale record's
    // declaration and answers INACTIVE_ACCESS ("not yet") where the entry is
    // gone for good.
    if (!this.inRegistry(fiber)) throw Model.noSuchEntry('read')
    let walk = fiber
    while (walk) {
      const committed = this.mutant === 'no-commit-view' ? this.liveView(walk) : walk.committed
      if (committed?.has(key)) {
        const provider = this.fibers.get(committed.get(key))
        const label = this.labelOf(walk.ctx, key)
        const entry = provider?.table.get(label)
        if (entry) return entry.value
        const error = new Error(`binding for "${key}" withdrawn`)
        error.code = 'INACTIVE_ACCESS'
        throw error
      }
      if (walk.spec.inject.includes(key) && this.mutant !== 'proxy-skips-inactive-check') {
        const error = new Error(`cannot get required service "${key}" in inactive context`)
        error.code = 'INACTIVE_ACCESS'
        throw error
      }
      // Algorithm 6 stops the walk at an isolation boundary: an ancestor
      // resolving the key in a different realm cannot authorize the access.
      if (walk.parent && this.labelOf(walk.ctx, key) !== this.labelOf(walk.parent.ctx, key)) {
        const error = new Error(`cannot get property "${key}" without inject`)
        error.code = 'UNDECLARED_ACCESS'
        throw error
      }
      walk = this.mutant === 'proxy-no-ancestry' ? null : walk.parent
    }
    if (this.mutant === 'proxy-allows-undeclared') {
      const provider = this.providerOf(fiber.ctx, key)
      const label = this.labelOf(fiber.ctx, key)
      if (provider) return provider.table.get(label).value
    }
    const error = new Error(`cannot get property "${key}" without inject`)
    error.code = 'UNDECLARED_ACCESS'
    throw error
  }

  liveView(fiber) {
    const view = new Map()
    for (const key of fiber.spec.inject) {
      const provider = this.providerOf(fiber.ctx, key)
      if (provider) view.set(key, provider.uid)
    }
    return view
  }

  // ---- runtime operations ----------------------------------------------

  /** In-place overwrite of an ACTIVE fiber's own provision (an A_k op). */
  setOwn(fiber, key, value) {
    // Registry premise (occurrence P7) is checked BEFORE Definition 24's own
    // precondition: O-Remove clears the table, so without this the input is
    // refused with P4's reason ("no own binding") at a name that has no entry
    // at all, and Definition 3 clause 1 compares refusal reasons.
    if (!this.inRegistry(fiber)) throw Model.noSuchEntry('setval')
    const label = this.labelOf(fiber.ctx, key)
    const entry = fiber.table.get(label)
    if (!entry) throw new Error(`cannot set "${key}" without provide`)
    entry.value = value
    if (this.mutant === 'overwrite-tears-episode') this.tearDependents(fiber, key)
  }

  /** Mutant machinery: re-run dependents while discarding their recovery. */
  tearDependents(provider, key) {
    for (const fiber of this.fibers.values()) {
      if (fiber.removed || fiber === provider) continue
      if (fiber.installed && fiber.spec.inject.includes(key)) {
        fiber.accumulator = []
        fiber.remaining = [...fiber.spec.steps]
        fiber.state = 'reloading'
      }
    }
  }

  /** Orchestrator entry update: new config, failure latch cleared, restart. */
  update(fiber, config) {
    // Registry premise (occurrence W6): the entry must exist. Without it the
    // input silently rewrites a record O-Remove has already taken out of
    // dom(F_γ) — a write to a field Lemma 54(5) says no step returns to.
    if (!this.inRegistry(fiber)) throw Model.noSuchEntry('update')
    fiber.config = config
    fiber.outcome = null
    if (fiber.installed) {
      const wasStale = this.mutant === 'update-keeps-stale-binding'
      if (!wasStale) fiber.stale = true
    }
  }

  /** Intercept resolution (Definition 31 realized as §5 does): nearest wins. */
  interceptMerged(fiber, key, base) {
    const configs = []
    let chain = fiber.ctx.intercept
    const seen = []
    while (chain) {
      if (Object.hasOwn(chain, key)) seen.push(chain[key])
      chain = Object.getPrototypeOf(chain)
    }
    // seen is nearest-first; entries closer to the root apply first.
    if (this.mutant === 'intercept-outer-wins') seen.reverse()
    for (const entry of seen.reverse()) configs.push(entry)
    return Object.assign({}, base, ...configs)
  }

  stateOf(fiber) {
    if (fiber.removed) return 'disposed'
    if (fiber.state === 'inactive') {
      if (fiber.outcome !== null) return 'failed'
      return 'pending'
    }
    if (fiber.state === 'reloading') return 'loading'
    return fiber.state // active | unloading
  }
}

function render(value) {
  if (value === undefined) return 'undefined'
  try {
    return JSON.stringify(value)
  } catch {
    return String(value)
  }
}
