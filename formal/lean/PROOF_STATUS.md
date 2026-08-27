# PROOF_STATUS — Track L (deliverable D4)

Lean 4 mechanization of the bounded core of the finite-characterization
result. Core Lean only; **no mathlib**, no external packages
(`lake-manifest.json` lists zero dependencies).

- Toolchain: `leanprover/lean4:v4.33.1` (pinned in `lean-toolchain`).
- Build command: `lake build` (from this directory).
- **Build result: GREEN.** Clean build (`rm -rf .lake/build && lake build`)
  succeeds with no errors and no warnings, in ≈5 minutes on the development
  machine. `grep -r sorry Bounded/` returns nothing; there is not a single
  `sorry` in the development.

---

## 1. The bound actually mechanized

```
B = ( 3 fiber slots          Slot = Fin 3
    , 2 keys                 Key  = Fin 2
    , 2 values               Val  = Fin 2
    , 2 tags                 Tag  = Fin 2
    , scripts of length ≤ 3  Script = BList Step 3
    , accumulators ≤ 3       Acc    = BList Inv 3
    , register depth 1       `register` instantiates one fixed `childComp`
    )
```

**Component catalog** (`Bounded/SigDec.lean`, `catalog`):

| name     | deps | provs | script                          |
| -------- | ---- | ----- | ------------------------------- |
| `cProv`  | ∅    | {k₀}  | `[provide k₀ v₀]`               |
| `cCons`  | {k₀} | ∅     | `[read k₀, track t₀, track t₁]` |
| `cReg`   | {k₀} | ∅     | `[register]`                    |

plus the hard-wired child `childComp` = `[read k₀, track t₀, raise]`
(deps ∅, provs ∅) that `register` installs.

**Probe alphabet** `catalogActs`: 45 labels (9 `oInsert` = 3 slots × 3
components, 3 each of `oRetire`/`oRemove`/`lBegin`/`lFinish`/`lDivert`/
`lRaise`/`lLeave`/`lUnload`, and 12 `lIter` = 3 slots × 4 register targets
{none, slot 0, slot 1, slot 2}).

**State counts.**

| quantity                                        | value                     |
| ----------------------------------------------- | ------------------------- |
| `Config` cardinality at bound B (Theorem B)     | 267 648 282 889 869 237 623 728 247 633 140 826 876 161 ≈ 2.68·10⁴¹ |
| reachable states from γ₀ under `catalogActs`    | **15 173** (machine-checked: `visited_card`) |
| transitions (enabled successor edges)           | 77 295                    |
| longest shortest-access word                    | 34 labels                 |
| bounded suite `T_B` = `suite` size              | 15 173 × 45 = 682 785 test words |

The reachable count is exactly the 15 173 the previous author reported. It is
reproducible outside the proof by `lake build probe && ./.lake/build/bin/probe`,
which also reports the counts for the sub-catalogs (`[cProv]` 31, `[cCons]` 27,
`[cReg]` 27, `[cProv,cCons]` 2 835, `[cProv,cReg]` 7 209).

---

## 2. Status of every definition and theorem

Legend: **P** = proved structurally (kernel only) · **K** = proved by `decide`
(kernel-checked finite computation) · **N** = proved by `native_decide`
(compiled execution — *added trust*, itemised in §3) · **AX** = axiom ·
**NEG** = a machine-checked *negative* result.

### `Bounded/Basic.lean` — finite-enumeration infrastructure

| name | status | note |
| ---- | ------ | ---- |
| `FinEnum` (class), instances for `Bool`, `Unit`, `Fin n`, `Option`, `×`, `⊕`, `→` | P | mathlib-free stand-in for `Fintype`; field `complete : ∀ x, x ∈ all` is the finiteness witness |
| `finList_complete`, `allFunAux_complete`, `listsLE_complete` | P | |
| `decidableBallFinEnum`, `decidableBexFinEnum` | P | declared `priority := low` — see §5, deviation D4 |
| `decEqFinEnumFun` | P | |
| `BList` + `DecidableEq`/`FinEnum`/`push`/`tail`/`map` | P | |

### `Bounded/Perm.lean` — the renaming groups

| name | status | note |
| ---- | ------ | ---- |
| `Perm3` (S₃ on slots), `ap`, `inv` | — | definitions |
| `ap_inv_ap`, `inv_ap_ap` | **K** | `decide` over 6 × 3 cases |
| `ap_injective`, `ap_surjective`, `inv_inv`, `ap_eq_iff` | P | |
| `swap2`, `ap2`, `ap2_ap2` | **K** | `decide` |
| `ap2_injective`, `ap2_surjective`, `ap2_eq_iff` | P | |
| `Ren` (slot × key × value permutation) and its lemmas | P | tags fixed — deviation D1 |
| `all_reindex`, `any_reindex` | P | |

### `Bounded/Calc.lean` — the bounded state space

All definitions (`KMap`, `SMap`, `Step`, `Component`, `LState`, `Fiber`,
`Config`, `provP`, `providerOf`, `storeOf`, `WF`, `satisfied`, `targetOf`,
`reliedUpon`, `hasChild`, `quiet`, `readC`, …). Supporting lemmas
`KMap.ext_iff`, `SMap.ext_iff`, `slot_cases`, `get_set_same`,
`get_set_other`, `upd_same`, `upd_other`: **P**.

### `Bounded/SigDec.lean` — the ten rules, clause-factored

All definitions (`Rule`, `Act`, `Event`, the signature alphabet `SigR` and
`sig`, the specification table `fS`, the reconstruction operator `liftStep`,
`execStep`, `applyInv`, `specStep`, the observation `Obs`/`obs`/`obsRow`, the
catalog and probe alphabet). No theorems; the shape
`specStep a γ = liftStep a γ (fS (sig a γ))` is definitional, which is the
bounded form of the paper's factorization lemma
(`specStep_factored : specStep = implStep fS := rfl`, **P**).

### `Bounded/Enum.lean` — **Theorem B (finiteness)**

| name | status | note |
| ---- | ------ | ---- |
| `FinEnum Outcome`, `Inv` | P | |
| `FinEnum Component`, `LState`, `Fiber`, `finEnumConfig` | P | `noncomputable` — see §5, deviation D5 |
| **`config_finite : ∀ γ : Config, γ ∈ (all : List Config)`** | **P** | **Theorem B**, fully structural, axiom-free (`propext`, `Quot.sound` only) |

### `Bounded/Explore.lean` — **Theorem C (explorer soundness + completeness)**

| name | status | note |
| ---- | ------ | ---- |
| `Reachable` (inductive), `runFrom`, `succsOf` | — | definitions |
| `reachable_of_run`, `runFrom_append`, `mem_succsOf`, `succsOf_mem` | P | |
| `expand` (worklist explorer) and its correctness lemmas: `expand_seen_mono`, `expand_pathsOK`, `expand_closedExcept`, `addNew_spec`, `addNew_covers`, `foldl_addNew_*` | P | the *generic* explorer is verified; it is not on the shipped path — see §5, deviation D6 |
| **`complete_of_closed`** | **P** | generic Theorem C2: any γ₀-containing, `succsOf`-closed list contains every reachable state |
| `fastExpand`, `visitedP`, `visited` | — | the shipped exploration (hash-backed); nothing is *proved* about it, everything is *checked* about its output |
| `explore_sound_core` | **N** | every explored pair replays: `runFrom γ0 p.2 = some p.1`, word ⊆ `catalogActs` |
| **`explore_sound : PathsOK visitedP`** | N | **Theorem C1 (soundness)** |
| `visited_sound : ∀ γ ∈ visited, Reachable γ` | N | via C1 |
| `gamma0_visited` | **N** | |
| `visited_closed` | **N** | |
| **`explore_complete : ∀ γ, Reachable γ → γ ∈ visited`** | N | **Theorem C2 (completeness)**, from `complete_of_closed` |
| **`reachable_iff_visited : Reachable γ ↔ γ ∈ visited`** | N | **Theorem C**, the two halves combined |
| `visited_card : visited.length = 15173` | **N** | the reported state count, machine-checked |

### `Bounded/Equiv.lean` — **Theorem A (equivariance)**

| name | status | note |
| ---- | ------ | ---- |
| `key_cases`, `FinEnum Ren`, `allRens` (24 renamings) | P | |
| the action: `KMap.ren`, `SMap.ren`, `renStep`/`renScript`/`renKSet`/`renTable`/`renView`/`renComponent`/`renInv`/`renAcc`/`renLState`/`renFiber`/`renConfig`/`renAct`/`renEvent`/`renEv`/`renRow` | — | definitions |
| `KMap.ren_get(')`, `SMap.ren_get(')`, `renConfig_get` | P | |
| `renLState_isActive`, `renLState_viewOf`, `renLState_isInstalled`, `renTable_get`, `renKSet_get` | P | |
| **`provP_ren`** | **P** | Lemma 1 atom (1): the provider predicate is equivariant. Structural, axiom-free |
| **`WF_ren`** | **P** | Lemma 2, well-formedness clause: the single-source discipline is preserved by every renaming. Structural, axiom-free |
| `renFixesChild`, `kRens` | — | the subgroup fixing the hard-wired `childComp` |
| `kRens_card : kRens.length = 12`, `kRens_kp` | **K** | kernel `decide`: exactly the 12 renamings with `kp = false` |
| **`theoremA`** | **N** | **Theorem A**: `∀ γ ∈ visited, ∀ r ∈ kRens, ∀ a ∈ catalogActs, specStep (r·a) (r·γ) = (r·) <$> specStep a γ` — 15 173 × 12 × 45 ≈ 8.2 M checks |
| **`sig_invariant`** | **N** | Lemma 1 (κ-invariance): `sig (r·a) (r·γ) = sig a γ` over the same domain |
| `fS_sig_invariant` | P | corollary of `sig_invariant` |

**Weakening, stated plainly.** Theorem A is *not* proved for all of `Config`;
it is proved for all **reachable** configurations, all 45 probe labels, and
the 12-element subgroup of renamings that fix `childComp`. See §5,
deviations D1, D2, D3.

### `Bounded/Charact.lean` — **Theorem D (bounded characterization)**

| name | status | note |
| ---- | ------ | ---- |
| `implStep`, `certOf`, `rowOf`, `nextState`, `runObs`, `runState`, `suite`, `AgreesOnTB`, `AgreesOnReach`, `IsBisim`, `Bisimilar` | — | definitions |
| `specStep_factored : specStep = implStep fS` | **P** | by `rfl`; bounded factorization |
| `wf_visited : ∀ γ ∈ visited, WF γ` | **N** | the single-source discipline holds at every reachable state |
| **`reflect_fails`** | **N / NEG** | **certificate-free observation reflection is FALSE at this bound** — see §4 |
| `table_eq_of_cert`, `step_eq_of_table` | **P** | reflection *with* certificates, definitional |
| `runObs_append`, `runObs_length`, `runState_runFrom`, `mem_visitedP_of_visited`, `suite_words_catalog` | P | |
| `traj_forcing` | P | certified trajectory equality forces state equality |
| **`agree_pointwise : AgreesOnTB fI → AgreesOnReach fI`** | P | (rests on the explorer's N-facts) |
| `runObs_eq_of_agree`, `agreesOnTB_iff_reach` | P | converse direction, unconditional |
| `bisim_runObs` | P | |
| **`theoremD : AgreesOnTB fI ↔ Bisimilar fI fS`** | **P** | **Theorem D**, fully structural. No computational step of its own; it inherits only the three explorer `native_decide` facts |

### `Bounded/Cutoff.lean` — **Theorems E and F**

| name | status | note |
| ---- | ------ | ---- |
| `ConfB` | — | agreement at *every* bounded configuration, reachable or not |
| **`transport_cutoff`** | **AX** | **Theorem E** — the single named axiom. See §3.2 |
| `confB_eq` | P | |
| **`theoremF`** | P + AX | **Theorem F**: the three unconditional equivalences plus `AgreesOnTB → ConfB` under the axiom |
| `conformance_iff_passes_suite : Bisimilar fI fS ↔ AgreesOnTB fI` | P | unconditional, axiom-free of `transport_cutoff` |
| `passes_suite_implies_confB` | P + AX | |

---

## 3. Added trust: every `native_decide`, and the axiom

### 3.1 `native_decide` — eight uses

`native_decide` evaluates a decidable proposition with the **compiled**
Lean evaluator and accepts the result via `Lean.ofReduceBool`. It therefore
trusts the Lean compiler, the runtime, and this machine's execution, in
addition to the kernel. Each use below appears in `#print axioms` as its own
`…_native.native_decide.ax_1_1`. There are eight, and no others.

| # | theorem | file:line | what is computed | cost |
| - | ------- | --------- | ---------------- | ---- |
| 1 | `explore_sound_core` | `Explore.lean:425` | replay each of 15 173 recorded access words from γ₀ and check it lands on its state, and that every letter is a catalog label | ≈ 10 s |
| 2 | `gamma0_visited` | `Explore.lean:431` | γ₀ ∈ `visited` | < 1 s |
| 3 | `visited_closed` | `Explore.lean:439` | for all 15 173 states and all 77 295 successor edges, the successor is in `visited` | ≈ 35 s |
| 4 | `visited_card` | `Explore.lean:442` | `visited.length = 15173` | < 1 s |
| 5 | `wf_visited` | `Charact.lean:49` | the single-source discipline at all 15 173 states (2 keys × 3 × 3 slot pairs each) | < 1 s |
| 6 | `reflect_fails` | `Charact.lean:62` | *finds a counterexample* to certificate-free reflection | < 1 s |
| 7 | `theoremA` | `Equiv.lean:267` | 15 173 × 12 × 45 ≈ 8.2 M successor-equivariance equations | ≈ 110 s |
| 8 | `sig_invariant` | `Equiv.lean:280` | 15 173 × 12 × 45 ≈ 8.2 M signature-invariance equations | ≈ 110 s |

Uses 1–4 are the explorer certificate; 5 is a state invariant; 6 is a
negative result (so its trust burden is the mildest kind — it asserts that a
counterexample *exists*, and the witness can be re-extracted by running the
explorer); 7–8 are Theorem A.

Facts 1, 2 and 3 are the *only* ones that Theorem D and Theorem F depend on.
Theorems A and B do not depend on each other or on the explorer.

`decide` (kernel-checked, **no** added trust) is used in
`Perm.lean` (`ap_inv_ap`, `inv_ap_ap`, `ap2_ap2`), in `Equiv.lean`
(`kRens_card`, `kRens_kp`) and inline in `SigDec.lean` for the script-length
side conditions.

### 3.2 The one axiom

```lean
axiom transport_cutoff (fI : SigR → Dec) : AgreesOnReach fI → ConfB fI
```

* **File:** `Bounded/Cutoff.lean:58`.
* **Paper lemma it corresponds to:** Lemma 4 (transport), §6.2, clauses
  (1)–(3), consumed as described in Remark 2 ("the suite pins `f_r^I` at the
  canonical window, and transport carries the per-occurrence pin
  everywhere"). It is the paper's Track-M obligation D2 names as *Transport*.
* **What it asserts here:** if a clause-factored bounded implementation's
  decision table agrees with the specification's at every window of a
  *reachable* configuration, then the two successor functions agree at
  *every* configuration of the bounded domain.
* **Why it is not mechanized:** the conclusion quantifies over all ≈2.68·10⁴¹
  configurations of `Config` and over signatures the reachable windows never
  exhibit. Theorem B gives finiteness, not tractability. The paper's proof
  does not enumerate either — it argues that both sides factor through κ,
  that a decision is a function of the occurrence multiset alone (CF3), and
  that `liftStep` is the same operator on both sides so the frames
  correspond. That argument is on paper; this axiom is its interface.

**Complete axiom audit** (`#print axioms`, run on the built library):

| theorem | axioms beyond `propext`, `Quot.sound` |
| ------- | ------------------------------------- |
| `config_finite` (B) | *none* |
| `provP_ren`, `WF_ren` | *none* (`propext` only) |
| `complete_of_closed` | *none* |
| `specStep_factored` | *none* |
| `kRens_card`, `kRens_kp` | *none* |
| `theoremA` | `theoremA._native…` |
| `sig_invariant` | `sig_invariant._native…` |
| `explore_sound`, `visited_sound` | `explore_sound_core._native…` |
| `explore_complete` | `gamma0_visited._native…`, `visited_closed._native…` |
| `reachable_iff_visited` (C) | the three explorer natives |
| `wf_visited` | `wf_visited._native…` |
| `reflect_fails` | `reflect_fails._native…` |
| `theoremD` (D) | the three explorer natives |
| `agree_pointwise`, `agreesOnTB_iff_reach`, `conformance_iff_passes_suite` | the three explorer natives |
| `theoremF` (F), `passes_suite_implies_confB` | the three explorer natives **+ `transport_cutoff`** |

`Classical.choice` is used **nowhere** in the development.

---

## 4. A negative result the mechanization produced

`reflect_fails` (`Charact.lean`) is not a scaffolding lemma; it is a finding.
The previous draft of this development asserted the *positive* statement

```lean
∀ p ∈ visitedP, ∀ a ∈ catalogActs, ∀ d : Dec,
  obsRow (liftStep a p.1 d) = obsRow (specStep a p.1) →
  liftStep a p.1 d = specStep a p.1
```

("observably equal rows at a reachable state force equal transitions", the
bounded form of obligation CF4) and left it to `native_decide`. Evaluated, it
is **false**: at the shipped bound there exist a reachable state, a probe
label, and a decision producing the same event word and the same successor
*observation* as the specification, yet a different successor *state*.

This is exactly what §6.3 of the paper proves in general — reflection is
false in the event-and-report vocabulary alone, and transition certificates
are what restore it. The mechanization has therefore been rebuilt the way the
paper prescribes: a test row is
`(certificate, observation)` where the certificate is `(rule, sig, decision)`
(§5.4's `V_{r,s}`), and with certificates reflection becomes *definitional*
(`table_eq_of_cert`, `step_eq_of_table`). Theorem D then goes through with no
computational step at all.

A second, related asymmetry is recorded in Theorem F and is not an oversight:
`ConfB → AgreesOnTB` is **false**. `liftStep` is not injective in its
decision argument, so two tables can induce the same successor function at
every configuration while differing at a signature whose window makes the
difference inert (e.g. `fire std` vs `fire fifoAcc` at a signature forcing an
empty accumulator). The suite sees it because it compares certificates; the
successor function does not. Theorem F is therefore stated as three
unconditional equivalences plus the one-directional cutoff implication.

---

## 5. Deviations from MASTER.md and from the paper's stated bound

**D1 — tags are not permuted.** `Ren` permutes slots, keys and values; tags
are fixed. The paper's Lemma 2 covers four sorts. Tags occur only as opaque
payloads of `track`/`untrack` and are never compared by any premise, so the
tag component of equivariance is the trivial one; it is simply not
mechanized.

**D2 — Theorem A holds for a subgroup, and this is forced.** `execStep`'s
`register` case instantiates a *hard-wired* child component `childComp` whose
script names key 0. A renaming that swaps the two keys therefore does not
commute with registration: `renComponent r childComp ≠ childComp`. Theorem A
is stated for `kRens`, the 12 renamings that fix `childComp` (kernel-checked
to be exactly those with `kp = false`: all 6 slot permutations × both value
permutations). Removing the restriction would require making the registered
child a parameter of the calculus rather than a constant.

**D3 — Theorem A is proved on the reachable domain, not all of `Config`.**
Two reasons, one practical and one mathematical. Practical: `Config` has
≈2.68·10⁴¹ inhabitants. Mathematical: `providerOf` resolves a key by a
least-slot scan of `allSlots`, which is equivariant **exactly when the
provider is unique**, i.e. under `WF`. `wf_visited` establishes `WF` at every
reachable state, so the reachable domain is precisely where the scan is
canonical. The structural halves that hold everywhere — `provP_ren` and
`WF_ren` — are proved for all configurations and all 24 renamings.

**D4 — `decidableBallFinEnum` is `priority := low`.** `∀ x ∈ l, p x` unfolds
to `∀ x, x ∈ l → p x`, which the `FinEnum` instance would otherwise resolve by
enumerating the whole type instead of walking the list. At `α = Config` that
is the difference between 15 173 states and 2.68·10⁴¹.

**D5 — Theorem B's instances are `noncomputable`.** A Lean top-level constant
of non-function type is materialized by the compiled module's *initializer*.
Left computable, `finEnumConfig` makes every program and every
`native_decide` that transitively imports `Bounded/Enum.lean` attempt to build
the full enumeration of `Config` before executing an instruction — this is
what made the previous draft hang. `noncomputable` erases the code, not the
definition: the kernel still sees the enumeration and its completeness proof,
which is the entirety of Theorem B's claim.

**D6 — the shipped exploration is certificate-checked, not
construction-verified.** `expand` (linear-scan worklist) and its correctness
lemmas are retained and proved, but the shipped `visitedP` is produced by
`fastExpand`, a hash-backed worklist about which nothing is proved. This is
sound because Theorem C needs only three *checkable* properties of the
resulting list — every entry replays from γ₀, γ₀ is present, the list is
`succsOf`-closed — and all three are checked (`native_decide` uses 1–3),
after which `complete_of_closed` is a structural proof. The linear-scan
explorer costs ≈6·10⁸ structural comparisons per evaluation, which every
`native_decide` would repeat.

**D7 — the catalog is three components, not six.** `setval` and the second
key/value are present in the step grammar, the state space and Theorem A, but
are not exercised by the catalog. The previous author's note in
`Bounded/SigDec.lean` records 157 230 states for a full six-component
catalog; that figure is inherited and has **not** been re-verified here — the
only counts this session measured are the ones in §1. The three-component
catalog reaches 15 173 and exercises registration, the
ancestor-committed read, the reliance guard, LIFO accumulator recovery and
L-Raise with a non-empty accumulator.

**D8 — `BList.push` truncates at the bound.** Pushing onto a full bounded
list is a no-op rather than an error. On specification runs the bound is
never reached (accumulator growth is dominated by script consumption, and
both are bounded by 3).

**D9 — determinism per label.** In this encoding the successor is a *function*
of the label; the calculus's nondeterminism is the choice of enabled label,
which the explorer enumerates exhaustively. `IsBisim` is stated for that
setting, and termination-sensitivity does not arise because every probe is a
single step.

---

## 6. What a reader may conclude — and what remains on paper

**What is machine-checked.** At the bound *B* above, with the three-component
catalog and its 45 probe labels, the following are established inside Lean,
with no `sorry` and with exactly one named axiom:

The bounded configuration type is finite, with an explicit complete
enumeration and decidable equality (Theorem B — fully structural, no computation
and no axioms). Its reachable part under the probe alphabet, starting from the
empty registry, consists of exactly 15 173 configurations, and the explorer's
output is *provably* that set: every listed state comes with an executable
access word that replays to it, and the set is closed under every enabled
transition, so it is sound and complete for the inductively defined
reachability relation (Theorem C). At every one of those 15 173 states the
single-source discipline holds; the specification's successor function is
equivariant under the 12 renamings that fix the registered child component,
and its normalized rule signature is literally unchanged by those renamings
(Theorem A, and the paper's Lemma 1 in bounded form). And a clause-factored
bounded implementation — any function of the form
`liftStep a γ (fI (sig a γ))` — passes the generated suite `T_B` **if and
only if** it is certified-observation-bisimilar to the specification on the
bounded domain, and **if and only if** its decision table agrees with the
specification's at every reachable window (Theorem D, and the unconditional
part of Theorem F). That last equivalence is proved structurally: it does not
depend on any computation of its own, only on the three explorer facts.

The mechanization also *falsifies* the certificate-free form of observation
reflection at this bound, confirming §6.3's claim that transition
certificates are necessary, and it exhibits the corresponding one-way failure
in Theorem F (`ConfB` does not imply suite agreement).

**What is assumed.** One axiom, `transport_cutoff`, corresponding to the
paper's Lemma 4 (transport). It carries the pin from reachable windows to the
whole bounded domain. Everything that uses it says so in its `#print axioms`
output; the characterization theorem D and the equivalence
`conformance_iff_passes_suite` do **not** use it.

**What is trusted beyond the kernel.** Eight `native_decide` calls (§3.1).
A reader who declines compiler trust retains Theorem B, `specStep_factored`,
`provP_ren`, `WF_ren`, `complete_of_closed`, `table_eq_of_cert`,
`step_eq_of_table` and `kRens_card` — that is, the whole *structural* skeleton
— but loses the concrete identification of the reachable set, and with it the
instantiations of Theorems A, C and D at the shipped catalog.

**What remains on paper, and is not even bounded here.** The unbounded
theorem — `I ∈ 𝔦_CF ⟹ (I conf S ⟺ I ⊨ T⋆)` — is not mechanized in any form.
Specifically: (i) the cutoff from bound *B* to arbitrary bounds, and from the
bounded state space to the full calculus, is the paper's transport plus
shortest-counterexample and ranking arguments, of which only transport is
represented here, as an axiom; (ii) the safety direction by shortest
counterexample and the termination direction by ranking (§6.4, §6.5) have no
counterpart in this development — the bounded systems are one-step-per-probe,
so termination-sensitivity never arises; (iii) the coeffect operation clauses
of Appendix D.11–D.14 (isolation, interception, Algorithm 6 proxy access) are
not modelled: `readC` implements the committed/IA/ancestor/UD discipline only;
(iv) the reachability column of Appendix D — which signatures are reachable in
the *unbounded* system, including its six negative claims — is not formalized;
the mechanization determines reachability only at bound *B* with this catalog.
Nothing in §6 of the paper depends on this development; as §7 states, the
dependency runs the other way.
