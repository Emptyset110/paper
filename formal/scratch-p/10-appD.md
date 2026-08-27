## Appendix D. Signature Tables, Finiteness, and Reachability

This appendix enumerates, for each rule of Table 1 and each coeffect operation, the occurrence alphabet $\Sigma_r$ with its atoms, a finiteness proof, and the reachability analysis $\Sigma_r^{\mathrm{reach}} \subseteq \Sigma_r$, together with a compact index of the canonical scripts $\rho_{r,s}$. The full scripts with step-by-step derivation sketches are in the artifact (`formal/signatures.md`; Appendix A); the reachability column's positive claims are witnessed by those scripts, and both the positive and the six negative claims are targets for independent confirmation by the bounded state-space computations of Appendix E and the explorer of §7. Authority order in case of doubt: [SZC26] Table 1 and the rule statements of §4.2–§4.3 > the reference semantics (`proof/src/model.mjs`).

### D.0 Conventions

**Occurrences vs. signatures.** The window of a rule attempt is normalized by $\kappa_r : W_r \to \mathcal M_{\mathrm{fin}}(\Sigma_r)$ (Definition 6) into a finite multiset of occurrences. The suite $T^\star$ indexes canonical experiments by *atomic occurrence* $s \in \Sigma_r^{\mathrm{reach}}$, not by whole-window multiset; a single script may realize several occurrences at once (§5.4). "Reachable" below means: some window of some run from the empty registry, driven entirely through the orchestration interface $\Lambda_{\mathrm{orch}} \cup \{\mathsf{settle}\}$, contains that occurrence — obligation **(D-B)**.

**Cardinality freedom.** No occurrence mentions a count, a collection length, or a whole map. Unbounded structure enters only as per-key occurrences (target/satisfaction, view equality, conflict) and per-witness occurrences (reliance edges, children, accumulator items).

**Atom domains.** Every atom below ranges over one of the fixed finite domains:

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

Each is finite by inspection (3, 2, 5, 2, 2, 3, 5, 15, 5, 4, 4, 4 elements respectively); every finiteness proof below is a product count over these domains, so it is written once here and instantiated per rule.

**Canonical component vocabulary.** Reserved names `P, Q, C, G, X` (with subscripts), keys `k1, k2`, values `v1, v2`, tags `a, b, c`, error `x`, realms `r1, r2`, metadata `m1, m2`, flag `f`. A component is written `Name := (d, p, S)` with `d` the declared dependencies, `p` the declared provisions, `S` the step list in Definition 2's syntax; orchestration scripts use `insert(π, c, cfg) / retire(n) / update(n, cfg) / setval(n, k, v) / isolate(k, r) / intercept(k, ν) / settle`.

**Verdict background.** Every $\rho$ below is implicitly paired with the verdict of §5.4 (equality, up to $\equiv$, with the complete specification outcome set over all fair schedules, obligation (D-E)); where an occurrence is schedule-dependent this is said explicitly, and the exhaustive explorer collects all interleavings.

### D.1 O-Insert

Premises (Table 1): (i) $n \notin \mathrm{dom}(F_\gamma)$; (ii) $\pi \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$; (iii) $(d,p,e) \in \mathfrak C_\Gamma$; (iv) $\forall m \in \mathrm{dom}(F_\gamma).\ p \cap p_m = \varnothing$. Premise (iv) ranges over *every registered* fiber — retired, failed, or mid-teardown fibers still block the keys they declare; only O-Remove frees them. Premise (iii) is a static datum of the component language, not a runtime guard atom; it contributes no occurrence.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | I1 | ParentClass = root | scalar guard |
| 2 | I2 | ParentClass = present ($\pi \in \mathrm{dom}(F_\gamma)$) | scalar guard |
| 3 | I3 | ParentClass = absent ($\pi \neq \mathsf{root}$, $\pi \notin \mathrm{dom}(F_\gamma)$) | scalar guard, refusing |
| 4 | I4 | Fresh = fresh ($n \notin \mathrm{dom}(F_\gamma)$) | scalar guard |
| 5 | I5 | Fresh = stale ($n \in \mathrm{dom}(F_\gamma)$) | scalar guard, refusing |
| 6 | I6 | per-key: $k \in p$, no registered $m$ with $k \in p_m$ | per-key witness, clear |
| 7 | I7 | per-key: $k \in p$, ∃ registered $m$ with $k \in p_m$ | per-key witness, refusing |

$\kappa_{\text{O-Insert}}$ of a window is: one ParentClass occurrence, one Fresh occurrence, and one of I6/I7 per declared provision key of the inserted component (zero occurrences of that kind when $p = \varnothing$).

*Finiteness.* $|\Sigma_{\text{O-Insert}}| = |\text{ParentClass}| + |\text{Fresh}| + 2 = 3 + 2 + 2 = 7$. The per-key kinds contribute exactly two alphabet letters (witness-present, witness-absent) regardless of how many keys a component declares or how many fibers are registered: the key name is normalized away (CF2) and the existential over $m$ is folded to its witness bit. ∎

*Reachability.* I1, I2, I4, I6, I7: yes (first insert; child insert; every accepted insert; providing insert; two declarers of one key — the second refused, no settle needed, since the check is against *declared* provisions, active or not). I3: yes (retire + settle removes the parent; a subsequent insert naming it is refused). I5: **interface-unrealizable** — names are system-drawn: neither $\Lambda_{\mathrm{orch}}$'s insert nor Def. 47 registration lets the caller choose $n$; Def. 47 "draws a name not already in use". No experiment can present a stale name, so I5 is discarded from $T^\star$.

*Scripts (4).* **S-Ins-1** (I1, I4, I6): `P := (∅, {k1}, [provide(k1,v1)])`; ρ = `insert(root, P); settle`. **S-Ins-2** (I2): `P := (∅,∅,[])`, `C := (∅,∅,[])`; ρ = `insert(root, P); settle; insert(P, C); settle`. **S-Ins-3** (I3): as S-Ins-2 with ρ = `insert(root, P); retire(P); settle; insert(P, C)` — refused. **S-Ins-4** (I7): `P := (∅, {k1}, [provide(k1,v1)])`, `Q := (∅, {k1}, [])`; ρ = `insert(root, P); insert(root, Q)` — Q refused.

### D.2 O-Retire

Premise: $n \in \mathrm{dom}(F_\gamma)$; write $\tau_n \mapsto \top$. The rule reads no field of the fiber other than registry membership; the state class recorded below is write-aspect bookkeeping only. Prior $\tau_n$ is not read and the write is idempotent, so a second retire of a still-registered fiber falls into whichever state-class occurrence its $\theta$ selects; no separate "already retired" letter is needed.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | R1 | $n$ present, StateClass = Inactive(⊥) ("pending") | scalar |
| 2 | R2 | $n$ present, StateClass ∈ {Reloading, Active, Unloading} ("installed", eq. 44) | scalar |
| 3 | R3 | $n$ present, StateClass = Inactive(ξ) ("failed") | scalar |
| 4 | R4 | $n \notin \mathrm{dom}(F_\gamma)$ | scalar, refusing |

*Finiteness.* The single guard atom (membership) has 2 values; the bookkeeping class partitions StateClass (5 values) into 3 blocks on the positive side. $|\Sigma_{\text{O-Retire}}| = 3 + 1 = 4$. ∎

*Reachability.* All 4: R1 a consumer with an unsatisfied dependency quiesces Inactive(⊥); R2 retire an Active fiber (the Reloading/Unloading sub-cases arise mid-settle and the row reads none of them); R3 a raising component quiesces at Inactive(ξ); R4 retire a name already removed.

*Scripts (4).* **S-Ret-1** (R1): `C := ({k1}, ∅, [read(k1)])`; ρ = `insert(root, C); settle; retire(C); settle`. **S-Ret-2** (R2): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle; retire(P); settle`. **S-Ret-3** (R3): `P := (∅, ∅, [raise(x)])`; same ρ shape. **S-Ret-4** (R4): `P := (∅, ∅, [])`; ρ = `insert(root, P); retire(P); settle; retire(P)` — refused.

### D.3 O-Remove

Premises: $\tau_n = \top$; $\theta_n = \mathsf{Inactive}(-)$; $\forall m.\ \pi_m \neq n$. Write: $\gamma \smallsetminus n$.

**Interface note (ambiguity A1).** O-Remove is orchestration-prefixed ($\gamma \Rightarrow \delta$) yet $\Lambda_{\mathrm{orch}}$ has no `remove` input. We adopt the reference semantics' reading: removal fires during settle whenever its premises hold, as the §5.2 loader does. Blocked occurrences are therefore observed not as refusals but as the fiber's persistence in the quiescent report or as `disabled` certificates mid-settle. Logged in D.16.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | M1 | RetClass = τ=⊤ | scalar guard |
| 2 | M2 | RetClass = τ=⊥ | scalar guard, blocking |
| 3 | M3 | StateClass = Inactive(⊥) | scalar guard |
| 4 | M4 | StateClass = Inactive(ξ) | scalar guard |
| 5 | M5 | StateClass ∈ {Reloading, Active, Unloading} | scalar guard, blocking |
| 6 | M6 | per-witness: no $m$ with $\pi_m = n$ | witness, clear |
| 7 | M7 | per-witness: ∃ $m$ with $\pi_m = n$ present | witness, blocking |

The premise's pattern $\mathsf{Inactive}(-)$ does not read $\zeta$; M3/M4 are distinguished because the constructor is selected (Definition 6, item 2) and the quiescent report distinguishes disposal of a clean vs. failed fiber.

*Finiteness.* RetClass (2) + the 3-block StateClass partition + witness bit (2) gives $2 + 3 + 2 = 7$; the child fold contributes one witness bit regardless of the number of children. ∎

*Reachability.* All 7: M1 every completed retire-then-settle disposal; M2 any unretired quiescent fiber (witnessed by its presence in the report); M3/M4 disposal of a clean/failed fiber; M5 mid-settle window (a retired fiber still Active/Unloading is not removable until L-Leave/L-Unload finish; witnessed by the certificate order deact(P) < removal); M6 every leaf disposal; M7 a parent whose registered child is still present stays registered until the child is removed ("removing children before their parent", [SZC26] p. 31).

*Scripts (5).* **S-Rem-1** (M1, M3, M6): `C := ({k1}, ∅, [])`; ρ = `insert(root, C); retire(C); settle`. **S-Rem-2** (M2): `P := (∅, ∅, [])`; ρ = `insert(root, P); settle` — P persists unretired. **S-Rem-3** (M4): `P := (∅, ∅, [raise(x)])`; ρ = `insert(root, P); settle; retire(P); settle`. **S-Rem-4** (M5): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle; retire(P); settle` — mid-settle window; observation is the certificate/event order inv(P,a) ≤ deact(P) < removal, not the final report. **S-Rem-5** (M7): `G := (∅, ∅, [register(C), track(a)])`, `C := (∅, ∅, [track(b)])`; ρ = `insert(root, G); settle; retire(G); settle` — G's removal is blocked by witness C between G reaching Inactive and C's own removal; certificate order shows C's removal before G's.

### D.4 L-Begin

Premises: $\theta_n = \mathsf{Inactive}(\bot)$; $\omega = \mathrm{target}_n(\gamma) \neq \bot$, which unfolds (Def. 46) to $\tau_n = \bot \wedge \gamma \vDash d_n$, and $\gamma \vDash d_n$ decomposes pointwise: each $k \in d_n$ needs $k \in \mathrm{dom}(\sigma_\gamma)$, with $\sigma_\gamma$ the union over **Active** fibers only (eq. 40) — a key held in the table of a Reloading/Unloading/failed fiber does not satisfy.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | B1 | StateClass = Inactive(⊥) | scalar guard |
| 2 | B2 | StateClass = Inactive(ξ) | scalar guard, blocking (no lifecycle re-entry from an error outcome) |
| 3 | B3 | RetClass = τ=⊥ | scalar guard |
| 4 | B4 | RetClass = τ=⊤ (forces target ⊥) | scalar guard, blocking |
| 5 | B5 | per-key: KeySat = Active-provided | per-key |
| 6 | B6 | per-key: KeySat = installed-only-provided (some installed non-Active fiber's table holds $k$; $\sigma_\gamma$ excludes it) | per-key, blocking |
| 7 | B7 | per-key: KeySat = unprovided (no table holds $k$) | per-key, blocking |

$\kappa$ yields one state occurrence, one retirement occurrence, and one KeySat occurrence per declared key ($d_n = \varnothing$ contributes zero key occurrences). The installed-but-not-Inactive state classes contribute no letter: no L-Begin window exists there (the pattern match fails before any guard is evaluated), and every such state is some other rule's window.

*Finiteness.* 2 (state letters retained) + 2 (RetClass) + 3 (KeySat) = **7**. The per-key decomposition contributes |KeySat| letters independent of $|d_n|$. ∎

*Reachability.* All 7: B1 first settle after inserting a satisfiable component; B2 a raising component quiesces at Inactive(ξ) with a non-⊥ target — the begin attempt is disabled exactly by B2, quiet by eq. 45's first clause ($\zeta \neq \bot$); B3 co-occurs with every firing L-Begin; B4 insert then retire before settle (disposed without ever emitting act); B5 consumer beginning against an Active provider; B6 the mid-teardown window — a provider in Unloading still holds its table (only L-Unload's accumulator withdraws it) while a pending consumer's begin attempt is evaluated (S-Beg-5); B7 consumer with no provider at all.

*Scripts (6).* **S-Beg-1** (B1, B3): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle`. **S-Beg-2** (B2): `P := (∅, {k1}, [provide(k1,v1), raise(x)])`; ρ = `insert(root, P); settle` — report: P failed, k1 absent; re-entry would be visible as a second app/act. **S-Beg-3** (B4): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); retire(P); settle` — no act(P), no app(P,a). **S-Beg-4** (B5): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [read(k1)])`; ρ = `insert(root, P); settle; insert(root, C); settle`. **S-Beg-5** (B6): `P := (∅, {k1}, [provide(k1,v1), track(a)])`, `C1 := ({k1}, ∅, [read(k1)])`, `C2 := ({k1}, ∅, [read(k1)])`; ρ = `insert(root, P); insert(root, C1); settle; retire(P); insert(root, C2); settle` — during the second settle P L-Leaves (Unloading, table still held; the reliance guard holds P there while C1 tears down), and in that window C2's begin attempt reads k1: some installed non-Active fiber holds it but $\sigma_\gamma$ excludes it — occurrence B6, disabled; after C1 and P unload, C2's window becomes B7. B6 is witnessed by the disabled certificate during the guarded window (distinguishing it from B7 and from the deviants `leave-keeps-providing` / `satisfied-by-installed-provider`, Appendix F). **S-Beg-6** (B7): `C := ({k1}, ∅, [read(k1)])`; ρ = `insert(root, C); settle` — C pending.

### D.5 L-Iter

Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$; $\mathrm{target}_n(\gamma) = \omega$; $i(\gamma) = \mathsf{Right}(\delta, h, \mathsf{Just}(i'))$. The view premise decomposes per key; the iterator premise's constructor is the step class: exactly the step constructors that land (Right) with a continuation. Steps that raise (Left) belong to L-Raise's alphabet and iterator exhaustion (Nothing) to L-Finish's.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | T1 | StateClass = Reloading, view relation holds (scalar part: ¬τ, satisfied) | scalar |
| 2 | T2 | per-key: ViewRel = key-equal ($\omega(k) = \mathrm{provider}_k(\gamma)$) | per-key |
| 3 | T3 | StepClass = provide-fresh (label unbound; Def. 23 set precondition holds) | step |
| 4 | T4 | StepClass = track | step |
| 5 | T5 | StepClass = read-committed (Alg. 6 hit at self) | step |
| 6 | T6 | StepClass = read-ancestor-committed (Alg. 6 hit at an ancestor) | step |
| 7 | T7 | StepClass = read-declared-uncommitted (Alg. 6 IA; observed as rderr(n,k,IA), lands — ambiguity A6) | step |
| 8 | T8 | StepClass = read-undeclared (Alg. 6 UD; rderr(n,k,UD), lands — A6) | step |
| 9 | T9 | StepClass = setval-own ($\mathcal A_k$ overwrite of an own binding, Def. 24 — the PB-1 mapping) | step |
| 10 | T10 | StepClass = register (Def. 47: O-Insert under π = n, O-Retire as inverse) | step |
| 11 | T11 | StepClass = raiseUnless-set (flag present in cfg; lands) | step |

*Finiteness.* 1 scalar letter + 1 per-key letter + 9 step letters = **11**. The step letters are a subset of the finite StepClass domain (15 constructors); only key-equal appears in an enabled L-Iter window. Payloads are normalized away by CF2; the equality pattern each occurrence records is on the ≤ 3 names/values that single atomic decision reads, hence finite. ∎

*Reachability.* All 11. T1/T2 every iterating consumer; T3 any providing activation; T4 any tracker; T5 consumer reads its own committed key; T6 a registered child reads a key its ancestor declared and committed, without declaring it itself; T7 reachable only through an orchestrator-inserted child under a *pending* declaring parent — the child re-iterates while the parent declares k1 but holds no committed view; three fibers and two extra settles are required (S-It-4, the subtlest reachability fact in the tables); T8 a read no chain member declares; T9 provider overwrites its own provided value mid-activation; T10 any registering component; T11 raiseUnless with the flag set.

*Scripts (8).* **S-It-1** (T1, T2, T4, T5): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [track(a), read(k1)])`; ρ = `insert(root, P); settle; insert(root, C); settle`. **S-It-2** (T3): P as above; ρ = `insert(root, P); settle`. **S-It-3** (T6): `P := (∅, {k1}, [provide(k1,v1)])`, `G := ({k1}, ∅, [register(C)])`, `C := (∅, ∅, [read(k1)])`; ρ = `insert(root, P); settle; insert(root, G); settle` — C's read walks Alg. 6 to the ancestor hit. **S-It-4** (T7): `P := (∅, {k1}, [provide(k1,v1)])`, `Q := (∅, {k2}, [provide(k2,v2)])`, `Q2 := (∅, {k2}, [provide(k2,v2)])`, `G := ({k1}, ∅, [])`, `C := ({k2}, ∅, [read(k1)])`; ρ = `insert(root, P); insert(root, Q); settle; insert(root, G); settle; insert(G, C); settle; retire(P); retire(Q); settle; insert(root, Q2); settle` — after P and Q withdraw, G quiesces pending with no committed view; Q2 re-satisfies C, whose re-run read walks to G: committed absent but $k_1 \in d_G$ → rderr(C,k1,IA), occurrence T7; C still lands and finishes (A6). **S-It-5** (T8): `X := (∅, ∅, [read(k1)])`; ρ = `insert(root, X); settle`. **S-It-6** (T9): `P := (∅, {k1}, [provide(k1,v1), setval(k1,v2)])`; ρ = `insert(root, P); settle` — val(P,k1); report k1 = v2. **S-It-7** (T10): `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`; ρ = `insert(root, G); settle`. **S-It-8** (T11): `P := (∅, ∅, [raiseUnless(f,x)])`; ρ = `insert(root, P, cfg={f}); settle`.

### D.6 L-Finish

Premises: as L-Iter with $i(\gamma) = (\delta, h, \mathsf{Nothing})$.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | F1 | Reloading, view holds, iterator Nothing, after ≥ 1 landed iteration (accumulator ≠ id) | scalar |
| 2 | F2 | as F1 but the degenerate $\mathfrak E_\Gamma$ case: first iteration already yields Nothing, accumulator = id | scalar |
| 3 | F3 | per-key: ViewRel = key-equal at the finishing window | per-key |

*Finiteness.* 2 scalar letters + 1 per-key letter = **3**. The accumulator's content is not enumerated here (its items are L-Unload's per-item occurrences); only the id/non-id constructor distinction appears. ∎

*Reachability.* All 3 (any completing component with a nonempty step list; an empty step list; any finishing consumer).

*Scripts (3).* **S-Fin-1** (F1): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle`. **S-Fin-2** (F2): `P := (∅, ∅, [])`; ρ = `insert(root, P); settle` — act(P) with no app events. **S-Fin-3** (F3): the S-Beg-4 configuration; act(C) after rd(C,k1,v1).

### D.7 L-Divert

Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$; $\mathrm{target}_n(\gamma) \neq \omega$; $(\delta,h) = (\gamma, \mathrm{id}_\Gamma) \vee i(\gamma) = (\delta, h, -)$. The divergence premise decomposes: either $\mathrm{target} = \bot$ (via $\tau$ or unsatisfiability) or some key's provider differs from the committed one. The two alternatives (abort the held iteration / let it land) are the rule's own disjunction; §4.3.3 restricts a host under inertia to the landing alternative.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | D1 | StateClass = Reloading, divergence present | scalar |
| 2 | D2 | per-key: ViewRel = key-changed-provider ($\omega(k) = m$, $\mathrm{provider}_k(\gamma) = m' \neq m$) | per-key witness |
| 3 | D3 | ViewRel = target-⊥-retired ($\tau_n$ flipped mid-activation) | scalar |
| 4 | D4 | per-key: ViewRel = target-⊥-unsatisfied (a committed key's provider left $\sigma_\gamma$) | per-key witness |
| 5 | D5 | alternative = abort ($h = \mathrm{id}_\Gamma$) | scalar |
| 6 | D6 | alternative = land ($i(\gamma) = (\delta,h,-)$ with $h \neq \mathrm{id}$) | scalar |

*Finiteness.* $1 + 1 + 1 + 1 + 2 =$ **6**; the divergence classes are drawn from the finite ViewRel domain, one occurrence per witnessing key, and the alternative bit is binary. ∎

*Reachability.* D1, D3, D4, D5: yes (any mid-activation target change; the registration-inverse retire of a concurrently re-activating child, S-Div-3; provider withdrawal between iterations; the synchronous interface always aborts at an iteration boundary). D2: **interface-unrealizable** — the changed-provider argument, in full: suppose a window where consumer $C$ is Reloading with $\omega_C(k_1) = P$ and $\mathrm{provider}_{k_1}(\gamma) = P' \neq P$. Then (i) $C$ is installed with a committed edge to $P$, so $\mathrm{relied}_P(\gamma)$ holds and L-Unload is blocked at $P$: $P$ cannot reach Inactive, hence cannot be O-Removed, hence stays registered with $k_1 \in p_P$. (ii) While $P$ is registered, O-Insert refuses any component declaring $k_1$ — directly or through Def. 47 registration (same premise) — so no fiber $P'$ declaring $k_1$ can enter the registry. (iii) A registered non-declarer cannot provide $k_1$ either: Def. 43 confines an effect function's writes to its declared $p$, and under isolation a *joined* provider's provide would raise on the still-bound label (X4) rather than land. So no $P'$ exists: contradiction. The divergence a Reloading consumer can observe is therefore always target $= \bot$ (D3/D4), never a changed provider. (Ambiguity note A10; the same argument applies verbatim to L-Leave's V2, D.9.) D6: **interface-unrealizable** — landing the in-flight iteration requires the target to change *between an iteration's launch and its landing* (§4.3.3 inertia). In the script semantics every step is one atomic landing and orchestration inputs fall between settles, so no experiment separates launch from landing. The occurrence is real in the calculus; it is excluded from $T^\star$ with the same status as I5 (ambiguity A9 — the cleanest example of why $\Sigma_r^{\mathrm{reach}} \subsetneq \Sigma_r$ matters).

*Scripts (2).* **S-Div-1** (D1, D4, D5): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [track(a), track(b)])`; ρ = `insert(root, P); settle; insert(root, C); retire(P); settle` — at the second settle C's L-Begin and P's L-Leave are both enabled (a nondeterministic branch); on the branch that begins C first, C commits ω(k1)=P, iterates track(a), P leaves (guarded from unloading by C's committed edge), and C's next window has target $= \bot \neq \omega$: L-Divert aborts, C unloads (inv(C,a)), quiesces pending; the exhaustive explorer also visits the branch where P leaves first. **S-Div-3** (D3): `Q := (∅, {k2}, [provide(k2,v2)])`, `Q2 := (∅, {k2}, [provide(k2,v2)])`, `G := (∅, ∅, [register(C), track(a)])`, `C := ({k2}, ∅, [track(b), track(c)])`; ρ = `insert(root, Q); insert(root, G); settle; retire(Q); retire(G); insert(root, Q2); settle` — on the exhibited branch C re-begins against Q2 and is mid-Reloading when G's unload runs its register inverse, performing O-Retire(C) and flipping $\tau_C$: C's next window is {D1, D3, D5}. Every occurrence here is branch-dependent; the explorer collects all interleavings. (The script id S-Div-2 is withdrawn: it named the D2 experiment, replaced by the unreachability argument above.)

### D.8 L-Raise

Premises: $\theta_n = \mathsf{Reloading}(i,g,\omega)$; $i(\gamma) = \mathsf{Left}(\xi)$.

**No view premise (ambiguity A2).** L-Raise does not read the target, so at a window where target $\neq \omega$ *and* the next iteration raises, both L-Divert (abort) and L-Raise are enabled — genuine calculus nondeterminism that the reference semantics resolves deterministically in favor of L-Divert. Exhaustive exploration must offer both.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | X1 | StateClass = Reloading, iterator Left(ξ) | scalar |
| 2 | X2 | StepClass = raise | step |
| 3 | X3 | StepClass = raiseUnless-unset (flag absent from cfg) | step |
| 4 | X4 | StepClass = provide-conflict (Def. 23 set precondition fails: label already bound in another fiber's table) | step |
| 5 | X5 | StepClass = setval-foreign ($\mathcal A_k$ with no own binding at the label) | step |
| 6 | X6 | InvClass = (empty) — accumulator id at the raise | per-item |
| 7 | X7 | InvClass = provide⁻¹ present in $g$ | per-item witness |
| 8 | X8 | InvClass = track⁻¹ present in $g$ | per-item witness |
| 9 | X9 | InvClass = register⁻¹ present in $g$ | per-item witness |

*Finiteness.* 1 scalar + 4 step letters (the Left-producing subset of StepClass) + 1 empty marker + 3 inverse-class witnesses = **9**. Accumulator length is invisible: each accumulated item contributes one occurrence of its InvClass, and the alphabet holds one letter per class. ∎

*Reachability.* All 9. X1/X2/X6 a bare raising component; X3 raiseUnless with cfg omitting f; X4 **only through the isolation layer**: in the realm-free base calculus, O-Insert's declared disjointness plus Def. 43's confinement make live tables disjoint, so the set precondition can never fail — with Def. 28 realms, two keys isolated to one realm ("joined") collide at the same label while their *declared* key sets stay disjoint, slipping past O-Insert (ambiguity A4 — a genuine gap in the calculus's premise inventory); X5 setval on a never-provided key; X7/X8/X9 provide/track/register before raise.

*Scripts (7).* **S-Rai-1** (X1, X2, X6): `P := (∅, ∅, [raise(x)])`; ρ = `insert(root, P); settle`. **S-Rai-2** (X3): `P := (∅, ∅, [raiseUnless(f,x)])`; ρ = `insert(root, P, cfg={}); settle`. **S-Rai-3** (X4): `P := (∅, {k1}, [provide(k1,v1)])`, `Q := (∅, {k2}, [provide(k2,v2)])`; ρ = `isolate(k1, r1); isolate(k2, r1); insert(root, P); settle; insert(root, Q); settle` — Q's provide meets ρ(k2) = r1 ∈ dom(σ) → Left; Q failed, k1 still bound by P. **S-Rai-4** (X5): `P := (∅, ∅, [setval(k1,v2)])`; ρ = `insert(root, P); settle`. **S-Rai-5** (X7): `P := (∅, {k1}, [provide(k1,v1), raise(x)])`; ρ = `insert(root, P); settle` — the withdrawal of k1 distinguishes X7. **S-Rai-6** (X8): `P := (∅, ∅, [track(a), raise(x)])`; ρ = `insert(root, P); settle` — inv(P,a) before deact. **S-Rai-7** (X9): `G := (∅, ∅, [register(C), raise(x)])`, `C := (∅, ∅, [track(b)])`; ρ = `insert(root, G); settle` — recovery retires the child.

### D.9 L-Leave

Premises: $\theta_n = \mathsf{Active}(g,\omega)$; $\mathrm{target}_n(\gamma) \neq \omega$.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | V1 | StateClass = Active, divergence present | scalar |
| 2 | V2 | per-key: ViewRel = key-changed-provider | per-key witness |
| 3 | V3 | ViewRel = target-⊥-retired | scalar |
| 4 | V4 | per-key: ViewRel = target-⊥-unsatisfied | per-key witness |
| 5 | V5 | ViewRel = orch-update (`update(n,cfg)` forces re-resolution; loader extension, ambiguity A3) | scalar |

*Finiteness.* 1 + 4 ViewRel letters = **5**; per-key classes contribute one letter each independent of $|d_n|$. ∎

*Reachability.* V1, V3, V4, V5: yes. V2: **interface-unrealizable** — the D.7 changed-provider argument applies verbatim with $C$ Active instead of Reloading; nor does `update` help: an updated provider re-activates under the *same* name, so $\omega(k_1)$ still matches. Provider replacement is realizable only as ⊥-then-new-provider across two windows (V4 followed by a fresh L-Begin), never as a direct $m \to m'$ comparison.

*Scripts (3).* **S-Lea-1** (V1, V3): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle; retire(P); settle` — deact after inv. **S-Lea-2** (V4): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [read(k1), track(a)])`; ρ = `insert(root, P); settle; insert(root, C); settle; retire(P); settle` — C's inv(C,a) runs while P is still Unloading (reliance guard, D.10); C pending. **S-Lea-3** (V5): `P := (∅, ∅, [track(a)])`; ρ = `insert(root, P); settle; update(P, cfg2); settle` — a full bounce observable as inv(P,a) < app(P,a) with two act events; the calculus has no rule for `update` (A3).

### D.10 L-Unload

Premises: $\theta_n = \mathsf{Unloading}(g,\omega,\zeta)$; $\neg\mathrm{relied}_n(\gamma)$; $g(\gamma) = \delta$. Write: $\theta_n \mapsto \mathsf{Inactive}(\zeta)$; $\Psi = g$ (the only rule applying an accumulator). $\mathrm{relied}_n$ (Def. 50) is an existential fold over committed-view edges — one witness occurrence per edge class. The accumulator $g = g_1 \circ \cdots \circ g_j$ decomposes per item into InvClass occurrences, applied LIFO. $\tau$ and the post-state target are not read by the rule; they are write-aspect bookkeeping recorded because the canonical verdict observes the successor (removal / rest / bounce).

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
| 12 | U12 | bookkeeping: τ=⊥ ∧ post-target satisfiable (successor: immediate re-begin — deactivation chaining into activation, §4.3.3) | scalar |

*Finiteness.* $1 + 1 + 2 + 4 + 1 + 3 =$ **12**. Reliance witnesses: one letter regardless of how many dependents or edges exist. Accumulator items: one letter per InvClass (4) plus the empty marker; item count and item order are properties of the multiset and of the observation word, not extra letters. Bookkeeping: RetClass × post-target folded into 3 well-formed blocks (τ=⊤ forces target ⊥, so τ=⊤ ∧ satisfiable is ill-formed). ∎

*Reachability.* All 12 (U8 modulo the read-on-revert grammar extension, ambiguity A7). U1/U3/U9/U10 every clean retire-driven unload; U2 retire a provider under an installed consumer — the guard window is observable as the certificate order (consumer's inverses and committed reads precede provider's inverses — Thm. 63's content); U4 any failed activation's recovery; U5/U6/U7 retire a provider/tracker/registering host; U8 a consumer's teardown inverse reads its committed key (the committed-read-during-teardown that Thm. 63 promises); U11 consumer whose provider is gone rests pending; U12 unload whose successor window is already satisfiable (via `update`).

*Scripts (9).* **S-Unl-1** (U1, U3, U6, U10): `P := (∅, ∅, [track(a), track(b), track(c)])`; ρ = `insert(root, P); settle; retire(P); settle` — g applied LIFO: inv(P,c) < inv(P,b) < inv(P,a) < deact(P); the accumulator-order canonical test (obligation D-G's single-fiber forcing). **S-Unl-2** (U2): `P := (∅, {k1}, [provide(k1,v1), track(a)])`, `C := ({k1}, ∅, [read(k1), track(b)])`; ρ = `insert(root, P); settle; insert(root, C); settle; retire(P); settle` — P's unload window carries U2 (witness: C installed, ω_C(k1)=P): blocked; C leaves (V4), unloads (inv(C,b)); P's window flips to U1; verdict: inv(C,b) precedes inv(P,a) and the k1 withdrawal. **S-Unl-3** (U4): `P := (∅, ∅, [track(a), raise(x)])`; ρ = `insert(root, P); settle`. **S-Unl-4** (U5): `P := (∅, {k1}, [provide(k1,v1)])`; ρ = `insert(root, P); settle; retire(P); settle` — k1 absent in the report. **S-Unl-5** (U7): `G := (∅, ∅, [register(C)])`, `C := (∅, ∅, [track(b)])`; ρ = `insert(root, G); settle; retire(G); settle` — the register⁻¹ item retires C; the cascade reaches the child "one level at a time". **S-Unl-6** (U8; uses the grammar extension `trackReadOnRevert(k1, a)`, A7): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [read(k1), trackReadOnRevert(k1, a)])`; ρ = `insert(root, P); settle; insert(root, C); settle; retire(P); settle` — C's inverse *reads* k1 during C's L-Unload: P is still Unloading (guard held by C), its table intact, so the read succeeds with v1; observed as the read-on-revert event before P's withdrawal. **S-Unl-7** (U9): `P := (∅, ∅, [])`; ρ = `insert(root, P); settle; retire(P); settle`. **S-Unl-8** (U11): shared with S-Lea-2 — C rests pending, no re-begin certificate follows. **S-Unl-9** (U12): `P := (∅, {k1}, [provide(k1,v1)])`, `C := ({k1}, ∅, [track(a)])`; ρ = `insert(root, P); settle; insert(root, C); settle; update(C, cfg2); settle` — C leaves (V5), unloads with τ=⊥ and target still satisfiable — occurrence U12 — and immediately re-begins: deact(C) directly followed by app/act(C).

The guard-blocked signature U2's canonical experiment — retiring a provider under an installed consumer whose tracked inverse reads the provided key (S-Unl-2/S-Unl-6) — asserts the consumer's read event, its precedence over every provider inverse, and the final disposal: it is the experiment that convicts the published build (§8.2).

### D.11 Coeffect operations I — Def. 23/24: get, set/provide, $\mathcal A_k$ overwrite

Per PB-1 (§9), Cordis `provide` realizes Def. 23 set, and `setval`/`ctx.set` realizes a Def. 24 $\mathcal A_k$ operation; the tables adopt the corrected mapping. These operations occur *inside* L-Iter/L-Raise windows (component steps) and once as an orchestration input (`setval(n,k,v)`); their occurrences compose with the host rule's alphabet and are tabulated separately so the factorization (Appendix C.11) can cite them.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | P1 | set/provide, label fresh — lands, inverse = restriction | scalar |
| 2 | P2 | set/provide, label bound in another fiber's table — precondition violated, error | witness |
| 3 | P3 | $\mathcal A_k$ overwrite, own binding present — value replaced in place | scalar |
| 4 | P4 | $\mathcal A_k$ overwrite, no own binding — error | scalar |
| 5 | P5 | get, label bound (value returned) | scalar |
| 6 | P6 | get, label unbound (surfaces through Alg. 6 as IA/UD) | scalar |

*Finiteness.* Three operations × binary precondition state = **6**; key and value payloads normalized by CF2. ∎

*Reachability (all 6) and scripts (2 new).* P1 = S-It-2; P2 = S-Rai-3 (isolation layer, A4); P3 = S-It-6 and the orchestration form `insert(root, P:(∅,{k1},[provide(k1,v1)])); settle; setval(P, k1, v2); settle` — val(P,k1), report k1 = v2, and *no* dependent re-run (PB-2's fixity question is left where the calculus leaves it: the reference semantics treats overwrite as episode-invisible — A3/PB-2); P4 = S-Rai-4 and the orchestration form `setval(P, k1, v1)` against a non-providing P — refused; P5 = S-It-1; P6 = S-It-5 / S-It-4.

### D.12 Coeffect operations II — Def. 28/29: isolation

Def. 28: $\Sigma^{\mathrm{iso}} = (\rho, \sigma)$ with realm table $\rho : K \rightharpoonup R$, default $\rho(k) = k$. Def. 29: get/set transported along $\rho$; `isolate(k,r)` derives a context with $\rho[k \mapsto r]$, no precondition — an already-isolated key is *reassigned*, not refused; the shared table is untouched, so there is no inverse.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | S1 | RealmRel = default (k ∉ dom ρ; shared realm) | scalar |
| 2 | S2 | RealmRel = isolated-distinct (accessor's ρ(k) differs from would-be provider's) | witness |
| 3 | S3 | RealmRel = joined (two keys/contexts sharing one realm label) | witness |
| 4 | S4 | RealmRel = reassigned (isolate over an already-isolated key) | scalar |

*Finiteness.* $|\text{RealmRel}| =$ **4**. Realm identifiers are names, normalized by CF2; the joined/distinct classification is an equality pattern on the ≤ 2 labels a single resolution reads. ∎

*Reachability (all 4) and scripts (3 new).* S1: every script of D.1–D.10. S2: **S-Iso-1** — `P := (∅,{k1},[provide(k1,v1)])`, `C := ({k1},∅,[read(k1)])`; ρ = `insert(root, P); settle; isolate(k1, r1); insert(root, C); settle` — the isolate input derives the ambient context for *subsequent* inserts, so P resolves k1 at the shared realm and C at r1, where nothing provides: the same key satisfied at one realm, unsatisfied at the other. S3: = S-Rai-3, and the positive form **S-Iso-2** — `isolate(k1, r1); isolate(k2, r1); insert(root, P:(∅,{k1},[provide(k1,v1)])); settle; insert(root, C:({k2},∅,[read(k2)])); settle` — C activates and reads v1 through the join. S4: **S-Iso-3** — `isolate(k1, r1); isolate(k1, r2); insert(root, C:({k1},∅,[read(k1)])); settle` — no refusal on the second isolate, and resolution follows r2 not r1.

### D.13 Coeffect operations III — Def. 31: interception

Def. 31: get evaluates $\sigma(k)(d(k) \oplus_k \iota(k))$; `intercept(k,ν)` derives $\iota[k \mapsto \iota(k) \oplus_k \nu]$; merge right-biased, so the context-carried (and, among nested contexts, the *later/nearer*) entry overrides.

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | N1 | MetaPat = ε (no metadata on either side) | scalar |
| 2 | N2 | MetaPat = context-only | scalar |
| 3 | N3 | MetaPat = component⊕context (right-bias: ι(k) wins on the overlapping field) | order pattern |
| 4 | N4 | MetaPat = context₁⊕context₂ (two nested intercepts; nearer wins) | order pattern (depth 2) |

Depth is capped at 2: associativity of $\oplus_k$ makes every deeper chain a $\oplus$ of a depth-2 pattern, so deeper patterns add no new atomic decision — this is CF3's lift making the induction, not the suite's job (Remark 2's division of labor).

*Finiteness.* $|\text{MetaPat}| =$ **4**; metadata payloads are values, normalized by CF2; the order pattern records only which side supplies each of the ≤ 2 fields the one merged read inspects. ∎

*Reachability (all 4) and scripts (3 new).* **S-Int-1** (N1): any read script of D.5. **S-Int-2** (N2): `P := (∅,{k1},[provide(k1,v1)])`, `C := ({k1},∅,[read(k1)])`; ρ = `insert(root, P); settle; intercept(k1, m1); insert(root, C); settle`. **S-Int-3** (N3): as S-Int-2 with C declaring metadata for k1 in its cfg: `insert(root, C, cfg={k1: m2})` — the overlapping field carries m1 (context over component); disjoint fields merge. **S-Int-4** (N4): ρ = `insert(root, P); settle; intercept(k1, m1); intercept(k1, m2); insert(root, C); settle` — the overlapping field carries m2 (nearer/later wins; kills `intercept-outer-wins`, Appendix F).

### D.14 Algorithm 6 — proxy-mediated access

The walk (p. 61): upward from the accessing context; (line 4) first fiber whose *committed view* binds the key → return the binding; (line 5) a fiber that declares the key uncommitted → INACTIVE_ACCESS; (line 6) root without declaration → UNDECLARED_ACCESS. The reference semantics refines the walk in two logged ways beyond the pseudocode: it stops at an isolation boundary (child and parent resolve k at different realms → UD; ambiguity A8), and it distinguishes a committed-but-withdrawn binding (provider's table lacks the label → IA; ambiguity A5).

| # | id | atoms | kind |
| --- | --- | --- | --- |
| 1 | A1 | outcome hit, PosClass = self ($\omega_n$ binds k) | scalar |
| 2 | A2 | outcome hit, PosClass = ancestor | scalar |
| 3 | A3 | outcome IA, PosClass = ancestor (ancestor declares k, committed view absent) | scalar |
| 4 | A4 | outcome IA, PosClass = self (own declared key uncommitted) | scalar |
| 5 | A5 | outcome UD, PosClass = root-boundary | scalar |
| 6 | A6 | outcome UD, PosClass = isolation-boundary (realm mismatch stops the walk) | scalar |
| 7 | A7 | outcome IA, withdrawn binding (committed hit, provider table lacks the label) | scalar |

*Finiteness.* 3 outcomes × ≤ 3 position classes, of which 7 combinations are well-formed = **7**. Chain length is invisible: the occurrence records the class of the *deciding* fiber only. ∎

*Reachability (5 of 7).* A1 = S-It-1; A2 = S-It-3; A3 = S-It-4; A5 = S-It-5. A6: yes — **S-Acc-1**: `P := (∅,{k1},[provide(k1,v1)])`, `G := ({k1},∅,[])`, `C := (∅,∅,[read(k1)])`; ρ = `insert(root, P); insert(root, G); settle; isolate(k1, r1); insert(G, C); settle` — the boundary must fall *between* C and its parent, so C is orchestrator-inserted under G after the isolate: C resolves k1 at r1 while G resolves it at the shared realm; the walk from C stops at the realm mismatch → UD, although G's committed view binds k1 and would otherwise have authorized it (contrast S-It-3's T6). A4: **interface-unrealizable** — while a fiber runs (forward or in recovery) its own committed view is total on $d_n$ and is discarded only as L-Unload's last act (Table 1: $\omega$ survives until Inactive); a fiber never executes a step while Inactive. So no self-window with a declared-uncommitted key exists. This is exactly the visibility half of §4.3.1's ordering promise. A7: **spec-unreachable** — a committed edge $\omega_m(k) = n$ keeps $\mathrm{relied}_n$ true, so L-Unload — the only rule that withdraws provisions via provide⁻¹ — is blocked until the edge is gone (Thm. 63); hence a committed binding is never withdrawn while readable. The reference semantics' branch exists to catch deviants (`unload-without-guard`, `unload-clears-view-early`; Appendix F); in $\mathbb S$ the occurrence is unreachable and is discarded from $T^\star$ with a note that its *unreachability* is itself Theorem 63's testable content (S-Unl-2/S-Unl-6 witness the guard).

*Scripts.* 1 new (S-Acc-1), rest shared.

### D.15 Summary counts

| rule / operation | $\|\Sigma_r\|$ | $\|\Sigma_r^{\mathrm{reach}}\|$ | unrealizable (ids) | canonical scripts |
| --- | :-: | :-: | --- | :-: |
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

Cross-check target for the explorer (§7) and the manual computations (Appendix E): the per-rule reachable occurrence sets above; in particular the *negative claims* (I5, D2, D6, V2, A4, A7 never occur in any normalized reachable window at the working bound) as well as the positive ones.

### D.16 Calculus ambiguities found (recorded, not silently resolved)

- **A1 — O-Remove's agent.** The rule is orchestration-prefixed yet $\Lambda_{\mathrm{orch}}$ offers no remove input. Adopted reading (matching the reference semantics and §5.2's loader): removal fires during settle when enabled. If removal is preferred as an explicit input, D.3's scripts gain one `remove(n)` action each; the alphabet is unchanged.
- **A2 — L-Divert / L-Raise overlap.** L-Raise carries no view premise, so at target $\neq \omega$ with a raising next iteration both rules are enabled; the calculus commits to no order. Exhaustive exploration (CF6) must offer both branches; verdicts for windows in the overlap must accept both outcome sets.
- **A3 — `update` has no rule.** $\Lambda_{\mathrm{orch}}$'s update(n,cfg) (and the loader behavior of §5.2) is not among Table 1's ten rules. Realized as a forced divergence. Interacts with PB-2 (active-overwrite underspecification): the tables treat an in-place $\mathcal A_k$ overwrite (P3) as episode-invisible and an entry update (V5) as a full bounce, which is the reference semantics' choice, not the source paper's theorem.
- **A4 — label-level disjointness gap.** O-Insert's premise is key-level; with Def. 28 realms, joined keys collide at the same storage label without violating it, making the Def. 23 set precondition fail dynamically (X4, S-Rai-3). The calculus needs either a label-level insertion premise or an explicit statement that dynamic conflict is an ordinary raise — the tables adopt the latter.
- **A5 — withdrawn committed binding.** Algorithm 6 line 4 returns the committed binding assuming the provider still holds the value; the reference semantics returns IA when the table lacks it. Unreachable in the specification (the reliance guard is exactly what prevents it — Thm. 63), so the choice is invisible to conforming implementations, but the algorithm as printed does not say so.
- **A6 — read-failure convention.** Algorithm 6 *throws* on IA/UD; Definition 1 makes rderr(n,k,ε) an ordinary event and the read step lands. Adopted: a failing read is an observed event and the iteration continues (Right); a strict/raising read would move T7/T8 into L-Raise's alphabet.
- **A7 — inverse reads are inexpressible in the plain step grammar.** Def. 48 clause 2 licenses an inverse to read $\sigma_m|_{d_n}$, and Thm. 63's content is precisely a committed read during teardown — but the plain step constructors provide no inverse that reads. The reference semantics adds `trackReadOnRevert`, which Definition 2's script language admits (the read-on-revert form); S-Unl-6 depends on it.
- **A8 — isolation boundary in Algorithm 6.** The pseudocode stops only at root; the reference semantics also stops where child and parent resolve the key at different realms (A6 letter, reachable via S-Acc-1). The §5 prose supports the refinement; the algorithm should be emended.
- **A9 — L-Divert's landing alternative needs asynchrony.** §4.3.3's inertia is the only source of a target change between an iteration's launch and landing; the synchronous script semantics has no such gap. D6 is calculus-real, interface-unrealizable.
- **A10 — changed-provider divergence is unrealizable.** While any installed consumer holds $\omega(k)=m$: (i) $\mathrm{relied}_m$ blocks $m$'s L-Unload, so $m$ stays registered and its removal is impossible; (ii) O-Insert's declared disjointness then refuses any new declarer of $k$. Hence $\mathrm{provider}_k$ can only become $\bot$, never $m' \neq m$, under a live committed edge. Isolation does not escape this: a live fiber's resolution context is fixed at insertion. So every reachable divergence at L-Divert/L-Leave is a ⊥-divergence or an orch-update. (Stated in full at D.7; cited from §5.3.)

### D.17 Interface obligations consumed by the proofs

Every property the proofs of §5–§6 and Appendix C assume of this appendix's tables, with where it is used and where it is discharged:

| Tag | Where used | Property | Discharged |
| --- | --- | --- | --- |
| **(D-A)** | Def. 6, Appendix C (per rule), C.11, Thm. 3 (CF3) | For each rule and coeffect operation, a **finite** alphabet $\Sigma_r$ whose occurrence classes cover exactly the guard atoms and write inputs of Table 1's row (scalar atoms, step constructors, equality patterns, witness statuses, normalized per-item updates), with finiteness proved. | The alphabet tables and finiteness proofs of D.1–D.14. |
| **(D-B)** | Cor. 1, Thm. 4 (reachability bridge) | $s \in \Sigma_r^{\mathrm{reach}} \iff$ some finite $\mathbb S$-derivation from the empty registry reaches a pointed window with $s \in \kappa_r(W_r(\gamma,n))$; stability under the renamings of Lemmas 56 / 2. | The reachability tables of D.1–D.14 (with Cor. 1 for stability). |
| **(D-C)** | Thm. 3 (CF5), Lemma 5 (Step 0), Lemma 6 | For every $s \in \Sigma_r^{\mathrm{reach}}$, a canonical script $\rho_{r,s} \in T^\star$ whose unique-up-to-$\equiv$ specification run reaches, after its prefix, a pointed configuration presenting $s$ at the acting fiber, with the final action attempting $r$; construction invariant under renaming; surjectivity onto $\Sigma_r^{\mathrm{reach}}$. | The script indices of D.1–D.14 (60 scripts; full derivations in the artifact). |
| **(D-D)** | C.1(K), C.7(K) | The interface-unrealizable vectors are identified and excluded from $\Sigma_r^{\mathrm{reach}}$: I5, D6 (and the D2/V2, A4, A7 exclusions). | The unrealizability arguments of D.1, D.7, D.9, D.14. |
| **(D-E)** | §6.3 (preamble, case (a)) | Per canonical script, the complete specification outcome set is computed by exhaustive exploration of every fair choice (no policy sampling), and $V_{r,s}$ is $\equiv$-set-equality against it, certificates included, plus the termination clause. | D.0 (verdict background) with §7's exhaustive-schedule harness. |
| **(D-F)** | §6.3 (cases (a),(b)) | Attempt-point determinacy: every specification schedule of $\rho_{r,s}$ presents the same normalized signature $s$ at the attempt point. | The script derivations (artifact); branch-dependent occurrences are flagged in D.7 and covered by D-E's exhaustive verdicts. |
| **(D-G)** | §6.3 (case (c)) | For order-sensitive write aspects (accumulator $\mathsf{inv}$ order; landing order), the canonical script pins a schedule-invariant distinguishing subword (single-fiber forcing). | S-Unl-1 (D.10) and its kin. |
| **(D-H)** | Appendix C's (K) items | The tables' numbered rows are citable as numbered facts; Appendix C's per-rule occurrence descriptions agree with them row-for-row, discrepancies resolving to this appendix or logged at integration. | This appendix (see Appendix C's integration note). |

**Additional cross-checks** (facts the tables confirm that the proofs highlight): the masked entry of Proposition 1 appears in $\Sigma_{\text{L-Unload}}^{\mathrm{reach}}$ with $\tau = \top$ (U10), distinct from its $\tau = \bot$ siblings (U11/U12) — the distinction is load-bearing in §6.3; the L-Begin classes $\mathsf{installed\mbox{-}only\mbox{-}provided}$ (B6) and $\mathsf{unprovided}$ (B7) are both reachable (D.4); and the explorer output should exhibit a $\prec$-cyclic reachable state to witness that Theorem 5's extra generality is exercised.
