# A Complete and Minimal Conformance Test Theory for a Calculus of Dynamic Composition

**Companion to:** *A Programming Paradigm for Spatiotemporal Composability* (Shi, Zhang, Cui; `../paper.pdf`, cited as [SZC26]). Numbered references of the form Def. 43, Thm. 63, Table 1 are to [SZC26]; references of the form Definition 3, Theorem 2 are internal.

**Artifacts:** the executable reference semantics, the suite, the deviant harness, and the logs behind every finite check cited below reside in this directory and reproduce with the commands of Appendix A.

---

## Abstract

[SZC26] presents a calculus of dynamic composition with a proved metatheory, and an implementation, Cordis, related to the calculus by a correspondence table (its Table 2) and reference algorithms — but by no proof. We close the gap with a conformance test theory. We formalize the plugin-system interface induced by Table 2 as a labeled transition system with a fixed observation vocabulary, define conformance as observation-simulation up to the calculus's own equivalences, and construct a finite suite $T$ of 32 tests standing in constructive bijection with the clauses of the calculus. We prove: **soundness** — the calculus itself satisfies $T$, each verdict derived from the metatheorems of [SZC26]; **completeness (sufficiency)** — any implementation admitting a faithful abstraction and satisfying formally stated uniformity, scheduling, and witness hypotheses that passes $T$ is simulated by the calculus; and **minimality (necessity)** — the witness map is injective, and against a formally defined family of twenty-seven deviant calculi, each negating one clause, the suite is adequate and irredundant. Applying $T$ verifies one Cordis build completely ($32/32$) and convicts the published build on exactly four obligations, one previously unknown; applying the unchanged $T$ to a two-node distributed deployment reproduces exactly the underlying build's failures, giving the corollary that the distribution layer preserves conformance. The construction also yields three corrections to [SZC26] itself.

---

## 1. Introduction

Dynamic composition frameworks promise that components may be loaded, unloaded, and reconfigured at runtime while the system behaves as if the final configuration had been assembled statically. [SZC26] gives the promise formal content — a small-step calculus whose metatheory (preservation, recovery exactness, ordering, coherence, progress, confluence) is proved — and an implementation whose relation to the calculus is asserted through a correspondence table and reference algorithms. The assertion is not a theorem, and §8 exhibits a shipping build that honors the table's names while violating the calculus's rules.

**Problem.** What does it mean, mathematically, for an implementation to *follow* the calculus, and can a finite set of executable test cases carry that verification with the force of a theorem?

**Approach.** We answer with the classical apparatus of conformance testing [Gau95, Tre96], instantiated so that every object in the statement is defined rather than described: the implementation interface is a labeled transition system (Definition 2); conformance is the existence of an observation simulation into the calculus (Definitions 6–7, Lemma 1); a test suite is a set of scripts with verdict predicates (Definition 10); the hypotheses that any finite-testing argument must make are stated as properties of transition systems (Definitions 12–13), not as prose; sufficiency and necessity are Theorems 3 and 4. Where an argument reduces to finitely many mechanical case checks — realization of premise vectors by catalog scenarios, and the deviant kill matrix — we tabulate the cases, prove representative rows by derivation, and discharge the remainder by executed enumeration, in the tradition of computer-checked finite case analyses.

**Contributions.**

1. A formalization of the [SZC26] §5 plugin-system interface as an instrumented LTS with an explicit observation algebra, and of components as specification-level data at the granularity of Def. 51 (§3).
2. A conformance relation defined by observation simulation up to the calculus's own $\simeq/\approx$, with the abstraction function replacing the informal "Table-2 reading" (§4).
3. A 32-test suite in constructive bijection with the clauses of the calculus, with a **soundness theorem** in which each verdict is derived from a metatheorem of [SZC26] (§5).
4. A **completeness theorem**: passing the suite, together with equivariance, locality, fair scheduling, and the inverse-witness obligation, implies simulation by the calculus (§6). The proof is a case analysis over the ten rules in the style of [SZC26]'s own Table-1 arguments, with the locality lemma playing the role its Lemmas 54–57 play there.
5. A **minimality theorem** over a formally defined family of deviant calculi $\mathbb{S}_{\neg c}$, with derivations for representative deviants and the full matrix by enumeration (§7).
6. Empirical verification of two builds and a two-node deployment; four implementation defects (one new) and three corrections to the paper (§8, §9).

**Non-claims.** The proofs are rigorous mathematics over explicitly stated hypotheses, in the same sense as [SZC26]'s own; they are not mechanized in a proof assistant. Hypotheses H2–H4 concern the implementation and are exactly what testing cannot itself establish; §11 discusses them as threats.

---

## 2. Background: the calculus

We recall from [SZC26] only what the development manipulates, in its notation.

Fix countable, pairwise disjoint sets $K$ (keys), $\mathfrak{N}$ (names), $\mathbb{V}$ (values), $\mathbb{T}$ (effect tags). A **component** is a triple $(d, p, e)$ with $d, p \subseteq K$ finite and $e$ a witnessed effect function (Def. 8, 43); a **fiber** is a tuple $\langle d, p, e, \pi, \sigma, \tau, \theta\rangle$ (Def. 44) with lifecycle states

$$\theta \;\in\; \{\ \mathsf{Inactive}(\zeta),\ \mathsf{Reloading}(i, g, \omega),\ \mathsf{Active}(g, \omega),\ \mathsf{Unloading}(g, \omega, \zeta)\ \},$$

$\zeta \in \{\bot\} \cup \Xi$, $g$ the accumulator, $\omega : d \to \mathfrak{N}$ the committed view, $i$ the remaining iterator (Def. 49, 51). A state $\gamma$ carries a registry $F_\gamma : \mathfrak{N} \rightharpoonup \mathrm{Fibers}$ (Def. 45); the derived coeffect context and target view are

$$\sigma_\gamma = \bigcup\{\sigma_m \mid \theta_m = \mathsf{Active}(-,-)\}, \qquad
\mathrm{target}_n(\gamma) = \begin{cases}\bot & \text{if } \tau_n \vee \neg(\gamma \vDash d_n)\\ (k \in d_n) \mapsto \mathrm{provider}_k(\gamma) & \text{otherwise,}\end{cases}$$

(eq. 40, Def. 46), and $\mathrm{relied}_n(\gamma) \iff \exists m \neq n,\ k \in d_m.\ \mathrm{installed}_m(\gamma) \wedge \omega_m(k) = n$ (Def. 50). The semantics is generated by ten rules (Table 1): O-Insert (premises: freshness, $\pi \in \mathrm{dom}(F_\gamma) \cup \{\mathsf{root}\}$, $\forall m.\ p \cap p_m = \varnothing$), O-Retire (unconditional, writes $\tau_n$), O-Remove (premises $\tau_n$, $\theta_n = \mathsf{Inactive}(-)$, $\forall m.\ \pi_m \neq n$), and the lifecycle rules L-Begin, L-Iter, L-Finish, L-Divert, L-Raise, L-Leave, L-Unload, the last guarded by $\neg\mathrm{relied}_n(\gamma)$. Registration (Def. 47) allows an iteration to perform an O-Insert whose inverse is the corresponding O-Retire. Every step factors as $\gamma^{t+1} = \mathrm{edit}^t(\Psi^t(\gamma^t))$ (eq. 52), with the writes tabulated in Table 1.

The metatheory we invoke: $\simeq$-invariance of the rules (Lemma 55), equivariance under name bijections (Lemma 56), vestigial-entry framing (Lemma 57), well-formedness preservation (Thm. 59), recovery exactness (Thm. 61, Cor. 62), ordering and value fixity (Thm. 63), resolution coherence (Thm. 64), progress and termination (Thm. 66), confluence (Thm. 73). Equalities on states are read up to $\simeq$ (Def. 33) and $\approx$ (Def. 53).

---

## 3. The instrumented interface

### 3.1 Observation algebra

**Definition 1 (events).** The event alphabet is

$$\mathcal{E} \;::=\; \mathsf{app}(n, t) \;\mid\; \mathsf{inv}(n, t) \;\mid\; \mathsf{rd}(n, k, v) \;\mid\; \mathsf{rderr}(n, k, \epsilon) \;\mid\; \mathsf{act}(n) \;\mid\; \mathsf{deact}(n) \;\mid\; \mathsf{val}(n,k)$$

with $n \in \mathfrak{N}$, $t \in \mathbb{T}$, $k \in K$, $v \in \mathbb{V}$, $\epsilon \in \{\mathsf{IA}, \mathsf{UD}\}$ (inactive access, undeclared access). An *observation* is a pair $(w, q)$: $w \in \mathcal{E}^*$ an event word, and $q$ a *quiescent report* — a function assigning each inserted name its status in $\{\mathsf{pend}, \mathsf{load}, \mathsf{act}, \mathsf{fail}, \mathsf{unld}, \mathsf{disp}\}$ and outcome in $\{\bot\} \cup \Xi$, together with the store report $\mathrm{st} : K \rightharpoonup \mathbb{V}$, $\mathrm{st}(k) = \sigma_\gamma(k)$, and the log of refused inputs.

**Definition 2 (plugin system).** A *plugin system* is an LTS $\mathbb{X} = (\Gamma_{\mathbb{X}}, \gamma^0_{\mathbb{X}}, \longrightarrow_{\mathbb{X}})$ with $\longrightarrow_{\mathbb{X}} \subseteq \Gamma_{\mathbb{X}} \times \Lambda \times \mathcal{E}^* \times \Gamma_{\mathbb{X}}$, over the label alphabet $\Lambda = \Lambda_{\mathrm{orch}} \uplus \{\mathsf{life}\}$,

$$\Lambda_{\mathrm{orch}} = \{\mathsf{insert}(\pi, c, \mathit{cfg}),\ \mathsf{retire}(n),\ \mathsf{update}(n,\mathit{cfg}),\ \mathsf{setval}(n,k,v),\ \mathsf{isolate}(k,r),\ \mathsf{intercept}(k,\nu)\},$$

each transition emitting a (possibly empty) event word. A configuration is *quiescent* when no $\mathsf{life}$-transition is enabled and a quiescent report $q(\cdot)$ is defined on it.

**Definition 3 (components as scripts).** A *component script* is $c = (\mathit{name}, d, p, S)$, $S \in \mathrm{Step}^*$,

$$\mathrm{Step} ::= \mathsf{provide}(k,v) \mid \mathsf{track}(t) \mid \mathsf{read}(k) \mid \mathsf{setval}(k,v) \mid \mathsf{register}(c',\mathit{cfg}) \mid \mathsf{raise}(m) \mid \mathsf{raiseUnless}(\mathit{fl},m).$$

**Definition 4 (the specification $\mathbb{S}$).** $\mathbb{S}$ is the plugin system whose configurations are the registries of §2 with each fiber's $e$ a script and each $\mathsf{Reloading}$ iterator a script suffix; whose transitions are the ten rules, one step per rule application, reading each script step as one iteration of Def. 51 with the following instrumentation, where $n$ is the acting fiber and the step executed is $s$:

| rule / step | emitted word |
| --- | --- |
| L-Iter at $s = \mathsf{track}(t)$ | $\mathsf{app}(n,t)$; the inverse composed onto $g$ emits $\mathsf{inv}(n,t)$ when applied |
| L-Iter at $s = \mathsf{provide}(k,v)$ | $\varepsilon$; the inverse (restriction, Def. 23) emits $\varepsilon$ |
| L-Iter at $s = \mathsf{read}(k)$ | $\mathsf{rd}(n,k,v)$ with $v$ per Algorithm 6, or $\mathsf{rderr}(n,k,\epsilon)$ at its rejection lines |
| L-Iter at $s = \mathsf{setval}(k,v)$ | $\mathsf{val}(n,k)$ |
| L-Finish | $\mathsf{act}(n)$ |
| L-Unload | the accumulator's inverse events in application order, then $\mathsf{deact}(n)$ |
| all others | $\varepsilon$ |

Orchestration labels map to O-Insert, O-Retire, the update of §5.2.1, the $\mathcal{A}_k$ operation of Def. 24, and the derivations of Def. 29/31; a label whose rule premises fail is *refused* (logged in $q$, no transition). The quiescent report reads $\theta, \zeta, \sigma_\gamma$ as in Definition 1.

**Definition 5 (scripts, runs, behaviors).** An *orchestration script* $\rho$ is a finite word over $\Lambda_{\mathrm{orch}} \cup \{\mathsf{settle}\}$. A *run* of $\mathbb{X}$ on $\rho$ executes the orchestration labels in order and, at each $\mathsf{settle}$, extends by $\mathsf{life}$-transitions until a quiescent configuration is reached (if ever). Its observation is the concatenated event word together with the final quiescent report. The *behavior set* is

$$\mathrm{obs}_{\mathbb{X}}(\rho) \;=\; \{\, (w, q) \mid \text{some run of } \mathbb{X} \text{ on } \rho \text{ observes } (w,q) \,\}$$

— a set, since $\mathsf{life}$-scheduling is nondeterministic.

### 3.2 Conformance

Write $(w,q) \sim (w',q')$ when $w, w'$ are equal as words and $q, q'$ agree up to $\simeq$ on store reports and equally-labeled statuses/outcomes; this is the reading "up to Def. 33/53" fixed once and used throughout.

**Definition 6 (conformance).** $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$ iff for every script $\rho$: (i) for every $(w,q) \in \mathrm{obs}_{\mathbb{I}}(\rho)$ there is $(w',q') \in \mathrm{obs}_{\mathbb{S}}(\rho)$ with $(w,q) \sim (w',q')$; and (ii) whenever every run of $\mathbb{S}$ on $\rho$ reaches quiescence at each settle point (which is always, by Thm. 66, when $\rho$'s inserts keep $\prec$ acyclic and registrations finite), every run of $\mathbb{I}$ on $\rho$ does as well.

**Proposition 1.** $\mathbf{conf}$ is a preorder.
*Proof.* Reflexivity is immediate. For transitivity let $\mathbb{A} \mathrel{\mathbf{conf}} \mathbb{B} \mathrel{\mathbf{conf}} \mathbb{C}$ and $(w,q) \in \mathrm{obs}_{\mathbb{A}}(\rho)$: clause (i) twice yields $(w'',q'')\in \mathrm{obs}_{\mathbb{C}}(\rho)$ with $(w,q) \sim (w'',q'')$ since $\sim$ is transitive; clause (ii) composes because $\mathbb{B}$'s settles terminate whenever $\mathbb{C}$'s do. $\blacksquare$

**Definition 7 (observation simulation).** Let $A : \Gamma_{\mathbb{I}} \rightharpoonup \Gamma_{\mathbb{S}}$ be partial with $\mathrm{Reach}(\mathbb{I}) \subseteq \mathrm{dom}(A)$. The relation $\mathcal{R}_A = \{(u, \gamma) \mid u \in \mathrm{Reach}(\mathbb{I}),\ \gamma \approx A(u)\}$ is an *observation simulation* when:

- (S0) $A(\gamma^0_{\mathbb{I}}) = \gamma^0$;
- (S1) if $u \xrightarrow{\lambda / w}_{\mathbb{I}} u'$ with $\lambda \in \Lambda_{\mathrm{orch}}$ then $\gamma \xRightarrow{\lambda / w'}_{\mathbb{S}} \gamma'$ for some $\gamma' \approx A(u')$ and $w \sim w'$; and $\lambda$ is refused at $u$ iff refused at $\gamma$;
- (S2) if $u \xrightarrow{\mathsf{life} / w}_{\mathbb{I}} u'$ then $\gamma \xrightarrow{\mathsf{life} / w'}_{\mathbb{S}} \gamma'$ for some $\gamma' \approx A(u')$, $w \sim w'$;
- (S3) if $u$ is quiescent then $A(u)$ is quiescent and $q_{\mathbb{I}}(u) \sim q_{\mathbb{S}}(A(u))$; conversely if every $\mathbb{S}$-run of the pending settle quiesces, $\mathbb{I}$'s settle at $u$ terminates.

**Lemma 1 (simulation soundness).** If some $A$ makes $\mathcal{R}_A$ an observation simulation, then $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$.
*Proof.* Fix $\rho$ and an $\mathbb{I}$-run observing $(w,q)$. By induction on the run's length, using (S0) for the base and (S1)/(S2) for each step, there is an $\mathbb{S}$-run on $\rho$ through configurations $\approx$-related to the $A$-images, emitting a word $\sim w$; the step case is licensed because $\approx$-related $\mathbb{S}$-configurations enable the same rules with $\approx$-related results (Lemma 55 of [SZC26], which proves exactly this $\simeq$-invariance, extended to $\approx$ by its own statement). At the final settle, (S3) gives quiescence of the $A$-image and $q \sim q_{\mathbb{S}}$, so $(w,q) \sim$ an element of $\mathrm{obs}_{\mathbb{S}}(\rho)$, establishing (i); the converse half of (S3) establishes (ii). $\blacksquare$

---

## 4. Clauses, windows, and satisfaction

### 4.1 Windows

For each rule $r$ of Table 1 acting at $n$, define its *window* $W_r(\gamma, n)$: the tuple of exactly the fields $r$'s premises and writes read, as tabulated by [SZC26]'s own reading of Table 1 (Lemmas 54–55): for L-Begin, $(\theta_n, \tau_n, d_n, \{(\theta_m, \sigma_m\!\upharpoonright_{d_n}) \mid m \in \mathrm{dom} F_\gamma\})$; for L-Unload, $(\theta_n, \{\,\omega_m \mid \mathrm{installed}_m\,\}, g_n)$; and so on, one row per rule. Two pointed configurations are *$r$-similar*, written $(\gamma, n) \sim_r (\gamma', n')$, when a bijection $\chi$ of names, keys, values, and tags aligns their windows.

**Lemma 2 (locality and equivariance of $\mathbb{S}$).** For every rule $r$: if $(\gamma, n) \sim_r (\gamma', n')$ via $\chi$, then $r$ is applicable at $(\gamma, n)$ iff at $(\gamma', n')$; and when applicable, the windows of the successors are aligned by $\chi$ and the emitted words correspond under $\chi$.
*Proof.* Premises: each premise of $r$ is a predicate of the window by construction of $W_r$ — e.g. for L-Begin, $\theta_n = \mathsf{Inactive}(\bot)$ and $\mathrm{target}_n(\gamma) \neq \bot$ are functions of $(\theta_n, \tau_n)$ and of which $m$ with $\sigma_m \ni k$ are Active for $k \in d_n$, all in $W_{\text{L-Begin}}$ — and $\chi$ preserves each field. Writes: the step factors as $\mathrm{edit} \circ \Psi$ (eq. 52) where $\mathrm{edit}$ assigns fields of $n$ from window values and $\Psi$ is $\mathrm{id}$, an iteration of $e_n$, or $g_n$; each case reads only the window and commutes with $\chi$ by Lemma 56 of [SZC26] (equivariance) for the name part, with $\chi$ acting on keys/values pointwise, while entries outside the window are inert by Lemma 57 (vestigial framing) and by clause (1) of Lemma 54 ($\sigma_m$ moves only at steps acting on $m$). Emissions: Definition 4's table maps each case to events built from window values. $\blacksquare$

### 4.2 Clauses

**Definition 8 (clauses).** The *clause set* $\mathcal{C}$ consists of: for each rule $r$, the pair of clauses $\langle r{:}\mathsf{prem}\rangle$ and $\langle r{:}\mathsf{act}\rangle$; the coeffect-layer clauses $\langle \mathrm{op} \rangle$ for the operations of Def. 23/24, the realm clauses of Def. 28–29, the interception clause of Def. 31, and the three outcome clauses of Algorithm 6; and the composite clauses $\langle \mathrm{M}_1\rangle$–$\langle\mathrm{M}_5\rangle$, one for each of Thm. 61, 63, 64, 66, 73 read as an observation predicate (their statements quantified over the scenario schemas of §5.2). Overlapping premises shared by several rules (e.g. the target comparison of L-Iter/L-Finish/L-Divert) are one clause each, attributed per Table C.

**Definition 9 (satisfaction).** Let $A$ be as in Definition 7. $\mathbb{I}$ *satisfies* clause $c$ under $A$, written $\mathrm{Sat}_A(c)$:

- $\mathrm{Sat}_A\langle r{:}\mathsf{prem}\rangle$: every $\mathbb{I}$-transition that $A$ maps to an $r$-step at $n$ occurs only where $\mathrm{Prem}_r(A(u), n)$ holds; and each $\lambda \in \Lambda_{\mathrm{orch}}$ is refused at $u$ iff its rule's premises fail at $A(u)$.
- $\mathrm{Sat}_A\langle r{:}\mathsf{act}\rangle$: when such a transition occurs, $A(u') \approx \mathrm{edit}_r(\Psi_r(A(u)))$ per $r$'s Table-1 row, and the emitted word is Definition 4's, under $\sim$.
- $\mathrm{Sat}_A\langle \mathrm{op}/\mathrm{Alg6}/\ldots \rangle$: the operation's defining equation of Def. 23/24/29/31 resp. the outcome of Algorithm 6 holds of $A(u)$, with the prescribed event.
- $\mathrm{Sat}_A\langle \mathrm{M}_i\rangle$: the corresponding metatheorem's observation predicate holds of $\mathbb{I}$'s runs on its schema.
- $\mathrm{Sat}_A(\mathsf{live})$ (one clause): if $\mathrm{Prem}_r(A(u), n)$ holds for some lifecycle $r, n$ and persists along every $\mathbb{I}$-extension in which no transition acts on $n$, then some transition acts on $n$ eventually.

**Theorem 1 (satisfaction implies conformance).** If $\mathrm{Sat}_A(c)$ for all $c \in \mathcal{C}$, then $\mathcal{R}_A$ is an observation simulation; hence $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$.
*Proof.* (S0) is $A(\gamma^0_{\mathbb{I}}) = \gamma^0$, part of $A$'s definition (§6, H1). (S1)–(S2): let $u \to u'$ be a transition, mapped by $A$ to rule $r$ at $n$. By $\mathrm{Sat}\langle r{:}\mathsf{prem}\rangle$, $\mathrm{Prem}_r(A(u), n)$; hence $r$ applies at $A(u)$ in $\mathbb{S}$, producing $\gamma' = \mathrm{edit}_r(\Psi_r(A(u)))$. By $\mathrm{Sat}\langle r{:}\mathsf{act}\rangle$, $A(u') \approx \gamma'$ and the words correspond. For a $\gamma \approx A(u)$ (the relation's second components), Lemma 55 transports applicability and result across $\approx$. Refusals correspond by the second half of $\mathrm{Sat}\langle r{:}\mathsf{prem}\rangle$. The coeffect-layer clauses cover the labels that are derivations rather than rules ($\mathsf{isolate}, \mathsf{intercept}, \mathsf{setval}$) and the read events inside iterations, so every emitted event is accounted. (S3): let $u$ be quiescent. If some lifecycle rule were applicable at $A(u)$, its premises would persist at $u$ (no $\mathbb{I}$-transition occurs at a quiescent $u$ at all), so $\mathrm{Sat}(\mathsf{live})$ would produce a transition — contradiction; hence $A(u)$ is quiescent, and $q_{\mathbb{I}}(u) \sim q_{\mathbb{S}}(A(u))$ because the report fields are exactly window fields preserved by $\mathrm{Sat}\langle\cdot{:}\mathsf{act}\rangle$ along the run (an induction identical in shape to the (S1)/(S2) case). The converse half of (S3): where $\mathbb{S}$'s settle terminates (Thm. 66), non-termination of $\mathbb{I}$'s settle would require an infinite sequence of $\mathbb{I}$-transitions; their $A$-images form, by the (S1)/(S2) cases already established, an infinite $\mathbb{S}$-derivation from a configuration on which every maximal lifecycle sequence is finite — contradicting Thm. 66's termination bound $S(n) \le (K{+}4)(V(n){+}1)$. $\blacksquare$

---

## 5. The suite

### 5.1 Tests

**Definition 10 (test, verdict, passing).** A *test* is a pair $t = (\rho_t, V_t)$: a script over the component data of Definition 3, and a decidable predicate $V_t$ on observations. $\mathbb{I} \models t$ iff $V_t(w,q)$ for every $(w,q) \in \mathrm{obs}_{\mathbb{I}}(\rho_t)$; $\mathbb{I} \models T$ iff $\forall t \in T.\ \mathbb{I} \models t$.

The suite $T$ has 32 tests; Table C (Appendix B) lists for each: its script, its verdict as a first-order predicate over $(w, q)$ in the vocabulary of Definition 1, the clause $w(t) \in \mathcal{C}$ it witnesses, and the premise vector it realizes. Two representative rows, in full:

- $t = \text{R5.1}$: $\rho_t = \mathsf{insert}(\mathsf{root}, P, -);\ \mathsf{settle};\ \mathsf{retire}(P);\ \mathsf{settle}$ with $S_P = \mathsf{track}(a); \mathsf{track}(b); \mathsf{track}(c)$.
  $V_t(w, q) \equiv w \supseteq_{\mathrm{ord}} \mathsf{app}(P,a)\,\mathsf{app}(P,b)\,\mathsf{app}(P,c)\ \wedge\ w \supseteq_{\mathrm{ord}} \mathsf{inv}(P,c)\,\mathsf{inv}(P,b)\,\mathsf{inv}(P,a)$, where $\supseteq_{\mathrm{ord}}$ is subword order. $w(t) = \langle\text{L-Iter/L-Unload}{:}\mathsf{act}\rangle$ (order and LIFO composition).
- $t = \text{R9.1}$: $\rho_t = \mathsf{insert}(\mathsf{root}, P, -); \mathsf{insert}(\mathsf{root}, C, -); \mathsf{settle}; \mathsf{retire}(P); \mathsf{settle}$ with $S_P = \mathsf{provide}(k, v_0); \mathsf{track}(p_1)$, $S_C$ declaring $d_C = \{k\}$ with one tracked effect whose inverse performs $\mathsf{read}(k)$.
  $V_t(w,q) \equiv \mathsf{rd}(C,k,v_0) \in w \ \wedge\ \mathsf{rd}(C,k,v_0) <_w \mathsf{inv}(P,p_1) \ \wedge\ q(P) = \mathsf{disp}$, where $<_w$ is precedence in $w$. $w(t) = \langle\text{L-Unload}{:}\mathsf{prem}\rangle$ (the guard $\neg\mathrm{relied}$).

### 5.2 Soundness

**Theorem 2 (soundness: $\mathbb{S} \models T$).** The calculus satisfies every test, under every schedule.
*Proof.* For each $t$, $V_t$ is an instance of a metatheorem of [SZC26] at $\rho_t$'s scenario; Table C's fourth column names the theorem, and we derive the two representatives (the rest are identical in kind):

*R5.1.* Any schedule on $\rho$: O-Insert; L-Begin (premises hold: fresh Inactive($\bot$), $d_P = \varnothing$ so $\mathrm{target} = \varnothing \ne \bot$); three L-Iters — by Definition 4 emitting $\mathsf{app}(P,a), \mathsf{app}(P,b), \mathsf{app}(P,c)$ in $S_P$'s order, each composing its inverse as $g \mapsto g_x \circ g$ (Table 1's $g \circ h$ read in application order), so after the third, $g = g_c \circ g_b \circ g_a$... — precisely, Table 1 composes $g' = g \circ h$ with $h$ the new inverse, giving $g = g_a \circ g_b \circ g_c$ *as a function composition applied right-to-left*, i.e. $g_c$ runs first; L-Finish; then $\mathsf{retire}$ sets $\tau_P$, L-Leave, and L-Unload (guard vacuous: no $\omega_m$ names $P$) applies $g$, emitting $\mathsf{inv}(P,c), \mathsf{inv}(P,b), \mathsf{inv}(P,a)$ — Thm. 16's LIFO order. Both subword conjuncts hold; no schedule choice occurs (one fiber).

*R9.1.* After the first settle both fibers are Active with $\omega_C(k) = P$ (L-Begin's premise via Def. 46). $\mathsf{retire}(P)$ sets $\tau_P$, so $\mathrm{target}_P = \bot \neq \omega_P$: L-Leave puts $P$ in Unloading; then $\sigma_\gamma$ loses $\sigma_P$ (eq. 40), so $\mathrm{target}_C = \bot \neq \omega_C$: L-Leave puts $C$ in Unloading. Now L-Unload($P$) is *blocked*: $\mathrm{installed}_C$ holds and $\omega_C(k) = P$, so $\mathrm{relied}_P$; the only applicable rule is L-Unload($C$) (its guard is vacuous), which applies $C$'s accumulator — its single inverse performs $\mathsf{read}(k)$: Algorithm 6 finds $k \in \mathrm{dom}(\omega_C)$ — the committed view survives until $C$'s own L-Unload completes (Table 1: L-Unload discards $\omega$ as its write, after $\Psi = g$) — and reads $P$'s binding, still present since no inverse of $P$ has run; so $\mathsf{rd}(C,k,v_0)$ is emitted (value fixity: Thm. 63(3)). Only then does $\neg\mathrm{relied}_P$ hold and L-Unload($P$) emit $\mathsf{inv}(P,p_1)$; O-Remove disposes $P$ ($q(P) = \mathsf{disp}$). Every schedule takes these steps in this order because at each point at most one lifecycle rule is enabled — which is Thm. 63(2)'s content, $u' < u$, at this scenario. $\blacksquare$ *(Executed corroboration: run 1, four policies, $32/32$.)*

During construction this theorem failed twice on draft verdicts, in both cases convicting the draft: an R3.2 draft asserted an inverse ordering between parent and child that §4.3.1 of [SZC26] leaves open, and an M3 draft issued an $\mathsf{insert}$ whose O-Insert premise was false at that instant (§9, PB-3). We record this as evidence that Theorem 2 is a genuine gate, not a formality.

**Definition 11 (witness map).** $w : T \to \mathcal{C}$ per Table C. By construction $w$ is injective, and its image meets every clause of $\mathcal{C}$ (*onto*-ness over the catalog's clause enumeration); both facts are checked row-by-row in Table C.

**Lemma 3 (realization).** For every rule $r$ and every truth assignment $\beta$ to $\mathrm{Prem}_r$ consistent with reachability in $\mathbb{S}$, some $t \in T$ with $w(t) \in \{\langle r{:}\mathsf{prem}\rangle, \langle r{:}\mathsf{act}\rangle\}$ reaches, during its unique-up-to-$\approx$ $\mathbb{S}$-run, a pointed configuration whose window realizes $\beta$; and $V_t$ constrains exactly the behavior Definitions 8–9 attach to $r$ at $\beta$: firing with $r$'s writes and emissions where $\beta = \mathbf{1}$, non-firing (observed through O1 status or O3 refusal) where a premise is false.
*Proof.* Finite inspection; Table C's fifth column lists, for each rule, which tests realize which $\beta$. We verify the L-Begin row here: its premise vector ranges over (fresh-$\bot$ outcome; unretired; satisfaction). $\beta = (1,1,1)$: R1.1's run reaches $(\gamma, P)$ with $\theta_P = \mathsf{Inactive}(\bot)$, $\neg\tau_P$, $\mathrm{target}_P = \varnothing$, and $V$ demands $\mathsf{act}(P)$ and the O1 status $\mathsf{act}$ — firing with writes. Satisfaction false: R4.1 ($d_C = \{k\}$, no provider; $V$ demands status $\mathsf{pend}$ and $\mathsf{app}(C,c_1) \notin w$), sharpened by R4.3 (provider present but Reloading at the decisive instant: $V$ demands $\mathsf{act}(P) <_w \mathsf{app}(C, c_1)$, i.e. non-firing while the provider is not Active). Outcome $\xi$: R4.4 ($V$ demands one $\mathsf{app}$ only and status $\mathsf{fail}$ across a settle). Retirement: R2.2 (retired while pending: no $\mathsf{app}$ ever). The remaining rows are checked the same way and tabulated. $\blacksquare$

---

## 6. Completeness

### 6.1 Hypotheses, stated formally

- **H1 (abstraction).** There is a map $A : \mathrm{Reach}(\mathbb{I}) \to \Gamma_{\mathbb{S}}$ with $A(\gamma^0_{\mathbb{I}}) = \gamma^0$, a tagging of every $\mathbb{I}$-transition by the rule it implements, and preservation of the observation surfaces: $q_{\mathbb{I}}(u) = q_{\mathbb{S}}(A(u))$ on quiescent $u$, event emissions as tagged, orchestration labels mapped identically. *(Constructed, not assumed, for the systems under test: the adapter audit exhibits $A$ — fiber-by-field per Table 2 with the PB-1 correction — and the tagging; §8.)*
- **H2 (uniformity = equivariance + locality).** (a) $\longrightarrow_{\mathbb{I}}$ is equivariant under bijections $\chi$ of $\mathfrak{N}, K, \mathbb{V}, \mathbb{T}$ fixing the finitely many reserved constants; (b) for every rule $r$: whether an $r$-tagged transition is enabled at $(u, n)$, and its effect and emissions on the window, depend only on $W_r(A(u), n)$ — the implementation-side counterpart of Lemma 2. *(This is Gaudel's uniformity hypothesis [Gau95] in the concrete form our proof consumes; it is exactly what finite testing cannot itself establish — Remark 1.)*
- **H3 (scheduling).** $\mathbb{I}$'s scheduler is fair — a persistently enabled fiber is eventually acted on — and its settle procedure terminates exactly on quiescent configurations (sound and complete quiescence detection).
- **H4 (witness).** Inverses of test components revert their tracked effects and emit their $\mathsf{inv}$ events — true by construction of Definition 3's $\mathsf{track}$; what remains on $\mathbb{I}$ is composing and invoking them, which is observable and constrained by the verdicts.

**Theorem 3 (completeness / sufficiency).** Under H1–H4: $\mathbb{I} \models T \implies \mathrm{Sat}_A(c)$ for every $c \in \mathcal{C}$ — hence, by Theorem 1, $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$.
*Proof.* Suppose some clause fails; we derive $\mathbb{I} \not\models T$.

*Case $c = \langle r{:}\mathsf{prem}\rangle$.* There is a reachable $u$ and an $r$-tagged transition at $n$ with some premise $p$ false at $(A(u), n)$; let $\beta$ be the window's premise vector. If $\beta$ is reachably consistent in $\mathbb{S}$, Lemma 3 yields $t$ with a run of $\rho_t$ reaching $(\gamma_t, n_t)$ realizing $\beta$ via some $\chi$; by H2(a) transport $\mathbb{I}$'s violating transition along $\chi$, and by H2(b) shrink its context to $\rho_t$'s (the fields outside $W_r$ differ, and by locality do not matter): the transported transition is enabled in $\mathbb{I}$'s run of $\rho_t$ at the realizing instant. Its occurrence produces the observable Lemma 3 says $V_t$ forbids at $\beta$ — an $\mathsf{app}$/status/emission where the verdict demands absence, or a non-refusal where it demands refusal — so $\mathbb{I} \not\models t$. If $\beta$ is not reachably consistent in $\mathbb{S}$, then already the *reachability* of $u$'s window requires a prior clause violation (the fields of $W_r$ are written only by rules, Lemma 54), and the argument applies to the earliest violated clause along $u$'s history, which exists since $A(\gamma^0_{\mathbb{I}}) = \gamma^0$ is reachably consistent.

*Case $c = \langle r{:}\mathsf{act}\rangle$.* An $r$-tagged transition fires with premises true but wrong writes or emissions. The discrepancy is a window discrepancy (writes land in $W_r$; emissions are functions of it — Definition 4). Transport as above to the Lemma-3 instance whose verdict asserts $r$'s writes at $\beta = \mathbf{1}$ positively: the discrepancy violates one of $V_t$'s conjuncts — the status equation (O1), the event word's required letters or their order (O2: e.g. LIFO order for L-Unload's $\Psi = g$; the committed-read value for Algorithm 6's line), or the store report. So $\mathbb{I} \not\models t$.

*Case $c = \langle\mathrm{op}\rangle$, Algorithm-6 clauses.* Identical, with Lemma 3 replaced by the direct catalog instances C1–C5 whose verdicts are the operations' defining equations at both outcomes (e.g. C5.3 demands the $\mathsf{IA}$ error exactly where line 5 of Algorithm 6 rejects, C5.1 the $\mathsf{UD}$ error at line 6).

*Case $c = \mathsf{live}$.* A persistently enabled $(r, n)$ never acted on. Under H3's fairness this cannot occur for the scheduler's own reasons, so the enabling condition itself must be mis-evaluated — a $\langle r{:}\mathsf{prem}\rangle$ discrepancy, handled above; while a settle that fails to terminate on a quiescent-in-$\mathbb{S}$ scenario directly fails the test containing that settle (every test ends in one, and H3 makes settle termination equivalent to quiescence).

*Case $c = \langle\mathrm{M}_i\rangle$.* $\mathrm{Sat}\langle\mathrm{M}_i\rangle$ is quantified over the scenario schema that $\rho_{\mathrm{M}_i}$ instantiates (independent pairs; $\prec$-chains; replacement round-trips; $\prec$-cycles; permuted histories). A violation at some instance of the schema transports by H2 to the catalog instance — the schemas were chosen closed under H2's transports: their windows involve at most four fibers and two keys, the catalog instance's size — where it violates $V_{\mathrm{M}_i}$ verbatim (the verdict *is* the predicate). $\blacksquare$

**Remark 1 (rôle and cost of H2).** H2 cannot be dropped: for any finite $T$, an implementation that behaves correctly except on a key name absent from $T$'s scripts passes $T$ and violates conformance; such an $\mathbb{I}$ simply fails H2(a). The theorem's content is thus a *reduction*: conformance of an arbitrary implementation reduces to (i) passing $T$ — mechanical — plus (ii) H1's audit and H2's uniformity — properties of the implementation's text, not of its behavior, and the natural residue for code review or verification. This division of labor is precisely Gaudel's [Gau95]; we have only made (ii) concrete enough to point at the code that discharges it.

---

## 7. Necessity

**Definition 12 (deviants).** For a clause $c \in \mathcal{C}$, the *deviant* $\mathbb{S}_{\neg c}$ is the plugin system obtained from Definition 4 by negating $c$ alone, per the following table (excerpt; full table in `src/model.mjs` with one switch per row):

| $c$ | $\mathbb{S}_{\neg c}$ |
| --- | --- |
| $\langle$L-Unload:prem$\rangle$ (guard) | premise $\neg\mathrm{relied}_n(\gamma)$ replaced by $\top$ |
| $\langle$L-Iter/L-Unload:act$\rangle$ (LIFO) | accumulator composed $h \circ g$ (application order) |
| $\langle$L-Begin:prem$\rangle$ (satisfaction) | $\gamma \vDash d_n$ deleted from the premise |
| $\langle$Def 45$\rangle$ (Active-only $\sigma_\gamma$) | union taken over installed fibers |
| $\langle$L-Begin:prem$\rangle$ ($\xi$ latch) | $\mathsf{Inactive}(\zeta)$ matched for any $\zeta$ |
| $\langle$Alg 6 line 5$\rangle$ | the declared-but-uncommitted rejection deleted |
| … (27 rows) | … |

**Theorem 4 (necessity).** (a) *Structural:* $w$ is injective and onto the clause enumeration (Definition 11), so for every $t$, $T \setminus \{t\}$ leaves $w(t)$ unwitnessed and Lemma 3's realization — hence Theorem 3's case for $w(t)$ — fails. (b) *Adequacy:* for every deviant, $\mathbb{S}_{\neg c} \not\models T$. (c) *Exclusive witness:* for 14 clauses $c$, $\mathbb{S}_{\neg c} \models T \setminus w^{-1}(c)$ — the designated test is the only one that convicts. (d) Consequently no proper subset of $T$ is both adequate for $\{\mathbb{S}_{\neg c}\}_{c}$ and onto $\mathcal{C}$.
*Proof.* (a) is Definition 11's row check. (b), (c) are $27$ resp. $27 \times 32$ claims of the form "$\mathbb{S}_{\neg c}$'s runs on $\rho_t$ (do not) all satisfy $V_t$", each a finite derivation in the deviant's rules; we derive one of each and discharge the rest by executed enumeration over both fifo and lifo policies (run 4; enumeration is exact, not sampled, for these scenarios, since at every configuration of every $\rho_t$ at most four fibers are enabled and the policies together cover the branch orders the verdicts distinguish — where they did not, the matrix run showed it and the policy set was extended).

*Sample for (b), $c = \langle$L-Unload:prem$\rangle$:* in $\mathbb{S}_{\neg c}$ run $\rho_{\text{R9.1}}$. As in Theorem 2's derivation, after $\mathsf{retire}(P)$ both $P$ and $C$ reach Unloading; but now L-Unload($P$) is enabled *concurrently* with L-Unload($C$), and under the fifo policy the scan meets $P$ first: $\Psi = g_P$ emits $\mathsf{inv}(P,p_1)$ before $C$'s inverse performs its read — indeed the subsequent $\mathsf{read}(k)$ finds $P$'s binding withdrawn and emits $\mathsf{rderr}(C,k,\mathsf{IA})$. Both conjuncts of $V_{\text{R9.1}}$ fail. Hence $\mathbb{S}_{\neg c} \not\models \text{R9.1}$.

*Sample for (c), $c = \langle$LIFO$\rangle$:* $\mathbb{S}_{\neg c}$ differs only in inverse order; on every $\rho_t$ other than R5.1 either at most one tracked inverse exists per fiber or the verdict constrains membership and cross-fiber order but not intra-fiber order (inspect Table C's verdicts: R9.1 orders $C$'s read against $P$'s inverse, not $P$'s inverses among themselves; M2 orders $\mathsf{deact}$ letters and A's inverse against them; …), so all other verdicts hold; on $\rho_{\text{R5.1}}$ the emitted inverse word is $\mathsf{inv}(P,a)\,\mathsf{inv}(P,b)\,\mathsf{inv}(P,c)$, violating $V_{\text{R5.1}}$'s second conjunct. Hence R5.1 alone convicts. $\blacksquare$

**Remark 2 (the 18 shielded witnesses).** For the remaining 18 clauses, no *single-clause* deviant can be convicted by its designated test alone: those clauses are load-bearing — negating L-Begin's satisfaction premise, say, perturbs every scenario with a dependency — so their deviants are convicted by several tests at once (the matrix lists the kill sets). This is the subsumption phenomenon of mutation analysis [PAO17], and it is a property of the *clause structure*, not a defect of the suite: irredundancy for those tests rests on Theorem 4(a), which is exact. Two candidate deviants were discarded during construction because they are *observationally vacuous* — provably so: a value-compared target view never diverges from the provider-compared one under the single-provider discipline plus the guard, and a retire-that-flushes-pending-work is cancelled by L-Divert before any iteration lands (both little propositions verified on the model). Their vacuity is a small self-healing result about the calculus that the exercise surfaced.

---

## 8. Empirical verification

**Targets.** (i) the reference semantics $R$ (soundness control); (ii) **Cordis-aligned** — the vendored build carrying the calculus-alignment fixes of the prior targeted catalog (`paper-review/`, GAP-1..9); (iii) **Cordis-upstream** — `@deepseek-ai/cordis` 4.0.1 as published; (iv) upstream deployed as **two nodes** joined by `@rebuilding/cordis-node` (in-process transports, mutual mounts, inserts alternating across nodes, observation from node A through projection).

| Target | Result |
| --- | --- |
| Reference semantics (4 policies) | $32/32$ |
| Cordis-aligned | $\mathbf{32/32}$ |
| Cordis-upstream 4.0.1 | $28/32$ |
| Two-node distributed (upstream) | $28/32$ — the same four |

**Upstream divergences.** R9.1 and M2 — the L-Unload guard implemented one level too low, provider inverses racing dependents' teardown (reproduces GAP-1/GAP-2; the observed words realize the $\mathbb{S}_{\neg\mathrm{guard}}$ derivation of Theorem 4 almost verbatim, which is what a conformance theory predicts a guard-less implementation must emit). R1.4 — declared disjointness unenforced at insertion (GAP-6). RU.1 — **new**: after a failed first activation, a later $\mathsf{update}$ of the recovered, Active fiber releases the first episode's error as a process-level unhandled rejection; §4.3.4 requires $\xi$ recorded on the fiber and nothing escaping.

**Theorem 5 (distribution preserves conformance).** If $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$ and the distribution layer $D$ satisfies the Distribution Equivalence Contract (`cordis-node/docs/equivalence.md`: placement over nodes is observationally equivalent to single-node execution on the P1 vocabulary, links healthy), then $D(\mathbb{I}) \mathrel{\mathbf{conf}} \mathbb{S}$.
*Proof.* The contract gives $\mathrm{obs}_{D(\mathbb{I})}(\rho) \sim \mathrm{obs}_{\mathbb{I}}(\rho)$ for every $\rho$ in the suite's vocabulary — i.e. $D(\mathbb{I}) \mathrel{\mathbf{conf}} \mathbb{I}$ with Definition 6 read over that vocabulary — and $\mathbf{conf}$ composes by Proposition 1. $\blacksquare$
*Empirical check:* the unchanged suite against the two-node deployment fails exactly the underlying build's four obligations; the difference set attributable to $D$ is empty. Cross-node execution is real: placement alternates, so R9.2's provider activates on node A with its dependent on node B, satisfied through projection.

## 9. Findings about the paper

- **PB-1 (Table 2 erratum).** Table 2 maps Def. 23's $\mathrm{set}(k,v)$ to `ctx.set`; the primitive with $\mathrm{set}$'s precondition ($k \notin \mathrm{dom}\,\sigma$) and inverse is `ctx.provide`, while `ctx.set` is an $\mathcal{A}_k$ operation (Def. 24). H1's abstraction uses the corrected row.
- **PB-2 (internal contradiction).** For an in-place overwrite by an Active provider, §5.1.3 prescribes *not observed* while Thm. 63(3)'s episode-constancy forces *observed replacement* if the operation enters the transition system at all; the calculus is silent (its rules give an Active fiber no operations — the prior catalog's GAP-7). Test C2.1 pins the disjunction any extension must satisfy — neutral, or a complete withdraw–reinstall; never a torn episode — and records each build's branch. The paper should strike the §5.1.3 sentence or scope Thm. 63(3).
- **PB-3 (Algorithm 10 races its premise).** O-Insert's disjointness premise makes replacement a staged retire–drain–remove–insert; Algorithm 10 calls `dispose()` and `use()` back-to-back, relying on the dynamic-conflict fail-safe winning a scheduler race. The reference semantics loses that race under the lifo policy, producing a latched spurious failure. The staged form (used by M3) is the one whose premises hold at every step.

## 10. Related work

Gaudel's theory of testing from algebraic specifications [Gau95] contributes the architecture — finite suites complete relative to named testability hypotheses; our H2 is her uniformity hypothesis in windowed form, and Lemma 2/H2's split (proved for $\mathbb{S}$, hypothesized for $\mathbb{I}$) makes the asymmetry explicit. Tretmans' ioco [Tre96, Tre08] contributes soundness/exhaustiveness for LTS conformance with quiescence; our settle observation plays $\delta$'s role, and our Definition 7 is a simulation formulation rather than a trace one because the calculus's own $\simeq$-invariance lemma (its Lemma 55) is exactly the up-to technique simulation needs. Mutation adequacy originates with [DLS78]; deviants of an executable *specification* follow specification-mutation [BOY00], and the subsumption structure of Remark 2 is documented in the surveys [JH11, PAO17]. Executable semantics validated against suites is the methodology of semantics engineering [Fel09] and K [RŞ10]. Conformance suites without completeness theorems (test262 et al.) and mechanized metatheory without implementation conformance are the two adjacent practices this work bridges for a dynamic-composition calculus; we know of no prior conformance *theorem* for a plugin-system runtime.

## 11. Limitations and threats to validity

(1) H2 is a hypothesis about $\mathbb{I}$'s text; Remark 1 shows it is unavoidable and locates the residue for review. (2) The proofs are mathematics, not mechanized derivations; the finite checks (Lemma 3's table, Theorem 4's matrix) are discharged by executed enumeration — exact for the stated scenarios, but trusting the harness that enumerates. (3) H3's settle is sound/complete quiescence detection by hypothesis; a scheduler with unbounded internal chatter would stall it. (4) The event word is observed through synchronous instrumentation (H1); batching implementations could permute within $\approx$. (5) Theorem 5 inherits the equivalence contract's boundary; run 5 used in-process transports (the contract's own multi-process lab covers TCP). (6) Adequacy is relative to the deviant family; faults outside all single-clause negations are constrained only by Theorem 3's hypotheses, not by Theorem 4.

## 12. Conclusion

"Does the implementation follow the calculus?" is, made precise, the conjunction of one audit (H1), one uniformity property (H2), and a finite, executable judgment ($\mathbb{I} \models T$) that this paper proves complete and minimal for [SZC26]'s calculus. The theory located four defects in a shipping build, proved a second build conformant relative to the stated hypotheses, transferred the verdict unchanged across a distribution layer, and returned three corrections to the source paper — including one place where its algorithm races its own premise, found not by testing the implementation but by running the calculus against itself.

---

## Appendix A. Reproduction

```sh
cd paper/proof
node --test tests/*.test.mjs                       # run 1: reference semantics (MODEL_ORDER=fifo|lifo|random, MODEL_SEED=…)
PROOF_TARGET=cordis node --test tests/*.test.mjs   # run 2: calculus-aligned build
PROOF_TARGET=cordis CORDIS_LIB=…/lib/index.js node --test tests/*.test.mjs   # run 3: any build
node run-necessity.mjs                             # run 4: deviant matrix (adequacy, exclusivity, minimality)
PROOF_TARGET=cordis-node node --test tests/*.test.mjs   # run 5: two-node distributed
```

Node $\ge$ 22, no dependencies; build paths in `src/target.mjs`.

## Appendix B. Table C — the catalog

The full 32-row catalog (script, verdict predicate, witnessed clause, premise vector realized, soundness source) is maintained in `conformance.md` §2 with the engineering details of adapters and deviants in its §§4–6; the two rows displayed in §5.1 are representative of the level of formality of every row.

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026. (`../paper.pdf`)
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model based testing with labelled transition systems.* In *Formal Methods and Testing*, LNCS 4949, 2008.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on test data selection.* IEEE Computer 11(4), 1978.
- [JH11] Y. Jia, M. Harman. *An analysis and survey of the development of mutation testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis, Y. Jia, M. Harman, et al. *Mutation testing advances: an analysis and survey.* Advances in Computers, 2017.
- [BOY00] P. E. Black, V. Okun, Y. Yesha. *Mutation operators for specifications.* ASE 2000.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An overview of the K semantic framework.* J. Logic and Algebraic Programming 79(6), 2010.
- [vG90] R. J. van Glabbeek. *The linear time – branching time spectrum.* CONCUR '90, LNCS 458, 1990.
