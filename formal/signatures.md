# D1 — Signature tables, finiteness, reachability, canonical scripts

Deliverable D1 of the two-track proof program (see `MASTER.md`). Authority
order: [SZC26] Table 1 (`../paper.pdf` p. 40) and the rule statements of
§4.2–§4.3 (pp. 31–38) > `../proof/src/model.mjs` > MASTER's drafts. Every
departure from MASTER's drafts is logged in §16 (Deviations); every point
where the calculus itself underdetermines the answer is logged in §17
(Ambiguities) and referenced inline as A1–A9.

## 0. Conventions

**Occurrences vs. signatures.** Following PAPER_REWRITE Definition 3, the
window of a rule attempt is normalized by
$\kappa_r : W_r \to \mathcal M_{\mathrm{fin}}(\Sigma_r)$ into a finite
*multiset of occurrences* over a finite alphabet $\Sigma_r$. The suite
$T^\star$ indexes canonical experiments by *atomic occurrence*
$s \in \Sigma_r^{\mathrm{reach}}$ (PAPER_REWRITE §5.2, Lemma 4), not by
whole-window multiset; a single script may realize several occurrences at
once (PAPER_REWRITE §7.1 explicitly allows sharing). "Reachable signature"
below therefore means: some window of some run from the empty registry,
driven entirely through the orchestration interface
$\Lambda_{\mathrm{orch}} \cup \{\mathsf{settle}\}$, contains that
occurrence.

**Cardinality freedom.** No occurrence mentions a count, a collection
length, or a whole map. Unbounded structure enters only as per-key
occurrences (target/satisfaction, view equality, conflict) and per-witness
occurrences (reliance edges, children, accumulator items), per
PAPER_REWRITE §4.1/§4.2.

**Atom domains.** Every atom below ranges over one of the fixed finite
domains

| domain | elements |
| --- | --- |
| `ParentClass` | root, present, absent |
| `Fresh` | fresh, stale |
| `StateClass` | Inactive(⊥), Inactive(ξ), Reloading, Active, Unloading |
| `RetClass` | τ=⊥, τ=⊤ |
| `OutClass` | ζ=⊥, ζ=ξ |
| `KeySat` | Active-provided, installed-only-provided, unprovided |
| `ViewRel` | key-equal, key-changed-provider, target-⊥-retired, target-⊥-unsatisfied, orch-update |
| `StepClass` | provide-fresh, provide-conflict, track, read-committed, read-ancestor-committed, read-declared-uncommitted, read-undeclared, setval-own, setval-foreign, register, raise, raiseUnless-set, raiseUnless-unset, exhausted, empty-script |
| `InvClass` | provide⁻¹, track⁻¹, register⁻¹, read-on-revert, (empty) |
| `PosClass` | self, ancestor, root-boundary, isolation-boundary |
| `RealmRel` | default, isolated-distinct, joined, reassigned |
| `MetaPat` | ε, context-only, component⊕context, context₁⊕context₂ |

Each is finite by inspection (3, 2, 5, 2, 2, 3, 5, 15, 5, 4, 4, 4
elements respectively); every finiteness proof below is a product count
over these domains, so it is written once here and instantiated per rule.

**Canonical component vocabulary.** Reserved names `P, Q, C, G, X` (with
subscripts), keys `k1, k2`, values `v1, v2`, tags `a, b, c`, error `x`,
realms `r1, r2`, metadata `m1, m2`, flag `f`. A component is written
`Name := (d, p, S)` with `d` the declared dependencies, `p` the declared
provisions, `S` the step list in PAPER_REWRITE §2.2 syntax
(`provide/track/read/setval/register/raise/raiseUnless`); orchestration
scripts use `insert(π, c, cfg) / retire(n) / update(n, cfg) /
setval(n, k, v) / isolate(k, r) / intercept(k, ν) / settle`.

**Verdict background.** Every ρ below is implicitly paired with the
verdict of PAPER_REWRITE §5.2 (equality, up to ≡, with the complete
specification outcome set over all fair schedules); derivation sketches
name the rule sequence of one realizing schedule, and where the occurrence
is schedule-dependent this is said explicitly.

---

## 1. O-Insert

**Table-1 row.** Premises: (i) $n \notin \mathrm{dom}(F_\gamma)$
(freshness); (ii) $\pi \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$;
(iii) $(d,p,e) \in \mathfrak C_\Gamma$ (static well-formedness);
(iv) $\forall m \in \mathrm{dom}(F_\gamma).\ p \cap p_m = \varnothing$.
Write: $\gamma[n \mapsto \langle d,p,e,\pi,\varnothing,\bot,
\mathsf{Inactive}(\bot)\rangle]$, $\Psi = \mathrm{id}_\Gamma$, control
fields edited: $\mathrm{dom}(F_\gamma)$.

Premise (iv) ranges over *every registered* fiber — retired, failed, or
mid-teardown fibers still block the keys they declare; only O-Remove frees
them (model.mjs `insert`, comment at line 198, agrees). Premise (iii) is a
static datum of the component language, not a runtime guard atom; it
contributes no occurrence.

### 1.1 Alphabet Σ_{O-Insert}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | I1 | ParentClass = root | scalar guard |
| 2 | I2 | ParentClass = present ($\pi \in \mathrm{dom}(F_\gamma)$) | scalar guard |
| 3 | I3 | ParentClass = absent ($\pi \neq \mathsf{root}$, $\pi \notin \mathrm{dom}(F_\gamma)$) | scalar guard, refusing |
| 4 | I4 | Fresh = fresh ($n \notin \mathrm{dom}(F_\gamma)$) | scalar guard |
| 5 | I5 | Fresh = stale ($n \in \mathrm{dom}(F_\gamma)$) | scalar guard, refusing |
| 6 | I6 | per-key: $k \in p$, no registered $m$ with $k \in p_m$ | per-key witness, clear |
| 7 | I7 | per-key: $k \in p$, ∃ registered $m$ with $k \in p_m$ | per-key witness, refusing |

$\kappa_{\text{O-Insert}}$ of a window is: one ParentClass occurrence, one
Fresh occurrence, and one of I6/I7 per declared provision key of the
inserted component (zero occurrences of that kind when
$p = \varnothing$).

### 1.2 Finiteness

$|\Sigma_{\text{O-Insert}}| = |{\text{ParentClass}}| + |{\text{Fresh}}| +
2 = 3 + 2 + 2 = 7$. The per-key kinds contribute exactly two alphabet
letters (witness-present, witness-absent) regardless of how many keys a
component declares or how many fibers are registered: the key name is
normalized away (CF2) and the existential over $m$ is folded to its
witness bit. Hence $\Sigma_{\text{O-Insert}}$ is finite with exactly 7
elements. ∎

### 1.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| I1 | yes | any first insert has $\pi = \mathsf{root}$. |
| I2 | yes | insert a second component naming the first as parent; the interface carries π. |
| I3 | yes | after retire + settle the parent's entry is removed (O-Remove), so its name no longer lies in $\mathrm{dom}(F_\gamma)$; a subsequent insert naming it is refused (model.mjs: `INACTIVE_EFFECT`). |
| I4 | yes | co-occurs with every accepted insert. |
| I5 | **interface-unrealizable** | names are system-drawn: neither $\Lambda_{\mathrm{orch}}$'s insert nor Def. 47 registration lets the caller choose $n$; Def. 47 "draws a name not already in use". No experiment can present a stale name, so I5 is discarded from $T^\star$ (per MASTER's draft, confirmed). |
| I6 | yes | co-occurs with every accepted insert of a providing component. |
| I7 | yes | insert two components both declaring $k_1 \in p$; the second is refused. No settle is needed in between — the check is against *declared* provisions, active or not. |

### 1.4 Canonical scripts

**S-Ins-1** (realizes I1, I4, I6):
`P := (d=∅, p={k1}, S=[provide(k1,v1)])`
ρ = `insert(root, P); settle`.
*Derivation:* empty registry ⊢ O-Insert premises (i,ii,iv) hold (root
parent, fresh name, no registered fiber to conflict); the pointed
configuration at the insert attempt carries occurrences {I1, I4, I6(k1)};
O-Insert fires, then settle runs L-Begin, L-Iter(provide), L-Finish.
Report: P active, k1 bound.

**S-Ins-2** (realizes I2):
`P := (∅, ∅, []); C := (∅, ∅, [])`
ρ = `insert(root, P); settle; insert(P, C); settle`.
*Derivation:* after the first settle P is registered (and Active); the
second insert's window has ParentClass = present; O-Insert fires; C
activates under P.

**S-Ins-3** (realizes I3):
`P := (∅, ∅, []); C := (∅, ∅, [])`
ρ = `insert(root, P); retire(P); settle; insert(P, C)`.
*Derivation:* retire sets $\tau_P$; settle runs L-Leave/L-Unload (or
nothing, if P never began) then O-Remove — P leaves
$\mathrm{dom}(F_\gamma)$; the final insert's window has ParentClass =
absent and is refused; refusal event recorded.

**S-Ins-4** (realizes I7):
`P := (∅, {k1}, [provide(k1,v1)]); Q := (∅, {k1}, [])`
ρ = `insert(root, P); insert(root, Q)`.
*Derivation:* P registered (state irrelevant, no settle run); Q's window
contains I7(k1) — witness m = P with $k_1 \in p \cap p_P$; premise (iv)
false; the insert is refused with a refusal event.

Scripts: **4**.

---

## 2. O-Retire

**Table-1 row.** Premise: $n \in \mathrm{dom}(F_\gamma)$. Write:
$\tau_n \mapsto \top$; $\theta_n$ unconstrained and unchanged;
$\Psi = \mathrm{id}_\Gamma$.

The rule reads no field of the fiber other than registry membership; the
state class recorded below is write-aspect bookkeeping only (which report
transitions follow), per MASTER's draft. Prior $\tau_n$ is not read and
the write $\tau \mapsto \top$ is idempotent, so a second retire of a
still-registered fiber falls into whichever state-class occurrence its
$\theta$ selects; no separate "already retired" letter is needed.

### 2.1 Alphabet Σ_{O-Retire}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | R1 | $n$ present, StateClass ∈ {Inactive(⊥)} ("pending") | scalar |
| 2 | R2 | $n$ present, StateClass ∈ {Reloading, Active, Unloading} ("installed", Def. 49 eq. 44) | scalar |
| 3 | R3 | $n$ present, StateClass = Inactive(ξ) ("failed") | scalar |
| 4 | R4 | $n \notin \mathrm{dom}(F_\gamma)$ | scalar, refusing |

### 2.2 Finiteness

The single guard atom (membership) has 2 values; the bookkeeping class
partitions StateClass (5 values) into 3 blocks on the positive side.
$|\Sigma_{\text{O-Retire}}| = 3 + 1 = 4$. ∎

### 2.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| R1 | yes | a consumer with an unsatisfied dependency stays Inactive(⊥) at quiescence; retire it. |
| R2 | yes | retire an Active fiber (the ordinary case). Reloading/Unloading sub-cases arise mid-settle via Def. 47 registration inverses; the Active representative suffices since the row reads none of them. |
| R3 | yes | a raising component quiesces at Inactive(ξ); retire it. |
| R4 | yes | retire a name already removed (retire twice with a settle between). |

### 2.4 Canonical scripts

**S-Ret-1** (R1): `C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, C); settle; retire(C); settle`.
*Derivation:* no provider for k1, so L-Begin never fires and C quiesces
pending; the retire window carries R1; then O-Remove disposes C
(childless, Inactive). Report: C disposed, never activated.

**S-Ret-2** (R2): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* P activates (L-Begin, L-Iter, L-Finish); the retire window
carries R2; settle then runs L-Leave, L-Unload (inv(P,a)), O-Remove.

**S-Ret-3** (R3): `P := (∅, ∅, [raise(x)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* L-Begin, L-Raise, L-Unload leave P at Inactive(ξ); the
retire window carries R3; O-Remove disposes it.

**S-Ret-4** (R4): `P := (∅, ∅, [])`;
ρ = `insert(root, P); retire(P); settle; retire(P)`.
*Derivation:* first retire + settle removes P; the second retire's window
carries R4; refusal event recorded.

Scripts: **4**.

---

## 3. O-Remove

**Table-1 row.** Premises: $\tau_n = \top$;
$\theta_n = \mathsf{Inactive}(-)$; $\forall m.\ \pi_m \neq n$
(childlessness). Write: $\gamma \setminus n$; $\Psi = \mathrm{id}_\Gamma$;
control fields edited: $\mathrm{dom}(F_\gamma)$.

**Interface note (A1).** O-Remove is orchestration-prefixed
($\gamma \Rightarrow \delta$) yet $\Lambda_{\mathrm{orch}}$ has no
`remove` input. We adopt the model's reading (model.mjs `removePass`
inside `sweep`): removal fires during settle whenever its premises hold,
as the §5.2 loader does. Blocked occurrences are therefore observed not as
refusals but as the fiber's persistence in the quiescent report or as
`disabled` certificates mid-settle. Logged as Ambiguity A1.

### 3.1 Alphabet Σ_{O-Remove}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | M1 | RetClass = τ=⊤ | scalar guard |
| 2 | M2 | RetClass = τ=⊥ | scalar guard, blocking |
| 3 | M3 | StateClass = Inactive(⊥) | scalar guard |
| 4 | M4 | StateClass = Inactive(ξ) | scalar guard |
| 5 | M5 | StateClass ∈ {Reloading, Active, Unloading} | scalar guard, blocking |
| 6 | M6 | per-witness: no $m$ with $\pi_m = n$ | witness, clear |
| 7 | M7 | per-witness: ∃$m$ with $\pi_m = n$ present | witness, blocking |

The premise's pattern $\mathsf{Inactive}(-)$ does not read ζ; M3/M4 are
distinguished because occurrence clause 2 (constructor selected) applies
and the quiescent report distinguishes disposal of a clean vs. failed
fiber (deviation Dev-3).

### 3.2 Finiteness

RetClass (2) + the 3-block StateClass partition + witness bit (2) gives
$2 + 3 + 2 = 7$ letters; the child fold contributes one witness bit
regardless of the number of children. $|\Sigma_{\text{O-Remove}}| = 7$. ∎

### 3.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| M1 | yes | every completed retire-then-settle disposal. |
| M2 | yes | any unretired quiescent fiber: removal is never attempted-enabled for it; witnessed by its presence in the report. |
| M3 | yes | disposal of a clean fiber (S-Rem-1). |
| M4 | yes | disposal of a failed fiber. |
| M5 | yes | mid-settle window: a retired fiber still Active/Unloading is not removable until L-Leave/L-Unload finish; witnessed by the certificate order deact(P) < removal. |
| M6 | yes | co-occurs with every leaf disposal. |
| M7 | yes | a parent whose registered child is still present stays registered until the child is removed (Table 1 discussion, p. 31: "removing children before their parent"). |

All 7 reachable.

### 3.4 Canonical scripts

**S-Rem-1** (M1, M3, M6): `C := ({k1}, ∅, [])`;
ρ = `insert(root, C); retire(C); settle`.
*Derivation:* C pending (unsatisfied), retired; window {M1, M3, M6};
O-Remove fires; report: C disposed.

**S-Rem-2** (M2): `P := (∅, ∅, [])`;
ρ = `insert(root, P); settle`.
*Derivation:* P activates and quiesces unretired; the (never-enabled)
removal window carries M2; report shows P still present — the observation
distinguishing M2's blocking decision.

**S-Rem-3** (M4): `P := (∅, ∅, [raise(x)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* L-Begin, L-Raise, L-Unload → Inactive(ξ); retire; removal
window {M1, M4, M6}; O-Remove fires; report: P disposed with recorded
failure (harness history, PAPER_REWRITE §2.3).

**S-Rem-4** (M5): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* during the second settle, after retire but before L-Unload
completes, P is retired and installed: the removal window carries
{M1, M5} and removal is disabled; certificates order
inv(P,a) ≤ deact(P) < removal. The occurrence is mid-settle; its
observation is the certificate/event order, not the final report.

**S-Rem-5** (M7): `G := (∅, ∅, [register(C), track(a)])`,
`C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle; retire(G); settle`.
*Derivation:* G activates, registering C; C activates. retire(G); G
leaves and unloads — its accumulator retires C (Def. 47 inverse = the
O-Retire of C). Between G reaching Inactive and C's own removal, G's
removal window carries {M1, M3, M7(witness C)}: blocked. C unloads and is
removed, then G's window flips to M6 and G is removed. Report: both
disposed; certificate order shows C's removal before G's.

Scripts: **5**.

---

## 4. L-Begin

**Rule (p. 36).** Premises: $\theta_n = \mathsf{Inactive}(\bot)$;
$\omega = \mathrm{target}_n(\gamma) \neq \bot$. Write:
$\theta_n \mapsto \mathsf{Reloading}(e_n, \mathrm{id}_\Gamma, \omega)$;
$\Psi = \mathrm{id}_\Gamma$.

$\mathrm{target}_n \neq \bot$ unfolds (Def. 46) to
$\tau_n = \bot \land \gamma \vDash d_n$, and $\gamma \vDash d_n$
decomposes pointwise: each $k \in d_n$ needs
$k \in \mathrm{dom}(\sigma_\gamma)$, with $\sigma_\gamma$ the union over
**Active** fibers only (Def. 45/eq. 40) — a key held in the table of a
Reloading/Unloading/failed fiber does not satisfy.

### 4.1 Alphabet Σ_{L-Begin}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | B1 | StateClass = Inactive(⊥) | scalar guard |
| 2 | B2 | StateClass = Inactive(ξ) | scalar guard, blocking (no lifecycle re-entry from an error outcome, p. 38) |
| 3 | B3 | RetClass = τ=⊥ | scalar guard |
| 4 | B4 | RetClass = τ=⊤ (forces target ⊥) | scalar guard, blocking |
| 5 | B5 | per-key: KeySat = Active-provided ($k \in d_n$, provider Active) | per-key |
| 6 | B6 | per-key: KeySat = installed-only-provided (some installed non-Active fiber's table holds $k$; $\sigma_\gamma$ excludes it) | per-key, blocking |
| 7 | B7 | per-key: KeySat = unprovided (no table holds $k$) | per-key, blocking |

$\kappa$ yields one state occurrence, one retirement occurrence, and one
KeySat occurrence per declared key ($d_n = \varnothing$ contributes zero
key occurrences; the enabled window is then {B1, B3} alone). The
installed-but-not-Inactive state classes contribute no letter: no L-Begin
window exists there (the rule's pattern match fails before any guard is
evaluated), and every such state is some other rule's window.

### 4.2 Finiteness

2 (state letters retained) + 2 (RetClass) + 3 (KeySat) = **7**. The
per-key decomposition contributes |KeySat| letters independent of $|d_n|$;
key identity is normalized away by CF2. ∎

### 4.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| B1 | yes | first settle after any insert of a satisfiable component. |
| B2 | yes | a raising component quiesces at Inactive(ξ) with a non-⊥ target (dep-free, unretired); the begin attempt is disabled exactly by B2 — quiet by eq. 45's first clause (ζ ≠ ⊥). |
| B3 | yes | co-occurs with every firing L-Begin. |
| B4 | yes | insert then retire before settle: the fiber is disposed without ever emitting act. |
| B5 | yes | consumer beginning against an Active provider. |
| B6 | yes | mid-teardown window: a provider in Unloading still holds its table (only L-Unload's accumulator withdraws it) while a pending consumer's begin attempt is evaluated. See S-Beg-5. |
| B7 | yes | consumer inserted with no provider at all. |

All 7 reachable.

### 4.4 Canonical scripts

**S-Beg-1** (B1, B3): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle`.
*Derivation:* O-Insert; window {B1, B3} enabled; L-Begin, L-Iter(track),
L-Finish. Observation: act(P) preceded by app(P,a); cert(L-Begin, …).

**S-Beg-2** (B2): `P := (∅, {k1}, [provide(k1,v1), raise(x)])`;
ρ = `insert(root, P); settle`.
*Derivation:* L-Begin, L-Iter(provide), L-Raise, L-Unload (inverse
withdraws k1) → Inactive(ξ). The subsequent begin window is {B2, B3}:
disabled; quiescent report shows P failed and k1 absent — re-entry would
be visible as a second app/act.

**S-Beg-3** (B4): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); retire(P); settle`.
*Derivation:* the begin window at settle is {B1, B4}: target ⊥ by
retirement; disabled. O-Remove disposes P. Report: disposed, no act(P),
no app(P,a).

**S-Beg-4** (B5): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.
*Derivation:* P Active; C's begin window {B1, B3, B5(k1)} enabled with
ω_C(k1) = P; L-Begin, L-Iter(read → rd(C,k1,v1)), L-Finish.

**S-Beg-5** (B6): `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C1 := ({k1}, ∅, [read(k1)])`, `C2 := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); insert(root, C1); settle; insert(root, C2);
retire(C2)?` — no: keep C2 pending by inserting it *after* retiring P:
ρ = `insert(root, P); insert(root, C1); settle; retire(P);
insert(root, C2); settle`.
*Derivation:* after the first settle P and C1 are Active. retire(P):
during the second settle P L-Leaves (Unloading, table still held), the
reliance guard (C1's committed edge) holds P there while C1 tears down.
In that window C2's begin attempt reads k1: some installed non-Active
fiber (P, Unloading) holds it but σ_γ excludes it — occurrence B6(k1),
disabled. After C1 and P unload, C2's window becomes B7. Report: C2
pending, never activated. B6 is witnessed by the disabled certificate
during the guarded window (distinguishing it from B7 and from the
mutant classes `leave-keeps-providing` / `satisfied-by-installed-provider`).

**S-Beg-6** (B7): `C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, C); settle`.
*Derivation:* no fiber's table holds k1; window {B1, B3, B7(k1)}
disabled; C quiesces pending (eq. 45: Inactive(⊥) quiet because target
= ⊥... target is ⊥ by unsatisfiability). Report: C pending.

Scripts: **6**.

---

## 5. L-Iter

**Rule (p. 36, read with §4.3.4's Right wrapper).** Premises:
$\theta_n = \mathsf{Reloading}(i,g,\omega)$;
$\mathrm{target}_n(\gamma) = \omega$;
$i(\gamma) = \mathsf{Right}(\delta, h, \mathsf{Just}(i'))$. Write:
$\theta_n \mapsto \mathsf{Reloading}(i', g \circ h, \omega)$;
$\Psi = \mathrm{pr}_1 \circ i$.

The view premise $\mathrm{target}_n(\gamma) = \omega$ decomposes per key:
$\neg\tau_n$, $\gamma \vDash d_n$, and $\omega(k) =
\mathrm{provider}_k(\gamma)$ for each $k \in d_n$. The iterator premise's
constructor is the step class: exactly the §2.2 step constructors that
land (Right) with a continuation. Steps that raise (Left) belong to
L-Raise's alphabet and iterator exhaustion (Nothing) to L-Finish's —
deviation Dev-5 from MASTER's pooled draft list.

### 5.1 Alphabet Σ_{L-Iter}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | T1 | StateClass = Reloading, view relation holds (scalar part: ¬τ, satisfied) | scalar |
| 2 | T2 | per-key: ViewRel = key-equal ($\omega(k) = \mathrm{provider}_k(\gamma)$) | per-key |
| 3 | T3 | StepClass = provide-fresh (label unbound; Def. 23 set precondition holds) | step |
| 4 | T4 | StepClass = track | step |
| 5 | T5 | StepClass = read-committed (Alg. 6 hit at self) | step |
| 6 | T6 | StepClass = read-ancestor-committed (Alg. 6 hit at an ancestor) | step |
| 7 | T7 | StepClass = read-declared-uncommitted (Alg. 6 IA; observed as rderr(n,k,IA), lands — A6) | step |
| 8 | T8 | StepClass = read-undeclared (Alg. 6 UD; rderr(n,k,UD), lands — A6) | step |
| 9 | T9 | StepClass = setval-own (A_k overwrite of an own binding, Def. 24 — PB-1 mapping) | step |
| 10 | T10 | StepClass = register (Def. 47: O-Insert under π = n, O-Retire as inverse) | step |
| 11 | T11 | StepClass = raiseUnless-set (flag present in cfg; lands, emits flag observation) | step |

### 5.2 Finiteness

1 scalar letter + 1 per-key letter + 9 step letters = **11**. The step
letters are a subset of the finite StepClass domain (15 constructors);
per-key letters are one per KeyRel value used (only key-equal appears in
an enabled L-Iter window). Payloads (keys, values, tags) are normalized
away by CF2; the equality pattern each occurrence records is on the ≤ 3
names/values that single atomic decision reads, hence finite. ∎

### 5.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| T1, T2 | yes | every iterating activation of a consumer with a dependency. |
| T3 | yes | any providing component's activation. |
| T4 | yes | any tracking component. |
| T5 | yes | consumer reads its own committed key. |
| T6 | yes | a registered/inserted child reads a key its ancestor declared and committed, without declaring it itself (Alg. 6 walk). |
| T7 | yes | reachable only through an orchestrator-inserted child under a *pending* declaring parent: the child re-iterates while the parent declares k1 but holds no committed view. See S-It-4; three fibers and two settles are required — the subtlest reachability fact in this deliverable. |
| T8 | yes | a component reads a key nobody declared on its chain. |
| T9 | yes | provider overwrites its own provided value mid-activation. |
| T10 | yes | any registering component. |
| T11 | yes | raiseUnless with the flag set in cfg. |

All 11 reachable.

### 5.4 Canonical scripts

**S-It-1** (T1, T2, T4, T5): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [track(a), read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.
*Derivation:* P Active; C L-Begins (ω(k1)=P); two L-Iter windows, each
carrying {T1, T2(k1)} plus T4 then T5; events app(C,a), rd(C,k1,v1);
L-Finish.

**S-It-2** (T3): P as above; ρ = `insert(root, P); settle`.
*Derivation:* L-Begin; L-Iter window with T3(k1): label unbound in every
other fiber's table; binding lands, provide⁻¹ pushed; L-Finish.

**S-It-3** (T6): `P := (∅, {k1}, [provide(k1,v1)])`,
`G := ({k1}, ∅, [register(C)])`, `C := (∅, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, G); settle`.
*Derivation:* P Active; G begins with ω_G(k1)=P and registers C; C
begins (dep-free); C's read walks Alg. 6: self miss (k1 ∉ d_C,
committed_C empty), parent G's committed binds k1 → ancestor hit;
rd(C,k1,v1) with occurrence T6.

**S-It-4** (T7): `P := (∅, {k1}, [provide(k1,v1)])`,
`Q := (∅, {k2}, [provide(k2,v2)])`, `Q2 := (∅, {k2}, [provide(k2,v2)])`,
`G := ({k1}, ∅, [])`, `C := ({k2}, ∅, [read(k1)])`;
ρ = `insert(root, P); insert(root, Q); settle; insert(root, G); settle;
insert(G, C); settle; retire(P); retire(Q); settle;
insert(root, Q2); settle`.
*Derivation:* after the third settle P, Q, G, C are Active; C (child of
G) read k1 through G's committed view (a T6 window). retire(P);
retire(Q); settle: P and Q withdraw; G's target turns ⊥ → G leaves,
unloads, quiesces **pending** with no committed view; C likewise unloads
(its k2 provider gone). insert(root, Q2); settle: C's target (k2 → Q2)
is satisfiable, C re-begins and re-runs read(k1): Alg. 6 walks — C: miss;
G: committed absent but $k_1 \in d_G$ → INACTIVE_ACCESS. Occurrence
T7; event rderr(C,k1,IA); C still lands and finishes (A6).

**S-It-5** (T8): `X := (∅, ∅, [read(k1)])`;
ρ = `insert(root, X); settle`.
*Derivation:* X begins; read walks to root with no declaration →
UNDECLARED_ACCESS; rderr(X,k1,UD); lands; L-Finish. Report: X active.

**S-It-6** (T9): `P := (∅, {k1}, [provide(k1,v1), setval(k1,v2)])`;
ρ = `insert(root, P); settle`.
*Derivation:* provide lands (T3); next L-Iter window carries T9: own
binding present, A_k overwrite v1 → v2; val(P,k1) event; L-Finish.
Report: k1 = v2.

**S-It-7** (T10): `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle`.
*Derivation:* G begins; L-Iter window with T10: the iteration performs
Def. 47's O-Insert (π = G, fresh name — occurrence I2/I4 of §1 also
realized) and pushes the O-Retire inverse; C then activates; both quiesce
Active.

**S-It-8** (T11): `P := (∅, ∅, [raiseUnless(f,x)])`;
ρ = `insert(root, P, cfg={f})`; `settle`.
*Derivation:* flag present → the step lands (T11) emitting the flag
observation; L-Finish. (Contrast X3 in §7.)

Scripts: **8**.

---

## 6. L-Finish

**Rule (p. 36).** Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$;
$\mathrm{target}_n(\gamma) = \omega$;
$i(\gamma) = (\delta, h, \mathsf{Nothing})$. Write:
$\theta_n \mapsto \mathsf{Active}(g \circ h, \omega)$;
$\Psi = \mathrm{pr}_1 \circ i$.

### 6.1 Alphabet Σ_{L-Finish}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | F1 | StateClass = Reloading, view holds, iterator Nothing, after ≥ 1 landed iteration (accumulator ≠ id) | scalar |
| 2 | F2 | as F1 but the degenerate 𝔈_Γ case: first iteration already yields Nothing, accumulator = id (p. 36's "plain effect function" paragraph) | scalar |
| 3 | F3 | per-key: ViewRel = key-equal at the finishing window | per-key |

### 6.2 Finiteness

2 scalar letters + 1 per-key letter = **3**. The accumulator's content is
not enumerated here (its items are L-Unload's per-item occurrences); only
the id/non-id constructor distinction of occurrence clause 2 appears. ∎

### 6.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| F1 | yes | every component with a nonempty step list that completes. |
| F2 | yes | a component with an empty step list. |
| F3 | yes | every finishing consumer. |

### 6.4 Canonical scripts

**S-Fin-1** (F1): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle`.
*Derivation:* L-Begin; L-Iter(track); the next window has i(γ) = Nothing
with g ∘ h ≠ id → L-Finish fires, act(P). Occurrence F1.

**S-Fin-2** (F2): `P := (∅, ∅, [])`;
ρ = `insert(root, P); settle`.
*Derivation:* L-Begin; the first iterator application yields Nothing;
L-Finish with accumulator id — occurrence F2; act(P) with no app events.

**S-Fin-3** (F3): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1)])`;
ρ = `insert(root, P); settle; insert(root, C); settle`.
*Derivation:* C's finishing window carries F3(k1) (ω(k1) = P still the
provider); act(C) after rd(C,k1,v1).

Scripts: **3**.

---

## 7. L-Divert

**Rule (p. 36).** Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$;
$\mathrm{target}_n(\gamma) \neq \omega$;
$(\delta,h) = (\gamma, \mathrm{id}_\Gamma)$ **or**
$i(\gamma) = (\delta, h, -)$. Write:
$\theta_n \mapsto \mathsf{Unloading}(g \circ h, \omega, \bot)$;
$\Psi = \mathrm{id}_\Gamma$ or $\mathrm{pr}_1 \circ i$.

The divergence premise decomposes: either $\mathrm{target} = \bot$
(via $\tau$ or unsatisfiability) or some key's provider differs from the
committed one. The two alternatives (abort the held iteration / let it
land) are the rule's own disjunction; §4.3.3 restricts a host under
inertia to the landing alternative.

### 7.1 Alphabet Σ_{L-Divert}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | D1 | StateClass = Reloading, divergence present (scalar) | scalar |
| 2 | D2 | per-key: ViewRel = key-changed-provider ($\omega(k) = m$, $\mathrm{provider}_k(\gamma) = m' \neq m$; equality pattern m ≠ m′) | per-key witness |
| 3 | D3 | ViewRel = target-⊥-retired ($\tau_n$ flipped mid-activation) | scalar |
| 4 | D4 | per-key: ViewRel = target-⊥-unsatisfied (a committed key's provider left σ_γ) | per-key witness |
| 5 | D5 | alternative = abort ($h = \mathrm{id}_\Gamma$) | scalar |
| 6 | D6 | alternative = land ($i(\gamma) = (\delta,h,-)$ with $h \neq \mathrm{id}$) | scalar |

### 7.2 Finiteness

1 + 1 + 1 + 1 + 2 = **6** letters; the divergence classes are drawn from
the finite ViewRel domain, one occurrence per witnessing key, and the
alternative bit is binary. ∎

### 7.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| D1 | yes | any mid-activation target change (below). |
| D2 | **interface-unrealizable** | a provider replacement visible as m → m′ would require the old provider removed (or a co-declarer inserted) while the consumer still holds ω(k)=m; the reliance guard blocks the former and O-Insert's declared disjointness the latter. Full argument at S-Div-2 below and A10. |
| D3 | yes | only Def. 47's inverse can flip τ during a settle; a registered child that is concurrently re-activating when its registering parent unloads meets D3. See S-Div-3. |
| D4 | yes | committed provider withdraws (L-Leave) while consumer is between iterations. |
| D5 | yes | the synchronous interface always aborts at an iteration boundary (model.mjs L-Divert branch). |
| D6 | **interface-unrealizable** | landing the in-flight iteration requires the target to change *between an iteration's launch and its landing* (§4.3.3 inertia). In the §2.2 script semantics every step is one atomic landing and orchestration inputs fall between settles, so no experiment separates launch from landing. The occurrence is real in the calculus; it is excluded from $T^\star$ with the same status as I5. Logged as A9. |

4 of 6 reachable (D1, D3, D4, D5).

### 7.4 Canonical scripts

**S-Div-1** (D1, D4, D5): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [track(a), track(b)])`;
ρ = `insert(root, P); settle; insert(root, C); retire(P); settle`.
*Derivation:* at the second settle both C's L-Begin (P still Active —
τ_P does not enter target_C) and P's L-Leave are enabled: a
nondeterministic branch. On the branch that begins C first: C commits
ω(k1)=P, iterates track(a); P leaves (Unloading — guarded from unloading
by C's committed edge); C's next window has target_C = ⊥
(k1 ∉ dom σ_γ) ≠ ω — occurrences {D1, D4(k1), D5}; L-Divert aborts,
C unloads (inv(C,a)), quiesces pending; guard releases, P unloads and is
removed. The exhaustive explorer must also visit the branch where P
leaves first (C never begins); both outcomes lie in Out(ρ).

**S-Div-2 — withdrawn (unreachability argument for D2).** Suppose a
window where some consumer C is Reloading with $\omega_C(k_1) = P$ and
$\mathrm{provider}_{k_1}(\gamma) = P' \neq P$. Then (i) C is installed
with a committed edge to P, so $\mathrm{relied}_P(\gamma)$ holds and
L-Unload is blocked at P: P cannot reach Inactive, hence cannot be
O-Removed, hence stays registered with $k_1 \in p_P$. (ii) While P is
registered, O-Insert refuses any component declaring $k_1$ — directly or
through Def. 47 registration (same premise) — so no fiber P′ declaring
$k_1$ can enter the registry. (iii) A registered non-declarer cannot
provide $k_1$ either: Def. 43 confines an effect function's writes to its
declared $p$, and under isolation a *joined* provider's provide would
raise on the still-bound label (X4) rather than land. So no P′ exists:
contradiction. The divergence a Reloading consumer can observe is
therefore always target = ⊥ (D3/D4), never a changed provider. Logged as
A10; the same argument applies verbatim to L-Leave's V2 (§9.3).

**S-Div-3** (D3): `Q := (∅, {k2}, [provide(k2,v2)])`,
`Q2 := (∅, {k2}, [provide(k2,v2)])`,
`G := (∅, ∅, [register(C), track(a)])`,
`C := ({k2}, ∅, [track(b), track(c)])`;
ρ = `insert(root, Q); insert(root, G); settle; retire(Q); retire(G);
insert(root, Q2); settle`.
*Derivation:* first settle: Q, G, C all Active (G registered C; C
committed ω(k2)=Q). Second settle, on the branch: Q leaves (retired);
C's target turns ⊥ → C leaves, unloads (inv order c, b), pending; Q2
begins, finishes → C re-begins (ω(k2)=Q2), iterates track(b) —
Reloading; now schedule G: G leaves (retired), G's guard is clear (C's
committed view names Q2, not G), G unloads — its register inverse
performs O-Retire(C), flipping τ_C while C is Reloading. C's next window:
{D1, D3, D5} — target ⊥ by retirement; L-Divert; C unloads (inv(C,b)),
disposed with G. Every occurrence here is branch-dependent; the
exhaustive explorer collects all interleavings.

Scripts: **2** (S-Div-1, S-Div-3; S-Div-2 withdrawn by the A10 analysis).

---

## 8. L-Raise

**Rule (p. 38).** Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$;
$i(\gamma) = \mathsf{Left}(\xi)$. Write:
$\theta_n \mapsto \mathsf{Unloading}(g, \omega, \xi)$;
$\Psi = \mathrm{id}_\Gamma$.

**No view premise (A2).** L-Raise does not read the target, so at a
window where target ≠ ω *and* the next iteration raises, both L-Divert
(abort) and L-Raise are enabled — genuine calculus nondeterminism that
model.mjs resolves deterministically in favor of L-Divert (its Reloading
branch tests the view first). Exhaustive exploration must offer both.

### 8.1 Alphabet Σ_{L-Raise}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | X1 | StateClass = Reloading, iterator Left(ξ) (scalar) | scalar |
| 2 | X2 | StepClass = raise | step |
| 3 | X3 | StepClass = raiseUnless-unset (flag absent from cfg; equality pattern: cfg ∌ f) | step |
| 4 | X4 | StepClass = provide-conflict (Def. 23 set precondition fails: label already bound in another fiber's table) | step |
| 5 | X5 | StepClass = setval-foreign (A_k with no own binding at the label) | step |
| 6 | X6 | InvClass = (empty) — accumulator id at the raise | per-item |
| 7 | X7 | InvClass = provide⁻¹ present in g | per-item witness |
| 8 | X8 | InvClass = track⁻¹ present in g | per-item witness |
| 9 | X9 | InvClass = register⁻¹ present in g | per-item witness |

### 8.2 Finiteness

1 scalar + 4 step letters (the Left-producing subset of StepClass) +
1 empty marker + 3 inverse-class witnesses = **9**. Accumulator length is
invisible: each accumulated item contributes one occurrence of its
InvClass, and the alphabet holds one letter per class. ∎

### 8.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| X1, X2, X6 | yes | a bare raising component. |
| X3 | yes | raiseUnless with cfg omitting f. |
| X4 | yes — **but only through the isolation layer** | in the realm-free base calculus, O-Insert's declared disjointness plus Def. 43's confinement (a fiber writes only keys in p) make live tables disjoint, so the set precondition can never fail: X4 is unreachable there. With Def. 28 realms, two keys isolated to one realm ("joined") collide at the same label while their *declared* key sets stay disjoint, slipping past O-Insert. Logged as A4 — a genuine gap in the calculus's premise inventory. |
| X5 | yes | setval on a key the component never provided. |
| X7 | yes | provide before raise. |
| X8 | yes | track before raise. |
| X9 | yes | register before raise (recovery retires the child). |

All 9 reachable (X4 conditionally on the isolation layer being in scope,
which this deliverable's coeffect sections make it).

### 8.4 Canonical scripts

**S-Rai-1** (X1, X2, X6): `P := (∅, ∅, [raise(x)])`;
ρ = `insert(root, P); settle`.
*Derivation:* L-Begin; first window's iterator yields Left(x) with g =
id: occurrences {X1, X2, X6}; L-Raise → Unloading(id, ω, x); L-Unload
(nothing to revert) → Inactive(ξ). Report: P failed(x), no act.

**S-Rai-2** (X3): `P := (∅, ∅, [raiseUnless(f,x)])`;
ρ = `insert(root, P, cfg={})`; `settle`.
*Derivation:* cfg lacks f → Left(x); as S-Rai-1 with occurrence X3.

**S-Rai-3** (X4): `P := (∅, {k1}, [provide(k1,v1)])`,
`Q := (∅, {k2}, [provide(k2,v2)])`;
ρ = `isolate(k1, r1); isolate(k2, r1); insert(root, P); settle;
insert(root, Q); settle`.
*Derivation:* both keys resolve to realm r1; P binds label r1. Q's insert
passes O-Insert ({k2} ∩ {k1} = ∅); Q's provide(k2,·) meets the set
precondition ρ(k2) = r1 ∈ dom(σ) → Left; occurrences {X1, X4, X6};
L-Raise, L-Unload → Q failed. Report: Q failed, k1 still bound by P.

**S-Rai-4** (X5): `P := (∅, ∅, [setval(k1,v2)])`;
ρ = `insert(root, P); settle`.
*Derivation:* no own binding at k1's label → A_k precondition fails →
Left; {X1, X5, X6}; P failed.

**S-Rai-5** (X7): `P := (∅, {k1}, [provide(k1,v1), raise(x)])`;
ρ = `insert(root, P); settle`.
*Derivation:* provide lands (pushes provide⁻¹); raise window carries
{X1, X2, X7}; L-Raise carries g = provide⁻¹ into Unloading; L-Unload
withdraws k1. Report: P failed, k1 absent — the withdrawal
distinguishes X7.

**S-Rai-6** (X8): `P := (∅, ∅, [track(a), raise(x)])`;
ρ = `insert(root, P); settle`.
*Derivation:* app(P,a); raise window {X1, X2, X8}; recovery emits
inv(P,a) before deact — the inverse event distinguishes X8.

**S-Rai-7** (X9): `G := (∅, ∅, [register(C), raise(x)])`,
`C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle`.
*Derivation:* registration inserts C; G raises; window {X1, X2, X9};
L-Unload's g performs O-Retire(C); C (which may have activated on an
interleaved branch) tears down and both are disposed/failed per branch.
Report: G failed, C disposed.

Scripts: **7**.

---

## 9. L-Leave

**Rule (p. 34).** Premises: $\theta_n = \mathsf{Active}(g,\omega)$;
$\mathrm{target}_n(\gamma) \neq \omega$. Write:
$\theta_n \mapsto \mathsf{Unloading}(g, \omega, \bot)$;
$\Psi = \mathrm{id}_\Gamma$.

### 9.1 Alphabet Σ_{L-Leave}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | V1 | StateClass = Active, divergence present (scalar) | scalar |
| 2 | V2 | per-key: ViewRel = key-changed-provider | per-key witness |
| 3 | V3 | ViewRel = target-⊥-retired | scalar |
| 4 | V4 | per-key: ViewRel = target-⊥-unsatisfied | per-key witness |
| 5 | V5 | ViewRel = orch-update (update(n,cfg) forces re-resolution; **extension**, A3) | scalar |

### 9.2 Finiteness

1 + 4 ViewRel letters = **5**; per-key classes contribute one letter each
independent of |d_n|. ∎

### 9.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| V1 | yes | every deactivation of an Active fiber. |
| V2 | **interface-unrealizable** | the S-Div-2 argument (§7.4, A10) applies verbatim with C Active instead of Reloading: while C holds ω(k1)=P1, P1 cannot be removed (reliance guard) and no other declarer of k1 can be inserted (O-Insert), so provider_k1 can only become ⊥, never P2 ≠ P1. Nor does `update` help: an updated provider re-activates under the *same* name, so ω(k1) still matches. Provider replacement is realizable only as ⊥-then-new-provider across two windows (V4 followed by a fresh L-Begin), never as a direct m → m′ comparison. |
| V3 | yes | retire an Active fiber. |
| V4 | yes | withdraw the provider under an Active consumer. |
| V5 | yes | update(n, cfg′) on an Active fiber forces leave/re-begin with the new config. |

4 of 5 reachable.

### 9.4 Canonical scripts

**S-Lea-1** (V1, V3): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* window {V1, V3}: Active, τ=⊤ ⇒ target ⊥ ≠ ω; L-Leave;
L-Unload (inv(P,a)); O-Remove. Certificate order deact after inv.

**S-Lea-2** (V4): `P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), track(a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle`.
*Derivation:* P leaves first (only enabled rule: its target is ⊥, C's
still matches until σ_γ loses k1); then C's window is {V1, V4(k1)}:
Active with committed k1 unprovided; L-Leave; C unloads — its inv(C,a)
runs while P is still Unloading (reliance guard, §10); C pending; P
unloads, removed. Report: C pending.

**S-Lea-3** (V5): `P := (∅, ∅, [track(a)])`;
ρ = `insert(root, P); settle; update(P, cfg2); settle`.
*Derivation:* update rewrites the entry and marks the episode stale;
window {V1, V5}; L-Leave, L-Unload (inv(P,a)), L-Begin, L-Iter,
L-Finish — a full bounce observable as inv(P,a) < app(P,a) with two act
events. The calculus has no rule for `update`; this is the loader
extension of A3.

Scripts: **3**.

---

## 10. L-Unload

**Rule (p. 34).** Premises: $\theta_n = \mathsf{Unloading}(g,\omega,\zeta)$;
$\neg\mathrm{relied}_n(\gamma)$; $g(\gamma) = \delta$. Write:
$\theta_n \mapsto \mathsf{Inactive}(\zeta)$; $\Psi = g$ (the only rule
applying an accumulator).

$\mathrm{relied}_n$ (Def. 50) is an existential fold over committed-view
edges: $\exists m \neq n,\ k \in d_m.\ \mathrm{installed}_m \land
\omega_m(k) = n$ — one witness occurrence per edge class. The
accumulator $g = g_1 \circ \cdots \circ g_j$ decomposes per item into
InvClass occurrences, applied LIFO. τ and the post-state target are not
read by the rule; they are write-aspect bookkeeping recorded because the
canonical verdict observes the successor (removal / rest / bounce).

### 10.1 Alphabet Σ_{L-Unload}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | U1 | StateClass = Unloading, guard clear (no reliance witness) | scalar |
| 2 | U2 | per-witness: ∃ installed $m$, $k$ with $\omega_m(k) = n$ | witness, blocking |
| 3 | U3 | OutClass ζ=⊥ | scalar |
| 4 | U4 | OutClass ζ=ξ | scalar |
| 5 | U5 | per-item: InvClass = provide⁻¹ | per-item |
| 6 | U6 | per-item: InvClass = track⁻¹ | per-item |
| 7 | U7 | per-item: InvClass = register⁻¹ (performs O-Retire of the child) | per-item |
| 8 | U8 | per-item: InvClass = read-on-revert (an inverse whose run reads a committed coeffect, Def. 48 clause 2) | per-item |
| 9 | U9 | accumulator = id (no items) | scalar |
| 10 | U10 | bookkeeping: RetClass τ=⊤ (successor: removable) | scalar |
| 11 | U11 | bookkeeping: τ=⊥ ∧ post-target = ⊥ (successor: rests pending) | scalar |
| 12 | U12 | bookkeeping: τ=⊥ ∧ post-target satisfiable (successor: immediate re-begin — the deactivation-chains-into-activation composite of §4.3.3) | scalar |

### 10.2 Finiteness

1 + 1 + 2 + 4 + 1 + 3 = **12** letters. Reliance witnesses: one letter
regardless of how many dependents or edges exist. Accumulator items: one
letter per InvClass (4) plus the empty marker; item count and item order
are properties of the multiset and of the observation word, not extra
letters. Bookkeeping: RetClass × post-target folded into 3 blocks. ∎

### 10.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| U1 | yes | every completed deactivation. |
| U2 | yes | retire a provider under an installed consumer: the guard window is observable as the certificate order (consumer's inverses and committed reads precede provider's inverses — Thm. 63's content, PAPER_REWRITE §5.3 "reliance guard"). |
| U3 | yes | any clean deactivation. |
| U4 | yes | any failed activation's recovery. |
| U5 | yes | retire a provider. |
| U6 | yes | retire a tracker. |
| U7 | yes | retire a registering host. |
| U8 | yes in the calculus; **not expressible in the §2.2 step grammar** | Def. 48 clause 2 lets an inverse read $\sigma_m|_{d_n}$; the calculus reaches U8 whenever a consumer's teardown inverse reads its committed key. But §2.2's `track(t)` inverse only emits inv(n,t) — no step constructor yields a reading inverse. model.mjs extends the grammar with `trackReadOnRevert` precisely for this. Logged as A7; canonical script below uses the extension, flagged. |
| U9 | yes | retire an empty-script component. |
| U10 | yes | any retire-driven unload. |
| U11 | yes | consumer whose provider is gone rests pending. |
| U12 | yes | provider replaced across settles: unload's successor window re-begins. |

All 12 reachable (U8 modulo the A7 grammar extension).

### 10.4 Canonical scripts

**S-Unl-1** (U1, U3, U6, U10): `P := (∅, ∅, [track(a), track(b), track(c)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* L-Leave; window {U1, U3, U6×3, U10}; L-Unload applies
g = c⁻¹∘b⁻¹∘a⁻¹ read LIFO: inv(P,c) < inv(P,b) < inv(P,a) < deact(P);
O-Remove. This is PAPER_REWRITE §5.3's accumulator-order canonical test.

**S-Unl-2** (U2): `P := (∅, {k1}, [provide(k1,v1), track(a)])`,
`C := ({k1}, ∅, [read(k1), track(b)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P); settle`.
*Derivation:* P leaves; P's unload window carries U2 (witness: C
installed, ω_C(k1)=P): blocked. C leaves (V4), C unloads (inv(C,b));
C's committed view gone → P's window flips to U1; P unloads
(inv(P,a), withdraw k1); removal. Verdict: inv(C,b) precedes inv(P,a)
and the k1 withdrawal — the positive-witness entry of the reliance fold
(PAPER_REWRITE §5.3's second representative test).

**S-Unl-3** (U4): `P := (∅, ∅, [track(a), raise(x)])`;
ρ = `insert(root, P); settle`.
*Derivation:* L-Raise carries ζ = x into Unloading; window {U1, U4, U6};
L-Unload: inv(P,a), fiber Inactive(x). Report: P failed.

**S-Unl-4** (U5): `P := (∅, {k1}, [provide(k1,v1)])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* window {U1, U3, U5, U10}; the provide⁻¹ item withdraws the
binding; report: k1 absent, P disposed.

**S-Unl-5** (U7): `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`;
ρ = `insert(root, G); settle; retire(G); settle`.
*Derivation:* G's unload window {U1, U3, U7, U10}; the register⁻¹ item
retires C (Def. 47); the cascade then unloads and removes C (inv(C,b));
G removable only after (M7, §3). Certificate order: inv(C,b) after G's
deact — the child is reached "one level at a time" (p. 32).

**S-Unl-6** (U8; uses the A7 grammar extension `trackReadOnRevert(k1, t)`):
`P := (∅, {k1}, [provide(k1,v1)])`,
`C := ({k1}, ∅, [read(k1), trackReadOnRevert(k1, a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P); settle`.
*Derivation:* as S-Unl-2, but C's inverse *reads* k1 during C's L-Unload:
P is still Unloading (guard held by C), its table intact, so the read
succeeds with v1 — occurrence U8, the committed-read-during-teardown
that Thm. 63 promises; observed as rd-on-revert(C,k1,v1) before P's
withdrawal.

**S-Unl-7** (U9): `P := (∅, ∅, [])`;
ρ = `insert(root, P); settle; retire(P); settle`.
*Derivation:* window {U1, U3, U9, U10}; g = id; deact(P) with no inv
events.

**S-Unl-8** (U11): shared with S-Lea-2 (§9.4): C's unload window carries
{U1, U3, U6, U11}; C rests pending — no re-begin certificate follows.

**S-Unl-9** (U12): `P := (∅, {k1}, [provide(k1,v1)])`,
`P2 := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [track(a)])`;
ρ = `insert(root, P); settle; insert(root, C); settle; retire(P);
settle; insert(root, P2); settle`.
*Derivation:* third settle: C unloads (U11 window), P removed. Fourth
settle: P2 activates; C's L-Begin refires. To realize U12 proper (unload
whose *successor window* is already satisfiable) the explorer takes the
branch in the third-and-fourth combined trace where... P2's insert
follows the settle, so within the fourth settle C is already Inactive.
U12 needs unload and satisfiability in one window: use update instead —
ρ′ = `insert(root, P); settle; insert(root, C); settle; update(C, cfg2);
settle`: C leaves (V5), unloads with τ=⊥ and target still k1 → P
satisfiable — occurrence U12 — and immediately re-begins: deact(C)
directly followed by app/act(C). Canonical script is ρ′.

Scripts: **9**.

---

## 11. Coeffect operations I — Def. 23/24: get, set/provide, A_k overwrite

**Sources.** Def. 23 (p. 18): `get(k)` requires $k \in \mathrm{dom}(\sigma)$;
`set(k,v)` requires $k \notin \mathrm{dom}(\sigma)$, yields
$(\sigma[k \mapsto v],\ \lambda\sigma'. \sigma' \setminus k)$ — an effect
function, hence tracked and reverted. Def. 24: an operation
$a \in \mathcal A_k$ acts on the *existing* value at k, yielding value,
inverse, outcome. Per PB-1 (PAPER_REWRITE §9), Cordis `provide` realizes
Def. 23 set, and `setval`/`ctx.set` realizes a Def. 24 $\mathcal A_k$
operation; this deliverable adopts the corrected mapping.

These operations occur *inside* L-Iter/L-Raise windows (component steps)
and once as an orchestration input (`setval(n,k,v)`); their occurrences
compose with the host rule's alphabet, and are tabulated separately so D2
can cite them for the coeffect equations.

### 11.1 Alphabet Σ_{CO-Prov}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | P1 | set/provide, label fresh ($\rho(k) \notin \mathrm{dom}(\sigma)$) — lands, inverse = restriction | scalar |
| 2 | P2 | set/provide, label bound in another fiber's table — precondition violated, error | witness |
| 3 | P3 | A_k overwrite, own binding present — value replaced in place | scalar |
| 4 | P4 | A_k overwrite, no own binding — error | scalar |
| 5 | P5 | get, label bound (value returned) | scalar |
| 6 | P6 | get, label unbound (no value; surfaces through Alg. 6 as IA/UD) | scalar |

### 11.2 Finiteness

Three operations × binary precondition state = **6** letters; key and
value payloads normalized by CF2. ∎

### 11.3 Reachability and canonical scripts

| id | reachable? | script |
| --- | --- | --- |
| P1 | yes | = S-It-2 (§5.4): P provides k1 fresh. |
| P2 | yes (isolation layer; A4) | = S-Rai-3 (§8.4): joined realms collide. |
| P3 | yes | = S-It-6 (component setval) and the orchestration form: `insert(root, P:(∅,{k1},[provide(k1,v1)])); settle; setval(P, k1, v2); settle` — val(P,k1) event, report k1 = v2, and *no* dependent re-run (PB-2's fixity question is left where the calculus leaves it; the model treats overwrite as invisible to episodes — A3/PB-2). |
| P4 | yes | = S-Rai-4; orchestration form: `setval(P, k1, v1)` against a non-providing P — refused. |
| P5 | yes | = S-It-1 (read of a bound key). |
| P6 | yes | = S-It-5 / S-It-4 (unbound reads, classified by Alg. 6). |

Scripts: **2 new** (the two orchestration-setval forms in P3/P4), rest
shared. |reach| = 6.

---

## 12. Coeffect operations II — Def. 28/29: isolation

**Sources.** Def. 28 (p. 21): $\Sigma^{\mathrm{iso}} = (\rho, \sigma)$
with realm table $\rho : K \rightharpoonup R$, default $\rho(k) = k$.
Def. 29: get/set transported along ρ; `isolate(k,r)` derives a context
with $\rho[k \mapsto r]$, no precondition — an already-isolated key is
*reassigned*, not refused; the shared table is untouched, so there is no
inverse.

### 12.1 Alphabet Σ_{CO-Iso}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | S1 | RealmRel = default (k ∉ dom ρ; shared realm) | scalar |
| 2 | S2 | RealmRel = isolated-distinct (accessor's ρ(k) differs from would-be provider's) | witness |
| 3 | S3 | RealmRel = joined (two keys/contexts sharing one realm label) | witness |
| 4 | S4 | RealmRel = reassigned (isolate over an already-isolated key) | scalar |

### 12.2 Finiteness

|RealmRel| = **4**. Realm identifiers are names, normalized by CF2;
the joined/distinct classification is an equality pattern on the ≤ 2
labels a single resolution reads. ∎

### 12.3 Reachability and canonical scripts

| id | reachable? | justification / script |
| --- | --- | --- |
| S1 | yes | every script of §§1–10 (no isolate input). |
| S2 | yes | **S-Iso-1:** `P := (∅,{k1},[provide(k1,v1)])`, `C := ({k1},∅,[read(k1)])`; ρ = `insert(root, P); settle; isolate(k1, r1); insert(root, C); settle`. The Λ_orch isolate input derives the ambient context for *subsequent* inserts, so P resolves k1 at the shared realm and C at r1, where nothing provides: C stays pending — the same key satisfied at one realm, unsatisfied at the other. |
| S3 | yes | = S-Rai-3 (§8.4): k1, k2 joined at r1; also the positive form **S-Iso-2:** `isolate(k1, r1); isolate(k2, r1); insert(root, P:(∅,{k1},[provide(k1,v1)])); settle; insert(root, C:({k2},∅,[read(k2)])); settle` — C's declared k2 resolves to r1, provided by P under k1: C activates and reads v1 through the join. |
| S4 | yes | **S-Iso-3:** `isolate(k1, r1); isolate(k1, r2); insert(root, C:({k1},∅,[read(k1)])); settle` — the second isolate reassigns; C resolves at r2 (pending). Verdict: no refusal on the second isolate, and resolution follows r2 not r1. |

|reach| = 4. Scripts: **3 new** (S-Iso-1..3), plus sharing with S-Rai-3.

---

## 13. Coeffect operations III — Def. 31: interception

**Sources.** Def. 31 (p. 22): get evaluates
$\sigma(k)(d(k) \oplus_k \iota(k))$; `intercept(k,ν)` derives
$\iota[k \mapsto \iota(k) \oplus_k \nu]$; merge right-biased, so the
context-carried (and, among nested contexts, the *later/nearer*) entry
overrides. model.mjs `interceptMerged` agrees (nearest wins; mutant
`intercept-outer-wins` is the deviation).

### 13.1 Alphabet Σ_{CO-Int}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | N1 | MetaPat = ε (no metadata on either side) | scalar |
| 2 | N2 | MetaPat = context-only (ι(k) ≠ ε, d(k) = ε) | scalar |
| 3 | N3 | MetaPat = component⊕context (both present; right-bias: ι(k) wins on the overlapping field) | order pattern |
| 4 | N4 | MetaPat = context₁⊕context₂ (two nested intercepts; nearer wins) | order pattern (depth 2) |

Depth is capped at 2 as MASTER directs: associativity of ⊕_k makes every
deeper chain a ⊕ of a depth-2 pattern, so deeper patterns add no new
atomic decision (this is the CF3 lift's induction, not the suite's job —
same division of labor as PAPER_REWRITE §5.3's accumulator remark).

### 13.2 Finiteness

|MetaPat| = **4**. Metadata payloads are values, normalized by CF2; the
order pattern records only which side supplies each of the ≤ 2 fields the
one merged read inspects. ∎

### 13.3 Reachability and canonical scripts

All four reachable through the `intercept(k, ν)` input plus
component-declared metadata in cfg.

**S-Int-1** (N1): any read script of §5 (no intercept input).

**S-Int-2** (N2): `P := (∅,{k1},[provide(k1,v1)])`,
`C := ({k1},∅,[read(k1)])`;
ρ = `insert(root, P); settle; intercept(k1, m1); insert(root, C);
settle`. C's read resolves through metadata m1; the observation is the
metadata-dependent read value/certificate.

**S-Int-3** (N3): as S-Int-2 with C declaring metadata for k1 in its cfg:
ρ = `insert(root, P); settle; intercept(k1, m1);
insert(root, C, cfg={k1: m2}); settle`. Verdict: the overlapping field
carries m1 (context over component, right-bias); the disjoint fields
merge.

**S-Int-4** (N4): ρ = `insert(root, P); settle; intercept(k1, m1);
intercept(k1, m2); insert(root, C); settle`. Verdict: the overlapping
field carries m2 (nearer/later wins — kills `intercept-outer-wins`).

|reach| = 4. Scripts: **3 new** (S-Int-2..4).

---

## 14. Algorithm 6 — proxy-mediated access

**Source (p. 61).** Walk the fiber chain upward from the accessing
context: (line 4) first fiber whose *committed view* binds the key →
return the binding; (line 5) a fiber that declares the key uncommitted →
INACTIVE_ACCESS; (line 6) root without declaration → UNDECLARED_ACCESS.
The three outcomes carry an ancestry-position class per MASTER. The
model refines the walk in two ways beyond the pseudocode: it stops at an
isolation boundary (child and parent resolve k at different realms →
UD), and it distinguishes a committed-but-withdrawn binding (provider's
table lacks the label → IA). Both refinements are logged (A8, A5).

### 14.1 Alphabet Σ_{CO-Acc}

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | A1 | outcome hit, PosClass = self ($\omega_n$ binds k) | scalar |
| 2 | A2 | outcome hit, PosClass = ancestor | scalar |
| 3 | A3 | outcome IA, PosClass = ancestor (ancestor declares k, committed view absent) | scalar |
| 4 | A4 | outcome IA, PosClass = self (own declared key uncommitted) | scalar |
| 5 | A5 | outcome UD, PosClass = root-boundary | scalar |
| 6 | A6 | outcome UD, PosClass = isolation-boundary (realm mismatch stops the walk — model/§5 refinement, A8) | scalar |
| 7 | A7 | outcome IA, withdrawn binding (committed hit, provider table lacks the label — model refinement, A5) | scalar |

### 14.2 Finiteness

3 outcomes × ≤ 3 position classes, of which 7 combinations are
well-formed = **7** letters. Chain length is invisible: the occurrence
records the class of the *deciding* fiber only. ∎

### 14.3 Reachability

| id | reachable? | justification |
| --- | --- | --- |
| A1 | yes | any consumer reading its declared key (= S-It-1). |
| A2 | yes | registered child reading the parent's committed key (= S-It-3). |
| A3 | yes | = S-It-4: orchestrator-inserted child under a pending declaring parent. |
| A4 | **interface-unrealizable** | while a fiber runs (forward or in recovery) its own committed view is total on $d_n$ and is discarded only as L-Unload's last act (Table 1: ω survives until Inactive); a fiber never executes a step while Inactive. So no self-window with a declared-uncommitted key exists. This is exactly the visibility half of §4.3.1's ordering promise. |
| A5 | yes | undeclared read at root (= S-It-5). |
| A6 | yes | **S-Acc-1:** `P := (∅,{k1},[provide(k1,v1)])`, `G := ({k1},∅,[])`, `C := (∅,∅,[read(k1)])`; ρ = `insert(root, P); insert(root, G); settle; isolate(k1, r1); insert(G, C); settle`. The boundary must fall *between* C and its parent, so C is orchestrator-inserted under G after the isolate: C resolves k1 at r1 while G resolves it at the shared realm. The walk from C stops at the realm mismatch → UD, although G’s committed view binds k1 and would otherwise have authorized it (contrast S-It-3’s T6). Verdict: rderr(C,k1,UD), and C still activates (per the A6 landing convention). |
| A7 | **spec-unreachable** | a committed edge $\omega_m(k) = n$ keeps $\mathrm{relied}_n$ true, so L-Unload — the only rule that withdraws provisions via provide⁻¹ — is blocked until the edge is gone (Thm. 63); hence a committed binding is never withdrawn while readable. The model's branch exists to catch mutants (`unload-without-guard`, `unload-clears-view-early`); in $\mathbb S$ the occurrence is unreachable and is discarded from $T^\star$ with a note that its *unreachability* is itself Theorem 63's testable content (S-Unl-2/S-Unl-6 witness the guard). |

5 of 7 reachable. Scripts: **1 new** (S-Acc-1), rest shared.

---

## 15. Summary counts

| rule / operation | \|Σ_r\| | \|Σ_r^reach\| | unrealizable (ids) | canonical scripts |
| --- | --- | --- | --- | --- |
| O-Insert | 7 | 6 | I5 (freshness, system-controlled) | 4 |
| O-Retire | 4 | 4 | — | 4 |
| O-Remove | 7 | 7 | — | 5 |
| L-Begin | 7 | 7 | — | 6 |
| L-Iter | 11 | 11 | — | 8 |
| L-Finish | 3 | 3 | — | 3 |
| L-Divert | 6 | 4 | D2 (A10), D6 (A9) | 2 |
| L-Raise | 9 | 9 | — (X4 via isolation layer, A4) | 7 |
| L-Leave | 5 | 4 | V2 (A10) | 3 |
| L-Unload | 12 | 12 | — (U8 via A7 grammar extension) | 9 |
| CO-Prov (Def. 23/24) | 6 | 6 | — | 2 new (4 shared) |
| CO-Iso (Def. 28/29) | 4 | 4 | — | 3 |
| CO-Int (Def. 31) | 4 | 4 | — | 3 |
| CO-Acc (Alg. 6) | 7 | 5 | A4 (self-IA), A7 (withdrawn) | 1 new (4 shared) |
| **total** | **92** | **86** | **6** | **60** |

Interface consumed by D2/D4: the numbered occurrence tables of
§§1.1–14.1 (rule, occurrence id, atoms, kind), the reachability columns
of §§1.3–14.3, and the script ids S-⋆. Cross-check target for D3: the
per-rule reachable occurrence sets above; in particular D3's explorer
should *confirm the negative claims* (I5, D2, D6, V2, A4, A7 never occur
in any normalized reachable window at bound $B_0$) as well as the
positive ones.

---

## 16. Deviations from MASTER's drafts

Each entry: what changed, and why Table 1 (or the cited definition)
demands it.

1. **Dev-1 (O-Insert).** MASTER's single atom "parent-live?" split into
   ParentClass = {root, present, absent}: the premise is
   $\pi \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$, a
   three-way pattern whose root and present cases produce different
   equality patterns (occurrence clause 3) and whose absent case is a
   reachable refusal MASTER's draft had no letter for. Also clarified
   that the conflict fold's domain is *all registered fibers* (Table 1
   premise $\forall m \in \mathrm{dom}(F_\gamma)$), not merely live
   or Active ones.
2. **Dev-2 (O-Retire).** Added R4: the premise
   $n \in \mathrm{dom}(F_\gamma)$ has a reachable violation (retire
   after removal) that refuses; MASTER's draft called the alphabet
   "trivial (unconditional)" — unconditional on *state*, but not
   premise-free.
3. **Dev-3 (O-Remove).** MASTER's "state = Inactive?" split into
   Inactive(⊥) / Inactive(ξ) / not-Inactive: the premise's pattern
   $\mathsf{Inactive}(-)$ selects a constructor (occurrence clause 2)
   and the harness report distinguishes disposal of clean vs. failed
   fibers, so the verdicts differ.
4. **Dev-4 (L-Begin).** No structural change from the draft; the
   "installed" state classes deliberately contribute no letter (no
   L-Begin window exists there), stated explicitly in §4.1.
5. **Dev-5 (step-class repartition).** MASTER pooled one step-class list
   under L-Iter/L-Finish/L-Divert. Table 1's premise constructors force
   the partition: Right + Just classes to L-Iter (provide-fresh, track,
   4 read classes, setval-own, register, raiseUnless-set — the last
   *added*, missing from the draft); Nothing to L-Finish (with the
   p. 36 degenerate empty-script case added as its own letter);
   Left-producing classes (raise, raiseUnless-unset, provide-conflict,
   setval-foreign) to L-Raise. L-Divert carries no step class at all in
   its abort alternative ($h = \mathrm{id}$).
6. **Dev-6 (view-relation decomposition).** MASTER's "view relation ∈
   {target = ω, target ≠ ω, target = ⊥}" refined into ViewRel with
   per-key witnesses, and the "target ≠ ω with a *new* provider" class
   (key-changed-provider) proved **interface-unrealizable at both
   L-Divert and L-Leave** (A10): the reliance guard plus O-Insert's
   declared disjointness prevent a provider replacement while any
   consumer still holds the old committed edge. The realizable
   divergences are exactly the two ⊥ forms and (extension) orch-update.
7. **Dev-7 (L-Leave).** Added V5 (orch-update divergence): the
   `update(n,cfg)` input of Λ_orch has no Table-1 rule; realized (as in
   model.mjs) as a forced target divergence. Flagged as extension, A3.
8. **Dev-8 (L-Raise).** The draft's "accumulator nonemptiness per
   inverse class" made into explicit letters X6–X9, and the raising step
   classes (absent from the draft's L-Raise line) added per Dev-5.
9. **Dev-9 (L-Unload).** Draft's "post-target ∈ {⊥, satisfiable}" and
   "τ" folded into three well-formed bookkeeping blocks U10–U12 (τ=⊤;
   τ=⊥ ∧ post-⊥; τ=⊥ ∧ satisfiable — the τ=⊤ ∧ satisfiable combination
   is ill-formed since τ=⊤ forces target ⊥). read-on-revert retained
   but flagged: not expressible in PAPER_REWRITE §2.2's step grammar
   (A7).
10. **Dev-10 (coeffect layer).** Adopted PB-1's corrected mapping
    (provide = Def. 23 set; setval = Def. 24 $\mathcal A_k$) and added
    the $\mathcal A_k$-no-binding error letter (P4) the draft lacked.
    Algorithm 6's alphabet extended beyond the draft's "three outcomes
    with ancestry-position class" by the two model refinements:
    isolation-boundary UD (A6/A8, reachable) and withdrawn-binding IA
    (A7 letter, spec-unreachable by Thm. 63). Intercept depth-2 cap kept
    with the associativity justification the draft implied (§13.1).

## 17. Calculus ambiguities found (recorded, not silently resolved)

- **A1 — O-Remove's agent.** The rule is orchestration-prefixed
  ($\gamma \Rightarrow \delta$) yet $\Lambda_{\mathrm{orch}}$ offers no
  remove input. Adopted reading (matching model.mjs and §5.2's loader):
  removal fires during settle when enabled. If the coordinating session
  prefers removal as an explicit input, §3's scripts gain one
  `remove(n)` action each; the alphabet is unchanged.
- **A2 — L-Divert / L-Raise overlap.** L-Raise carries no view premise
  (p. 38), so at target ≠ ω with a raising next iteration both rules are
  enabled; the calculus commits to no order. model.mjs deterministically
  prefers L-Divert. Exhaustive exploration (CF6/D3) must offer both
  branches; verdicts for windows in the overlap must accept both
  outcome sets.
- **A3 — `update` has no rule.** Λ_orch's update(n,cfg) (and the loader
  behavior of §5.2) is not among Table 1's ten rules. Realized as a
  forced divergence (model.mjs `stale`). Interacts with PB-2
  (active-overwrite underspecification): this deliverable treats an
  in-place A_k overwrite (P3) as episode-invisible and an entry update
  (V5) as a full bounce, which is the model's choice, not the paper's
  theorem.
- **A4 — label-level disjointness gap.** O-Insert's premise is key-level
  ($p \cap p_m = \varnothing$); with Def. 28 realms, joined keys collide
  at the same storage label without violating it, making the Def. 23 set
  precondition fail dynamically (X4, S-Rai-3). The base calculus
  ("we do not introduce realms here", p. 28) never faces this; the
  combined system as implemented does. The calculus needs either a
  label-level insertion premise or an explicit statement that dynamic
  conflict is an ordinary raise — this deliverable adopts the latter
  (the model's behavior).
- **A5 — withdrawn committed binding.** Algorithm 6 line 4 returns
  `fiber.committed[key]` assuming the provider still holds the value;
  the model returns IA when the table lacks it. Unreachable in the
  specification (the reliance guard is exactly what prevents it —
  Thm. 63), so the choice is invisible to conforming implementations,
  but the algorithm as printed does not say so.
- **A6 — read-failure convention.** Algorithm 6 *throws* on IA/UD;
  PAPER_REWRITE §2.3 makes rderr(n,k,ε) an ordinary event and §2.2's
  read step lands. Adopted: a failing read is an observed event and the
  iteration continues (Right), matching the harness; a strict/raising
  read would move T7/T8 into L-Raise's alphabet.
- **A7 — inverse reads are inexpressible in the test grammar.** Def. 48
  clause 2 licenses an inverse to read $\sigma_m|_{d_n}$, and Thm. 63's
  content is precisely a committed read during teardown — but §2.2's
  step constructors provide no inverse that reads. model.mjs adds
  `trackReadOnRevert`. Either PAPER_REWRITE §2.2 gains that constructor
  (recommended; S-Unl-6 depends on it) or U8's script is demoted to the
  model-extended language with a note in Lemma 4's table.
- **A8 — isolation boundary in Algorithm 6.** The pseudocode stops only
  at root; the model also stops where child and parent resolve the key
  at different realms (A6 letter, reachable via S-Acc-1). The §5 prose
  supports the model ("an ancestor resolving the key in a different
  realm cannot authorize the access" appears only in the implementation
  comment, not the algorithm). The algorithm should be emended.
- **A9 — L-Divert's landing alternative needs asynchrony.** §4.3.3's
  inertia is the only source of a target change between an iteration's
  launch and landing; the synchronous script semantics has no such gap.
  D6 is calculus-real, interface-unrealizable — the cleanest example of
  why $\Sigma_r^{\mathrm{reach}} \subsetneq \Sigma_r$ matters.
- **A10 — changed-provider divergence is unrealizable.** Proof sketch
  (from §7.4/§9.3): while any installed consumer holds ω(k)=m, (i)
  relied_m blocks m's L-Unload, so m stays registered and its removal is
  impossible; (ii) O-Insert's declared disjointness then refuses any
  new declarer of k. Hence provider_k can only become ⊥, never m′ ≠ m,
  under a live committed edge. Isolation does not escape this: a live
  fiber's resolution context is fixed at insertion. So every reachable
  divergence at L-Divert/L-Leave is a ⊥-divergence or an orch-update.
  This sharpens Table 1's reading and should be stated as a lemma in D2
  (it is a consequence, not an assumption).

---

*End of D1. Scratch material: none retained (no `scratch-d1/` needed).*
