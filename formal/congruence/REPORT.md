# D6 — The κ_r-congruence check, and four fixes to the executable specification

**What this is.** `../alphabet-audit.md` §5 ends by naming the one thing that
would turn the paper's completeness *argument* into a *proof*, and by saying it
is checkable today:

> The property that would make completeness *provable* rather than *auditable*
> … is stateable: for each rule $r$,
> $\kappa_r(W) = \kappa_r(W') \Rightarrow \mathrm{result}_r(W) \equiv \mathrm{result}_r(W')$
> over all interface-reachable windows — **$\kappa_r$ is a congruence for the
> rule's observable result**. … it is provable *at a bound* by the explorer
> today: quotient the reachable window set by $\kappa_r$ and check that each
> class has a single result. That check is cheap, it is not currently run, and
> it is the single highest-value next artifact.

This deliverable runs it, over the alphabets as revised by that audit's §3
closure (its 16 new letters), against the reference semantics, at a portfolio
of nine bounds. It also fixes the four specification defects the same audit
reported and left for the integration pass — and three of them turn out to
*be* κ-congruence counterexamples, so the two halves are one thing.

Everything new is under `formal/congruence/`. `explorer/`, `tstar/`,
`paper.md`, `signatures.md`, `derivations.md` and `alphabet-audit.md` are
untouched; `paper/proof/src/model.mjs` is edited, and §3 says exactly how.

---

## 1. Verdict

Over the union of the portfolio: **32,592,988 interface-reachable windows,
118 κ-classes, exactly one non-singleton result class.** That one is a genuine
residual gap in the alphabet, at L-Iter, reported in §4; adding the one letter
it asks for closes it (machine-confirmed, §4.3).

| rule | reachable windows | κ-classes | non-singleton result classes (level 1) | classes split by frame only (level 2) |
| --- | ---: | ---: | ---: | ---: |
| O-Insert | 331,436 | 8 | **0** | 0 |
| O-Retire | 4,612,590 | 4 | **0** | 0 |
| O-Remove | 4,600,267 | 12 | **0** | 0 |
| O-Update | 4,612,590 | 6 | **0** | 0 |
| L-Begin | 1,163,730 | 14 | **0** | 0 |
| L-Iter | 222,869 | 11 | **1** | 2 |
| L-Raise | 123,104 | 5 | **0** | 0 |
| L-Finish | 232,218 | 4 | **0** | 2 |
| L-Divert | 897,029 | 18 | **0** | 7 |
| L-Leave | 720,970 | 4 | **0** | 0 |
| L-Unload | 1,238,415 | 23 | **0** | 2 |
| CO-Prov | 4,612,590 | 3 | **0** | 0 |
| CO-Acc | 9,225,180 | 6 | **0** | 0 |
| **total** | **32,592,988** | **118** | **1** | 13 |

Windows excluded as explorer state-encoding artifacts (§2.4): 1,932.

The bounds, and their wall clock:

| run | bound | states | windows | κ-classes | wall | BFS saturation (windows since the last new class) |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| A1 | 1 fiber, all 19 shapes | 588 | 4,498 | 66 | 0.2 s | 1,148 of 4,128 |
| A2c | 2 fibers, all shapes, no `update`/`setval` | 30,765 | 508,261 | 100 | 8.2 s | 156,651 of 507,891 |
| A2w | 2 fibers, all shapes | 300,001 (trunc.) | 3,523,526 | 114 | 86.2 s | 43,530 of 3,523,156 |
| A3c | 3 fibers, all shapes, no `update`/`setval` | 300,000 (trunc.) | 3,713,532 | 82 | 72.7 s | 1,511,714 of 3,713,162 |
| dep3 | 3 fibers, `P,M,CC,CRR` | 400,003 (trunc.) | 8,075,008 | 83 | 209.3 s | 3,476,616 of 8,074,638 |
| fail3 | 3 fibers, `P,FP,C` | 400,000 (trunc.) | 6,862,427 | 63 | 185.6 s | 6,154,850 of 6,862,057 |
| regA | 3 fibers, `P,A` | 300,000 (trunc.) | 4,440,552 | 69 | 212.7 s | 4,176,311 of 4,440,182 |
| regB | 3 fibers, `P,A`, no child-insert/`update`/`setval` | 19,707 | 550,362 | 62 | 26.7 s | 507,325 of 549,992 |
| sat3 | 3 fibers, `P,C` | 235,316 | 4,914,822 | 61 | 132.6 s | 4,642,366 of 4,914,452 |

Total wall clock for the portfolio: **15 min 34 s** on one core.

**Bound reductions, logged.** The bound family is the explorer's own
(`../explorer-report.md` §4), so the results are comparable with it, but five
runs were capped where the explorer ran longer: A2w at 300 k states (the
explorer took 2.5 M and was itself truncated), A3c at 300 k (explorer 2.34 M,
truncated), dep3 and fail3 at 400 k (explorer 558 k and 688 k, untruncated),
regA at 300 k (explorer 631 k, truncated). Per-window cost here is roughly
50× the explorer's — each window is a fresh materialization, a κ computation,
a rule application and two abstract-state snapshots — so the caps buy the
portfolio a fifteen-minute wall clock instead of several hours. Four runs (A1,
A2c, regB, sat3) are complete and untruncated.

Two facts bound how much the truncation costs. First, saturation: at seven of
nine bounds the last new κ-class appeared with millions of windows still to
come and none arrived. Second, redundancy: of the 118 classes in the union,
**114 are reached by at least two different runs**; the four that are not are
all `dep3`'s, and every class the two truncated all-shapes runs (A2w, A3c)
reach is reached by some other run as well. The largest bound actually checked is 3 fibers with the full
19-shape catalog (A3c, 300 k states, 3.7 M windows).

---

## 2. What was checked, precisely

### 2.1 The window set

A *window* $W_r(\gamma, n)$ is a configuration together with the fiber (or the
name, or the name-and-key) the rule acts at, restricted to the rule's own
state-class premise. Windows are enumerated at every state of a breadth-first
exploration of the LTS — the same transition relation `explorer/explore.mjs`
uses, over the same finite orchestration generator (`explorer/catalog.mjs`),
with the same χ-normalization (`explorer/norm.mjs`) deduplicating states.

Blocking windows are included wherever Appendix D letters them (M2, M5, M7 at
O-Remove; B2, B4, B6, B7 at L-Begin; V6 at L-Leave; U2 at L-Unload): a blocked
decision is a decision, and Definition 8 clause 1 needs the scalar occurrence
whose atoms *fail* in order to produce the block.

Windows at a name O-Remove has taken out of $\mathrm{dom}(F_\gamma)$ — the
letters R4, W6, P7, A8 and I3 — occur at no state of the graph, because
normalization drops removed fibers nothing references. (This is the same
structural gap that forced `run-explore.mjs`'s coda test TB.88.) They are
checked on a **coda family** built outside the graph: `insert S; settle;
retire S; settle` over eleven catalog shapes under three companion
configurations, 33 configurations, which gives each of those classes dozens of
windows and so a real congruence test rather than a vacuous singleton.

### 2.2 κ_r

`kappa.mjs` computes κ_r from the configuration, letter by letter, following
`../signatures.md` §§1–14 as revised by `../alphabet-audit.md` §3. Two
properties matter.

**It is finer than the explorer's α.** `explorer/reconcile.mjs` and
`../scratch-audit/alpha2.mjs` project a *certificate field record* onto
letters, and that encoding cannot separate D3 from D4, V3 from V4, A3 from A4,
A5 from A6, or S2 from S3 — the audit's §4.3 calls these "conflated
witnesses". κ here reads the state and separates all of them, which is what
Appendix D's tables actually say. The trade-off is worth stating: a finer κ
makes fewer windows κ-equal, so it is the *easier* congruence to satisfy. Had
the check been run through the explorer's coarser α it would have reported the
five conflations as counterexamples — correctly, of the *encoding*, not of the
alphabet. We check the alphabet.

**It is a set, not a sequence.** Per-key, per-witness and per-item families
contribute one letter per class regardless of how many keys, witnesses or
accumulator items realize the class (`../alphabet-audit.md` §3.1.2, §8.2,
§10.2). Accumulator order and length, and the iterator's position, are absent
by construction: they are frame data (Remark 1).

### 2.3 result_r(W), and why there are two levels

`../paper.md` §5 Remark 1 already rules out the naive reading:

> κ_r(W) is a multiset and carries no order; the accumulator's composition
> order and the iterator's position are frame data of W, consumed by lift_r.
> … The Transport Lemma (§6.2) is stated with exactly this split; a version
> claiming that κ-equal windows receive identical *whole-rule* results would be
> **false** for windows that agree as multisets but differ in accumulator
> order.

So the check runs at two granularities.

**Level 1 — the per-occurrence result.** Decision (fire / block / refuse),
refusal reason, the *set* of abstract emission classes, and the abstract
update. This is the hypothesis Lemma 4(1)–(2) needs: $f_r^{\mathbb I}$ is a
function of the occurrence alone. **Congruence must hold here**, and a split
is a counterexample.

**Level 2 — the whole-rule result.** Level 1 plus the frame: accumulator
length and composition order, iterator position, and the emission *word* with
order and multiplicity. Splits here are Remark 1's own prediction.

`check-l2.mjs` inspects every level-2 split mechanically and asks whether it
differs in anything but `iterAt`, `accLen`, `accOrder`, or emission order and
multiplicity. Over the portfolio: **44 level-2 splits, of which 40 are purely
frame data**, and the remaining 4 are the single L-Iter class of §4 recurring
at four bounds. Remark 1 draws the line in exactly the right place, and this
is the first machine evidence for that.

The abstract update is assembled in Table 1's vocabulary and no finer:

* it is **the write, not the change** — Lemma 54(5) makes $\tau_n \mapsto \top$
  the same write whether or not $\tau_n$ was already $\top$, so an idempotent
  re-write is not a different result. Each row's written fields (Table 1's
  $\theta^{t+1}$ and "control fields edited" columns) are reported as
  post-values unconditionally when the rule fires, and not at all when it
  refuses or blocks (a refusal has $\Psi = \mathrm{id}_\Gamma$ and
  $\mathrm{edit} = \mathrm{id}$);
* the **accumulator's** update is the per-occurrence write — `push(c)`,
  `clear`, `unchanged` — never the resulting composite: composing $g \circ h$
  is $\mathrm{lift}_r$'s job under CF3, not the occurrence's decision;
* the O-Retire a registration inverse yields (Def. 47) lands on a fiber that is
  not the subject, so its $\tau \mapsto \top$ is reported as a write too;
* fibers are named by their **role** relative to the subject (self / ancestor /
  descendant / view-provider / dependent, composite), because names are atoms
  compared only for equality (Lemma 56, equivariance);
* keys are named by their **class** in the owning fiber's declaration, and
  per-key families are folded to one occurrence per class;
* values are **dropped** (CF2; Lemma 2, "no premise of any row inspects a
  value"). A served read reports the *role* of the fiber whose table answered
  it, never the value — [SZC26] p. 31: "recording a provider rather than a
  value is what makes the comparison usable."

The last four items are where this artifact makes judgements rather than
reading them off, and they are the place to attack it: each fold is a place
where a real difference could be hidden. Each is tied above to the clause that
licenses it, and §6 restates the risk.

### 2.4 What is excluded, and why

1. **Normalization round-trip faults (1,932 windows).** `explorer/norm.mjs`
   stores a registration inverse's child by uid, and O-Remove nulls the uid, so
   a record whose registered child has been *removed* loses the reference and
   the rebuilt inverse retires `null`. That is an artifact of the explorer's
   state encoding — in a live run the record is still there and the O-Retire is
   a no-op on it — not a decision of any rule. Such windows are counted and
   excluded rather than reported as split classes; without the exclusion,
   L-Unload {U1,U10,U3,U7} would appear to split into "fires" and "throws a
   `TypeError`". (`explorer/explore.mjs` silently absorbs the same fault into
   its `refused` bucket, so it is pre-existing, not introduced here.)
2. **CO-Iso and CO-Int as separate rules.** `interceptMerged` and Def. 29's
   context-deriving `isolate` are derived operations no LTS transition invokes
   (`../explorer-report.md` log S7), so the graph offers no window for them.
   The realm letters S1/S2/S3 *are* checked, inside κ_{O-Insert}, where the
   derived context is captured.

### 2.5 Reproducing

```sh
cd paper/formal/congruence
node defects.mjs         # §3: the four fixes, before/after, with citations
sh portfolio.sh          # ~15 min; writes out/cong-<tag>.json per bound
node summarize.mjs       # unions the portfolio -> out/SUMMARY.md
node check-l2.mjs        # every level-2 split is frame data (§2.3)

# the one alphabet repair §4 finds to be owed, applied:
node run-congruence.mjs --repair --tag=rep-A2c --maxFibers=2 --noUpdates --noSetowns

# the same check against the PRE-fix reference semantics (§3.5):
CONG_NO_FIX=1 node run-congruence.mjs --tag=nofix-A1 --maxFibers=1
```

Node ≥ 22, no dependencies. Pre-fix outputs are kept in `out-nofix/`, repaired
ones in `out-repair/`.

---

## 3. The specification defects

`../alphabet-audit.md` §6 reports three defects in `paper/proof/src/model.mjs`
and a fourth item it calls "a candidate defect rather than a defect, because
the calculus does not decide it". All four are fixed here. The reference
semantics is the paper's *executable specification*, so a defect there means
Theorem 2's soundness gate — "the specification satisfying its own suite" —
was run against a slightly wrong specification.

`node defects.mjs` reproduces each with a minimal script and prints before,
after and citation: 8/8 cases, five defect cases and three regression guards.

### 3.1 Defect 1 — `update(n, cfg)` at n ∉ dom(F_γ) was accepted

**Before.** `update` on a name O-Remove had taken out of the registry was
accepted: it rewrote a record with `removed === true` and `uid === null`, and
cleared its outcome latch.

**After.** Refused, `code = 'NO_SUCH_ENTRY'`.

**Calculus.** [SZC26] p. 31 states O-Retire with the single premise
$n \in \mathrm{dom}(F_\gamma)$, and p. 32 repeats it in words: "**O-Retire has
$n \in \mathrm{dom}(F_\gamma)$ as its only premise**." That is the only
premise Table 1 attaches to a name-taking orchestration input, and by parity it
is the premise `update` owes; it is the audit's letter **W6** (§3.4.1), whose
specification decision the audit already states as refusal. Lemma 54(5) is why
it cannot be a silent no-op: $\pi, d, p, e$ "come into existence with the entry
of $n$ and are never written again", so after $\gamma \setminus n$ there is no
entry to rewrite. Definition 7 requires one $\mathsf{block}(\varrho)$ per
premise schema and Definition 3 clause 1 requires the reason to be matched, so
silent acceptance is not laxity but a missing observation.

**Edit.** `Model.prototype.inRegistry` and `Model.noSuchEntry`, plus a guard at
the head of `update`.

### 3.2 Defect 2 — `read(n, k)` at n ∉ dom(F_γ) was served from the stale record

**Before.** `readCommitted` at a disposed fiber consulted the dead record's
`spec.inject` and its dead parent chain, and answered `INACTIVE_ACCESS`, or
`UNDECLARED_ACCESS`, or served a value — depending on what the dead record
still declared (see §3.5).

**After.** Refused, `code = 'NO_SUCH_ENTRY'`.

**Calculus.** Definition 2′ (`../alphabet-audit.md` §3.6.1) gives the read
label the premise $n \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$:
Algorithm 6 ([SZC26] p. 61) runs *from n's resolution context*, and a removed
name has none. Letter **A8**. The reason is the point: "the two reasons
license different client behaviour — one says 'not yet', the other 'never
again' — and Definition 3 clause 1 compares refusal reasons."

**Edit.** A guard at the head of `readCommitted`. In-lifecycle reads are
unaffected: a fiber executing a step is in the registry by construction, and so
is one running a read-on-revert inverse from `Unloading`. Guard `GUARD-3` in
`defects.mjs` pins that A4 (the live-but-uncommitted declaring fiber, C5.3 /
S-Acc-3 / TB.91) still answers `INACTIVE_ACCESS`.

### 3.3 Defect 3 — `setval(n, k, v)` at n ∉ dom(F_γ) was refused for the wrong reason

**Before.** Refused with P4's reason, `cannot set "k1" without provide` —
because O-Remove clears the table, so Definition 24's own precondition happened
to fail before any registry check.

**After.** Refused, `code = 'NO_SUCH_ENTRY'`, checked **before** Definition
24's precondition.

**Calculus.** The same registry premise; letter **P7**
(`../alphabet-audit.md` §3.7.1). The mildest of the three — the input was at
least refused — and, as §3.5 shows, invisible to the congruence check.

### 3.4 Defect 4 (the audit's "candidate") — the restart mark was never cleared

**Before.** `update` at an `Unloading` fiber sets `fiber.stale`; only L-Divert
and L-Leave clear it, and neither runs from `Unloading`. The mark survived
L-Unload onto the `Inactive` fiber and forced a spurious L-Divert in the *next*
episode. The audit's own S-Upd-4 shows it: one orchestration input produced
**three** episodes,
`begin, provide, raise, deactivated, begin, divert, deactivated, begin, provide, raise, deactivated`,
the middle one a begin/divert/deactivate with no rule premise true at it.

**After.** L-Unload clears the mark as part of its write. S-Upd-4 now observes
two episodes:
`begin, provide, raise, deactivated, begin, provide, raise, deactivated`.

**Calculus.** The audit logs this as ambiguity **A15** ("nothing in the
calculus says what an entry update does to a fiber already in `Unloading`") and
offers the integration pass two options: clear the mark at L-Unload, or letter
the surviving mark as a further UpdClass. The calculus does decide between
them, and it decides for clearing:

* **eq. 43** fixes
  $\Theta_\Gamma := \mathsf{Inactive}(\zeta) \mid \mathsf{Reloading}(i,g,\omega)
  \mid \mathsf{Active}(g,\omega) \mid \mathsf{Unloading}(g,\omega,\zeta)$.
  $\mathsf{Inactive}(\zeta)$ has **no** restart-mark constituent, and Table 1's
  L-Unload row writes $\theta_n \mapsto \mathsf{Inactive}(\zeta)$ *whole* — its
  fifth column names $\theta_n$ and nothing else. Nothing of the `Unloading`
  state survives it.
* **Lemma 54(2)**: "$\omega_n$ … ceases only where $\mathrm{step}^t =
  \text{L-Unload}(n)$." The mark's whole meaning is "force
  $\mathrm{target}_n(\gamma) \neq \omega_n$ at this window"; at
  $\mathsf{Inactive}$ there is no $\omega_n$ for it to mean anything against.
* The consequence of not clearing is an L-Divert step taken with its own
  premise $\mathrm{target}_n(\gamma) \neq \omega$ **false** — not a resolution
  of an ambiguity but a violation of the rule.

The audit's W4 verdict — "the update at an `Unloading` fiber perturbs no event,
no certificate and no report field" — is now literally true, including of the
record, where before it held only up to the residue the audit had to except.

**Edit.** `fiber.stale = false` inside L-Unload's closure, next to
`fiber.committed = null`.

### 3.5 Three of the four are κ-congruence counterexamples

Running the same check against the pre-fix semantics (`CONG_NO_FIX=1`, output
in `out-nofix/`) shows that the two halves of this deliverable are one thing:

| bound | non-singleton classes | which |
| --- | :-: | --- |
| A1, **pre-fix** | **10** | 8 × L-Unload (defect 4), 1 × O-Update {W2} (defect 4 downstream), 1 × CO-Acc {A8} (defect 2) |
| A1, post-fix | **0** | — |
| A2c, **pre-fix** | **2** | 1 × CO-Acc {A8} (defect 2), 1 × L-Iter {T1,T2,T4} (§4, not a defect) |
| A2c, post-fix | **1** | L-Iter {T1,T2,T4} only |

Two shapes are worth reading.

**`L-Unload {U1,U10,U3,U9}` and seven siblings, pre-fix** — two windows with
identical κ-images, one writing `stale = ⊤` into the successor and one writing
`stale = ⊥`:

```
κ = {U1, U3, U9, U10}
  result A: fire; emits {deactivated@self};
            θ ↦ Inactive(⊥), ω ↦ ⊥, acc unchanged, stale = ⊥
  result B: fire; emits {deactivated@self};
            θ ↦ Inactive(⊥), ω ↦ ⊥, acc unchanged, stale = ⊤
```

The alphabet has no letter for an incoming restart mark at L-Unload and, by
eq. 43, should not have one: the field is not part of the state the rule
writes. So either the alphabet owes a letter or the semantics owes a clear;
§3.4 shows the calculus says the latter, and the class becomes singleton.

**`CO-Acc {A8}`, pre-fix, three distinct results over 1,882 windows** — a read
at a name that is *not in the registry* answered `UNDECLARED_ACCESS`, or
`INACTIVE_ACCESS`, or **was served a value**, depending on what the dead record
still declared and what its dead parent chain still resolved:

```
κ = {A8}
  result A: refuse, reason UNDECLARED_ACCESS
  result B: refuse, reason INACTIVE_ACCESS
  result C: fire, served
```

κ_{A8} is a single scalar occurrence ("the read label's own premise fails"), so
this is as clean a congruence violation as the check can produce, and it is
defect 2 seen from the other side.

**Defects 1 and 3 do not show as splits.** Pre-fix, `update` at an absent name
was accepted *uniformly*, and `setval` was refused with the wrong reason
*uniformly*. Uniformly wrong is congruent. This is worth saying plainly,
because it bounds what the check does: it tests that the alphabet determines
the result, not that the result is the one the calculus prescribes. Those two
defects are caught by the other instrument — Definition 3 clause 1's comparison
of refusal reasons, realized as T*'s S-Upd-5 and S-Set-1 (§5).

---

## 4. The one residual gap

### 4.1 The counterexample

```
rule    L-Iter
κ       {T1, T2, T4}
30 windows, 2 distinct results, at bounds A2c, A2w, A3c and dep3
```

| | witness W | witness W′ |
| --- | --- | --- |
| access | `insert(root, P); L-Begin(P); L-Iter(P); L-Finish(P); insert(root, C); L-Begin(C)` | `insert(root, P); L-Begin(P); L-Iter(P); L-Finish(P); insert(root, CRR); L-Begin(CRR)` |
| component | `C := ({k1}, ∅, [track(a)])` | `CRR := ({k1}, ∅, [trackReadOnRevert(a, k1)])` |
| window | the first L-Iter window of the consumer: θ = Reloading, target = ω, iterator yields Just | same |
| κ | {T1, T2, T4} | {T1, T2, T4} |
| result | fire; emits {`apply@self`}; **acc: push(track⁻¹)** | fire; emits {`apply@self`}; **acc: push(read-on-revert)** |

Both are depth-6 windows in the graph; both are `StepClass = track` as far as
`Σ_{L-Iter}` can say. The difference is the *inverse class of h*, and it is
not cosmetic: it decides whether the fiber's teardown later emits
`revert:C:a` or `revertread:C:k1="v1"`, i.e. whether the L-Unload window that
consumes it presents **U6** or **U8**.

### 4.2 Why this is the alphabet's problem and not the model's

`../signatures.md` §5.1 gives L-Iter's step letters as nine of StepClass's
fifteen constructors, with

> | 4 | T4 | StepClass = track | step |

and Table 1's L-Iter row makes $g \circ h$ a write input, with $h$ the inverse
the iteration yields. Fixing $h$'s class is exactly what a step letter is for.
`trackReadOnRevert` is a *different* constructor of the same StepClass domain,
yielding a different InvClass value, and T4 covers both.

The audit already treats read-on-revert as a real InvClass value everywhere it
is **carried or applied**: **U8** at L-Unload (`signatures.md` §10.1),
**D11** at L-Divert and **X10** at L-Raise (its own §3.1.1 and §3.2.1 — GAP-9
was precisely "L-Raise's InvClass letters cover four of InvClass's five
values"). It letters it nowhere it is **created**. That asymmetry is the gap:
GAP-9's repair went to the consuming rules and never came back to the producing
one.

Call it **GAP-11**. The same conflation is latent at `trackMutate`, which T4
also swallows; the audit excludes that one as an artifact (its §2.2 item 2, "used
by no obligation and by no explorer catalog shape"), and no catalog shape
realizes it, so the check cannot see it. `trackReadOnRevert` is not excluded
anywhere — it is the A7 grammar extension the audit *accepts* at three rules.

### 4.3 The repair, and its cost

Two coherent repairs, and the audit's own A11 precedent picks between them.

**(a) Upward — split T4.** Add `T4′ : StepClass = track-with-read-on-revert
(the iteration yields an inverse that reads its committed key on revert; Def.
48 clause 2, A7 grammar extension)`. $|\Sigma_{\text{L-Iter}}|$ goes 11 → 12,
reachable 11 → 12. It needs no new canonical script: S-Div-7, S-Rai-8 and
S-Unl-6 all already drive a `trackReadOnRevert` step through an L-Iter window,
so the letter needs one added verdict clause, not a new experiment. Totals go
from 108/103/75 to **109/104/75**.

**(b) Downward — reject A7.** Declare `trackReadOnRevert` outside the §2.2 step
grammar, in which case T4 is complete — and X10, D11 and U8 must go with it,
taking S-Rai-8, S-Div-7 and S-Unl-6's U8 clause. That is −4 letters and −2
scripts, and it undoes GAP-9.

`../alphabet-audit.md` §4.4's A11 resolved the same kind of inconsistency
"**upward** … rather than **downward**", on the ground that the downward repair
moves coverage into other rules' scripts. Here the downward repair does not
even do that; it deletes coverage. (a) is the consistent choice.

**Machine-confirmed.** `--repair` implements (a). At every bound where the
split occurs, it closes:

| bound | classes without the repair | non-singleton | classes with T4′ | non-singleton |
| --- | ---: | :-: | ---: | :-: |
| A2c | 100 | 1 | 101 | **0** |
| A2w | 114 | 1 | 115 | **0** |
| A3c | 82 | 1 | 83 | **0** |
| dep3 | 83 | 1 | 84 | **0** |

With the repair the portfolio has **no non-singleton class at any rule at any
bound**.

`signatures.md` and `alphabet-audit.md` are owned elsewhere and are not edited
here; the letter, its finiteness argument (one more element of the finite
StepClass domain), its reachability (witnessed at four bounds, and by three
existing T* scripts) and its script accounting are stated above so the
integration pass can splice them.

---

## 5. Regression runs

All against the fixed `paper/proof/src/model.mjs`.

| suite | command | result |
| --- | --- | --- |
| 32-obligation suite, exhaustive schedules | `cd paper/proof && MODEL_EXHAUST=1 node --test tests/*.test.mjs` | **108/108 tests pass** (32 obligations) |
| T* characteristic suite vs. the reference model | `cd paper/formal/tstar && node run-tstar.mjs` | **75/75 scripts, 103/103 reachable letters** |
| characteristic-suite index check | `cd paper/proof && node run-characteristic.mjs` | **71/71** |
| mutant necessity | `cd paper/proof && node run-necessity.mjs` | baseline 32 green; **all 27 mutants killed** |
| the defect reproductions | `cd paper/formal/congruence && node defects.mjs` | **8/8** |

### 5.1 The fixes are not merely harmless — T* requires them

The T* suite carries the audit's post-closure scripts. Reverting the four
edits and re-running it is decisive:

| `paper/proof/src/model.mjs` | 32-obligation suite | T* |
| --- | :-: | :-: |
| pre-fix | 108/108 | **71/75**, 99/103 letters |
| fixed | 108/108 | **75/75**, 103/103 letters |

The four that fail without the fixes are exactly **S-Upd-4 (W5)**, **S-Upd-5
(W6)**, **S-Set-1 (P7)** and **S-Acc-2 (A8)** — one per defect, with defect 4
convicted through W5. S-Upd-3 (W4) passes either way, because the audit
deliberately stated its verdict over observables only and excepted the residue;
after the fix the exception is no longer needed.

The 32-obligation suite is unmoved in both directions, which is the audit's own
prediction: "None affects any pre-existing result: all three are at inputs the
32-obligation suite and the explorer's generator never make."

### 5.2 Observables that changed — stated loudly

**One quoted trace in `../alphabet-audit.md` is now wrong.** §3.4.4's script
**S-Upd-4** (letter W5) quotes

> `begin, provide, raise, deactivated, begin, divert, deactivated, begin, provide, raise, deactivated`
> — **three episodes from one input**, versus the four-event baseline

The middle episode was the spurious L-Divert of defect 4. After the fix the
trace is

> `begin, provide, raise, deactivated, begin, provide, raise, deactivated`
> — two episodes from one input, versus the four-event baseline

The *letter* W5 is unaffected — its content is that ζ is cleared before
L-Unload reads it, flipping the unload window U4 → U3 and re-enabling the
U10–U12 block, and that still happens. Only the count of episodes changes.
`alphabet-audit.md` is not mine to edit; the integration pass must update that
one sentence. (`tstar/verdicts.mjs` already asserts the two-episode reading,
which is why S-Upd-4 fails pre-fix.)

**Four quoted "the reference semantics does not…" observations are now
obsolete**, all of them in the audit's own voice as defects to be fixed:
§3.4.4's "The reference semantics does not refuse" (S-Upd-5), §3.6.5's
"`C=disposed; read(C,k1) -> threw INACTIVE_ACCESS`" (S-Acc-2), §3.7.3's
"`setval -> refused: cannot set "k1" without provide`" (S-Set-1), and §3.4.4's
"the reference semantics leaves the mark set on the removed record" (S-Upd-3).
Each now matches the specification decision the audit itself states. The audit's
§6 defect list and §2.2 artifact item 13 are discharged.

**`../scratch-audit/verify-scripts.mjs` will print different output** for
S-Upd-3, S-Upd-4, S-Upd-5, S-Set-1 and S-Acc-2. That file is another
deliverable's and was not edited.

**Nothing in `../paper.md` changes.** The manuscript's numbers are pre-closure
(92/86/60) and cite none of these five observations; the state-space counts it
reports are the explorer's, and `explorer/` was not modified. The reference
semantics' own state count *does* change (e.g. 614 → 588 normalized states at
1 fiber, all shapes), because the surviving restart mark had been generating
distinct states; if a future integration re-runs the explorer against the fixed
semantics, its state counts will drop and its signature set will lose the
tuples that only the residue reached.

### 5.3 One further finding, reported and not fixed

`Model.retire` accepts a name not in $\mathrm{dom}(F_\gamma)$ and silently sets
`retired = true` on a removed record — the same shape as defect 1, at the one
input whose registry premise [SZC26] states *explicitly* (p. 31, p. 32).
`../alphabet-audit.md` §1.1 lists R4 as a premise-derived letter, which implies
refusal; the model does not refuse.

It is **not fixed here**, deliberately and for one reason: Def. 47 makes an
O-Retire the inverse a registration yields, and p. 32 argues that inverse must
apply "wherever it is reached" — so adding a refusing premise to `retire` would
have to be reconciled with the registration inverse, which is a design decision
about Def. 47 and not a bug fix. The congruence check does not convict it
(κ_{R4} has one result: accept, no observable change), and no suite exercises
it. Recorded for the integration pass.

---

## 6. What this establishes, and what it does not

The check is a **bounded, semantic, single-implementation** result, and each of
those three words limits it.

**Bounded.** The property verified is: for every rule $r$, over the windows
reachable within this portfolio's bounds, κ_r determines the per-occurrence
result. It is not "over all reachable windows". The evidence that the bound is
not the binding constraint is circumstantial and should be read as such: at
seven of nine bounds the last new κ-class arrived with millions of windows
still to go; 114 of the 118 classes are reached by at least two different runs;
and the largest untruncated run (sat3, 235 k states, 4.9 M windows) found its
last class after 5 % of its window stream. That is saturation, not exhaustion.
The audit's §5 layer 2 names what would replace it: a cut-off theorem of the
form "no window class first appears above $b$ fibers", which would convert the
explorer from corroboration into a decision procedure at the bound — the same
missing lemma, now with one more thing riding on it.

**Over the reference semantics, not over arbitrary implementations.** This is
the sharpest limitation and the easiest to misread. κ_r-congruence is a
property of a *pair* — a normalization and a semantics — and what is checked
here is that pair. It says the specification's own rule behaviour factors
through κ. It says nothing directly about any $\mathbb I \in \mathfrak
I_{\mathrm{CF}}$: for an implementation, CF3 *postulates* that its behaviour
factors through the occurrence (that is what "$f_r^{\mathbb I}$ is a function
of the occurrence" means), and Theorem 1 is precisely the result that this
postulate cannot be tested. What the check does for the theorem is different
and narrower, and it is the thing that was actually missing: **it establishes
that the alphabet is fine enough for the factorization to be satisfiable at
all.** If two κ-equal specification windows had different specification
results, then no implementation agreeing with the specification could factor
through κ — CF3 would be unsatisfiable by $\mathbb S$ itself, Theorem 3's
factorization claim would be false, and the canonical experiments indexed by
those letters would be pinning something incoherent. That is the failure mode
ruled out here, at a bound, for the first time.

**It validates granularity, which is what the Transport Lemma's hypothesis
really is.** Lemma 4 says per-occurrence decisions transport along κ-equality,
and whole-rule results along κ-equality plus frame correspondence. Its proof
(§6.2 clause (2)) reads the correspondence of decision families off (D-A) — the
premise that the alphabets "cover exactly the guard atoms and write inputs" of
each row. (D-A) is an *interface obligation*: a claim about what the tables
cover, discharged in Appendix D by argument. κ_r-congruence is the same claim
with the argument replaced by a checkable statement about a function, and it is
the form in which the lemma consumes it. Every gap the audit found is a
counterexample to it as the tables stood; that no counterexample survives the
closure, over 32.6 M windows and 13 rules, is the first evidence for (D-A) that
is not itself an argument about coverage.

**What it does not touch.** (i) The frame half of Lemma 4 — clause (3), the
`lift_r` reconstruction — is not verified; it is *corroborated* only in the
negative sense that the 44 level-2 splits are frame data and nothing else, so
the frame carries what the paper says it carries and no more. (ii) The
observation-reflection lemma, the safety argument and termination are
untouched. (iii) Nothing here bears on the interface-scope proviso (the audit's
§5 layer 4, GAP-10, A12–A14, A16b): κ-congruence over
$\Lambda_{\mathrm{orch}}$ says nothing about a wider interface, and widening it
would require re-running this check, which the artifact makes cheap. (iv) The
abstraction folds of §2.3 — role-naming, per-key class folding, value dropping,
the write-not-change encoding — are each tied to a clause, but they are
judgements, and a fold that is too coarse would hide a counterexample. They
are the artifact's own attack surface, and the most useful next thing anyone
could do to it is to try to make one of them too coarse and see what appears.

The honest one-line form: **at three fibers and thirty-two million windows,
over the reference semantics and the audit's closed alphabets, κ_r is a
congruence for the per-occurrence result at every rule — after one further
letter, T4′, that the check itself found to be owed.**
