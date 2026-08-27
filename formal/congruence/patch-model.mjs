// Bring the explorer's INSTRUMENTED twin up to date with the reference
// semantics after the D5-audit defect fixes (`paper/proof/src/model.mjs`).
//
// `explorer/` is owned by another deliverable and is not edited here, and its
// `model.mjs` is a byte-for-byte copy of the reference semantics plus
// certificate hooks. Rather than fork it (and fork `norm.mjs` with it), this
// module imports the twin and re-applies, as prototype patches, exactly the
// four edits this deliverable made to `paper/proof/src/model.mjs`:
//
//   (1) `inRegistry` / NO_SUCH_ENTRY  — the n ∈ dom(F_γ) premise helper
//   (2) `update`      — refuse at n ∉ dom(F_γ)                    [W6]
//   (3) `setOwn`      — refuse at n ∉ dom(F_γ), before Def. 24's  [P7]
//   (4) `readCommitted` — refuse at n ∉ dom(F_γ)                  [A8]
//   (5) L-Unload      — clear the restart mark with θ_n ↦ Inactive(ζ)
//
// Importing this module for side effect patches the ONE `Model` class that
// `explorer/norm.mjs` also imports, so `materialize()` yields fixed models.
// `verify-patch.mjs` checks the patched twin against the real reference
// semantics on the defect scripts, so drift between the two is caught.

import { Model } from '../explorer/model.mjs'

// CONG_NO_FIX=1 leaves the twin at the PRE-fix reference semantics, so the
// congruence check can be run against the defective specification and the
// defects seen as the κ-congruence counterexamples they are.
export const FIXED = process.env.CONG_NO_FIX !== '1'

if (FIXED && !Model.prototype.inRegistry) {
  // (1)
  Model.prototype.inRegistry = function (fiber) {
    return !!fiber && !fiber.removed && fiber.uid !== null && this.fibers.get(fiber.uid) === fiber
  }
  Model.noSuchEntry = function (op) {
    const error = new Error(`NO_SUCH_ENTRY: ${op} at a name not in dom(F)`)
    error.code = 'NO_SUCH_ENTRY'
    return error
  }

  // (2) O-Update's registry premise.
  const update = Model.prototype.update
  Model.prototype.update = function (fiber, config) {
    if (!this.inRegistry(fiber)) {
      this.emitCert('O-Update', 'refused', { installed: false, outcome: 'bot', stateClass: 'disposed' })
      throw Model.noSuchEntry('update')
    }
    return update.call(this, fiber, config)
  }

  // (3) CO-Prov's registry premise, checked before Definition 24's own.
  const setOwn = Model.prototype.setOwn
  Model.prototype.setOwn = function (fiber, key, value) {
    if (!this.inRegistry(fiber)) {
      this.emitCert('A-Set', 'refused', { binding: 'absent', stateClass: 'disposed', dependents: [] })
      throw Model.noSuchEntry('setval')
    }
    return setOwn.call(this, fiber, key, value)
  }

  // (4) The read label's registry premise.
  const readCommitted = Model.prototype.readCommitted
  Model.prototype.readCommitted = function (fiber, key) {
    if (!this.inRegistry(fiber)) {
      this.emitCert('A-Read', 'refused', { cls: 'no-entry' })
      throw Model.noSuchEntry('read')
    }
    return readCommitted.call(this, fiber, key)
  }

  // (5) L-Unload writes θ_n ↦ Inactive(ζ) whole; eq. 43 gives Inactive(ζ) no
  //     restart-mark constituent, so the mark cannot survive the write.
  const ruleFor = Model.prototype.ruleFor
  Model.prototype.ruleFor = function (fiber) {
    const fn = ruleFor.call(this, fiber)
    if (fn && fn.ruleName === 'L-Unload') {
      const wrapped = () => { fn(); fiber.stale = false }
      wrapped.ruleName = 'L-Unload'
      return wrapped
    }
    return fn
  }
}

export { Model }
