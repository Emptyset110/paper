// INSTRUMENTED COPY of ../../proof/src/model.mjs — deliverable D3 only.
// The file under paper/proof/ is never modified; this copy adds:
//   * `this.cert` hook: every rule attempt (fired / refused / disabled)
//     reports a certificate {rule, decision, fields} — the occurrence
//     signature vocabulary of MASTER.md's field drafts;
//   * `.ruleName` tags on the closures returned by ruleFor;
//   * `.data` payloads on accumulator inverses so a state can be
//     serialized and rebuilt (see norm.mjs buildInverse);
//   * read-only helpers: classifyRead, accClasses, removeEligible,
//     removeOne (removePass now folds over removeOne — same order, same
//     per-fiber checks, so semantics are unchanged);
//   * FiberM and Ctx are exported for state reconstruction.
// Everything else — every guard, every mutant branch, every trace string —
// is byte-for-byte the reference semantics.

import { createTrace } from '../../proof/src/dsl.mjs'

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
  'guard-only-direct', // relied_n restricted to first-order dependents
  'recovery-leaves-residue', // one binding survives the accumulator
  'refresh-misses-pending', // a provider becoming Active does not wake PENDING
  'update-keeps-stale-binding', // provider replacement leaves dependents on the
  // old committed provider
]

let nextLabelId = 1

export class Ctx {
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

export class FiberM {
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
    this.oracle = oracle
    this.oracleAt = 0
    this.branching = []
    this.trace = createTrace()
    this.fibers = new Map() // uid -> FiberM
    this.nextUid = 1
    this.rootLabels = Object.create(null) // key -> shared-realm label
    this.rootCtx = new Ctx(null, Object.create(null), Object.create(null))
    // Certificate hook (instrumentation, D3): null = silent.
    this.cert = globalThis.__MODEL_CERT_HOOK__ ?? null
  }

  emitCert(rule, decision, fields) {
    if (this.cert) this.cert({ rule, decision, fields })
  }

  // ---- instrumentation helpers (read-only) ------------------------------

  outcomeClass(fiber) {
    return fiber.outcome === null ? 'bot' : 'xi'
  }

  accClasses(fiber) {
    return [...new Set(fiber.accumulator.map(inv => inv.data?.kind ?? 'other'))].sort()
  }

  /**
   * Order pattern (up to length 2) of the EVENT-EMITTING inverses in
   * application order — the finite order-pattern component of Def. 3(3)
   * needed so composition order of witnessed inverses is a signature atom
   * (mirrors MASTER's "depth-as-order-pattern up to 2" for intercepts).
   */
  accObsPattern(fiber) {
    const obs = fiber.accumulator
      .map(inv => inv.data?.kind ?? 'other')
      .filter(k => k === 'track' || k === 'rrev' || k === 'mutate')
    return obs.slice(0, 2)
  }

  injectClasses(fiber) {
    return [...new Set(fiber.spec.inject.map(k =>
      this.providerOf(fiber.ctx, k) ? 'provided' : 'unprovided'))].sort()
  }

  /**
   * Baseline Algorithm-6 walk classification (read-only, no throw).
   * Failing outcomes carry a provider-witness atom (Def. 3(4): existential
   * σ-membership witness) — '-p' when an Active provider holds the key in
   * the reader's realm, '-np' otherwise. Without it, the rejected-access
   * occurrences cannot distinguish "nothing there" from "there but not
   * authorized", and the line-5/line-6 deviants are undetectable by any
   * single-occurrence experiment.
   */
  classifyRead(fiber, key) {
    const witness = () => (this.providerOf(fiber.ctx, key) ? '-p' : '-np')
    let walk = fiber
    while (walk) {
      if (walk.committed?.has(key)) {
        const provider = this.fibers.get(walk.committed.get(key))
        const label = this.labelOf(walk.ctx, key)
        const entry = provider?.table.get(label)
        if (entry) return walk === fiber ? 'committed-self' : 'committed-ancestor'
        return 'withdrawn'
      }
      if (walk.spec.inject.includes(key)) return `inactive-declared${witness()}`
      if (walk.parent && this.labelOf(walk.ctx, key) !== this.labelOf(walk.parent.ctx, key)) {
        return `undeclared${witness()}`
      }
      walk = walk.parent
    }
    return `undeclared${witness()}`
  }

  classifyStep(fiber, step) {
    switch (step.do) {
      case 'provide': {
        const label = this.labelOf(fiber.ctx, step.key)
        for (const other of this.fibers.values()) {
          if (other.removed || other === fiber) continue
          if (other.table.has(label)) return 'provide-conflict'
        }
        return 'provide-fresh'
      }
      case 'track': return 'track'
      case 'trackMutate': return 'track-mutate'
      case 'trackReadOnRevert': return 'track-rrev'
      case 'read': return `read-${this.classifyRead(fiber, step.key)}${step.strict ? '-strict' : ''}`
      case 'set': {
        const entry = fiber.table.get(this.labelOf(fiber.ctx, step.key))
        if (!entry) return 'setval-foreign'
        return entry.value === step.value ? 'setval-own-eq' : 'setval-own-neq'
      }
      case 'register': return 'register'
      case 'raise': return 'raise'
      case 'raiseUnless': return fiber.config?.[step.flag] ? 'flag-pass' : 'flag-fail'
      case 'trace': return 'mark'
      default: return `unknown-${step.do}`
    }
  }

  // ---- resolution -------------------------------------------------------

  labelOf(ctx, key) {
    if (this.mutant === 'isolate-shared') {
      return (this.rootLabels[key] ??= `realm#root:${key}`)
    }
    return ctx.isolate[key] ?? (this.rootLabels[key] ??= `realm#root:${key}`)
  }

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
    const parentClass = !parentFiber ? 'root'
      : (parentFiber.removed || parentFiber.uid === null) ? 'removed'
        : parentFiber.retired ? 'retired' : 'live'
    let realm = 'root'
    for (const _k in ctx.isolate) { realm = 'isolated'; break }
    let declaredConflict = false
    for (const key of spec.provide ?? []) {
      for (const other of this.fibers.values()) {
        if (!other.removed && (other.spec.provide ?? []).includes(key)) declaredConflict = true
      }
    }
    const sigFields = { parent: parentClass, declaredConflict, realm }
    if (parentFiber && (parentFiber.removed || parentFiber.uid === null)) {
      if (this.mutant !== 'insert-allows-disposed-parent') {
        this.emitCert('O-Insert', 'refused', sigFields)
        throw new Error('INACTIVE_EFFECT: cannot insert under a removed fiber')
      }
    }
    if (this.mutant !== 'insert-allows-duplicate-provider') {
      for (const key of spec.provide ?? []) {
        for (const other of this.fibers.values()) {
          if (!other.removed && (other.spec.provide ?? []).includes(key)) {
            this.emitCert('O-Insert', 'refused', sigFields)
            throw new Error(`provision "${key}" already declared by ${other.spec.name}`)
          }
        }
      }
    }
    this.emitCert('O-Insert', 'fired', sigFields)
    const uid = this.nextUid++
    const fiber = new FiberM(this, uid, spec, config, parentFiber, ctx.child(null))
    fiber.ctx.fiber = fiber
    this.fibers.set(uid, fiber)
    return fiber
  }

  retire(fiber) {
    this.emitCert('O-Retire', 'fired', { stateClass: this.stateOf(fiber), again: fiber.retired })
    fiber.retired = true
  }

  // ---- lifecycle rules --------------------------------------------------

  ruleFor(fiber) {
    if (fiber.removed) return null
    switch (fiber.state) {
      case 'inactive': {
        if (fiber.outcome !== null && this.mutant !== 'begin-from-failed') {
          this.emitCert('L-Begin', 'disabled', { outcome: 'xi', retired: fiber.retired })
          return null
        }
        const target = this.targetOf(fiber)
        if (target === null) {
          this.emitCert('L-Begin', 'disabled', {
            outcome: this.outcomeClass(fiber),
            retired: fiber.retired,
            inject: fiber.retired ? undefined : this.injectClasses(fiber),
          })
          fiber.everUnsatisfied = true
          return null
        }
        if (this.mutant === 'refresh-misses-pending' && fiber.everUnsatisfied) return null
        const fn = () => { // L-Begin
          this.emitCert('L-Begin', 'fired', {
            outcome: this.outcomeClass(fiber),
            inject: this.injectClasses(fiber),
          })
          fiber.committed = target
          fiber.remaining = [...fiber.spec.steps]
          fiber.accumulator = []
          fiber.state = 'reloading'
          this.trace.push(`begin:${fiber.spec.name}`)
        }
        fn.ruleName = 'L-Begin'
        return fn
      }
      case 'reloading': {
        const target = fiber.stale ? Symbol.for('stale') : this.targetOf(fiber)
        const matches = !fiber.stale && this.sameView(target, fiber.committed)
        if (!matches) {
          const trigger = fiber.stale ? 'stale' : target === null ? 'target-bot' : 'target-diff'
          const fn = () => { // L-Divert (abort at the iteration boundary)
            this.emitCert('L-Divert', 'fired', { trigger, acc: this.accClasses(fiber) })
            fiber.stale = false
            fiber.remaining = null
            if (this.mutant === 'divert-skips-recovery') fiber.accumulator = []
            fiber.state = 'unloading'
            this.trace.push(`divert:${fiber.spec.name}`)
          }
          fn.ruleName = 'L-Divert'
          return fn
        }
        if (fiber.remaining.length === 0) {
          const fn = () => { // L-Finish
            this.emitCert('L-Finish', 'fired', { acc: this.accClasses(fiber) })
            fiber.remaining = null
            fiber.state = 'active'
            this.trace.push(`active:${fiber.spec.name}`)
          }
          fn.ruleName = 'L-Finish'
          return fn
        }
        const fn = () => { // L-Iter / L-Raise
          const step = fiber.remaining[0]
          const stepClass = this.classifyStep(fiber, step)
          const accPre = this.accClasses(fiber)
          fiber.remaining.shift()
          try {
            this.execute(fiber, step)
            this.emitCert('L-Iter', 'fired', { stepClass })
          } catch (error) {
            this.emitCert('L-Raise', 'fired', { stepClass, acc: accPre })
            fiber.outcome = error
            fiber.remaining = null
            fiber.state = 'unloading'
            this.trace.push(`raise:${fiber.spec.name}`)
          }
        }
        fn.ruleName = 'L-Iter'
        return fn
      }
      case 'active': {
        const target = fiber.stale ? Symbol.for('stale') : this.targetOf(fiber)
        if (!fiber.stale && this.sameView(target, fiber.committed)) {
          this.emitCert('L-Leave', 'disabled', { trigger: 'view-stable' })
          return null
        }
        const trigger = fiber.stale ? 'stale' : target === null ? 'target-bot' : 'target-diff'
        const fn = () => { // L-Leave
          this.emitCert('L-Leave', 'fired', { trigger })
          fiber.stale = false
          fiber.state = 'unloading'
          this.trace.push(`leave:${fiber.spec.name}`)
        }
        fn.ruleName = 'L-Leave'
        return fn
      }
      case 'unloading': {
        if (this.reliedUpon(fiber) && this.mutant !== 'unload-without-guard') {
          this.emitCert('L-Unload', 'disabled', {
            relied: true,
            outcome: this.outcomeClass(fiber),
            retired: fiber.retired,
            acc: this.accClasses(fiber),
          })
          return null
        }
        const fn = () => { // L-Unload
          const sigFields = {
            relied: this.reliedUpon(fiber),
            outcome: this.outcomeClass(fiber),
            retired: fiber.retired,
            acc: this.accClasses(fiber),
            obs: this.accObsPattern(fiber),
          }
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
          fiber.state = 'inactive'
          this.trace.push(`deactivated:${fiber.spec.name}`)
          sigFields.postTarget = this.targetOf(fiber) === null ? 'bot' : 'sat'
          this.emitCert('L-Unload', 'fired', sigFields)
        }
        fn.ruleName = 'L-Unload'
        return fn
      }
    }
    return null
  }

  // O-Remove: retired, Inactive, childless entries leave the registry.
  // Refactored into a per-fiber eligibility check + per-fiber removal so the
  // explorer can enumerate removals one at a time; removePass folds over the
  // same checks in the same order — semantics identical to the reference.
  removeEligible(fiber) {
    if (fiber.removed || !fiber.retired) return false
    const inactive = fiber.state === 'inactive'
    if (!inactive && this.mutant !== 'remove-before-inactive') {
      this.emitCert('O-Remove', 'disabled', { stateClass: fiber.state, hasChild: this.hasChild(fiber) })
      return false
    }
    if (this.hasChild(fiber)) {
      this.emitCert('O-Remove', 'disabled', { stateClass: fiber.state, hasChild: true })
      return false
    }
    return true
  }

  hasChild(fiber) {
    return [...this.fibers.values()].some(m => !m.removed && m.parent === fiber)
  }

  removeOne(fiber) {
    this.emitCert('O-Remove', 'fired', {
      stateClass: fiber.state,
      outcome: this.outcomeClass(fiber),
    })
    fiber.removed = true
    fiber.uid = null
    fiber.table.clear()
  }

  removePass() {
    let changed = false
    for (const fiber of this.fibers.values()) {
      if (!this.removeEligible(fiber)) continue
      this.removeOne(fiber)
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
        inverse.data = { kind: 'provide', label }
        fiber.accumulator.push(inverse)
        this.trace.push(`provide:${name}:${step.key}`)
        return
      }
      case 'track': {
        this.trace.push(`apply:${name}:${step.tag}`)
        const inverse = () => this.trace.push(`revert:${name}:${step.tag}`)
        inverse.data = { kind: 'track', tag: step.tag }
        fiber.accumulator.push(inverse)
        return
      }
      case 'trackMutate': {
        const label = this.labelOf(fiber.ctx, step.key)
        this.trace.push(`apply:${name}:${step.tag}`)
        const inverse = () => {
          const entry = fiber.table.get(label)
          if (entry && entry.value && typeof entry.value === 'object') entry.value[step.field] = step.to
          this.trace.push(`revert:${name}:${step.tag}`)
        }
        inverse.data = { kind: 'mutate', label, tag: step.tag, field: step.field, to: step.to }
        fiber.accumulator.push(inverse)
        return
      }
      case 'trackReadOnRevert': {
        this.trace.push(`apply:${name}:${step.tag}`)
        const inverse = () => {
          try {
            const value = this.readCommitted(fiber, step.key)
            this.trace.push(`revertread:${name}:${step.key}=${render(step.field ? value?.[step.field] : value)}`)
          } catch (error) {
            this.trace.push(`revertreadfail:${name}:${step.key}:${error.code ?? 'ERR'}`)
          }
        }
        inverse.data = { kind: 'rrev', key: step.key, field: step.field, tag: step.tag }
        fiber.accumulator.push(inverse)
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
          const inverse = () => this.retire(child)
          inverse.data = { kind: 'retire', childUid: child.uid }
          fiber.accumulator.push(inverse)
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

  readCommitted(fiber, key) {
    this.emitCert('A-Read', 'fired', { cls: this.classifyRead(fiber, key) })
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
    const label = this.labelOf(fiber.ctx, key)
    const entry = fiber.table.get(label)
    // Dependent witness (Def. 3(4)): the set of state classes of installed
    // fibers whose committed view binds this key to this provider — the
    // existential the observed-replacement reading of an active overwrite
    // (§5.1.3 / GAP-3) folds over. The witness carries its state class
    // because only a dependent with a completed episode makes the
    // overwrite's consumer effect observable.
    const dependents = new Set()
    for (const other of this.fibers.values()) {
      if (other.removed || other === fiber || !other.installed) continue
      if (other.committed.get(key) === fiber.uid) dependents.add(this.stateOf(other))
    }
    this.emitCert('A-Set', entry ? 'fired' : 'refused', {
      binding: entry ? 'own' : 'foreign',
      valueEq: entry ? entry.value === value : undefined,
      stateClass: this.stateOf(fiber),
      dependents: [...dependents].sort(),
    })
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
    this.emitCert('O-Update', 'fired', {
      installed: fiber.installed,
      outcome: this.outcomeClass(fiber),
      stateClass: this.stateOf(fiber),
    })
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
    this.emitCert('A-Intercept', 'fired', { entries: Math.min(seen.length, 2) })
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
