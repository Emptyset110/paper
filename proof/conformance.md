# The Plugin-System Conformance Proof

**Subject.** *A Programming Paradigm for Spatiotemporal Composability*
(`../paper.pdf`) states in §5 that Cordis implements the calculus of §3–§4,
and formalizes the correspondence in Table 2 and Algorithms 1–10 — but does
not prove it. This document formalizes the plugin system that §5 describes,
constructs a finite test set, and proves the two claims the verification
needs:

- **Sufficiency** — an implementation passing the test set implements the
  calculus (under axioms stated in §4 below, each of which is named, honest,
  and as small as we could make it);
- **Necessity** — no test can be removed: each is the designated witness of a
  distinct clause of the formal system (injectivity into the clause catalog),
  and the mutation analysis shows the suite is minimal with respect to an
  executable catalog of single-decision deviations.

Everything checkable by machine is checked by machine: the reference model,
the suite, the kill matrix, and the verification runs live next to this file
and reproduce with the commands in §9. "Proof" below means: a rigorous
argument over explicitly stated axioms, whose every discharged step is either
constructive (a table you can audit) or executable (a run you can repeat). It
does not mean machine-checked derivation in a proof assistant; §4's axioms
delimit exactly what is assumed.

---

## 1. The formalized plugin system

### 1.1 The interface (from Table 2)

**Definition P1 (plugin-system interface).** A *plugin system* is a labeled
transition system whose configurations are the registries of Definition 45 —
finite maps of named fibers ⟨d, p, e, π, σ, τ, θ⟩ (Definition 44) over a
context carrying the coeffect store of Definition 22 with the isolation and
interception structure of Definitions 28–31 — together with:

- *orchestration inputs*: insert (O-Insert), retire (O-Retire), entry update
  (§5.2.1), the runtime value operation set(k,v) on an owned binding (an
  A_k operation, Definition 24), and the scope constructors isolate
  (Definition 29) and intercept (Definition 31);
- *lifecycle transitions*: the seven L-rules of Table 1, taken unprompted
  whenever their premises hold;
- *observables*: (i) the quiescent state — each fiber's lifecycle state Θ
  (Definition 49), its recorded outcome ξ, and the derived coeffect context
  σ_γ (Definition 45: the union of Active fibers' tables) read through get;
  (ii) the *event order* of effect applications, inverse applications,
  committed-view reads, and Active/deactivation transitions; (iii) the
  errors thrown at the two rejection points of Algorithm 6.

This is precisely the surface Table 2 assigns to `ctx.plugin`,
`fiber.dispose`, `fiber.update`, `ctx.provide`/`ctx.set`/`ctx.get`,
`ctx.isolate`, `ctx.intercept`, `ctx.effect`, `fiber.state`, and the proxy
read `ctx[key]`; the suite's adapter interface (`src/target.mjs`) is P1
verbatim, and the mapping of each member is written in the adapter sources.

### 1.2 Components as data

**Definition P2 (component script).** A component is the triple (d, p, e) of
Definition 43 given as data: `inject` is d; `provide` is p (the declared
provision set); and the effect function e is a finite list of *steps*, each
interpreted as **one iteration** of the effect iterator of Definition 51 —
provide(k,v) (the set of Definition 23), a revertible tracked effect (an
element of 𝔈*_Γ whose inverse is supplied with it, Definition 8), a
committed-view read (Algorithm 6), an in-place value operation, a
registration (Definition 47), or a raise (§4.3.4).

The step-per-iteration reading is not a convenience but the exact §5
correspondence: the real runtime drives an async generator and checks the
epoch before every `next()` (Algorithm 1's guard; `fiber.ts _execute`), so
one yielded inverse per step gives L-Iter's granularity and L-Divert's
abort boundary. The reference model (`src/model.mjs`) executes the same
steps under the literal Table 1 rules.

### 1.3 The reference model is the calculus

`src/model.mjs` implements, by direct transcription: the ten rules of
Table 1 with their premises (target views per Definition 46, σ_γ over
Active fibers per Definition 45/49, the relied guard of Definition 50, the
failure latch of §4.3.4, LIFO accumulators per Definition 52); O-Remove
gated on retirement + inactivity + childlessness; registration whose inverse
retires (Definition 47); Algorithm 6's access walk including its isolation
boundary; realms per Definitions 28–29 and interception per Definition 31
as §5.1.2 realizes them. The transcription is auditable rule-by-rule: each
`ruleFor` branch names its rule, and each premise reads the same fields
Table 1's row reads. Scheduling nondeterminism is explicit (fifo / lifo /
seeded-random visit order), because every claim of §4.4 quantifies over
schedules.

---

## 2. The obligation catalog (the "onto" map)

Each obligation pins one clause of the formal system. The catalog is the
bijection's constructive half: **onto** because every rule of Table 1, every
premise that guards one, the coeffect operations, the access discipline, and
the five metatheorems appear in the right column; **one-to-one** because no
two obligations pin the same clause (audit the middle column: all distinct).

| Obligation (test id) | Formal clause | Source |
| --- | --- | --- |
| R1.1 insert-activates-fresh | O-Insert conclusion: fresh Inactive(⊥) entry; lifecycle carries an unconstrained fiber to Active; provisions enter σ_γ | Table 1; Def 45 |
| R1.2 insert-under-removed-parent-rejected | O-Insert premise π ∈ dom(F_γ) ∪ {root} | Table 1 |
| R1.3 dynamic-provision-conflict-fails-offender | single-provider discipline when the Def 43 containment premise is broken: conflicting write fails the offender, never overwrites | Def 43/45; GAP-6 residue |
| R1.4 declared-provision-disjointness-at-insert | O-Insert premise ∀m. p ∩ p_m = ∅ (declared p; freed by removal, not retirement) | Table 1 |
| R2.1 retire-runs-recovery | O-Retire is a request; the rules run the accumulator — retirement never discards effects | §4.2; Table 1 |
| R2.2 retire-pending-clean | retiring a never-activated fiber applies an empty accumulator | Def 44 (σ empty until activation) |
| R3.1 removal-follows-inactivity | O-Remove premise θ = Inactive(−): the entry survives (serving committed reads) until dependents finished | Table 1; Lemma 57 |
| R3.2 registration-cascade-recovers-children | Def 47: the registration's inverse retires the child; the cascade leaves nothing (order vs. parent's own inverses deliberately open — §4.3.1) | Def 47 |
| R4.1 begin-requires-satisfaction | L-Begin premise ω = target ≠ ⊥ | Table 1; Def 46 |
| R4.2 provider-arrival-wakes-pending | reactivity: rules fire unprompted when premises become true | §4.2 "reactive only" |
| R4.3 satisfaction-counts-active-only | σ_γ unions **Active** tables alone; a Reloading provider's keys satisfy nobody | Def 45/49 |
| R4.4 failure-latch-unchanged-env | L-Begin reads Inactive(⊥): no retry of Inactive(ξ) against an unchanged environment | §4.3.4 |
| R5.1 iteration-order-and-lifo-recovery | L-Iter order; accumulator g∘h composition ⇒ LIFO recovery | Table 1; Def 52; Thm 16 |
| R6.1 divert-honors-target-change | Thm 64 dichotomy: abort at a boundary with recovery, or land-then-deactivate; never quiesce Active on a stale ω; applied ⇒ recovered | Thm 64; §4.3.3 |
| R7.1 raise-recovers-then-latches | L-Raise: route through Unloading (accumulator runs), record ξ, provide nothing after | Table 1; §4.3.4 |
| RU.1 update-restarts-with-new-config | entry update: re-run against new config; new entry state clears the latch | §5.2.1 |
| R8.1 leaving-provider-reads-own-deps | Thm 63(3): committed reads served for the whole episode, own teardown included | Thm 63 |
| R9.1 withdrawal-guard-orders-teardown | L-Unload guard ¬relied: dependents' teardown (reads included) completes before ANY provider inverse | Table 1; Def 50; Alg 5 line 25 |
| R9.2 recovery-exactness-on-deactivation | Cor 62 on the non-retired path: no residual binding; clean re-provision | Cor 62 |
| C1.1 provision-value-operations | get/set of Def 23 + an A_k value operation on the owned binding | Def 23/24 |
| C2.1 overwrite-observability-dichotomy | the calculus leaves post-activation overwrite undefined (GAP-7 hole); either §5.1.3's not-observed or GAP-3's observed-replacement — never a torn episode | §5.1.3 vs Thm 63(3); see §7 PB-2 |
| C3.1 isolation-independence | Def 28/29: same key, independent realms, independent bindings | Def 28/29 |
| C3.2 isolation-label-join | shared label joins scopes; joined realm has one binding | Def 29 |
| C4.1 intercept-nearest-wins | Def 31 merge as §5 realizes it: nearer entries override, base below all | Def 31; service resolveConfig |
| C5.1 undeclared-access-rejected | Alg 6 line 6: reject at root | Alg 6 |
| C5.2 ancestry-authorized-access | Alg 6 walk: first ancestor's committed view authorizes | Alg 6 |
| C5.3 declared-inactive-access | Alg 6 line 5: declared-but-uncommitted fails as inactive, not undeclared | Alg 6 |
| M1 interleaved-recovery-independence | Thm 61 / Cor 21: an inverse withdraws its own contribution only, in any order | Thm 61 |
| M2 dependency-ordering-chain | Thm 63 globally: activations follow ≺, guarded deactivations reverse it | Thm 63/66 |
| M3 provider-identity-coherence | ω records the provider, not the value: equal-valued replacement still reloads | §5.1.3 p60; Thm 64 |
| M4 quiescence-on-unsatisfiable | Thm 66: quiescence; a ≺-cycle quiesces Inactive(⊥), no spin, no failure | Thm 66 |
| M5 confluence-across-histories | Thm 73: the quiescent state is a function of the final configuration | Thm 73 |

Clauses deliberately **not** in the catalog are listed in §8 (boundary), each
with its reason.

---

## 3. The claims

**Theorem S (sufficiency).** Let I be an implementation of P1, and suppose
axioms A1–A4 (§4). If I passes every obligation of §2 under every schedule,
then every run of I under orchestration inputs is a run of the calculus:
each configuration I quiesces in, and each event order I exhibits, is one
the rules of Table 1 (with §4.3's extensions) derive — up to the paper's own
≃/≈ (Definition 33, Definition 53) and the declared boundary of §8.

**Theorem N (necessity).** (a) The catalog map obligation → clause is
injective, so no two tests witness the same clause; dropping any test leaves
its clause without a designated witness, and the "onto" property fails.
(b) Empirically: for an executable catalog of 27 single-decision deviations
of the model (`MUTANTS` in `src/model.mjs`), every deviation is caught by
the suite (K1), and the suite is minimal in the standard mutation-testing
sense — §6 gives the exact matrix, including which 14 tests are the *unique*
catcher of some deviation and which 4 are subsumption-shielded witnesses
retained by claim (a).

---

## 4. Axioms

Everything Theorem S assumes beyond the runs themselves:

- **A1 (Adapter faithfulness).** Table 2's correspondence is the intended
  reading of P1: `ctx.plugin` is O-Insert (+ the lifecycle's autostart),
  `dispose` is O-Retire with O-Remove collapsed onto inactivity,
  `ctx.provide` is Definition 23's set, the async-generator interpretation
  of steps is Definition 51's iterator, and the trace/state observables of
  §1.1 are read where the calculus reads them (Definition 53's fields at
  quiescence; order from synchronously pushed events). The adapters are
  ~200 lines each and exist to be audited against Table 2.
- **A2 (Schema uniformity).** The implementation does not special-case: its
  behavior on a rule instance does not depend on component identity, key
  names, or step payloads beyond what the rule reads. Under A2, verifying a
  rule schema on the catalog's finite instances verifies the schema. This is
  the standard finite-instantiation axiom of testing; the premise-coverage
  design (each rule premise is toggled by some obligation: presence and
  absence both appear in §2's rows) makes the instances span every guard.
- **A3 (Scheduling abstraction).** The runtime's microtask scheduler
  realizes the calculus's nondeterministic step relation: any rule whose
  premises hold is eventually taken (fairness), and quiescence detection
  (`settle`) observes Definition 49's quiet. The instant a target view turns
  is not externally observable under asynchrony — §4.3.3's inertia — so
  obligations quantify over the dichotomy Thm 64 states, not over the
  unobservable instant (see R6.1's note).
- **A4 (Witness obligation).** The inverse a tracked effect supplies indeed
  reverts it (the witness of Definition 8). The paper itself discharges this
  by convention, not verification (§5.1.1); the suite's tracked effects are
  trace-writers whose inverses are correct by construction, so A4 is about
  the implementation's *composition* of inverses, which is exactly what
  R5.1/R9.x observe.

**Proof of Theorem S** (sketch with every load-bearing step named).
By induction over a run's steps. *Base*: the empty registry is the
calculus's γ⁰. *Induction*: assume the configuration after t steps is
calculus-derivable. The next event is (i) an orchestration input — its
admission conditions are pinned by R1.2/R1.4 (O-Insert premises), R2.x
(O-Retire unconditional-but-recovering), RU.1 (update) and its write
discipline by R1.1/R3.1 (Table 1's write columns); or (ii) a lifecycle
transition — for each L-rule, its *applicability* is pinned positively and
negatively by the R4.x obligations (L-Begin: fires at satisfaction, not
before, not on Reloading providers, not from ξ), its *iteration semantics*
by R5.1/R6.1/R7.1 (order, boundary, raise), its *deactivation semantics* by
R8.1/R9.x (guard, committed reads, exactness), and its *scope semantics* by
C1–C5 (which fix how σ_γ, realms, interception, and the access walk read
the configuration the rules write). By A2 the pinned instances extend to the
schema; by A3 the scheduler takes only applicable rules and takes an
applicable one eventually. Hence the step reached after t+1 is derivable.
The M-obligations discharge the residue A2 alone cannot: they observe the
*composition machinery* (interleaving, chains, replacement, quiescence,
history-independence) whose defects are invisible to any single-rule test —
each M-theorem is a consequence of the rules in the calculus (proved in
§4.4 of the paper), so a failure of an M-test with all R/C-tests passing
would convict precisely the engine gluing rule applications together, and
passing them closes the induction over multi-fiber runs. ∎

**Proof of Theorem N(a).** Inspection of §2's middle column: the 32 clauses
are pairwise distinct (distinct rule, distinct premise of one rule, or
distinct definitional obligation). A dropped test's clause retains no other
witness — the remaining tests each pin their own clause, and no assertion in
another test reads the dropped clause's observable in a way its mutant
analysis credits (§6's matrix column for that test). ∎

**Proof of Theorem N(b).** Executable: `node run-necessity.mjs`. Results in
§6. ∎

---

## 5. Verification results — single process

Targets: the reference model (4 schedules), the calculus-aligned build
(`deepseek-harness/vendor/cordis`, carrying the paper-review GAP fixes),
and the unfixed upstream build (`@deepseek-ai/cordis` 4.0.1 as installed —
identical to `dsh-ts/vendor/cordis`).

| Target | Result |
| --- | --- |
| Reference model (fifo / lifo / random×2) | **32/32** on every schedule |
| Calculus-aligned build | **32/32** |
| Upstream 4.0.1 | **28/32** |

The four upstream divergences, each independently rediscovered by the
systematic suite and mapped to the prior targeted catalog
(`paper-review/README.md`):

- **R9.1, M2** — the L-Unload guard sits inside the provide effect's own
  disposer while `Fiber._unload` starts every disposer at once, so provider
  inverses run before (R9.1) and interleave with (M2) dependents' guarded
  teardown. This is GAP-1 + GAP-2 (both class A, fixed in the aligned
  build); the suite's traces show the literal violation
  (`revert:P:p1` preceding `revertread:C:…`).
- **R1.4** — declared-provision disjointness unenforced at insert: GAP-6's
  fixed half, present upstream.
- **RU.1** — **new, not in the prior catalog**: after a failed first
  activation, a *later* `update()` of the by-then recovered and ACTIVE
  fiber releases the first episode's rejection as a process-level
  `unhandledRejection` (observable states and effect traces are otherwise
  correct). Minimal reproduction: insert a plugin that yields one disposer
  then raises; update it to a passing config (recovers, ACTIVE); update it
  once more — the original error surfaces as an unhandled rejection. Absent
  on the aligned build, whose GAP-9 fix reworked exactly this rejection
  plumbing. Classification: class A (the calculus records ξ on the fiber;
  nothing may escape the boundary).

## 6. Necessity results — the kill matrix

`run-necessity.mjs` runs the suite once per mutant per schedule (fifo +
lifo; a deviation counts as caught if any schedule exhibits it — the
calculus quantifies over schedules, and one mutant is *only* catchable
under lifo, which is itself a finding about schedule-shielded bugs).

- **K1 — all 27 mutants killed.** Every cataloged single-decision deviation
  of the model fails at least one test, under fifo or lifo scheduling (the
  matrix runs both, and kill sets genuinely differ across schedules — a
  finding in itself about schedule-shielded bugs).
- **K2 — 14 obligations have an exclusive killer**: a mutant that fails that
  test and no other (C2.1, C3.1, C4.1, C5.1, C5.2, C5.3, R5.1, R6.1, R7.1,
  RU.1, R9.2, R1.2, R1.4, R3.2 — the runner prints the pairing).
- **K3 — minimality, honestly stated.** "Test t is non-redundant w.r.t. the
  mutant set" (some mutant is caught by t alone) is *the same criterion* as
  K2's exclusive killer, so exactly those 14 tests are mutation-minimal.
  The other 18 are *subsumption-shielded*: every single-decision deviation
  in their reach is caught alongside them by sharper or broader
  observables — a breaking of L-Begin's guard, for instance, cascades into
  half the suite, so no mutant can be caught by R4.1 alone. Foundational
  clauses are like that structurally, and inventing compound mutants to
  force exclusivity would only manufacture contrivance. Those 18 tests are
  retained by Theorem N(a): each is the designated witness of a clause that
  would otherwise have none. Two candidate mutants were *removed* during
  construction for being observationally vacuous, which is itself evidence
  the rules self-heal those deviations: a value-compared target view
  (unreachable under the single-provider discipline + guard), and a
  retire-flushes-pending-work variant (whose phantom episode the divert
  rule cancels before an iteration runs).

## 7. Findings about the paper itself

The construction surfaced three paper-side issues, distinct from
implementation bugs:

- **PB-1 (Table 2 erratum).** Table 2 maps Definition 23's set(k,v) to
  `ctx.set`. The primitive carrying set's precondition (k ∉ dom σ) and its
  inverse is `ctx.provide`; `ctx.set` is an A_k value operation on an
  existing binding. (Independently noted in paper-review GAP-3's analysis;
  the catalog and adapters use the corrected mapping.)
- **PB-2 (§5.1.3 vs Theorem 63(3)).** For an in-place overwrite by an
  Active provider, §5.1.3 prescribes "not observed" while the
  Theorem-63(3)-consistent repair adopted by the aligned build makes it an
  observed replacement. The calculus itself is silent — an Active fiber's
  operations are outside the transition system (the GAP-7 hole) — so both
  are extensions, and they contradict each other. C2.1 pins what the
  calculus *does* force on any extension (never a torn episode) and treats
  the branch as a documented choice. The paper should pick one: either
  strike the "not observed" sentence or scope Thm 63(3) to bindings not
  overwritten in place.
- **PB-3 (Algorithm 10 races its own premise).** O-Insert's disjointness
  premise forbids admitting a new declarer of k while any fiber declaring k
  is still registered — replacement must be staged retire → drain → remove →
  insert. Algorithm 10 (transactional reload) instead calls
  `entry.fiber.dispose()` and `ctx.use(...)` back-to-back, relying on the
  dynamic-conflict path winning a microtask race against the disposal. The
  model exposed this under lifo scheduling as a latched spurious failure
  (M3's construction note). The loader is correct only under scheduling
  assumptions the calculus neither states nor licenses; the staged form
  (which M3 now uses) is the one whose premises hold at every step.

Also recorded as a lesson: the calculus orders parent/child deactivation
strictly weaker than provider/consumer (§4.3.1) — the first draft of R3.2
overclaimed there, and the reference model (not the implementation) was
what caught it.

## 8. Boundary — clauses deliberately not in the catalog

- Def 48 confinement (a component reads only its d): a premise on
  components, unenforceable at runtime; Algorithm 6's ancestry walk (C5.2)
  is the implementation-normative access rule and *serves* reads Def 48
  forbids — the paper's own §5 supersedes its §4 here (GAP-5, class B).
- `Impl.check` as a second availability channel (GAP-4, class B): no
  calculus counterpart; untested.
- Effects registered while ACTIVE (GAP-7, class B): outside the transition
  system; only its C2.1 shadow is pinned.
- Retirement/removal collapse residue (GAP-8's registry-timing half):
  upstream/aligned both collapse O-Retire+O-Remove into dispose; R3.1 pins
  the observable half (entry survival until inactivity).
- The event system (`ctx.on`/emit): modeled by the paper only as
  commutative-key registrations (§3.3.2 discussion); not part of the
  calculus's rule set.
- Inverse correctness (A4), emissions across the system boundary (§6.1),
  and GC/timing — as the paper itself scopes them.

## 9. Corollary — the distributed system

**Statement.** Let I be single-process conformant (§5) and let cordis-node
satisfy its Distribution Equivalence Contract
(`cordis-plugins/cordis-node/docs/equivalence.md`: any placement of
components over nodes is observationally equivalent to single-node while
links are healthy). Then the distributed system conforms to the calculus:
every obligation holds with components placed across nodes, because each
obligation is a statement over P1-observables and the contract carries
P1-observables across placement. The corollary is *checked*, not merely
argued: the identical 32-test suite runs against a third adapter
(`src/adapter-distributed.mjs`) — two Cordis nodes joined by
`@rebuilding/cordis-node` over loopback transports with mutual partition
mounts, root-level inserts alternating between the nodes (so provider and
consumer genuinely straddle the boundary — e.g. R9.2 passes with the
provider on node A and its dependent on node B, satisfied through
projection), and all σ_γ observations reading node A.

**Result: 28/32 — failing exactly the four obligations the underlying
build fails locally** (the distributed stack runs on upstream 4.0.1, its
dependency): R9.1, M2, R1.4, RU.1. The set difference
(distributed failures) − (single-process failures on the same build) is
**empty**: the distribution layer introduced no divergence of its own,
which is the corollary's empirical content. Isolation/interception
obligations (C3.x, C4.1) place node-locally by design — realm labels are
per-node vocabulary — and are classified as node-local rather than
cross-node obligations.

## 10. Reproduction

```sh
cd paper/proof
node --test tests/*.test.mjs                     # reference model (default)
MODEL_ORDER=lifo node --test tests/*.test.mjs    # any schedule
PROOF_TARGET=cordis node --test tests/*.test.mjs # calculus-aligned build
PROOF_TARGET=cordis CORDIS_LIB=<path>/lib/index.js node --test tests/*.test.mjs
PROOF_TARGET=cordis-node node --test tests/*.test.mjs   # two-node distributed
node run-necessity.mjs                           # kill matrix, K1/K2/K3
```

No install step: the suite has no dependencies beyond Node ≥ 22; real
builds are imported directly from their checkouts (`src/target.mjs` holds
the default paths).

## 11. What the proof bought

The exercise found, on top of the prior targeted catalog: one new
implementation defect (RU.1's escaped rejection, upstream), one paper
erratum (PB-1, corroborated), one paper-internal contradiction (PB-2, now
pinned as a dichotomy any conforming extension must satisfy), one
algorithm-vs-premise race in the paper's own loader (PB-3), one
overclaimed ordering in our own first draft (R3.2 — caught by the model,
i.e. by the calculus itself), and the empirical form of the distribution
corollary (zero divergence attributable to cordis-node). Fixes for the
upstream defects exist in the aligned build; RU.1's fix belongs with the
GAP-9 plumbing rework when upstream syncs it.
