# D5 — Alphabet completeness audit and closure

Deliverable D5. **Question.** Theorem 2's load-bearing premise is (D-A) of
Definition 6: the per-rule alphabets $\Sigma_r$ "cover exactly the guard atoms
and write inputs of Table 1's row for $r$". If some distinction the interface
can make has no letter, then $f_r^{\mathbb I}$ has no entry that can be wrong
about it, no canonical experiment is indexed by it, and $T^\star$ certifies
less than the theorem says. This deliverable audits that premise
exhaustively, rule by rule and operation by operation, and closes every gap it
finds.

**Authority order** (as in `signatures.md`): [SZC26] Table 1 (`../paper.pdf`
p. 40) and the rule statements of §4.2–§4.3 (pp. 31–38) > the §5 realization
(Algorithm 6, p. 61; the component loader of §5.2.1, Def. 74, pp. 62–63) >
`../proof/src/model.mjs` > the bounded explorer's records
(`explorer/out/`). Where the calculus underdetermines the answer the point is
logged as an ambiguity (A11–A16), continuing `signatures.md` §17's numbering,
not silently resolved.

**Scope.** This file **adds** to `signatures.md` §§1–15; it changes no existing
letter, no existing reachability verdict, and no existing script. A later
integration pass merges §3 below into Appendix D. Nothing under `paper/proof/`
was modified; the reference semantics and the explorer were driven read-only,
and every executable check is reproducible from `scratch-audit/` (§7).

**Result in one line.** Ten genuine gaps, sixteen distinctions correctly
excluded as reference-implementation artifacts; **16 new occurrence letters**
(one new alphabet, $\Sigma_{\text{O-Update}}$) and **15 new canonical
scripts**, taking the tables from **92 / 86 / 60** to **108 / 103 / 75**, and
leaving no explorer signature unlettered.

---

## 0. Method

An occurrence letter is owed to a *distinction*: a pair of interface-reachable
windows of the same rule or operation that the specification treats
differently and that the observation vocabulary of Definition 1
(events, certificates, quiescent report, refusal reason) separates. The audit
derives the candidate distinctions three ways and takes the union, so that no
step of it depends on noticing something:

1. **From the row.** For each of Table 1's ten rows, enumerate the premises as
   the p. 41 (Lemma 55) premise inventory classifies them — a pattern match on
   $\theta_n$ or $\tau_n$; the component conditions of O-Insert; a condition
   mentioning $\mathrm{target}_n$ or $\mathrm{relied}_n$; a read of
   $\mathrm{dom}(F_\gamma)$ — and enumerate the *write inputs*, i.e. the
   constituents of the $\theta^{t+1}_n$ column and of $\Psi^t$. (D-A) owes a
   letter to each valuation class of each.
2. **From the operation.** For each of Definition 2's six $\Lambda_{\mathrm{orch}}$
   labels, enumerate its defining conditions: from Def. 23/24 (`setval`),
   Def. 29 (`isolate`), Def. 31 (`intercept`), Table 1 rows 1–2
   (`insert`, `retire`), and — since it has no rule at all — from §5.2.1's
   Def. 74 and Algorithm 7 (`update`).
3. **From the code paths.** Enumerate every branch of `model.mjs` that a
   non-mutant execution can take, and every field the explorer's instrumented
   twin records in a signature tuple. A recorded field with no letter is a
   *candidate* gap; it is a *genuine* gap only if the distinction survives the
   folds Appendix D justifies (CF2 normalization, per-key folds, existential
   witness folds, frame/order data) and is not mutant-only.

Every gap below is annotated **calculus-level** (the distinction is one the
specification makes, or one the interface of Definition 2 exposes and the
specification must therefore fix) or **artifact** (a branch or field of the
reference implementation that no premise and no write input reads).

---

## 1. The completeness audit

### 1.1 The six $\Lambda_{\mathrm{orch}}$ operations

`insert`, `retire`, `setval`, `isolate` and `intercept` each descend from a
rule or a definition of the calculus; `update` descends from neither, which is
where the density of gaps is.

#### insert(π, c, cfg) — O-Insert, Table 1 row 1

| distinction | derived from | covering letter |
| --- | --- | --- |
| $\pi = \mathsf{root}$ | premise (ii) | I1 |
| $\pi \in \mathrm{dom}(F_\gamma)$ | premise (ii) | I2 |
| $\pi \notin \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$ | premise (ii); `model.mjs:193` `INACTIVE_EFFECT` | I3 |
| $n \notin \mathrm{dom}(F_\gamma)$ | premise (i) | I4 |
| $n \in \mathrm{dom}(F_\gamma)$ | premise (i) | I5 (interface-unrealizable) |
| per key $k \in p$: no registered co-declarer | premise (iv); `model.mjs:200–207` | I6 |
| per key $k \in p$: a registered co-declarer | premise (iv) | I7 |
| $(d,p,e) \in \mathfrak C_\Gamma$ | premise (iii) | **none, correctly**: a static datum of the component language, not a runtime guard atom (`signatures.md` §1) |
| ambient realm table $\rho$ captured into the new fiber's context | `model.mjs:210` `ctx.child(null)`; Def. 29 | S1 / S2 / S3 (CO-Iso layer) |
| ambient interception table $\iota$ captured | `model.mjs:210`; Def. 31 | N1–N4 (CO-Int layer) |
| `cfg` bound to the entry | Def. 74 `config`; `model.mjs:210` | consumed downstream: T11 / X3 (`raiseUnless`), N3 (component-declared metadata) |
| $\pi$ present but retired | `model.mjs:193` tests `removed`, not `retired`; explorer field `parent:"retired"` | I2 — **artifact-fold, justified**: premise (ii) reads $\mathrm{dom}(F_\gamma)$, not $\tau_\pi$ |

**Verdict: complete.**

#### retire(n) — O-Retire, Table 1 row 2

| distinction | derived from | covering letter |
| --- | --- | --- |
| $n \in \mathrm{dom}(F_\gamma)$, $\theta_n = \mathsf{Inactive}(\bot)$ | premise + Def. 49 bookkeeping | R1 |
| $n \in \mathrm{dom}(F_\gamma)$, $\theta_n$ installed | premise + eq. 44 | R2 |
| $n \in \mathrm{dom}(F_\gamma)$, $\theta_n = \mathsf{Inactive}(\xi)$ | premise + eq. 44 | R3 |
| $n \notin \mathrm{dom}(F_\gamma)$ | premise | R4 |
| $\tau_n$ already $\top$ | explorer field `again` | **none, correctly**: $\tau$ is not read and the write is idempotent (`signatures.md` §2); Lemma 54(5) makes $\tau$ monotone |

**Verdict: complete.**

#### update(n, cfg) — no Table-1 rule (§5.2.1, Def. 74)

`update` is the operation the interface exposes and the calculus does not
model. `signatures.md` §17's A3 records that fact and letters *one* of its
consequences (V5, the forced divergence at an Active fiber). The operation
itself is unlettered, and it makes six decisions, all of them reachable and
five of them machine-witnessed.

| distinction | derived from | covering letter |
| --- | --- | --- |
| $n \in \mathrm{dom}(F_\gamma)$, $\mathrm{installed}_n$, $\theta_n \in \{\mathsf{Reloading}, \mathsf{Active}\}$: entry rewritten, episode marked for restart | `model.mjs:550–557`; explorer `O-Update fired {installed:true, outcome:"bot", stateClass:"active"/"loading"}` | **GAP-3 → W1** |
| $n \in \mathrm{dom}(F_\gamma)$, $\neg\mathrm{installed}_n$, $\zeta_n = \bot$: entry rewritten, no episode to disturb | `model.mjs:551–553`; explorer `{installed:false, outcome:"bot", stateClass:"pending"}` | **GAP-3 → W2** |
| $n \in \mathrm{dom}(F_\gamma)$, $\neg\mathrm{installed}_n$, $\zeta_n = \xi$: entry rewritten **and the failure latch cleared** | `model.mjs:552` `fiber.outcome = null`; explorer `{installed:false, outcome:"xi", stateClass:"failed"}` | **GAP-4 → W3** |
| $\mathrm{installed}_n$, $\theta_n = \mathsf{Unloading}$, $\zeta = \bot$: the restart mark falls on a fiber already leaving | `model.mjs:553`; explorer `{installed:true, outcome:"bot", stateClass:"unloading"}` | **GAP-5 → W4** |
| $\mathrm{installed}_n$, $\theta_n = \mathsf{Unloading}$, $\zeta = \xi$: the outcome is cleared **before L-Unload reads it** | `model.mjs:552–553`; explorer `{installed:true, outcome:"xi", stateClass:"unloading"}` | **GAP-6 → W5** |
| $n \notin \mathrm{dom}(F_\gamma)$ | parity with O-Retire's premise; `model.mjs:550` consults no premise | **GAP-7 → W6** |
| the *consequence* at $\theta_n = \mathsf{Active}$ | forced divergence | V5 |
| the *consequence* at $\theta_n = \mathsf{Reloading}$ | forced divergence at an iteration boundary; explorer `L-Divert fired {trigger:"stale", …}` (6 signatures) | **GAP-1 → D7** |
| `cfg` $\simeq$ the entry's previous `config` (immaterial update) | §5.2.1: "reloading only on a material change" | **none, correctly**: the diff is performed inside the component's `apply`, not by the orchestration input; it is a component-language decision, not a decision of $\Lambda_{\mathrm{orch}}$ |
| Def. 74's other fields (`id`, `url`, `isolate`, `intercept`, `disabled`) | §5.2.1 dispatch table, p. 63 | outside `update(n,cfg)`; logged as ambiguities **A12–A14** |

#### setval(n, k, v) — Def. 24, an $\mathcal A_k$ operation

| distinction | derived from | covering letter |
| --- | --- | --- |
| own binding at $\rho(k)$ present: value replaced in place | Def. 24; `model.mjs:529–535` | P3 |
| no own binding: error | Def. 24 precondition; `model.mjs:532` | P4 |
| $n \notin \mathrm{dom}(F_\gamma)$ | parity with R4; `model.mjs:529` consults no registry premise | **GAP-7 → P7** |
| $\theta_n$ at the overwrite | explorer field `stateClass` (5 values) | **none, correctly**: Def. 24 reads the binding at $k$ and nothing else — **artifact-fold** |
| $v \simeq_k$ the standing value | explorer field `valueEq` | **none, correctly**: no premise of any row inspects a value (Lemma 2, *Values*) — **artifact-fold** |
| the state classes of installed fibers whose committed view names $n$ at $k$ | explorer field `dependents` (7 values) | **none, correctly**: an existential the witness fold collapses; §7 of the manuscript already reports this fibre as 30 of the 35 value-operation tuples — **artifact-fold** |
| whether dependents re-run | PB-2 / A3 | carried inside P3's decision (episode-invisible, the model's resolution) |

#### isolate(k, r) — Def. 29

| distinction | derived from | covering letter |
| --- | --- | --- |
| $k \notin \mathrm{dom}(\rho)$ (shared realm) | Def. 28 default $\rho(k)=k$ | S1 |
| accessor's $\rho(k)$ differs from the would-be provider's | Def. 29 transport | S2 |
| two keys or contexts share one realm label | Def. 29 | S3 |
| $k \in \mathrm{dom}(\rho)$ already: reassignment, not refusal | Def. 29 ("no precondition") | S4 |
| $r$ omitted: a fresh realm label is drawn | `model.mjs:65–69` `realm#N` | S2 — the drawn label is distinct by construction; CF2 normalizes it away |
| no precondition ⇒ no refusal class | Def. 29 | **none needed** |
| retargeting a *live* entry (Algorithm 7, delimiters $\delta_k$) | §5.2.1, p. 63 | outside $\Lambda_{\mathrm{orch}}$'s context-deriving `isolate`; ambiguity **A13** |

**Verdict: complete for the Def.-29 operation.**

#### intercept(k, ν) — Def. 31

| distinction | derived from | covering letter |
| --- | --- | --- |
| no metadata on either side | Def. 31 | N1 |
| context-only | Def. 31 | N2 |
| component ⊕ context (right-biased) | Def. 31; `model.mjs:560–572` | N3 |
| context₁ ⊕ context₂ (nearer wins) | Def. 31; `interceptMerged` | N4 |
| overlapping vs. disjoint merged fields | Def. 31 $\oplus_k$ | inside N3/N4's order pattern (`signatures.md` §13.1) |
| chains deeper than 2 | associativity of $\oplus_k$ | capped, with the argument at §13.1 |
| retargeting a live entry (in place, no reload) | §5.2.1, p. 63 | ambiguity **A14** |

**Verdict: complete for the Def.-31 operation.**

#### read — absent

$\Lambda_{\mathrm{orch}}$ carries no environment-initiated read. **GAP-10**;
see §3.6.

### 1.2 The ten rules

Read premise-by-premise and write-input-by-write-input against Table 1 (p. 40)
and the rule statements of pp. 34–38.

| rule | distinction | covering letter |
| --- | --- | --- |
| **O-Insert** | (§1.1 above) | complete |
| **O-Retire** | (§1.1 above) | complete |
| **O-Remove** | $\tau_n = \top$ / $\tau_n = \bot$ | M1 / M2 |
| | $\theta_n = \mathsf{Inactive}(\bot)$ / $\mathsf{Inactive}(\xi)$ / installed | M3 / M4 / M5 |
| | $\forall m.\ \pi_m \neq n$: witness absent / present | M6 / M7 |
| | write $\gamma \setminus n$ (registry entry removed, table cleared) | the scalar occurrence's update constructor |
| | *no agent in $\Lambda_{\mathrm{orch}}$* | ambiguity A1 (already logged) — the alphabet is unchanged either way |
| | **complete** | |
| **L-Begin** | $\theta_n = \mathsf{Inactive}(\bot)$ / $\mathsf{Inactive}(\xi)$ | B1 / B2 |
| | $\tau_n = \bot$ / $\top$ (through $\mathrm{target}_n \neq \bot$) | B3 / B4 |
| | per key: Active-provided / installed-only / unprovided | B5 / B6 / B7 |
| | installed state classes (no L-Begin window exists) | none, correctly (Dev-4) |
| | write $\mathsf{Reloading}(e_n, \mathrm{id}_\Gamma, \omega)$: inputs $e_n$ (static), $\mathrm{id}_\Gamma$ (constant), $\omega$ (per-key, B5) | complete |
| | `everUnsatisfied` (`model.mjs:231,232`) | **artifact**: read only by the mutant `refresh-misses-pending`; not an abstract field |
| | **complete** | |
| **L-Iter** | $\theta_n = \mathsf{Reloading}$, view scalar | T1 |
| | per key: $\omega(k) = \mathrm{provider}_k(\gamma)$ | T2 |
| | step constructor, Right + Just classes (9 of StepClass's 15) | T3–T11 |
| | write $\mathsf{Reloading}(i', g \circ h, \omega)$: $h$'s inverse class is fixed by the step letter; $g$ is carried and not applied | complete (see §2, GAP-2's boundary) |
| | `trackMutate` step class | **artifact**: used by no obligation and by no explorer catalog shape; a grammar extension beyond even A7's `trackReadOnRevert` |
| | `trace`/`mark` step class | **artifact**: a pure observation marker; no state effect, no premise |
| | `read … strict` step class | **none needed**: the A6 read-failure convention; adopting the strict reading *moves* T7/T8 into L-Raise, it does not add letters |
| | `setval-own-eq` / `setval-own-neq` | **artifact-fold**: no premise reads a value (Lemma 2) |
| | **complete** | |
| **L-Finish** | $\theta_n = \mathsf{Reloading}$, first application yields Nothing / later one does | F2 / F1 (post-C4) |
| | per key: view equal at the finishing window | F3 |
| | write $\mathsf{Active}(g \circ h, \omega)$: at exhaustion $h = \mathrm{id}_\Gamma$, so the composition introduces no new item | complete |
| | **complete** | |
| **L-Divert** | $\theta_n = \mathsf{Reloading}$, divergence present | D1 |
| | per key: changed provider | D2 (interface-unrealizable, A10) |
| | $\mathrm{target} = \bot$ by retirement / by unsatisfiability | D3 / D4 |
| | $\mathrm{target}$ forced stale by `update(n,cfg)` | **GAP-1 → D7** |
| | alternative abort / land | D5 / D6 (D6 unrealizable, A9) |
| | write $\mathsf{Unloading}(g \circ h, \omega, \bot)$: **$g$ is a write input and the rule commits it to be applied**, but its items are unlettered — while L-Raise, whose write $\mathsf{Unloading}(g,\omega,\xi)$ carries $g$ in exactly the same way, letters them X6–X9 | **GAP-2 → D8–D12** |
| **L-Raise** | $\theta_n = \mathsf{Reloading}$, $i(\gamma) = \mathsf{Left}(\xi)$ | X1 |
| | step constructor, Left-producing classes (4 of 15) | X2–X5 |
| | write $\mathsf{Unloading}(g, \omega, \xi)$, per-item InvClass of $g$: (empty), provide⁻¹, track⁻¹, register⁻¹ | X6–X9 |
| | per-item InvClass = read-on-revert (the 5th value of InvClass) | **GAP-9 → X10** |
| | $\xi$'s identity | none, correctly: $\Xi$ is a value sort, normalized by CF2 |
| | no view premise (the L-Divert overlap) | ambiguity A2 — a nondeterminism, not an alphabet fact |
| **L-Leave** | $\theta_n = \mathsf{Active}$, divergence present | V1 |
| | per key: changed provider | V2 (unrealizable, A10) |
| | $\mathrm{target} = \bot$ by retirement / unsatisfiability | V3 / V4 |
| | forced by `update(n,cfg)` | V5 |
| | $\theta_n = \mathsf{Active}$, **no divergence** — the rule is not applicable; a reachable window with a distinct (blocking) decision, which O-Remove (M2, M5, M7), L-Begin (B2, B4, B6, B7) and L-Unload (U2) all letter | **GAP-8 → V6** |
| | write $\mathsf{Unloading}(g,\omega,\bot)$, per-item InvClass of $g$ | **none needed** — see §2, GAP-2: every canonical script of U5–U9 already enters `Unloading` through L-Leave, so the (entry-path × inverse-class) column is covered |
| **L-Unload** | $\theta_n = \mathsf{Unloading}$, guard clear | U1 |
| | per-witness: an installed $m$ with $\omega_m(k) = n$ | U2 |
| | $\zeta = \bot$ / $\zeta = \xi$ | U3 / U4 |
| | per-item InvClass: provide⁻¹, track⁻¹, register⁻¹, read-on-revert, (empty) — all 5 values of InvClass | U5–U9 |
| | bookkeeping ($\zeta = \bot$ only): $\tau = \top$ / $\tau=\bot \wedge$ post-⊥ / $\tau=\bot \wedge$ satisfiable | U10–U12 |
| | the witness's own state class | **artifact-fold**: Def. 50 reads $\mathrm{installed}_m$ only; the state class is read by the mutant `guard-only-direct` alone |
| | the inverse *order* pattern (`obs`) | **none, correctly**: order is frame data consumed by $\mathrm{lift}$, not a letter (Remark 1; §10.2) |
| | **complete** | |
| **Alg. 6** | hit at self / at an ancestor | A1 / A2 |
| | IA at an ancestor / at self | A3 / A4 (A4 in-lifecycle-unrealizable, C5) |
| | UD at the root boundary / at an isolation boundary | A5 / A6 |
| | IA on a withdrawn binding | A7 (spec-unreachable, Thm. 63) |
| | walk started at a name not in $\mathrm{dom}(F_\gamma)$ | **GAP-7 → A8** |
| | environment-initiated invocation | **GAP-10 → the read label** |
| | whether a provider exists for the key on a failing path (explorer's `-p`/`-np`) | **artifact-fold**: Algorithm 6 never consults $\sigma_\gamma$ on lines 5–6 |

---

## 2. The gap list

Ten genuine gaps; sixteen candidate distinctions excluded as artifacts.

### 2.1 Genuine (calculus- or interface-level)

**GAP-1 — L-Divert has no letter for the orchestrator-forced restart.**
*Distinction.* A Reloading fiber whose divergence is not a target change but an
entry update. *Evidence.* Six explorer signatures,
`L-Divert fired {trigger:"stale", acc:…}` for
`acc ∈ {[], [provide], [track], [retire], [rrev], [provide,track]}`
(`explorer/out/reconcile.json`, fibre `L-Divert fired {D1,D5,V5@divert*}`); the
projection $\alpha$ has to invent the placeholder letter `V5@divert*` for them
(`explorer/reconcile.mjs:118`), and the manuscript §7 lists them as "6 explorer
signatures with no Appendix D letter at all". *Code path.*
`model.mjs:242–243` — the Reloading branch tests `fiber.stale` **before** it
computes `targetOf`, so `stale` is a third, independent divergence trigger
alongside $\bot$-target and changed-provider. *Status.* **Calculus-level at the
interface**: `update` is a label of Definition 2's LTS, and Dev-7 already
accepts the same distinction as a letter at L-Leave (V5). Its absence at
L-Divert is an omission, not a decision — `signatures.md` §9.3 letters V5 and
§7.3 does not mention `update` at all.

**GAP-2 — L-Divert has no per-item accumulator letters.**
*Distinction.* Which inverse classes stand in $g$ when the divert commits the
fiber to `Unloading`. *Evidence.* The explorer records `acc` at L-Divert with
five distinct class-sets over both triggers (12 tuples), and $\alpha$ discards
the field with the comment "f.acc has no L-Divert letter in D1"
(`reconcile.mjs:120`). *Derivation.* By (D-A), $g$ is a write input of the
L-Divert row ($\theta^{t+1}_n = \mathsf{Unloading}(g \circ h, \omega, \bot)$),
exactly as it is of the L-Raise row ($\mathsf{Unloading}(g,\omega,\xi)$) where
Appendix D does letter it (X6–X9, Dev-8). *Why the letters are owed here and
not at L-Iter, L-Finish or L-Leave.* Per-item letters at a rule that merely
*carries* $g$ are bookkeeping letters in Appendix D's own explicit sense
(R1–R3, U10–U12: "write-aspect bookkeeping recorded because the canonical
verdict observes the successor"). They earn their place when they force one
canonical experiment per *(entry path into `Unloading`) × (inverse class)*, a
column L-Unload's own letters cannot force because U5–U9 do not record how the
fiber entered `Unloading`. Checking the existing scripts: every one of
§10.4's U5–U9 scripts (S-Unl-1, S-Unl-4, S-Unl-5, S-Unl-6, S-Unl-7) enters
through **L-Leave**, so L-Leave's column is covered and needs no letters; §8.4's
S-Rai-5/6/7 cover **L-Raise**'s column, which is what X6–X9 exist for; and
**L-Divert**'s column is covered by exactly one script, S-Div-1, with
$g = \mathrm{track}^{-1}$ alone. L-Iter and L-Finish do not commit the
accumulator to be applied and are excluded on that ground. *That the column is
not idle:* run `divert-skips-recovery` against a divert holding a
register-inverse and the registered child **survives its parent's aborted
episode as an orphan** (`scratch-audit/ev-read-acc.mjs`: baseline
`Q:disposed G:pending K:disposed`, mutant `… K:active`). *Status.*
**Calculus-level**, with one alternative repair recorded as ambiguity **A11**.

**GAP-3 — `update` has no alphabet; its principal decision (whether an episode
is disturbed at all) is unlettered.** *Distinction.*
$\mathrm{installed}_n$ vs. not. *Evidence.* `model.mjs:553`
`if (fiber.installed)`; explorer `O-Update` tuples with `installed:true` and
`installed:false`; $\alpha$ collapses **all six** `O-Update` tuples onto the
single letter V5 (`reconcile.mjs:79`), and `reconcile.mjs:219` records
Appendix D's alphabet for the rule as `['—','—']`. *Executed contrast*
(`scratch-audit/ev-update.mjs`): `update` on an Active fiber produces the full
bounce `leave, revert, deactivated, begin, apply, active`; `update` on a
pending fiber produces the empty trace. *Status.* **Interface-level, genuine.**
Definition 3 clause 1 makes every accepted orchestration input part of the
bisimulation, so an input whose decisions have no letters is an input on which
$T^\star$ tests nothing.

**GAP-4 — `update` clears the failure latch, and no letter records it.**
*Distinction.* `update` at $\theta_n = \mathsf{Inactive}(\xi)$ sets
$\zeta_n \mapsto \bot$, which lifts B2's block and lets the lifecycle be
re-entered from an error outcome — the very thing p. 38 says the calculus
forbids ("L-Begin has $\mathsf{Inactive}(\bot)$ as a premise, so the lifecycle
is not re-entered from an error outcome"). *Evidence.* `model.mjs:552`
`fiber.outcome = null`, unconditional, executed before the `installed` test.
*Executed contrast* (`scratch-audit/verify-scripts.mjs`, S-Upd-2): a component
`[track(a), raise(x)]` inserted and settled quiesces `failed`; after
`update(P, cfg2); settle` the trace is
`begin, apply, raise, revert, deactivated, begin, apply, raise, revert, deactivated`
— **a second complete episode**, with a second `raise`. *Status.*
**Interface-level, genuine, and the most consequential of the ten**: it is the
one input that reverses the outcome latch B2 exists to enforce, and it is
adjacent to the fourth upstream divergence the manuscript §8.2 reports
("after a failed first activation, a later `update()` … releases the *first*
episode's error").

**GAP-5 — `update` at an `Unloading` fiber.** *Distinction.* The restart mark
falls on a fiber whose teardown is already committed; no rule of Table 1 reads
it there. *Evidence.* Explorer
`O-Update fired {installed:true, outcome:"bot", stateClass:"unloading"}`;
`model.mjs:281–310` (the `unloading` branch never consults `stale`, and
L-Unload does not clear it). *Executed* (S-Upd-3): after the settle the fiber
is `disposed` with `stale === true` still set. *Status.* The **window class is
genuine and reachable**; the reference semantics' particular resolution — a
residual mark that survives L-Unload and fires a spurious L-Divert in the
*next* episode — is an **artifact** (a missing latch clear) and must not be
written into W4's decision entry. Logged as ambiguity **A15**.

**GAP-6 — `update` at an `Unloading` fiber carrying $\xi$ rewrites the field
L-Unload's row reads.** *Distinction.* $\zeta$ is cleared between L-Raise and
L-Unload, so the unload window's OutClass flips U4 $\to$ U3 and, by correction
C2, the bookkeeping block U10–U12 becomes live where it was suppressed.
*Evidence.* Explorer
`O-Update fired {installed:true, outcome:"xi", stateClass:"unloading"}`;
`model.mjs:552` runs before any state test. *Executed* (S-Upd-4): a component
`[provide(k1,v1), raise(x)]` with `update` anchored at the raise yields
`begin, provide, raise, deactivated, begin, divert, deactivated, begin, provide, raise, deactivated`
— **three episodes from one input**, versus the four-event baseline. *Status.*
**Interface-level, genuine.** This is the only $\Lambda_{\mathrm{orch}}$ input
that writes a $\theta$ constituent of a mid-transition fiber, and Lemma 54
(2)–(5) does not admit it: $\zeta$ is written by L-Raise and read by L-Unload
and by nothing else.

**GAP-7 — Only two of the five name-taking $\Lambda_{\mathrm{orch}}$ inputs
have a letter for $n \notin \mathrm{dom}(F_\gamma)$.** *Distinction.* The
refusal reason "no such entry", which Definition 7 requires to be one
$\mathsf{block}(\varrho)$ per premise schema and Definition 3 clause 1 requires
to be matched *with the same reason*. `insert` has I3 (absent parent) and
`retire` has R4; `update`, `setval` and the read of §3.6 have none.
*Evidence.* `model.mjs:550` (`update`) and `model.mjs:529` (`setOwn`) consult
no registry premise; `readCommitted` (`model.mjs:480`) does not either.
*Executed* (`verify-scripts.mjs`): after `insert(root,P); settle; retire(P);
settle`, `update(P, cfg2)` is **accepted** and silently rewrites a removed
record (`removed=true`, `outcome=null`); `setval(P,k1,v2)` is refused but with
P4's reason ("no own binding") rather than "no such entry", because O-Remove
happened to clear the table; and `read(C,k1)` at a disposed `C` is served by
the stale record's `spec.inject` and throws `INACTIVE_ACCESS`. *Status.*
**Interface-level, genuine.** The reference semantics' acceptance of
`update` at a removed name is a **found defect**, reported in §6 and not fixed
here.

**GAP-8 — L-Leave has no letter for its blocking (stable-view) window.**
*Distinction.* $\theta_n = \mathsf{Active}(g,\omega)$ with
$\mathrm{target}_n(\gamma) = \omega$: the rule is not applicable, and this is
a distinct decision on a reachable window — every quiescent state with an
Active fiber realizes it (eq. 45's second clause is exactly this condition).
*Evidence.* Explorer `L-Leave disabled {trigger:"view-stable"}`, for which
$\alpha$ invents a second placeholder, `V1-disabled*`
(`reconcile.mjs:125`); `model.mjs:273–274`. *Derivation.* Appendix D letters
the blocking valuations of every other row that has a reachable one — M2, M5,
M7 at O-Remove; B2, B4, B6, B7 at L-Begin; U2 at L-Unload — and Definition 8
clause 1 needs a scalar occurrence whose required atoms *fail* in order to
produce the block. L-Divert needs no counterpart because its complementary
valuation ($\mathsf{Reloading}$ with a stable view) is lettered by T1 and F1/F2
at the rules that fire there instead; at `Active` no other rule fires.
*Status.* **Calculus-level, genuine.**

**GAP-9 — L-Raise's InvClass letters cover four of InvClass's five values.**
*Distinction.* An accumulator holding a read-on-revert inverse at a raise.
InvClass = {provide⁻¹, track⁻¹, register⁻¹, read-on-revert, (empty)} is fixed
at `signatures.md` §0 with five elements; L-Unload letters all five (U5–U9);
L-Raise letters four (X6–X9). *Evidence.* $\alpha$ conflates the class onto
track⁻¹ — `const am = { provide: 'X7', track: 'X8', rrev: 'X8', retire: 'X9' }`
(`reconcile.mjs:93`). *Executed* (S-Rai-8): `read(k1); trackReadOnRevert(k1,a);
raise(x)` yields `… apply:C:a, raise:C, revertread:C:k1="v1", deactivated:C` —
the committed read runs *inside the failure recovery*, which is Thm. 63's
content at the raise entry. *Status.* **Genuine, at exactly U8's epistemic
grade**: real in the calculus (Def. 48 clause 2), inexpressible in §2.2's
printed step grammar (ambiguity A7), realized by `model.mjs`'s
`trackReadOnRevert`.

**GAP-10 — $\Lambda_{\mathrm{orch}}$ carries no environment-initiated read.**
Established, not suspected: it is stated in the manuscript's own §9 and
Definition 2 fixes the six labels. Its consequences are (i) A4 is unreachable
in the formalism though both grounding suites realize it (C5), and (ii) the
deviant `proxy-skips-inactive-check` is killed by exactly one test in either
artifact, and that test uses the missing channel. *Status.* **Interface-level,
genuine**; closed in §3.6.

### 2.2 Excluded as artifacts (sixteen)

Each is a branch or recorded field of the reference implementation that no
premise and no write input of Table 1 reads, or that a fold Appendix D
justifies removes.

| # | candidate | why excluded |
| --- | --- | --- |
| 1 | `fiber.everUnsatisfied` | read only by the mutant `refresh-misses-pending`; not an abstract field, so CF1 forbids an implementation to carry it into a decision |
| 2 | `trackMutate` step class | used by no obligation of the 32-suite and by no explorer catalog shape; a grammar extension beyond even A7's |
| 3 | `trace`/`mark` step class | pure observation marker; changes no field, satisfies no premise |
| 4 | `read … strict` step class | the A6 convention: adopting it *moves* T7/T8 into $\Sigma_{\text{L-Raise}}$, it adds no letter |
| 5 | `setval-own-eq` / `-neq` (value equality) | no premise of any row inspects a value (Lemma 2, *Values*); CF2 |
| 6 | A-Set `dependents` state-class multiset | an existential domain the witness fold collapses; 30 of the 35 value-operation tuples |
| 7 | A-Set `stateClass` of the provider | Def. 24 reads the binding at $k$ and nothing else |
| 8 | O-Retire `again` bit | $\tau$ is not read; the write is idempotent; Lemma 54(5) |
| 9 | O-Insert `parent:"retired"` vs `"live"` | premise (ii) reads $\mathrm{dom}(F_\gamma)$, not $\tau_\pi$ |
| 10 | the reliance witness's state class at L-Unload | Def. 50 reads $\mathrm{installed}_m$; the refinement is the mutant `guard-only-direct` |
| 11 | L-Unload `obs` (inverse order pattern) | order is the frame's data, consumed by $\mathrm{lift}$ (Remark 1) |
| 12 | Algorithm-6 `-p`/`-np` (provider exists on a failing path) | lines 5–6 never consult $\sigma_\gamma$ |
| 13 | residual `stale` surviving L-Unload | a missing latch clear in `model.mjs`, not a decision of any rule; the *window* is genuine (W4), the *behaviour* is not specified — ambiguity A15 |
| 14 | Def. 74 `disabled` cleared (un-retirement) | would write $\tau \mapsto \bot$, which Lemma 54(5) forbids; a §5.2.1 feature outside $\Lambda_{\mathrm{orch}}$ — ambiguity A12 |
| 15 | Def. 74 `isolate` retargeting a live entry (Alg. 7) | a different operation from Def. 29's context-deriving `isolate` — ambiguity A13 |
| 16 | Def. 74 `intercept` updated in place on a live entry | likewise, against Def. 31's context derivation — ambiguity A14 |

Items 14–16 are the honest borderline: they are *not* implementation noise —
they are operations [SZC26] §5.2.1 really specifies — but they are operations
$\Lambda_{\mathrm{orch}}$ as fixed by Definition 2 does not contain, and
lettering them would be lettering a different interface. They are recorded as
ambiguities so that the decision is visible rather than absorbed.

---

## 3. The closure

Format follows `signatures.md` §§1–14 exactly, so that these sections can be
spliced into Appendix D. Atom domains extend `signatures.md` §0's table by two
rows:

| domain | elements |
| --- | --- |
| `UpdClass` | installed-episode, pending-entry, failed-entry, unloading-clean, unloading-failed, absent-entry |
| `ViewRel` (extended) | key-equal, key-changed-provider, target-⊥-retired, target-⊥-unsatisfied, orch-update, **view-stable** |

`InvClass` is unchanged (its fifth element, read-on-revert, was already there
and merely unused at L-Raise). `UpdClass` has 6 elements and `ViewRel` now 6;
both are finite by inspection, so every finiteness proof below is again a
product count over §0's domains.

### 3.1 L-Divert — six new letters

#### 3.1.1 Alphabet $\Sigma_{\text{L-Divert}}$ (additions to §7.1)

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 7 | D7 | ViewRel = orch-update (`update(n,cfg)` forces re-resolution while $\theta_n = \mathsf{Reloading}$; **extension**, A3) | scalar |
| 8 | D8 | per-item: InvClass = provide⁻¹ present in $g$ at the divert | per-item witness |
| 9 | D9 | per-item: InvClass = track⁻¹ present in $g$ | per-item witness |
| 10 | D10 | per-item: InvClass = register⁻¹ present in $g$ (its application performs O-Retire of the child) | per-item witness |
| 11 | D11 | per-item: InvClass = read-on-revert present in $g$ (Def. 48 clause 2; A7 grammar extension) | per-item witness |
| 12 | D12 | InvClass = (empty) — accumulator $\mathrm{id}_\Gamma$ at the divert (the degenerate $\mathfrak E_\Gamma$ case of p. 36 among them) | scalar |

$\kappa_{\text{L-Divert}}$ of a window is now: one StateClass occurrence (D1),
one ViewRel occurrence (one of D2/D3/D4/D7, per witnessing key where the class
is per-key), one alternative occurrence (D5 or D6), and one InvClass occurrence
per accumulator item — or the single marker D12 when $g = \mathrm{id}_\Gamma$.

#### 3.1.2 Finiteness

1 (StateClass) + 4 (the ViewRel classes L-Divert can present) + 2
(alternative) + 4 (InvClass values reachable in an accumulator) + 1 (empty
marker) = **12**. Accumulator length is invisible: each item contributes one
occurrence of its class, and the alphabet holds one letter per class — the
same argument as §8.2 and §10.2. $\blacksquare$

#### 3.1.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| D7 | yes in the LTS; **requires the anchored-input notation** of §3.5 | `update(n,cfg)` must arrive while $n$ is `Reloading`, which no configuration between two settles is. Definition 2's LTS admits the input at every state and Definition 3 clause 1 quantifies over every reachable related pair, so the occurrence is genuinely reachable *for conformance*; it is only §5.4's script notation that cannot place the input. Machine-witnessed: six explorer signatures. Script S-Div-4. |
| D8 | yes | a consumer that has provided a key before the divergence reaches it. S-Div-5. |
| D9 | yes | a consumer that has tracked before the divergence. S-Div-1 (already), S-Div-5. |
| D10 | yes | a host that has registered a child before the divergence. S-Div-6. |
| D11 | yes | a consumer holding a read-on-revert inverse; modulo the A7 grammar extension, exactly U8's status. S-Div-7. |
| D12 | yes | the divergence reaches the fiber at its first iteration boundary. S-Div-8. |

All six machine-witnessed in the explorer's reachable set (12 L-Divert tuples,
which after the extended $\alpha$ project **bijectively** onto 12 letter-sets;
`scratch-audit/reconcile-postclosure.json`). D2 and D6 remain
interface-unrealizable, unchanged. **10 of 12 reachable.**

#### 3.1.4 Canonical scripts

**S-Div-4** (realizes D1, D5, D7, D9):
`P := (∅, ∅, [track(a), track(b), track(c)])`
ρ = `insert(root, P); at app(P,a) do update(P, cfg2); settle`.
*Derivation:* the settle runs L-Begin (window {B1, B3}) and one L-Iter
(T4, emitting app(P,a)). The anchored input fires at that event, rewriting P's
entry and marking the episode stale. P's next window is
{D1, D7, D5, D9(track⁻¹)}: $\theta_P = \mathsf{Reloading}$, the target is
neither $\omega$ nor a target at all but the forced-restart marker, and the
alternative is the abort. L-Divert routes P through `Unloading(track⁻¹, ω, ⊥)`;
L-Unload emits inv(P,a) then deact(P); the fiber is Inactive(⊥) with a
satisfiable target (U12) and immediately re-begins on the *new* entry, running
all three steps. Verified against the reference semantics
(`scratch-audit/verify-scripts.mjs`): trace
`begin, apply:a, divert, revert:a, deactivated, begin, apply:a, apply:b, apply:c, active`.
The attempt point is schedule-invariant (P is the only fiber), discharging
obligation (D-F).

**S-Div-4b** (realizes D1, D5, D7, D12) — the empty-prefix variant, kept
because it separates D12 from D9 under the orch-update trigger:
`P := (∅, ∅, [track(a), track(b)])`
ρ = `insert(root, P); at cert(L-Begin, P) do update(P, cfg2); settle`.
*Derivation:* the update lands before any step has, so the divert window is
{D1, D7, D5, D12} with $g = \mathrm{id}_\Gamma$; observed as `begin, divert,
deactivated, begin, apply:a, apply:b, active` — a deactivation with **no**
`inv` event between the two `begin`s, which is what distinguishes D12 from
D8–D11. Verified.

**S-Div-5** (realizes D1, D4, D5, D8, D9):
`Q := (∅, {k2}, [provide(k2,v2)])`,
`C := ({k2}, {k1}, [provide(k1,v1), track(a), track(b)])`
ρ = `insert(root, Q); settle; insert(root, C); retire(Q); settle`.
*Derivation:* the mechanism is S-Div-1's — at the second settle both C's
L-Begin and Q's L-Leave are enabled, and the occurrence lies on the branch
that begins C first. On that branch C commits $\omega_C(k_2) = Q$, lands
`provide(k1,v1)` (T3, pushing provide⁻¹) and `track(a)` (T4, pushing track⁻¹);
Q then leaves, so $k_2 \notin \mathrm{dom}(\sigma_\gamma)$ and C's next window
is {D1, D4(k2), D5, D8(provide⁻¹), D9(track⁻¹)}. L-Divert carries
$g = \mathrm{track}^{-1} \circ \mathrm{provide}^{-1}$ into `Unloading`;
L-Unload applies it LIFO — inv(C,a) precedes the withdrawal of k1 — and the
quiescent report shows k1 **absent**, which is the observation D8 pins.
Verified by exhaustive oracle enumeration
(`scratch-audit/verify-divert.mjs`): the branch exists and yields
`begin:C, provide:C:k1, apply:C:a, leave:Q, divert:C, revert:C:a, deactivated:C`.
The occurrence is schedule-dependent, as S-Div-1's already is; the verdict is
the exhaustive outcome set of obligation (D-E).

**S-Div-6** (realizes D1, D4, D5, D10):
`Q := (∅, {k2}, [provide(k2,v2)])`, `K := (∅, ∅, [track(kk)])`,
`G := ({k2}, ∅, [register(K), track(g1)])`
ρ = `insert(root, Q); settle; insert(root, G); retire(Q); settle`.
*Derivation:* as S-Div-5, with G's first landed step being Def. 47's
registration (T10), which pushes register⁻¹. On the branch where G begins
before Q leaves, G's divert window is {D1, D4(k2), D5, D10(register⁻¹)};
L-Unload's application of register⁻¹ performs O-Retire(K), and the cascade
disposes K. **This is the letter with teeth:** under `divert-skips-recovery`
the same run leaves K **Active**, an orphan child outliving the aborted
episode of the host that registered it (`scratch-audit/ev-read-acc.mjs`:
`Q:disposed G:pending K:disposed` versus `… K:active`). Verified.

**S-Div-7** (realizes D1, D4, D5, D11; uses the A7 grammar extension
`trackReadOnRevert(k1,t)`):
`P := (∅, {k1}, [provide(k1,v1)])`, `Q := (∅, {k2}, [provide(k2,v2)])`,
`C := ({k1,k2}, ∅, [read(k1), trackReadOnRevert(k1,a), track(b)])`
ρ = `insert(root, P); insert(root, Q); settle; insert(root, C); retire(Q);
settle`.
*Derivation:* C commits $\omega_C = \{k_1 \mapsto P,\ k_2 \mapsto Q\}$, reads
k1 (T5) and lands the read-on-revert inverse; Q leaves, so C's window is
{D1, D4(k2), D5, D11(read-on-revert)}. C routes through `Unloading`, and the
inverse *reads its committed k1 during the diverted teardown* — P is Active
and its table is intact — emitting `rd-on-revert(C,k1,v1)` before deact(C).
This is Thm. 63's promise at the divert entry, the counterpart of S-Unl-6 at
the leave entry. Verified.

**S-Div-8** (realizes D1, D4, D5, D12):
`Q := (∅, {k2}, [provide(k2,v2)])`, `C := ({k2}, ∅, [track(a), track(b)])`
ρ = `insert(root, Q); settle; insert(root, C); retire(Q); settle`.
*Derivation:* on the branch where C's L-Begin fires and Q's L-Leave fires
immediately after, C's very first post-begin window is already divergent with
$g = \mathrm{id}_\Gamma$: {D1, D4(k2), D5, D12}. The distinguishing subword is
`begin:C` followed by `divert:C, deactivated:C` with **no** `inv` event
between them, and C quiescing pending having applied nothing. Verified.

**Counting convention.** S-Div-4 and S-Div-4b are **one** canonical
experiment with two verdict clauses — §5.4 explicitly allows a single script
to realize several occurrences, and the two differ only in where the anchored
input lands. L-Divert therefore contributes **5 new scripts**: S-Div-4
(D7 with D9, and D7 with D12), S-Div-5 (D8, D9), S-Div-6 (D10), S-Div-7 (D11),
S-Div-8 (D12 under the ⊥-trigger). Its total rises from 2 to **7**.

### 3.2 L-Raise — one new letter

#### 3.2.1 Alphabet $\Sigma_{\text{L-Raise}}$ (addition to §8.1)

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 10 | X10 | InvClass = read-on-revert present in $g$ (Def. 48 clause 2; A7) | per-item witness |

#### 3.2.2 Finiteness

1 scalar + 4 step letters + 1 empty marker + **4** inverse-class witnesses =
**10**. InvClass now contributes all five of its values across X6–X10, exactly
as it does across U5–U9. $\blacksquare$

#### 3.2.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| X10 | yes in the calculus; **not expressible in the §2.2 step grammar** — precisely U8's status (A7) | a consumer whose teardown inverse reads its committed key, raising afterwards. Not witnessed by the explorer: no catalog shape combines `rrev` with a raise, the same generator gap that leaves X9 unwitnessed. |

#### 3.2.4 Canonical script

**S-Rai-8** (realizes X1, X2, X10; uses the A7 extension):
`P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), trackReadOnRevert(k1,a), raise(x)])`
ρ = `insert(root, P); settle; insert(root, C); settle`.
*Derivation:* C begins against Active P (B5), reads k1 (T5, rd(C,k1,v1)),
lands the read-on-revert inverse (T4-class step, app(C,a)), then raises: the
window is {X1, X2, X10}. L-Raise carries $g$ into
`Unloading(g, ω, x)`; L-Unload runs the inverse, which reads the still-held
k1 and emits `rd-on-revert(C,k1,v1)` before deact(C). Verified
(`scratch-audit/verify-scripts.mjs`): trace
`begin:C, read:C:k1="v1", apply:C:a, raise:C, revertread:C:k1="v1", deactivated:C`,
report C failed, P Active, k1 still bound.

New scripts at L-Raise: **1**.

### 3.3 L-Leave — one new letter

#### 3.3.1 Alphabet $\Sigma_{\text{L-Leave}}$ (addition to §9.1)

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 6 | V6 | StateClass = Active, ViewRel = view-stable ($\tau_n = \bot$ and $\omega_n(k) = \mathrm{provider}_k(\gamma)$ for every $k \in d_n$) | scalar guard, blocking |

#### 3.3.2 Finiteness

1 + 5 ViewRel letters = **6**; per-key classes contribute one letter each
independent of $|d_n|$. $\blacksquare$

#### 3.3.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| V6 | yes | every quiescent configuration containing an Active fiber realizes it — this is eq. 45's second clause read as a window. Machine-witnessed: `L-Leave disabled {trigger:"view-stable"}`. |

#### 3.3.4 Canonical script

**S-Lea-4** (realizes V6): `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C := ({k1}, ∅, [read(k1), track(b)])`
ρ = `insert(root, P); insert(root, C); settle; settle`.
*Derivation:* the first settle activates P and C. At every configuration of the
second settle the L-Leave window at P and at C carries {V6}: Active, target
equal to the committed view. The rule is not applicable at either fiber, the
second settle emits nothing, and the report is unchanged. The verdict is the
*absence* of any deact/inv event across the second settle together with the
`disabled` certificate for L-Leave at both fibers — an implementation whose
$f^{\mathbb I}_{\text{L-Leave}}$ passes on a stable window would emit a
spurious bounce, and nothing in the pre-closure alphabet indexes an
experiment against it. Verified (`verify-scripts.mjs`, S-Lea-4:
`ruleFor(P) = null`, `ruleFor(C) = null`, empty second-settle trace).
ρ coincides with S-Fin-3's up to the added `track` steps and the second
settle; the *experiment* differs by its verdict, so it is counted as one new
script.

New scripts at L-Leave: **1**.

### 3.4 O-Update — a new alphabet

**Source.** $\Lambda_{\mathrm{orch}}$'s `update(n, cfg)` (Definition 2), which
is not among Table 1's ten rules; realized as [SZC26] §5.2.1 realizes an entry
change (Def. 74's `config` field). The operation's premise is
$n \in \mathrm{dom}(F_\gamma)$; its write rewrites the entry's configuration
and, where the fiber is mid-episode, forces a re-resolution. Its *consequence*
is lettered at L-Leave (V5) and L-Divert (D7); its *own decision* — which of
the five fiber situations it meets, and hence what it writes — is what
$\Sigma_{\text{O-Update}}$ letters. The division of labour matches §11's for
`setval`: CO-Prov letters the operation, L-Iter/L-Raise letter the host rule.

#### 3.4.1 Alphabet $\Sigma_{\text{O-Update}}$

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | W1 | UpdClass = installed-episode ($n \in \mathrm{dom}(F_\gamma)$, $\mathrm{installed}_n$, $\theta_n \in \{\mathsf{Reloading}, \mathsf{Active}\}$): entry rewritten, episode marked for re-resolution | scalar |
| 2 | W2 | UpdClass = pending-entry ($\neg\mathrm{installed}_n$, $\zeta_n = \bot$): entry rewritten, no episode disturbed; the next L-Begin runs the new entry | scalar |
| 3 | W3 | UpdClass = failed-entry ($\neg\mathrm{installed}_n$, $\zeta_n = \xi$): entry rewritten **and $\zeta_n \mapsto \bot$**, lifting B2's block | scalar |
| 4 | W4 | UpdClass = unloading-clean ($\mathrm{installed}_n$, $\theta_n = \mathsf{Unloading}$, $\zeta = \bot$): the entry is rewritten while the teardown is already committed | scalar |
| 5 | W5 | UpdClass = unloading-failed ($\mathrm{installed}_n$, $\theta_n = \mathsf{Unloading}$, $\zeta = \xi$): $\zeta \mapsto \bot$ **before L-Unload reads it**, flipping the unload window U4 → U3 and re-enabling the U10–U12 block (C2) | scalar |
| 6 | W6 | UpdClass = absent-entry ($n \notin \mathrm{dom}(F_\gamma)$) | scalar, refusing |

$\kappa_{\text{O-Update}}$ of a window is a single scalar occurrence: the
operation reads the registry membership, $\mathrm{installed}_n$ and $\zeta_n$,
and nothing per-key, per-witness or per-item. The new configuration payload is
a value, normalized away by CF2.

#### 3.4.2 Finiteness

$|\mathrm{UpdClass}| = 6$: membership (2 values) times, on the positive side,
the product of $\mathrm{installed}_n$ (2) and $\zeta_n$ (2) folded to the four
well-formed blocks plus the `Unloading` split — the combination
$\neg\mathrm{installed} \wedge \theta = \mathsf{Unloading}$ is ill-formed
(eq. 44 makes `Unloading` installed), and $\mathsf{Reloading}$ and
$\mathsf{Active}$ share a block because the operation's write is the same at
both. $|\Sigma_{\text{O-Update}}| = 6$. $\blacksquare$

#### 3.4.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| W1 | yes | `update` on an Active fiber (= S-Lea-3's ρ) and on a Reloading one (S-Div-4). Machine-witnessed twice. |
| W2 | yes | `update` on a pending consumer. S-Upd-1. |
| W3 | yes | `update` on a failed fiber. S-Upd-2. |
| W4 | yes in the LTS; **requires the anchored-input notation** (§3.5) | `Unloading` is not a between-settles configuration. Machine-witnessed. S-Upd-3. |
| W5 | yes in the LTS; **requires the anchored-input notation** | likewise. Machine-witnessed. S-Upd-4. |
| W6 | yes | `insert; settle; retire; settle; update`. Not witnessed by the explorer, which offers `update` only at live fibers — the same class of generator gap as M2's. S-Upd-5. |

All 6 reachable.

#### 3.4.4 Canonical scripts

**S-Upd-0** (W1) — shared with **S-Lea-3** (§9.4) and **S-Div-4** (§3.1.4).
The Active sub-case is S-Lea-3's window read at the input rather than at
L-Leave; the Reloading sub-case is S-Div-4's. No new script.

**S-Upd-1** (W2): `C := ({k1}, ∅, [read(k1)])`
ρ = `insert(root, C); settle; update(C, cfg2); settle`.
*Derivation:* no provider for k1, so C quiesces pending with
$\mathrm{installed}_C$ false. The update window is {W2}: the entry is
rewritten and nothing else — no divergence is forced (there is no episode),
and the second settle emits **nothing**. Verified
(`verify-scripts.mjs`, S-Upd-1: `installed=false stale=false
events-after-update=0`). The verdict is precisely that emptiness together
with the update's certificate: an implementation that bounces a pending fiber
on `update` — or one that fails to pick up the new entry at the eventual
L-Begin — is separated here and nowhere else.

**S-Upd-2** (W3): `P := (∅, ∅, [track(a), raise(x)])`
ρ = `insert(root, P); settle; update(P, cfg2); settle`.
*Derivation:* the first settle runs L-Begin, L-Iter(track), L-Raise,
L-Unload (inv(P,a)) and quiesces at $\mathsf{Inactive}(x)$ — B2 blocks any
re-entry. The update window is {W3}: the entry is rewritten and the outcome
latch is cleared, so the fiber returns to $\mathsf{Inactive}(\bot)$ and B2 no
longer applies. The second settle runs a **complete second episode**:
`begin, app(P,a), raise, inv(P,a), deact`. Verified: trace
`begin, apply:a, raise, revert:a, deactivated, begin, apply:a, raise, revert:a, deactivated`,
final state failed. The distinguishing subword is the second `act`/`raise`
pair — the only experiment in $T^\star$ in which an $\mathsf{Inactive}(\xi)$
fiber is legitimately re-entered, and therefore the only one that pins where
the boundary of p. 38's "no re-entry from an error outcome" actually lies.

**S-Upd-3** (W4): `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C := ({k1}, ∅, [read(k1), track(b)])`
ρ = `insert(root, P); insert(root, C); settle; retire(P);
at cert(L-Leave, P) do update(P, cfg2); settle`.
*Derivation:* after the first settle P and C are Active. `retire(P)` sets
$\tau_P$; at the second settle P L-Leaves (V1, V3) and is held in `Unloading`
by C's committed edge (U2). The anchored update fires there: the window is
{W4}. The reference semantics writes a restart mark that no rule of the
`Unloading` branch reads; the teardown proceeds unchanged (inv(C,b) before
inv(P,a), by the guard) and P is removed. Verified: the quiescent report is
identical to the same run without the update — *except* that the reference
semantics leaves the mark set on the removed record. That residue is an
artifact (ambiguity A15), and the verdict for this experiment is stated over
the observable outcome only: **the update at an `Unloading` fiber perturbs no
event, no certificate and no report field.** This is the letter's content, and
an implementation that restarts the fiber instead is separated by it.

**S-Upd-4** (W5): `P := (∅, {k1}, [provide(k1,v1), raise(x)])`
ρ = `insert(root, P); at cert(L-Raise, P) do update(P, cfg2); settle`.
*Derivation:* the settle runs L-Begin, L-Iter(provide → T3), then the raise
(X1, X2, X7). The anchored update fires with P in `Unloading` carrying
$\zeta = x$: the window is {W5}. The outcome latch is cleared *before*
L-Unload's window is evaluated, so that window presents U3 (ζ=⊥) instead of
U4 and — by correction C2 — carries a bookkeeping letter it otherwise would
not; the fiber reaches $\mathsf{Inactive}(\bot)$, re-begins, and (with the
restart mark still set, A15) immediately diverts, then re-begins a third time
and raises again. Verified: trace
`begin, provide, raise, deactivated, begin, divert, deactivated, begin, provide, raise, deactivated`
against a four-event baseline. The verdict is the exhaustive outcome set: this
is the single experiment in which one orchestration input rewrites a
$\theta$-constituent of a mid-transition fiber, and it is the experiment
against which any resolution of PB-2/A15 must be stated.

**S-Upd-5** (W6): `P := (∅, ∅, [track(a)])`
ρ = `insert(root, P); settle; retire(P); settle; update(P, cfg2)`.
*Derivation:* the second settle runs L-Leave, L-Unload (inv(P,a)) and
O-Remove, so $P \notin \mathrm{dom}(F_\gamma)$. The update window is {W6} and
the input is refused, with the refusal reason "no such entry" — the reason
Definition 3 clause 1 requires to be matched, and the one that distinguishes
this refusal from P4's ("no own binding") and from any silent no-op. **The
reference semantics does not refuse:** it accepts the input and rewrites the
removed record (`verify-scripts.mjs`, S-Upd-5: `update ACCEPTED (no refusal)`).
That is a defect of `model.mjs`, reported in §6 and left for the integration
pass; the letter's specification decision is refusal, by parity with O-Retire's
R4 premise, which is the only premise Table 1 attaches to a name-taking
orchestration input.

New scripts at O-Update: **5**.

### 3.5 The anchored-input notation

Three of the new reachable letters — D7, W4, W5 — are windows at
*non-quiescent* configurations reached by an orchestration input. The
**interface** already admits them: Definition 2's LTS carries orchestration
labels alongside internal lifecycle steps, and Definition 3 clause 1
quantifies over every reachable related pair, so an implementation's behaviour
on an input delivered mid-episode is part of conformance whether or not
$T^\star$ tests it. What does not admit them is §5.4's **script notation**,
in which a $\rho$ is a sequence of inputs and `settle` macros and every input
therefore lands at a quiescent configuration.

The repair is additive and one line:

$$\rho \;::=\; \cdots \;\mid\; \mathsf{at}\ \varepsilon\ \mathsf{do}\ \lambda
\qquad (\varepsilon \in \mathcal E \cup \{\mathsf{cert}(r,n)\},\ \lambda \in \Lambda_{\mathrm{orch}})$$

read as: during the next `settle`, deliver $\lambda$ synchronously at the first
occurrence of $\varepsilon$. It is not new machinery — it is exactly the
`trace.when(marker, action)` device the reference harness already implements
(`proof/src/dsl.mjs`, `createTrace`), and its correctness obligation is the
one $T^\star$ already carries: the anchor event must be produced on *every*
fair schedule of the script, so that the attempt point is determinate
(obligation (D-F)). Each of S-Div-4, S-Upd-3 and S-Upd-4 anchors on an event
its script forces on every schedule (P is the only fiber, or the anchor is a
retired fiber's inevitable leave), and that is checked in
`scratch-audit/verify-scripts.mjs`.

**The alternative, recorded.** If the notation is not extended, D7, W4 and W5
join D6 as *interface-unrealizable in the script language while real in the
calculus* — the honest status, since the LTS reaches them and the printed
notation does not. Under that reading the totals below become
**108 letters / 100 reachable / 8 unrealizable / 72 scripts** instead of
108 / 103 / 5 / 75. We take the extension as primary because the occurrences
are conformance-relevant under Definition 3 as written, and because the
alternative would make $T^\star$ silent about the input whose four decisions
(W1, W3, W4, W5) include the failure-latch reversal of GAP-4 and the
$\zeta$-rewrite of GAP-6. Logged as ambiguity **A16**.

### 3.6 The environment-initiated read — the label, one new letter, two new experiments

#### 3.6.1 The label

**Definition 2′ (extension of Definition 2).**

$$\Lambda_{\mathrm{orch}} := \{\mathsf{insert}, \mathsf{retire}, \mathsf{update},
\mathsf{setval}, \mathsf{isolate}, \mathsf{intercept}, \mathbf{\mathsf{read}}\}$$

with $\mathsf{read}(n,k)$ for $n \in \mathfrak N \cup \{\mathsf{root}\}$ and
$k \in K$: the environment's *proxy-mediated* access, running Algorithm 6 from
$n$'s resolution context (and, for $n = \mathsf{root}$, from the root context,
where the walk holds no fiber and line 6 fires at once). Its premise is
$n \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$; its state map is
$\Psi = \mathrm{id}_\Gamma$ and its edit the identity — it **writes nothing**,
which is why it adds a label without adding a rule to Table 1. It emits the
same $\mathsf{rd}(n,k,v)$ / $\mathsf{rderr}(n,k,\epsilon)$ letters a
$\mathsf{read}$ step emits, and a certificate
$\mathsf{cert}(\text{A-Read}, \widehat s, \mathrm{id})$.

This is the channel [SZC26] p. 61 describes ("Cordis realizes this with a
`Proxy` whose `get` trap mediates every property access"), the channel
`adapter-model.mjs`/`adapter-cordis.mjs`/`adapter-distributed.mjs` already
expose as `readVia`, and the channel the 32-suite's `C5.3` and the explorer's
coda tests TB.90/TB.91 already drive. The formalization simply had no label
for it.

*What the label deliberately does not carry.* The **bare** Def.-23 `get` —
`ctx.get(k)`, "a lookup against the store that returns the bound value or
nothing and **never fails**" (p. 61) — is a different operation with different
decisions, and it is already lettered as CO-Prov's P5/P6. A system exposing
both surfaces needs both labels; we add only the proxy one, because it is the
one that carries deviant-distinguishing content, and record the other as
ambiguity **A16b**.

#### 3.6.2 Alphabet $\Sigma_{\text{CO-Acc}}$ (addition to §14.1)

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 8 | A8 | $n \notin \mathrm{dom}(F_\gamma)$: the read label's own premise fails | scalar, refusing |

A1–A7 are unchanged: they now letter the decisions of *both* a
$\mathsf{read}$ step and a $\mathsf{read}$ label, which is exactly correction
C5's point — Algorithm 6's outcomes are properties of the algorithm, and the
alphabet always letters the algorithm, not the caller.

#### 3.6.3 Finiteness

3 outcomes × ≤ 3 position classes (7 well-formed combinations) + 1 premise
failure = **8**. $\blacksquare$

#### 3.6.4 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| A4 | **yes** — the exclusion is lifted | C5 established that A4 is unrealizable as an *in-lifecycle window* and realizable as an external access; with the read label in $\Lambda_{\mathrm{orch}}$ the external access is an interface action, so A4 is reachable and the qualifier "excluded as a lifecycle-window occurrence" no longer applies. This is the bookkeeping change §14.3's C5 note flagged and declined to apply for want of a label; the label supplies it. S-Acc-3. |
| A8 | yes | `insert; settle; retire; settle; read(n,k)`. S-Acc-2. |
| A7 | unchanged | spec-unreachable by Thm. 63; the label does not help, because the guard blocks withdrawal while any committed edge names the provider, and the label creates no edge. |

**7 of 8 reachable** (A7 the sole exclusion) — the "strict reading" of C5, now
forced rather than optional.

#### 3.6.5 Canonical scripts

**S-Acc-3** (A4): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1,k2}, ∅, [track(c)])`
ρ = `insert(root, P); insert(root, C); settle; read(C, k1)`.
*Derivation:* P activates and binds k1; C declares k1 **and** k2, k2 has no
provider, so $\mathrm{target}_C = \bot$ and C quiesces
$\mathsf{Inactive}(\bot)$ with no committed view. The read label starts
Algorithm 6's walk at C: line 4 misses ($\omega_C$ is absent), line 5 fires
because $k_1 \in d_C$ — occurrence A4, PosClass = self. Verified
(`verify-scripts.mjs`, S-Acc-3): `C=pending; read(C,k1) -> threw
INACTIVE_ACCESS`, while P is Active and k1 *is* in $\sigma_\gamma$, which is
what makes the occurrence non-trivial: the fiber is refused its own declared
key because it has not committed to a provider. This ρ is the 32-suite's
`C5.3 declared-inactive-access` and the explorer's coda TB.91, lifted into
$T^\star$; it is the sole killer of the deviant `proxy-skips-inactive-check`
in either grounding artifact.

**S-Acc-2** (A8): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`
ρ = `insert(root, P); insert(root, C); settle; retire(C); settle;
read(C, k1)`.
*Derivation:* C activates and reads k1 (A1); `retire(C); settle` runs L-Leave,
L-Unload and O-Remove, so $C \notin \mathrm{dom}(F_\gamma)$. The read window is
{A8} and the input is refused with the reason "no such entry" — *not* with
`INACTIVE_ACCESS`, which is what the reference semantics returns
(`verify-scripts.mjs`, S-Acc-2: `C=disposed; read(C,k1) -> threw
INACTIVE_ACCESS [no dom(F) premise is consulted]`). The distinction matters
because the two reasons license different client behaviour — one says "not
yet", the other "never again" — and Definition 3 clause 1 compares refusal
reasons. Reported as a second defect of `model.mjs` in §6.

New scripts at CO-Acc: **2**.

### 3.7 CO-Prov — one new letter

#### 3.7.1 Alphabet $\Sigma_{\text{CO-Prov}}$ (addition to §11.1)

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 7 | P7 | $\mathcal A_k$ overwrite at $n \notin \mathrm{dom}(F_\gamma)$: the orchestration form's own premise fails | scalar, refusing |

#### 3.7.2 Finiteness

Three operations × binary precondition state + 1 premise failure = **7**.
$\blacksquare$

#### 3.7.3 Reachability and canonical script

**S-Set-1** (P7): `P := (∅, {k1}, [provide(k1,v1)])`
ρ = `insert(root, P); settle; retire(P); settle; setval(P, k1, v2)`.
*Derivation:* the second settle disposes P, so the name is gone. The window is
{P7}: refused for absence of the entry. In the reference semantics the input
is refused, but with P4's reason — O-Remove clears the table
(`model.mjs:326`), so the $\mathcal A_k$ precondition happens to fail first
(`verify-scripts.mjs`, S-Set-1: `setval -> refused: cannot set "k1" without
provide`). The two reasons are distinguishable in Definition 1's vocabulary
and the letter pins which one the specification owes; this is the third
`model.mjs` reporting item of §6, and the mildest, since the input is at least
refused.

New scripts at CO-Prov: **1**.

---

## 4. Revised counts

### 4.1 The delta, itemized

| site | letters | Δ\|Σ\| | Δreach | Δunreal. | Δscripts | what |
| --- | --- | :-: | :-: | :-: | :-: | --- |
| L-Divert | D7 | +1 | +1 | 0 | +1 | orch-update trigger (GAP-1) |
| L-Divert | D8, D9, D10, D11, D12 | +5 | +5 | 0 | +4 | per-item InvClass at the divert (GAP-2) |
| L-Raise | X10 | +1 | +1 | 0 | +1 | read-on-revert InvClass (GAP-9) |
| L-Leave | V6 | +1 | +1 | 0 | +1 | stable-view blocking window (GAP-8) |
| O-Update | W1–W6 | +6 | +6 | 0 | +5 | the whole alphabet (GAP-3/4/5/6/7) |
| CO-Prov | P7 | +1 | +1 | 0 | +1 | `setval` at an absent entry (GAP-7) |
| CO-Acc | A8 | +1 | +1 | 0 | +1 | `read` at an absent entry (GAP-7) |
| CO-Acc | A4 (existing) | 0 | +1 | **−1** | +1 | reachable through the read label (GAP-10, C5 applied) |
| **total** | | **+16** | **+17** | **−1** | **+15** | |

Script arithmetic: L-Divert +5 (S-Div-4, folding S-Div-4b as a second verdict
clause; S-Div-5; S-Div-6; S-Div-7; S-Div-8), L-Raise +1 (S-Rai-8), L-Leave +1
(S-Lea-4), O-Update +5 (S-Upd-1..5; W1 shares S-Lea-3 and S-Div-4), CO-Prov +1
(S-Set-1), CO-Acc +2 (S-Acc-2, S-Acc-3) = **15**.

### 4.2 The revised summary table

| rule / operation | \|Σ_r\| | \|Σ_r^reach\| | unrealizable (ids) | canonical scripts |
| --- | --- | --- | --- | --- |
| O-Insert | 7 | 6 | I5 (freshness, system-controlled) | 4 |
| O-Retire | 4 | 4 | — | 4 |
| O-Remove | 7 | 7 | — | 5 |
| **O-Update** | **6** | **6** | — | **5** |
| L-Begin | 7 | 7 | — | 6 |
| L-Iter | 11 | 11 | — | 8 |
| L-Finish | 3 | 3 | — | 3 |
| L-Divert | **12** | **10** | D2 (A10), D6 (A9) | **7** |
| L-Raise | **10** | **10** | — (X4 via isolation, A4; X10 via A7) | **8** |
| L-Leave | **6** | **5** | V2 (A10) | **4** |
| L-Unload | 12 | 12 | — (U8 via A7) | 9 |
| CO-Prov (Def. 23/24) | **7** | **7** | — | **3** new (4 shared) |
| CO-Iso (Def. 28/29) | 4 | 4 | — | 3 |
| CO-Int (Def. 31) | 4 | 4 | — | 3 |
| CO-Acc (Alg. 6 + read label) | **8** | **7** | A7 (withdrawn binding) | **3** new (4 shared) |
| **total** | **108** | **103** | **5** | **75** |

**92 / 86 / 60 / 6 → 108 / 103 / 75 / 5.**

Column check, in §15's own convention (the coeffect rows count *new* scripts,
the rest count totals): $4+4+5+5+6+8+3+7+8+4+9 = 63$ for the rules and
$3+3+3+3 = 12$ for the coeffect layer, so $|T^\star| = 75$.

The unrealizable set shrinks by one and by one only: A4 leaves it (the read
label reaches it), and nothing enters it, because every new letter is
reachable. The five survivors are I5, D2, D6, V2, A7 — and their evidence
grades are unchanged: D2, V2 and A7 remain genuine negative search results
over 7.05 M states, I5 and D6 remain absences the model shares by assumption.

### 4.3 The reconciliation with the explorer, recomputed

Re-running the manuscript §7 projection with the extended alphabets
(`scratch-audit/alpha2.mjs`, a patched copy of `explorer/reconcile.mjs`; the
explorer's own outputs were restored untouched):

| quantity | before | after |
| --- | :-: | :-: |
| reachable explorer tuples | 146 | 146 |
| distinct classes under $\alpha$ | 74 | **88** |
| collapse factor | 1.97× | **1.66×** |
| explorer signatures with **no** Appendix D letter | **6** | **0** |
| pseudo-letters $\alpha$ must invent | 2 (`V5@divert*`, `V1-disabled*`) | **0** |
| letters witnessed separately | 67 | **79** |
| letters witnessed only as a conflated pair | 8 | 8 (unchanged) |
| unrealizable letters witnessed | 0 | 0 |

and the arithmetic of §7 becomes

$$108 - 5 = 103 = \underbrace{87}_{\text{witnessed in the graph}} + \underbrace{3}_{\text{covered by tests outside the graph}} + \underbrace{13}_{\text{unwitnessed, each with an identified cause}},$$

against the pre-closure $92 - 6 = 86 = 75 + 2 + 9$. The coda-covered group
grows from {I3, N4} to {I3, N4, **A4**}. The unwitnessed group grows from
9 to 13 by exactly the four new letters the explorer's *generator* cannot
offer: **W6, P7, A8** (it never applies `update`, `setval` or a read at a
disposed name) and **X10** (no catalog shape combines `trackReadOnRevert` with
a raise — the same generator gap that already leaves X9 unwitnessed). All four
causes are of the kind §7 calls "closable by widening the generator", not
encoding blind spots. L-Divert's 12 tuples now project **bijectively** onto 12
letter-sets, and O-Update's 6 tuples onto 5 (the Active and Reloading tuples
share W1 by design, their consequences being lettered at V5 and D7).

### 4.4 New ambiguities

Continuing `signatures.md` §17's numbering.

- **A11 — the accumulator's status at the three `Unloading` entries.** Table 1
  makes $g$ a write input of L-Divert, L-Raise and L-Leave alike, and
  Appendix D letters it at L-Raise only. This deliverable resolves the
  inconsistency **upward** (letter it at L-Divert too, on the coverage
  argument of GAP-2) rather than **downward** (delete X6–X9 and attach an
  entry-path atom to U5–U9). The downward repair is coherent and cheaper by
  five letters, but it moves per-class coverage into L-Unload's scripts, which
  would then have to be triplicated across the three entry paths — a net
  increase in $|T^\star|$. Recorded so the choice is visible.
- **A12 — Def. 74's `disabled` field un-retires a fiber.** §5.2.1 (p. 63):
  "`disabled` — unloads the fiber when set and reloads when cleared", and
  Def. 74 says "`disabled` gives $\tau$". Clearing it therefore writes
  $\tau \mapsto \bot$, which Lemma 54(5) forbids ("$\tau_n$ is monotone,
  written only at $\top$ and only by an O-Retire"). Either the loader's
  `disabled`-clear is a *rebuild* (retire, drain, insert — three inputs, all
  lettered) or Table 1's O-Retire needs an inverse. Not lettered here.
- **A13 — `isolate` on a live entry.** Def. 29's `isolate` derives a context;
  §5.2.1's Algorithm 7 *reassigns* a live entry's realms with delimiter tags
  $\delta_k$ and then reloads. These are different operations with different
  decisions; $\Lambda_{\mathrm{orch}}$ contains the first.
- **A14 — `intercept` on a live entry.** Likewise: §5.2.1 updates interception
  "in place, as interception metadata is consulted at read time and needs no
  reload", where Def. 31 derives a context for subsequent resolution.
- **A15 — the restart mark's lifetime.** Nothing in the calculus says what an
  entry update does to a fiber already in `Unloading` (W4/W5). The reference
  semantics sets a mark that no `Unloading`-branch rule reads and that
  L-Unload does not clear, so it survives into the *next* episode and forces a
  spurious L-Divert there (`verify-scripts.mjs`, S-Upd-4). W4's and W5's
  decision entries are stated over the observable outcome only; the residue is
  an artifact and the integration pass should either clear the mark at
  L-Unload or letter the surviving mark as a sixth UpdClass.
- **A16 — inputs at non-quiescent configurations.** Definition 3 makes them
  conformance-relevant; §5.4's script notation cannot write them. §3.5 gives
  the one-line repair and the alternative bookkeeping.
- **A16b — two read surfaces.** Implementations expose both the proxy read
  (Algorithm 6, d-enforcing, failing) and the bare Def.-23 `get` (store
  lookup, never failing). §3.6 adds a label for the first; the second is
  lettered as P5/P6 but has no label, so $T^\star$ still cannot drive it
  directly.

---

## 5. Verdict

**Are the alphabets complete after the closure?** For the interface of
Definition 2′ and the observation vocabulary of Definition 1, I believe they
are, and I can say precisely how strong that belief is — which is the useful
part.

What the closure *establishes*, in the sense of a checkable fact: every
signature the bounded explorer reaches now has a letter (0 unlettered, down
from 6; 0 pseudo-letters, down from 2); every branch of the reference
semantics that a non-mutant execution can take is either lettered or listed in
§2.2 with a reason drawn from a premise inventory rather than from taste; every
premise and every write input of all ten Table-1 rows has been walked
individually against the alphabet; and each of the five name-taking
$\Lambda_{\mathrm{orch}}$ inputs now has a letter for its registry premise,
where before only two did.

What the closure *does not* establish, and what would be needed to turn the
argument into a proof — this is the paper's real epistemic frontier, and it
has four distinct layers, only the last of which is hard:

1. **The audit is a search, not a decision procedure.** Its three independent
   derivations (row premises; operation definitions; code branches and
   recorded fields) agree, and their agreement is evidence — the third found
   GAP-1 and GAP-2, the second found GAP-3 through GAP-7, the first found
   GAP-8 and GAP-9 — but agreement of three searches is not exhaustion. A
   fourth vantage would be another such search.
2. **The gap between "no explorer signature is unlettered" and "no window is
   unlettered" is the explorer's bound.** The portfolio is exhaustive in every
   dimension but the fiber count, where it stops at 3; the saturation evidence
   (zero new signatures across 3.8 M further states at the widest alphabet)
   is strong and is not a proof. Closing this layer means either a cut-off
   theorem — *no window class first appears above $b$ fibers* — or a bounded
   model checked in Lean, which is what `formal/lean/` is for. A cut-off
   theorem is the right target: the rules read no cardinality (that is CF3's
   own content), so a bound of the form "$|d_n| + 2$ fibers suffice" is
   plausible and, if proved, would convert the explorer from corroboration
   into a decision procedure at the bound.
3. **The completeness property is stated but not formalized.** (D-A) says the
   alphabet "covers exactly the guard atoms and write inputs" *at the
   granularity of Appendix D's tables* — and the qualifier is doing real work,
   because the granularity is where GAP-2 and GAP-8 lived. The property that
   would make completeness *provable* rather than *auditable* is a different
   one, and it is stateable: for each rule $r$,
   $$\kappa_r(W) = \kappa_r(W') \;\Longrightarrow\; \mathrm{result}_r(W) \equiv \mathrm{result}_r(W')$$
   over all interface-reachable windows — **$\kappa_r$ is a congruence for the
   rule's observable result**. That is an *adequacy* statement about the
   normalization, it does not mention "atoms" or "granularity", and it is
   exactly what the transport lemma needs. Every gap in this deliverable is a
   counterexample to it as the tables stood: two windows with equal
   $\kappa$-images and different results (a divert with a register-inverse and
   one with none; an `update` at a failed fiber and one at a pending fiber).
   **Proving the congruence — rather than arguing the coverage — is what
   would close the question.** It is provable by induction over the premise
   inventory once the alphabet is fixed, and it is provable *at a bound* by
   the explorer today: quotient the reachable window set by $\kappa_r$ and
   check that each class has a single result. That check is cheap, it is not
   currently run, and it is the single highest-value next artifact.
4. **The interface itself is a modelling choice, and choices are not
   provable.** GAP-10 and ambiguities A12–A14, A16b are all of one shape:
   $\Lambda_{\mathrm{orch}}$ is narrower than what implementations expose.
   Adding the read label narrows the gap by the one channel with demonstrated
   deviant-distinguishing content; it does not close it, and no theorem can,
   because "the interface under test" is an empirical claim about the software,
   not a mathematical one. The honest form of the completeness claim is
   therefore always relative: *$T^\star$ characterizes conformance with respect
   to $\Lambda_{\mathrm{orch}}$ as fixed by Definition 2′*, and every widening
   of that interface owes a fresh reachability analysis — which, as §9 of the
   manuscript already promises and this deliverable now demonstrates
   concretely, is additive and invalidates nothing.

So: complete relative to Definition 2′, the reference semantics, and a
3-fiber bound; not proved complete, and the missing proof has a name (the
$\kappa_r$-congruence of layer 3) and a cheap first instalment (checking it at
the explorer's bound). Layers 1 and 2 are quantitative and closable with work
already scoped; layer 4 is not closable and should be stated as a proviso
rather than chased.

One further thing this audit is evidence for, and it is not comfortable: the
gaps clustered almost perfectly where the hypothesis predicted. Eight of the
ten are at `update` or at a rule consuming `update`, and the ninth and tenth
are at the two other places where $\Lambda_{\mathrm{orch}}$ and Table 1 fail to
line up (the missing read label; the registry premise no rule states for
non-rule inputs). The alphabets were derived from Table 1 and are, as far as
this audit can tell, *complete for Table 1*. What they were not complete for is
the interface — and that boundary, not any individual letter, is the finding.

---

## 6. Defects found in the reference semantics (reported, not fixed)

`paper/proof/` is out of scope for edits; these three are recorded for the
integration pass. None affects any pre-existing result: all three are at
inputs the 32-obligation suite and the explorer's generator never make.

1. **`update` at a removed name is accepted** (`model.mjs:550`). It rewrites a
   record with `removed === true` and `uid === null`, clearing its outcome.
   The specification decision for W6 is refusal, by parity with O-Retire's
   $n \in \mathrm{dom}(F_\gamma)$ premise.
2. **`read` at a removed name is served from the stale record**
   (`model.mjs:480`, `readCommitted`). It consults `spec.inject` and the parent
   chain of a disposed fiber, so it returns `INACTIVE_ACCESS` where the
   specification decision for A8 is refusal with reason "no such entry".
3. **`setval` at a removed name is refused for the wrong reason**
   (`model.mjs:529`). O-Remove clears the table, so P4's precondition fails
   before any registry check; the letter P7 owes the "no such entry" reason.

A fourth item is a candidate defect rather than a defect, because the calculus
does not decide it: **the restart mark is never cleared** (`model.mjs:550–557`
sets `stale`; only L-Divert and L-Leave clear it, and L-Unload does not), so an
`update` at an `Unloading` fiber leaves a mark that fires a spurious L-Divert
in the fiber's next episode. See ambiguity A15.

---

## 7. Reproduction

All checks are read-only over `paper/proof/src/model.mjs` and
`paper/formal/explorer/out/*.json`; every artifact written by this deliverable
is under `paper/formal/scratch-audit/`. Node ≥ 22, no dependencies.

```sh
cd paper/formal/scratch-audit
node ev-update.mjs        # §2 GAP-3..GAP-7: the six decisions of `update`
node ev-read-acc.mjs      # §2 GAP-2 (orphan child), GAP-7, GAP-8, GAP-10
node verify-scripts.mjs   # §3: all 15 new canonical scripts, default schedule
node verify-divert.mjs    # §3.1.4: S-Div-5..8 under exhaustive oracle enumeration
cd ../explorer && node ../scratch-audit/alpha2.mjs out/signatures-*.json
                          # §4.3: the recomputed α-projection (88 classes, 0 unlettered)
```

`alpha2.mjs` is a patched copy of `explorer/reconcile.mjs` carrying the
extended alphabets; it writes `out/reconcile.{json,md}` in place, so the
originals were copied out and restored with `git checkout` immediately after
the run — the post-closure outputs are kept here as
`reconcile-postclosure.{json,md}`. Run it only with that restore in hand, or
redirect its output directory first.

---

*End of D5. The 15 new scripts have been executed against the unmutated
reference semantics; the four schedule-dependent ones (S-Div-5..8) were
verified by exhaustive oracle enumeration, and three (S-Div-4, S-Upd-3,
S-Upd-4) require the anchored-input notation of §3.5, realized in the harness
by `createTrace`'s watcher.*
