# Appendix E. Manual State-Space Computations

*Companion to D1 (`signatures.md`) and the manuscript (`paper.md`). This
appendix carries out, by hand, the state-space computations that D1's
derivation sketches only outline: for every canonical script
$\rho_{r,s}$ of D1 (all 60) an explicit configuration sequence
$\gamma_0 \to \gamma_1 \to \cdots \to \gamma_k$, one line per rule
application, each line checkable against the rule statements of [SZC26]
§4.2–§4.3 (pp. 31–38; summarized in Table 1) with nothing else at hand;
and for each of D1's six interface-unrealizable occurrences a complete
invariant proof. Internal references Def. 43–53, Thm. 63/66 are to
[SZC26]; occurrence ids I1–I7, R1–R4, M1–M7, B1–B7, T1–T11, F1–F3,
D1–D6, X1–X9, V1–V5, U1–U12, P1–P6, S1–S4, N1–N4, A1–A7 are D1's
(§§1.1–14.1 of `signatures.md`); script ids S-⋆ are D1's §§1.4–14.3.*

---

## E.0 Conventions

### E.0.1 Configuration display

A configuration $\gamma$ is displayed as a block: one row per registered
fiber, then the derived context.

```
γi   P: Act⟨g=[pv⁻(k1), a⁻]; ω={}⟩            | τ=⊥ | σ={k1↦v1}
     C: Rel⟨i=[read(k1)]; g=id; ω={k1↦P}⟩     | τ=⊥ | σ=∅   | π=P
     σ_γ = {k1↦v1 @P}     quiet: no
```

- **θ abbreviations** (Def. 49): `In(⊥)`, `In(ξ:x)` (failed with error
  x), `Rel⟨i; g; ω⟩`, `Act⟨g; ω⟩`, `Unl⟨g; ω; ζ⟩`.
- **i** — the remaining step list of the effect iterator (Defs. 49/51),
  in the §2.2 script syntax. `i=[]` means the next application yields
  `Nothing`.
- **g** — the accumulator, displayed **in push order**
  `[h₁⁻, h₂⁻, …]`; L-Unload applies it **right-to-left** (LIFO,
  Def. 52/eq. 48). Item forms: `pv⁻(k)` (provide inverse: withdraw the
  binding), `t⁻` (track inverse: emit `inv(n,t)`), `reg⁻(C)` (register
  inverse: O-Retire the child, Def. 47), `ror⁻(k,t)` (read-on-revert
  inverse, Def. 48 cl. 2; A7 grammar extension). `g=id` = no items.
- **ω** — the committed view as `{k↦provider}`; `{}` is the empty total
  map of a dependency-free fiber (`{} ≠ ⊥`).
- **τ** shown as `⊥`/`⊤`; **σ** the fiber's own table, keyed by
  declared key (the storage label ℓ(k) is spelled out only in the
  isolation items E.CS.⋆, E.LR.X4, E.CA.A6, where it differs from k).
- **π** shown only when ≠ root.
- **σ_γ** — the derived context (eq. 40): union of **Active** tables
  only, annotated with the provider. **quiet** — eq. 45, stated with
  the deciding clause when non-obvious.
- Rows omitted from a display are unchanged from the last full display;
  removed fibers are dropped with a note.

### E.0.2 Step lines

Three line forms, numbered `(1), (2), …` within each item:

1. **Orchestration input** (O-rules and the coeffect inputs):
   `γi ⇒ γj  [O-Insert @P ⊳ insert(root,P)]` followed by the premise
   checks and the window's occurrence multiset κ. `isolate/intercept`
   inputs edit the ambient resolution context (Defs. 28/31), not the
   registry, and are displayed as ambient-table updates. `update/setval`
   are the A3-extension inputs (D1 §17).
2. **Lifecycle / removal step**: `γi → γj  [L-Iter @C]` followed by
   *every* premise of the rule with its value read off the displayed
   γi, the window multiset κ, the events emitted, and the fields
   written ("writes: …" — the configuration delta).
3. **Evaluated-but-disabled (or refused) attempt**:
   `γi ⊘ [L-Begin @C2]` — not a transition; displays the window, names
   the failing premise, and (for orchestration inputs) the refusal
   event. Blocking occurrences (D1's "refusing"/"blocking" letters) are
   realized at exactly these lines.

The **pointed configuration** at which the item's target signature is
realized is marked `★` on its step line. Every item ends at the
quiescent configuration (eq. 45 checked per fiber) with the report, and
states the **realized occurrence multiset** — the target occurrence(s)
plus load-bearing co-realizations. Multiset multiplicities are written
`U6·3`.

### E.0.3 Rule premises as checked (the checklist a referee applies)

For each rule application line, the premises verified are exactly:

| rule | premises checked on the displayed γ |
| --- | --- |
| O-Insert | n ∉ dom F; π ∈ dom F ∪ {root}; (d,p,e) ∈ 𝕮_Γ; ∀m ∈ dom F. p ∩ p_m = ∅ |
| O-Retire | n ∈ dom F |
| O-Remove | τ_n=⊤; θ_n=In(−); ∀m. π_m ≠ n |
| L-Begin | θ_n=In(⊥); ω := target_n(γ) ≠ ⊥ |
| L-Iter | θ_n=Rel⟨i;g;ω⟩; target_n(γ)=ω; i(γ)=Right(δ,h,Just i′) |
| L-Finish | θ_n=Rel⟨i;g;ω⟩; target_n(γ)=ω; i(γ)=Right(δ,h,Nothing) |
| L-Divert | θ_n=Rel⟨i;g;ω⟩; target_n(γ)≠ω; (δ,h)=(γ,id) [abort] ∨ i(γ)=Right(δ,h,−) [land] |
| L-Raise | θ_n=Rel⟨i;g;ω⟩; i(γ)=Left(ξ) |
| L-Leave | θ_n=Act⟨g;ω⟩; target_n(γ)≠ω |
| L-Unload | θ_n=Unl⟨g;ω;ζ⟩; ¬relied_n(γ); g(γ)=δ |

with target_n (Def. 46: ⊥ iff τ_n ∨ ¬(γ ⊨ d_n), else k ↦
provider_k(γ) read off σ_γ), relied_n (Def. 50: ∃m≠n, k∈d_m.
installed_m ∧ ω_m(k)=n), installed = θ ≠ In(−) (eq. 44). Settle runs
lifecycle steps and O-Remove (D1 A1 reading) until quiet(γ) (eq. 45).
Every step-execution inside L-Iter/L-Raise windows is additionally
checked against Def. 23 (set precondition), Def. 24 (A_k precondition),
Def. 47 (registration = O-Insert with π=n; inverse = O-Retire),
Algorithm 6 (the access walk, with D1's A6 landing convention and A8
boundary refinement), and Defs. 28/29/31 for the coeffect inputs.

### E.0.4 Schedules

Where a settle has more than one enabled rule, the line notes the
enabled set and either (a) proves the realized signature
schedule-invariant (the branches commute to the same window), or (b)
names the **canonical schedule** and derives it, listing the other
branches' outcomes — the occurrence is then *schedule-dependent* and
the item says so explicitly, per D1 §0's convention; the verdict
V_{r,s} compares full outcome sets over all fair schedules, so both
sides of the branch belong to Out(ρ).

---

## Corrections to D1 (read first)

The line-by-line expansion found one script **wrong**, one alphabet
imprecision, and two points needing a stated reading. Details in
§E.98; the derivations below use the corrected forms.

- **C1 (error — S-Div-3 / signature D3).** D1's printed script
  `insert(root,Q); insert(root,G); settle; retire(Q); retire(G);
  insert(root,Q2); settle` does **not** reach D3: `insert(root,Q2)` is
  **refused** by O-Insert's premise ∀m ∈ dom F. p ∩ p_m = ∅, because
  the retired Q is still registered with p_Q = {k2} = p_{Q2} — exactly
  the fact D1 itself establishes at §1 (I7: "the check is against
  *declared* provisions", only O-Remove frees keys) and uses in
  S-Ins-4. With Q2 refused, C never re-begins, so C is never Reloading
  when τ_C flips: the printed run realizes V3/U-occurrences but no D3.
  The corrected script splits the settle so Q is *removed* before Q2 is
  inserted:
  `insert(root,Q); insert(root,G); settle; retire(Q); settle;
  insert(root,Q2); retire(G); settle` — full derivation at E.LD.D3.
- **C2 (reading — U10–U12 bookkeeping).** D1's S-Unl-3 window is
  printed `{U1, U4, U6}` with no τ×post-target letter, yet its atoms
  (τ=⊥, post-target satisfiable) match U12 literally — whose gloss
  ("successor: immediate re-begin") is false for a ζ=ξ unload, since
  Inactive(ξ) blocks L-Begin (B2). Adopted reading, consistent with
  every D1 window listing: **U10–U12 are conditioned on ζ=⊥**; a ζ=ξ
  unload's successor is fixed by B2 and carries no bookkeeping letter.
- **C3 (clarification — S-Rem-2 / M2).** The never-enabled removal
  window of an unretired Active fiber is the multiset {M2, M5, M6},
  not {M2} alone; M2 is the credited (deciding-first-failing) letter.
  D1's claim "S-Rem-2 realizes M2" stands; the full multiset is stated
  at E.OM.M2. Not an error — D1 §0 allows co-realization — but the
  multiset must be stated to be checkable.
- **C4 (alphabet imprecision — L-Finish F1/F2).** A finishing window
  after ≥ 1 landed iteration whose iterations pushed no inverse
  (read-only scripts) matches neither F1's printed atom ("accumulator
  ≠ id") nor F2's ("first iteration already Nothing"). Adopted
  reading: the split follows the **iterator history** (F2 iff the
  first application yields Nothing), the accumulator constructor being
  an equality pattern inside the letter. Detail in §E.98; no script or
  reachability claim changes.

---

## E.1 O-Insert

### E.OI.I1 — signatures I1, I4, I6 (script S-Ins-1)

**Script.** `P := (d=∅, p={k1}, S=[provide(k1,v1)])`;
ρ = `insert(root, P); settle`.

**Derivation.**

```
γ0   (empty registry)      σ_γ = ∅
```

(1) ★ γ0 ⇒ γ1 [O-Insert @P ⊳ insert(root,P)] — premises: n_P ∉ dom F ✓
(dom F = ∅); π = root ∈ dom F ∪ {root} ✓ (**I1**); (d,p,e) ∈ 𝕮_Γ ✓
(static); ∀m ∈ dom F. {k1} ∩ p_m = ∅ ✓ (vacuous — no registered m, so
the k1 witness is clear: **I6(k1)**); freshness **I4**.
κ = **{I1, I4, I6(k1)}**. Writes: F[P ↦ ⟨∅,{k1},e,root,∅,⊥,In(⊥)⟩].

```
γ1   P: In(⊥) | τ=⊥ | σ=∅          σ_γ = ∅     quiet: no (target_P ≠ ⊥)
```

⟨settle⟩ — sole enabled rule at each step:

(2) γ1 → γ2 [L-Begin @P] — θ_P = In(⊥) ✓; target_P(γ1): τ_P=⊥, d_P=∅ so
γ ⊨ d_P vacuously, target = {} ≠ ⊥ ✓. κ = {B1, B3}.
Writes: θ_P ↦ Rel⟨[provide(k1,v1)]; id; {}⟩.

(3) γ2 → γ3 [L-Iter @P] — θ_P = Rel ✓; target_P(γ2) = {} = ω ✓;
i(γ2) = Right(δ, pv⁻(k1), Just i′) — step provide(k1,v1), Def. 23 set
precondition: k1's label unbound in every table ✓ (all tables empty).
κ = {T1, T3} (co-realizes CP.P1). Writes: σ_P := {k1↦v1},
g := [pv⁻(k1)], i := [].

(4) γ3 → γ4 [L-Finish @P] — θ_P = Rel ✓; target = {} = ω ✓;
i(γ3) = Right(δ, id, Nothing) ✓. κ = {F1} (g ≠ id). Emits act(P).
Writes: θ_P ↦ Act⟨[pv⁻(k1)]; {}⟩.

```
γ4   P: Act⟨[pv⁻(k1)]; {}⟩ | τ=⊥ | σ={k1↦v1}
     σ_γ = {k1↦v1 @P}      quiet: ✓ (target_P = {} = ω_P)
```

**Realized multiset at ★:** {I1, I4, I6(k1)}. Report: P active,
st(k1)=v1. Deterministic (one enabled rule throughout).

### E.OI.I2 — signature I2 (script S-Ins-2)

**Script.** `P := (∅, ∅, [])`, `C := (∅, ∅, [])`;
ρ = `insert(root, P); settle; insert(P, C); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P ⊳ insert(root,P)] — as E.OI.I1(1) with p = ∅:
κ = {I1, I4} (no provision keys → no I6/I7 occurrence).

(2) γ1 → γ2 [L-Begin @P] — In(⊥) ✓, target = {} ≠ ⊥ ✓. κ = {B1, B3}.
θ_P ↦ Rel⟨[]; id; {}⟩.

(3) γ2 → γ3 [L-Finish @P] — target = {} = ω ✓; first iterator
application yields Right(γ, id, Nothing) (empty script). κ = {F2}
(degenerate case, g = id — co-realizes E.LF.F2's letter). act(P).
θ_P ↦ Act⟨id; {}⟩. Quiet ✓.

(4) ★ γ3 ⇒ γ4 [O-Insert @C ⊳ insert(P, C)] — n_C ∉ dom F ✓;
π = P ∈ dom F ✓ (**I2**: ParentClass = present); disjointness ✓
(p_C = ∅). κ = **{I2, I4}**. Writes: F[C ↦ ⟨…, π=P, In(⊥)⟩].

(5) γ4 → γ5 [L-Begin @C] κ = {B1, B3}; (6) γ5 → γ6 [L-Finish @C]
κ = {F2}, act(C). Both Active, quiet ✓.

**Realized multiset at ★:** {I2, I4}. Report: P, C active.
Deterministic.

### E.OI.I3 — signature I3 (script S-Ins-3)

**Script.** `P := (∅, ∅, [])`, `C := (∅, ∅, [])`;
ρ = `insert(root, P); retire(P); settle; insert(P, C)`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4} as above.

(2) γ1 ⇒ γ2 [O-Retire @P ⊳ retire(P)] — P ∈ dom F ✓. κ = {R1}
(θ_P = In(⊥): the "pending" bookkeeping class — co-realizes E.OT.R1's
letter). Writes: τ_P ↦ ⊤.

⟨settle⟩:

(3) γ2 ⊘ [L-Begin @P] — θ_P = In(⊥) ✓ but target_P(γ2) = ⊥ by τ_P = ⊤:
window {B1, B4}, disabled (co-realizes E.LB.B4).

(4) γ2 → γ3 [O-Remove @P] — τ_P = ⊤ ✓; θ_P = In(⊥) matches In(−) ✓;
∀m. π_m ≠ P ✓ (registry = {P}). κ = {M1, M3, M6}.
Writes: γ ∖ P. Registry now empty; quiet ✓ (vacuous).

(5) ★ γ3 ⊘ [O-Insert @C ⊳ insert(P, C)] — n_C ∉ dom F ✓ (I4), but
π = P ∉ dom F ∪ {root} ✗: ParentClass = absent, **I3**. Refused;
refusal event logged. κ = **{I3, I4}**.

**Realized multiset at ★:** {I3, I4}. Outcome:
Refused(w, insert(P,C), q) with q showing the empty registry.
Deterministic.

### E.OI.I7 — signature I7 (script S-Ins-4)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`, `Q := (∅, {k1}, [])`;
ρ = `insert(root, P); insert(root, Q)`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)} as E.OI.I1(1). No settle
runs — P stays In(⊥) with σ_P = ∅.

(2) ★ γ1 ⊘ [O-Insert @Q ⊳ insert(root,Q)] — n_Q fresh ✓ (I4); π = root
✓ (I1); disjointness: ∃ registered m = P with k1 ∈ p_Q ∩ p_P ✗ —
per-key witness **I7(k1)**. Premise (iv) false; refused, refusal event.
κ = **{I1, I4, I7(k1)}**.

**Realized multiset at ★:** {I1, I4, I7(k1)}. Note the load-bearing
fact (D1 §1.3): P is In(⊥) — *declared* provisions block, no settle or
activation needed. Outcome: Refused. Deterministic.

---

## E.2 O-Retire

O-Retire's window is the singleton {R_i}: the rule reads registry
membership only; the state class is write-aspect bookkeeping (D1 §2).

### E.OT.R1 — signature R1 (script S-Ret-1)

**Script.** `C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, C); settle; retire(C); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @C] — fresh ✓, root ✓, p_C = ∅ ✓.
κ = {I1, I4}.

⟨settle⟩:

(2) γ1 ⊘ [L-Begin @C] — θ_C = In(⊥) ✓ (B1), τ_C = ⊥ (B3), but
γ ⊨ d_C fails: k1 ∉ dom σ_γ = ∅ and no table anywhere holds k1 —
KeySat = unprovided, window {B1, B3, B7(k1)} (co-realizes E.LB.B7).
target_C = ⊥: disabled. No rule enabled; O-Remove not enabled
(τ_C = ⊥, window {M2, M3, M6} — co-realizes M2's blocking letter).

```
γ1   C: In(⊥) | τ=⊥ | σ=∅      σ_γ = ∅
     quiet: ✓ (eq. 45 first clause: θ_C=In(⊥) with target_C = ⊥)
```

(3) ★ γ1 ⇒ γ2 [O-Retire @C ⊳ retire(C)] — C ∈ dom F ✓;
θ_C = In(⊥) = "pending" class: κ = **{R1}**. Writes: τ_C ↦ ⊤.

⟨settle⟩:

(4) γ2 → γ3 [O-Remove @C] — τ_C = ⊤ ✓; In(⊥) ✓; childless ✓.
κ = {M1, M3, M6}. Registry empty, quiet ✓.

**Realized multiset at ★:** {R1}. Report: C disposed, never activated
(no act(C) in w). Deterministic.

### E.OT.R2 — signature R2 (script S-Ret-2)

**Script.** `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) γ1 → γ2 [L-Begin @P] — In(⊥) ✓, target {} ≠ ⊥ ✓. κ = {B1, B3}.
θ_P ↦ Rel⟨[track(a)]; id; {}⟩.

(3) γ2 → γ3 [L-Iter @P] — target {} = ω ✓; i(γ2) = Right(δ, a⁻,
Just []) — step track(a), unconditional. κ = {T1, T4}. Emits app(P,a).
Writes: g := [a⁻], i := [].

(4) γ3 → γ4 [L-Finish @P] — i(γ3) = Right(δ, id, Nothing) ✓.
κ = {F1}. act(P). θ_P ↦ Act⟨[a⁻]; {}⟩. Quiet ✓.

(5) ★ γ4 ⇒ γ5 [O-Retire @P] — P ∈ dom F ✓; θ_P = Act ∈ "installed"
class (eq. 44): κ = **{R2}**. Writes: τ_P ↦ ⊤.

⟨settle⟩:

(6) γ5 → γ6 [L-Leave @P] — θ_P = Act⟨[a⁻]; {}⟩ ✓; target_P(γ5) = ⊥
(τ_P = ⊤) ≠ ω = {} ✓. κ = {V1, V3}. θ_P ↦ Unl⟨[a⁻]; {}; ⊥⟩.

(7) γ6 → γ7 [L-Unload @P] — θ_P = Unl ✓; ¬relied_P ✓ (no other fiber);
g applies right-to-left: a⁻ emits inv(P,a). κ = {U1, U3, U6, U10}.
deact(P). θ_P ↦ In(⊥).

(8) γ7 → γ8 [O-Remove @P] — τ=⊤, In(⊥), childless ✓. κ = {M1, M3, M6}.
Registry empty, quiet ✓.

**Realized multiset at ★:** {R2}. Report: P disposed; certificate order
retire < deact(P) < removal distinguishes the installed class.
Deterministic.

### E.OT.R3 — signature R3 (script S-Ret-3)

**Script.** `P := (∅, ∅, [raise(x)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}. θ_P ↦ Rel⟨[raise(x)]; id; {}⟩.

(3) γ2 → γ3 [L-Raise @P] — θ_P = Rel ✓; i(γ2) = Left(x) (step
raise(x)) ✓; no view premise (D1 A2). κ = {X1, X2, X6} (g = id).
θ_P ↦ Unl⟨id; {}; x⟩.

(4) γ3 → γ4 [L-Unload @P] — ¬relied_P ✓; g = id: no inverses.
κ = {U1, U4, U9} (ζ=ξ: no U10–U12 letter, reading C2). deact(P).
θ_P ↦ In(ξ:x).

```
γ4   P: In(ξ:x) | τ=⊥ | σ=∅     σ_γ = ∅
     quiet: ✓ (eq. 45 first clause: ζ = x ≠ ⊥)
```

(5) ★ γ4 ⇒ γ5 [O-Retire @P] — P ∈ dom F ✓; θ_P = In(ξ): "failed"
class, κ = **{R3}**. τ_P ↦ ⊤.

(6) γ5 → γ6 [O-Remove @P] — τ=⊤; In(ξ) matches In(−) ✓; childless ✓.
κ = {M1, M4, M6} (co-realizes E.OM.M4's letter). Registry empty,
quiet ✓.

**Realized multiset at ★:** {R3}. Report: P disposed with recorded
failure x. Deterministic.

### E.OT.R4 — signature R4 (script S-Ret-4)

**Script.** `P := (∅, ∅, [])`;
ρ = `insert(root, P); retire(P); settle; retire(P)`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) γ1 ⇒ γ2 [O-Retire @P] — P ∈ dom F ✓, θ_P = In(⊥): κ = {R1}.
τ_P ↦ ⊤.

⟨settle⟩:

(3) γ2 ⊘ [L-Begin @P] — target ⊥ by τ: window {B1, B4}, disabled.

(4) γ2 → γ3 [O-Remove @P] — τ=⊤, In(⊥), childless ✓. κ = {M1, M3, M6}.
Registry empty, quiet ✓.

(5) ★ γ3 ⊘ [O-Retire @P ⊳ retire(P)] — P ∉ dom F ✗: κ = **{R4}**.
Refused; refusal event logged.

**Realized multiset at ★:** {R4}. Outcome: Refused(w, retire(P), q),
q the empty-registry report. Deterministic.

---

## E.3 O-Remove

Per D1's A1 reading, O-Remove fires during settle whenever its premises
hold; blocked windows are realized as ⊘ lines and observed as fiber
persistence in the report or as certificate order mid-settle.

### E.OM.M1 — signatures M1, M3, M6 (script S-Rem-1)

**Script.** `C := ({k1}, ∅, [])`;
ρ = `insert(root, C); retire(C); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @C] κ = {I1, I4}.

(2) γ1 ⇒ γ2 [O-Retire @C] — C ∈ dom F ✓, In(⊥): κ = {R1}. τ_C ↦ ⊤.

⟨settle⟩:

(3) γ2 ⊘ [L-Begin @C] — window {B1, B4} (target ⊥ by τ; also k1
unprovided but τ decides first — the B-window's RetClass letter),
disabled.

(4) ★ γ2 → γ3 [O-Remove @C] — τ_C = ⊤ ✓ (**M1**); θ_C = In(⊥) ✓
(**M3**); ∀m. π_m ≠ C ✓, no child witness (**M6**).
κ = **{M1, M3, M6}**. Writes: γ ∖ C. Registry empty, quiet ✓.

**Realized multiset at ★:** {M1, M3, M6}. Report: C disposed, never
activated. Deterministic.

### E.OM.M2 — signature M2 (script S-Rem-2)

**Script.** `P := (∅, ∅, [])`; ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}. θ_P ↦ Rel⟨[]; id; {}⟩.

(3) γ2 → γ3 [L-Finish @P] — first application Nothing, g = id.
κ = {F2}. act(P). θ_P ↦ Act⟨id; {}⟩.

(4) ★ γ3 ⊘ [O-Remove @P] — τ_P = ⊥ ✗ (**M2**, the deciding failure);
θ_P = Act ∈ {Rel, Act, Unl} (M5 atoms also present); childless (M6).
κ = **{M2, M5, M6}** (full multiset per Correction C3; M2 credited).
Disabled — P persists.

```
γ3   P: Act⟨id; {}⟩ | τ=⊥ | σ=∅     σ_γ = ∅   quiet: ✓ (target = {} = ω)
```

**Realized multiset at ★:** {M2, M5, M6}. Report: P **present and
active** — the observation distinguishing the blocking decision (a
spurious-remove deviant would dispose it). Deterministic.

### E.OM.M4 — signature M4 (script S-Rem-3)

**Script.** `P := (∅, ∅, [raise(x)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.** Steps (1)–(4) are E.OT.R3 (1)–(4) verbatim: γ4 has
P: In(ξ:x), τ=⊥, quiet.

(5) γ4 ⇒ γ5 [O-Retire @P] κ = {R3}. τ_P ↦ ⊤.

(6) ★ γ5 → γ6 [O-Remove @P] — τ = ⊤ ✓ (M1); θ_P = In(ξ:x) matches
In(−), constructor selects the failed block: **M4**; childless (M6).
κ = **{M1, M4, M6}**. Registry empty, quiet ✓.

**Realized multiset at ★:** {M1, M4, M6}. Report: P disposed with
recorded failure x in the harness history — the observation
distinguishing M4 from M3. Deterministic.

### E.OM.M5 — signature M5 (script S-Rem-4)

**Script.** `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.** Steps (1)–(4) are E.OT.R2 (1)–(4): γ4 has
P: Act⟨[a⁻]; {}⟩, quiet.

(5) γ4 ⇒ γ5 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.

⟨settle⟩:

(6) γ5 → γ6 [L-Leave @P] — Act ✓, target ⊥ (τ) ≠ {} ✓. κ = {V1, V3}.
θ_P ↦ Unl⟨[a⁻]; {}; ⊥⟩.

(7) ★ γ6 ⊘ [O-Remove @P] — τ_P = ⊤ ✓ (M1) but θ_P = Unl ∉ In(−) ✗:
**M5**, blocking; childless (M6). κ = **{M1, M5, M6}**. Disabled —
removal must wait for L-Unload.

(8) γ6 → γ7 [L-Unload @P] — ¬relied_P ✓; g: inv(P,a).
κ = {U1, U3, U6, U10}. deact(P). θ_P ↦ In(⊥).

(9) γ7 → γ8 [O-Remove @P] — τ=⊤, In(⊥), childless ✓. κ = {M1, M3, M6}.
Registry empty, quiet ✓.

**Realized multiset at ★:** {M1, M5, M6} — a mid-settle window; its
observation is the certificate/event order inv(P,a) ≤ deact(P) <
removal (a remove-before-inactive deviant inverts it and discards the
accumulator). Deterministic.

### E.OM.M7 — signature M7 (script S-Rem-5)

**Script.** `G := (∅, ∅, [register(C), track(a)])`,
`C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle; retire(G); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @G] κ = {I1, I4}.

(2) γ1 → γ2 [L-Begin @G] κ = {B1, B3}.
θ_G ↦ Rel⟨[register(C), track(a)]; id; {}⟩.

(3) γ2 → γ3 [L-Iter @G] — target {} = ω ✓; i(γ2) = Right(δ, reg⁻(C),
Just i′) — step register(C): performs Def. 47's O-Insert (n_C drawn
fresh ✓, π = G ∈ dom F ✓, p_C = ∅ ✓; inner window {I2, I4}); pushes
reg⁻(C). κ = {T1, T10}. Writes: F[C ↦ ⟨…, π=G, In(⊥)⟩],
g_G := [reg⁻(C)].

(4) γ3: enabled = {L-Iter @G, L-Begin @C} — schedule freedom; the item's
target window (step 9) is reached on every branch since it depends only
on the final registry shape, which both orders produce (the branches
commute: G's remaining steps touch no field C's activation reads, and
conversely). Canonical: continue G.
γ3 → γ4 [L-Iter @G] — step track(a). κ = {T1, T4}. app(G,a).
g_G := [reg⁻(C), a⁻], i := [].

(5) γ4 → γ5 [L-Finish @G] κ = {F1}. act(G). θ_G ↦ Act⟨[reg⁻(C), a⁻]; {}⟩.

(6) γ5 → γ6 [L-Begin @C] — In(⊥) ✓, target {} ≠ ⊥ ✓. κ = {B1, B3}.
(7) γ6 → γ7 [L-Iter @C] — track(b). κ = {T1, T4}. app(C,b).
(8) γ7 → γ8 [L-Finish @C] κ = {F1}. act(C).

```
γ8   G: Act⟨[reg⁻(C), a⁻]; {}⟩ | τ=⊥ | σ=∅
     C: Act⟨[b⁻]; {}⟩ | τ=⊥ | σ=∅ | π=G
     σ_γ = ∅     quiet: ✓
```

(9) γ8 ⇒ γ9 [O-Retire @G] κ = {R2}. τ_G ↦ ⊤.

⟨settle⟩:

(10) γ9 → γ10 [L-Leave @G] — target ⊥ (τ) ≠ {} ✓. κ = {V1, V3}.
θ_G ↦ Unl⟨[reg⁻(C), a⁻]; {}; ⊥⟩.

(11) γ10 → γ11 [L-Unload @G] — ¬relied_G ✓ (C's ω = {} names nobody;
relied reads committed views only, not the fiber tree — p. 35).
g right-to-left: a⁻ emits inv(G,a); then reg⁻(C) performs O-Retire(C)
(premise C ∈ dom F ✓; inner window {R2}): τ_C ↦ ⊤.
κ = {U1, U3, U6, U7, U10}. deact(G). θ_G ↦ In(⊥).

(12) ★ γ11 ⊘ [O-Remove @G] — τ_G = ⊤ ✓ (M1); In(⊥) ✓ (M3); but
∃m = C with π_C = G ✗: witness present, **M7(C)**.
κ = **{M1, M3, M7(C)}**. Disabled — G persists until C is removed.

(13) γ11 → γ12 [L-Leave @C] — Act ✓; target_C = ⊥ (τ_C = ⊤) ≠ {} ✓.
κ = {V1, V3}. θ_C ↦ Unl⟨[b⁻]; {}; ⊥⟩.

(14) γ12 → γ13 [L-Unload @C] — ¬relied_C ✓; inv(C,b).
κ = {U1, U3, U6, U10}. deact(C). θ_C ↦ In(⊥).

(15) γ13 → γ14 [O-Remove @C] — τ=⊤, In(⊥), childless ✓.
κ = {M1, M3, M6}. Writes: γ ∖ C.

(16) γ14 → γ15 [O-Remove @G] — childlessness now ✓: κ = {M1, M3, M6}.
Registry empty, quiet ✓.

**Realized multiset at ★:** {M1, M3, M7(C)}. Report: both disposed;
certificate order C's removal (15) before G's (16) — "removing children
before their parent" (p. 31). Schedule note: (4)/(6) may interleave;
all interleavings give γ8 up to event order app(G,a)/app(C,b),
and the ★ window is schedule-invariant.

---

## E.4 L-Begin

### E.LB.B1 — signatures B1, B3 (script S-Beg-1)

**Script.** `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) ★ γ1 → γ2 [L-Begin @P] — θ_P = In(⊥) ✓ (**B1**); target_P(γ1):
τ_P = ⊥ (**B3**), d_P = ∅ so γ ⊨ d_P vacuously; target = {} ≠ ⊥ ✓;
d_P = ∅ contributes zero KeySat occurrences. κ = **{B1, B3}**.
θ_P ↦ Rel⟨[track(a)]; id; {}⟩.

(3) γ2 → γ3 [L-Iter @P] — track(a). κ = {T1, T4}. app(P,a).
(4) γ3 → γ4 [L-Finish @P] κ = {F1}. act(P). Quiet ✓.

**Realized multiset at ★:** {B1, B3}. Observation: cert(L-Begin, …)
then app(P,a) < act(P). Deterministic.

### E.LB.B2 — signature B2 (script S-Beg-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1), raise(x)])`;
ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.

(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.
θ_P ↦ Rel⟨[provide(k1,v1), raise(x)]; id; {}⟩.

(3) γ2 → γ3 [L-Iter @P] — provide(k1,v1), Def. 23 set precondition ✓
(no table holds k1). κ = {T1, T3}. σ_P := {k1↦v1}, g := [pv⁻(k1)].
Note σ_γ still ∅: P is Reloading, eq. 40 unions Active tables only.

(4) γ3 → γ4 [L-Raise @P] — i(γ3) = Left(x) ✓. κ = {X1, X2, X7}
(g holds a provide⁻¹ item — co-realizes E.LR.X7).
θ_P ↦ Unl⟨[pv⁻(k1)]; {}; x⟩.

(5) γ4 → γ5 [L-Unload @P] — ¬relied_P ✓; g: pv⁻(k1) withdraws the
binding. κ = {U1, U4, U5} (ζ=ξ; reading C2). deact(P).
θ_P ↦ In(ξ:x), σ_P := ∅.

(6) ★ γ5 ⊘ [L-Begin @P] — θ_P = In(ξ:x) ✗: the rule's pattern requires
In(⊥); τ_P = ⊥ (B3-atom holds but the state letter decides): **B2**,
blocking — no lifecycle re-entry from an error outcome (p. 38).
κ = **{B2, B3}**. Disabled.

```
γ5   P: In(ξ:x) | τ=⊥ | σ=∅     σ_γ = ∅
     quiet: ✓ (eq. 45 first clause: ζ = x ≠ ⊥ — despite target_P = {} ≠ ⊥)
```

**Realized multiset at ★:** {B2, B3}. Report: P failed(x), st(k1)
absent; exactly one app-free act-free episode — a begin-from-failed
deviant would show a second activation. Deterministic.

### E.LB.B4 — signature B4 (script S-Beg-3)

**Script.** `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); retire(P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.

(2) γ1 ⇒ γ2 [O-Retire @P] — P ∈ dom F ✓, In(⊥): κ = {R1}. τ_P ↦ ⊤.

⟨settle⟩:

(3) ★ γ2 ⊘ [L-Begin @P] — θ_P = In(⊥) ✓ (B1); target_P(γ2) = ⊥ forced
by τ_P = ⊤ (Def. 46 first clause): **B4**. κ = **{B1, B4}**. Disabled.

(4) γ2 → γ3 [O-Remove @P] — τ=⊤, In(⊥), childless ✓. κ = {M1, M3, M6}.
Registry empty, quiet ✓.

**Realized multiset at ★:** {B1, B4}. Report: P disposed; w contains
neither app(P,a) nor act(P). Deterministic.

### E.LB.B5 — signature B5 (script S-Beg-4)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) verbatim — γ4: P Active, σ_P = {k1↦v1},
σ_γ = {k1↦v1 @P}, quiet.

(5) γ4 ⇒ γ5 [O-Insert @C] — fresh ✓, root ✓, p_C = ∅ ✓. κ = {I1, I4}.

⟨settle⟩:

(6) ★ γ5 → γ6 [L-Begin @C] — θ_C = In(⊥) ✓ (B1); τ_C = ⊥ (B3);
per-key k1: k1 ∈ dom σ_γ with provider_k1(γ5) = P Active — KeySat =
Active-provided, **B5(k1)**; target_C = {k1↦P} ≠ ⊥ ✓.
κ = **{B1, B3, B5(k1)}**. θ_C ↦ Rel⟨[read(k1)]; id; {k1↦P}⟩.

(7) γ6 → γ7 [L-Iter @C] — target_C(γ6) = {k1↦P} = ω ✓;
step read(k1): Algorithm 6 from C: ω_C binds k1 ↦ P; P's table holds
k1 ↦ v1 — hit at self (CA.A1, CP.P5). κ = {T1, T2(k1), T5}.
Emits rd(C,k1,v1). No inverse (g unchanged = id).

(8) γ7 → γ8 [L-Finish @C] — i Nothing; ω(k1) = provider still P.
κ = {F1, F3(k1)}. act(C). θ_C ↦ Act⟨id; {k1↦P}⟩. Quiet ✓.

**Realized multiset at ★:** {B1, B3, B5(k1)}. Report: P, C active,
rd(C,k1,v1) < act(C). Deterministic.

### E.LB.B6 — signature B6 (script S-Beg-5)

**Script.** `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C1 := ({k1}, ∅, [read(k1)])`, `C2 := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); insert(root, C1); settle; retire(P);
insert(root, C2); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(2) γ1 ⇒ γ2 [O-Insert @C1] κ = {I1, I4}.

⟨settle⟩ — C1's begin is disabled ({B1, B3, B7(k1)}) until P is Active,
so P's activation runs first (sole enabled chain):

(3) γ2 → γ3 [L-Begin @P] κ = {B1, B3}.
θ_P ↦ Rel⟨[provide(k1,v1), track(a)]; id; {}⟩.
(4) γ3 → γ4 [L-Iter @P] — provide, precondition ✓. κ = {T1, T3}.
σ_P := {k1↦v1}, g := [pv⁻(k1)].
(5) γ4 → γ5 [L-Iter @P] — track(a). κ = {T1, T4}. app(P,a).
g := [pv⁻(k1), a⁻].
(6) γ5 → γ6 [L-Finish @P] κ = {F1}. act(P). θ_P ↦ Act. σ_γ = {k1@P}.
(7) γ6 → γ7 [L-Begin @C1] — B5(k1): κ = {B1, B3, B5(k1)}.
θ_C1 ↦ Rel⟨[read(k1)]; id; {k1↦P}⟩.
(8) γ7 → γ8 [L-Iter @C1] — read: hit at self. κ = {T1, T2(k1), T5}.
rd(C1,k1,v1).
(9) γ8 → γ9 [L-Finish @C1] κ = {F1, F3(k1)}. act(C1).

```
γ9   P:  Act⟨[pv⁻(k1), a⁻]; {}⟩   | τ=⊥ | σ={k1↦v1}
     C1: Act⟨id; {k1↦P}⟩          | τ=⊥ | σ=∅
     σ_γ = {k1↦v1 @P}     quiet: ✓
```

(10) γ9 ⇒ γ10 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.
(11) γ10 ⇒ γ11 [O-Insert @C2] — fresh ✓, root ✓, p_C2 = ∅ ✓ (note:
d_C2 = {k1} is a *dependency*, not a provision — no conflict with P).
κ = {I1, I4}.

⟨settle⟩. Enabled at γ11: L-Leave @P (target ⊥ by τ ≠ {}) **and**
L-Begin @C2 (P still Active: target_C2 = {k1↦P} ≠ ⊥). **Schedule
freedom** — the B6 occurrence is *schedule-dependent* (D1 §0
convention): it is realized on schedules that evaluate C2's begin
attempt inside P's Unloading window. Canonical schedule: P leaves
first. (Branch B — C2 begins first — derived after the main line.)

(12) γ11 → γ12 [L-Leave @P] — Act ✓, target ⊥ ≠ {} ✓. κ = {V1, V3}.
θ_P ↦ Unl⟨[pv⁻(k1), a⁻]; {}; ⊥⟩. σ_γ = ∅ (P's table {k1↦v1} persists
but leaves the union — eq. 40).

(13) ★ γ12 ⊘ [L-Begin @C2] — θ_C2 = In(⊥) ✓ (B1); τ_C2 = ⊥ (B3);
per-key k1: no Active table holds k1, but the **installed non-Active**
fiber P (Unl) still holds it — KeySat = installed-only-provided,
**B6(k1)**; target_C2 = ⊥: disabled. κ = **{B1, B3, B6(k1)}**.
This is the window separating the calculus from the
`leave-keeps-providing` / `satisfied-by-installed-provider` deviants:
they would fire here.

(14) γ12 → γ13 [L-Leave @C1] — Act ✓; target_C1 = ⊥ (k1 ∉ dom σ_γ)
≠ ω = {k1↦P} ✓. κ = {V1, V4(k1)}. θ_C1 ↦ Unl⟨id; {k1↦P}; ⊥⟩.

(15) γ13 ⊘ [L-Unload @P] — relied_P: C1 installed (Unl) with
ω_C1(k1) = P ✗ — blocked. κ = {U2(C1,k1), U3, U5, U6, U10}.

(16) γ13 → γ14 [L-Unload @C1] — ¬relied_C1 ✓; g = id.
κ = {U1, U3, U9, U11} (τ=⊥, post-target ⊥). deact(C1).
θ_C1 ↦ In(⊥) — ω_C1 discarded as the unload's last act.

(17) γ14 → γ15 [L-Unload @P] — relied_P now clear ✓ (C1 not
installed). g right-to-left: a⁻ emits inv(P,a); pv⁻(k1) withdraws the
binding. κ = {U1, U3, U5, U6, U10}. deact(P). θ_P ↦ In(⊥), σ_P := ∅.

(18) γ15 → γ16 [O-Remove @P] — τ=⊤, In(⊥), childless ✓.
κ = {M1, M3, M6}. Writes: γ ∖ P.

(19) γ16 ⊘ [L-Begin @C1], ⊘ [L-Begin @C2] — both windows now
{B1, B3, B7(k1)}: no table anywhere holds k1. Disabled; quiet ✓
(both In(⊥) with target ⊥).

```
γ16  C1: In(⊥) | τ=⊥ | σ=∅        C2: In(⊥) | τ=⊥ | σ=∅
     σ_γ = ∅   quiet: ✓
```

**Realized multiset at ★:** {B1, B3, B6(k1)}. Report: P disposed;
C1, C2 pending; st(k1) absent.

*Branch B (C2 begins at (12) instead).* C2 commits ω = {k1↦P},
reads k1 (rd(C2,k1,v1)), and on P's subsequent leave either finishes
then leaves (V1, V4) or diverts (D1, D4, D5); in all sub-branches C2
unloads to In(⊥) and P's teardown completes as above. Every fair
schedule quiesces at the same report (P disposed; C1, C2 pending);
Out(ρ) contains the branch event words (with rd(C2,k1,v1)) alongside
the canonical one, and V_{LB,B6} compares the full sets. The *report*
is schedule-invariant; the realized-window set is not — B6 belongs to
the canonical branch, as D1's sketch says.

### E.LB.B7 — signature B7 (script S-Beg-6)

**Script.** `C := ({k1}, ∅, [read(k1)])`; ρ = `insert(root, C); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @C] κ = {I1, I4}.

⟨settle⟩:

(2) ★ γ1 ⊘ [L-Begin @C] — θ_C = In(⊥) ✓ (B1); τ_C = ⊥ (B3); per-key
k1: **no** fiber's table holds k1 (registry = {C}, σ_C = ∅) — KeySat =
unprovided, **B7(k1)**; target_C = ⊥ (¬(γ ⊨ d_C)): disabled.
κ = **{B1, B3, B7(k1)}**. No other rule enabled; O-Remove blocked at
{M2, M3, M6}.

```
γ1   C: In(⊥) | τ=⊥ | σ=∅   σ_γ = ∅
     quiet: ✓ (In(⊥) with target_C = ⊥ — eq. 45 first clause)
```

**Realized multiset at ★:** {B1, B3, B7(k1)}. Report: C pending, no
act(C). Deterministic.

---

## E.5 L-Iter

### E.LI.T1 — signatures T1, T2, T4, T5 (script S-It-1)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [track(a), read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — γ4: P Active, σ_γ = {k1↦v1 @P}, quiet.

(5) γ4 ⇒ γ5 [O-Insert @C] κ = {I1, I4}.

(6) γ5 → γ6 [L-Begin @C] — κ = {B1, B3, B5(k1)}.
θ_C ↦ Rel⟨[track(a), read(k1)]; id; {k1↦P}⟩.

(7) ★ γ6 → γ7 [L-Iter @C] — θ_C = Rel ✓ (**T1**: ¬τ_C, satisfied);
target_C(γ6): provider_k1 = P = ω_C(k1) — per-key ViewRel = key-equal,
**T2(k1)**; i(γ6) = Right(δ, a⁻, Just i′) — step track(a),
unconditional (**T4**). κ = **{T1, T2(k1), T4}**. app(C,a).
g_C := [a⁻], i := [read(k1)].

(8) ★ γ7 → γ8 [L-Iter @C] — T1, T2(k1) as above; step read(k1):
Algorithm 6 from C: ω_C binds k1 ↦ P, P's table holds k1 ↦ v1 — hit at
self, **T5** (co-realizes CA.A1, CP.P5). κ = **{T1, T2(k1), T5}**.
rd(C,k1,v1). i := [].

(9) γ8 → γ9 [L-Finish @C] κ = {F1, F3(k1)}. act(C).
θ_C ↦ Act⟨[a⁻]; {k1↦P}⟩. Quiet ✓.

**Realized multisets at ★:** {T1, T2(k1), T4} then {T1, T2(k1), T5}.
Report: P, C active; app(C,a) < rd(C,k1,v1) < act(C). Deterministic.

### E.LI.T3 — signature T3 (script S-It-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`;
ρ = `insert(root, P); settle`.

**Derivation.** Identical to E.OI.I1 (1)–(4); the ★ is step (3):

(3) ★ γ2 → γ3 [L-Iter @P] — T1 (d_P = ∅: no T2 occurrences); step
provide(k1,v1): Def. 23 set precondition — k1's label unbound in every
fiber's table ✓ (only P registered, σ_P = ∅) — **T3** (co-realizes
CP.P1). The landing writes σ_P := {k1↦v1} and pushes pv⁻(k1) (the
restriction inverse of Def. 23). κ = **{T1, T3}**.

**Realized multiset at ★:** {T1, T3}. Report: P active, st(k1)=v1.
Deterministic.

### E.LI.T6 — signature T6 (script S-It-3)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`G := ({k1}, ∅, [register(C)])`, `C := (∅, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, G); settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — γ4: P Active, σ_γ = {k1↦v1 @P}.

(5) γ4 ⇒ γ5 [O-Insert @G] κ = {I1, I4}.

⟨settle⟩:

(6) γ5 → γ6 [L-Begin @G] — per-key k1 Active-provided:
κ = {B1, B3, B5(k1)}. θ_G ↦ Rel⟨[register(C)]; id; {k1↦P}⟩.

(7) γ6 → γ7 [L-Iter @G] — T1, T2(k1); step register(C): Def. 47
O-Insert (fresh n_C ✓, π = G ✓, p_C = ∅ ✓; inner {I2, I4}); pushes
reg⁻(C). κ = {T1, T2(k1), T10}. F[C ↦ ⟨…, π=G, In(⊥)⟩],
g_G := [reg⁻(C)].

(8) γ7: enabled = {L-Finish @G, L-Begin @C}. Schedule-invariant for the
★ window: G's committed view exists from step (6) on and is what C's
read consults; both orders reach it (Branch: C's begin/read/finish
first — same events, different order; same report). Canonical: finish G.
γ7 → γ8 [L-Finish @G] κ = {F1, F3(k1)}. act(G).
θ_G ↦ Act⟨[reg⁻(C)]; {k1↦P}⟩.

(9) γ8 → γ9 [L-Begin @C] — d_C = ∅: κ = {B1, B3}.
θ_C ↦ Rel⟨[read(k1)]; id; {}⟩.

(10) ★ γ9 → γ10 [L-Iter @C] — T1 (no T2: d_C = ∅); step read(k1):
Algorithm 6 walk from C: (self) ω_C = {} does not bind k1, and
k1 ∉ d_C — no self clause fires; no isolation boundary (all shared
realm); (parent G) ω_G binds k1 ↦ P, P's table holds v1 — **hit at
ancestor**, **T6** (co-realizes CA.A2). κ = **{T1, T6}**.
rd(C,k1,v1). i := [].

(11) γ10 → γ11 [L-Finish @C] — i Nothing after **one landed**
iteration, yet g∘h = id (a read pushes no inverse): this window
matches neither of D1's printed F-atoms; per the Correction-C4
reading the letter follows the iterator history, so κ = {F1} (with
the accumulator constructor id recorded as the letter's equality
pattern, not as its definition). act(C). Quiet ✓.

**Realized multiset at ★:** {T1, T6}. Report: P, G, C active;
rd(C,k1,v1) attributed to the ancestor hit. Schedule note at (8):
both branches realize the ★ window unchanged.

### E.LI.T7 — signature T7 (script S-It-4; the five-component case)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`Q := (∅, {k2}, [provide(k2,v2)])`,
`Q2 := (∅, {k2}, [provide(k2,v2)])`,
`G := ({k1}, ∅, [])`, `C := ({k2}, ∅, [read(k1)])`;
ρ = `insert(root, P); insert(root, Q); settle; insert(root, G); settle;
insert(G, C); settle; retire(P); retire(Q); settle;
insert(root, Q2); settle`.

**Derivation.** Completeness beats brevity; every step follows.

*Phase 1 — providers up.*

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(2) γ1 ⇒ γ2 [O-Insert @Q] — disjointness: {k2} ∩ {k1} = ∅ ✓.
κ = {I1, I4, I6(k2)}.

⟨settle⟩ — enabled: L-Begin @P, L-Begin @Q; independent fibers, the
two activation chains commute (they touch disjoint fields and
σ_γ-keys); canonical order P then Q:

(3) γ2 → γ3 [L-Begin @P] κ = {B1, B3}. (4) γ3 → γ4 [L-Iter @P]
provide(k1,v1) ✓ κ = {T1, T3}; σ_P := {k1↦v1}, g := [pv⁻(k1)].
(5) γ4 → γ5 [L-Finish @P] κ = {F1}; act(P).
(6) γ5 → γ6 [L-Begin @Q] κ = {B1, B3}. (7) γ6 → γ7 [L-Iter @Q]
provide(k2,v2) ✓ (k2 unbound) κ = {T1, T3}; σ_Q := {k2↦v2},
g := [pv⁻(k2)]. (8) γ7 → γ8 [L-Finish @Q] κ = {F1}; act(Q).

```
γ8   P: Act⟨[pv⁻(k1)]; {}⟩ | τ=⊥ | σ={k1↦v1}
     Q: Act⟨[pv⁻(k2)]; {}⟩ | τ=⊥ | σ={k2↦v2}
     σ_γ = {k1@P, k2@Q}     quiet: ✓
```

*Phase 2 — G under the providers.*

(9) γ8 ⇒ γ9 [O-Insert @G] κ = {I1, I4}.
(10) γ9 → γ10 [L-Begin @G] — k1 Active-provided:
κ = {B1, B3, B5(k1)}. θ_G ↦ Rel⟨[]; id; {k1↦P}⟩.
(11) γ10 → γ11 [L-Finish @G] — first application Nothing, g = id.
κ = {F2, F3(k1)}. act(G). θ_G ↦ Act⟨id; {k1↦P}⟩. Quiet ✓.

*Phase 3 — C as orchestrator-inserted child of G.*

(12) γ11 ⇒ γ12 [O-Insert @C ⊳ insert(G, C)] — π = G ∈ dom F ✓ (I2).
κ = {I2, I4}.
(13) γ12 → γ13 [L-Begin @C] — k2 Active-provided (Q):
κ = {B1, B3, B5(k2)}. θ_C ↦ Rel⟨[read(k1)]; id; {k2↦Q}⟩.
(14) γ13 → γ14 [L-Iter @C] — T1, T2(k2); read(k1): walk: (self) k1 ∉
ω_C, k1 ∉ d_C; (parent G) ω_G binds k1 ↦ P, table hit — ancestor hit
(a T6 window, second realization). κ = {T1, T2(k2), T6}. rd(C,k1,v1).
(15) γ14 → γ15 [L-Finish @C] κ = {F1, F3(k2)}. act(C). Quiet ✓.

```
γ15  P: Act⟨[pv⁻(k1)]; {}⟩       | τ=⊥ | σ={k1↦v1}
     Q: Act⟨[pv⁻(k2)]; {}⟩       | τ=⊥ | σ={k2↦v2}
     G: Act⟨id; {k1↦P}⟩          | τ=⊥ | σ=∅
     C: Act⟨id; {k2↦Q}⟩          | τ=⊥ | σ=∅ | π=G
     σ_γ = {k1@P, k2@Q}     quiet: ✓
```

*Phase 4 — tear both providers down; G and C rest pending.*

(16) γ15 ⇒ γ16 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.
(17) γ16 ⇒ γ17 [O-Retire @Q] κ = {R2}. τ_Q ↦ ⊤.

⟨settle⟩. Enabled at γ17: L-Leave @P, L-Leave @Q (both: target ⊥ by τ);
G and C still match their views (P, Q still Active). Schedule freedom:
the two teardown cascades commute — each step below stays enabled
under any interleaving of the other cascade, and the quiescent
configuration is the same (checked: the only cross-dependencies are
the guards, which reference disjoint edges G→P and C→Q). Canonical
order:

(18) γ17 → γ18 [L-Leave @P] κ = {V1, V3}. θ_P ↦ Unl⟨[pv⁻(k1)]; {}; ⊥⟩.
σ_γ = {k2@Q}.
(19) γ18 → γ19 [L-Leave @Q] κ = {V1, V3}. θ_Q ↦ Unl⟨[pv⁻(k2)]; {}; ⊥⟩.
σ_γ = ∅.
(20) γ19 → γ20 [L-Leave @G] — Act ✓; target_G = ⊥ (k1 unprovided)
≠ ω_G ✓. κ = {V1, V4(k1)}. θ_G ↦ Unl⟨id; {k1↦P}; ⊥⟩.
(21) γ20 → γ21 [L-Leave @C] — target_C = ⊥ (k2 unprovided) ≠ ω_C ✓.
κ = {V1, V4(k2)}. θ_C ↦ Unl⟨id; {k2↦Q}; ⊥⟩.
(22) γ21 ⊘ [L-Unload @P] — relied_P: G installed, ω_G(k1) = P ✗.
κ = {U2(G,k1), U3, U5, U10}. Blocked. Similarly ⊘ [L-Unload @Q]
(witness C: {U2(C,k2), U3, U5, U10}).
(23) γ21 → γ22 [L-Unload @G] — ¬relied_G ✓ (no ω names G). g = id.
κ = {U1, U3, U9, U11} (τ_G=⊥, post-target ⊥). deact(G).
θ_G ↦ In(⊥); **ω_G discarded** — the fact phase 5 turns into T7.
(24) γ22 → γ23 [L-Unload @C] — ¬relied_C ✓; g = id.
κ = {U1, U3, U9, U11}. deact(C). θ_C ↦ In(⊥).
(25) γ23 → γ24 [L-Unload @P] — guard clear (G no longer installed) ✓.
pv⁻(k1) withdraws. κ = {U1, U3, U5, U10}. deact(P). σ_P := ∅.
(26) γ24 → γ25 [L-Unload @Q] — guard clear ✓. pv⁻(k2) withdraws.
κ = {U1, U3, U5, U10}. deact(Q). σ_Q := ∅.
(27) γ25 → γ26 [O-Remove @P] κ = {M1, M3, M6}. γ ∖ P.
(28) γ26 → γ27 [O-Remove @Q] κ = {M1, M3, M6}. γ ∖ Q.
(29) γ27 ⊘ [L-Begin @G] {B1, B3, B7(k1)}; ⊘ [L-Begin @C]
{B1, B3, B7(k2)}. Quiet ✓ (G, C pending with target ⊥).

```
γ27  G: In(⊥) | τ=⊥ | σ=∅            C: In(⊥) | τ=⊥ | σ=∅ | π=G
     σ_γ = ∅   quiet: ✓
```

*Phase 5 — Q2 revives C's target; the read meets a pending declarer.*

(30) γ27 ⇒ γ28 [O-Insert @Q2] — disjointness: p_Q2 = {k2}; registered
fibers G, C declare no provisions; **Q was removed at (28)** ✓ — this
is why the settle/insert order matters (contrast Correction C1).
κ = {I1, I4, I6(k2)}.

(31) γ28 → γ29 [L-Begin @Q2] κ = {B1, B3}. (32) γ29 → γ30
[L-Iter @Q2] provide(k2,v2) ✓ κ = {T1, T3}. (33) γ30 → γ31
[L-Finish @Q2] κ = {F1}. act(Q2). σ_γ = {k2@Q2}.

(34) γ31 → γ32 [L-Begin @C] — In(⊥) ✓ (τ_C=⊥ — C was never retired);
k2 Active-provided by Q2: κ = {B1, B3, B5(k2)}.
θ_C ↦ Rel⟨[read(k1)]; id; {k2↦Q2}⟩. (G stays pending: its k1 has no
provider — window {B1, B3, B7(k1)}, disabled.)

(35) ★ γ32 → γ33 [L-Iter @C] — T1, T2(k2); step read(k1):
Algorithm 6 walk from C: (self) ω_C = {k2↦Q2} does not bind k1, and
k1 ∉ d_C — no self clause; no isolation boundary; (parent G)
ω_G is **discarded** (G Inactive — step (23)), but **k1 ∈ d_G**:
Algorithm 6 line 5 — declared-but-uncommitted at an ancestor:
INACTIVE_ACCESS. **T7** (co-realizes CA.A3). By the A6 landing
convention the step lands (Right) with the error as an event.
κ = **{T1, T2(k2), T7}**. Emits rderr(C,k1,IA). i := [].

(36) γ33 → γ34 [L-Finish @C] κ = {F1, F3(k2)}. act(C).
θ_C ↦ Act⟨id; {k2↦Q2}⟩. Quiet ✓ (G pending via target ⊥).

```
γ34  Q2: Act⟨[pv⁻(k2)]; {}⟩ | τ=⊥ | σ={k2↦v2}
     G:  In(⊥) | τ=⊥ | σ=∅
     C:  Act⟨id; {k2↦Q2}⟩ | τ=⊥ | σ=∅ | π=G
     σ_γ = {k2@Q2}   quiet: ✓
```

**Realized multiset at ★:** {T1, T2(k2), T7}. Report: Q2, C active;
G pending; rderr(C,k1,IA) in the final episode — the subtlest
reachability fact of D1 (§5.3), now fully checked: three settles build
and tear the committed ancestor view, two more revive the reader.
Schedule notes: (3)/(6) and the phase-4 cascade interleavings are
outcome-invariant (disjoint fields/edges); the ★ window itself is on
every fair schedule of the final settle (Q2's activation must precede
C's begin — B5's premise forces the order — and G can never begin).

### E.LI.T8 — signature T8 (script S-It-5)

**Script.** `X := (∅, ∅, [read(k1)])`; ρ = `insert(root, X); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @X] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @X] κ = {B1, B3}. θ_X ↦ Rel⟨[read(k1)]; id; {}⟩.

(3) ★ γ2 → γ3 [L-Iter @X] — T1; step read(k1): Algorithm 6 walk from
X: (self) ω_X = {} no k1, k1 ∉ d_X; X's parent is root — line 6:
UNDECLARED_ACCESS. **T8** (co-realizes CA.A5, CP.P6). Lands per A6.
κ = **{T1, T8}**. Emits rderr(X,k1,UD).

(4) γ3 → γ4 [L-Finish @X] κ = {F1} (per E.LI.T6(11)'s reading; g=id).
act(X). Quiet ✓.

**Realized multiset at ★:** {T1, T8}. Report: X active,
rderr(X,k1,UD) < act(X). Deterministic.

### E.LI.T9 — signature T9 (script S-It-6)

**Script.** `P := (∅, {k1}, [provide(k1,v1), setval(k1,v2)])`;
ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.
(3) γ2 → γ3 [L-Iter @P] — provide ✓. κ = {T1, T3}. σ_P := {k1↦v1},
g := [pv⁻(k1)].

(4) ★ γ3 → γ4 [L-Iter @P] — T1; step setval(k1,v2): Def. 24 A_k
operation — precondition: an **own** binding at k1's label exists ✓
(σ_P from step (3); note P is Reloading, so this is not a σ_γ read but
the fiber's own table, which Def. 43's confinement licenses).
**T9** (co-realizes CP.P3). Value replaced in place.
κ = **{T1, T9}**. Emits val(P,k1). Writes: σ_P := {k1↦v2}.

(5) γ4 → γ5 [L-Finish @P] κ = {F1}. act(P). Quiet ✓.

**Realized multiset at ★:** {T1, T9}. Report: P active, st(k1) = v2 —
the overwrite is episode-invisible (A3/PB-2 reading), no dependent
exists to re-run. Deterministic.

### E.LI.T10 — signature T10 (script S-It-7)

**Script.** `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @G] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @G] κ = {B1, B3}.

(3) ★ γ2 → γ3 [L-Iter @G] — T1; step register(C): Def. 47 — the
iteration performs O-Insert(C) with π = G (premises: n_C drawn fresh ✓
— the drawing discipline of p. 30; π = G ∈ dom F ✓; p_C = ∅ ✓; inner
window {I2, I4}, a second realization of I2), and pushes the O-Retire
of C as this iteration's inverse: g_G := [reg⁻(C)]. **T10**.
κ = **{T1, T10}**.

(4) γ3: enabled = {L-Finish @G, L-Begin @C}; commuting (as E.OM.M7(4)).
Canonical: γ3 → γ4 [L-Finish @G] κ = {F1}. act(G).
(5) γ4 → γ5 [L-Begin @C] κ = {B1, B3}. (6) γ5 → γ6 [L-Iter @C]
track(b), κ = {T1, T4}, app(C,b). (7) γ6 → γ7 [L-Finish @C] κ = {F1}.
act(C). Quiet ✓.

**Realized multiset at ★:** {T1, T10}. Report: G, C active, C under G.
Schedule note: (4)–(7) interleavings commute; ★ precedes the branch.

### E.LI.T11 — signature T11 (script S-It-8)

**Script.** `P := (∅, ∅, [raiseUnless(f,x)])`;
ρ = `insert(root, P, cfg={f}); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P ⊳ insert(root,P,cfg={f})] κ = {I1, I4}; the
cfg is carried on the entry.

(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.

(3) ★ γ2 → γ3 [L-Iter @P] — T1; step raiseUnless(f,x): equality
pattern cfg ∋ f ✓ — the step **lands** (Right), **T11**, emitting the
flag observation. κ = **{T1, T11}**. i := [].

(4) γ3 → γ4 [L-Finish @P] κ = {F1}. act(P). Quiet ✓.

**Realized multiset at ★:** {T1, T11}. Report: P active with the flag
event (contrast E.LR.X3, the unset branch). Deterministic.

---

## E.6 L-Finish

### E.LF.F1 — signature F1 (script S-Fin-1)

**Script.** `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle`.

**Derivation.** Steps (1)–(3) are E.LB.B1 (1)–(3): γ3 has
P: Rel⟨[]; [a⁻]; {}⟩ after app(P,a).

(4) ★ γ3 → γ4 [L-Finish @P] — θ_P = Rel ✓; target = {} = ω ✓;
i(γ3) = Right(δ, id, Nothing) ✓; accumulator g∘h = [a⁻] ≠ id after one
landed iteration: **F1**. κ = **{F1}** (d_P = ∅ → no F3). act(P).
θ_P ↦ Act⟨[a⁻]; {}⟩. Quiet ✓.

**Realized multiset at ★:** {F1}. Report: P active; app(P,a) < act(P).
Deterministic.

### E.LF.F2 — signature F2 (script S-Fin-2)

**Script.** `P := (∅, ∅, [])`; ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}. θ_P ↦ Rel⟨[]; id; {}⟩.

(3) ★ γ2 → γ3 [L-Finish @P] — Rel ✓; target = {} = ω ✓; the **first**
iterator application already yields Right(γ, id, Nothing) and the
accumulator is id — the p. 36 "plain effect function" degenerate case,
**F2**. κ = **{F2}**. act(P). θ_P ↦ Act⟨id; {}⟩. Quiet ✓.

**Realized multiset at ★:** {F2}. Report: P active with **no** app
events — the observation separating F2 from F1. Deterministic.

### E.LF.F3 — signature F3 (script S-Fin-3)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.

**Derivation.** Steps (1)–(7) are E.LB.B5 (1)–(7): γ7 has
C: Rel⟨[]; id; {k1↦P}⟩ after rd(C,k1,v1).

(8) ★ γ7 → γ8 [L-Finish @C] — Rel ✓; target_C(γ7): provider_k1 = P =
ω_C(k1) — per-key ViewRel = key-equal at the finishing window,
**F3(k1)**; i = Nothing ✓. κ = **{F1, F3(k1)}** (one landed
iteration). act(C). θ_C ↦ Act⟨id; {k1↦P}⟩. Quiet ✓.

**Realized multiset at ★:** {F1, F3(k1)}. Report: P, C active;
act(C) after rd(C,k1,v1). Deterministic.

---

## E.7 L-Divert

### E.LD.D1 — signatures D1, D4, D5 (script S-Div-1)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [track(a), track(b)])`;
ρ = `insert(root, P); settle; insert(root, C); retire(P); settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — γ4: P Active, σ_γ = {k1↦v1 @P}.

(5) γ4 ⇒ γ5 [O-Insert @C] κ = {I1, I4}.
(6) γ5 ⇒ γ6 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.

⟨settle⟩. Enabled at γ6: L-Begin @C (target_C = {k1↦P}: P still
Active — τ_P does **not** enter target_C, only P's Activeness does)
**and** L-Leave @P (target_P ⊥ by τ). **Schedule freedom** — genuine
calculus nondeterminism; the D-occurrences are schedule-dependent.
Canonical schedule (realizes the target signature): C begins, iterates
once, then P leaves.

(7) γ6 → γ7 [L-Begin @C] — κ = {B1, B3, B5(k1)}.
θ_C ↦ Rel⟨[track(a), track(b)]; id; {k1↦P}⟩.

(8) γ7 → γ8 [L-Iter @C] — target_C(γ7) = {k1↦P} = ω ✓ (P still
Active); track(a). κ = {T1, T2(k1), T4}. app(C,a). g_C := [a⁻].

(9) γ8 → γ9 [L-Leave @P] — Act ✓, target ⊥ ≠ {} ✓. κ = {V1, V3}.
θ_P ↦ Unl⟨[pv⁻(k1)]; {}; ⊥⟩. σ_γ = ∅.

(10) ★ γ9 → γ10 [L-Divert @C] — θ_C = Rel⟨[track(b)]; [a⁻]; {k1↦P}⟩ ✓
(**D1**); target_C(γ9) = ⊥ (k1 ∉ dom σ_γ; the committed provider left
the union) ≠ ω — per-key ViewRel = target-⊥-unsatisfied, **D4(k1)**;
alternative: (δ,h) = (γ,id) — the abort alternative, **D5** (the
landing alternative is barred by inertia at an iteration boundary,
E.U.2). κ = **{D1, D4(k1), D5}**.
Writes: θ_C ↦ Unl⟨[a⁻]; {k1↦P}; ⊥⟩ (g∘h = g, held iteration
track(b) discarded — no app(C,b) ever).

(11) γ10 ⊘ [L-Unload @P] — relied_P: C installed (Unl),
ω_C(k1) = P ✗. κ = {U2(C,k1), U3, U5, U10}. Blocked.

(12) γ10 → γ11 [L-Unload @C] — ¬relied_C ✓. g: inv(C,a).
κ = {U1, U3, U6, U11}. deact(C). θ_C ↦ In(⊥).

(13) γ11 → γ12 [L-Unload @P] — guard clear ✓. pv⁻(k1).
κ = {U1, U3, U5, U10}. deact(P). σ_P := ∅.

(14) γ12 → γ13 [O-Remove @P] κ = {M1, M3, M6}. γ ∖ P.
(15) γ13 ⊘ [L-Begin @C] {B1, B3, B7(k1)}. Quiet ✓ (C pending).

**Realized multiset at ★:** {D1, D4(k1), D5}. Report: P disposed, C
pending; event word app(C,a) < inv(C,a) with **no** app(C,b).
*Branches:* (a) P leaves before C begins — C never begins (target ⊥
at its window), no D-occurrences, report identical, word lacks
app/inv(C,a); (b) C finishes both tracks before P leaves — C goes
Active then V1/V4-leaves; report identical. All fair schedules
quiesce at {P disposed, C pending}; Out(ρ) = the three word classes;
V_{LD,D1} accepts the set. The exhaustive explorer (D3 deliverable)
must visit all three, as D1's sketch demands.

### E.LD.D3 — signature D3 (script S-Div-3, **corrected — see C1**)

**Corrected script ρ′.** `Q := (∅, {k2}, [provide(k2,v2)])`,
`Q2 := (∅, {k2}, [provide(k2,v2)])`,
`G := (∅, ∅, [register(C), track(a)])`,
`C := ({k2}, ∅, [track(b), track(c)])`;
ρ′ = `insert(root, Q); insert(root, G); settle; retire(Q); settle;
insert(root, Q2); retire(G); settle`.

(D1's printed ρ puts `insert(root, Q2)` before any settle following
`retire(Q)`; that insert is refused — O-Insert premise (iv) against
the still-registered Q, window {I1, I4, I7(k2)} — and D3 is never
reached. Correction C1.)

**Derivation.**

*Phase 1.*

(1) γ0 ⇒ γ1 [O-Insert @Q] κ = {I1, I4, I6(k2)}.
(2) γ1 ⇒ γ2 [O-Insert @G] κ = {I1, I4}.

⟨settle⟩ — canonical order (Q's and G's chains commute until C's
begin, which needs Q Active):

(3) γ2 → γ3 [L-Begin @Q] κ = {B1, B3}. (4) γ3 → γ4 [L-Iter @Q]
provide(k2,v2) ✓, κ = {T1, T3}; σ_Q := {k2↦v2}, g := [pv⁻(k2)].
(5) γ4 → γ5 [L-Finish @Q] κ = {F1}; act(Q). σ_γ = {k2@Q}.
(6) γ5 → γ6 [L-Begin @G] κ = {B1, B3}.
(7) γ6 → γ7 [L-Iter @G] — register(C): Def. 47 O-Insert (fresh, π=G,
p_C = ∅ ✓; inner {I2, I4}); g_G := [reg⁻(C)]. κ = {T1, T10}.
(8) γ7 → γ8 [L-Iter @G] — track(a). κ = {T1, T4}. app(G,a).
g_G := [reg⁻(C), a⁻].
(9) γ8 → γ9 [L-Finish @G] κ = {F1}. act(G).
(10) γ9 → γ10 [L-Begin @C] — k2 Active-provided:
κ = {B1, B3, B5(k2)}. θ_C ↦ Rel⟨[track(b), track(c)]; id; {k2↦Q}⟩.
(11) γ10 → γ11 [L-Iter @C] — track(b). κ = {T1, T2(k2), T4}.
app(C,b). g_C := [b⁻].
(12) γ11 → γ12 [L-Iter @C] — track(c). κ = {T1, T2(k2), T4}.
app(C,c). g_C := [b⁻, c⁻].
(13) γ12 → γ13 [L-Finish @C] κ = {F1, F3(k2)}. act(C). Quiet ✓.

```
γ13  Q: Act⟨[pv⁻(k2)]; {}⟩       | τ=⊥ | σ={k2↦v2}
     G: Act⟨[reg⁻(C), a⁻]; {}⟩   | τ=⊥ | σ=∅
     C: Act⟨[b⁻, c⁻]; {k2↦Q}⟩    | τ=⊥ | σ=∅ | π=G
     σ_γ = {k2@Q}    quiet: ✓
```

*Phase 2 — retire Q; C rests pending; Q leaves the registry.*

(14) γ13 ⇒ γ14 [O-Retire @Q] κ = {R2}. τ_Q ↦ ⊤.

⟨settle⟩:

(15) γ14 → γ15 [L-Leave @Q] κ = {V1, V3}. θ_Q ↦ Unl⟨[pv⁻(k2)]; {}; ⊥⟩.
σ_γ = ∅.
(16) γ15 → γ16 [L-Leave @C] — target_C ⊥ (k2 unprovided) ≠ ω ✓.
κ = {V1, V4(k2)}. θ_C ↦ Unl⟨[b⁻, c⁻]; {k2↦Q}; ⊥⟩.
(17) γ16 ⊘ [L-Unload @Q] — relied_Q: C installed, ω_C(k2)=Q ✗.
κ = {U2(C,k2), U3, U5, U10}. Blocked.
(18) γ16 → γ17 [L-Unload @C] — ¬relied_C ✓. g LIFO: inv(C,c),
inv(C,b). κ = {U1, U3, U6·2, U11}. deact(C). θ_C ↦ In(⊥).
(19) γ17 → γ18 [L-Unload @Q] — guard clear ✓. pv⁻(k2).
κ = {U1, U3, U5, U10}. deact(Q).
(20) γ18 → γ19 [O-Remove @Q] κ = {M1, M3, M6}. γ ∖ Q.
G: Act, target {} = ω ✓; C pending (target ⊥). Quiet ✓.

*Phase 3 — Q2 in, G retired; the race that realizes D3.*

(21) γ19 ⇒ γ20 [O-Insert @Q2] — disjointness ✓ (**Q removed at
(20)**). κ = {I1, I4, I6(k2)}.
(22) γ20 ⇒ γ21 [O-Retire @G] κ = {R2}. τ_G ↦ ⊤.

⟨settle⟩. Enabled at γ21: L-Begin @Q2, L-Leave @G. **Schedule
freedom** — D3 is realized exactly on schedules where G's unload
lands while C is Reloading; canonical schedule below. (Branches:
G's teardown completes before C re-begins → C is retired while
In(⊥), never re-begins, disposed — no D3; or after C finishes → V3
at L-Leave — no D3. All quiesce at the same report, derived below.)

(23) γ21 → γ22 [L-Begin @Q2] κ = {B1, B3}. (24) γ22 → γ23
[L-Iter @Q2] provide(k2,v2) ✓ (Q gone, no table holds k2),
κ = {T1, T3}. (25) γ23 → γ24 [L-Finish @Q2] κ = {F1}. act(Q2).
σ_γ = {k2@Q2}.

(26) γ24 → γ25 [L-Begin @C] — In(⊥), τ_C = ⊥ ✓; k2 Active-provided by
Q2: κ = {B1, B3, B5(k2)}. θ_C ↦ Rel⟨[track(b), track(c)]; id;
{k2↦Q2}⟩ — note the **fresh** committed view names Q2.

(27) γ25 → γ26 [L-Iter @C] — target_C = {k2↦Q2} = ω ✓; track(b).
κ = {T1, T2(k2), T4}. app(C,b). g_C := [b⁻]. **C is now Reloading
mid-activation.**

(28) γ26 → γ27 [L-Leave @G] — Act ✓; target_G = ⊥ (τ_G = ⊤) ≠ {} ✓.
κ = {V1, V3}. θ_G ↦ Unl⟨[reg⁻(C), a⁻]; {}; ⊥⟩.

(29) γ27 → γ28 [L-Unload @G] — ¬relied_G ✓ (C's ω = {k2↦Q2} names
Q2, not G — the guard follows coeffects, not the fiber tree, p. 35).
g LIFO: a⁻ emits inv(G,a); reg⁻(C) performs O-Retire(C) (C ∈ dom F ✓;
inner window {R2} — C is installed/Reloading): **τ_C ↦ ⊤ while C is
Reloading**. κ = {U1, U3, U6, U7, U10}. deact(G). θ_G ↦ In(⊥).

(30) ★ γ28 → γ29 [L-Divert @C] — θ_C = Rel⟨[track(c)]; [b⁻];
{k2↦Q2}⟩ ✓ (**D1**); target_C(γ28) = ⊥ **by retirement** (Def. 46
first clause: τ_C = ⊤ — flipped mid-activation by Def. 47's inverse,
the only agent that can do this during a settle) ≠ ω — ViewRel =
target-⊥-retired, **D3**; abort alternative (δ,h) = (γ,id), **D5**.
κ = **{D1, D3, D5}**. θ_C ↦ Unl⟨[b⁻]; {k2↦Q2}; ⊥⟩.

(31) γ29 → γ30 [L-Unload @C] — ¬relied_C ✓. inv(C,b).
κ = {U1, U3, U6, U10} (τ_C = ⊤). deact(C). θ_C ↦ In(⊥).

(32) γ30 → γ31 [O-Remove @C] — τ_C=⊤, In(⊥), childless ✓.
κ = {M1, M3, M6}. γ ∖ C.
(33) γ31 → γ32 [O-Remove @G] — τ_G=⊤, In(⊥), **now** childless ✓
(the ⊘-window {M1, M3, M7(C)} between (29) and (32) co-realizes M7).
κ = {M1, M3, M6}. γ ∖ G. Quiet ✓.

```
γ32  Q2: Act⟨[pv⁻(k2)]; {}⟩ | τ=⊥ | σ={k2↦v2}
     σ_γ = {k2@Q2}   quiet: ✓
```

**Realized multiset at ★:** {D1, D3, D5}. Report: Q2 active; G, C
disposed. Schedule-dependence: as flagged at (22) — every fair
schedule reaches this report (C is retired by G's reg⁻ on every
branch and can never re-begin thereafter; B4 blocks it), but the word
differs (whether app(C,b)/inv(C,b) — and possibly app(C,c) — occur);
D3's window exists only on schedules interleaving (26)–(29) as shown.
Out(ρ′) collects all interleavings; the explorer must confirm.

---

## E.8 L-Raise

### E.LR.X1 — signatures X1, X2, X6 (script S-Rai-1)

**Script.** `P := (∅, ∅, [raise(x)])`; ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}. θ_P ↦ Rel⟨[raise(x)]; id; {}⟩.

(3) ★ γ2 → γ3 [L-Raise @P] — θ_P = Rel ✓ with i(γ2) = Left(x)
(**X1**); step class raise (**X2**); accumulator g = id — no inverse
items, the empty marker **X6**. No view premise (A2). κ =
**{X1, X2, X6}**. θ_P ↦ Unl⟨id; {}; x⟩ (accumulator carried, error
recorded as the outcome).

(4) γ3 → γ4 [L-Unload @P] — ¬relied_P ✓; g = id. κ = {U1, U4, U9}.
deact(P). θ_P ↦ In(ξ:x). Quiet ✓ (ζ ≠ ⊥).

**Realized multiset at ★:** {X1, X2, X6}. Report: P failed(x), no
act(P). Deterministic.

### E.LR.X3 — signature X3 (script S-Rai-2)

**Script.** `P := (∅, ∅, [raiseUnless(f,x)])`;
ρ = `insert(root, P, cfg={}); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P, cfg = {}] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.

(3) ★ γ2 → γ3 [L-Raise @P] — i(γ2) = Left(x): step
raiseUnless(f,x) with equality pattern cfg ∌ f — **X3** (X1; X6:
g = id). κ = **{X1, X3, X6}**. θ_P ↦ Unl⟨id; {}; x⟩.

(4) γ3 → γ4 [L-Unload @P] κ = {U1, U4, U9}. deact(P). θ_P ↦ In(ξ:x).
Quiet ✓.

**Realized multiset at ★:** {X1, X3, X6}. Report: P failed(x); the
cfg={f} twin (E.LI.T11) activates — the pair pins the flag test.
Deterministic.

### E.LR.X4 — signature X4 (script S-Rai-3; isolation layer, A4)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`Q := (∅, {k2}, [provide(k2,v2)])`;
ρ = `isolate(k1, r1); isolate(k2, r1); insert(root, P); settle;
insert(root, Q); settle`.

**Derivation.** Storage labels are now explicit: ℓ(k) = ρ-table realm.

(1) γ0 ⇒ γ0′ [isolate(k1, r1)] — Def. 28/29: ambient realm table
ρ := {k1↦r1} (k1 was at its default realm — derivation, no
precondition, no registry effect). Realized relation: the subsequent
resolutions of k1 and k2 at the shared label r1 — **S3** (joined),
co-realizing E.CS.S3's letter negatively below.
(2) γ0′ ⇒ γ0″ [isolate(k2, r1)] — ρ := {k1↦r1, k2↦r1}.

(3) γ0″ ⇒ γ1 [O-Insert @P] — premise (iv) is **key-level**:
{k1} ∩ p_m = ∅ ✓ (vacuous). κ = {I1, I4, I6(k1)}.
(4) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.
(5) γ2 → γ3 [L-Iter @P] — provide(k1,v1): set precondition at label
ℓ(k1) = r1: unbound ✓. κ = {T1, T3}. σ_P := {r1 ↦ (k1,v1)},
g := [pv⁻(k1@r1)].
(6) γ3 → γ4 [L-Finish @P] κ = {F1}. act(P). σ_γ = {r1↦(k1,v1) @P}.
Quiet ✓.

(7) γ4 ⇒ γ5 [O-Insert @Q] — key-level disjointness:
{k2} ∩ {k1} = ∅ ✓ — the insert **passes**; this is exactly the A4 gap
(label-level conflict is invisible to premise (iv)). κ = {I1, I4,
I6(k2)} (I6: no registered fiber *declares* k2).
(8) γ5 → γ6 [L-Begin @Q] κ = {B1, B3}. θ_Q ↦ Rel⟨[provide(k2,v2)];
id; {}⟩.

(9) ★ γ6 → γ7 [L-Raise @Q] — i(γ6) = Left(conflict): step
provide(k2,v2) meets Def. 23's set precondition at label ℓ(k2) = r1,
which **is bound** — in P's table, another fiber (**X4**,
provide-conflict; X1; X6: g_Q = id). κ = **{X1, X4, X6}** (co-realizes
CP.P2 and the joined-realm relation S3). θ_Q ↦ Unl⟨id; {}; ξ_conf⟩.

(10) γ7 → γ8 [L-Unload @Q] — ¬relied_Q ✓; g = id. κ = {U1, U4, U9}.
deact(Q). θ_Q ↦ In(ξ:conf). Quiet ✓ (ζ ≠ ⊥; P still Active).

**Realized multiset at ★:** {X1, X4, X6}. Report: Q failed(conflict);
st at r1 still (k1,v1) by P — the standing binding untouched (a
dynamic-conflict-ignored deviant would overwrite it). Deterministic.

### E.LR.X5 — signature X5 (script S-Rai-4)

**Script.** `P := (∅, ∅, [setval(k1,v2)])`;
ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.

(3) ★ γ2 → γ3 [L-Raise @P] — i(γ2) = Left(ξ_set): step setval(k1,v2)
is a Def. 24 A_k operation whose precondition — an own binding at
k1's label — fails (σ_P = ∅): **X5** (setval-foreign; X1; X6).
κ = **{X1, X5, X6}** (co-realizes CP.P4). θ_P ↦ Unl⟨id; {}; ξ_set⟩.

(4) γ3 → γ4 [L-Unload @P] κ = {U1, U4, U9}. deact(P). θ_P ↦ In(ξ).
Quiet ✓.

**Realized multiset at ★:** {X1, X5, X6}. Report: P failed.
Deterministic.

### E.LR.X7 — signature X7 (script S-Rai-5)

**Script.** `P := (∅, {k1}, [provide(k1,v1), raise(x)])`;
ρ = `insert(root, P); settle`.

**Derivation.** Steps (1)–(3) are E.LB.B2 (1)–(3): γ3 has
P: Rel⟨[raise(x)]; [pv⁻(k1)]; {}⟩ with σ_P = {k1↦v1}.

(4) ★ γ3 → γ4 [L-Raise @P] — i(γ3) = Left(x) ✓ (X1, X2); accumulator
g = [pv⁻(k1)]: one provide⁻¹ item present — witness **X7** (no X6).
κ = **{X1, X2, X7}**. θ_P ↦ Unl⟨[pv⁻(k1)]; {}; x⟩ — g carried into
Unloading.

(5) γ4 → γ5 [L-Unload @P] — ¬relied_P ✓; pv⁻(k1) withdraws the
binding. κ = {U1, U4, U5}. deact(P). θ_P ↦ In(ξ:x), σ_P := ∅.
Quiet ✓.

**Realized multiset at ★:** {X1, X2, X7}. Report: P failed(x) and
st(k1) **absent** — the withdrawal is X7's observation (a
recovery-leaves-residue deviant keeps it). Deterministic.

### E.LR.X8 — signature X8 (script S-Rai-6)

**Script.** `P := (∅, ∅, [track(a), raise(x)])`;
ρ = `insert(root, P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.
(3) γ2 → γ3 [L-Iter @P] — track(a). κ = {T1, T4}. app(P,a).
g := [a⁻].

(4) ★ γ3 → γ4 [L-Raise @P] — i(γ3) = Left(x) ✓ (X1, X2); g = [a⁻]:
track⁻¹ present — witness **X8**. κ = **{X1, X2, X8}**.
θ_P ↦ Unl⟨[a⁻]; {}; x⟩.

(5) γ4 → γ5 [L-Unload @P] — inv(P,a). κ = {U1, U4, U6}. deact(P).
θ_P ↦ In(ξ:x). Quiet ✓.

**Realized multiset at ★:** {X1, X2, X8}. Report: P failed(x);
app(P,a) < inv(P,a) < deact(P) — recovery emits the inverse before
deactivation. Deterministic.

### E.LR.X9 — signature X9 (script S-Rai-7)

**Script.** `G := (∅, ∅, [register(C), raise(x)])`,
`C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @G] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @G] κ = {B1, B3}.
(3) γ2 → γ3 [L-Iter @G] — register(C): Def. 47 O-Insert (inner
{I2, I4}); g_G := [reg⁻(C)]. κ = {T1, T10}. C now In(⊥), π = C…G.

(4) γ3: enabled = {L-Iter @G (the raise), L-Begin @C}. **Schedule
freedom**; the ★ window is **schedule-invariant** — G's raise window
carries {X1, X2, X9} whether or not C has begun (the X-alphabet reads
G's iterator and accumulator only). Canonical: continue G.

★ γ3 → γ4 [L-Raise @G] — i(γ3) = Left(x) ✓ (X1, X2); g_G =
[reg⁻(C)]: register⁻¹ present — witness **X9**. κ = **{X1, X2, X9}**.
θ_G ↦ Unl⟨[reg⁻(C)]; {}; x⟩.

(5) γ4 → γ5 [L-Unload @G] — ¬relied_G ✓ (C's ω, if any, is {}).
g: reg⁻(C) performs O-Retire(C) (inner window: {R1} on the canonical
branch — C still In(⊥)). κ = {U1, U4, U7}. deact(G). θ_G ↦ In(ξ:x),
τ_C ↦ ⊤.

(6) γ5 ⊘ [L-Begin @C] — {B1, B4} (target ⊥ by τ_C). Disabled.
(7) γ5 → γ6 [O-Remove @C] — τ_C=⊤, In(⊥), childless ✓.
κ = {M1, M3, M6}. γ ∖ C. Quiet ✓ (G: In(ξ), ζ ≠ ⊥, τ_G = ⊥ — G
persists as a failed entry).

**Realized multiset at ★:** {X1, X2, X9}. Report: G failed(x), C
disposed. *Branch:* C activates before G's raise (steps
L-Begin/L-Iter/L-Finish @C interleaved before (4)); then reg⁻(C)
retires an Active C, which V1/V3-leaves, unloads (inv(C,b)), and is
removed — same report, richer word (app(C,b), act(C), inv(C,b));
X9's window unchanged. Both branches ∈ Out(ρ).

---

## E.9 L-Leave

### E.LL.V1 — signatures V1, V3 (script S-Lea-1)

**Script.** `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.** Steps (1)–(5) are E.OT.R2 (1)–(5): γ5 has
P: Act⟨[a⁻]; {}⟩, τ_P = ⊤.

(6) ★ γ5 → γ6 [L-Leave @P] — θ_P = Act⟨[a⁻]; {}⟩ ✓ (**V1**);
target_P(γ5) = ⊥ by τ_P = ⊤ (Def. 46 first clause) ≠ ω = {} —
ViewRel = target-⊥-retired, **V3**. κ = **{V1, V3}**.
θ_P ↦ Unl⟨[a⁻]; {}; ⊥⟩.

(7) γ6 → γ7 [L-Unload @P] — inv(P,a). κ = {U1, U3, U6, U10}.
deact(P). (8) γ7 → γ8 [O-Remove @P] κ = {M1, M3, M6}. Quiet ✓.

**Realized multiset at ★:** {V1, V3}. Report: P disposed; certificate
order inv(P,a) < deact(P) < removal. Deterministic.

### E.LL.V4 — signature V4 (script S-Lea-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), track(a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — γ4: P Active, σ_γ = {k1@P}.
(5) γ4 ⇒ γ5 [O-Insert @C] κ = {I1, I4}.
(6) γ5 → γ6 [L-Begin @C] κ = {B1, B3, B5(k1)}.
θ_C ↦ Rel⟨[read(k1), track(a)]; id; {k1↦P}⟩.
(7) γ6 → γ7 [L-Iter @C] — read: self hit. κ = {T1, T2(k1), T5}.
rd(C,k1,v1).
(8) γ7 → γ8 [L-Iter @C] — track(a). κ = {T1, T2(k1), T4}. app(C,a).
g_C := [a⁻].
(9) γ8 → γ9 [L-Finish @C] κ = {F1, F3(k1)}. act(C).
θ_C ↦ Act⟨[a⁻]; {k1↦P}⟩. Quiet ✓.

(10) γ9 ⇒ γ10 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.

⟨settle⟩. At γ10 the **only** enabled rule is L-Leave @P: C's target
is {k1↦P} = ω_C while P is still Active (deterministic — no schedule
note needed):

(11) γ10 → γ11 [L-Leave @P] κ = {V1, V3}.
θ_P ↦ Unl⟨[pv⁻(k1)]; {}; ⊥⟩. σ_γ = ∅.

(12) ★ γ11 → γ12 [L-Leave @C] — θ_C = Act⟨[a⁻]; {k1↦P}⟩ ✓ (**V1**);
target_C(γ11) = ⊥: τ_C = ⊥ but k1 ∉ dom σ_γ — the committed key's
provider left the Active union — per-key ViewRel =
target-⊥-unsatisfied, **V4(k1)**. κ = **{V1, V4(k1)}**.
θ_C ↦ Unl⟨[a⁻]; {k1↦P}; ⊥⟩.

(13) γ12 ⊘ [L-Unload @P] — relied_P: C installed, ω_C(k1) = P ✗.
κ = {U2(C,k1), U3, U5, U10}. Blocked — C's teardown runs first
(the reliance guard, §4.3.1).

(14) γ12 → γ13 [L-Unload @C] — ¬relied_C ✓; inv(C,a).
κ = {U1, U3, U6, U11}. deact(C). θ_C ↦ In(⊥).

(15) γ13 → γ14 [L-Unload @P] — guard clear ✓; pv⁻(k1).
κ = {U1, U3, U5, U10}. deact(P). (16) γ14 → γ15 [O-Remove @P]
κ = {M1, M3, M6}. γ ∖ P. Quiet ✓ (C pending).

**Realized multiset at ★:** {V1, V4(k1)}. Report: C pending, P
disposed; inv(C,a) precedes P's deact and withdrawal. Deterministic.

### E.LL.V5 — signature V5 (script S-Lea-3; A3 extension)

**Script.** `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; update(P, cfg2); settle`.

**Derivation.** Steps (1)–(4) are E.LB.B1 (1)–(4): γ4 has
P: Act⟨[a⁻]; {}⟩, quiet.

(5) γ4 ⇒ γ5 [update(P, cfg2)] — the A3 extension input: rewrites the
entry's cfg and marks the episode stale (forced re-resolution; no
Table-1 rule — flagged per D1 Dev-7/A3).

⟨settle⟩:

(6) ★ γ5 → γ6 [L-Leave @P] — θ_P = Act ✓ (**V1**); divergence =
orch-update (the stale mark forces target ≢ ω for this window),
**V5**. κ = **{V1, V5}**. θ_P ↦ Unl⟨[a⁻]; {}; ⊥⟩; stale mark
consumed.

(7) γ6 → γ7 [L-Unload @P] — ¬relied_P ✓; inv(P,a).
κ = {U1, U3, U6, U12} (τ=⊥, post-target = {} satisfiable — the U12
window; see E.LU.U12 for the dedicated item). deact(P). θ_P ↦ In(⊥).

(8) γ7 → γ8 [L-Begin @P] — In(⊥) ✓, target {} ≠ ⊥ ✓ (fresh episode,
cfg2). κ = {B1, B3}. (9) γ8 → γ9 [L-Iter @P] track(a),
κ = {T1, T4}, app(P,a). (10) γ9 → γ10 [L-Finish @P] κ = {F1}.
act(P). Quiet ✓.

**Realized multiset at ★:** {V1, V5} (co-realizes U12). Report: P
active under cfg2; word contains the full bounce
inv(P,a) < deact(P) < app(P,a) < act(P) with **two** act(P) events.
Deterministic.

---

## E.10 L-Unload

### E.LU.U1 — signatures U1, U3, U6, U10 (script S-Unl-1)

**Script.** `P := (∅, ∅, [track(a), track(b), track(c)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4}.
(2) γ1 → γ2 [L-Begin @P] κ = {B1, B3}.
(3) γ2 → γ3 [L-Iter @P] track(a): κ = {T1, T4}, app(P,a), g := [a⁻].
(4) γ3 → γ4 [L-Iter @P] track(b): κ = {T1, T4}, app(P,b),
g := [a⁻, b⁻].
(5) γ4 → γ5 [L-Iter @P] track(c): κ = {T1, T4}, app(P,c),
g := [a⁻, b⁻, c⁻].
(6) γ5 → γ6 [L-Finish @P] κ = {F1}. act(P). θ_P ↦ Act⟨[a⁻,b⁻,c⁻]; {}⟩.
Quiet ✓.
(7) γ6 ⇒ γ7 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.
(8) γ7 → γ8 [L-Leave @P] κ = {V1, V3}. θ_P ↦ Unl⟨[a⁻,b⁻,c⁻]; {}; ⊥⟩.

(9) ★ γ8 → γ9 [L-Unload @P] — θ_P = Unl ✓; ¬relied_P ✓ — guard clear,
**U1**; ζ = ⊥ (**U3**); items: three track⁻¹ (**U6·3**); τ_P = ⊤
(**U10**: successor removable). g applies right-to-left (LIFO,
eq. 48): inv(P,c) < inv(P,b) < inv(P,a). κ = **{U1, U3, U6·3, U10}**.
deact(P). θ_P ↦ In(⊥).

(10) γ9 → γ10 [O-Remove @P] κ = {M1, M3, M6}. Registry empty, quiet ✓.

**Realized multiset at ★:** {U1, U3, U6·3, U10}. Report: P disposed;
the word inv(P,c) < inv(P,b) < inv(P,a) < deact(P) is PAPER_REWRITE
§5.3's accumulator-order canonical test (kills accumulator-fifo).
Deterministic.

### E.LU.U2 — signature U2 (script S-Unl-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C := ({k1}, ∅, [read(k1), track(b)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle`.

**Derivation.**

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(2)–(5) ⟨settle⟩: L-Begin @P {B1,B3}; L-Iter provide {T1,T3}
(σ_P := {k1↦v1}, g := [pv⁻(k1)]); L-Iter track(a) {T1,T4}, app(P,a),
g := [pv⁻(k1), a⁻]; L-Finish {F1}, act(P). σ_γ = {k1@P}.
(6) γ5 ⇒ γ6 [O-Insert @C] κ = {I1, I4}.
(7)–(10) ⟨settle⟩: L-Begin @C {B1,B3,B5(k1)} (ω_C = {k1↦P});
L-Iter read {T1,T2(k1),T5}, rd(C,k1,v1); L-Iter track(b)
{T1,T2(k1),T4}, app(C,b), g_C := [b⁻]; L-Finish {F1,F3(k1)}, act(C).
Quiet ✓.
(11) γ10 ⇒ γ11 [O-Retire @P] κ = {R2}. τ_P ↦ ⊤.

⟨settle⟩ — deterministic (C's view matches while P is Active):

(12) γ11 → γ12 [L-Leave @P] κ = {V1, V3}.
θ_P ↦ Unl⟨[pv⁻(k1), a⁻]; {}; ⊥⟩. σ_γ = ∅.

(13) ★ γ12 ⊘ [L-Unload @P] — θ_P = Unl ✓, but relied_P(γ12): witness
m = C, k = k1: C ≠ P, k1 ∈ d_C, installed_C (Act) ∧ ω_C(k1) = P ✗ —
the positive reliance witness, **U2(C,k1)**, blocking.
κ = **{U2(C,k1), U3, U5, U6, U10}**. P's withdrawal is held back.

(14) γ12 → γ13 [L-Leave @C] — target_C ⊥ (k1 unprovided) ≠ ω ✓.
κ = {V1, V4(k1)}. θ_C ↦ Unl⟨[b⁻]; {k1↦P}; ⊥⟩.
(15) γ13 → γ14 [L-Unload @C] — ¬relied_C ✓; inv(C,b).
κ = {U1, U3, U6, U11}. deact(C). θ_C ↦ In(⊥).
(16) γ14 → γ15 [L-Unload @P] — guard **now** clear (C not installed) ✓
(U1); LIFO: inv(P,a) then pv⁻(k1) withdraws. κ = {U1, U3, U5, U6, U10}.
deact(P). σ_P := ∅.
(17) γ15 → γ16 [O-Remove @P] κ = {M1, M3, M6}. Quiet ✓ (C pending).

**Realized multiset at ★:** {U2(C,k1), U3, U5, U6, U10}. Report: C
pending, P disposed; verdict word: inv(C,b) **precedes** inv(P,a) and
the k1 withdrawal — Thm. 63's ordering as an event order (kills
unload-without-guard). Deterministic.

### E.LU.U4 — signature U4 (script S-Unl-3)

**Script.** `P := (∅, ∅, [track(a), raise(x)])`;
ρ = `insert(root, P); settle`.

**Derivation.** Steps (1)–(4) are E.LR.X8 (1)–(4): γ4 has
P: Unl⟨[a⁻]; {}; x⟩.

(5) ★ γ4 → γ5 [L-Unload @P] — Unl ✓; ¬relied_P ✓ (U1); outcome
ζ = x ≠ ⊥: **U4**; one track⁻¹ item (U6). Per Correction C2 no
U10–U12 letter (ζ = ξ). g: inv(P,a). κ = **{U1, U4, U6}**. deact(P).
θ_P ↦ In(ξ:x). Quiet ✓ (ζ ≠ ⊥).

**Realized multiset at ★:** {U1, U4, U6}. Report: P failed(x) with
inv(P,a) emitted — recovery ran despite the failure (kills
raise-skips-recovery). Deterministic.

### E.LU.U5 — signature U5 (script S-Unl-4)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.** (1)–(4): E.OI.I1 (1)–(4) — γ4: P Active,
σ_P = {k1↦v1}. (5) γ4 ⇒ γ5 [O-Retire @P] κ = {R2}. (6) γ5 → γ6
[L-Leave @P] κ = {V1, V3}. θ_P ↦ Unl⟨[pv⁻(k1)]; {}; ⊥⟩.

(7) ★ γ6 → γ7 [L-Unload @P] — U1 (no dependent ever committed to P);
U3 (ζ=⊥); item pv⁻(k1): **U5** — the provide⁻¹ withdraws the binding
(Def. 23's restriction inverse); U10 (τ=⊤).
κ = **{U1, U3, U5, U10}**. deact(P). σ_P := ∅.

(8) γ7 → γ8 [O-Remove @P] κ = {M1, M3, M6}. Quiet ✓.

**Realized multiset at ★:** {U1, U3, U5, U10}. Report: P disposed,
st(k1) absent. Deterministic.

### E.LU.U7 — signature U7 (script S-Unl-5)

**Script.** `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle; retire(G); settle`.

**Derivation.** Steps (1)–(7) are E.LI.T10 (1)–(7): γ7 = both Active,
g_G = [reg⁻(C)].

(8) γ7 ⇒ γ8 [O-Retire @G] κ = {R2}. τ_G ↦ ⊤.
(9) γ8 → γ9 [L-Leave @G] κ = {V1, V3}. θ_G ↦ Unl⟨[reg⁻(C)]; {}; ⊥⟩.

(10) ★ γ9 → γ10 [L-Unload @G] — U1 (C's ω = {} names nobody); U3;
item reg⁻(C): **U7** — the register⁻¹ performs Def. 47's O-Retire(C)
(inner window {R2}); U10. κ = **{U1, U3, U7, U10}**. deact(G).
τ_C ↦ ⊤, θ_G ↦ In(⊥).

(11) γ10 ⊘ [O-Remove @G] — {M1, M3, M7(C)}: blocked (child present).
(12) γ10 → γ11 [L-Leave @C] — target ⊥ (τ_C) ✓. κ = {V1, V3}.
(13) γ11 → γ12 [L-Unload @C] — inv(C,b). κ = {U1, U3, U6, U10}.
deact(C).
(14) γ12 → γ13 [O-Remove @C] κ = {M1, M3, M6}. γ ∖ C.
(15) γ13 → γ14 [O-Remove @G] κ = {M1, M3, M6}. Registry empty,
quiet ✓.

**Realized multiset at ★:** {U1, U3, U7, U10}. Report: both disposed;
word: deact(G) < inv(C,b) — the child is reached "one level at a
time" (p. 32); kills unload-skips-child-retire. Deterministic.

### E.LU.U8 — signature U8 (script S-Unl-6; A7 grammar extension)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), trackReadOnRevert(k1, a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle`.

`trackReadOnRevert` is the A7 extension of the §2.2 step grammar: its
forward half is a track; its inverse **reads** σ|_{d_C} when applied —
exactly the read Def. 48 clause 2 licenses an inverse to perform.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4). (5) [O-Insert @C] κ = {I1, I4}.
(6) [L-Begin @C] κ = {B1, B3, B5(k1)}; ω_C = {k1↦P}.
(7) [L-Iter @C] read: κ = {T1, T2(k1), T5}, rd(C,k1,v1).
(8) [L-Iter @C] trackReadOnRevert: forward = track, κ = {T1, T4},
app(C,a), g_C := [ror⁻(k1,a)]. (9) [L-Finish @C] κ = {F1, F3(k1)},
act(C). Quiet ✓. (10) [O-Retire @P] κ = {R2}.
(11) [L-Leave @P] κ = {V1, V3}. θ_P ↦ Unl⟨[pv⁻(k1)]; {}; ⊥⟩;
**σ_P = {k1↦v1} persists** — only pv⁻ withdraws it.
(12) ⊘ [L-Unload @P] — relied_P (witness C) ✗:
{U2(C,k1), U3, U5, U10}.
(13) [L-Leave @C] — target ⊥ ≠ ω: κ = {V1, V4(k1)}.
θ_C ↦ Unl⟨[ror⁻(k1,a)]; {k1↦P}; ⊥⟩.

(14) ★ γ → γ′ [L-Unload @C] — ¬relied_C ✓ (U1); ζ=⊥ (U3); item
ror⁻(k1,a): a **read-on-revert** inverse, **U8** — its application
reads k1 through ω_C (still held: L-Unload discards ω as its last
act), resolving to P, whose table still holds k1 ↦ v1 (step (11) note;
P is pinned in Unloading by C's own edge — the E.U.6 invariant seen
from the positive side). The read **succeeds** with v1.
κ = **{U1, U3, U8, U11}**. Emits rd-on-revert(C,k1,v1), then
deact(C). θ_C ↦ In(⊥).

(15) [L-Unload @P] — guard clear; pv⁻(k1). κ = {U1, U3, U5, U10}.
deact(P). (16) [O-Remove @P] κ = {M1, M3, M6}. Quiet ✓ (C pending).

**Realized multiset at ★:** {U1, U3, U8, U11}. Report: C pending, P
disposed; word: rd-on-revert(C,k1,v1) **precedes** P's withdrawal —
the committed-read-during-teardown Thm. 63 promises. Flag: U8 is
realized in the A7-extended grammar only (D1 §10.3/§17-A7).
Deterministic.

### E.LU.U9 — signature U9 (script S-Unl-7)

**Script.** `P := (∅, ∅, [])`;
ρ = `insert(root, P); settle; retire(P); settle`.

**Derivation.** (1) [O-Insert @P] {I1, I4}; (2) [L-Begin @P] {B1, B3};
(3) [L-Finish @P] {F2}, act(P); (4) [O-Retire @P] {R2};
(5) [L-Leave @P] {V1, V3}. θ_P ↦ Unl⟨id; {}; ⊥⟩.

(6) ★ γ → γ′ [L-Unload @P] — U1; U3; accumulator **id** — the empty
marker **U9**, no per-item occurrence; U10 (τ=⊤). g(γ) = γ.
κ = **{U1, U3, U9, U10}**. deact(P) with **no** inv events.
θ_P ↦ In(⊥).

(7) [O-Remove @P] {M1, M3, M6}. Quiet ✓.

**Realized multiset at ★:** {U1, U3, U9, U10}. Report: P disposed;
w contains deact(P) and no inv. Deterministic.

### E.LU.U11 — signature U11 (script S-Unl-8 = S-Lea-2's ρ)

**Script.** Shared with E.LL.V4:
`P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), track(a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle`.

**Derivation.** Steps (1)–(13) are E.LL.V4 (1)–(13) verbatim. The ★
is E.LL.V4's step (14), restated with its window in full:

(14) ★ γ12 → γ13 [L-Unload @C] — Unl ✓; ¬relied_C ✓ (U1); ζ=⊥ (U3);
item a⁻ (U6); bookkeeping: τ_C = ⊥ **and** post-target ⊥ — at γ12,
target_C = ⊥ since k1 ∉ dom σ_γ (P is Unloading) — **U11**: the
successor **rests pending**. κ = **{U1, U3, U6, U11}**. inv(C,a),
deact(C). θ_C ↦ In(⊥).

Steps (15)–(16) as E.LL.V4: P unloads and is removed; quiet with
C: In(⊥), target ⊥.

**Realized multiset at ★:** {U1, U3, U6, U11}. Report: C pending —
and **no re-begin certificate follows** deact(C), the observation
separating U11 from U12. Deterministic.

### E.LU.U12 — signature U12 (script S-Unl-9, D1's corrected ρ′)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [track(a)])`;
ρ′ = `insert(root, P); settle; insert(root, C); settle;
update(C, cfg2); settle`.
(D1 §10.4 already replaces its first attempt by this ρ′; the first
attempt's failure is re-derived in §E.98 for the record.)

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — P Active, σ_γ = {k1@P}.
(5) [O-Insert @C] {I1, I4}. (6) [L-Begin @C] {B1, B3, B5(k1)},
ω_C = {k1↦P}. (7) [L-Iter @C] track(a): {T1, T2(k1), T4}, app(C,a),
g_C := [a⁻]. (8) [L-Finish @C] {F1, F3(k1)}, act(C). Quiet ✓.

(9) γ8 ⇒ γ9 [update(C, cfg2)] — A3 extension: stale mark on C.

(10) γ9 → γ10 [L-Leave @C] — Act ✓; divergence = orch-update:
κ = {V1, V5}. θ_C ↦ Unl⟨[a⁻]; {k1↦P}; ⊥⟩.

(11) ★ γ10 → γ11 [L-Unload @C] — ¬relied_C ✓ (U1); ζ=⊥ (U3); item a⁻
(U6); bookkeeping: τ_C = ⊥ and post-target **satisfiable** — at γ10,
target_C = {k1↦P} ≠ ⊥ (P is still Active; nothing changed but C's own
episode) — **U12**: the successor window re-begins immediately (the
deactivation-chains-into-activation composite, §4.3.3).
κ = **{U1, U3, U6, U12}**. inv(C,a), deact(C). θ_C ↦ In(⊥).

(12) γ11 → γ12 [L-Begin @C] — In(⊥) ✓, target {k1↦P} ≠ ⊥ ✓:
κ = {B1, B3, B5(k1)}. (13) γ12 → γ13 [L-Iter @C] track(a):
{T1, T2(k1), T4}, app(C,a). (14) γ13 → γ14 [L-Finish @C]
{F1, F3(k1)}, act(C). Quiet ✓ (P, C Active).

**Realized multiset at ★:** {U1, U3, U6, U12}. Report: P, C active
under cfg2; word: deact(C) **directly followed by** app(C,a)/act(C)
— the re-begin certificate that separates U12 from U11.
Deterministic.

---

## E.11 Coeffect operations I — CO-Prov (Def. 23/24)

P1, P2, P5, P6 are realized inside L-Iter/L-Raise windows and are
checked in E.LI.T3 (P1), E.LR.X4 (P2), E.LI.T1 (P5), E.LI.T8/T7 (P6);
E.LI.T9 and E.LR.X5 realize the step forms of P3/P4. The two **new**
scripts are the orchestration-setval forms.

### E.CP.P3 — signature P3, orchestration form

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`;
ρ = `insert(root, P); settle; setval(P, k1, v2); settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — γ4: P Active, σ_P = {k1↦v1},
σ_γ = {k1@P}, quiet.

(5) ★ γ4 ⇒ γ5 [setval(P, k1, v2)] — the Λ_orch A_k input (Def. 24 via
PB-1's corrected mapping): precondition — an own binding of P at k1's
label ✓ (σ_P). **P3**: value replaced in place. Emits val(P,k1).
Writes: σ_P := {k1↦v2}. κ = **{P3}**.

(6) ⟨settle⟩: no rule enabled — P: Act with target {} = ω (the
overwrite touches no view, no σ_γ-domain, no θ); quiet **immediately**
✓.

```
γ5   P: Act⟨[pv⁻(k1)]; {}⟩ | τ=⊥ | σ={k1↦v2}
     σ_γ = {k1↦v2 @P}   quiet: ✓
```

**Realized multiset at ★:** {P3}. Report: st(k1) = v2 and **no**
dependent re-run / no new act events — the A3/PB-2
overwrite-invisible reading, adopted from the model and flagged as
such by D1. Deterministic.

### E.CP.P4 — signature P4, orchestration form

**Script.** `P := (∅, ∅, [])`;
ρ = `insert(root, P); settle; setval(P, k1, v1)`.

**Derivation.**

(1) [O-Insert @P] {I1, I4}; (2) [L-Begin @P] {B1, B3};
(3) [L-Finish @P] {F2}, act(P). Quiet ✓.

(4) ★ γ3 ⊘ [setval(P, k1, v1)] — Def. 24 precondition: **no** own
binding of P at k1's label (σ_P = ∅) ✗ — **P4**: refused, refusal
event. κ = **{P4}**.

**Realized multiset at ★:** {P4}. Outcome: Refused(w, setval, q); q
shows P active, st(k1) absent. Deterministic.

---

## E.12 Coeffect operations II — CO-Iso (Def. 28/29)

S1 (default realm) is realized by every script of E.1–E.10 (no
isolate input); canonical carrier E.OI.I1. S3's negative (conflict)
form is E.LR.X4.

### E.CS.S2 — signature S2 (script S-Iso-1)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; isolate(k1, r1); insert(root, C);
settle`.

**Derivation.** Labels explicit: default label of k1 is ℓ0.

(1)–(4): E.OI.I1 (1)–(4) — P Active with σ_P = {ℓ0 ↦ (k1,v1)}
(inserted **before** the isolate: P's resolution context maps k1 ↦ ℓ0,
fixed at insertion).

(5) γ4 ⇒ γ4′ [isolate(k1, r1)] — ambient ρ := {k1↦r1}; derivation
only, no registry effect, no inverse (Def. 29).

(6) γ4′ ⇒ γ5 [O-Insert @C] — κ = {I1, I4}; C's resolution context
carries k1 ↦ r1.

⟨settle⟩:

(7) ★ γ5 ⊘ [L-Begin @C] — B1, B3; per-key k1: C resolves k1 at label
r1; **no Active table holds r1** (P's binding is at ℓ0) — the
accessor's realm differs from the would-be provider's: **S2**
(isolated-distinct), and the KeySat class at r1 is unprovided (a B7
window at label level). target_C = ⊥: disabled.
κ = **{B1, B3, B7(k1)}** with the CO-Iso occurrence **S2** on the
resolution read. Quiet ✓ (C pending).

```
γ5   P: Act⟨[pv⁻(k1)]; {}⟩ | τ=⊥ | σ={ℓ0↦(k1,v1)}
     C: In(⊥) | τ=⊥ | σ=∅
     σ_γ = {ℓ0↦(k1,v1) @P}   quiet: ✓
```

**Realized multiset at ★:** {S2} (window {B1, B3, B7(k1)}). Report:
the same key k1 satisfied at ℓ0 (P active) and unsatisfied at r1
(C pending) — the two-realm split observable in one report.
Deterministic.

### E.CS.S3 — signature S3, positive form (script S-Iso-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k2}, ∅, [read(k2)])`;
ρ = `isolate(k1, r1); isolate(k2, r1); insert(root, P); settle;
insert(root, C); settle`.

**Derivation.**

(1) γ0 ⇒ γ0′ [isolate(k1, r1)]; (2) γ0′ ⇒ γ0″ [isolate(k2, r1)] —
ambient ρ = {k1↦r1, k2↦r1}: k1 and k2 **joined** at r1.

(3) γ0″ ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(4) γ1 → γ2 [L-Begin @P] {B1, B3}. (5) γ2 → γ3 [L-Iter @P]
provide(k1,v1): precondition at r1 ✓ (unbound); κ = {T1, T3};
σ_P := {r1 ↦ (k1,v1)}. (6) γ3 → γ4 [L-Finish @P] {F1}, act(P).
σ_γ = {r1 @P}.

(7) γ4 ⇒ γ5 [O-Insert @C] — {k2} disjoint from {k1} ✓ (key-level).
κ = {I1, I4}.

(8) ★ γ5 → γ6 [L-Begin @C] — B1, B3; per-key k2: C resolves k2 at
label r1, held by the Active P — **S3** (joined: C's declared key
satisfied through P's *different* key at the shared realm); KeySat =
Active-provided. κ = **{B1, B3, B5(k2)}** with CO-Iso occurrence
**S3**. θ_C ↦ Rel⟨[read(k2)]; id; {k2↦P}⟩.

(9) γ6 → γ7 [L-Iter @C] — read(k2): Algorithm 6: ω_C binds k2 ↦ P;
label r1; P's table holds r1 ↦ (k1,v1) — the joined read returns v1.
κ = {T1, T2(k2), T5}. rd(C,k2,v1).
(10) γ7 → γ8 [L-Finish @C] {F1, F3(k2)}. act(C). Quiet ✓.

**Realized multiset at ★:** {S3} (windows {B1,B3,B5(k2)} and the
read). Report: C active having read **v1 through the join** — with
distinct realms C would be pending (E.CS.S2): the pair pins Def. 28's
transport. Deterministic.

### E.CS.S4 — signature S4 (script S-Iso-3)

**Script.** `C := ({k1}, ∅, [read(k1)])`;
ρ = `isolate(k1, r1); isolate(k1, r2); insert(root, C); settle`.

**Derivation.**

(1) γ0 ⇒ γ0′ [isolate(k1, r1)] — ρ := {k1↦r1}.

(2) ★ γ0′ ⇒ γ0″ [isolate(k1, r2)] — k1 **already isolated** (r1);
Def. 29 has **no precondition**: the input is *not refused*; the
derived context **reassigns** ρ := {k1↦r2} (the shared table is
untouched; there is no inverse). **S4**. κ = **{S4}**.

(3) γ0″ ⇒ γ1 [O-Insert @C] κ = {I1, I4}; C resolves k1 at r2.

(4) γ1 ⊘ [L-Begin @C] — {B1, B3, B7(k1)}: no table holds r2;
disabled. Quiet ✓ (C pending).

**Realized multiset at ★:** {S4}. Verdict content: **no refusal
event** on the second isolate (a precondition-adding deviant refuses),
and C's resolution follows r2, not r1 — observable as C pending even
if a provider is later added under r1 only. Deterministic.

---

## E.13 Coeffect operations III — CO-Int (Def. 31)

N1 (ε: no metadata) is realized by every intercept-free read;
canonical carrier E.LI.T1. Reads below evaluate Def. 31's
σ(k)(d(k) ⊕_k ι(k)); the realized value is written v1⟨μ⟩ for merged
metadata μ, and the occurrence records which side supplies each field
the read inspects.

### E.CN.N2 — signature N2 (script S-Int-2)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; intercept(k1, m1); insert(root, C);
settle`.

**Derivation.**

(1)–(4): E.OI.I1 (1)–(4) — P Active.

(5) γ4 ⇒ γ4′ [intercept(k1, m1)] — Def. 31: derived context
ι := {k1 ↦ ε ⊕ m1 = m1}; no registry effect, no inverse.

(6) γ4′ ⇒ γ5 [O-Insert @C] κ = {I1, I4}; C carries ι.
(7) γ5 → γ6 [L-Begin @C] {B1, B3, B5(k1)} — interception does not
touch resolution (realms do; ι enters only the get).

(8) ★ γ6 → γ7 [L-Iter @C] — read(k1): Algorithm 6 hit at self
(ω_C(k1) = P); the get evaluates σ(k1)(d(k1) ⊕ ι(k1)) with
d(k1) = ε (C declares no metadata) and ι(k1) = m1 — MetaPat =
**context-only, N2**. κ = {T1, T2(k1), T5} with CO-Int occurrence
**N2**. Emits rd(C,k1,v1⟨m1⟩).

(9) γ7 → γ8 [L-Finish @C] {F1, F3(k1)}, act(C). Quiet ✓.

**Realized multiset at ★:** {N2}. Report: C active; the read
value/certificate is the m1-dependent evaluation (≠ the ε evaluation
of E.LI.T1 — the pair pins ι's participation). Deterministic.

### E.CN.N3 — signature N3 (script S-Int-3)

**Script.** As E.CN.N2 with C declaring component metadata for k1:
ρ = `insert(root, P); settle; intercept(k1, m1);
insert(root, C, cfg={k1: m2}); settle`.

**Derivation.** Steps (1)–(7) as E.CN.N2 (C's entry now carries
d(k1) = m2).

(8) ★ γ6 → γ7 [L-Iter @C] — read(k1): the get evaluates
σ(k1)(m2 ⊕_k m1): **both** sides present — MetaPat =
component⊕context, **N3**; ⊕_k is right-biased, so on the overlapping
field **ι's m1 wins** and disjoint fields merge.
κ = {T1, T2(k1), T5} with **N3**. Emits rd(C,k1,v1⟨m2⊕m1⟩).

(9) L-Finish as before. Quiet ✓.

**Realized multiset at ★:** {N3}. Verdict: the overlapping field
carries m1 (context over component); a left-biased deviant shows m2.
Deterministic.

### E.CN.N4 — signature N4 (script S-Int-4)

**Script.** As E.CN.N2 with two intercepts:
ρ = `insert(root, P); settle; intercept(k1, m1); intercept(k1, m2);
insert(root, C); settle`.

**Derivation.** Steps as E.CN.N2 with (5′) a second intercept:
ι(k1) = (ε ⊕ m1) ⊕ m2 = m1 ⊕ m2.

(8) ★ [L-Iter @C] — read(k1): get evaluates σ(k1)(ε ⊕ (m1 ⊕ m2)):
two nested context entries — MetaPat = context₁⊕context₂, **N4**;
right-bias makes the **nearer/later m2 win** the overlapping field.
κ = {T1, T2(k1), T5} with **N4**. Emits rd(C,k1,v1⟨m1⊕m2⟩).

**Realized multiset at ★:** {N4}. Verdict: overlapping field carries
m2 (kills intercept-outer-wins). Depth 2 suffices: associativity of
⊕_k folds every deeper chain to this pattern (D1 §13.1).
Deterministic.

---

## E.14 Algorithm 6 — CO-Acc

A1, A2, A3, A5 are realized inside the L-Iter read windows of
E.LI.T1 (self hit), E.LI.T6 (ancestor hit), E.LI.T7 (ancestor IA),
E.LI.T8 (root UD). The one new script:

### E.CA.A6 — signature A6 (script S-Acc-1; isolation boundary, A8)

**Script.** `P := (∅, {k1}, [provide(k1,v1)])`, `G := ({k1}, ∅, [])`,
`C := (∅, ∅, [read(k1)])`;
ρ = `insert(root, P); insert(root, G); settle; isolate(k1, r1);
insert(G, C); settle`.

**Derivation.** Default label of k1 is ℓ0.

(1) γ0 ⇒ γ1 [O-Insert @P] κ = {I1, I4, I6(k1)}.
(2) γ1 ⇒ γ2 [O-Insert @G] κ = {I1, I4}.

⟨settle⟩ — G's begin waits on P's Activeness (B5's premise), so P's
chain runs first:

(3) [L-Begin @P] {B1, B3}; (4) [L-Iter @P] provide at ℓ0 ✓ {T1, T3},
σ_P := {ℓ0↦(k1,v1)}; (5) [L-Finish @P] {F1}, act(P).
(6) [L-Begin @G] — k1 Active-provided at ℓ0: {B1, B3, B5(k1)};
ω_G = {k1↦P}. (7) [L-Finish @G] {F2, F3(k1)}, act(G) — committed
view **retained** while Active. Quiet ✓.

(8) γ7 ⇒ γ7′ [isolate(k1, r1)] — ambient ρ := {k1↦r1}; G's own
resolution context (fixed at its insertion) still maps k1 ↦ ℓ0 —
the boundary now falls **between** C (to be inserted) and G.

(9) γ7′ ⇒ γ8 [O-Insert @C ⊳ insert(G, C)] — π = G ∈ dom F ✓ (I2).
κ = {I2, I4}. C's context: k1 ↦ r1.

⟨settle⟩:

(10) [L-Begin @C] — d_C = ∅: κ = {B1, B3}. θ_C ↦ Rel⟨[read(k1)];
id; {}⟩.

(11) ★ γ9 → γ10 [L-Iter @C] — T1; step read(k1): Algorithm 6 walk
from C: (self) ω_C = {} no k1, k1 ∉ d_C; (boundary check before
ascending — the A8 refinement) ℓ_C(k1) = r1 ≠ ℓ_G(k1) = ℓ0: **the
walk stops at the isolation boundary** — an ancestor resolving the
key in a different realm cannot authorize the access —
UNDECLARED_ACCESS, although ω_G binds k1 and would otherwise have
authorized it (contrast E.LI.T6). CO-Acc occurrence **A6**
(PosClass = isolation-boundary); step letter T8 (read-undeclared).
Lands per the A6 convention. κ = **{T1, T8}** with **A6**.
Emits rderr(C,k1,UD).

(12) [L-Finish @C] {F1} (C4 reading), act(C). Quiet ✓ — P, G, C all
active.

**Realized multiset at ★:** {A6} (window {T1, T8}). Report: all
active; rderr(C,k1,UD) despite a committed ancestor binding — the
observation separating A6 from A2/A5 (an ancestry-ignoring or
boundary-ignoring deviant returns v1 here). Deterministic.

---

## E.U Unrealizability proofs

Each proof establishes that the named occurrence appears in **no**
window of **any** run driven through Λ_orch ∪ {settle} from the empty
registry — D1's definition of reachability (§0). Proofs are by
invariants over reachable configurations, with the induction cases
enumerated against the ten rules and the interface inputs.

### E.U.1 — O-Insert I5 (stale name) is interface-unrealizable

**Occurrence.** I5: an insert attempt whose name n ∈ dom(F_γ).

**Proof.** There are exactly two sources of insert attempts:
(i) the Λ_orch input `insert(π, c, cfg)`, and (ii) a registering
iteration (Def. 47). Neither carries a name argument in the
interface: names are system-drawn — "introducing a fiber simply draws
one not already in use" (p. 30, the dynamically-created-local-names
discipline), and Def. 47 "draws the name, subject to the freshness
premise of O-Insert". Since F_γ is a *finite* partial function
(Def. 45) over the countable 𝔑, a name outside dom(F_γ) always
exists, so the draw is total. Hence at **every** insert attempt in
every run, the presented name satisfies n ∉ dom(F_γ): the window
contains I4 and cannot contain I5. (No induction over runs is even
needed: the claim is per-attempt, and the drawing discipline is part
of the attempt's construction.)

Consequently I5 is not merely never-fired but never-*attempted*: no
experiment presents a stale name, so a clause-factored
implementation's decision entry f_{O-Insert}(I5) is never exercised
by any script — which is exactly why I5 is excluded from T★ rather
than tested (CF3's table is unconstrained at unreachable letters;
D2's transport quantifies over reachable signatures only). ∎

### E.U.2 — L-Divert D6 (landing alternative) is interface-unrealizable

**Occurrence.** D6: an L-Divert firing whose second alternative is
taken — i(γ) = Right(δ, h, −) with h ≠ id composed into the
accumulator on the way to Unloading.

**Boundary invariant (BND).** *In every reachable configuration of
the instrumented 𝕊 (Def. 2 of the manuscript: script components, one
atomic landing per iteration of Def. 51; orchestration inputs fall
between settles), every Reloading fiber is at an iteration boundary —
no iteration is in flight.*

*Induction over rule applications.* Base: empty registry, no fibers.
O-Insert creates In(⊥); O-Retire/O-Remove write τ / delete — none
creates a Reloading state. L-Begin creates Rel⟨e_n; id; ω⟩ with the
iterator not yet applied: a boundary. L-Iter's single step takes
i(γ) = Right(δ, h, Just i′) and lands it entirely within the step
(the atomicity Def. 2 fixes); the post-state Rel⟨i′; g∘h; ω⟩ is again
at a boundary. L-Finish, L-Raise, L-Divert exit Reloading. No other
rule writes the θ of a Reloading fiber. ∎(BND)

**Inertia restriction.** §4.3.3 (p. 37): non-immediacy is modeled by
Future-valued iterations; "once launched, an iteration lands, and its
landing cannot be declined"; the layer "adds no rule … it takes the
form of a restriction on which alternative of L-Divert a host may
take" — the landing alternative is for a fiber holding an *in-flight*
iteration (p. 36: the abort alternative "only an iteration boundary
makes possible"; the landing alternative is "where §4.3.3 is
needed"). A host at an iteration boundary takes the abort
alternative.

**Conclusion.** By BND every reachable L-Divert window of 𝕊 is at a
boundary; by the inertia restriction the alternative taken there is
(δ,h) = (γ,id) — the D5 letter. Hence no reachable window carries
D6. The occurrence is calculus-real: dropping the atomicity of
Def. 2 (the Future layer) breaks BND exactly at the launch/landing
gap, and there D6 is forced, not optional. It is the synchronous
interface, not the rule, that excludes it (A9). ∎

### E.U.3 — L-Divert D2 (changed-provider divergence) is unrealizable

This and E.U.4 rest on three invariants and a corollary, proved here
once (the "committed-edge-pins-provider" lemma of manuscript §5.2).
Throughout, ℓ(k) denotes the storage label of k in the resolving
fiber's context (ℓ = k in the realm-free calculus; the ρ-table realm
under Def. 28, fixed per fiber at its insertion).

**Invariant DISJ (single declarer).** *∀ reachable γ, ∀ m ≠ m′ ∈
dom F_γ: p_m ∩ p_{m′} = ∅.*
*Induction.* Base: empty. O-Insert (whether the Λ_orch input or a
Def. 47 registration — the same rule with π = n): premise (iv)
∀m ∈ dom F. p ∩ p_m = ∅ makes the new fiber disjoint from every
present one; present pairs are untouched. O-Remove shrinks dom F. No
other rule or input edits dom F or any p-field. ∎

**Invariant TBL (table confinement).** *∀ reachable γ, ∀ n ∈ dom F_γ:
every entry of σ_n was written by n's own effect function or
inverses, and (realm-free) dom(σ_n) ⊆ p_n.*
*Induction.* Base: σ = ∅ at insertion (O-Insert's conclusion).
Writers of σ_n: L-Iter/L-Raise/L-Finish apply iterations of e_n, and
L-Unload applies g_n — all confined to n (Def. 43: "no key outside p
is one its effect function writes"; Def. 48(1): writes differ in n's
σ alone); a registration writes only the new entry and a τ (p. 32).
setval (Def. 24) replaces a value in place, preserving the domain;
isolate/intercept touch no σ. No rule writes another fiber's table. ∎

**Invariant UNIQ (label uniqueness).** *∀ reachable γ, ∀ label ℓ: at
most one fiber in dom F_γ has ℓ ∈ dom(σ_·).*
*Induction.* Base: no tables. Entries are created only by a Def. 23
set/provide landing, whose precondition — the reading D1 §8 fixes at
A4, realized as the X4 conflict — is that ℓ is unbound in **every**
registered fiber's table; the landing then creates the unique
binding. A_k operations preserve domains (Def. 24 acts on the
existing value). provide⁻¹ removes an entry; O-Remove deletes a
table. None duplicates a binding. ∎

**Lemma PIN (a live committed edge pins its provider).** *∀ reachable
γ: if m is installed with ω_m(k) = n, m ≠ n, then (a) n ∈ dom F_γ;
(b) θ_n ∈ {Active(−,−), Unloading(−,−,−)}; (c) ℓ(k) ∈ dom(σ_n),
where ℓ(k) is m's label for k, and this entry has persisted since the
edge was created.*

*Induction over rule applications, tracking the edge (m, k, n).*

- *Creation.* Only L-Begin(m) writes ω_m: ω_m := target_m(γ) ≠ ⊥, so
  ω_m(k) = provider_k(γ) — by Def. 45/eq. 40 the unique (UNIQ)
  **Active** fiber whose table holds ℓ(k). At creation (a)–(c) hold.
- *Edge persistence.* L-Iter/L-Finish carry ω_m unchanged (their
  conclusions rewrite i and g only); L-Divert/L-Leave/L-Raise carry
  ω_m into Unloading — m is **still installed** (eq. 44). The edge
  dies only at L-Unload(m) (ω discarded, m no longer installed) or
  never (O-Remove(m) requires Inactive, hence a prior L-Unload(m)).
- *Provider preservation while the edge lives.* Suppose (a)–(c) at γ
  and the edge survives the next step.
  - θ_n = Active: the only applicable θ_n-rules are L-Leave(n) →
    Unloading (claims preserved; σ_n untouched) — L-Unload needs
    Unloading, L-Begin needs Inactive, the Rel-rules need Reloading.
  - θ_n = Unloading: L-Unload(n) requires ¬relied_n(γ). But
    relied_n(γ) holds with witness (m, k): m ∈ dom F, k ∈ d_m
    (Def. 44: ω_m : d_m → 𝔑), m ≠ n, installed_m, ω_m(k) = n
    (Def. 50). So L-Unload(n) is **disabled**; θ_n stays Unloading.
  - Hence n never reaches Inactive while the edge lives, so
    O-Remove(n) (premise Inactive(−)) is disabled: (a) persists.
    θ_n never leaves {Active, Unloading}: (b) persists. (Note
    L-Begin is the *only* entry to Reloading and requires
    Inactive(⊥): a pinned provider can never be Reloading.)
  - *Table persistence (c):* entries of σ_n are removed only by
    g_n's provide⁻¹ at L-Unload(n) — disabled — or by O-Remove(n) —
    disabled. A_k overwrites preserve the domain (TBL case). No
    other fiber writes σ_n (Def. 48). So ℓ(k) ∈ dom σ_n persists.
  - O-Retire(n) may flip τ_n: it writes no θ, σ; claims unaffected. ∎

**Corollary NO-SWITCH.** *∀ reachable γ: if m is installed with
ω_m(k) = n, then provider_{ℓ(k)}(γ) ∈ {n, undefined} — never some
n′ ∉ {n}.* *Proof.* provider_{ℓ}(γ) is read off σ_γ, the union of
Active tables (eq. 40); a candidate n′ ≠ n must be Active with
ℓ ∈ dom σ_{n′}. By PIN(c), ℓ ∈ dom σ_n at γ; by UNIQ at γ, no second
fiber holds ℓ. So n′ does not exist; provider_ℓ is n (if n is
Active) or undefined (if n is Unloading). Realm-free reading: the
same argument via DISJ + TBL — k ∈ dom σ_{n′} ⊆ p_{n′} and
k ∈ p_n (TBL at creation) contradict DISJ. The `update` input does
not escape: an updated provider re-activates under the **same
name**, so the comparison ω_m(k) = n is by name (p. 31: "recording a
provider rather than a value is what makes the comparison usable")
and still agrees. ∎

**E.U.3 proper.** A reachable L-Divert window at consumer m carrying
D2 would have θ_m = Reloading (installed), ω_m(k) = n, and
provider_{ℓ(k)}(γ) = n′ with n′ ≠ n — contradicting NO-SWITCH. Hence
no reachable window carries D2: every divergence a Reloading
consumer can observe is a ⊥-divergence (D3/D4) or the A3 update
extension. (D1 A10, now proved rather than sketched.) ∎

### E.U.4 — L-Leave V2 (changed-provider divergence) is unrealizable

Identical to E.U.3 with θ_m = Active(−,ω_m) in place of Reloading:
Active is installed (eq. 44), so PIN and NO-SWITCH apply verbatim,
and a V2 window (ω_m(k) = n, provider_{ℓ(k)}(γ) = n′ ≠ n) is
contradictory. Provider replacement is observable only as the
two-window sequence ⊥-divergence (V4, provider gone) followed by a
fresh L-Begin against the new provider — E.LU.U12's derivation shows
precisely this shape — never as a one-window m→m′ comparison. ∎

### E.U.5 — Algorithm 6 A4 (self inactive-access) is unrealizable

**Occurrence.** A4: a fiber's read of its **own** declared key k ∈
d_n finds its committed view lacking k (Alg. 6 line 5 firing at
PosClass = self).

**Invariant TOT (view totality).** *∀ reachable γ, ∀ installed n:
dom(ω_n) = d_n.*
*Induction.* ω_n is created only by L-Begin(n): ω := target_n(γ) ≠ ⊥,
which by Def. 46 is the **total** map (k ∈ d_n) ↦ provider_k(γ) —
totality is exactly γ ⊨ d_n, forced by target ≠ ⊥. L-Iter/L-Finish
carry ω unchanged; L-Divert/L-Leave/L-Raise carry it into Unloading;
L-Unload discards it **whole** (n leaves installed-hood in the same
step). No rule writes a proper sub-view. ∎

**Steps run only installed.** A forward step of n executes inside an
L-Iter/L-Raise/L-Finish window — premise θ_n = Reloading, installed.
An inverse executes inside L-Unload(n)'s g application — θ_n =
Unloading, installed, and ω_n is discarded only as that step's *last
act* (p. 34), after g(γ) is computed; Def. 48(2) licenses exactly the
reads through the still-held view. No rule applies e_n or g_n at an
Inactive state (L-Begin's conclusion holds the iterator *unapplied*;
O-Remove deletes without running anything). Registration inserts a
child without running it (p. 32).

**Conclusion.** At every step execution by fiber n and every
k ∈ d_n, ω_n(k) is defined (TOT + installed-hood). Algorithm 6's
walk, started at n, therefore either returns at line 4 (committed
hit — whose withdrawn sub-case is impossible by E.U.6) or finds
k ∉ d_n and ascends; line 5 can never fire at the *self* position.
A pending fiber (which does have declared-uncommitted keys) executes
no step, so no window exhibits them. Line 5 at an *ancestor* remains
reachable (A3 — E.LI.T7): the ancestor is not the executing fiber.
This is the visibility half of §4.3.1's ordering promise, reappearing
as an unreachability fact. ∎

### E.U.6 — Algorithm 6 A7 (withdrawn committed binding) is unrealizable

**Occurrence.** A7: a walk's committed hit ω_w(k) = n whose provider
table lacks ℓ(k) at the moment of the read.

**Proof.** Let a read of key k, executed by fiber c, hit the
committed view of w (w = c or an ancestor of c) at ω_w(k) = n.

1. ω_w exists only while w is installed (Def. 49: only Reloading,
   Active, Unloading carry ω; L-Unload discards it upon leaving).
   So at the read, w is installed with ω_w(k) = n and k ∈ d_w
   (Def. 44: ω_w : d_w → 𝔑).
2. By Lemma PIN (E.U.3) applied to the edge (w, k, n): n ∈ dom F_γ,
   θ_n ∈ {Active, Unloading}, and ℓ(k) ∈ dom(σ_n) — the entry has
   persisted since the edge committed. (The label the walk uses is
   w's resolution label for k, the same one under which
   provider_{ℓ(k)} = n was read at commitment; a fiber's resolution
   context is fixed at insertion, so it cannot drift between
   commitment and read.)
3. Atomicity closes the last gap: the read occurs *within* a single
   rule application (an L-Iter window of c, or c's L-Unload g
   application — Def. 48(2)); no other rule fires between the
   window's premise evaluation and the read, so n cannot unload
   mid-step. Before the step, n's unload was disabled by
   relied_n(γ) with witness (w,k) — this includes the delicate case
   w = c mid-teardown: c is Unloading, hence installed, hence itself
   the witness pinning n (E.LU.U8's derivation walks this window
   positively and the read *succeeds*).

Hence the table lookup at line 4 always finds ℓ(k), and the
withdrawn-binding IA branch is dead in 𝕊. The model's branch
(readCommitted's `binding withdrawn` error) exists to convict the
deviants `unload-without-guard` and `unload-clears-view-early`, whose
runs violate PIN's step (2) resp. discard ω early; in the calculus
the unreachability of A7 *is* Theorem 63's content, witnessed
positively by E.LU.U2/E.LU.U8. ∎

---

## E.98 Corrections and clarifications to D1 (detail)

**C1 (error): S-Div-3 does not reach D3; corrected script supplied.**
D1 §7.4's printed ρ is
`insert(root,Q); insert(root,G); settle; retire(Q); retire(G);
insert(root,Q2); settle` with p_Q = p_{Q2} = {k2}. After the retire
inputs, Q is retired but **registered** (only O-Remove frees names
and declared keys — D1 §1, Table 1 premise (iv) over
∀m ∈ dom(F_γ)). The Q2 insert attempt is therefore the window
{I1, I4, I7(k2)} (witness m = Q) and is **refused** — the same
refusal D1's own S-Ins-4 canonizes. The printed run then settles as:
leave Q {V1,V3}; leave C {V1,V4(k2)} (k2 left σ_γ); leave G
{V1,V3}; unload G (inv(G,a); reg⁻ retires the already-Unloading C:
inner {R2}); unload C (inv(C,c), inv(C,b); τ_C=⊤ → {U1,U3,U6·2,U10});
unload Q; remove C, G, Q. C passes Active → Unloading → Inactive and
is **never Reloading during the settle**, so no L-Divert window
exists at all, let alone one carrying D3. What the printed script
actually realizes: {I7(k2)} plus V3/V4/U/M letters already covered
elsewhere. The corrected ρ′ (settle between retire(Q) and
insert(root,Q2), retire(G) moved after Q2's insert) realizes
{D1, D3, D5} at E.LD.D3(30); D1's component data is unchanged.
D1 §7.4, §15 (script count unchanged: 2) and the D3 reachability row
should cite ρ′.

**C2 (reading): U10–U12 are conditioned on ζ=⊥.** D1 §10.1 defines
U10–U12 as the τ × post-target bookkeeping blocks; §10.4's S-Unl-3
window {U1, U4, U6} omits any such letter although τ=⊥ ∧
post-target-satisfiable holds there literally — and U12's gloss
("successor: immediate re-begin") would be false for a ζ=ξ unload
(B2 blocks re-begin; E.LB.B2). Adopted reading, used throughout E.10:
a ζ=ξ unload carries no U10–U12 letter; its successor is fixed by
B2. D1 §10.1 should annotate U10–U12 with "ζ=⊥ only".

**C3 (clarification): S-Rem-2's full window.** The never-enabled
removal window of an unretired Active fiber is {M2, M5, M6}
(E.OM.M2(4)), of which D1 credits M2. Consistent with D1's
sharing convention; stated for checkability.

**C4 (alphabet imprecision): the F1/F2 split.** D1 §6.1 splits
L-Finish's scalar letter by "accumulator ≠ id" (F1) vs "first
iteration already Nothing, accumulator = id" (F2). A finishing window
after ≥ 1 landed iteration **whose iterations pushed no inverse**
(read-only scripts: E.LI.T6(11), E.LI.T8(4), E.LB.B5(8)/E.LF.F3(8),
E.CA.A6(12)) satisfies neither description: iterations landed, yet
g∘h = id. Adopted reading (used throughout): the split follows the
**iterator history** — F2 iff the *first* application yields Nothing
(the p. 36 degenerate 𝕰_Γ case), F1 otherwise — with the
accumulator's id/non-id constructor recorded as an equality pattern
inside the letter, not as its definition. D1 §6.1's F1 atom should
read "after ≥ 1 landed iteration" *simpliciter*. No script or
reachability claim changes.

**E1 (editorial).** D1 §4.4's S-Beg-5 retains an abandoned draft
fragment ("`retire(C2)?` — no: …") before its final ρ; E.LB.B6
derives the final ρ. D1 §10.4's S-Unl-9 similarly self-corrects
mid-paragraph to ρ′; E.LU.U12 derives ρ′. Both should be cleaned to
state only the surviving script.

---

## E.99 Completeness checklist

Every reachable occurrence of D1 §15's summary (86) has exactly one
**primary** derivation line (item + step); every unrealizable
occurrence (6) has exactly one impossibility proof. Totals:
86 + 6 = 92 = Σ|Σ_r|.

**O-Insert (6 reachable).**
| occ | primary | co-realized |
| --- | --- | --- |
| I1 | E.OI.I1(1) | every root insert |
| I2 | E.OI.I2(4) | E.LI.T10(3), E.LI.T6(7), E.OM.M7(3), E.LD.D3(7), E.LR.X9(3), E.LI.T7(12), E.CA.A6(9) |
| I3 | E.OI.I3(5) | — |
| I4 | E.OI.I1(1) | every insert window |
| I6 | E.OI.I1(1) | every providing insert |
| I7 | E.OI.I7(2) | E.98-C1 (printed S-Div-3) |
| I5 | — unrealizable → **E.U.1** | |

**O-Retire (4).**
| occ | primary | co-realized |
| --- | --- | --- |
| R1 | E.OT.R1(3) | E.OI.I3(2), E.OT.R4(2), E.OM.M1(2), E.LB.B4(2), E.LR.X9(5, inner) |
| R2 | E.OT.R2(5) | every installed retire; Def. 47 inverses (E.OM.M7(11), E.LD.D3(29), E.LU.U7(10), all inner) |
| R3 | E.OT.R3(5) | E.OM.M4(5) |
| R4 | E.OT.R4(5) | — |

**O-Remove (7).**
| occ | primary | co-realized |
| --- | --- | --- |
| M1 | E.OM.M1(4) | every completed disposal |
| M2 | E.OM.M2(4) | E.OT.R1(2, ⊘) |
| M3 | E.OM.M1(4) | passim |
| M4 | E.OM.M4(6) | E.OT.R3(6) |
| M5 | E.OM.M5(7) | E.OM.M2(4) |
| M6 | E.OM.M1(4) | passim |
| M7 | E.OM.M7(12) | E.LU.U7(11), E.LD.D3(33, ⊘) |

**L-Begin (7).**
| occ | primary | co-realized |
| --- | --- | --- |
| B1 | E.LB.B1(2) | every begin window |
| B2 | E.LB.B2(6) | — |
| B3 | E.LB.B1(2) | every unretired begin window |
| B4 | E.LB.B4(3) | E.OI.I3(3), E.OT.R4(3), E.LR.X9(6) |
| B5 | E.LB.B5(6) | E.LI.T1(6), E.LI.T7(13,34), E.LD.D3(10,26), E.LU.U12(6,12), E.CS.S3(8), E.CA.A6(6) |
| B6 | E.LB.B6(13) | — (schedule-dependent) |
| B7 | E.LB.B7(2) | E.OT.R1(2), E.LB.B6(19), E.LI.T7(29), E.CS.S2(7), E.CS.S4(4) |

**L-Iter (11).**
| occ | primary | co-realized |
| --- | --- | --- |
| T1 | E.LI.T1(7) | every enabled L-Iter window |
| T2 | E.LI.T1(7) | every satisfied-consumer iteration |
| T3 | E.LI.T3(3) | every provide landing |
| T4 | E.LI.T1(7) | every track |
| T5 | E.LI.T1(8) | E.LB.B5(7), E.LU.U2(8), E.LU.U8(7), E.CS.S3(9), E.CN.N2–N4(8) |
| T6 | E.LI.T6(10) | E.LI.T7(14) |
| T7 | E.LI.T7(35) | — |
| T8 | E.LI.T8(3) | E.CA.A6(11) |
| T9 | E.LI.T9(4) | — |
| T10 | E.LI.T10(3) | E.LI.T6(7), E.OM.M7(3), E.LD.D3(7), E.LR.X9(3) |
| T11 | E.LI.T11(3) | — |

**L-Finish (3).**
| occ | primary | co-realized |
| --- | --- | --- |
| F1 | E.LF.F1(4) | passim (C4 reading) |
| F2 | E.LF.F2(3) | E.OI.I2(3,6), E.LI.T7(11), E.CA.A6(7) |
| F3 | E.LF.F3(8) | every finishing consumer |

**L-Divert (4 of 6).**
| occ | primary | co-realized |
| --- | --- | --- |
| D1 | E.LD.D1(10) | E.LD.D3(30) — both schedule-dependent |
| D3 | E.LD.D3(30) | — (schedule-dependent; corrected script, C1) |
| D4 | E.LD.D1(10) | — |
| D5 | E.LD.D1(10) | E.LD.D3(30) |
| D2 | — unrealizable → **E.U.3** | |
| D6 | — unrealizable → **E.U.2** | |

**L-Raise (9).**
| occ | primary | co-realized |
| --- | --- | --- |
| X1 | E.LR.X1(3) | every raise window |
| X2 | E.LR.X1(3) | E.LR.X7/X8/X9 |
| X3 | E.LR.X3(3) | — |
| X4 | E.LR.X4(9) | — (isolation layer, A4) |
| X5 | E.LR.X5(3) | — |
| X6 | E.LR.X1(3) | E.LR.X3(3), X4(9), X5(3) |
| X7 | E.LR.X7(4) | E.LB.B2(4) |
| X8 | E.LR.X8(4) | E.LU.U4(4) |
| X9 | E.LR.X9(4) | — (schedule-noted, invariant) |

**L-Leave (4 of 5).**
| occ | primary | co-realized |
| --- | --- | --- |
| V1 | E.LL.V1(6) | every leave window |
| V3 | E.LL.V1(6) | passim (retire-driven leaves) |
| V4 | E.LL.V4(12) | E.LB.B6(14), E.LI.T7(20,21), E.LD.D1 branch, E.LD.D3(16), E.LU.U2(14), E.LU.U8(13) |
| V5 | E.LL.V5(6) | E.LU.U12(10) |
| V2 | — unrealizable → **E.U.4** | |

**L-Unload (12).**
| occ | primary | co-realized |
| --- | --- | --- |
| U1 | E.LU.U1(9) | every guard-clear unload |
| U2 | E.LU.U2(13) | E.LB.B6(15), E.LI.T7(22), E.LD.D1(11), E.LD.D3(17), E.LU.U8(12), E.LL.V4(13) |
| U3 | E.LU.U1(9) | every ζ=⊥ unload |
| U4 | E.LU.U4(5) | E.LR.X1(4) etc. |
| U5 | E.LU.U5(7) | E.LB.B2(5), E.LR.X7(5), E.LU.U2(16) |
| U6 | E.LU.U1(9) | passim |
| U7 | E.LU.U7(10) | E.OM.M7(11), E.LD.D3(29), E.LR.X9(5) |
| U8 | E.LU.U8(14) | — (A7 grammar extension) |
| U9 | E.LU.U9(6) | E.LB.B6(16), E.LI.T7(23,24) |
| U10 | E.LU.U1(9) | every retire-driven unload |
| U11 | E.LU.U11(14) | E.LB.B6(16), E.LD.D1(12), E.LD.D3(18) |
| U12 | E.LU.U12(11) | E.LL.V5(7) |

**CO-Prov (6).**
| occ | primary | co-realized |
| --- | --- | --- |
| P1 | E.LI.T3(3) | every provide landing |
| P2 | E.LR.X4(9) | — |
| P3 | E.CP.P3(5) | E.LI.T9(4) |
| P4 | E.CP.P4(4) | E.LR.X5(3) |
| P5 | E.LI.T1(8) | every successful read |
| P6 | E.LI.T8(3) | E.LI.T7(35) |

**CO-Iso (4).**
| occ | primary | co-realized |
| --- | --- | --- |
| S1 | E.OI.I1 (whole item; every isolate-free script) | |
| S2 | E.CS.S2(7) | — |
| S3 | E.CS.S3(8) | E.LR.X4(9) — negative form |
| S4 | E.CS.S4(2) | — |

**CO-Int (4).**
| occ | primary | co-realized |
| --- | --- | --- |
| N1 | E.LI.T1(8) | every intercept-free read |
| N2 | E.CN.N2(8) | — |
| N3 | E.CN.N3(8) | — |
| N4 | E.CN.N4(8) | — |

**CO-Acc (5 of 7).**
| occ | primary | co-realized |
| --- | --- | --- |
| A1 | E.LI.T1(8) | every self hit |
| A2 | E.LI.T6(10) | E.LI.T7(14) |
| A3 | E.LI.T7(35) | — |
| A5 | E.LI.T8(3) | — |
| A6 | E.CA.A6(11) | — |
| A4 | — unrealizable → **E.U.5** | |
| A7 | — unrealizable → **E.U.6** | |

**Item count check against D1 §15.** O-Insert 4 (E.OI.I1/I2/I3/I7);
O-Retire 4; O-Remove 5; L-Begin 6; L-Iter 8; L-Finish 3; L-Divert 2;
L-Raise 7; L-Leave 3; L-Unload 9; CO-Prov 2 new; CO-Iso 3; CO-Int 3;
CO-Acc 1 new — **60 items**, matching D1's 60 canonical scripts
one-for-one. Schedule-freedom notes were required at: E.OM.M7,
E.LI.T6, E.LI.T7 (phase interleavings), E.LI.T10, E.LB.B6
(occurrence schedule-dependent), E.LD.D1 (occurrence
schedule-dependent), E.LD.D3 (occurrence schedule-dependent),
E.LR.X9 (occurrence schedule-invariant). All other derivations are
schedule-deterministic (at most one enabled rule at every step, shown
line-by-line). Unrealizability proofs: E.U.1 (I5), E.U.2 (D6),
E.U.3 (D2), E.U.4 (V2), E.U.5 (A4), E.U.6 (A7) — matching D1 §15's
six negatives. The explorer deliverable (D3) cross-checks both
columns at bound B₀.

*End of Appendix E.*





