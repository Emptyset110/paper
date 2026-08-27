# T\* — the finite characteristic suite, executable

$T^\star = \{(\rho_{r,s}, V_{r,s})\}$, the **75** canonical experiments of
`../signatures.md` §§1.4–14.3 **as closed by `../alphabet-audit.md`**, expressed
so they run against real Cordis builds. Until now the suite existed only on
paper: the scripts were derived line by line in `../derivations.md`
(Appendix E) and in the audit's §3, and nothing executed them, so no build had
ever been checked against Theorem 2.

The audit (deliverable D5) found ten gaps in premise (D-A) and closed them
with 16 new occurrence letters — D7–D12, X10, V6, the new alphabet
$\Sigma_{\text{O-Update}} = \{W1..W6\}$, P7, A8 — and lifted A4 out of the
unrealizable column by adding Definition 2′'s environment read label. The
tables go **92 / 86 / 60 → 108 / 103 / 75**, and this suite grows with them,
additively: no existing script, letter or verdict changed.

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

# (a) the reference model — the executable specification. This must be 75/75:
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

| target | scripts | occurrence letters | (pre-closure) |
| --- | :-: | :-: | :-: |
| reference model (`adapter-model.mjs`) | **75 / 75** | 103 / 103 | 60/60, 86/86 |
| calculus-aligned build (`deepseek-harness/vendor/cordis`) | **59 / 75** | 86 / 103 | 50/60, 77/86 |
| published upstream `@deepseek-ai/cordis` 4.0.1 | **58 / 75** | 88 / 103 | 49/60, 79/86 |
| distributed (`cordis-node`, two nodes over the upstream build) | **58 / 75** | 83 / 103 | 49/60, 78/86 |

A script credits its target letter only when it passed *and* the target's
schedule took the canonical branch; a `branch` clause reported unrealized
leaves the letter untested on that run even though the script conformed. The
same now applies to a script's *co-realized* letters, which are the letters of
the same window: crediting them on any pass over-credited exactly the
schedule-dependent L-Divert scripts. On the distributed target, where no
L-Divert script takes its canonical branch, the old rule credited D4 to five
scripts none of which diverted (84/103); the corrected rule reports 83.

One script is **not presentable** on any certificate-erased target: S-Upd-4
(W5) has to place its input inside the L-Raise → L-Unload window, and no
ordinary event occurs there on any fair schedule. See F11.

Findings F1–F11 below explain every failure.

| | aligned | upstream | distributed |
| --- | :-: | :-: | :-: |
| F1 spurious deactivation of a never-activated fiber | 7 | 7 | 7 |
| F2 parent/child teardown order inverted | 1 | 1 | 1 |
| F3 orchestrator-inserted child disposed with its parent | 1 | 1 | 1 |
| F4 A4 resolved at the label level | 1 | — | — |
| F5 upstream's two premise violations | — | 2 | 2 |
| **F8 `update` at a Reloading fiber forces no re-resolution** | 1 | 1 | 1 |
| **F9 `update` is gated on context liveness, not on the registry** | 2 | 2 | 2 |
| **F10 the registry premise is unread by `setval` and by the read label** | 2 | 2 | 2 |
| **F11 W5 is not presentable (notation, not a defect)** | 1 | 1 | 1 |
| total not passed | 16 | 17 | 17 |

F6 (a canonical branch the pin does not select) and F7 (a defect in D1's own
S-Iso-3) are coverage/derivation findings and cost no script.

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
modified. Six kinds of addition were needed — four for the original 60, two
for the audit's closure.

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
   snapshots the report at `inv(C,b)`. The snapshot now carries the store as
   well as the states, because D8's observation is a binding that must be
   *live* at the pointed configuration and *withdrawn* at quiescence; the
   lenient probe is the meaningful one strictly inside a settle, since σ_γ
   unions Active tables only (which is B6's content). Watchers stack, so
   S-Div-5 arms the snapshot and the retirement on one marker, in that order.

5. **The anchored-input notation `at ε do λ` (`atEvent`, `cert`).** The audit's
   §3.5. Three of the new letters — D7, W4, W5 — are windows at *non-quiescent*
   configurations, which §5.4's `ρ ::= λ … | settle` notation cannot address
   while Definition 3 clause 1 makes them conformance-relevant all the same.
   `atEvent(ε, λ)` delivers λ synchronously at the first occurrence of ε during
   the next settle. **This is notation, not machinery**: it is the same one-shot
   `createTrace` watcher `pin` already used, and the two differ only in intent —
   a `pin` steers the schedule of a script whose printed ρ is quiescent-only,
   whereas an anchor *is* the printed ρ. Its correctness obligation is (D-F): ε
   must be produced on every fair schedule, argued per script in `anchorNote`
   and enforced by `tstar.test.mjs`; `observe.mjs` additionally records whether
   each anchor actually fired, and an undelivered anchor is reported as its own
   violation kind rather than as a mysterious word diff.

   ε ranges over the ordinary event vocabulary and, through `cert(r, n)`, over
   the rule-certificate channel. Two of the audit's three anchors are rendered
   in the ordinary vocabulary so the experiments stay presentable on real
   builds (S-Div-4 anchors on a `mark` step instead of `cert(L-Begin,P)`;
   S-Upd-3 on `inv(C,b)` instead of `cert(L-Leave,P)` — the same window in both
   cases). The third cannot be; see F11.

6. **The environment read label `read(n,k)` (`readLabel`).** The audit's §3.6,
   closing GAP-10 and with it the paper's §9 interface-scope limitation, by
   exactly one channel. It is Definition 2′'s seventh $\Lambda_{\mathrm{orch}}$
   label: Algorithm 6 run from $n$'s resolution context, $\Psi = \mathrm{id}$,
   premise $n \in \mathrm{dom} F_\gamma$ (occurrence A8), emitting the same
   `read:` / `readfail:` letters a read *step* emits. Again no new machinery:
   all three adapters already expose the proxy-mediated read as `readVia`; what
   was missing was its status as an *input*, with a refusal class of its own and
   a place in ρ. It is what makes A4 reachable (S-Acc-3) and it lets T\* drive
   the channel that kills `proxy-skips-inactive-check`.

Three further harness conventions, all stated rather than assumed:

- **The read label is delivered, not pre-checked.** The O-Retire convention
  below records the registry membership *instead of* attempting the input,
  because the adapters' `retire` swallows the attempt. The opposite choice is
  made for `update`, `setval` and `read`: the adapters do deliver those to the
  target, so the harness delivers them and records what came back. Synthesizing
  the refusal there would make W6, P7 and A8 vacuous — they exist precisely to
  test whether the target consults the premise, and all three convicted the
  reference semantics itself until `model.mjs` was repaired (audit §6).

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

### F8 — `update` at a Reloading fiber forces no re-resolution (both builds)

*Script:* S-Div-4 (D7, D9, D12, with W1).

This is the audit's GAP-1 tested, and the answer is that neither build
implements the window. `update(n,cfg)` delivered while $\theta_n =
\mathsf{Reloading}$ must, by D7, make the fiber's next iteration boundary
divergent: `model.mjs:242` tests the restart mark *before* it computes
`targetOf`, so `stale` is a third divergence trigger beside ⊥-target and
changed-provider. Observed:

```
spec: mark:P:m0 | deactivated:P | mark:P:m0 | apply:P:a | revert:P:a
      | deactivated:P | mark:P:m0 | apply:P:a | apply:P:b | active:P
impl: mark:P:m0 | apply:P:a | apply:P:b | active:P            (both builds)
```

— one episode where the specification has three. The two builds fail it
differently, and the difference is instructive:

- the **aligned** build writes the new entry (`fiber._config` becomes the new
  config) but the running episode keeps the old one and no restart occurs;
- **upstream** writes nothing at all. `update()` is invoked on the wrapper
  `ctx.plugin()` returns, which prototypes on the fiber, so `this._config = …`
  lands on the wrapper and never reaches the fiber. The aligned build's
  `const fiber = this.ctx.fiber` is exactly the repair for this.

Either way the input is *accepted* and then *dropped*, which is the one outcome
Definition 3 clause 1 excludes: an accepted orchestration label is part of the
bisimulation. W1's Active sub-case is honoured on both builds (S-Lea-3/V5
passes); it is the Reloading sub-case that is missing, so D7 and W1 are both
uncovered on every real target. **This is a new defect class**, and it is the
one the audit predicted: eight of its ten gaps were at `update` or at a rule
consuming `update`.

### F9 — `update` is gated on context liveness, not on registry membership (both builds)

*Scripts:* S-Upd-3 (W4), S-Upd-5 (W6).

Both builds' `update()` opens with `assertActive()`, which throws
`cannot create effect on inactive context`. That is not the premise the
calculus states, and the two experiments catch it from both sides:

- **W4 (S-Upd-3), the wrong refusal.** The specification accepts an update at
  an `Unloading` fiber and does nothing observable with it: "the update at an
  Unloading fiber perturbs no event, no certificate and no report field". Both
  builds **refuse** it. Everything else in the run agrees with the
  specification letter for letter — the entire divergence is
  `refusals: spec [] ≠ impl [{update, P, PARENT_ABSENT}]`. An input the
  specification enables and the implementation refuses is a §6.3 case (a)
  failure however inert the input is. On the **aligned** build that refusal is
  the *entire* divergence; on **upstream** and on the **distributed** target the
  same script also convicts F5 a second time, with
  `revert:P:a | revert:C:b` where the specification requires
  `revert:C:b | revert:P:a` — the provider's inverse running before its
  dependent's, i.e. `unload-without-guard` again, now witnessed from an
  `update` script rather than from S-Unl-2's.
- **W6 (S-Upd-5), the right refusal for the wrong reason.** Here the
  specification *does* refuse, and both builds refuse too — so they are ahead
  of the pre-repair reference semantics, which accepted the input and rewrote a
  removed record. But the reason is the effect-context reason, not
  "no such entry"; Definition 7 gives one $\mathsf{block}(\varrho)$ per premise
  schema and Definition 3 clause 1 compares them.

The two together show the refusal is incidental: the same check fires at an
`Unloading` fiber, which *is* in $\mathrm{dom}\,F_\gamma$, and at a removed
one, which is not. No build consults the registry.

### F10 — the registry premise is unread by `setval` and by the read label (both builds)

*Scripts:* S-Set-1 (P7), S-Acc-2 (A8).

The other two faces of GAP-7, and both were defects of `model.mjs` too until
the integration pass repaired them (audit §6 items 2 and 3), which is why these
two scripts are worth their place: they convicted the specification first.

- **P7.** `setval` at a removed name is refused for P4's reason ("no own
  binding"), because O-Remove has cleared the table and the $\mathcal A_k$
  precondition fails before any registry check.
- **A8.** The read label at a removed name is *served*: both builds run
  Algorithm 6 against the disposed fiber's context and answer
  `readfail:C:k1:INACTIVE_ACCESS`, where the specification refuses with
  "no such entry" and emits nothing. The distinction is not cosmetic — one
  reason says "not yet", the other "never again".

### F11 — W5 is presentable only in the certificate-instrumented vocabulary

*Script:* S-Upd-4, reported as **not presented** on all three real targets.

Its input has to land inside the window between L-Raise and L-Unload, and in
the reference semantics no *ordinary* event occurs there on any fair schedule:
the only rule that can delay L-Unload is the reliance guard, and no fiber can
hold a committed edge to a fiber that raised during its own Reloading, so the
window is entered and left with nothing observable in between. The audit's own
ρ therefore anchors on `cert(L-Raise, P)` — a channel §5.4's vocabulary proviso
says a real build does not have.

So §5.4's proviso, which the manuscript states for the *observing* half of an
experiment, turns out to bind the *driving* half as well: there are windows a
certificate-erased implementation cannot be placed in, whatever the alphabet
says about their reachability. This refines ambiguity A16 rather than
contradicting it — the audit's alternative bookkeeping (D7, W4, W5
"interface-unrealizable in the script language while real in the calculus")
turns out to be the right reading for **W5 alone**: D7 and W4 both have
ordinary-vocabulary anchors selecting the same window, and are presented and
convicting on every target. The paper should record W5 as reachable in the
calculus, presentable in the instrumented vocabulary, and *not presentable
against an uninstrumented implementation* — a fourth status, and the only
letter that has it.

## Coverage against the alphabet

`run-tstar.mjs` reports, per target, which of the **103** reachable occurrences
the passing scripts realize. On the reference model this is 103/103, which is
obligation **(D-C)** (CF5) checked rather than asserted; `tstar.test.mjs`
checks the same claim statically. On a real build the uncovered set is the
interesting output — it names the letters the build's own behaviour prevents
the suite from presenting:

| target | uncovered |
| --- | --- |
| aligned | A3, A8, D3, D7, D10, I3, M4, P2, P7, R3, R4, T7, W1, W4, W5, W6, X4 |
| upstream | A3, A8, D7, D10, I3, I7, M4, P7, R3, R4, T7, W1, W4, W5, W6 |
| distributed | A3, A8, D4, D7, D8, D9, D10, D11, D12, I3, I7, M4, P7, R3, R4, T7, W1, W4, W5, W6 |

Of the pre-closure set: `I3, M4, R3, R4` are uncovered only because their
scripts fail on F1 (the spurious deactivation); `A3, T7` are F3; `P2, X4` are
F4; `I7` is F5; `D3` (aligned) and `D4` (distributed) are F6.

Of the sixteen new letters, **nine are covered on every real target** —
D8, D9, D11, D12 (the L-Divert accumulator column), X10, V6, W2, W3, A4 — and
that is the closure's practical yield: the suite now exercises the per-item
inverse classes at the divert entry, the blocking L-Leave window, `update` at a
pending and at a failed fiber, and the external declared-inactive access, none
of which any earlier artifact could index. The seven that are not are exactly
the findings: `D7, W1` are F8; `W4, W6` are F9; `P7, A8` are F10; `W5` is F11.
`D10` is F6 again — with the pin in place both builds let the registered child
run to completion before the teardown reaches it (`registered:G:K |
apply:K:kk | … | deactivated:K`), so the canonical branch is not selected; the
report clauses pass and the script conforms. The distributed target loses
`D4, D8, D9, D11, D12` for the same reason its predecessor lost `D4`: its
schedule takes the non-diverting branch of every L-Divert script.

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
- ~~**C5.3 (declared-inactive access).**~~ **Closed.** This was Correction C5's
  external Def.-23 read realizing A4, which no canonical script could index
  because $\Lambda_{\mathrm{orch}}$ had no read label. The audit added the
  label (GAP-10) and A4 became reachable; **S-Acc-3** is that obligation,
  derived from the alphabet rather than borrowed, and it passes on all four
  targets. This is the one place where the closure lets T\* *subsume* an
  obligation of the older suite outright.

The first belongs in the alphabet audit's own open list: it is PB-2, and §5
of that document names the missing proof.

## Files

| file | contents |
| --- | --- |
| `scripts.mjs` | the 75 canonical scripts as data, each with rule, target letters, co-realized letters, derivation citation (Appendix E for the original 60, the audit's §3 for the 15 the closure adds), component data, Λ_orch program, and any schedule note or anchor argument |
| `verdicts.mjs` | $V_{r,s}$ per script: the load-bearing clauses of the derivation, each carrying the sentence it convicts |
| `observe.mjs` | the script interpreter and the observation (word, certificate word, report, refusals, snapshots, external reads) |
| `dsl-ext.mjs` | the DSL extensions described above; re-exports `../../proof/src/dsl.mjs` unchanged |
| `run-tstar.mjs` | the runner: per-script pass / fail / not-presented with realized letters, coverage against the 103, failures by rule and clause |
| `tstar.test.mjs` | `node:test` wrapper; also checks the suite's own structural obligations (75 scripts, 103 letters, no unrealizable claim, every schedule waiver justified, every anchor argued for (D-F)) |
