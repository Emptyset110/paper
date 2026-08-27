# MASTER — the two-track proof program

Workspace of the finite-characterization proof effort. Two tracks, one goal:

$$\mathbb I \in \mathfrak I_{\mathrm{CF}} \implies \big(\, \mathbb I \mathrel{\mathbf{conf}} \mathbb S \iff \mathbb I \models T^\star \,\big)$$

- **Track M (manual mathematics):** a complete hand-written proof, publishable
  without a proof assistant — every set, relation, and quantifier explicit;
  finite signature tables actually enumerated; transport, reflection,
  shortest-counterexample, and ranking arguments written in full.
- **Track L (machine-checked):** a Lean 4 mechanization of the bounded core
  (normalization equivariance; finiteness of the bounded quotient; explorer
  completeness; the bounded characterization theorem), with the cutoff
  isolated as the one explicitly-marked axiom and the final theorem derived
  conditionally on it.

Both tracks are grounded by an executable: a true all-successor state-space
explorer over the reference semantics, which generates the reachable
signature tables and the bounded suite $T_B$, and audits the existing
32-test suite against them.

## Adopted notation (binding for every deliverable)

From `../proof/PAPER_REWRITE.md` (§3–§5), which every author must read first:

- $\mathbb S$ — the calculus as an instrumented LTS (rules of [SZC26]
  Table 1, pp. 28–41 of `../paper.pdf`; metatheory pp. 42–53; the §5 mapping
  pp. 54–66). $\mathbb I$ — an implementation. $\mathbf{conf}$ —
  termination-sensitive observation equivalence + refusal agreement +
  rule-level observation bisimulation, as PAPER_REWRITE defines.
- $W_r$ — the window of rule $r$;
  $\kappa_r : W_r \to \mathcal M_{\mathrm{fin}}(\Sigma_r)$ — the
  normalization of a window into a finite multiset of *occurrences* over the
  finite atomic alphabet $\Sigma_r$. Large maps enter through their atomic
  entries (pointwise/existential decomposition), never as unbounded wholes.
- $\mathfrak I_{\mathrm{CF}}$ — clause-factored implementations, obligations
  CF1–CF5 (abstraction; equivariance; signature factorization
  $f_r^{\mathbb I} : \Sigma_r \to \mathrm{Decision}_r$; instrumentation
  faithfulness; canonical reachability).
- $\rho_{r,s}$ — the canonical script reaching signature $s \in
  \Sigma_r^{\mathrm{reach}}$; $V_{r,s}$ its verdict;
  $T^\star = \{(\rho_{r,s}, V_{r,s})\}$.
- $T_B$ — the bounded exhaustive suite at bound
  $B = (N_f, N_k, N_v, N_s, N_d)$; default working bound
  $B_0 = (4, 2, \text{value classes} \{v_1, v_2, \bot, \xi\}, 5, 2)$.
- The reference semantics executable is `../proof/src/model.mjs` (rules as
  guarded functions; choice oracle already present); the existing suite is
  `../proof/tests/*.test.mjs`; deviants (27) in `MUTANTS`.

## Signature field drafts (starting points; refine with logged deviations)

Per rule, the occurrence alphabet must cover exactly the guard atoms and
write inputs of Table 1's row, cardinality-free. Drafts:

- **O-Insert**: atoms {parent-live?, ∃ declared-provision conflict (as
  singleton-key witness occurrence)}; freshness is system-controlled — mark
  interface-unrealizable.
- **O-Retire**: trivial alphabet (unconditional); occurrence records the
  target's state class {pending, installed, failed} for write-aspect
  bookkeeping only.
- **O-Remove**: atoms {τ, state = Inactive?, ∃ child (witness occurrence)}.
- **L-Begin**: atoms {state ∈ {Inactive(⊥), Inactive(ξ)}, τ, per-key
  satisfaction occurrences with classes {Active-provided,
  installed-only-provided, unprovided}} — the *set of classes present*, not
  counts.
- **L-Iter / L-Finish / L-Divert**: atoms {state = Reloading, view relation
  ∈ {target = ω, target ≠ ω, target = ⊥}, next-step class ∈
  {provide(fresh), provide(conflict), track, read(committed),
  read(declared-uncommitted), read(undeclared), read(ancestor-committed),
  setval(own), setval(foreign), register, raise, exhausted}}.
- **L-Raise**: the raise step class above; occurrence records accumulator
  nonemptiness per inverse class.
- **L-Leave**: atoms {state = Active, view relation ∈ {≠ ω, = ⊥}}.
- **L-Unload**: atoms {state = Unloading, relied? (witness occurrence:
  installed dependent with committed edge), outcome ∈ {⊥, ξ}, τ,
  post-target ∈ {⊥, satisfiable}, inverse classes present ⊆
  {provide⁻¹, track⁻¹, register⁻¹, read-on-revert}}.
- **Coeffect operations** (Def. 23/24/28/29/31; Algorithm 6): per-operation
  small alphabets (own/foreign binding; realm same/joined/distinct;
  intercept chain depth-as-order-pattern up to 2; the three Alg-6 outcomes
  with ancestry-position class).

Every deliverable that refines these drafts must include a **Deviations**
section listing each change and why.

## Deliverables and interfaces

- **D1 `signatures.md`** (Track M): per-rule occurrence alphabets with
  finiteness proofs; the reachability analysis
  $\Sigma_r^{\mathrm{reach}} \subseteq \Sigma_r$ (which occurrences are
  reachable from the empty registry, with justification); the canonical
  scripts $\rho_{r,s}$ (explicit component data per PAPER_REWRITE's script
  syntax) and, per script, the derivation sketch that it reaches $s$.
  Interface consumed by D2 and D4: the numbered table
  (rule, occurrence id, atoms, reachable?, canonical script id).
- **D2 `proofs.md`** (Track M): full proofs of — Factorization of $\mathbb S$
  (per rule, citing Table 1 rows; establishes Lemma "$\mathbb S \in
  \mathfrak I_{\mathrm{CF}}$"); Transport (CF-members agree across
  $\kappa$-equal windows); Observation Reflection (a decision difference at
  a signature is visible in $\rho_{r,s}$'s observation); Safety direction by
  shortest counterexample; Termination direction by ranking against
  [SZC26] Thm. 66's measure $S(n) \le (K+4)(V(n)+1)$ (with the cyclic-≺
  case handled directly as in `../proof/PAPER.md` §5.3's M4 derivation);
  assembly of the main theorem, both directions. May cite D1's table rows
  as numbered facts; every other step written out.
- **D3 `explorer/` + `explorer-report.md`** (grounding): a normalized
  all-successor BFS/DFS over `model.mjs` semantics at bound $B_0$ —
  states canonicalized by name/key/value normalization, dedup, full
  successor enumeration (NOT the oracle-replay driver); outputs: reachable
  abstract state count, per-rule reachable occurrence sets (to cross-check
  D1), generated $T_B$ (access sequence + distinguishing observation per
  transition class), audit of the existing 32 tests against the reachable
  signature table (which signatures each test exercises; uncovered
  signatures if any), and the 27-deviant kill check of the *generated*
  $T_B$.
- **D4 `lean/`** (Track L): Lean 4 project (no mathlib): bounded calculus
  encoding; normalization with equivariance theorem (A); finiteness of the
  bounded state space (B); explorer function with soundness+completeness
  (C); bounded characterization (D) — by structural proof or
  decide/native_decide with the trust note; cutoff (E) as a named axiom
  matching D2's transport lemma statement; final conditional theorem (F).
  `PROOF_STATUS.md` must list every theorem with its status
  (proved / proved-by-native_decide / axiom) — no silent `sorry`.

## Quality bars

- No "easy to verify" without the verification; finite checks are tables or
  executables, cited by name.
- Deviations from this MASTER logged per deliverable.
- The 32-test suite is *material* for $T^\star$, not its definition: if D3's
  generation finds uncovered signatures, that is a finding to report, not to
  hide.
- Track M must stand alone as mathematics (readable without running
  anything); Track L must state precisely what is and is not machine-checked.

## Integration (owner: the coordinating session)

D1+D2 → the manual-proof manuscript; D3 → empirical appendix + Σ tables
cross-check; D4 → mechanization appendix. Final assembly updates
`../proof/PAPER_REWRITE.md`'s placeholders or supersedes it.
