# T\* — the finite characteristic suite, executable

$T^\star = \{(\rho_{r,s}, V_{r,s})\}$, the 60 canonical experiments of
`../signatures.md` §§1.4–14.3, expressed so they run against real Cordis
builds. Until now the suite existed only on paper: the scripts were derived
line by line in `../derivations.md` (Appendix E) and nothing executed them, so
no build had ever been checked against Theorem 2.

Every entry records the chain the manuscript claims —

> Table-1 rule → occurrence letter → canonical script → executable experiment

— as the `rule`, `letters`, `id` and `source` fields of `scripts.mjs`, so a
reader can follow any test back to the rule whose alphabet it indexes and the
Appendix E item that derives it. Nothing here is inherited from the
32-obligation suite in `../../proof/tests/`, which predates the theory. The
only things taken from `../../proof/` are the mechanism modules: `src/dsl.mjs`
(component/step vocabulary), `src/adapter-model.mjs`, `src/adapter-cordis.mjs`,
`src/adapter-distributed.mjs`, `src/target.mjs`.

## Running it

The environment conventions are `../../proof/src/target.mjs`'s, unchanged.

```bash
cd paper/formal/tstar

# (a) the reference model — the executable specification. This must be 60/60:
#     it is Theorem 2's soundness gate, the specification satisfying its own suite.
node run-tstar.mjs

# (b) the calculus-aligned build
PROOF_TARGET=cordis node run-tstar.mjs

# (c) the published upstream build
PROOF_TARGET=cordis \
CORDIS_LIB=../../../cordis-plugins/cordis-node/node_modules/.pnpm/@deepseek-ai+cordis@4.0.1_@deepseek-ai+cordis-plugin-include@1.0.6_@deepseek-ai+cordis-plugin-loader@1.0.2/node_modules/@deepseek-ai/cordis/lib/index.js \
  node run-tstar.mjs

# (d) the two-node distributed target
PROOF_TARGET=cordis-node node run-tstar.mjs

# a subset, with the full observation of each failure
TSTAR_ONLY=S-Div-1,S-Unl-6 TSTAR_VERBOSE=1 node run-tstar.mjs

# as an ordinary test run (adds the suite's own structural obligations)
node --test tstar.test.mjs
PROOF_TARGET=cordis node --test tstar.test.mjs
```

`CORDIS_LIB` may be a path relative to `../../proof/src/` or an absolute
`file://` URL; `../../proof/src/target.mjs` exports both `HARNESS_LIB` (the
aligned build, the default) and `UPSTREAM_LIB`.

## Results

| target | scripts | occurrence letters |
| --- | :-: | :-: |
| reference model (`adapter-model.mjs`) | **60 / 60** | 86 / 86 |
| calculus-aligned build (`deepseek-harness/vendor/cordis`) | **50 / 60** | 77 / 86 |
| published upstream `@deepseek-ai/cordis` 4.0.1 | **49 / 60** | 79 / 86 |
| distributed (`cordis-node`, two nodes over the upstream build) | **49 / 60** | 78 / 86 |

A script credits its target letter only when it passed *and* the target's
schedule took the canonical branch; a `branch` clause reported unrealized
leaves the letter untested on that run even though the script conformed.

Findings F1–F7 below explain every failure: 10 on the aligned build
(7 × F1, plus F2, F3, F4) and 11 on upstream (7 × F1, plus F2, F3, 2 × F5).
F1–F3 hit both builds; F4 and F6 are the aligned build's alone; F5 is
upstream's alone; F7 is a defect in D1 itself.

## What a verdict is

`§5.4`: a canonical experiment drives the system to a pointed configuration
realizing $s$, lets the attempt at $r$ occur, and asserts $\equiv$-equality of
the implementation's outcome set with the specification's — certificates
included. `§6.3` unpacks that into enablement/refusal, the certificate, the
ordinary event word, the quiescent report, and termination.

`verdicts.mjs` realizes $V_{r,s}$ in two halves, both required:

1. **$\equiv$-equality against the executable specification.** The script runs
   against the reference model and against the target; the two observations
   must agree on the report (states, recorded outcomes ζ, store contents,
   refusal reasons, external reads) and, unless Appendix E marks the word
   schedule-dependent, on the ordinary event word letter for letter and in
   order.
2. **The load-bearing clauses.** Each Appendix E item ends with a `Report:`
   line and usually a named observation that separates the target occurrence
   from its neighbours ("the withdrawal is X7's observation"; "no re-begin
   certificate follows deact(C)"; "inv(P,c) < inv(P,b) < inv(P,a) <
   deact(P)"). Those are transcribed as explicit predicates, each carrying the
   sentence it convicts, so a failure names a clause rather than showing a
   diff.

Half (2) is what makes (a) meaningful: against the reference model half (1) is
trivial, and the run is checking that the specification satisfies its own
suite.

**Vocabulary split.** Theorem 2 is stated for the certificate-instrumented
vocabulary with a proviso for the certificate-erased one (§5.4, §6.3). The
reference model emits rule certificates (`begin`/`leave`/`divert`/`raise`, and
the provision write); a real build has no certificate channel. The observation
therefore separates `word` (the ordinary events every target emits: `apply`,
`revert`, `read`, `readfail`, `revertread`, `setvalue`, `registered`,
`flagged`, `active`, `deactivated`) from `certWord`. Cross-target comparison
uses `word`; clauses that read `certWord` are declared `kind: 'certificate'`
and are skipped where the channel does not exist.

**Clause kinds.**

| kind | meaning |
| --- | --- |
| `verdict` | must hold on every target; failure fails the script |
| `certificate` | reads the certificate channel; evaluated on the model only |
| `branch` | the occurrence lives on one branch of an Appendix E schedule note. Required on the reference model, whose schedule the script pins. On another target a failure is reported as *letter-not-realized*, **not** as a conformance violation — the specification's own outcome set contains the other branch too. |

## DSL extensions

`dsl-ext.mjs` wraps `../../proof/src/dsl.mjs`; nothing under `../../proof/` was
modified. Four kinds of addition were needed.

1. **Missing step constructors.** `raiseUnless(f, x)` — required by L-Iter's
   T11 and L-Raise's X3 — had no builder, though both adapters interpret the
   step. `trackReadOnRevert(k, t)` is the **A7 grammar extension**: D1 §10.3
   records that §2.2's step grammar has no inverse that reads, while Def. 48
   clause 2 licenses one and S-Unl-6 (U8) depends on it. The paper explicitly
   flags this; the suite uses the extension and the script says so.

2. **An orchestration-script vocabulary.** D1 writes ρ as a sequence of
   `insert / retire / update / setval / isolate / intercept / settle` inputs;
   `dsl.mjs` covered only component data. `dsl-ext.mjs` makes the Λ_orch half
   data too, so a canonical script is fully declarative and `observe.mjs`
   interprets it uniformly against any adapter. `isolate`/`intercept` derive
   the *ambient* resolution context for subsequent inserts (Defs. 28/31), and
   an insert under a named parent composes the ambient derivations on top of
   that parent's context — which is what S-Acc-1 needs, the isolation boundary
   having to fall *between* C and its parent G.

3. **Schedule pinning (`pin`).** Three canonical scripts realize their target
   occurrence only on a schedule the reference model's FIFO strategy does not
   take:

   - **S-Div-1** (D1/D4/D5). The printed ρ retires P before the settle; FIFO
     then leaves P before C ever begins, so no L-Divert window is reached.
   - **S-Div-3** (D3). Same shape: FIFO leaves G first, retires C while it is
     still Inactive(⊥), and C never becomes Reloading —
     `../explorer-report.md` §11.6 records the same branch.
   - **S-Rem-5** (M7) uses the device only to *read*, see (4).

   `pin(marker, action)` arms an orchestration input on a trace marker, using
   the one-shot watcher already in `createTrace`. It places the input at the
   iteration boundary the canonical schedule uses without changing the pointed
   configuration: the L-Divert premises read the diverting fiber's state and
   σ_γ, not when τ flipped. Every steering pin carries a `schedulePin` field
   saying which branch it selects and why, and `tstar.test.mjs` fails if one
   does not.

4. **Mid-settle report reads (`snapshot`).** M7's observation is a *blocking*
   decision whose evidence exists only strictly inside a settle: the parent
   must still be in the registry while its child is being torn down. S-Rem-5
   snapshots the report at `inv(C,b)`.

Two further harness conventions, both stated rather than assumed:

- **O-Retire's refusal.** The adapters' `retire` is unconditional, but
  O-Retire has a premise ($n \in \mathrm{dom}\,F_\gamma$) whose violation is a
  reachable refusal (R4). `observe.mjs` records the registry membership at the
  attempt and classifies the input as refused when the name has been removed;
  the verdict additionally requires that the refused input emit nothing.
- **Interception reads.** Def. 31's get evaluates
  $\sigma(k)(d(k) \oplus_k \iota(k))$. Both adapters expose the merge directly
  (`interceptMerged`), with $d(k)$ supplied as the base argument, so S-Int-2..4
  read the merged metadata rather than inferring it from a value.

## Findings

Each is a place where the run disagrees with the manuscript. They are reported,
not patched away.

### F1 — disposal of a never-activated fiber emits a deactivation (both builds)

*Scripts:* S-Ins-3, S-Ret-1, S-Ret-3, S-Ret-4, S-Rem-1, S-Rem-3, S-Beg-3 — 7 of
the 10 failures on the aligned build.

The calculus takes a fiber that never began from Inactive(⊥) straight out of
the registry by O-Remove, with $\Psi = \mathrm{id}$ and no event: there is no
Unloading state to be in and no L-Unload window (Appendix E's derivations show
exactly this, e.g. E.OT.R1(4), E.LB.B4(4)). Both Cordis builds route *every*
disposal through UNLOADING, so an ordinary `deact` letter appears that no
specification outcome contains. In S-Ret-3 / S-Rem-3 it appears a second time,
after the deactivation the raise already produced.

The effect is benign — nothing is applied or recovered — but it is a genuine
difference in the abstract state trajectory, and `states` is a report-visible
field under CF1. It is also *decidable in the paper's favour either way*: if
L-Unload is read as applicable with an empty accumulator to any Inactive fiber
being removed, the divergence disappears and D1 §10's alphabet gains no letter.
**This wants a decision in Appendix D §10 before the evaluation section is
written**, because it accounts for the majority of both builds' failures and it
is a one-line reading, not a bug.

### F2 — parent/child teardown ordering is inverted (both builds)

*Scripts:* S-Unl-5 (U7); it is also what makes S-It-4's word diverge.

E.LU.U7(10) states the verdict as `deact(G) < inv(C,b)` — "the child is reached
one level at a time (p. 32)". That ordering is *forced* by the calculus's step
granularity: L-Unload@G is one atomic transition whose Ψ runs the accumulator
(including the register⁻¹ that retires C) and then writes
$\theta_G \mapsto \mathsf{Inactive}$, emitting deact(G); the child's own L-Leave
and L-Unload are separate later steps. Both builds do the opposite: the child's
subtree is fully torn down first and the parent's deactivation completes last
(`revert:C:b | deactivated:C | deactivated:G`).

This is the headline of the run, because the 32-obligation suite **explicitly
waived it** — `rules-o.test.mjs` R3.2 says in so many words: "Deliberately NOT
asserted: any order between the child's unload and the parent's other
inverses … an implementation may sequence the two more strongly, and Cordis
does." T\*, derived from the alphabet rather than from intuition, does not have
that freedom: E.LU.U7 names the order as U7's observation. Either

- the manuscript is right and both builds deviate at L-Unload's registration
  inverse, or
- §4.3.1's "a parent may run its inverse while a child of it is still
  Unloading" is meant to license either order, in which case **E.LU.U7's stated
  verdict overreaches** and the clause must be weakened to "inv(C,b) occurs"
  (which both builds satisfy).

The suite cannot decide this; the paper must.

### F3 — an orchestrator-inserted child is disposed with its parent (both builds)

*Script:* S-It-4 (T7), which also carries CO-Acc A3.

The calculus distinguishes a fiber inserted *under* π = G by the orchestrator
(plain O-Insert; G's teardown does not touch it) from a fiber *registered* by
G's effect function (Def. 47, which pushes an O-Retire inverse). S-It-4 turns on
that distinction: C must survive G's deactivation as a still-registered pending
fiber so that, when Q2 revives k2 and C re-begins, C's read walks to G — an
ancestor that *declares* k1 and holds no committed view — and Algorithm 6 line 5
fires (INACTIVE_ACCESS, not UNDECLARED).

In both builds `insert(G, C)` is `G.ctx.plugin(...)`, which is also the only
realization of Def. 47 registration, so C is disposed together with G. C ends
`disposed` where the specification has it `active`, and T7 (with A3) is
**unreachable on any Cordis build**: the interface has no way to present the
pointed configuration. This is a gap in Table 2's mapping, not merely in a
build — D1 §5.3 already calls T7 "the subtlest reachability fact in this
deliverable", and it turns out to be subtler than that: reachable in the
calculus, unreachable through the implementation's interface. It belongs in
D1 §15's unrealizable column *for implementations*, alongside the note that the
specification does reach it.

### F4 — A4 is resolved differently by the aligned build (aligned build only)

*Script:* S-Rai-3 (X4, with P2 and S3's negative form).

Ambiguity A4 (D1 §17) records that O-Insert's declared-disjointness premise is
**key**-level, so with Def. 28 realms two joined keys collide at one storage
*label* without violating it; D1 adopts the model's reading, that the collision
surfaces dynamically as Def. 23's set precondition failing — an ordinary raise
at the offender (X4).

- The **upstream** build does exactly that: Q activates, its `provide` fails
  with `service "k2" has been registered at <P>`, Q ends failed, P untouched.
  S-Rai-3 passes and X4/P2 are covered.
- The **aligned** build refuses Q's *insert* with a provision conflict — it
  enforces disjointness at the label level, after realm resolution. The
  offender never runs; X4 is unreachable there.

Both are defensible fail-safes and the calculus decides neither. A4 is
therefore not just "a gap in the premise inventory": the two builds have
resolved it in opposite directions, and D1 picked one. The paper should either
adopt the label-level insertion premise (and rewrite S-Rai-3, whose letter then
becomes unreachable exactly as in the realm-free base calculus) or state that
both resolutions conform and make $V_{\text{L-Raise},X4}$ accept the pair.

### F5 — upstream violates two premises the aligned build honours (upstream only)

*Scripts:* S-Ins-4 (I7), S-Unl-2 (U2).

- **I7 / O-Insert premise (iv).** Upstream admits a second component declaring
  an already-declared provision: no refusal, both fibers registered. This is
  the `insert-allows-duplicate-provider` deviation, on the nose.
- **U2 / the reliance guard.** Upstream runs the provider's inverse *before* its
  dependent's: `revert:P:a | revert:C:b` where the specification requires
  `revert:C:b | revert:P:a`. This is `unload-without-guard`, i.e. a direct
  violation of Theorem 63's ordering — the one Appendix E calls "Thm. 63's
  content as an event order".

The aligned build passes both; these are precisely the repairs it carries. The
distributed target (`cordis-node`, two nodes over upstream) reproduces
upstream's profile: 49/60, the *same eleven failing scripts and the same
convicted clauses*, differing only in which canonical branch its schedule takes
(S-Div-1's, rather than none). That is itself worth stating — the distribution
layer neither adds nor masks a conformance defect.

### F6 — D3's canonical branch is not selectable on the aligned build

*Script:* S-Div-3 (D3), reported as *letter-not-realized*, not as a failure.

With the pin in place the aligned build lets C's re-begun episode run to
completion — `apply:C:b | revert:G:a | apply:C:c | active:C` — so C reaches
Active *while retired* before leaving, rather than diverting at the iteration
boundary after track(b). Upstream and the reference model both abort. Because
the retirement here propagates asynchronously (G's dispose is a promise, C's
next `iter.next()` may win the race), this is a microtask-ordering artifact of
the pin rather than a demonstrated missing epoch check, so the runner classifies
it as a coverage gap. Confirming or refuting it needs a device that stops the
world between iterations — the same asynchrony question A9 raises for D6. On
the distributed target the analogous gap falls on S-Div-1 instead.

### F7 — S-Iso-3's stated verdict is half unobservable (a defect in D1 §12.3)

D1 §12.3 gives S-Iso-3's verdict as "no refusal on the second isolate, **and
resolution follows r2 not r1**". Under its own ρ —
`isolate(k1,r1); isolate(k1,r2); insert(root,C); settle` — nothing provides at
either realm, so C is pending whichever assignment survives: the second half is
not observable. `verdicts.mjs` asserts only the observable half and says so at
the site. E.CS.S4 itself notices this ("observable as C pending even if a
provider is later added under r1 only") without amending the script. The fix is
one component: add a provider inserted under r1 after the reassignment, whose
non-satisfaction of C then witnesses that r2 won.

## Coverage against the alphabet

`run-tstar.mjs` reports, per target, which of D1 §15's 86 reachable occurrences
the passing scripts realize. On the reference model this is 86/86, which is
obligation **(D-C)** (CF5) checked rather than asserted; `tstar.test.mjs`
checks the same claim statically. On a real build the uncovered set is the
interesting output — it names the letters the build's own behaviour prevents
the suite from presenting:

| target | uncovered |
| --- | --- |
| aligned | A3, D3, I3, M4, P2, R3, R4, T7, X4 |
| upstream | A3, I3, I7, M4, R3, R4, T7 |
| distributed | A3, D4, I3, I7, M4, R3, R4, T7 |

`I3, M4, R3, R4` are uncovered only because their scripts fail on F1 (the
spurious deactivation); they would return the moment F1 is decided.
`A3, T7` are F3. `P2, X4` are F4; `I7` is F5. `D3` (aligned) and `D4`
(distributed) are F6 — schedules whose canonical branch the pin did not
select, not conformance failures.

## What T\* does not catch that the 32-obligation suite does

Two of the older suite's obligations have no counterpart here, and both are
evidence about the alphabet rather than about the suite:

- **C2.1 (overwrite-observability dichotomy).** The older suite tests that an
  in-place overwrite under an *installed dependent* is either neutral or a
  complete withdraw-and-reinstall, never a torn episode. D1's P3 script
  (S-Prov-1) has no dependent at all, because P3's occurrence is about the
  A_k precondition, not about episode integrity. The property C2.1 tests is a
  *metatheorem* (Cor. 62 applied across an overwrite), not an occurrence, so
  it is invisible to an occurrence-indexed suite. If the paper wants T\* to
  subsume the obligation suite, the alphabet needs an occurrence for "A_k
  overwrite with a live committed reader" — which is exactly PB-2's
  under-specification, still open.
- **C5.3 (declared-inactive access).** This is Correction C5's external
  Def.-23 read realizing A4. D1 §14.3 records the letter as excluded from the
  *lifecycle-window* reading and keeps 86/6, so no canonical script indexes it
  and T\* does not exercise it. `dsl-ext.mjs` exports `readVia` so that an
  additive entry can, the day §14.3's strict reading (87/5) is adopted.

Both belong in the alphabet audit a concurrent deliverable is running.

## Files

| file | contents |
| --- | --- |
| `scripts.mjs` | the 60 canonical scripts as data, each with rule, target letters, co-realized letters, Appendix E citation, component data, Λ_orch program, and any schedule note |
| `verdicts.mjs` | $V_{r,s}$ per script: the load-bearing clauses of the derivation, each carrying the sentence it convicts |
| `observe.mjs` | the script interpreter and the observation (word, certificate word, report, refusals, snapshots, external reads) |
| `dsl-ext.mjs` | the DSL extensions described above; re-exports `../../proof/src/dsl.mjs` unchanged |
| `run-tstar.mjs` | the runner: per-script pass/fail with realized letters, coverage against the 86, failures by rule and clause |
| `tstar.test.mjs` | `node:test` wrapper; also checks the suite's own structural obligations (60 scripts, 86 letters, no unrealizable claim, every waiver justified) |
