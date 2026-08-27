# Sufficient and Necessary Conformance Testing for a Calculus of Dynamic Composition

**Companion to:** *A Programming Paradigm for Spatiotemporal Composability* (Shi, Zhang, Cui; `../paper.pdf`, cited as [SZC26]). References of the form Def. 43, Thm. 63, Table 1, Lemma 70 are to [SZC26]; Definition 3, Theorem 2 are internal.

**Artifacts.** The executable reference semantics, the suite, the deviant harness, and the exhaustive-schedule logs reside in this directory and reproduce with Appendix A. **Version.** Revision R1: this version repairs, against an external review, the uniformity hypothesis (the counterexample is now Example 1), the vacuous-pass defect in the passing definition, the soundness derivations of M4/M5, the schedule-enumeration claim (now genuinely exhaustive), and the statement of necessity (now three precise claims in place of one overclaimed word).

---

## Abstract

[SZC26] presents a calculus of dynamic composition with a proved metatheory and an implementation, Cordis, related to the calculus by a correspondence table and reference algorithms — but by no proof. We develop the missing verification as a conformance test theory. We formalize the plugin-system interface induced by the paper's Table 2 as a labeled transition system with a fixed observation vocabulary, define conformance as observation refinement up to the calculus's own equivalences, and construct a finite suite $T$ of 32 tests. We prove: **soundness** — the calculus satisfies $T$ on *every* schedule, each verdict derived from the metatheorems of [SZC26], with the schedule quantifier discharged by complete enumeration of each scenario's finite choice tree; **sufficiency** — an implementation passing $T$ conforms, relative to five testability hypotheses stated as properties of transition systems, among them the uniformity and regularity hypotheses that Gaudel's theory shows no finite test method can avoid (we exhibit the counterexample that makes regularity indispensable); and **necessity**, in three precise senses — each test is the unique realizer of its clause of the calculus, so its removal breaks the sufficiency proof (proof-necessity); the suite rejects all 27 formally defined single-clause deviant calculi, under exhaustive schedules (adequacy); and 14 tests are each the sole test rejecting some deviant, hence irreplaceable relative to that family (essentiality). We do not claim semantic minimality beyond these three senses, and we show why no single-clause deviant family can supply it for the remaining tests. Applying $T$: one Cordis build passes $32/32$; the published build fails exactly four obligations — three reproducing cataloged defects, one new; a two-node distributed deployment of the same build fails exactly the same four, exhibiting no divergence attributable to distribution on this suite. The construction also yields three corrections to [SZC26] itself.

---

## 1. Introduction

[SZC26] proves a metatheory for a calculus of dynamic composition and asserts, through its Table 2 and Algorithms 1–10, that Cordis implements it. The assertion is not a theorem, and §8 exhibits a shipping build honoring the table's names while violating the calculus's rules.

**Problem.** The goal of this paper, stated plainly: formalize the plugin system that [SZC26] §5 describes, and construct a finite test set that is a *sufficient and necessary* condition for verifying that a system implements the calculus — with both adjectives given mathematical content and proved, and with everything not provable by finite testing isolated into named hypotheses rather than smuggled into prose.

**Method.** We instantiate the classical theory of conformance testing from formal specifications: Gaudel's testability hypotheses for finite completeness [Gau95], Tretmans' sound/exhaustive suites for labeled transition systems with quiescence [Tre96, Tre08], and mutation adequacy [DLS78] transplanted from program syntax to *semantic deviants* of an executable specification. Three design decisions carry the development: the specification is executable, with scheduling nondeterminism reified as an enumerable choice oracle, so soundness and the deviant matrix are checked over *all* schedules of each scenario; tests are specification-level data — components are literally the $(d,p,e)$ triples of Def. 43 with $e$ a script at the iterator granularity of Def. 51 — so the suite cannot drift from the calculus's vocabulary; and the fault domain consists of deviant *calculi*, each negating one clause of Table 1's reading, so rejection of a deviant is exactly the suite distinguishing the calculus from its nearest neighbor.

**Contributions.** (1) The plugin-system interface as an instrumented LTS with an explicit observation algebra, and conformance as observation refinement with a termination clause (§3). (2) A 32-test suite whose scripts and verdicts are displayed formally, with a per-rule realization table for premise vectors (§5). (3) A soundness theorem with derivations from [SZC26]'s metatheorems — including the two places where the naive citation is *wrong* and a direct derivation is supplied (§5.3). (4) A sufficiency theorem under five named hypotheses, with the counterexample showing the regularity hypothesis is not removable (§6). (5) A necessity theorem in the three senses above, with the deviant family defined formally and the matrix computed under complete schedule enumeration (§7). (6) Verification of two builds and a distributed deployment; four implementation defects, one new; three corrections to the paper (§8, §9).

---

## 2. Background: the calculus

Notation of [SZC26], recalled minimally. Fix countable disjoint $K$ (keys), $\mathfrak N$ (names), $\mathbb V$ (values), $\mathbb T$ (tags). Components $(d,p,e)$, fibers $\langle d,p,e,\pi,\sigma,\tau,\theta\rangle$ with

$$\theta \in \{\mathsf{Inactive}(\zeta), \mathsf{Reloading}(i,g,\omega), \mathsf{Active}(g,\omega), \mathsf{Unloading}(g,\omega,\zeta)\},$$

registries $F_\gamma$, derived context $\sigma_\gamma = \bigcup\{\sigma_m \mid \theta_m = \mathsf{Active}(-,-)\}$ (eq. 40), target views $\mathrm{target}_n(\gamma)$ (Def. 46), $\mathrm{relied}_n(\gamma)$ (Def. 50). Ten rules (Table 1): O-Insert (freshness; $\pi \in \mathrm{dom} F_\gamma \cup \{\mathsf{root}\}$; $\forall m.\ p \cap p_m = \varnothing$), O-Retire, O-Remove ($\tau_n$; $\theta_n = \mathsf{Inactive}(-)$; $\forall m.\ \pi_m \neq n$), L-Begin, L-Iter, L-Finish, L-Divert, L-Raise, L-Leave, L-Unload (guard $\neg\mathrm{relied}_n$). Registration: Def. 47. Steps factor as $\gamma^{t+1} = \mathrm{edit}^t(\Psi^t(\gamma^t))$ (eq. 52). Metatheory used below: Lemmas 54–57 (write discipline, $\simeq$-invariance, equivariance, vestigial framing), Thm. 59, Thm. 61/Cor. 62, Thm. 63, Thm. 64, Thm. 66 (hypotheses: $\prec$ acyclic, $\mathrm{len}(e_n) \le K$, finitely many names), Lemmas 68/70/71/72, Thm. 73. Equalities up to $\simeq$ (Def. 33) and $\approx$ (Def. 53).

---

## 3. The instrumented interface

**Definition 1 (events; observations).** The event alphabet:

$$\mathcal E ::= \mathsf{app}(n,t) \mid \mathsf{inv}(n,t) \mid \mathsf{rd}(n,k,v) \mid \mathsf{rderr}(n,k,\epsilon) \mid \mathsf{act}(n) \mid \mathsf{deact}(n) \mid \mathsf{val}(n,k), \qquad \epsilon \in \{\mathsf{IA},\mathsf{UD}\}.$$

For words define $w \sim_{\mathcal E} w'$: equal length and letterwise equal, with embedded values compared by $\simeq$. An *observation* is $(w, q)$ with $w \in \mathcal E^*$ and $q$ a quiescent report (statuses in $\{\mathsf{pend},\mathsf{load},\mathsf{act},\mathsf{fail},\mathsf{unld},\mathsf{disp}\}$, outcomes, the store report $\mathrm{st}(k) = \sigma_\gamma(k)$, refused-input log); $(w,q) \sim (w',q')$ iff $w \sim_{\mathcal E} w'$ and the reports agree with $\simeq$ on values.

**Definition 2 (plugin system; scripts; behaviors).** As in R0 of this paper: an LTS over $\Lambda = \Lambda_{\mathrm{orch}} \uplus \{\mathsf{life}\}$ with event emission; orchestration scripts $\rho$ over $\Lambda_{\mathrm{orch}} \cup \{\mathsf{settle}\}$; a run executes inputs in order and at each $\mathsf{settle}$ fires $\mathsf{life}$-transitions until quiescence — *a run in which some settle never terminates is a* divergent *run and yields no observation*. $\mathrm{obs}_{\mathbb X}(\rho)$ is the set of observations of non-divergent runs. The specification $\mathbb S$ is the calculus with components-as-scripts and the emission table of R0 (one iteration per step; L-Finish emits $\mathsf{act}$; L-Unload emits the accumulator's $\mathsf{inv}$-events then $\mathsf{deact}$; Algorithm 6 reads emit $\mathsf{rd}/\mathsf{rderr}$).

**Definition 3 (conformance).** $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$ iff for every $\rho$: (i) $\forall o \in \mathrm{obs}_{\mathbb I}(\rho)\ \exists o' \in \mathrm{obs}_{\mathbb S}(\rho).\ o \sim o'$; and (ii) if every run of $\mathbb S$ on $\rho$ is non-divergent then every run of $\mathbb I$ on $\rho$ is non-divergent. $\mathbf{conf}$ is a preorder (transitivity: compose (i) via transitivity of $\sim$; compose (ii) directly).

**Definition 4 (passing — with termination).** For a test $t = (\rho_t, V_t)$: $\mathbb I \models t$ iff **every run of $\mathbb I$ on $\rho_t$ is non-divergent** and every observation satisfies $V_t$; $\mathbb I \models T$ iff all tests pass. *(The bold clause repairs a defect of R0, under which a diverging implementation passed vacuously.)*

**Definition 5 (observation simulation).** For partial $A : \Gamma_{\mathbb I} \rightharpoonup \Gamma_{\mathbb S}$ with $\mathrm{Reach}(\mathbb I) \subseteq \mathrm{dom} A$, the relation $\mathcal R_A = \{(u,\gamma) \mid \gamma \approx A(u)\}$ is an *observation simulation* when (S0) $A(\gamma^0_{\mathbb I}) = \gamma^0$; (S1/S2) every $\mathbb I$-transition from $u$ is matched from any $\gamma \approx A(u)$ by a same-labeled $\mathbb S$-transition with $\sim_{\mathcal E}$-equal emission, to configurations related again, and refusals correspond; (S3) quiescent $u$ have quiescent $A(u)$ with $\sim$-equal reports, and $\mathbb I$-settles terminate wherever all $\mathbb S$-settles do.

**Lemma 1.** If some $A$ makes $\mathcal R_A$ an observation simulation then $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$.
*Proof.* Induction on run length: (S0) grounds the base; (S1/S2) extend, with the matching step from an $\approx$-related configuration licensed by Lemma 55 of [SZC26] ($\simeq/\approx$-invariance of rule applicability and results — precisely the up-to technique the relation needs); (S3) delivers clauses (i) at the final settle and (ii) globally. $\blacksquare$

---

## 4. Windows, factorization, and clauses

**Definition 6 (windows and reads).** For each rule $r$ acting at $n$, its *window* $W_r(\gamma,n)$ is the tuple of fields Table 1's premises and writes touch (per [SZC26] Lemmas 54–55; e.g. for L-Begin: $\theta_n, \tau_n, d_n$, and for each $k \in d_n$ the set of Active providers of $k$). Its *read abstraction* is

$$\alpha_r(\gamma,n) \;=\; \big(\beta_r(\gamma,n),\ \iota_r(\gamma,n)\big),$$

where $\beta_r \in \{0,1\}^{m_r}$ is the truth vector of $r$'s premise conjuncts as listed in Table 1's row (with satisfaction refined into the one sub-premise the calculus itself distinguishes: *some provider vs. some Active provider*, Def. 45/49), and $\iota_r$ is the tuple of values the row's write functions consume (the committed $\omega$; the current step $s$; the accumulator as the *list of inverse events in composition order*; the outcome $\zeta$).

**Lemma 2 (factorization of $\mathbb S$).** For every rule $r$: applicability at $(\gamma,n)$ is a function of $\beta_r(\gamma,n)$ alone; and when applicable, the successor's window, the emission, and the refusal behavior are functions of $\alpha_r(\gamma,n)$, equivariantly under bijections $\chi$ of $\mathfrak N, K, \mathbb V, \mathbb T$ and invariantly under extension of $\gamma$ by fibers and keys outside $W_r$.
*Proof.* Applicability: each premise in Table 1's row is one conjunct of $\beta_r$ by construction. Effects: the step factors as $\mathrm{edit}_r \circ \Psi_r$ (eq. 52); $\mathrm{edit}_r$ assigns fields listed in the row from components of $\iota_r$; $\Psi_r \in \{\mathrm{id}, \text{one iteration of } e_n, g_n\}$ reads the current step resp. the accumulator, both components of $\iota_r$, and the iteration's own reads go through Algorithm 6 against $\omega$ — again $\iota_r$. Equivariance is Lemma 56 extended pointwise to keys/values/tags (no rule compares two names, keys, or values except by equality, and none reads a cardinality: Table 1's rows contain no arithmetic); frame invariance is Lemma 57 together with Lemma 54(1). $\blacksquare$

The parenthetical in the proof — *no rule reads a cardinality* — is the exact property the sufficiency hypothesis must transfer to $\mathbb I$, and cannot get for free:

**Example 1 (why regularity is indispensable; after the review).** Let $\mathbb I^\sharp$ behave exactly as $\mathbb S$ except that L-Begin never fires for fibers with $|d_n| \ge 3$. $\mathbb I^\sharp$ is equivariant, window-local (it reads only $W_{\text{L-Begin}}$), admits the identity abstraction, and passes every test of $T$ (all catalog components declare $\le 2$ keys) — yet does not conform. No finite suite excludes $\mathbb I^\sharp$ and its unboundedly many variants: this is the classical argument that finite testing is incomplete without an *instance-size* hypothesis, and it is Gaudel's regularity hypothesis [Gau95] that names it. R0 of this paper elided it inside an unsound transport step; it is now Hypothesis H3.

**Definition 7 (clauses).** $\mathcal C$ is the finite set enumerated in Table C (Appendix B, col. 3), of four kinds: $\langle r{:}\beta \to \mathsf{fire/refuse}\rangle$ — applicability of rule $r$ at premise vector $\beta$; $\langle r{:}\mathsf{write}[a]\rangle$ — an observable aspect $a$ of $r$'s write row (state transition, emission letter, emission *order*, store effect); $\langle \mathrm{op}\rangle$ — a defining equation of Def. 23/24/28/29/31 or an outcome line of Algorithm 6; $\langle \mathrm M_i \rangle$ — one of the five metatheorems read as an observation predicate over its scenario schema. Extension clauses (C2.1's overwrite dichotomy) and fail-safe clauses (R1.3, for components violating the Def. 43 containment premise) are flagged as such in Table C: they constrain behavior the calculus leaves open or forbids, and participate in sufficiency only as the guarantees [SZC26] §5 itself states.

---

## 5. The suite, and its soundness

### 5.1 Tests

The suite $T$ has 32 tests; each row of Table C gives its script, verdict formula, clause, and — for rule clauses — its premise vector. Displayed here, the two rows quoted throughout:

- **R5.1**: $\rho = \mathsf{insert}(\mathsf{root}, P); \mathsf{settle}; \mathsf{retire}(P); \mathsf{settle}$, $S_P = \mathsf{track}(a);\mathsf{track}(b);\mathsf{track}(c)$.
  $V(w,q) \equiv \mathsf{app}(P,a)\,\mathsf{app}(P,b)\,\mathsf{app}(P,c) \sqsubseteq w \ \wedge\ \mathsf{inv}(P,c)\,\mathsf{inv}(P,b)\,\mathsf{inv}(P,a) \sqsubseteq w$ ($\sqsubseteq$: subword).
- **R9.1**: $\rho = \mathsf{insert}(\mathsf{root},P); \mathsf{insert}(\mathsf{root},C); \mathsf{settle}; \mathsf{retire}(P); \mathsf{settle}$, $S_P = \mathsf{provide}(k,v_0);\mathsf{track}(p_1)$, $d_C = \{k\}$, $S_C$ = one tracked effect whose inverse reads $k$.
  $V(w,q) \equiv \mathsf{rd}(C,k,v_0) \in w \ \wedge\ \mathsf{rd}(C,k,v_0) <_w \mathsf{inv}(P,p_1) \ \wedge\ q(P) = \mathsf{disp}$.

### 5.2 Realization of premise vectors

**Lemma 3 (realization).** For every rule $r$ and every premise vector $\beta$ *reachably consistent* in $\mathbb S$ at the interface (a vector is excluded exactly when the interface cannot request it: O-Insert's freshness cannot be falsified because names are system-drawn), some test's unique-up-to-$\approx$ $\mathbb S$-run reaches a pointed configuration with $\beta_r = \beta$, and its verdict constrains precisely the clause $\langle r{:}\beta\rangle$ resp. the write aspects at $\beta = \mathbf 1$. The full correspondence:

| Rule | premise conjuncts | vectors realized (test) |
| --- | --- | --- |
| O-Insert | fresh; parent live; $p$-disjoint | $111$ (R1.1); $101$ (R1.2); $110$ (R1.4); fresh$=0$: N/A at interface |
| O-Retire | — (unconditional) | fires installed (R2.1), pending (R2.2) |
| O-Remove | $\tau$; Inactive; childless | $111$ (R2.1 end); Inactive$=0$: blocked during guard (R3.1); childless$=0$ (R3.2) |
| L-Begin | Inactive($\bot$); $\neg\tau$; $\exists$ provider; provider Active | $1111$ (R1.1); $1100$ (R4.1); $1110$ (R4.3); $1011$ (R2.2); $0{\cdot}{\cdot}{\cdot}$ with $\zeta = \xi$ (R4.4); late flip $0\to1$ (R4.2) |
| L-Iter/L-Finish | Reloading; $\mathrm{target} = \omega$ | $11$ (R5.1); $10$ (R6.1) |
| L-Raise | iteration raises | (R7.1) |
| L-Leave | Active; $\mathrm{target} \neq \omega$ | via $\tau$ (R8.1), provider loss (M2), replacement (M3) |
| L-Unload | Unloading; $\neg\mathrm{relied}$ | $11$ (R2.1/R5.1); $10$ (R9.1, R3.1, M2) |

*Proof.* Each cited run is derived once, in Theorem 2's style; the L-Begin row is derived in full in R0 §5 and unchanged. The reachability exclusions are read off the interface: freshness is the one premise the orchestration labels cannot falsify. $\blacksquare$

### 5.3 Soundness

**Theorem 2 (soundness).** $\mathbb S \models T$, over *every* schedule of every scenario.
*Proof.* The schedule quantifier first: each scenario's nondeterminism is the choice, at states where several rules are applicable, of which fires; the reference semantics reifies this as a choice oracle, and the harness enumerates the complete (finite) oracle tree of every scenario — 25 of 32 scenarios admit exactly one schedule, the largest tree has 924, and none is truncated (Appendix A, run 1; the enumeration is exact, replacing R0's two-policy sampling). It remains to show each verdict holds on each schedule; each is an instance of [SZC26] metatheory, with two exceptions derived directly. Representative derivations:

*R5.1, R9.1*: derived in full in R0 §5 (unchanged): LIFO from the $g \circ h$ composition and Thm. 16; the guard ordering from Def. 50 + Thm. 63(2,3), the schedule being forced at each point because at most one rule is enabled.

*M4 — direct, replacing an unsound citation.* R0 cited Thm. 66, whose hypothesis ($\prec$ acyclic) the scenario's mutual-inject cycle violates. Directly: after the two inserts, no fiber is Active and $\sigma_\gamma = \varnothing$. We show by induction on steps that this invariant persists and no lifecycle rule ever fires: L-Begin at either fiber requires its key in $\mathrm{dom}(\sigma_\gamma) = \varnothing$ — false; every other lifecycle rule requires a non-$\mathsf{Inactive}$ state, and both fibers are $\mathsf{Inactive}(\bot)$; hence no step changes the state, the configuration is already quiescent, settle terminates at once, and $q$ reports both $\mathsf{pend}$ with no $\mathsf{app}$ letters — which is $V_{\mathrm M4}$. (The scenario thus *extends* Thm. 66's guarantee outside its hypothesis; the cycle quiesces not by the theorem but by unsatisfiability.)

*M5 — derived from Lemmas 68/70/71/72, not from Thm. 73 alone.* R0's citation of Thm. 73 was too quick: its confluence clause compares sequences with the *same* orchestration steps, while M5's histories differ. $h_1$ vs. $h_2$ (insertion order): O-Inserts of distinct fresh names commute — their Table-1 writes are disjoint and neither reads the other's fields — so $h_2$'s orchestration steps permute to $h_1$'s; interleaved lifecycle steps commute past them by Lemma 71(2); then Thm. 73(2) applies to the same-step sequences. $h_3$ (retire–replace round trip of $B$): the episode of the retired $B$ closes, no $m$ with $B \prec m$ closes after it, and $B$'s replacement draws a fresh name; Lemma 72 deletes the closed episode and its steps leaving a state $\approx$-equal outside the deleted names, and Lemma 56 renames $B'$ to $B$; totality and acyclicity hold, so Lemma 70 identifies the Active set with the support set — a function of $(\tau,\pi,d,p)$ alone (Lemma 68), equal across the three histories; quiescent $\omega$'s and stores then agree by quiet (Def. 49) and single-providership. Hence the three quiescent reports are $\sim$-equal — which is $V_{\mathrm M5}$. $\blacksquare$

Theorem 2 failed twice during construction against draft verdicts and convicted the drafts (R3.2's overclaimed ordering; M3's premise-violating insert — §9 PB-3): the soundness gate has bite.

---

## 6. Sufficiency

### 6.1 Hypotheses

- **H1 (abstraction).** There is $A : \mathrm{Reach}(\mathbb I) \to \Gamma_{\mathbb S}$ with $A(\gamma^0_{\mathbb I}) = \gamma^0$, a total tagging of $\mathbb I$-transitions by rules, label- and event-preservation, and $q_{\mathbb I} = q_{\mathbb S} \circ A$ on quiescent configurations. *(For the systems of §8, $A$ is constructed field-by-field in the adapter audit, with Table 2's one erratum corrected — PB-1.)*
- **H2 (uniformity).** $r$-tagged applicability at $(u,n)$ is a function of $\beta_r(A(u),n)$; $r$-tagged effects and emissions are functions of $\alpha_r(A(u),n)$; both equivariant under $\chi$ and invariant under extension outside $W_r$ — i.e., $\mathbb I$ factors as Lemma 2 proves $\mathbb S$ does.
- **H3 (regularity).** If $\mathbb I$'s tagged behavior agrees with a function of $\alpha_r$ on all instances within the catalog bounds ($|d| \le 2$, four fibers, five steps), it agrees on all instances. *(Indispensable by Example 1; this is where the burden of finite testing lives, and it is deliberately a hypothesis, not a lemma. A cutoff theorem for a syntactically delimited class of rule-table implementations would discharge it and is left open.)*
- **H4 (scheduling).** $\mathbb I$'s scheduler refines the nondeterministic step relation, is fair, and $\mathsf{settle}$ terminates exactly on quiescent configurations.
- **H5 (witness).** Test components' inverses revert their effects and emit their events — true by construction of $\mathsf{track}$; the runtime's *composition* of inverses is what the verdicts observe.

**Theorem 3 (sufficiency).** Under H1–H5, $\mathbb I \models T \implies \mathbb I \mathrel{\mathbf{conf}} \mathbb S$.
*Proof.* We show every clause of $\mathcal C$ holds of $\mathbb I$'s tagged behavior, then conclude by the simulation argument. Fix a rule $r$.

*Applicability.* By H2, $r$-tagged applicability is a function $f_r$ of $\beta_r$. For each interface-reachable $\beta$, Lemma 3 gives a test whose run realizes $\beta$ within the catalog bounds, and whose verdict distinguishes firing from non-firing at that instance ($\mathsf{app}$/status/refusal observables); $\mathbb I \models T$ therefore fixes $f_r(\beta)$ to the calculus's value *at the catalog instance*, and H3 extends the agreement to all instances; H2's equivariance and frame invariance make "the" catalog instance well-defined across renamings and contexts. A $\beta$ unreachable at the interface constrains nothing, and $\mathbb I$ cannot exhibit it either: reachability of a window is itself produced by rule applications (Lemma 54), so the first deviation along any $\mathbb I$-run lies at a reachable window, and the induction below only ever consults those.

*Writes and emissions.* By H2 these are functions of $\alpha_r$; at $\beta = \mathbf 1$, Lemma 3's realizing tests assert every observable aspect listed in Table C for $r$'s row — state transition (O1), the emission letters and, where the row's $\Psi$ is order-sensitive (the iterator; the accumulator), their order (O2), the store effect (O1), refusals (O3) — pinning the function at the catalog instance; H3 extends; H5 lets the $\mathsf{inv}$-letters stand for the accumulator's action.

*Operation, fail-safe, and extension clauses.* The same argument over the C-group tests, whose verdicts are the defining equations at both outcomes of each operation resp. Algorithm 6 line.

*Composite clauses.* $\langle \mathrm M_i\rangle$ are verdicts over scenario schemas closed under H2's transports at the catalog size; H3 extends to larger instances of the same schemas. They pin what no single-rule clause can: the interaction of tagged steps through shared state (notification, guard bookkeeping, chain scheduling).

*Conclusion.* Define $\mathcal R_A$ as in Definition 5. (S0) is H1. (S1/S2): a tagged $\mathbb I$-transition fires only where its $\beta_r$ says the calculus fires (applicability, above), so the same rule applies at $A(u)$, and its result and emission agree by the writes paragraph — the transition is matched, with Lemma 55 carrying the match to any $\approx$-related $\gamma$; refusals likewise. (S3): if $u$ is quiescent but some rule were applicable at $A(u)$, applicability-agreement makes it $\mathbb I$-applicable at $u$, and H4's fairness would fire it — contradiction; report agreement is H1; and where all $\mathbb S$-settles terminate, an infinite $\mathbb I$-settle would map, by the matched steps, to an infinite $\mathbb S$-derivation, contradicting the finiteness of maximal lifecycle sequences there — for scenarios within Thm. 66's hypotheses by its bound $S(n) \le (K{+}4)(V(n){+}1)$, and in general because Definition 3(ii) only quantifies over $\rho$ on which $\mathbb S$'s runs all terminate. By Lemma 1, $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$. $\blacksquare$

**Remark 1.** H3 cannot be weakened away (Example 1), and H2 cannot either (an implementation reading a field outside the window can correlate behavior with untested context). The theorem is a *reduction*: conformance of an arbitrary system reduces to one audit (H1), two structural properties of its text (H2, H3), one scheduler property (H4) — and the finite, executable judgment $\mathbb I \models T$. That reduction, not an unconditional completeness, is what any finite test theory can deliver [Gau95]; ours differs from folklore test suites in that the residue is *named* and the judgment is *proved* sufficient relative to it.

---

## 7. Necessity

**Definition 8 (deviants).** For each rule clause $c$, the deviant $\mathbb S_{\neg c}$ is Definition 2's specification with $c$ negated — premise conjunct deleted or write aspect altered per the table in `src/model.mjs` (27 deviants; each is itself uniform in the sense of H2, hence a member of the universe Theorem 3 quantifies over).

**Theorem 4 (necessity, in three senses).** Let $T$ be the suite and $F = \{\mathbb S_{\neg c}\}$ the deviant family.

1. *(Proof-necessity.)* The assignment $t \mapsto$ (its Table-C clause) is injective, and each $t$ is the **unique** element of $T$ realizing its rule-and-vector entry in Lemma 3's table. Hence for every $t$, the suite $T \setminus \{t\}$ fails Lemma 3, and Theorem 3's applicability (or writes) case for $t$'s clause has no instance to consult: the sufficiency proof does not go through for $T \setminus \{t\}$.
2. *(Adequacy.)* Every deviant fails the suite: $\forall c.\ \mathbb S_{\neg c} \not\models T$ — verified under complete schedule enumeration of every scenario (no sampling).
3. *(Essentiality.)* For 14 tests $t$ there is a deviant failed by $t$ and by no other test; for these, $T \setminus \{t\}$ is passed by a non-conforming uniform system, so $t$ is irreplaceable relative to $F$. The 14 pairs are printed by the matrix runner (Appendix A, run 4).

*Proof.* (1) Table C row check (each vector entry names exactly one test). (2)–(3): finitely many claims of the form "every/some schedule of $\mathbb S_{\neg c}$ on $\rho_t$ violates $V_t$"; two are derived by hand below, the rest by the exhaustive matrix. *Guard deviant on R9.1:* with $\neg\mathrm{relied}$ replaced by $\top$, after $\mathsf{retire}(P)$ both L-Unload($P$) and L-Unload($C$) are enabled; the schedule firing $P$ first emits $\mathsf{inv}(P,p_1)$ before $C$'s teardown read — which then meets a withdrawn binding and emits $\mathsf{rderr}(C,k,\mathsf{IA})$ — violating both order and membership conjuncts of $V_{\text{R9.1}}$; since $\models$ quantifies over all schedules, one violating schedule suffices, and the enumeration exhibits it. *LIFO deviant exclusivity:* the deviant reverses only intra-fiber inverse order; inspection of Table C's verdicts shows R5.1's second conjunct is the only formula constraining the relative order of two $\mathsf{inv}$-letters of one fiber (R9.1 orders a read against an inverse; M2 orders $\mathsf{deact}$ letters and cross-fiber inverses); on every other scenario the deviant's observations are the calculus's. $\blacksquare$

**Remark 2 (what is *not* claimed, and why).** We do not claim semantic minimality of $T$ — that every test is irreplaceable against *all* non-conforming uniform systems. For the 18 tests outside claim (3), no single-clause deviant is caught by that test alone: their clauses are load-bearing (a satisfaction-premise deviation perturbs most scenarios), so any deviant reaching them fails several tests — the subsumption phenomenon of mutation analysis [PAO17]. Sharper, *conditional* deviants (deviating only at a designated premise vector) could in principle separate some of them, but our attempts ran into a fact worth recording: several shielded write aspects are **masked** in the observation vocabulary (e.g. a provide-inverse skipped at a *retirement* unload is unobservable, disposal deleting the entry the residue would sit in), so the corresponding fine-grained deviants are observationally vacuous — a self-healing property of the calculus, not a gap in the suite. The necessity your verification can rely on is exactly (1)–(3); the R0 abstract's word "minimal" overstated this, and is withdrawn.

---

## 8. Empirical verification

Targets and results as in R0, restated with the corrected epistemic force. (i) Reference semantics: $32/32$ under complete schedule enumeration. (ii) **Cordis-aligned** (vendored build with the paper-review GAP fixes): **passes the suite**, $32/32$; conformance additionally rests on the H1 audit (constructed) and H2–H4 (asserted of the build's text and scheduler, not proved — Remark 1). (iii) **Cordis-upstream 4.0.1**: $28/32$ — R9.1, M2 (the L-Unload guard one level too low: GAP-1/2; the observed words realize Theorem 4's guard-deviant derivation almost letter for letter), R1.4 (GAP-6), RU.1 (**new**: a later $\mathsf{update}$ of a recovered fiber releases the first failed episode's error as a process-level unhandled rejection, violating §4.3.4's requirement that $\xi$ be recorded on the fiber). (iv) **Two-node distributed** (same upstream build under `@rebuilding/cordis-node`, alternating placement, observation through projection): $28/32$, failing exactly the same four.

**Theorem 5 (conditional).** If $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$ and the distribution layer satisfies the Distribution Equivalence Contract (`cordis-node/docs/equivalence.md`) on the observation vocabulary, then $D(\mathbb I) \mathrel{\mathbf{conf}} \mathbb S$ — by the contract giving $D(\mathbb I) \mathrel{\mathbf{conf}} \mathbb I$ on that vocabulary and transitivity of $\mathbf{conf}$.
The empirical statement is correspondingly modest: run 5 shows *no divergence attributable to distribution was found on this suite* — it instantiates the theorem's conclusion on 32 points; it does not by itself establish the contract's antecedent, which has its own companion verification.

## 9. Findings about the paper

Unchanged from R0 and unaffected by the review: **PB-1** (Table 2 maps Def. 23's $\mathrm{set}$ to `ctx.set`; the primitive with its precondition and inverse is `ctx.provide`); **PB-2** (§5.1.3's "not observed" overwrite contradicts Thm. 63(3)'s episode-constancy; the calculus is silent — C2.1 pins the dichotomy any extension must satisfy); **PB-3** (Algorithm 10's `dispose`-then-`use` races O-Insert's own disjointness premise; the reference semantics loses the race under enumeration, latching a spurious failure). To these the revision adds a fourth, self-inflicted and instructive: R0's Theorem 3 fell to precisely the counterexample class Gaudel's regularity hypothesis exists to name — recorded as Example 1.

## 10. Related work

Gaudel [Gau95]: uniformity *and* regularity hypotheses — our H2/H3 are both, the second restored by review; completeness relative to hypotheses is her program's shape. Tretmans [Tre96, Tre08]: sound + exhaustive = complete suites for LTS conformance with quiescence; our settle plays $\delta$'s role, our Definition 5 takes a simulation form because [SZC26]'s Lemma 55 is natively an up-to technique. Mutation adequacy [DLS78]; specification mutation [BOY00]; subsumption in mutation analysis [JH11, PAO17]. Executable semantics validated by suites [Fel09, RŞ10]. The exhaustive schedule enumeration is bounded model exploration in the sense standard for acceptance testing of nondeterministic specifications; each scenario's full choice tree here is small enough (max 924) to enumerate outright.

## 11. Limitations and threats to validity

(1) H2/H3 are hypotheses about $\mathbb I$'s text; Example 1 shows H3 unavoidable; the reduction reading (Remark 1) is the claim's honest form. (2) Proofs are rigorous but unmechanized; the finite checks (Lemma 3's table, Theorem 4's matrix) are discharged by an enumeration harness that is itself trusted. (3) For real builds (not the model) schedules are sampled by execution, not enumerated; H4 covers the residue. (4) The M5 scenario constructs its three histories directly and is exercised under the enumerated policies rather than the oracle tree (its nondeterminism spans three system instances); its soundness rests on the §5.3 derivation. (5) Theorem 5 is conditional; run 5 instantiates, not establishes, its antecedent. (6) Adequacy is relative to $F$; Remark 2 delimits what stronger necessity would need and why single-clause deviants cannot supply it.

## 12. Conclusion

The paper's goal — a formalization of the plugin system in which a finite test set is a sufficient and necessary verification condition — is achieved in the following exact sense. Sufficiency: Theorem 3 proves the 32-test suite complete relative to five named hypotheses, of which the audit (H1) is constructed, the scheduler property (H4) and witness (H5) are conventional, and the two structural ones (H2, H3) are the irreducible price of finite testing, with the counterexample displayed. Necessity: Theorem 4 proves each test unremovable for the sufficiency proof, the suite adequate against all twenty-seven single-clause deviant calculi under complete schedule enumeration, and fourteen tests irreplaceable outright relative to that family — and Remark 2 proves the honest boundary of the claim. On this foundation the verification of Cordis is no longer anecdotal: one build passes the suite; the published build fails it at four located clauses; and the distribution layer preserves the verdict on every point tested.

---

## Appendix A. Reproduction

```sh
cd paper/proof
node --test tests/*.test.mjs                        # reference semantics, one policy
MODEL_EXHAUST=1 node --test tests/*.test.mjs        # run 1: ALL schedules per scenario
PROOF_TARGET=cordis node --test tests/*.test.mjs    # run 2: calculus-aligned build
PROOF_TARGET=cordis CORDIS_LIB=…/lib/index.js node --test tests/*.test.mjs   # run 3: any build
node run-necessity.mjs                              # run 4: deviant matrix (exhaustive; exit 0 = K1 + baseline)
PROOF_TARGET=cordis-node node --test tests/*.test.mjs   # run 5: two-node distributed
```

Node $\ge 22$; no dependencies. `MODEL_EXHAUST_REPORT=1` prints per-test exploration sizes (25 scenarios have one schedule; the largest tree is 924; all complete). The TAP parser in run 4 is indentation- and isolation-mode tolerant.

## Appendix B. Table C

The catalog — script, verdict formula, clause, premise vector, soundness source, per test — is `conformance.md` §2 (revision R1), the single maintained copy.

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026. (`../paper.pdf`)
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model based testing with labelled transition systems.* LNCS 4949, 2008.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on test data selection.* IEEE Computer 11(4), 1978.
- [JH11] Y. Jia, M. Harman. *An analysis and survey of the development of mutation testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis et al. *Mutation testing advances.* Advances in Computers, 2017.
- [BOY00] P. E. Black, V. Okun, Y. Yesha. *Mutation operators for specifications.* ASE 2000.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An overview of the K semantic framework.* JLAP 79(6), 2010.
