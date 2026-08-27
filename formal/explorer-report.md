# D3 — Explorer report (executable grounding)

Deliverable D3 of `MASTER.md`: a true all-successor state-space explorer over
the reference semantics (`../proof/src/model.mjs`), its normalized reachable
signature tables, the generated bounded suite `T_B`, the audit of the
existing 32-test suite, and the deviant (mutant) check of the generated
suite. All code lives in `explorer/`; all machine-readable outputs in
`explorer/out/`.

Contents:

1. [Artifact layout and how to reproduce](#1-artifact-layout)
2. [Normalization](#2-normalization)
3. [The orchestration-input generator and its finiteness](#3-generator)
4. [Bounds: infeasibility of B0 and the explored portfolio](#4-bounds)
5. [Exploration results](#5-results)
6. [Per-rule reachable signature tables](#6-signatures)
7. [T_B generation](#7-tb)
8. [Audit of the 32 tests; uncovered signatures](#8-audit)
9. [Deviant check: generated-suite kill matrix](#9-kill)
10. [Scoping decisions and deviations (complete log)](#10-scoping)
11. [Reconciliation with D1's 86 reachable signatures](#11-reconcile)
12. [Limitations: what the bound excludes](#12-limitations)

---

## 1. Artifact layout

| file | role |
| --- | --- |
| `explorer/model.mjs` | instrumented COPY of `../proof/src/model.mjs` (the proof tree is untouched); adds certificate hooks, rule-name tags, serializable inverse payloads, per-fiber removal helpers — the diff against the reference is instrumentation-only (verified by diff during development; every guard, mutant branch and trace string is identical) |
| `explorer/sig.mjs` | canonical signature keys for certificates |
| `explorer/norm.mjs` | snapshot / canonicalize (χ-normal form) / materialize |
| `explorer/catalog.mjs` | the finite component-shape catalog = the orchestration-input generator |
| `explorer/explore.mjs` | all-successor BFS, dedup on normal forms, LTS + signature extraction |
| `explorer/run-explore.mjs` | driver; emits `out/signatures-<tag>.{json,md}`, `out/tb-<tag>.json` |
| `explorer/runner.mjs` | T_B script replay + full settle-outcome sets (reports, events, certificates, divergence) |
| `explorer/kill-tb.mjs` | generated-suite kill matrix over the 27 mutants |
| `explorer/audit-32.mjs`, `redirect-loader.mjs`, `register-audit.mjs` | instrumented execution of the untouched 32-test proof suite |
| `explorer/coverage.mjs` | coverage matrix + uncovered-signature computation |
| `explorer/selftest-norm.mjs` | normalization self-test (random renamings) |

Reproduction:

| `explorer/reconcile.mjs` | D3 ↔ D1 vocabulary reconciliation (§11); emits `out/reconcile.{json,md}` |
| `explorer/c1-check.mjs` | reproduces correction C1 — signatures.md's S-Div-3 script is refused by declared disjointness (§11.6); exits 0 iff it reproduces |

Reproduction (tags as actually run; every number in this report cites one of
these artifacts):

```bash
cd paper/formal/explorer
node selftest-norm.mjs

# --- T_B-generating portfolio (complete, untruncated runs) ---------------
node run-explore.mjs --tag=A1    --maxFibers=1 --maxStates=500000 --timeBudgetMs=900000
node run-explore.mjs --tag=A2c   --maxFibers=2 --noUpdates --noSetowns --maxStates=2500000 --timeBudgetMs=2100000
node run-explore.mjs --tag=dep3  --maxFibers=3 --shapes=P,M,CC,CRR --maxStates=900000 --timeBudgetMs=1500000
node run-explore.mjs --tag=fail3 --maxFibers=3 --shapes=P,FP,C    --maxStates=900000 --timeBudgetMs=1500000
node run-explore.mjs --tag=regB  --maxFibers=3 --shapes=P,A --noChildInserts --noUpdates --noSetowns --maxStates=900000 --timeBudgetMs=900000
# regA is the SAME bound as regB with the full input set; it TRUNCATES (see §5).
node run-explore.mjs --tag=regA  --maxFibers=3 --shapes=P,A --maxStates=900000 --timeBudgetMs=1500000

# --- corroboration runs (truncated; not used to generate T_B) ------------
node run-explore.mjs --tag=A2w --maxFibers=2 --maxStates=2500000 --timeBudgetMs=2100000
node run-explore.mjs --tag=A3c --maxFibers=3 --noUpdates --noSetowns --maxStates=2500000 --timeBudgetMs=2100000

# --- saturation probes ----------------------------------------------------
node run-explore.mjs --tag=sat2 --maxFibers=2 --shapes=P,C --maxStates=900000
node run-explore.mjs --tag=sat3 --maxFibers=3 --shapes=P,C --maxStates=900000

# --- analysis -------------------------------------------------------------
node audit-32.mjs
node coverage.mjs  out/signatures-{A2c,dep3,fail3,regA,regB,A1}.json
node kill-tb.mjs   out/tb-{A2c,dep3,fail3,regA,regB,A1}.json
node reconcile.mjs out/signatures-{A2c,dep3,fail3,regA,regB,A1,A2w,A3c}.json
node ../../proof/run-necessity.mjs   # hand-suite matrix (runs the proof tree unmodified)
```

## 2. Normalization

A configuration is snapshotted into a plain-data record (per fiber: spec
structure, config class, parent link, isolation entries, lifecycle state,
retirement/removal/stale flags, outcome class, committed view, iterator
position, accumulator entry list, store table) and canonicalized:

- **Fiber renaming by deterministic traversal**: every permutation of the
  (≤ 6, see §4) kept fibers is serialized; atoms are renamed in
  first-encounter order along that serialization; the lexicographically
  smallest string is the canonical form. Because the atom renaming is a
  function of the permutation and the walk is deterministic, this is a true
  canonical representative of the orbit under fiber-renaming × atom-renaming
  (χ-equivalence), not a heuristic.
- **Atom classes renamed**: component names (excluded from spec
  serialization entirely), keys `K0,K1,…`, values `V0,…`, tags `T0,…`,
  isolation realm labels `R0,…`. Shared-realm store labels
  (`realm#root:<key>`) are represented through the renamed key, so a state
  using only `k2` normalizes identically to the same state using only `k1`.
- **Dropped from the normal form**: the trace (history, not state); removed
  fibers, unless still referenced by a kept fiber's committed view, parent
  link, or registration inverse (baseline semantics never leaves such
  references; mutants can, and the runner keeps them); the
  `everUnsatisfied` latch (read only by the `refresh-misses-pending`
  mutant; carried in records, included in identity only for mutant
  executions).

**Self-test** (`selftest-norm.mjs`, all green): a scenario state — three
components including isolation, a mid-teardown accumulator and committed
views — is rebuilt under 23 random/adversarial renamings of every atom class
with permuted insertion order; all canonicalize to the same string; a
semantically different state does not; `materialize(snapshot(m))`
round-trips and behaves identically under `sweep()`.

## 3. The orchestration-input generator and its finiteness {#3-generator}

At every state the explorer offers, besides every enabled lifecycle rule at
every fiber and every eligible single-fiber removal (both dimensions of
internal nondeterminism):

- `insert(shape, root)` for each of the 19 catalog shapes (`catalog.mjs`),
  when the live-fiber cap admits the shape's weight (1, or 2 for the
  registrar shapes whose activation registers a child);
- `insert(P | CR, isolated)` under the context `isolate(k1, r1)`;
- `insert(T, child-of(f))` under each live fiber's context;
- `retire(f)` for each live non-retired fiber;
- `update(f, {ok:true})` for each live fiber;
- `setown(f, k1, v2)` for each live fiber (refusal = the foreign-binding
  occurrence of the Def. 23 value operation).

**Finiteness.** The catalog is a fixed finite list; keys are drawn from
{k1,k2}, values from {v1,v2}, tags from {a,b}, realms from {root, r1},
configs from {∅, {ok:true}}. Hence at any state the action alphabet is
bounded (≤ 19 + 2 + 4 + 3·4 internal/external actions ≈ 45), and every field
of a configuration ranges over a finite set: fiber count is capped, each
fiber's spec is one of finitely many shapes, its iterator position is a
suffix index of a ≤3-step program, its accumulator a ≤3-element list over
finitely many entry classes, tables/views are maps over the finite key/realm
alphabet. The normalized state space at any of the explored bounds is
therefore finite, and the BFS terminates without truncation for every run
in the final portfolio (§4).

**Why a shape catalog rather than all step sequences ≤ 5**: occurrence
signatures are guard-atom valuations, step-constructor classes and equality
patterns on finite support (Def. 3); they do not count steps. The catalog
was chosen to realize every step class in every relevant key-relation
pattern (fresh/conflicting provide, committed/ancestor/inactive/undeclared/
withdrawn reads, own-eq/own-neq/foreign setval, register at depth 2, raise
with each accumulator class, flag pass/fail), plus the shapes needed for
guard witnesses (providers, chain middles, two-key consumers, read-on-revert
teardown witnesses, a two-track shape for the binary inverse-composition
order pattern). Enumerating all raw step sequences of length ≤ 5 over the
step alphabet would multiply the insert alphabet by ~10^5 without adding
occurrence classes; this is a deliberate, logged scoping decision (§10,
S1).

## 4. Bounds: infeasibility of B0 and the explored portfolio {#4-bounds}

MASTER's default working bound is B0 = (N_f=4, N_k=2, values {v1,v2,⊥,ξ},
N_s=5, N_d=2). Keys, values, step counts and register depth are respected
exactly as stated. The fiber dimension at the FULL generator is not
exhaustively explorable: measured growth of the normalized space
(all-successor, post-normalization dedup):

| generator | N_f = 2 | N_f = 3 | N_f = 4 |
| --- | --- | --- | --- |
| `{P,C}` (2 shapes) | 7,150 (`sat2`, 1.0 s) | 277,063 (`sat3`, 1.6 m) | ~10⁷ (extrapolated ×38.8/fiber) |
| `{P,A}` + updates/setowns | — | ≥ 631,538, **truncated** (`regA`) | — |
| full 19-shape catalog, no upd/own | 30,765 (`A2c`, 2.1 s) | ≥ 2,337,816, **truncated** (`A3c`) | infeasible |
| full 19-shape catalog + upd/own | ≥ 2,500,001, **truncated** (`A2w`) | infeasible | infeasible |

The measured per-fiber factor is **38.8×** (`sat2` → `sat3`, both exhaustive:
7,150 → 277,063). Extrapolating from the full catalog's exhaustive N_f = 2
point (`A2c`, 30,765) gives ≳ 10⁶ at N_f = 3 and ≳ 10⁹ at N_f = 4 — and the
truncated `A3c` run, which reached 2.34 M states at N_f = 3 without
finishing, is consistent with that. Full-generator N_f = 4 is infeasible on
this machine (≈ 6 × 10³ states/s single-threaded; ≈ 3 × 10³/s once `update`
and `setown` widen the alphabet).

Per MASTER's instruction the bound was reduced minimally and the reduction is
logged, not hidden. The deliverable explores a **portfolio** whose union of
reachable-signature sets is reported. Five of its six runs are exhaustive
(untruncated) explorations of their declared bound; the sixth (`regA`) is
truncated and is paired with an exhaustive twin at the same bound (`regB`):

| run | generator | N_f | exhaustive? | rationale |
| --- | --- | --- | --- | --- |
| `A1` | full 19-shape catalog, all input kinds | 1 | yes | every single-component occurrence including `update`/`setown`; the only run reaching `L-Iter flag-pass` |
| `A2c` | full 19-shape catalog, no upd/own | 2 | yes | every pairwise shape interaction (conflicts, provider/consumer, declared conflicts, isolation joins) |
| `dep3` | `{P, M, CC, CRR}` | 3 | yes | dependency chains of depth 2, transitive reliance, mixed per-key satisfaction, teardown reads |
| `fail3` | `{P, FP, C}` | 3 | yes | failing provider among dependents, ξ-outcome interactions at 3 fibers |
| `regB` | `{P, A}`, no child-inserts/upd/own | 3 | yes | registration cascades, ancestry-walk reads, child-retire inverses — the exhaustive twin of `regA` |
| `regA` | `{P, A}`, all input kinds | 3 | **no** (time budget) | the same bound with updates/setowns; contributes 2 signatures nothing else reaches (§6) |

**There is no N_f = 4 run.** MASTER's B0 fiber dimension is *not* met by any
run in this deliverable; the largest exhaustive bounds are N_f = 2 on the
full catalog (`A2c`) and N_f = 3 on restricted generators. This is the single
largest deviation from B0 and is logged as S2.

Signature saturation supports the portfolio's adequacy empirically: raising
`{P,C}` from N_f = 2 to N_f = 3 — a 38.8× state-space growth — added 12
signature *tuples*, all of them `A-Set` records differing only in the
`dependents` field, which project onto **zero** new occurrence classes
(§5.3, §11.2). The same holds at much larger scale for `A2w` and `A3c`: zero
new signatures of any kind (§5.2).

Note on the cap: the insert cap counts live fibers and shape weight; a
registrar admitted at the cap can still push the transient live count to
N_f+2 while its child registers before another fiber unloads — the
normalizer and PERM tables handle up to 8 fibers.

## 5. Exploration results {#5-results}

All figures below are read from `out/signatures-<tag>.json` → `.stats`
(`normalizedStates`, `expandedStates`, `edges`, `refusalEdges`,
`quiescentStates`, `wallClockMs`, `truncated`). "sigs" is the number of
distinct (rule, decision, field-record) keys the run witnessed.

| run | shapes | N_f | upd | own | normalized states | expanded | edges | refusal edges | quiescent | wall clock | truncated | sigs |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| `A1` | full 19 | 1 | y | y | 614 | 614 | 2,100 | 345 | 49 | 0.1 s | no | 76 |
| `A2c` | full 19 | 2 | n | n | 30,765 | 30,765 | 92,343 | 199 | 463 | 2.1 s | no | 87 |
| `dep3` | P,M,CC,CRR | 3 | y | y | 558,748 | 558,748 | 5,495,264 | 1,031,008 | 1,729 | 3.6 m | no | 104 |
| `fail3` | P,FP,C | 3 | y | y | 688,484 | 688,484 | 6,943,826 | 1,255,740 | 729 | 4.7 m | no | 88 |
| `regB` | P,A | 3 | n | n | 19,707 | 19,707 | 87,654 | 434 | 46 | 20.9 s | no | 49 |
| `regA` | P,A | 3 | y | y | 631,538 | 407,815 | 4,886,365 | 959,173 | 320 | 25.0 m | **yes** | 98 |
| `A2w` | full 19 | 2 | y | y | 2,500,001 | 1,806,058 | 20,063,988 | 5,348,285 | 2,941 | 33.0 m | **yes** | 133 |
| `A3c` | full 19 | 3 | n | n | 2,337,816 | 2,034,542 | 9,334,269 | 15,804 | 3,968 | 35.0 m | **yes** | 89 |
| `sat2` | P,C | 2 | y | y | 7,150 | 7,150 | 47,719 | 7,350 | 97 | 1.0 s | no | 73 |
| `sat3` | P,C | 3 | y | y | 277,063 | 277,063 | 2,760,383 | 490,532 | 453 | 1.6 m | no | 85 |

**Total normalized states explored across all ten runs: 7,051,886**; no run
reported `internalCycle`.

### 5.1 Which runs generate T_B, and why

`T_B` and the coverage matrix are computed from the **six-run portfolio**
`{A2c, dep3, fail3, regA, regB, A1}` (this is the argument list recorded in
`out/coverage.json` → `sigFiles` and `out/kill-tb.json` → `files`). Their
union is **146 distinct signatures**.

Four of the six are complete (untruncated) exhaustive explorations of their
declared bound. **`regA` is truncated** — it hit its 25-minute time budget
after expanding 407,815 of 631,538 discovered states (`stats.truncated =
true`). This is disclosed rather than hidden, and it is why `regB` exists:
`regB` is the *same* bound (N_f = 3 over `{P,A}`) with child-inserts,
`update` and `setown` switched off, which completes in 20.9 s and is
exhaustive. `regA` therefore contributes only *positive* witnesses (every
signature it found is genuinely reachable — a truncated BFS is sound for
reachability, merely incomplete), while `regB` supplies the completeness
guarantee for the registration theme at that bound.

### 5.2 Fate of the two long runs `A2w` and `A3c` (scoping decision S13)

Two further explorations were launched at the largest bounds this machine
could attempt and were left running:

- **`A2w`** — full 19-shape catalog at N_f = 2 with `update` *and* `setown`
  enabled (i.e. `A2c` plus the two external value operations). It hit the
  2,500,000-state cap after 33 minutes with 1,806,058 states expanded.
- **`A3c`** — full 19-shape catalog at N_f = 3 without updates/setowns
  (i.e. `A2c` lifted one fiber). It hit its 35-minute time budget with
  2,034,542 of 2,337,816 states expanded.

**Decision: harvested, and kept out of the T_B basis.** Both completed
normally and wrote `out/signatures-{A2w,A3c}.json` and `out/tb-*.json`, so
there was nothing to kill. Both are truncated, so neither can support a
*negative* (unreachability) claim, and admitting them to the T_B basis would
buy nothing while weakening the "every generating run is exhaustive or
paired with an exhaustive twin" property. They are reported instead as
**corroboration**, and what they corroborate is strong:

> Across `A2w` (1.81 M states expanded), `A3c` (2.03 M), `sat2` and `sat3`,
> the number of signatures **new** to the six-run union is **zero** in every
> case.

That is 3.8 M additional expanded states — at the largest fiber bound and
the widest input alphabet attempted — producing not one occurrence class the
portfolio had already missed. The 146 is stable under every enlargement of
the bound that was computationally reachable here.

### 5.3 Saturation probes

`sat2` / `sat3` isolate the fiber dimension on a fixed 2-shape generator:

| | N_f = 2 (`sat2`) | N_f = 3 (`sat3`) | growth |
|---|---|---|---|
| normalized states | 7,150 | 277,063 | **38.8×** |
| wall clock | 1.0 s | 1.6 m | 94× |
| signatures | 73 | 85 | +12 |

The 38.8× per-fiber state growth is the measurement that makes the full
generator at N_f = 4 infeasible (§4). The +12 signatures are **not** twelve
new occurrence classes: all twelve are `A-Set fired {binding:"own", …}`
records differing only in the `dependents` field (the multiset of lifecycle
states of fibers relying on the key), which needs three live fibers to
populate. Under the §11 projection α they collapse onto `P3`, already
witnessed at N_f = 2. In the hand analysis's vocabulary the probe saturates
exactly as MASTER's reachability argument predicts: **0 new letters.**

## 6. Per-rule reachable signature tables {#6-signatures}

Machine-readable: `out/signatures-<run>.json`; human-readable per-run tables
in `out/signatures-<run>.md`. The union table is summarized here.

Union over the six-run portfolio (`out/coverage.json` → `reachableCount`):
**146 signatures**, distributed by rule and by certificate decision:

| rule | fired | refused | disabled | total | covered by the 32 tests | uncovered |
|---|---|---|---|---|---|---|
| O-Insert | 6 | 1 | 0 | 7 | 4 | 3 |
| O-Retire | 10 | 0 | 0 | 10 | 2 | 8 |
| O-Remove | 2 | 0 | 7 | 9 | 2 | 7 |
| O-Update | 6 | 0 | 0 | 6 | 2 | 4 |
| L-Begin | 2 | 0 | 5 | 7 | 6 | 1 |
| L-Iter | 11 | 0 | 0 | 11 | 8 | 3 |
| L-Raise | 5 | 0 | 0 | 5 | 2 | 3 |
| L-Finish | 6 | 0 | 0 | 6 | 6 | 0 |
| L-Divert | 12 | 0 | 0 | 12 | 1 | 11 |
| L-Leave | 2 | 0 | 1 | 3 | 3 | 0 |
| L-Unload | 27 | 0 | 4 | 31 | 12 | 19 |
| A-Set | 30 | 5 | 0 | 35 | 2 | 33 |
| A-Read | 4 | 0 | 0 | 4 | 3 | 1 |
| A-Intercept | 0 | 0 | 0 | 0 | — | — |
| **total** | **123** | **6** | **17** | **146** | **53** | **93** |

`A-Intercept` has **zero** LTS occurrences: `interceptMerged` is a pure
derived operation that no transition invokes (log S7). Its occurrence is
supplied by a coda test, not by graph search.

Per-run tables, with the BFS depth at which each signature first appears and
how many times it occurred, are in `out/signatures-<tag>.md`; the machine-
readable form (including the first-witness state and action) is
`out/signatures-<tag>.json`.

**Why a portfolio and not a single run.** No single explored bound witnesses
all 146. `A2c` — the widest shape alphabet — witnesses only 11 of the 13
rules, because `update` and `setown` are disabled in it (so no `O-Update`,
no `A-Set`); the same holds for `regB`. Conversely `dep3`, `fail3`, `regA`
and `A1` all witness `A-Set` but over generators of only 2–4 shapes.

Counting signatures witnessed by **exactly one** run makes the dependency
concrete: **15 of the 146** have a single witness —

| sole witness | signatures |
|---|---|
| `A2c` | 7 |
| `dep3` | 4 |
| `regA` | 2 |
| `A1` | 2 |

Two consequences worth stating plainly. First, dropping `A2c` or `dep3`
would lose signatures outright, so the portfolio is not redundant padding.
Second, **two of the 146 are witnessed only by `regA`, the truncated run** —
they are sound positive witnesses (a truncated BFS still only reports states
it actually reached), but they are the one place where the union depends on a
run that did not finish. `regB` does not recover them, because they involve
inputs `regB` disables. The two are:

```
L-Divert fired {acc:["retire"],trigger:"stale"}
L-Unload fired {acc:["retire"],obs:[],outcome:"bot",postTarget:"sat",relied:false,retired:false}
```

— both require a `register`-inverse accumulator entry (`acc:["retire"]`,
available only from the registrar shape `A`) *together with* an `update`
(`trigger:"stale"`) or a satisfiable post-target, i.e. exactly the
`{P,A}` × updates combination that only `regA` offers. Both are ordinary
positive witnesses with a replayable access sequence in `out/tb-regA.json`;
the truncation affects only what `regA` might have *missed*, never what it
found.

## 7. T_B generation {#7-tb}

For every reachable (rule, signature) pair, `run-explore.mjs` emits one test
into `out/tb-<run>.json`:

- **access sequence**: the BFS-shortest path (orchestration inputs +
  scheduler-resolved lifecycle micro-steps, fiber references resolved
  χ-invariantly through re-canonicalization at replay time) from the empty
  registry to the state where the occurrence is enabled, followed by the
  occurrence's own action (omitted for `disabled` occurrences — the
  observation is that the rule must NOT fire there);
- **distinguishing observation**: the complete specification outcome data at
  that point — per-action refusals, emitted events and certificates along
  the script, then the full settle-outcome set from the final state: the set
  of normalized quiescent reports over ALL internal schedules (true
  successor enumeration with concrete-identity dedup and cycle detection),
  the set of reachable settle events, the set of reachable settle
  certificates (fired and disabled — the `cert(r, ŝ, â)` observable of
  PAPER_REWRITE §2.3), and the divergence flag.

Two coda tests fall outside the graph by construction and are appended
explicitly (log entries S6, S7): the O-Insert-under-removed-parent refusal
(canonical states drop unreferenced removed fibers, so no graph state can
offer that input) and the depth-2 intercept-chain resolution (Def. 31 is a
pure derived operation that no LTS transition invokes).

### 7.1 Size and composition

`out/kill-tb.json` → `testCount`: **|T_B| = 150 tests**, merged from the six
`out/tb-<tag>.json` files and deduplicated by signature (first file wins, so
the shortest-bound witness is preferred). The composition is exact:

| | count |
|---|---|
| graph tests — one per reachable signature | 146 |
| coda tests (outside the LTS by construction) | 4 |
| **total** | **150** |

The correspondence with §6 is one-to-one and was checked both ways: every one
of the 146 reachable signatures has exactly one T_B test, and the only T_B
signatures absent from the reachable union are the four coda tests. There is
no signature in T_B without a witness and no witnessed signature without a
test.

Provenance after dedup — which run supplied each test — shows the same
portfolio dependency as §6:

| source | tests contributed |
|---|---|
| `tb-A2c` | 91 |
| `tb-dep3` | 55 |
| `tb-regA` | 2 |
| `tb-A1` | 2 |

Script lengths: min 1 action, median 6, max 15, **1,000 actions in total**
across the suite. Baseline reproduction is exact: `out/kill-tb.json` →
`baselineBad = 0`, i.e. all 150 recorded observations replay identically
against the unmutated model.

### 7.2 The four coda tests

| id | signature | why it cannot come from the graph |
|---|---|---|
| `TB.88` | `O-Insert refused {parent:"removed",…}` | normalization erases unreferenced removed fibers, so no *canonical* state retains the removed parent to insert under (log S6). Addressed by raw uid via the `child-uid` action form. |
| `TB.89` | `A-Intercept fired {entries:2}` | `interceptMerged` is a pure derived operation; no LTS transition invokes it (log S7). |
| `TB.90` | `A-Read fired {cls:"inactive-declared-np"}` | the *external* Def.-23 read (`readVia`) on a declared-but-uncommitted fiber. In-lifecycle reads always run under a committed view total on the declared keys, so the graph cannot produce this class — see §11.4. |
| `TB.91` | `A-Read fired {cls:"inactive-declared-p"}` | as `TB.90`, with an Active provider present for the key (the `-p` witness). |

### 7.3 Sample entries

Shortest test in the suite (`TB.1`, from `out/tb-A2c.json`):

```json
{ "id": "TB.1",
  "sig": "O-Insert fired {declaredConflict:false,parent:\"root\",realm:\"root\"}",
  "script": [ {"t":"insert","shape":"P","ctx":"root"} ],
  "expected": {
    "perAction": [ { "refused": false, "emissions": [],
                     "certs": ["O-Insert fired {…parent:\"root\"…}"] } ],
    "settle": { "reports": ["{\"fibers\":{\"1\":\"active\"},\"store\":{…}}"],
                "diverged": false, "settleEvents": [ … ], "settleCerts": [ … ] } } }
```

A mid-length test showing the scheduler-resolved micro-steps (`TB.23`,
`L-Divert` with an empty accumulator on a ⊥ target):

```json
"script": [ {"t":"insert","shape":"P","ctx":"root"},
            {"t":"life","f":0,"rule":"L-Begin"},
            {"t":"retire","f":0},
            {"t":"life","f":0,"rule":"L-Divert"} ]
```

The longest class of test threads two fibers through a provider withdrawal
(`TB.85`, 11 actions, kills 15 of the 27 mutants):

```json
"script": [ {"t":"insert","shape":"P","ctx":"root"},
            {"t":"life","f":0,"rule":"L-Begin"}, {"t":"life","f":0,"rule":"L-Iter"},
            {"t":"life","f":0,"rule":"L-Finish"},
            {"t":"insert","shape":"M","ctx":"root"},
            {"t":"life","f":0,"rule":"L-Begin"}, {"t":"life","f":0,"rule":"L-Iter"},
            {"t":"retire","f":1}, {"t":"life","f":1,"rule":"L-Leave"},
            {"t":"life","f":0,"rule":"L-Divert"}, {"t":"life","f":0,"rule":"L-Unload"} ]
```

Note the `f` indices are *canonical positions*, not fiber names: the runner
re-canonicalizes its concrete state before each action and resolves the
position through the permutation (`runner.mjs: resolveFiber`), which is what
makes the scripts χ-invariant and replayable under mutants that alter fiber
creation order.

## 8. Audit of the 32 tests; uncovered signatures {#8-audit}

`audit-32.mjs` runs each named scenario of `../proof/tests/*.test.mjs` in
its own process against the instrumented semantics (a `node --import`
resolve hook substitutes `explorer/model.mjs` for `proof/src/model.mjs` at
load time — the proof tree is byte-identical throughout). Each test's
exercised (rule, signature) pairs — fired, refused and disabled — are
recorded with the same signature keys the explorer uses. All 32 scenarios
run green under instrumentation.

### 8.1 Headline

From `out/coverage.json` (recomputed and byte-identical on re-run):

| quantity | value |
|---|---|
| reachable signatures (union of the six-run portfolio) | **146** |
| exercised by at least one of the 32 tests | **53** (36.3 %) |
| **uncovered** | **93** (63.7 %) |
| exercised by a test but *outside* the reachable set | 11 |
| tests exercising zero reachable signatures | 0 |

All 32 scenarios run green under instrumentation. The audit records 64
distinct signatures in total (`out/audit-32.json`), of which 53 lie inside
the explorer's reachable set and 11 outside it.

### 8.2 The 11 "outside-set" signatures — a coverage result in reverse

These are exercised by the hand suite but never produced by the explorer.
They are *not* explorer errors; each has a specific cause, and two of them
are the strongest evidence in the report that the hand suite reaches places
the graph cannot:

| signature | cause |
|---|---|
| `O-Insert refused {parent:"removed",…}` | log S6 — erased by normalization; the graph offers it only as coda `TB.88`. |
| `A-Intercept fired {entries:2}` | log S7 — no LTS transition invokes `interceptMerged`; coda `TB.89`. |
| `A-Read fired {cls:"inactive-declared-p"}` | **the external Def.-23 access surface** — see §11.4. Exercised by `C5.3 declared-inactive-access`. |
| `L-Finish fired {acc:["provide","rrev"]}` | accumulator combination needing a shape that both provides and read-on-reverts. |
| `L-Finish fired {acc:["retire","track"]}` | registrar that also tracks. |
| `L-Raise fired {acc:["provide","track"],stepClass:"raise"}` | raise after both a provide and a track. |
| `L-Raise fired {acc:["track"],stepClass:"flag-fail"}` | `raiseUnless` failing after a track. |
| 4 × `L-Unload fired {…}` | four accumulator/`obs`/outcome combinations (`["provide","rrev"]`, `obs:["track","track"]` with `acc:["provide","track"]`, `xi` with a satisfiable post-target, `["retire","track"]`). |

Seven of the eleven are **catalog gaps, not bound gaps**: the 19-shape
catalog has no single component that both provides *and* read-on-reverts, or
both registers *and* tracks, so those accumulator multisets are unreachable
at *any* fiber bound with this generator. This is the concrete cost of
scoping decision S1 (shape catalog instead of raw step-sequence enumeration),
and it is measurable rather than hypothetical: **the hand suite covers 7
occurrence combinations the generator structurally cannot emit.** Widening
the catalog with two composite shapes (`provide+rrev`, `register+track`)
would close them.

### 8.3 Per-test coverage matrix

Each test's count of exercised reachable signatures (`out/coverage.json` →
`matrix`; full per-signature lists there and in `out/coverage.md`):

| test | reachable sigs | outside-set | | test | reachable sigs | outside-set |
|---|---|---|---|---|---|---|
| R3.1 removal-follows-inactivity | 18 | 0 | | R1.2 insert-under-removed-parent-rejected | 10 | 1 |
| R9.1 withdrawal-guard-orders-teardown | 18 | 0 | | R2.1 retire-runs-recovery | 10 | 1 |
| M3 provider-identity-coherence | 18 | 0 | | R5.1 iteration-order-and-lifo-recovery | 10 | 0 |
| R6.1 divert-honors-target-change | 16 | 0 | | C3.1 isolation-independence | 10 | 0 |
| R9.2 recovery-exactness-on-deactivation | 16 | 0 | | R4.2 provider-arrival-wakes-pending | 9 | 0 |
| M2 dependency-ordering-chain | 16 | 0 | | C2.1 overwrite-observability-dichotomy | 9 | 0 |
| M5 confluence-across-histories | 16 | 0 | | R1.3 dynamic-provision-conflict-fails-offender | 8 | 0 |
| R3.2 registration-cascade-recovers-children | 13 | 2 | | R4.3 satisfaction-counts-active-only | 8 | 0 |
| RU.1 update-restarts-with-new-config | 12 | 1 | | C3.2 isolation-label-join | 8 | 0 |
| R8.1 leaving-provider-reads-own-deps | 12 | 2 | | C5.1 undeclared-access-rejected | 8 | 0 |
| C5.2 ancestry-authorized-access | 12 | 0 | | R1.1 insert-activates-fresh | 6 | 0 |
| M1 interleaved-recovery-independence | 11 | 0 | | R1.4 declared-provision-disjointness-at-insert | 6 | 0 |
| R4.4 failure-latch-unchanged-env | 6 | 0 | | C1.1 provision-value-operations | 6 | 0 |
| C5.3 declared-inactive-access | 6 | 1 | | R2.2 retire-pending-clean | 5 | 0 |
| R7.1 raise-recovers-then-latches | 5 | 2 | | C4.1 intercept-nearest-wins | 5 | 1 |
| R4.1 begin-requires-satisfaction | 2 | 0 | | M4 quiescence-on-unsatisfiable | 2 | 0 |

The per-test counts sum to 317 against 53 distinct signatures — an average
redundancy of **6.0×**. The suite is dense on a small core and empty
elsewhere, which is exactly the shape the uncovered list below confirms.

### 8.4 The 93 uncovered signatures, by id

Each row cites the T_B test that covers it (`TB.<n>@<run>` — the id in
`out/tb-<run>.json`) and, in the last column, the signatures.md occurrence
letters it projects to under §11's α. Rows whose α-class is already covered
by some *other* test are **cross-product duplicates**: new field records, not
new occurrence classes.

**O-Insert (3)** — isolated-realm and retired-parent inserts.

| id | signature | α-class |
|---|---|---|
| `TB.8@A2c` | `fired {declaredConflict:false,parent:"live",realm:"isolated"}` | `{I2,I4,I6,S2|S3}` |
| `TB.20@A2c` | `fired {declaredConflict:false,parent:"retired",realm:"isolated"}` | `{I2,I4,I6,S2|S3}` |
| `TB.13@A2c` | `fired {declaredConflict:false,parent:"retired",realm:"root"}` | `{I2,I4,I6,S1}` |

*Theme*: inserting under a **retired-but-not-removed** parent. The hand
suite never does this; D1 folds `retired` into ParentClass = present (`I2`),
so no *letter* is missed, but the interface distinction is untested.

**O-Retire (8)** — the `again` idempotence dimension and mid-lifecycle retire.

| id | signature | α-class |
|---|---|---|
| `TB.45@A2c` | `fired {again:false,stateClass:"failed"}` | `{R3}` |
| `TB.10@A2c` | `fired {again:false,stateClass:"loading"}` | `{R2}` |
| `TB.29@A2c` | `fired {again:false,stateClass:"unloading"}` | `{R2}` |
| `TB.82@A2c` | `fired {again:true,stateClass:"active"}` | `{R2}` |
| `TB.73@A2c` | `fired {again:true,stateClass:"disposed"}` | `{R4}` |
| `TB.72@A2c` | `fired {again:true,stateClass:"loading"}` | `{R2}` |
| `TB.69@A2c` | `fired {again:true,stateClass:"pending"}` | `{R1}` |
| `TB.78@A2c` | `fired {again:true,stateClass:"unloading"}` | `{R2}` |

*Theme*: **re-retiring an already-retired fiber** (5 of the 8). `O-Retire` is
idempotent in the reference model; nothing in the hand suite pins that down
at any state class except implicitly. This is a genuine behavioural gap, not
a cross-product artefact — the `again` atom is an explorer refinement (log
S8) with no D1 letter at all.

**O-Remove (7)** — the disabled (blocking) occurrences.

| id | signature | α-class |
|---|---|---|
| `TB.50@A2c` | `disabled {hasChild:false,stateClass:"active"}` | `{M5,M6}` |
| `TB.22@A2c` | `disabled {hasChild:false,stateClass:"reloading"}` | `{M5,M6}` |
| `TB.38@A2c` | `disabled {hasChild:false,stateClass:"unloading"}` | `{M5,M6}` |
| `TB.61@A2c` | `disabled {hasChild:true,stateClass:"active"}` | `{M5,M7}` |
| `TB.37@A2c` | `disabled {hasChild:true,stateClass:"reloading"}` | `{M5,M7}` |
| `TB.54@A2c` | `disabled {hasChild:true,stateClass:"unloading"}` | `{M5,M7}` |
| `TB.60@A2c` | `fired {outcome:"xi",stateClass:"inactive"}` | `{M1,M4,M6}` |

*Theme*: **removal refused at every non-Inactive state class**. The hand
suite tests that removal *follows* inactivity (`R3.1`) but never enumerates
the states where it must be blocked. `TB.60` is different and more pointed:
disposal of a *failed* (ξ) fiber — D1's Dev-3 explicitly split `M3`/`M4`
because "the quiescent report distinguishes disposal of clean vs. failed
fibers", and the hand suite tests only the clean case.

**O-Update (4)** — update at non-Active state classes.

| id | signature | α-class |
|---|---|---|
| `TB.5@dep3` | `fired {installed:false,outcome:"bot",stateClass:"pending"}` | `{V5}` |
| `TB.10@dep3` | `fired {installed:true,outcome:"bot",stateClass:"loading"}` | `{V5}` |
| `TB.28@dep3` | `fired {installed:true,outcome:"bot",stateClass:"unloading"}` | `{V5}` |
| `TB.45@dep3` | `fired {installed:true,outcome:"xi",stateClass:"unloading"}` | `{V5}` |

*Theme*: `RU.1` covers update-on-Active only. All four project to the single
letter `V5`, so no D1 letter is lost — but `update` mid-teardown
(`unloading`) is a real interface case with no test.

**L-Begin (1)**

| id | signature | α-class |
|---|---|---|
| `TB.59@A2c` | `disabled {outcome:"xi",retired:true}` | `{B2,B4}` |

*Theme*: both blocking reasons (failed outcome **and** retirement) present at
once. Each is tested separately; their conjunction is not.

**L-Iter (3)**

| id | signature | α-class |
|---|---|---|
| `TB.15@A2c` | `fired {stepClass:"read-undeclared-np"}` | `{P6,T1,T2,T8}` |
| `TB.31@A2c` | `fired {stepClass:"setval-own-eq"}` | `{T1,T2,T9}` |
| `TB.30@A2c` | `fired {stepClass:"setval-own-neq"}` | `{T1,T2,T9}` |

*Theme*: **in-lifecycle `setval`**. `C1.1` exercises the value operations
externally; no test performs a `set` step *inside* an effect script, in
either the value-equal or value-changed form. The `-np` read is the
undeclared read with no provider anywhere (vs `-p`, which is covered).

**L-Raise (3)**

| id | signature | α-class |
|---|---|---|
| `TB.27@A2c` | `fired {acc:["provide"],stepClass:"raise"}` | `{X1,X2,X7}` |
| `TB.17@A2c` | `fired {acc:[],stepClass:"flag-fail"}` | `{X1,X3,X6}` |
| `TB.18@A2c` | `fired {acc:[],stepClass:"setval-foreign"}` | `{X1,X5,X6}` |

*Theme*: raising with a **provide** already in the accumulator (the recovery
must undo a provision, not just a track), and the two non-`raise` ways to
produce `Left(ξ)` — a failed `raiseUnless` flag and a foreign `setval` — each
from an empty accumulator.

**L-Divert (11 of 12 — the worst-covered rule)**

| id | signature | α-class |
|---|---|---|
| `TB.75@dep3` | `fired {acc:["provide","track"],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.55@A2c` | `fired {acc:["provide","track"],trigger:"target-bot"}` | `{D1,D3|D4,D5}` |
| `TB.24@dep3` | `fired {acc:["provide"],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.36@A2c` | `fired {acc:["provide"],trigger:"target-bot"}` | `{D1,D3|D4,D5}` |
| `TB.60@regA` | `fired {acc:["retire"],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.47@A2c` | `fired {acc:["retire"],trigger:"target-bot"}` | `{D1,D3|D4,D5}` |
| `TB.58@dep3` | `fired {acc:["rrev"],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.75@A2c` | `fired {acc:["rrev"],trigger:"target-bot"}` | `{D1,D3|D4,D5}` |
| `TB.98@dep3` | `fired {acc:["track"],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.18@dep3` | `fired {acc:[],trigger:"stale"}` | `{D1,D5,V5@divert*}` |
| `TB.23@A2c` | `fired {acc:[],trigger:"target-bot"}` | `{D1,D3|D4,D5}` |

*Theme*: the single covered signature is
`fired {acc:["track"],trigger:"target-bot"}` (`R6.1`). Everything else —
**every accumulator class other than a lone track, and the entire
`trigger:"stale"` column (orchestrator-forced restart mid-activation)** — is
untested. Only 2 α-classes are involved, so no D1 letter is lost; but the
*recovery content* at a divert varies with the accumulator, and that is the
dimension the suite never varies.

**L-Unload (19)** — 6 fired families plus 2 disabled. Full list in
`out/coverage.md`; the structure is:

| id | signature | α-class |
|---|---|---|
| `TB.100@dep3` | `disabled {acc:["provide","track"],outcome:"bot",relied:true,retired:false}` | `{U2,U3,U5,U6}` |
| `TB.62@dep3` | `disabled {acc:["provide"],outcome:"bot",relied:true,retired:false}` | `{U2,U3,U5}` |
| `TB.82@dep3` | `fired {acc:["provide","track"],obs:["track"],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U5,U6}` |
| `TB.85@A2c` | `fired {acc:["provide"],obs:[],…,postTarget:"bot",retired:false}` | `{U1,U11,U3,U5}` |
| `TB.41@dep3` | `fired {acc:["provide"],obs:[],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U5}` |
| `TB.58@A2c` | `fired {acc:["provide"],obs:[],outcome:"xi",postTarget:"bot",retired:true}` | `{U1,U10,U4,U5}` |
| `TB.43@A2c` | `fired {acc:["provide"],obs:[],outcome:"xi",postTarget:"sat",retired:false}` | `{U1,U12,U4,U5}` |
| `TB.86@A2c` | `fired {acc:["retire"],obs:[],…,postTarget:"bot",retired:false}` | `{U1,U11,U3,U7}` |
| `TB.62@A2c` | `fired {acc:["retire"],obs:[],…,postTarget:"bot",retired:true}` | `{U1,U10,U3,U7}` |
| `TB.72@regA` | `fired {acc:["retire"],obs:[],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U7}` |
| `TB.80@A2c` | `fired {acc:["rrev"],obs:["rrev"],…,postTarget:"bot",retired:true}` | `{U1,U10,U3,U8}` |
| `TB.69@dep3` | `fired {acc:["rrev"],obs:["rrev"],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U8}` |
| `TB.76@A1` | `fired {acc:["track"],obs:["track","track"],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U6}` |
| `TB.56@A2c` | `fired {acc:["track"],obs:["track"],outcome:"xi",postTarget:"bot",retired:true}` | `{U1,U10,U4,U6}` |
| `TB.79@A2c` | `fired {acc:[],obs:[],…,postTarget:"bot",retired:false}` | `{U1,U11,U3,U9}` |
| `TB.39@A2c` | `fired {acc:[],obs:[],…,postTarget:"bot",retired:true}` | `{U1,U10,U3,U9}` |
| `TB.30@dep3` | `fired {acc:[],obs:[],…,postTarget:"sat",retired:false}` | `{U1,U12,U3,U9}` |
| `TB.93@dep3` | `fired {acc:[],obs:[],outcome:"xi",postTarget:"bot",retired:false}` | `{U1,U11,U4,U9}` |
| `TB.46@A2c` | `fired {acc:[],obs:[],outcome:"xi",postTarget:"bot",retired:true}` | `{U1,U10,U4,U9}` |

*Theme*: the **`U12` bookkeeping block — `postTarget:"sat"`, the
"deactivation chains directly into re-activation" composite of §4.3.3** — is
uncovered in *six* of its seven accumulator variants. D1 calls `U12` out
specifically as the interesting bookkeeping case; the hand suite reaches it
once. Second theme: `outcome:"xi"` unloads (a *failed* fiber running its
recovery) are uncovered in 5 of 6 variants.

**A-Set (33 of 35 — the largest block, and almost entirely cross-product)**

29 fired records (all α-class `{P3}`) and 4 refused (all `{P4}`). The two
covered ones are `fired {…dependents:[],stateClass:"active",valueEq:false}`
and `fired {…dependents:["active"],stateClass:"active",valueEq:false}`. The
33 uncovered differ only in:

- `dependents` — the multiset of lifecycle states of fibers currently relying
  on the key: 8 values (`[]`, `[active]`, `[loading]`, `[unloading]`, and the
  four 2-element combinations). **This field has no D1 letter whatsoever.**
- `stateClass` of the setter: `{active, loading, unloading}` (+ `failed`,
  `pending` on the refused side).
- `valueEq`: whether the new value equals the old.

*Theme*: **this is the cross-product blow-up, not a coverage crisis.** All 33
project onto two letters (`P3`, `P4`) that the suite already covers. Genuine
untested content hides inside: `valueEq:true` (idempotent overwrite) is
untested at every state class, and `setown` while *unloading* is untested.
But 30-odd of the "93 uncovered" are one occurrence class counted many times
— which is precisely the §11 reconciliation point.

**A-Read (1)**

| id | signature | α-class |
|---|---|---|
| `TB.14@A2c` | `fired {cls:"undeclared-np"}` | `{A5|A6,P6}` |

*Theme*: undeclared
read with **no provider anywhere** — `C5.1` covers the `-p` case (provider
exists but access is unauthorized); the `-np` case (nothing there at all) is
the control that distinguishes "not authorized" from "not present".

### 8.5 Top themes of the uncovered set

Ranked by how much genuinely-new occurrence content they represent (not by
raw count):

1. **`L-Divert` recovery content (11)** — every accumulator class but one,
   and the whole orchestrator-forced-restart (`stale`) column.
2. **`L-Unload` `U12` re-activation chaining and ξ-outcome teardown (19)** —
   the bookkeeping block D1 flags as the interesting one.
3. **`O-Retire` idempotence (5 of 8)** — `again:true` at every state class;
   an explorer-added atom with no D1 letter and no test.
4. **`O-Remove` blocking occurrences (6 of 7)** — the states where removal
   must be refused, plus disposal of a failed fiber.
5. **In-lifecycle `setval` (2)** and **`A-Set` value-equal overwrite** — the
   Def.-24 `A_k` path is tested only externally and only in the
   value-changing direction.
6. **`A-Set` `dependents` cross-product (≈30)** — high count, low
   information; one α-class.

## 9. Deviant check: generated-suite kill matrix {#9-kill}

`kill-tb.mjs` replays every generated test against each of the 27 mutants;
a kill is any difference from the baseline observation (per-action
refusal/event/certificate difference, or any difference in the settle
outcome set — reports, events, certificates, divergence).

### 9.1 Result

From `out/kill-tb.json` (recomputed; byte-identical to the stored artifact,
matrix computed in 0.7 s):

> **(K1) 27 / 27 mutants killed by T_B.** `unkilled: []`.
> Baseline reproduction 150 / 150 exact (`baselineBad: 0`).

| mutant | killed by (of 150) | | mutant | killed by |
|---|---|---|---|---|
| `isolate-shared` | 66 | | `no-commit-view` | 7 |
| `remove-before-inactive` | 49 | | `raise-skips-recovery` | 6 |
| `divert-skips-recovery` | 35 | | `dynamic-conflict-ignored` | 5 |
| `begin-without-deps` | 27 | | `recovery-leaves-residue` | 5 |
| `leave-keeps-providing` | 23 | | `proxy-no-ancestry` | 4 |
| `satisfied-by-installed-provider` | 23 | | `proxy-allows-undeclared` | 3 |
| `overwrite-tears-episode` | 20 | | `accumulator-fifo` | 2 |
| `update-keeps-stale-binding` | 19 | | `failed-still-provides` | 2 |
| `unload-without-guard` | 17 | | `refresh-misses-pending` | 2 |
| `retire-discards-accumulator` | 17 | | `insert-allows-disposed-parent` | 1 |
| `unload-skips-child-retire` | 15 | | `insert-allows-duplicate-provider` | 1 |
| `begin-from-failed` | 14 | | `intercept-outer-wins` | 1 |
| `unload-clears-view-early` | 11 | | `proxy-skips-inactive-check` | 1 |
| `guard-only-direct` | 10 | | | |

### 9.2 The four single-test kills — where the coda tests earn their place

Four mutants are killed by exactly one test each, and **three of those four
are killed by a coda test**:

| mutant | sole killer | note |
|---|---|---|
| `insert-allows-disposed-parent` | `TB.88` (coda) | the O-Insert-under-removed-parent refusal. Nothing in the graph can express it (log S6). |
| `intercept-outer-wins` | `TB.89` (coda) | Def. 31 nearest-wins at depth 2. No LTS transition invokes `interceptMerged` (log S7). |
| `proxy-skips-inactive-check` | `TB.90` (coda) | Algorithm 6 line 5 — the external read on a declared-but-uncommitted fiber, with **no** provider present (`-np`). |
| `insert-allows-duplicate-provider` | `TB.7` | declared-disjointness refusal at insert. |

Checked directly (`out/kill-tb.json` → `kills`): the mutants whose entire
kill set lies inside `{TB.88, TB.89, TB.90, TB.91}` are exactly
`insert-allows-disposed-parent`, `intercept-outer-wins` and
`proxy-skips-inactive-check`. **Without the coda tests T_B would kill 24/27,
not 27/27.** This is the
quantitative justification for scoping decisions S6 and S7: they are not
bookkeeping footnotes, they are load-bearing. It also means **the graph
alone is not a complete test basis** — a fact the reconciliation in §11
explains structurally (the LTS does not model the external Def.-23 access
surface or the derived intercept operation).

### 9.3 Comparison with the hand suite

`out/hand-suite-kill-matrix.txt` (produced by the untouched
`../proof/run-necessity.mjs`) records the same verdict for the 32-test hand
suite: **all 27 mutants killed**. The two suites therefore agree on (K1) and
differ in shape:

| | hand suite | generated T_B |
|---|---|---|
| tests | 32 | 150 |
| mutants killed | 27 / 27 | 27 / 27 |
| reachable signatures exercised | 53 | 146 |
| tests that are redundant for (K1) | 18 of 32 | not computed (see §12) |
| median kills per test | 2 (min 1, max 7) | 3 (min 0, max 16) |
| tests killing **no** mutant | **9** of 32 | **7** of 150 |

(Hand-suite figures derived from `out/hand-suite-kill-matrix.txt` by
inverting its per-mutant killer lists: 23 of the 32 tests appear as a killer
of something.)

Both suites contain tests that kill nothing, and in the hand suite's case
that is a *larger* fraction (9/32 vs 7/150). For T_B it is expected by
construction: T_B is generated to cover *signatures*, and a signature whose
behaviour no mutant perturbs has no mutant to kill. Neither suite is minimal
with respect to (K1).

The hand suite achieves the same kill result with a fifth of the tests, and
`run-necessity.mjs` finds 18 of its 32 tests redundant for mutant-killing
purposes. T_B is not a better *mutant* suite; it is a suite indexed by
occurrence signature, which is a different (and, for CF4's purposes,
complementary) adequacy criterion. Mutant-killing measures sensitivity to a
chosen fault model; signature coverage measures whether every occurrence
class the semantics can produce has been *observed at all*.

## 10. Scoping decisions and deviations (complete log) {#10-scoping}

Every decision that narrows, extends or interprets MASTER's field drafts and
bound B0.

- **S1 — component-shape catalog instead of raw step-sequence enumeration.**
  §3. The generator's input space is the 19-shape catalog; justification and
  the signature-class-coverage argument are given there. Consequence: any
  occurrence requiring a step *sequence* pattern beyond the catalog (e.g. a
  provide after a read in one component) is out of the explored generator;
  by Def. 3 such patterns decompose into the same per-step occurrence
  alphabet, so no *occurrence class* is lost, only extra multiset
  combinations of them.
- **S2 — B0's fiber dimension reduced to a portfolio** (§4), with the growth
  measurements that forced it. **No run reaches B0's N_f = 4**; the largest
  exhaustive bounds are N_f = 2 on the full catalog and N_f = 3 on restricted
  generators. Five of the six T_B-generating runs are exhaustive. The sixth,
  `regA`, **is truncated** (time budget) and is disclosed as such in §5.1 and
  §6: it contributes two signatures no other run reaches, which are sound
  positive witnesses, and it is paired with the exhaustive `regB` at the same
  bound so that no *negative* claim rests on it. Corroboration runs `A2w` and
  `A3c` are also truncated and are excluded from the T_B basis (S13).
- **S3 — trackMutate excluded** from the catalog: no test uses it, values
  in the explored bound are scalar classes, and its occurrence class
  (inverse that rewrites a field of an object value) collapses onto the
  `mutate` inverse class which the instrumentation still tags.
- **S4 — `update` offered with the single config class {ok:true}**; the
  initial config class is ∅ (insert). Config equality patterns beyond
  {absent, ok} add no guard atoms in Table 1 (config is opaque to every
  rule except `raiseUnless`'s single flag read).
- **S5 — orchestration allowed at every state**, not only at quiescence:
  the calculus places no quiescence premise on O-rules, and the 32-test
  suite itself injects orchestration mid-transition (trace watchers). T_B
  scripts therefore contain scheduler-resolved lifecycle micro-steps; a
  conforming implementation adapter must expose the same boundary (the
  suite's `trace.when` device shows it is realizable).
- **S6 — O-Insert under a removed parent** is exercised by an explicit coda
  test, not by graph search: normalization (correctly) erases unreferenced
  removed fibers, so no normalized state retains the removed parent to
  insert under. The refusal itself is state-independent.
- **S7 — intercept resolution (Def. 31)** is exercised by an explicit coda
  probe (depth-2 chain, nearest-wins), since `interceptMerged` is a pure
  derived operation never invoked by an LTS transition; interception has no
  other coupling to the explored state space. Isolation, by contrast, IS
  explored (isolated inserts, realm joins, per-realm σ).
- **S8 — signature field realizations vs MASTER's drafts** (deviations):
  - *O-Insert*: parent classes {root, live, retired, removed} (drafts had
    live?); declared-conflict witness boolean; realm class {root, isolated}.
    Freshness is system-controlled as drafted (no signature field).
  - *O-Retire*: state class over the five observable classes
    {pending, loading, active, unloading, failed} rather than the drafted
    three-way {pending, installed, failed} — strictly finer, still finite;
    plus the `again` (already-retired) idempotence atom.
  - *O-Remove*: fired occurrences record {stateClass, outcome ⊥/ξ};
    disabled occurrences record {stateClass, child-witness} — τ is implied
    (only retired fibers are candidates).
  - *O-Update*: not in MASTER's drafts (the orchestration alphabet of
    PAPER_REWRITE §2.3 includes it); fields {installed?, outcome class,
    state class}.
  - *L-Begin*: per-key satisfaction classes as the SET {provided,
    unprovided} present over the inject list (cardinality-free as drafted);
    `installed-only-provided` is not reachable in the baseline σ (it is a
    mutant behavior — `satisfied-by-installed-provider`) and appears in no
    baseline signature, as MASTER's reachability analysis predicts.
    Disabled occurrences additionally record the retirement/latch reason.
  - *L-Iter*: step class alphabet as drafted, with reads split by the
    Algorithm-6 resolution class {committed-self, committed-ancestor,
    inactive-declared, undeclared, withdrawn} and setval split
    {own-eq, own-neq, foreign}; raiseUnless contributes {flag-pass,
    flag-fail} (drafted as part of the step-constructor dimension).
    `exhausted` is L-Finish in the reference model, reported under
    L-Finish.
  - *L-Raise*: raising step class + accumulator classes present, as
    drafted.
  - *L-Divert / L-Leave*: trigger ∈ {stale, target-bot, target-diff}
    realizes the drafted view relation {target = ω excluded by guard,
    target ≠ ω, target = ⊥} plus the orchestrator-forced restart marker
    (§5.2.1 update), which the drafts subsume under "≠ ω".
  - *L-Unload*: as drafted {outcome, τ, relied witness (true only in
    disabled occurrences in baseline), inverse classes present,
    post-target ⊥/satisfiable} **plus** `obs`: the order pattern (length
    ≤ 2) of event-emitting inverse kinds in application order — the finite
    order-pattern component of Def. 3(3), mirroring MASTER's
    "depth-as-order-pattern up to 2" for intercepts. Without it the binary
    inverse-composition witness (PAPER_REWRITE §5.3 "accumulator order")
    has no signature of its own and `accumulator-fifo` is undetectable by
    any single-occurrence experiment (found empirically; log of the fix).
  - *Coeffect ops*: A-Set (Def. 23 set) {own/foreign binding, value
    equality pattern, state class}; A-Read (Algorithm 6) resolution class;
    A-Intercept {entry count 0/1/2+ as depth-order pattern}. Isolation has
    no operation of its own — it is a context constructor whose occurrence
    shows up in O-Insert's realm class and the per-realm σ resolution.
- **S9 — settle-outcome sets abstract event ORDER but not event set or
  certificate set.** Within a scripted action, emissions are compared as
  exact sequences; across the settle exploration, the observation is
  {report set, event set, certificate set (fired+disabled), divergence
  flag}. Order-sensitive properties inside a single rule application
  (inverse composition order) are visible because the final rule
  application is scripted; order across independent schedules is exactly
  what the calculus does not fix (confluence), so a set abstraction is the
  faithful comparison. The certificate set is what makes guard mutants
  (`unload-without-guard`, `guard-only-direct`, `remove-before-inactive`)
  observable at signature level, as CF4 intends.
- **S10 — audit schedule**: the 32-test audit runs each scenario once under
  the default fifo schedule. Signature coverage measured this way is a
  lower bound per test; the exhaustive-schedule quantification for
  VERDICTS is separately exercised by the untouched
  `run-necessity.mjs` machinery (its baseline asserts complete choice-tree
  exploration).
- **S11 — mutant certificates**: instrumentation fields are computed by the
  same (baseline-classification) helpers under mutants; a mutant may
  therefore emit a cert whose fields lie about its own internals — the kill
  comparison treats certs as opaque observables and compares them to the
  baseline's, which is exactly CF4's contract (a differing decision must
  produce a *visibly different* certificate/event/report, not a truthful
  one).
- **S12 — `sameView` totality**: the reference's stale-marker
  (`Symbol.for('stale')`) short-circuit is preserved bit-for-bit; the
  instrumented copy adds no behavior. The only semantic-adjacent refactor
  is `removePass` folding over per-fiber `removeEligible`/`removeOne` with
  identical checks in identical order (diff-reviewed).

- **S13 — the two long runs `A2w` and `A3c` were harvested but kept out of
  the T_B basis** (§5.2). Both truncated; both contributed zero new
  signatures. Recorded as corroboration, not as generating runs, so that
  every run in the T_B basis is either exhaustive or paired with an
  exhaustive twin at the same bound (`regA`/`regB`).
- **S14 — the reconciliation map α is hand-written** (`reconcile.mjs`), from
  signatures.md's §§1.1–14.1 alphabet tables. It is a claim about how two
  vocabularies correspond, not a computed fact, and §11.5 lists the places
  where it is a judgement call. Its inputs (the letter lists) are transcribed
  verbatim and can be re-checked against signatures.md line by line.

### Wall-clock summary

| phase | time |
|---|---|
| `selftest-norm.mjs` | < 1 s |
| six T_B-generating runs (`A1`, `A2c`, `dep3`, `fail3`, `regB`, `regA`) | 33.4 min (dominated by `regA`'s 25-min budget) |
| two corroboration runs (`A2w`, `A3c`) | 68.0 min |
| two saturation probes (`sat2`, `sat3`) | 1.6 min |
| `audit-32.mjs` (32 spawned processes) | ≈ 40 s |
| `coverage.mjs` | < 1 s |
| `kill-tb.mjs` (150 tests × 27 mutants) | 0.7 s |
| `reconcile.mjs` | < 1 s |
| **total** | **≈ 1 h 45 min** |

Machine: single-threaded Node on Linux 6.8; measured throughput ≈ 6 × 10³
normalized states/s on the full generator, ≈ 3 × 10³/s when `update` and
`setown` widen the action alphabet.

---

## 11. Reconciliation with D1's 86 reachable signatures {#11-reconcile}

`../signatures.md` §15 reports **86 reachable signatures**; this report
counts **146**. Both are correct. They count different things, and this
section gives the map between them. Artifacts: `explorer/reconcile.mjs`,
`out/reconcile.json`, `out/reconcile.md`.

### 11.1 The two vocabularies are not the same kind of object

- **D1 counts alphabet LETTERS.** Σ_r is a set of *occurrence letters*, each
  naming one guard atom, one step constructor class, or one existential
  witness bit. A window's occurrence multiset κ_r is a **set of letters**.
  `|Σ_r|` summed over the 14 rules/operations is 92; subtracting the six
  interface-unrealizable letters gives **86**.
- **D3 counts occurrence TUPLES.** A signature key is
  `rule + decision + the complete field record`, e.g.
  `L-Unload fired {acc:["provide","track"], obs:["track"], outcome:"bot", postTarget:"sat", relied:false, retired:false}`.
  That is one point in a **product** of field domains — closer to "a
  distinguishable window" than to "a letter".

So 146 is not a rival estimate of 86. Roughly: **86 counts the alphabet, 146
counts (reachable) words over it.**

### 11.2 The projection α and the 146 → 74 collapse

`reconcile.mjs` defines α: explorer signature ↦ set of D1 letters, reading
only the dimensions D1 gives letters to and discarding the rest. Applying α
to the 146:

> **146 explorer tuples collapse onto 74 distinct D1 letter-sets** — a
> **1.97× fold**. (`out/reconcile.json` → `projectedClasses`.)

Per rule (`out/reconcile.md`):

| rule | explorer sigs | after α | fold | D1 `|Σ_r|` | D1 reachable |
|---|---|---|---|---|---|
| O-Insert | 7 | 5 | 1.4× | 7 | 6 |
| O-Retire | 10 | 4 | 2.5× | 4 | 4 |
| O-Remove | 9 | 5 | 1.8× | 7 | 7 |
| O-Update | 6 | 1 | 6.0× | — | — |
| L-Begin | 7 | 7 | 1.0× | 7 | 7 |
| L-Iter | 11 | 8 | 1.4× | 11 | 11 |
| L-Raise | 5 | 5 | 1.0× | 9 | 9 |
| L-Finish | 6 | 2 | 3.0× | 3 | 3 |
| L-Divert | 12 | 2 | 6.0× | 6 | 4 |
| L-Leave | 3 | 3 | 1.0× | 5 | 4 |
| L-Unload | 31 | 27 | 1.1× | 12 | 12 |
| A-Set | 35 | 2 | **17.5×** | 6 | 6 |
| A-Read | 4 | 3 | 1.3× | 7 | 5 |
| **total** | **146** | **74** | **1.97×** | **92** | **86** |

Note the fold is wildly uneven, and the table makes the answer to the
question "is the explorer just splitting what the hand analysis groups?"
**partly yes, partly no** — see §11.3 and §11.4.

**Concrete example of splitting (the dominant effect).** The single D1
letter `P3` ("A_k overwrite, own binding present — value replaced in place")
has **30 explorer signatures** in its α-fibre, because the explorer's `A-Set`
record carries three fields D1 gives no letter to:

```
A-Set fired {binding:"own", dependents:["active","loading"], stateClass:"active",   valueEq:false}
A-Set fired {binding:"own", dependents:["active","loading"], stateClass:"active",   valueEq:true }
A-Set fired {binding:"own", dependents:["active","loading"], stateClass:"unloading",valueEq:false}
…27 more, all → {P3}
```

`dependents` (8 values) × `stateClass` (3) × `valueEq` (2) is the whole story
of A-Set's 35. D1 deliberately folds all three away: §11.2 of signatures.md
says "key and value payloads normalized by CF2", and reliance witnesses are
"one letter regardless of how many dependents". The explorer keeps them
because they are *state* and it dedups on state.

Other large fibres, same mechanism:

| D1 class | explorer sigs | the field(s) D1 folds away |
|---|---|---|
| `A-Set fired {P3}` | 30 | `dependents`, `stateClass`, `valueEq` |
| `O-Retire fired {R2}` | 6 | `stateClass` sub-split (loading/active/unloading), `again` |
| `L-Divert fired {D1,D3|D4,D5}` | 6 | `acc` (accumulator class) |
| `O-Update fired {V5}` | 6 | `installed`, `outcome`, `stateClass` |
| `L-Divert fired {D1,D5,V5@divert*}` | 6 | `acc` |
| `L-Finish fired {F1,F3}` | 5 | `acc` (D1 §6.2: "the accumulator's content is not enumerated here") |
| `A-Set refused {P4}` | 5 | `stateClass` |

**Where α does NOT collapse: L-Unload (31 → 27, only 1.1×).** This is worth
stating because it is the counter-example to a tidy story. D1 gives L-Unload
12 letters, but they are *per-item* letters (`U5`–`U8`, one per inverse
class) plus bookkeeping blocks (`U10`–`U12`), and a single window legitimately
realizes a **set** of them. 27 distinct realizable letter-sets over 12
letters is not a contradiction — it is what "occurrence multiset" means. So
for L-Unload the explorer is not splitting D1's classes; it is enumerating
the combinations D1's letters were always intended to combine into. The 74 is
therefore an intermediate quantity, not "the corrected 86".

### 11.3 The closing ledger

The arithmetic that actually reconciles the two numbers is over *letters*,
not tuples (`out/reconcile.json` → `ledger`):

| quantity | value |
|---|---|
| D1 letters, all 14 rules/operations | 92 |
| − interface-unrealizable (I5, D2, D6, V2, A4, A7) | 6 |
| **= D1 reachable letters** | **86** |
| witnessed in the explorer graph | **75** (67 separately + 8 only as a conflated pair) |
| not witnessed in the graph | **11** |
|  · covered by a T_B coda test | 2 — `I3`, `N4` |
|  · absence **predicted by D1 itself** | 2 — `B6`, `T7` |
|  · **genuine generator gaps** | **7** — `M2`, `X9`, `S4`, `N1`, `N2`, `N3`, `A3` |

**Verdict: 75 of D1's 86 reachable letters are confirmed by exhaustive
search; 2 more by coda tests; 2 absences are ones D1 predicts; 7 remain
unreconciled as generator gaps.** No letter is contradicted.

The 7 genuine gaps, with the reason each is unreachable *for this generator*
(not for the calculus):

| letter | what it is | why the generator misses it |
|---|---|---|
| `M2` | O-Remove RetClass τ=⊥, blocking | the explorer offers `remove` only where `removeEligible` holds, so the τ=⊥ refusal is never an *offered action*. Fixable by offering ineligible removes. |
| `X9` | `register⁻¹` in a raise accumulator | needs a shape that registers *then* raises; no catalog shape does both (an S1 consequence). |
| `S4` | isolate over an already-isolated key | the generator offers exactly one isolate context (`k1↦r1`) and never nests a second. |
| `N1`,`N2`,`N3` | intercept MetaPat ε / context-only / component⊕context | `A-Intercept` has **no** LTS occurrence at all (log S7); only `N4` is reached, by coda `TB.89`. |
| `A3` | Algorithm-6 IA at an **ancestor** | needs an orchestrator-inserted child that *reads* under a pending declaring parent; the child-insert probe uses shape `T`, which has no read step. |

Five of the seven (`X9`, `S4`, `N1`–`N3`, `A3`) are catalog/probe-alphabet
limits, closable by adding shapes; `M2` is closable by widening the offered
action set; none indicates a disagreement about the semantics.

The two predicted absences deserve emphasis, because they are D1's
reachability analysis being *confirmed*, not gaps:

- **`B6`** (`installed-only-provided`): D1 §4.1 and log S8 independently say
  no baseline σ realizes it — it is precisely the
  `satisfied-by-installed-provider` **mutant's** behaviour. Its absence from
  7.05 M explored states is the predicted result.
- **`T7`** (`read-declared-uncommitted` as an in-lifecycle **step**): this is
  A4's argument at step level. A fiber never executes a step while its own
  declared key is uncommitted, so no `L-Iter` window can carry this step
  class. Absent, as predicted.

### 11.4 The six interface-unrealizability claims — all confirmed

Checked explicitly by id against the reachable union
(`out/reconcile.json` → `unrealizableWitnessed: []`). For each, the
explorer's encoding *can* express the occurrence — the classifier branch
exists in `model.mjs` — so absence is a search result, not a definitional
artefact, except where noted:

| id | claim | encoding site | verdict |
|---|---|---|---|
| **D2** | L-Divert `key-changed-provider` | `model.mjs:357` emits `trigger:'target-diff'` | **CONFIRMED absent.** `target-diff` appears in **zero** of the 146 signatures and zero of the 64 audited signatures, over 7.05 M states. Strongest of the six: the branch is live code the search never reached. |
| **V2** | L-Leave `key-changed-provider` | `model.mjs:404`, same ternary | **CONFIRMED absent.** Same evidence, independent rule. Together D2+V2 are the machine-checked form of D1's A10 argument. |
| **A7** | Algorithm-6 withdrawn binding | `model.mjs:172` returns `'withdrawn'` | **CONFIRMED absent.** Never produced in-lifecycle or by the external probes. Matches Thm. 63: the reliance guard blocks `provide⁻¹` while a committed edge exists. |
| **D6** | L-Divert alternative = *land* (h ≠ id) | — | **CONFIRMED absent, but structurally.** The reference model's L-Divert branch only ever aborts (`fiber.remaining = null; state = 'unloading'`); there is no landing branch to reach. Consistent with D1 (which calls D6 calculus-real but script-unrealizable), but the explorer cannot *independently* corroborate it — it inherits the same modelling choice. |
| **I5** | O-Insert stale (reused) name | — | **CONFIRMED absent, but by construction.** Fiber names are system-drawn (`m.nextUid`) and the explorer has no freshness field at all, exactly as D1 argues the interface does. Absence is definitional here, so this is agreement, not evidence. |
| **A4** | Algorithm-6 IA at PosClass = **self** | `model.mjs:174` returns `inactive-declared…` | **CONFIRMED for in-lifecycle windows — but see §11.4.1.** |

Two of the six (`I5`, `D6`) are confirmed *because the model shares D1's
assumption*, and the report should not over-claim them as independent
corroboration. The other four (`D2`, `V2`, `A7`, and A4-in-lifecycle) are
genuine negative search results against live classifier branches.

#### 11.4.1 A4 — the one place the data qualifies D1

D1 §14.3 marks `A4` **interface-unrealizable**, justified by: "while a fiber
runs (forward or in recovery) its own committed view is total on d_n … a
fiber never executes a step while Inactive. So no self-window with a
declared-uncommitted key exists."

The exploration **confirms exactly that statement**: no `L-Iter` step class
`read-inactive-declared-*` and no in-graph `A-Read` of that class occurs
anywhere in 7.05 M states (this is the `T7` absence of §11.3).

But the occurrence *is* realizable through the **external** Def.-23 access
surface, and both suites contain a test that does it:

- coda tests `TB.90` / `TB.91` call `readCommitted` on a fiber that declares
  the key and holds no committed view. The Algorithm-6 walk starts at that
  fiber and decides there (`walk === fiber`), so PosClass = **self** = `A4`.
- the hand suite's `C5.3 declared-inactive-access` does the same via
  `sys.readVia(c, 'k')` on a pending consumer.
- it is not idle: `TB.90` is the **sole killer** of `proxy-skips-inactive-check`
  (§9.2).

So the precise statement is: **A4 is unrealizable as an in-lifecycle window
and realizable as an external access.** D1's justification is sound but its
scope is narrower than the blanket label suggests — the argument quantifies
over *steps*, while the occurrence is a property of Algorithm 6, which the
environment can also invoke. This is a scope refinement, not a refutation,
and it does not change the count of 86. But it does mean the *reason* A4 is
excluded from T\* should be restated: not "no experiment can present this
occurrence", but "no in-lifecycle window can — an external read can, and both
suites already contain one".

**Caveat on precision:** the explorer's `classifyRead` returns the same
`inactive-declared-{p,np}` string whether the walk decides at self (`A4`) or
at an ancestor (`A3`) — see §11.5. The attribution to `A4` above rests on
reading the two coda scripts, where the probed fiber is the declaring one, not
on the signature string alone.

### 11.5 Where α is a judgement call, and what stays unreconciled

α is hand-written (log S14). Three places it **coarsens** — the explorer is
*less* discriminating than D1, the opposite of the A-Set story — and these
are the honest limits of the mapping:

| explorer class | D1 letters it conflates | why |
|---|---|---|
| `L-Divert/L-Leave trigger:"target-bot"` | `D3` \| `D4` and `V3` \| `V4` | `targetOf()` returns `null` for **both** τ-retirement and provider-withdrawal, so the certificate cannot say which. D1 letters them separately (target-⊥-retired vs target-⊥-unsatisfied). |
| `A-Read cls:"undeclared-{p,np}"` | `A5` \| `A6` | `classifyRead` returns the same string whether the walk died at the root boundary (`A5`) or at a realm mismatch (`A6`). The `-p`/`-np` witness is an *orthogonal* explorer refinement, not this distinction. |
| `A-Read cls:"inactive-declared-*"` | `A3` \| `A4` | decides-at-self vs decides-at-ancestor is not recorded. |
| `O-Insert realm:"isolated"` | `S2` \| `S3` | the generator offers one isolate context, so two isolated inserts share realm `r1`: distinct-realm and joined-realm are the same signature. |

That is **8 letters witnessed only as a conflated pair** (`D3`, `D4`, `V3`,
`V4`, `S2`, `S3`, `A5`, `A6`). They are counted as witnessed in §11.3's 75,
which is the generous reading; the strict reading is 67 separately-witnessed
letters plus 8 known-reached-but-unresolved.

Two further α decisions worth flagging for anyone citing this section:

1. **`O-Update` has no D1 rule.** The explorer promotes `update` to a
   first-class rule with 6 signatures; D1 files it as letter `V5` under
   L-Leave (Dev-7, flagged there as an extension, A3). α maps all 6 → `V5`.
   A reader comparing rule-by-rule tables will otherwise see a phantom
   6-signature rule on one side.
2. **`L-Divert trigger:"stale"`** (orchestrator-forced restart) has **no D1
   letter at L-Divert at all** — D1 gives `V5` only to L-Leave. α emits the
   marker `V5@divert*` for it. Six explorer signatures sit in that class, and
   they are formally outside D1's L-Divert alphabet. This is a real gap in
   the *hand* analysis, symmetric to the explorer's gaps in §11.3.

**What remains unreconciled, stated plainly:**

- 7 D1 letters (`M2`, `X9`, `S4`, `N1`, `N2`, `N3`, `A3`) have no explorer
  witness. Each has an identified cause and a known fix; none is a
  disagreement about the semantics.
- 8 D1 letters are reached but not separated by the explorer's encoding.
- 6 explorer signatures (`L-Divert trigger:"stale"`) have no D1 letter.
- The blanket unrealizability of `A4` is qualified by §11.4.1.
- α itself is unverified against D1 beyond transcription of the letter
  tables; it encodes *this author's* reading of signatures.md §§1.1–14.1.

Everything else lines up: **92 − 6 = 86 = 75 + 2 + 2 + 7.**

### 11.6 Correction C1 — D1's canonical script for D3 is refused

This one shows up in the data directly, and it is reproducible in five lines.
Artifact: `explorer/c1-check.mjs` (exits 0 iff the correction reproduces).

signatures.md §7.4 gives **S-Div-3** as the canonical script for occurrence
`D3` (L-Divert with ViewRel = target-⊥-retired):

```
Q  := (∅, {k2}, [provide(k2,v2)])      Q2 := (∅, {k2}, [provide(k2,v2)])
G  := (∅, ∅, [register(C), track(a)])  C  := ({k2}, ∅, [track(b), track(c)])
ρ = insert(root,Q); insert(root,G); settle;
    retire(Q); retire(G); insert(root,Q2); settle
```

The step `insert(root, Q2)` **is refused**:

```
after retire(Q): registered=true retired=true state=active
insert(root, Q2) REFUSED — provision "k2" already declared by Q
certificate: O-Insert refused {parent:"root", declaredConflict:true, realm:"root"}
```

`retire` does not remove `Q` from the registry — only `O-Remove` does, and
only once `Q` reaches Inactive. O-Insert's declared-disjointness premise
quantifies over **all registered non-removed fibers** (`model.mjs:285`:
`if (!other.removed && (other.spec.provide ?? []).includes(key))`), which is
what D1's own Dev-1 insists on ("the conflict fold's domain is *all
registered fibers*… not merely live or Active ones"). So the script
contradicts the premise D1 states two sections earlier.

The refusal is not incidental: it produces
`O-Insert refused {declaredConflict:true, parent:"root", realm:"root"}` —
signature `TB.7` in T_B, the **sole killer** of the
`insert-allows-duplicate-provider` mutant (§9.2). The occurrence is real and
tested; what fails is S-Div-3's use of it as a *step on the way* to D3.

Nor is the obvious repair available. Inserting a `settle` before
`insert(root, Q2)` so that `Q` reaches Inactive and is removed also disposes
`C` — the control branch in `c1-check.mjs` shows **zero live fibers** at that
point — so the consumer whose target is supposed to flip no longer exists.
D3 needs `C` alive with `ω(k2)` bound while a *second* declarer of `k2`
enters, and O-Insert forbids exactly that for as long as the first declarer
is registered. This is the same shape of argument as D1's own A10 (which
proves `D2` unrealizable), applied one step earlier in the script.

**Consistency with the reachability claim.** None of this makes `D3`
unreachable. The explorer reaches D3's occurrence via a different route —
retirement flips τ, `targetOf()` returns `null`, and L-Divert fires with
`trigger:"target-bot"` — witnessed 6 times in the union (§8.4, the
`trigger:"target-bot"` rows). What the explorer *cannot* do is separate `D3`
from `D4`, since both present as `target-bot` (§11.5). So the corrected
statement is: **D3 is reachable, its D1 canonical script is not valid as
written, and the explorer confirms the former while being unable to
distinguish D3 from D4 in its certificates.**

---

## 12. Limitations: what the bound excludes {#12-limitations}

**146 is a bound-relative count, and the bound is not B0.** Every number in
§§5–9 is "reachable *within the explored portfolio*". Specifically excluded:

1. **The fiber dimension.** B0 specifies N_f = 4. The full 19-shape
   generator was explored exhaustively only at N_f = 1 (`A1`) and N_f = 2
   without external value operations (`A2c`). N_f = 3 on the full catalog
   (`A3c`) and N_f = 2 with updates/setowns (`A2w`) both **truncated**;
   N_f = 4 on the full generator is ≳ 10⁹ states (§4) and was never
   attempted. Restricted generators reach N_f = 3 exhaustively. So the claim
   "146 signatures are reachable" is sound (all are witnessed), but the claim
   "only 146 are reachable" holds only at the explored bounds.
2. **Step sequences.** The generator draws components from a fixed 19-shape
   catalog (log S1), not from all step sequences of length ≤ 5. §8.2
   measures the cost: **7 occurrence combinations exercised by the hand suite
   are structurally unreachable for this generator**, all of them accumulator
   multisets needing a component that combines two step kinds no catalog
   shape combines.
3. **`trackMutate`** is excluded entirely (log S3).
4. **Config classes** are {∅, {ok:true}} only (log S4).
5. **Isolation realms**: one isolate context (`k1↦r1`), never nested — hence
   the `S4` gap and the `S2`/`S3` conflation (§11.5).
6. **Interception** has no LTS presence at all (log S7): 3 of D1's 4 MetaPat
   letters are unreachable here, and the fourth only via a coda test.
7. **The external Def.-23 access surface** is not part of the explored LTS —
   only four coda tests touch it. §11.4.1 shows this is where `A4` lives, and
   §9.2 shows three of the 27 mutants are killed *only* there. The graph
   alone is not a complete test basis.
8. **Schedules in the audit.** The 32-test audit runs each scenario once
   under the default fifo schedule (log S10), so the 53 covered signatures
   are a **lower bound per test**; a test might touch more signatures under a
   different interleaving. The uncovered count of 93 is correspondingly an
   *upper* bound on what the suite misses.
9. **Mutant fault model.** 27/27 is relative to those 27 hand-written
   deviants. T_B is not minimal for that criterion (7 of its tests kill
   nothing, §9.3), and the hand suite achieves the same 27/27 with 32 tests.

**What is robust despite all of the above.** The union of 146 did not grow
under any enlargement attempted: `A2w` (1.81 M states expanded at the widest
alphabet), `A3c` (2.03 M at N_f = 3), `sat2`/`sat3` — **zero** new signatures
in every case (§5.2), and the `sat2`→`sat3` step added 12 tuples that project
to **zero** new occurrence classes. Signature saturation in the fiber
dimension is the one adequacy claim here with direct empirical support.
