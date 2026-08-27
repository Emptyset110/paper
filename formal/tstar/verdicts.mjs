// T* — the verdicts V_{r,s}.
//
// §5.4: the canonical experiment "asserts ≡-equality of the implementation's
// outcome set with the specification's at that point — certificates included."
// §6.3 unpacks that into five obligations: enablement/refusal equal to
// f_r^S(s); an equal normalized certificate; the prescribed ordinary event
// word; the prescribed normalized successor report after settling; and
// termination whenever the specification terminates.
//
// V_{r,s} is realized here in two halves, both required to pass:
//
//   (1) **≡-equality against the executable specification.** The script is run
//       against the reference model (`adapter-model.mjs`, the executable copy
//       of the calculus of §4) and against the target build; the two
//       observations must agree on the report (states, recorded outcomes,
//       store, refusal reasons, external reads) and — where Appendix E does
//       not mark the word schedule-dependent — on the ordinary event word,
//       letter for letter and in order. This is the mechanical half; it
//       catches everything but names nothing.
//
//   (2) **The load-bearing clauses the derivation names.** Every Appendix E
//       item ends with a `Report:` line and, usually, a named observation that
//       separates the target occurrence from its neighbours or kills a named
//       deviant ("the withdrawal is X7's observation"; "the word inv(P,c) <
//       inv(P,b) < inv(P,a) < deact(P)"; "no re-begin certificate follows
//       deact(C)"). Those are transcribed below as explicit predicates so a
//       failure convicts a *clause*, not a diff.
//
// Half (2) alone is what makes the 60/60 gate against the reference model
// meaningful: there half (1) is trivial, and the suite is testing that the
// specification satisfies its own suite — Theorem 2's soundness direction.
//
// Clause kinds:
//   'verdict'      must hold on every target; failure fails the script.
//   'certificate'  reads the rule-certificate channel, which only the
//                  reference model has (§5.4's vocabulary proviso); skipped
//                  elsewhere and reported as skipped.
//   'branch'       the occurrence is realized only on the derivation's
//                  canonical schedule (Appendix E's schedule notes). Required
//                  on the reference model, whose schedule the script pins;
//                  on other targets a failure is reported as
//                  `letter-not-realized`, not as a conformance violation,
//                  because the specification's own outcome set contains the
//                  other branch too.

import { inOrder, count } from './dsl-ext.mjs'

// ---- clause vocabulary ----------------------------------------------------

const has = (obs, event) => obs.word.includes(event)
const lacks = (obs, event) => !obs.word.includes(event)
const order = (obs, events) => inOrder(obs.word, events)
const times = (obs, event) => count(obs.word, event)
const state = (obs, name) => obs.states[name]

/** Component-scoped event count, e.g. every `apply:C:*`. */
const scoped = (obs, prefix) => obs.word.filter(e => e.startsWith(prefix)).length

const clause = (kind, why, check) => ({ kind, why, check })
const V = (why, check) => clause('verdict', why, check)
const Cert = (why, check) => clause('certificate', why, check)
const Branch = (why, check) => clause('branch', why, check)

/** Recovery exactness (Cor. 62): every applied iteration is recovered. */
const exact = (name, tags) => V(
  `recovery exactness at ${name}: every applied iteration is recovered (Cor. 62)`,
  obs => tags.every(t => times(obs, `apply:${name}:${t}`) === times(obs, `revert:${name}:${t}`)),
)

const VERDICTS = Object.create(null)
const verdict = (id, clauses) => { VERDICTS[id] = clauses }

// ===========================================================================
// §1  O-Insert
// ===========================================================================

verdict('S-Ins-1', [
  V('E.OI.I1 report: P active', obs => state(obs, 'P') === 'active'),
  V('E.OI.I1 report: st(k1) = v1 — the accepted insert\'s provision is in σ_γ',
    obs => obs.store.k1 === 'v1'),
  V('I1/I4/I6: the insert is accepted, no refusal recorded', obs => obs.refusals.length === 0),
])

verdict('S-Ins-2', [
  V('E.OI.I2 report: P and C both active', obs => state(obs, 'P') === 'active' && state(obs, 'C') === 'active'),
  V('I2 (ParentClass = present): the insert under a registered parent is accepted',
    obs => obs.at('star').refused === false),
  V('E.OI.I2(3,6): both fibers take the degenerate F2 route — act with no app events',
    obs => scoped(obs, 'apply:') === 0 && has(obs, 'active:P') && has(obs, 'active:C')),
])

verdict('S-Ins-3', [
  V('E.OI.I3(4): the retired parent is removed, leaving dom(F_γ) empty',
    obs => state(obs, 'P') === 'disposed'),
  V('I3 (ParentClass = absent): the insert naming a removed parent is REFUSED',
    obs => obs.at('star').refused === true),
  V('E.OI.I3 refusal reason: π ∉ dom(F_γ) ∪ {root}',
    obs => obs.refusals.length === 1 && obs.refusals[0].reason === 'PARENT_ABSENT'),
  V('E.OI.I3 outcome: C never enters the registry — no act(C)', obs => lacks(obs, 'active:C')),
])

verdict('S-Ins-4', [
  V('I7 (per-key conflict witness): the second declarer is REFUSED',
    obs => obs.at('star').refused === true),
  V('E.OI.I7 refusal reason: premise (iv) ∀m. p ∩ p_m = ∅ fails',
    obs => obs.refusals.length === 1 && obs.refusals[0].reason === 'PROVISION_CONFLICT'),
  V('E.OI.I7 load-bearing fact (D1 §1.3): DECLARED provisions block — the refusal '
    + 'needs no settle and no activation of P, whose provision is therefore not in '
    + 'σ_γ. (D1 states this as "P is Inactive(⊥)"; that stronger form presumes the '
    + 'script semantics in which lifecycle steps run only inside `settle`, which a '
    + 'real build with eager activation does not honour — finding F4 in README.md. '
    + 'The checkable, target-portable form is that P is not yet Active.)',
    obs => obs.at('star').statesBefore.P !== 'active'),
])

// ===========================================================================
// §2  O-Retire
// ===========================================================================

verdict('S-Ret-1', [
  V('R1 bookkeeping class "pending": θ_C = Inactive(⊥) at the retire window',
    obs => obs.at('star').statesBefore.C === 'pending'),
  V('E.OT.R1 report: C disposed', obs => state(obs, 'C') === 'disposed'),
  V('E.OT.R1 report: C never activated — no act(C) in w',
    obs => lacks(obs, 'active:C') && scoped(obs, 'read:C') === 0),
])

verdict('S-Ret-2', [
  V('R2 bookkeeping class "installed" (eq. 44): θ_P = Active at the retire window',
    obs => obs.at('star').statesBefore.P === 'active'),
  V('E.OT.R2 report: P disposed', obs => state(obs, 'P') === 'disposed'),
  V('E.OT.R2 certificate order: retire < deact(P) < removal, with the accumulator run',
    obs => order(obs, ['apply:P:a', 'revert:P:a', 'deactivated:P'])),
])

verdict('S-Ret-3', [
  V('R3 bookkeeping class "failed": θ_P = Inactive(ξ) at the retire window',
    obs => obs.at('star').statesBefore.P === 'failed'),
  V('E.OT.R3 report: P disposed with recorded failure x',
    obs => state(obs, 'P') === 'disposed'),
  V('E.OT.R3: the failure was never an activation — no act(P) anywhere in w',
    obs => lacks(obs, 'active:P')),
])

verdict('S-Ret-4', [
  V('R4: the name left the registry at the removal of step (4)',
    obs => obs.at('star').statesBefore.P === 'disposed'),
  V('R4 (premise n ∈ dom F_γ violated): the second retire is REFUSED',
    obs => obs.at('star').refused === true && obs.at('star').reason === 'NOT_REGISTERED'),
  V('E.OT.R4 outcome: q is the empty-registry report — the refused input emits nothing',
    obs => obs.at('star').wordAfter === obs.at('star').wordBefore),
])

// ===========================================================================
// §3  O-Remove
// ===========================================================================

verdict('S-Rem-1', [
  V('M1/M3/M6: τ=⊤, Inactive(⊥), childless — removal fires',
    obs => state(obs, 'C') === 'disposed'),
  V('E.OM.M1 report: C disposed, never activated', obs => lacks(obs, 'active:C')),
])

verdict('S-Rem-2', [
  V('M2 (RetClass τ=⊥, the deciding first-failing premise): removal is DISABLED, '
    + 'so P persists in the quiescent report — a spurious-remove deviant disposes it',
    obs => state(obs, 'P') === 'active'),
  V('E.OM.M2: the window is {M2, M5, M6} (Correction C3) — P is installed (M5 atoms '
    + 'present) and childless (M6)', obs => state(obs, 'P') === 'active'),
])

verdict('S-Rem-3', [
  V('M4 (StateClass = Inactive(ξ)): the constructor selects the failed block',
    obs => obs.at('retire').statesBefore.P === 'failed'),
  V('E.OM.M4 report: P disposed with the recorded failure — the observation '
    + 'distinguishing M4 from M3', obs => state(obs, 'P') === 'disposed'),
  V('E.OM.M4: no activation ever occurred', obs => lacks(obs, 'active:P')),
])

verdict('S-Rem-4', [
  V('M5 (StateClass ∈ {Reloading, Active, Unloading}): removal is BLOCKED until '
    + 'L-Unload finishes — the certificate order inv(P,a) ≤ deact(P) < removal '
    + '(a remove-before-inactive deviant inverts it and discards the accumulator)',
    obs => order(obs, ['revert:P:a', 'deactivated:P'])),
  V('E.OM.M5 report: P eventually disposed', obs => state(obs, 'P') === 'disposed'),
  exact('P', ['a']),
])

verdict('S-Rem-5', [
  V('M7 (child witness present): G is retired and Inactive while its registered child '
    + 'C is still tearing down, and must NOT yet have left the registry',
    obs => obs.snap('m7') !== undefined && obs.snap('m7').states.G !== 'disposed'),
  V('E.OM.M7 report: both disposed — removal resumes once the child is gone',
    obs => state(obs, 'G') === 'disposed'),
  V('E.OM.M7: the registration inverse retires the child, whose own accumulator runs',
    obs => has(obs, 'revert:C:b') && has(obs, 'revert:G:a')),
])

// ===========================================================================
// §4  L-Begin
// ===========================================================================

verdict('S-Beg-1', [
  V('B1/B3 enabled: L-Begin fires and the episode runs to Active',
    obs => state(obs, 'P') === 'active'),
  V('E.LB.B1 observation: app(P,a) < act(P)', obs => order(obs, ['apply:P:a', 'active:P'])),
])

verdict('S-Beg-2', [
  V('B2 (StateClass = Inactive(ξ)) blocks re-entry: no lifecycle re-entry from an '
    + 'error outcome (p. 38) — exactly one app-free, act-free episode',
    obs => times(obs, 'active:P') === 0),
  V('E.LB.B2 report: P failed(x)', obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
  V('E.LB.B2 report: st(k1) absent — the provide inverse withdrew it',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
])

verdict('S-Beg-3', [
  V('B4 (RetClass τ=⊤ forces target ⊥): L-Begin is DISABLED — no app, no act',
    obs => lacks(obs, 'apply:P:a') && lacks(obs, 'active:P')),
  V('E.LB.B4 report: P disposed without ever activating',
    obs => state(obs, 'P') === 'disposed'),
])

verdict('S-Beg-4', [
  V('B5 (KeySat = Active-provided): C begins against an Active provider',
    obs => state(obs, 'C') === 'active' && state(obs, 'P') === 'active'),
  V('E.LB.B5 observation: rd(C,k1,v1) < act(C) — the committed view names P',
    obs => order(obs, ['read:C:k1="v1"', 'active:C'])),
])

verdict('S-Beg-5', [
  V('E.LB.B6 report (schedule-invariant): P disposed; C1 and C2 both pending',
    obs => state(obs, 'P') === 'disposed' && state(obs, 'C1') === 'pending' && state(obs, 'C2') === 'pending'),
  V('E.LB.B6 report: st(k1) absent',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
  Branch('B6 (KeySat = installed-only-provided): C2\'s begin attempt inside P\'s '
    + 'Unloading window is DISABLED — σ_γ unions Active tables only, so the table P '
    + 'still holds satisfies nobody. C2 never activates. This is the window separating '
    + 'the calculus from the `leave-keeps-providing` and '
    + '`satisfied-by-installed-provider` deviants, which would fire here.',
    obs => times(obs, 'active:C2') === 0 && scoped(obs, 'read:C2') === 0),
  V('E.LB.B6: C1\'s teardown completes before P\'s (the reliance guard)',
    obs => order(obs, ['deactivated:C1', 'deactivated:P'])),
])

verdict('S-Beg-6', [
  V('B7 (KeySat = unprovided): L-Begin DISABLED, C quiesces pending',
    obs => state(obs, 'C') === 'pending'),
  V('E.LB.B7 report: no act(C), no read attempted',
    obs => lacks(obs, 'active:C') && scoped(obs, 'read:C') === 0),
])

// ===========================================================================
// §5  L-Iter
// ===========================================================================

verdict('S-It-1', [
  V('T4 then T5 in two consecutive L-Iter windows, each carrying {T1, T2(k1)}: '
    + 'app(C,a) < rd(C,k1,v1) < act(C)',
    obs => order(obs, ['apply:C:a', 'read:C:k1="v1"', 'active:C'])),
  V('E.LI.T1 report: P and C active',
    obs => state(obs, 'P') === 'active' && state(obs, 'C') === 'active'),
  V('T5/A1/P5: the read is a HIT AT SELF through the committed view',
    obs => has(obs, 'read:C:k1="v1"')),
])

verdict('S-It-2', [
  V('T3 (provide-fresh): the Def. 23 set precondition holds and the binding lands',
    obs => obs.store.k1 === 'v1'),
  V('E.LI.T3 report: P active', obs => state(obs, 'P') === 'active'),
])

verdict('S-It-3', [
  V('T6 (read-ancestor-committed): C declares nothing, and Algorithm 6\'s walk is '
    + 'authorized by the PARENT G\'s committed view — rd(C,k1,v1)',
    obs => has(obs, 'read:C:k1="v1"')),
  V('E.LI.T6 report: P, G, C all active',
    obs => state(obs, 'P') === 'active' && state(obs, 'G') === 'active' && has(obs, 'active:C')),
  V('E.LI.T6(7): the ancestor view exists because G registered C from inside its own '
    + 'transition', obs => order(obs, ['registered:G:C', 'read:C:k1="v1"'])),
])

verdict('S-It-4', [
  V('T7 (read-declared-uncommitted): the walk reaches an ancestor that DECLARES k1 and '
    + 'holds no committed view — Algorithm 6 line 5, INACTIVE_ACCESS, not UNDECLARED',
    obs => has(obs, 'readfail:C:k1:INACTIVE_ACCESS')),
  V('E.LI.T7: the same read succeeded earlier through the same ancestor (a T6 window), '
    + 'so the difference is the ancestor\'s committed view, not the topology',
    obs => order(obs, ['read:C:k1="v1"', 'readfail:C:k1:INACTIVE_ACCESS'])),
  V('E.LI.T7 report: Q2 and C active; G pending; P and Q disposed',
    obs => state(obs, 'Q2') === 'active' && state(obs, 'C') === 'active'
      && state(obs, 'G') === 'pending'
      && state(obs, 'P') === 'disposed' && state(obs, 'Q') === 'disposed'),
  V('E.LI.T7(30): Q2\'s insert is accepted only because Q was REMOVED, not merely '
    + 'retired — the fact Correction C1 turns on', obs => obs.refusals.length === 0),
  V('E.LI.T7: the failing read still LANDS (the A6 convention) — C reaches Active',
    obs => order(obs, ['readfail:C:k1:INACTIVE_ACCESS', 'active:C'])),
])

verdict('S-It-5', [
  V('T8 (read-undeclared): the walk reaches the root with no declaration — '
    + 'UNDECLARED_ACCESS', obs => has(obs, 'readfail:X:k1:UNDECLARED_ACCESS')),
  V('E.LI.T8 report: X active, rderr(X,k1,UD) < act(X) — the failing read lands',
    obs => order(obs, ['readfail:X:k1:UNDECLARED_ACCESS', 'active:X']) && state(obs, 'X') === 'active'),
])

verdict('S-It-6', [
  V('T9 (setval-own): the Def. 24 A_k precondition holds — an own binding exists — '
    + 'and the value is replaced IN PLACE', obs => obs.store.k1 === 'v2'),
  V('E.LI.T9 report: P active with st(k1) = v2',
    obs => state(obs, 'P') === 'active' && has(obs, 'setvalue:P:k1')),
])

verdict('S-It-7', [
  V('T10 (register): the iteration performs Def. 47\'s O-Insert under π = G and the '
    + 'child then activates', obs => order(obs, ['registered:G:C', 'apply:C:b', 'active:C'])),
  V('E.LI.T10 report: G and C both active, C under G',
    obs => state(obs, 'G') === 'active' && has(obs, 'active:C')),
])

verdict('S-It-8', [
  V('T11 (raiseUnless-set): the flag is present in cfg, so the step LANDS and emits '
    + 'the flag observation', obs => has(obs, 'flagged:P:f')),
  V('E.LI.T11 report: P active (contrast S-Rai-2, the unset branch)',
    obs => state(obs, 'P') === 'active'),
])

// ===========================================================================
// §6  L-Finish
// ===========================================================================

verdict('S-Fin-1', [
  V('F1 (iterator Nothing after ≥ 1 landed iteration): act(P) follows app(P,a)',
    obs => order(obs, ['apply:P:a', 'active:P']) && times(obs, 'apply:P:a') === 1),
  V('E.LF.F1 report: P active', obs => state(obs, 'P') === 'active'),
])

verdict('S-Fin-2', [
  V('F2 (the degenerate 𝔈_Γ case, p. 36): the FIRST iterator application yields '
    + 'Nothing — act(P) with NO app events, the observation separating F2 from F1',
    obs => has(obs, 'active:P') && scoped(obs, 'apply:') === 0),
  V('E.LF.F2 report: P active', obs => state(obs, 'P') === 'active'),
])

verdict('S-Fin-3', [
  V('F3 (per-key ViewRel = key-equal at the finishing window): ω(k1) is still the '
    + 'provider when C finishes — act(C) after rd(C,k1,v1)',
    obs => order(obs, ['read:C:k1="v1"', 'active:C'])),
  V('E.LF.F3 report: P and C active',
    obs => state(obs, 'P') === 'active' && state(obs, 'C') === 'active'),
])

// ===========================================================================
// §7  L-Divert
// ===========================================================================

verdict('S-Div-1', [
  V('E.LD.D1 report (all fair schedules): P disposed, C pending — the dependent may '
    + 'NOT quiesce Active on a stale committed view',
    obs => state(obs, 'P') === 'disposed' && state(obs, 'C') === 'pending'),
  V('E.LD.D1 report: st(k1) absent',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
  exact('C', ['a', 'b']),
  Branch('D1/D4(k1)/D5: on the canonical schedule C commits ω(k1)=P, lands track(a), '
    + 'and then meets target ⊥ (the committed provider left σ_γ). L-Divert takes the '
    + 'ABORT alternative: the held iteration track(b) is discarded and never applied, '
    + 'while the accumulator so far is recovered.',
    obs => has(obs, 'apply:C:a') && has(obs, 'revert:C:a') && lacks(obs, 'apply:C:b')),
  Cert('E.LD.D1(10): the pointed rule is L-Divert at C',
    obs => obs.certWord.includes('divert:C')),
])

verdict('S-Div-3', [
  V('E.LD.D3 report: Q2 active; G and C disposed',
    obs => state(obs, 'Q2') === 'active' && state(obs, 'G') === 'disposed'),
  V('E.LD.D3 report: st(k2) = v2 under the replacement provider',
    obs => obs.store.k2 === 'v2'),
  exact('C', ['b', 'c']),
  Branch('D3 (ViewRel = target-⊥-retired): the ONLY agent that can flip τ during a '
    + 'settle is Def. 47\'s registration inverse. G\'s unload retires C while C is '
    + 'Reloading, so C\'s SECOND episode runs track(b) and then diverts — the held '
    + 'iteration track(c) never runs a second time (2 × app(C,b) but 1 × app(C,c)), '
    + 'and the recovery of the aborted episode follows G\'s own deactivation.',
    obs => times(obs, 'apply:C:b') === 2 && times(obs, 'apply:C:c') === 1
      ),
  Branch('E.LD.D3(29): the guard follows coeffects, not the fiber tree — G unloads '
    + 'although its registered child C is installed, because C\'s committed view names '
    + 'Q2, not G', obs => order(obs, ['revert:G:a', 'revert:C:b'])),
  Cert('E.LD.D3(30): the pointed rule is L-Divert at C',
    obs => obs.certWord.includes('divert:C')),
])

// ===========================================================================
// §8  L-Raise
// ===========================================================================

verdict('S-Rai-1', [
  V('X1/X2 (Reloading with iterator Left(ξ), step class raise): P fails with x',
    obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
  V('X6 (accumulator id at the raise): nothing to recover — no inv events',
    obs => scoped(obs, 'revert:') === 0),
  V('E.LR.X1 report: no act(P)', obs => lacks(obs, 'active:P')),
])

verdict('S-Rai-2', [
  V('X3 (raiseUnless-unset, equality pattern cfg ∌ f): the step raises',
    obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
  V('E.LR.X3: the flag observation is NOT emitted (contrast S-It-8)',
    obs => lacks(obs, 'flagged:P:f') && lacks(obs, 'active:P')),
])

verdict('S-Rai-3', [
  V('X4 (provide-conflict): the Def. 23 set precondition fails at the joined label — '
    + 'the OFFENDER raises', obs => state(obs, 'Q') === 'failed'),
  V('E.LR.X4 report: the standing binding is untouched — P stays Active (a '
    + '`dynamic-conflict-ignored` deviant overwrites it and keeps Q alive)',
    obs => state(obs, 'P') === 'active'),
  V('E.LR.X4: the failure names the provision collision at the joined label, not some '
    + 'other error',
    obs => /provide|provision|already|registered/i.test(obs.errors.Q ?? '')),
  V('E.LR.X4: no O-Insert refusal — premise (iv) is KEY-level and {k2} ∩ {k1} = ∅, '
    + 'which is the A4 gap this script exhibits', obs => obs.refusals.length === 0),
])

verdict('S-Rai-4', [
  V('X5 (setval-foreign): the Def. 24 A_k precondition fails — no own binding',
    obs => state(obs, 'P') === 'failed'),
  V('E.LR.X5: the failure names the missing provision',
    obs => /set|provide/i.test(obs.errors.P ?? '')),
])

verdict('S-Rai-5', [
  V('X7 (provide⁻¹ present in g): the accumulator is carried into Unloading and the '
    + 'binding is WITHDRAWN — a `recovery-leaves-residue` deviant keeps it',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
  V('E.LR.X7 report: P failed(x)',
    obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
])

verdict('S-Rai-6', [
  V('X8 (track⁻¹ present in g): recovery emits the inverse BEFORE deactivation — '
    + 'app(P,a) < inv(P,a) < deact(P)',
    obs => order(obs, ['apply:P:a', 'revert:P:a', 'deactivated:P'])),
  V('E.LR.X8 report: P failed(x)',
    obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
])

verdict('S-Rai-7', [
  V('X9 (register⁻¹ present in g): L-Unload\'s accumulator performs O-Retire of the '
    + 'registered child, so nothing of the child survives',
    obs => times(obs, 'apply:C:b') === times(obs, 'revert:C:b')),
  V('E.LR.X9 report: G failed(x), the child gone',
    obs => state(obs, 'G') === 'failed' && /x/.test(obs.errors.G ?? '')),
  V('E.LR.X9(3): the registration happened before the raise, which is what puts '
    + 'register⁻¹ in the accumulator', obs => has(obs, 'registered:G:C')),
])

// ===========================================================================
// §9  L-Leave
// ===========================================================================

verdict('S-Lea-1', [
  V('V1/V3 (Active with target ⊥ by retirement): L-Leave then L-Unload, in that order '
    + '— inv(P,a) < deact(P)',
    obs => order(obs, ['apply:P:a', 'revert:P:a', 'deactivated:P'])),
  V('E.LL.V1 report: P disposed', obs => state(obs, 'P') === 'disposed'),
])

verdict('S-Lea-2', [
  V('V4 (per-key ViewRel = target-⊥-unsatisfied): C is unretired, yet its committed '
    + 'key\'s provider left σ_γ, so C leaves too',
    obs => state(obs, 'C') === 'pending' && state(obs, 'P') === 'disposed'),
  V('E.LL.V4 report: st(k1) absent',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
  V('E.LL.V4(13-15): the reliance guard orders the teardown — C\'s inverse and its '
    + 'deactivation precede P\'s deactivation and withdrawal',
    obs => order(obs, ['revert:C:a', 'deactivated:C', 'deactivated:P'])),
])

verdict('S-Lea-3', [
  V('V5 (ViewRel = orch-update): update(n,cfg) forces a full bounce — inv(P,a) then '
    + 'app(P,a) again, with TWO act(P) events',
    obs => order(obs, ['apply:P:a', 'revert:P:a', 'deactivated:P', 'apply:P:a', 'active:P'])),
  V('E.LL.V5: exactly one recovery and two applications',
    obs => times(obs, 'apply:P:a') === 2 && times(obs, 'revert:P:a') === 1
      && times(obs, 'active:P') === 2),
  V('E.LL.V5 report: P active under cfg2', obs => state(obs, 'P') === 'active'),
])

// ===========================================================================
// §10  L-Unload
// ===========================================================================

verdict('S-Unl-1', [
  V('U6·3 applied LIFO (Def. 52/eq. 48): inv(P,c) < inv(P,b) < inv(P,a) < deact(P) — '
    + 'this is the accumulator-order experiment, and it kills `accumulator-fifo`',
    obs => order(obs, ['revert:P:c', 'revert:P:b', 'revert:P:a', 'deactivated:P'])),
  V('U1 (guard clear) / U3 (ζ=⊥) / U10 (τ=⊤, successor removable): P disposed',
    obs => state(obs, 'P') === 'disposed'),
  exact('P', ['a', 'b', 'c']),
])

verdict('S-Unl-2', [
  V('U2 (positive reliance witness): the provider\'s unload is BLOCKED while an '
    + 'installed consumer holds ω(k1)=P, so inv(C,b) precedes inv(P,a) and the k1 '
    + 'withdrawal — Thm. 63 as an event order; kills `unload-without-guard`',
    obs => order(obs, ['revert:C:b', 'revert:P:a', 'deactivated:P'])),
  V('E.LU.U2 report: C pending, P disposed, st(k1) absent',
    obs => state(obs, 'C') === 'pending' && state(obs, 'P') === 'disposed'
      && obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
])

verdict('S-Unl-3', [
  V('U4 (OutClass ζ=ξ): recovery runs DESPITE the failure — inv(P,a) is emitted; '
    + 'kills `raise-skips-recovery`',
    obs => order(obs, ['apply:P:a', 'revert:P:a', 'deactivated:P'])),
  V('E.LU.U4 report: P failed(x)',
    obs => state(obs, 'P') === 'failed' && /x/.test(obs.errors.P ?? '')),
])

verdict('S-Unl-4', [
  V('U5 (provide⁻¹ item): Def. 23\'s restriction inverse withdraws the binding',
    obs => obs.store.k1 === undefined && obs.storeLenient.k1 === undefined),
  V('E.LU.U5 report: P disposed', obs => state(obs, 'P') === 'disposed'),
])

verdict('S-Unl-5', [
  V('U7 (register⁻¹ item): the inverse performs Def. 47\'s O-Retire of C, and the '
    + 'ordinary rules then carry the child all the way back — kills '
    + '`unload-skips-child-retire`', obs => has(obs, 'revert:C:b')),
  V('E.LU.U7: the child is reached "one level at a time" (p. 32) — the parent\'s own '
    + 'deactivation precedes the child\'s inverse',
    obs => order(obs, ['deactivated:G', 'revert:C:b'])),
  V('E.LU.U7 report: both disposed', obs => state(obs, 'G') === 'disposed'),
])

verdict('S-Unl-6', [
  V('U8 (read-on-revert item, Def. 48 clause 2): C\'s inverse reads k1 through its '
    + 'still-held committed view during its OWN teardown, and the read SUCCEEDS with '
    + 'v1 — P is pinned in Unloading by C\'s edge, table intact',
    obs => has(obs, 'revertread:C:k1="v1"')),
  V('E.LU.U8: the teardown read precedes P\'s withdrawal — the '
    + 'committed-read-during-teardown Thm. 63 promises',
    obs => order(obs, ['revertread:C:k1="v1"', 'deactivated:P'])),
  V('E.LU.U8 report: C pending, P disposed',
    obs => state(obs, 'C') === 'pending' && state(obs, 'P') === 'disposed'),
])

verdict('S-Unl-7', [
  V('U9 (accumulator = id): deact(P) with NO inv events',
    obs => has(obs, 'deactivated:P') && scoped(obs, 'revert:') === 0),
  V('E.LU.U9 report: P disposed', obs => state(obs, 'P') === 'disposed'),
])

verdict('S-Unl-8', [
  V('U11 (τ=⊥ ∧ post-target ⊥): the successor RESTS PENDING — no re-begin certificate '
    + 'follows deact(C), which is the observation separating U11 from U12',
    obs => obs.word.lastIndexOf('deactivated:C') > obs.word.lastIndexOf('active:C')
      && obs.word.lastIndexOf('deactivated:C') > obs.word.lastIndexOf('apply:C:a')),
  V('E.LU.U11 report: C pending', obs => state(obs, 'C') === 'pending'),
  V('E.LU.U11: exactly one episode of C', obs => times(obs, 'apply:C:a') === 1),
])

verdict('S-Unl-9', [
  V('U12 (τ=⊥ ∧ post-target satisfiable): deact(C) is DIRECTLY followed by the '
    + 're-begin — the deactivation-chains-into-activation composite of §4.3.3',
    obs => order(obs, ['revert:C:a', 'deactivated:C', 'apply:C:a', 'active:C'])),
  V('E.LU.U12 report: P and C active under cfg2, exactly one recovery',
    obs => state(obs, 'C') === 'active' && state(obs, 'P') === 'active'
      && times(obs, 'apply:C:a') === 2 && times(obs, 'revert:C:a') === 1),
])

// ===========================================================================
// §11  CO-Prov
// ===========================================================================

verdict('S-Prov-1', [
  V('P3 (A_k overwrite, own binding present): the value is replaced in place',
    obs => obs.store.k1 === 'v2'),
  V('E.CP.P3: the input is accepted', obs => obs.at('star').refused === false),
  V('E.CP.P3 report: NO dependent re-run and no new act events — the overwrite is '
    + 'episode-invisible (the A3/PB-2 reading D1 adopts)',
    obs => times(obs, 'active:P') === 1 && state(obs, 'P') === 'active'),
])

verdict('S-Prov-2', [
  V('P4 (A_k overwrite, no own binding): the input is REFUSED',
    obs => obs.at('star').refused === true),
  V('E.CP.P4 refusal reason: the Def. 24 precondition (an own binding at k1\'s label)',
    obs => obs.refusals.length === 1 && obs.refusals[0].reason === 'NO_OWN_BINDING'),
  V('E.CP.P4 outcome: q shows P active and st(k1) absent',
    obs => state(obs, 'P') === 'active' && obs.store.k1 === undefined),
])

// ===========================================================================
// §12  CO-Iso
// ===========================================================================

verdict('S-Iso-1', [
  V('S2 (RealmRel = isolated-distinct): the SAME key is satisfied at one realm and '
    + 'unsatisfied at the other — P active at the shared realm, C pending at r1',
    obs => state(obs, 'P') === 'active' && state(obs, 'C') === 'pending'),
  V('E.CS.S2: P\'s binding is still visible at the shared realm',
    obs => obs.store.k1 === 'v1'),
  V('E.CS.S2: C never began, so it never read',
    obs => scoped(obs, 'read:C') === 0 && lacks(obs, 'active:C')),
])

verdict('S-Iso-2', [
  V('S3 (RealmRel = joined): C\'s declared k2 resolves to the same label r1 as P\'s '
    + 'k1, so C activates and reads v1 THROUGH THE JOIN — with distinct realms it '
    + 'would be pending (S-Iso-1)',
    obs => state(obs, 'C') === 'active' && has(obs, 'read:C:k2="v1"')),
  V('E.CS.S3 report: P active', obs => state(obs, 'P') === 'active'),
])

verdict('S-Iso-3', [
  V('S4 (RealmRel = reassigned): Def. 29 has NO precondition — the second isolate over '
    + 'an already-isolated key is NOT refused (a precondition-adding deviant refuses)',
    obs => obs.at('star').refused === false && obs.refusals.length === 0),
  V('E.CS.S4 report: C pending at the reassigned realm',
    obs => state(obs, 'C') === 'pending' && lacks(obs, 'active:C')),
  // The other half of D1 §12.3's stated verdict — "resolution follows r2 not r1" — is
  // NOT observable under this ρ: with no provider at either realm, C is pending
  // whichever assignment survives. Recorded as finding F3 in README.md rather than
  // asserted as if it were checked.
])

// ===========================================================================
// §13  CO-Int
// ===========================================================================

const deepEq = (a, b) => JSON.stringify(a) === JSON.stringify(b)

verdict('S-Int-2', [
  V('N2 (MetaPat = context-only): d(k1) = ε and ι(k1) = m1, so the get evaluates '
    + 'σ(k1)(ε ⊕ m1) = the base overlaid with m1',
    obs => deepEq(obs.extras['merged:C:k1'], { base: true, a: 1, b: 1 })),
  V('E.CN.N2 report: C active having read through the intercepted context',
    obs => state(obs, 'C') === 'active' && has(obs, 'read:C:k1="v1"')),
])

verdict('S-Int-3', [
  V('N3 (MetaPat = component⊕context): ⊕_k is RIGHT-BIASED, so on the overlapping '
    + 'field b the context entry m1 wins over the component\'s m2, and the disjoint '
    + 'fields merge. A left-biased deviant shows b = 2.',
    obs => deepEq(obs.extras['merged:C:k1'], { a: 2, b: 1, c: 1 })),
  V('E.CN.N3 report: C active', obs => state(obs, 'C') === 'active'),
])

verdict('S-Int-4', [
  V('N4 (MetaPat = context₁⊕context₂): among nested contexts the NEARER/LATER entry '
    + 'wins the overlapping field — b = 2, not 1. This kills `intercept-outer-wins`.',
    obs => deepEq(obs.extras['merged:C:k1'], { a: 0, b: 2, c: 1, d: 2 })),
  V('E.CN.N4 report: C active', obs => state(obs, 'C') === 'active'),
])

// ===========================================================================
// §14  CO-Acc
// ===========================================================================

verdict('S-Acc-1', [
  V('A6 (PosClass = isolation-boundary, the A8 refinement): the walk STOPS where child '
    + 'and parent resolve k1 at different realms and yields UD — although G\'s '
    + 'committed view binds k1 and would otherwise have authorized the access '
    + '(contrast S-It-3\'s T6). An ancestry-ignoring or boundary-ignoring deviant '
    + 'returns v1 here.', obs => has(obs, 'readfail:C:k1:UNDECLARED_ACCESS')),
  V('E.CA.A6: the failure is UNDECLARED, not INACTIVE — the boundary, not a missing '
    + 'view, decides', obs => scoped(obs, 'readfail:C:k1:INACTIVE') === 0),
  V('E.CA.A6 report: P, G, C all active (the failing read lands, A6 convention)',
    obs => state(obs, 'P') === 'active' && state(obs, 'G') === 'active'
      && state(obs, 'C') === 'active'),
])

// ===========================================================================

export const TSTAR_VERDICTS = Object.freeze(VERDICTS)

/**
 * Evaluate V_{r,s} half (2) — the named clauses — against one observation.
 * `certificates` says whether the target supplies the rule-certificate channel.
 */
export function checkClauses(script, obs, { certificates }) {
  const clauses = VERDICTS[script.id]
  if (!clauses) return [{ status: 'fail', kind: 'verdict', why: `no verdict defined for ${script.id}` }]
  return clauses.map((c) => {
    if (c.kind === 'certificate' && !certificates) return { status: 'skip', kind: c.kind, why: c.why }
    let ok = false
    let error = null
    try {
      ok = Boolean(c.check(obs))
    } catch (e) {
      error = String(e?.message ?? e)
    }
    if (ok) return { status: 'pass', kind: c.kind, why: c.why }
    return { status: 'fail', kind: c.kind, why: c.why, error }
  })
}
