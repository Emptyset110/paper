# A Finite Characterization of Plugin-System Conformance for Dynamic Composition

*Living manuscript (Markdown; LaTeX math). The acmart shell for final typesetting is `acm/main.tex`. Internal references of the form Def. 43, Thm. 66, Table 1 are to the source paper [SZC26] (`../paper.pdf`); numbered items without that prefix are this paper's.*

---

## Abstract

The calculus of dynamic composition of Shi, Zhang, and Cui [SZC26] carries a proved metatheory — revertible effects, reactive coeffects, a guarded component lifecycle, and theorems from recovery exactness to confluence — and an implementation, Cordis, related to the calculus by a correspondence table and reference algorithms, but by no proof. We supply the missing verification as a theorem about testing. We formalize the plugin-system interface induced by the paper's own correspondence table as an instrumented labeled transition system with a fixed observation vocabulary, and prove first that *no* finite black-box suite characterizes conformance over unrestricted implementations. We then define the auditable class of **clause-factored** implementations, whose rule decisions factor through a finite alphabet of **atomic signatures** — the occurrence-level decomposition of each rule's window, with unbounded registries entering only through per-key and per-witness occurrences — and construct, for every reachable signature, a canonical experiment. The resulting finite suite $T^\star$ characterizes conformance on this class:

$$\mathbb I \in \mathfrak I_{\mathrm{CF}} \implies \big(\, \mathbb I \mathrel{\mathbf{conf}} \mathbb S \iff \mathbb I \models T^\star \,\big).$$

The proof is by hand, in the style of the source paper: a factorization lemma showing the calculus is itself clause-factored; transport and observation-reflection lemmas (the latter provably *false* without transition certificates: we exhibit a rule aspect that is unobservable in the event-and-report vocabulary on every script); a shortest-counterexample safety argument; and a termination argument by ranking that, en route, **strengthens the source paper's progress theorem by deleting its acyclicity hypothesis**. The signature tables are enumerated in full (92 occurrences, 86 reachable, 6 proved unrealizable at the interface). An exhaustive-schedule test harness grounds the theory: applying the concrete 32-obligation suite to the current Cordis TypeScript implementation verifies one build on every obligation under complete enumeration of each scenario's schedule tree, convicts the published build on exactly four (one defect previously unknown), and finds zero divergence attributable to a two-node distributed deployment. The construction also returns three corrections to the source paper itself.

---

## 1. Introduction

Dynamic composition frameworks promise that components can be loaded, unloaded, and reconfigured at runtime while the system behaves as if the final configuration had been assembled statically. [SZC26] gives this promise formal content: a small-step calculus of components, fibers, and a guarded lifecycle, with a metatheory proving preservation, recovery exactness, ordering, coherence, progress, and confluence. Its §5 asserts that the Cordis runtime implements the calculus, through a correspondence table (Table 2) and ten reference algorithms. The assertion is not a theorem. Nothing in [SZC26] excludes an implementation that matches Table 2 on names and violates Table 1 on behavior — and §8 exhibits a shipping build that does exactly that.

**The question.** What would it mean, mathematically, to *verify* that an implementation follows the calculus — and can a *finite* set of executable test cases carry that verification as a sufficient *and* necessary condition, rather than as anecdote?

**The obstruction.** For unrestricted implementations the answer is no, by a classical diagonalization made precise in Theorem 1: a black-box implementation may agree with the specification on every name, key, and configuration size occurring in a finite suite and deviate on a fresh one. Any honest finite characterization must name the structural hypothesis that closes this gap. The testing literature has known this since Gaudel [Gau95]: finite completeness is always relative to *uniformity* and *regularity* hypotheses. Our contribution is to give those hypotheses exact, auditable content for the dynamic-composition calculus, and then to prove the biconditional they enable.

**The idea.** Each rule of the calculus reads its state through a bounded set of *logical atoms*: lifecycle-state tests, retirement, equality of committed and target views, per-key satisfaction, existential witnesses for conflict, reliance, and childlessness. Operations on unbounded structures decompose pointwise (per key) or through witnesses (per edge). After names, keys, values, and tags are normalized, each rule's window collapses to a finite multiset of *occurrences* drawn from a finite alphabet $\Sigma_r$. A *clause-factored* implementation is one whose rule decisions are a lift of a per-occurrence decision table $f_r^{\mathbb I} : \Sigma_r \to \mathrm{Decision}_r$, equivariantly and without hidden dependence on registry size, spelling, or allocation order. For such implementations, one canonical experiment per reachable signature suffices — and is necessary — to pin the entire behavior.

**Contributions.**

1. A formalization of the plugin-system interface of [SZC26] §5 as an instrumented LTS with events, refusals, transition certificates, quiescent reports, and divergence; conformance as termination-sensitive observation equivalence with rule-level bisimulation (§3).
2. An impossibility theorem for unrestricted finite testing, and the clause-factored implementation class $\mathfrak I_{\mathrm{CF}}$ whose obligations CF1–CF7 are stated as checkable semantic properties, not slogans (§4).
3. The atomic-signature decomposition $\kappa_r : W_r \to \mathcal M_{\mathrm{fin}}(\Sigma_r)$ with fully enumerated alphabets — 92 occurrences across the ten rules and the coeffect layer, 86 reachable with canonical experiments, 6 proved interface-unrealizable — and the finite characteristic suite $T^\star$ (§5).
4. The characterization theorem $\mathbb I \in \mathfrak I_{\mathrm{CF}} \Rightarrow (\mathbb I \mathrel{\mathbf{conf}} \mathbb S \iff \mathbb I \models T^\star)$, proved by hand: factorization ($\mathbb S \in \mathfrak I_{\mathrm{CF}}$), transport, observation reflection, shortest-counterexample safety, and ranking-based termination (§6). Two byproducts are of independent interest: a *masking* proposition showing reflection is false in the certificate-free vocabulary (§6.3), and a progress theorem that removes the acyclicity hypothesis of [SZC26] Thm. 66 (§6.5).
5. An executable grounding: a reference semantics with an enumerable scheduling oracle (every test scenario's complete schedule tree explored; the largest has 924 schedules), a 27-member semantic deviant family with its kill matrix, and a bounded state-space explorer and Lean 4 mechanization in progress, reported with exact status (§7).
6. An evaluation of the current Cordis TypeScript implementation: one build passes all 32 obligations; the published `@deepseek-ai/cordis` 4.0.1 fails exactly four, one previously unknown; a two-node distributed deployment fails exactly the same four (§8). Three corrections to [SZC26] itself (§9).

**Non-claims.** The proofs are rigorous mathematics in the style of the source paper, not machine-checked derivations; the mechanization track and its exact status are reported in §7. Membership of a concrete codebase in $\mathfrak I_{\mathrm{CF}}$ is an audit obligation, not a testable property; the evaluation separates what the suite establishes from what the audit does.

---

## 2. Background and Motivation

### 2.1 The calculus of dynamic composition

We recall from [SZC26] only what the development manipulates, in its notation. A *component* is a triple $(d, p, e)$: a coeffect specification $d \subseteq K$ (keys read), a provision declaration $p \subseteq K$ (keys written), and a witnessed effect function $e$ carrying its own inverse ([SZC26] Defs. 8, 43). A *fiber* $\langle d, p, e, \pi, \sigma, \tau, \theta\rangle$ instantiates a component under parent $\pi$ with its own table $\sigma$, retirement flag $\tau$, and lifecycle state

$$\theta \in \{\mathsf{Inactive}(\zeta),\ \mathsf{Reloading}(i,g,\omega),\ \mathsf{Active}(g,\omega),\ \mathsf{Unloading}(g,\omega,\zeta)\},$$

where $g$ is the inverse accumulator, $\omega : d \to \mathfrak N$ the committed resolution, $i$ the remaining effect iterator, and $\zeta \in \{\bot\} \cup \Xi$ an outcome (Defs. 44, 49, 51). A state $\gamma$ carries a registry $F_\gamma$ of named fibers; the derived coeffect context is the union of *Active* tables only, $\sigma_\gamma = \bigcup \{\sigma_m \mid \theta_m = \mathsf{Active}(-,-)\}$, and the target view $\mathrm{target}_n(\gamma)$ maps each declared key to its provider, or is $\bot$ if $n$ is retired or a key lacks an Active provider (Def. 46). Ten rules generate the semantics (Table 1): O-Insert (freshness; live parent; declared disjointness $\forall m.\ p \cap p_m = \varnothing$), O-Retire, O-Remove (retired, Inactive, childless), and seven lifecycle rules: L-Begin commits $\omega$ where the target is defined; L-Iter runs one iteration against the committed view, composing its inverse LIFO; L-Finish reaches Active; L-Divert aborts a transition whose target turned; L-Raise routes a failing iteration through recovery to $\mathsf{Inactive}(\xi)$; L-Leave stops providing; L-Unload — guarded by $\neg\mathrm{relied}_n(\gamma)$: no installed fiber still resolves a key to $n$ — applies the accumulator and discards $\omega$. An iteration may *register* a child, whose retirement is that iteration's inverse (Def. 47). The metatheory we build on: rule invariance under the observational equivalences (Lemma 55), equivariance (Lemma 56), framing (Lemmas 54, 57), ordering and value fixity (Thm. 63), progress with the measure $S(n) \le (K{+}4)(V(n){+}1)$ (Thm. 66), and confluence (Thm. 73).

### 2.2 The verification gap

[SZC26] §5 maps the calculus onto Cordis: `ctx.plugin` for insertion, `fiber.dispose` for retirement, `ctx.provide`/`get`/`set` for the coeffect operations, `ctx.effect` for tracked effects, a committed per-fiber store with a proxy access walk (Algorithm 6) for the read discipline, and a dependent-await (Algorithm 5) for the unload guard. A prior targeted audit cataloged nine places where the shipped runtime and the calculus disagree, five of which were fixed in a vendored build. What was missing is the other direction: a principled argument that any finite battery of checks *could* certify conformance — and a battery provably sufficient and necessary. That is what this paper constructs. Motivation is not hypothetical: our evaluation (§8) shows the published build violating the unload guard's ordering in precisely the way a deviant semantics predicts, and leaking a recorded failure outcome across the fiber boundary on a reconfiguration path no targeted audit had visited.

---

## 3. The Plugin-System Interface

**Definition 1 (events and observations).** Fix countable disjoint sorts: names $\mathfrak N$, keys $K$, values $\mathbb V$, effect tags $\mathbb T$. The event alphabet is

$$\mathcal E ::= \mathsf{app}(n,t) \mid \mathsf{inv}(n,t) \mid \mathsf{rd}(n,k,v) \mid \mathsf{rderr}(n,k,\epsilon) \mid \mathsf{act}(n) \mid \mathsf{deact}(n) \mid \mathsf{val}(n,k)$$

with $\epsilon \in \{\mathsf{IA}, \mathsf{UD}\}$ (inactive resp. undeclared access). In addition, transitions emit *certificates* $\mathsf{cert}(r, \widehat s, \widehat a)$: the rule tag, the normalized signature of the window it fired at, and the normalized update abstract. An *outcome* of a run is $\mathsf{Done}(w,q)$, $\mathsf{Refused}(w,\lambda,q)$, or $\mathsf{Diverge}(u,v)$, where $w$ is the word of events and certificates, $q$ the quiescent report (statuses, outcomes, the store $\mathrm{st}(k) = \sigma_\gamma(k)$, refusal log), and $\lambda$ the refused input. $\mathrm{Out}_{\mathbb X}(\rho)$ is the outcome set of system $\mathbb X$ on orchestration script $\rho$ over all fair schedulers; $\equiv$ compares outcome sets up to sort-preserving renaming and the calculus's value equivalence.

**Definition 2 (plugin system; conformance; passing).** A *plugin system* is an LTS over orchestration labels $\{\mathsf{insert}, \mathsf{retire}, \mathsf{update}, \mathsf{setval}, \mathsf{isolate}, \mathsf{intercept}\}$ and internal lifecycle steps, with the instrumentation of Definition 1. The specification $\mathbb S$ is the calculus so instrumented, with components given as *scripts*: finite step lists over $\{\mathsf{provide}, \mathsf{track}, \mathsf{read}, \mathsf{setval}, \mathsf{register}, \mathsf{raise}, \mathsf{raiseUnless}\}$, one step per iteration of Def. 51 (a tracked inverse may itself read — the read-on-revert form — which §5 shows the suite requires). $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$ iff for every script $\rho$: (i) $\mathrm{Out}_{\mathbb I}(\rho) \equiv \mathrm{Out}_{\mathbb S}(\rho)$ restricted to $\mathsf{Done}/\mathsf{Refused}$ outcomes, and (ii) $\mathbb I$ has a $\mathsf{Diverge}$ outcome on $\rho$ only where $\mathbb S$ does. A test is $t = (\rho_t, V_t)$ with $V_t$ decidable on outcomes; $\mathbb I \models t$ iff **no run of $\mathbb I$ on $\rho_t$ diverges at a settle point** and every outcome satisfies $V_t$.

The divergence clause in $\models$ closes a vacuity: without it, an implementation that never quiesces passes every suite. Conformance is a preorder; its bisimulation presentation (each tagged implementation transition matched by a specification step with the same certificate and emission, and conversely each specification-enabled step offered) is what the sufficiency proof establishes and what necessity consumes.

---

## 4. Impossibility, and the Clause-Factored Class

**Theorem 1 (no finite suite characterizes unrestricted conformance).** For every finite suite $T$ there is an implementation $\mathbb I_T$ with $\mathbb I_T \models T$ and $\mathbb I_T \not\mathrel{\mathbf{conf}} \mathbb S$.

*Proof (sketch; full proof in the artifact).* Let $N$ bound the number of dependency keys any component declared in $T$'s scripts. Let $\mathbb I_T$ behave exactly as $\mathbb S$ except that L-Begin never fires for fibers with $|d_n| > N$. Every observable of every run of every $\rho_t$ is unchanged, so $\mathbb I_T \models T$; a script inserting a component with $N{+}1$ satisfiable keys distinguishes it from $\mathbb S$. The same construction works for fresh key spellings or registry sizes, so no finite suite escapes it. $\blacksquare$

The theorem locates exactly what a finite characterization must assume: that the implementation cannot *count*, *spell*, or otherwise read its state except through the rule's own atoms. We make this a definition.

**Definition 3 (clause-factored implementations).** $\mathbb I \in \mathfrak I_{\mathrm{CF}}$ iff:

- **CF1 (abstraction & tagging).** There is a total abstraction $A : \mathrm{Reach}(\mathbb I) \to \Gamma_{\mathbb S}$ with $A(\gamma^0_{\mathbb I}) = \gamma^0$, and every implementation transition is tagged with the rule it implements; certificates are emitted per Definition 1.
- **CF2 (equivariance).** Behavior commutes with sort-preserving bijections of names, keys, values, and tags fixing the reserved constants.
- **CF3 (signature factorization).** For each rule $r$ there is a table $f_r^{\mathbb I} : \Sigma_r \to \mathrm{Decision}_r$ such that tagged applicability, updates, and emissions at any window are the *lift* of $f_r^{\mathbb I}$ over the window's occurrence multiset $\kappa_r(W)$, combined by the row's declared folds (pointwise products over keys; existential folds over witnesses; one fixed binary composition for the accumulator), with order data drawn from the window's frame.
- **CF4 (instrumentation faithfulness).** Certificates report the actual $(r, \widehat s, \widehat a)$ of each tagged transition, and the certificate abstract $\widehat a$ covers the update aspects that events and reports do not determine (*certificate adequacy*; §6.3 shows this clause is not optional).
- **CF5 (canonical reachability).** Renaming-invariant behavior on the canonical experiments of §5.
- **CF6 (fair, exact settling).** The scheduler is fair and settle terminates exactly on quiescent configurations.
- **CF7 (refusal discipline).** Orchestration inputs are refused exactly where the rule's premises fail, with the refusal observable.

Each obligation is auditable against code: CF3 rules out branching on $|d_n|$, on registry cardinality, or on spellings (Theorem 1's implementation violates it); CF2 rules out reserved names; CF6 pins the scheduler. The class is far from vacuous: it contains $\mathbb S$ itself (Theorem 3) and all twenty-seven deviant calculi of §8, which is what makes necessity meaningful.

---

## 5. Atomic Signatures and the Characteristic Suite

### 5.1 Occurrence decomposition

For each rule $r$, the *window* $W_r(\gamma, n)$ is the tuple of fields the Table-1 row reads and writes, together with its *combination frame*: the index sets of its finite-map operations and the order data of its order-sensitive operators (iterator position; accumulator order). The normalization

$$\kappa_r : W_r \to \mathcal M_{\mathrm{fin}}(\Sigma_r)$$

maps a window to a finite multiset of *occurrences*: one scalar occurrence (the row's scalar guard-atom valuation, step constructor, and equality pattern); one per-key occurrence per key of each pointwise index set; one witness occurrence per satisfied existential (conflict key, reliance edge, child edge); one per-item occurrence per accumulator entry. Crucially, $\kappa_r$ keeps equality *patterns* and forgets identities and counts: a registry of a thousand independent fibers contributes nothing to a rule that does not read them (framing), and a dependency set of any size contributes only the set of satisfaction *classes* present.

### 5.2 The enumerated alphabets

The complete tables — every occurrence with its atoms, a finiteness proof per alphabet, reachability analysis, and a canonical experiment per reachable signature — occupy the artifact's `signatures.md` (1,342 lines); the summary:

| rule / operation | $\|\Sigma_r\|$ | reachable | scripts |
| --- | :-: | :-: | :-: |
| O-Insert | 7 | 6 | 4 |
| O-Retire | 4 | 4 | 4 |
| O-Remove | 7 | 7 | 5 |
| L-Begin | 7 | 7 | 6 |
| L-Iter | 11 | 11 | 8 |
| L-Finish | 3 | 3 | 3 |
| L-Divert | 6 | 4 | 2 |
| L-Raise | 9 | 9 | 7 |
| L-Leave | 5 | 4 | 3 |
| L-Unload | 12 | 12 | 9 |
| coeffect ops (Defs. 23/24, 28/29, 31; Alg. 6) | 21 | 19 | 9 |
| **total** | **92** | **86** | **60** |

Six occurrences are proved *interface-unrealizable*, each with an argument rather than an assertion: O-Insert freshness violation (names are system-drawn); the L-Divert landing alternative (requires the asynchrony layer of [SZC26] §4.3.3, absent from the synchronous reference semantics); the changed-provider divergence class at both L-Divert and L-Leave — ruled out by a lemma: a live committed edge pins its provider, by the reliance guard together with declared disjointness, so a target can change only *to or from* $\bot$; and two Algorithm-6 access classes (self-inactive; withdrawn-binding) blocked by view totality and the guard respectively — the latter being exactly the content of Thm. 63 reappearing as an unreachability fact.

### 5.3 Canonical experiments and $T^\star$

For each rule $r$ and reachable signature $s$, the canonical experiment $(\rho_{r,s}, V_{r,s})$ drives the system, by an explicit orchestration script over explicit component data, to a pointed configuration realizing $s$, lets the attempt at $r$ occur (directly for orchestration rules; by settling for lifecycle rules), and asserts $\equiv$-equality of the implementation's outcome set with the specification's at that point — certificates included. Then

$$T^\star = \{(\rho_{r,s}, V_{r,s}) \mid r \in \mathrm{Rules} \cup \mathrm{Ops},\ s \in \Sigma_r^{\mathrm{reach}}\}, \qquad |T^\star| = 60 \text{ scripts}.$$

Some scripts are load-bearing in nontrivial ways: realizing the *installed-only-provided* satisfaction class requires observing a begin attempt inside another fiber's guarded teardown window; realizing the inactive-access error under Algorithm 6 requires five components and five settles. The 32-test obligation suite that predates this construction (§8) is *material* for $T^\star$: the explorer track (§7) audits which signatures it covers, and the audit — not intuition — decides whether it must grow.

---

## 6. The Characterization Theorem

**Theorem 2 (finite characterization).** For every $\mathbb I \in \mathfrak I_{\mathrm{CF}}$:

$$\mathbb I \mathrel{\mathbf{conf}} \mathbb S \iff \mathbb I \models T^\star,$$

where observation equivalence is taken in the certificate vocabulary of Definition 1.

The proof decomposes into five results, each proved in full in the artifact's `proofs.md` (546 lines); we state them and give the proof shapes, displaying the two arguments of independent interest.

### 6.1 Factorization: the calculus is clause-factored

**Theorem 3 ($\mathbb S \in \mathfrak I_{\mathrm{CF}}$).** Each rule's applicability is a function of its window's occurrence multiset; each write is the lift of per-occurrence updates under the row's declared folds; emissions are per-occurrence; equivariance and framing hold.

*Proof shape.* Rule by rule against Table 1: the guard atoms are read through the occurrence scalar; target construction is a pointwise product of singleton-key provider decisions; conflict, reliance, and childlessness are existential folds over witness occurrences; the accumulator is a fold of one binary operator whose order lives in the frame. Equivariance extends Lemma 56 from names to all four sorts by a per-premise inventory; framing packages Lemmas 54(1) and 57. A symbol inventory per row verifies that *no rule reads a cardinality*: Table 1 contains no arithmetic. This last observation is the exact property Theorem 1's counterexample lacks. $\blacksquare$

### 6.2 Transport

**Lemma 1 (transport).** For $\mathbb I \in \mathfrak I_{\mathrm{CF}}$: windows with equal occurrence multisets (up to sort-preserving renaming) receive equal per-occurrence decisions; whole-rule results additionally correspond when the windows' *frames* correspond.

The second clause is not pedantry: accumulator *order* lives in the frame, and a whole-decision transport across order-differing, multiset-equal windows is false. (This corrected an earlier draft of the theory in which order data was homeless.)

### 6.3 Reflection, and the necessity of certificates

**Lemma 2 (observation reflection).** If $f_r^{\mathbb I}(s) \neq f_r^{\mathbb S}(s)$ at a reachable signature $s$, then $\mathbb I$ fails $(\rho_{r,s}, V_{r,s})$.

*Proof shape.* By cases on the decision variants (spurious fire; missed fire; wrong update; wrong emission; wrong refusal). The key device: at the realized signature, the specification's certificate is forced to $f_r^{\mathbb S}(s)$ because the table is a function — so a deviant certificate matches nothing in the specification's outcome set, and $V_{r,s}$'s $\equiv$-equality fails. CF4 is used exactly where the deviation would otherwise be invisible. $\blacksquare$

**Proposition 1 (masking).** In the certificate-free vocabulary (events and reports only), reflection is false: there is a rule aspect — skipping provision inverses at a *retirement* unload — whose deviation is unobservable on *every* script, because removal deletes the entry any residue would inhabit; moreover the deviant *conforms* in that vocabulary.

The proposition rescues the theorem honestly rather than weakening it silently: the biconditional holds in the certificate vocabulary, and holds in the certificate-free vocabulary only for the quotient of $\mathbb S$ by the masked aspects. It also explains an empirical fact we had met earlier: mutation analysis of the concrete suite found exactly this aspect unkillable.

### 6.4 Safety

**Theorem 4 (safety direction).** If $\mathbb I \in \mathfrak I_{\mathrm{CF}}$ and $\mathbb I \models T^\star$, every finite behavior of $\mathbb I$ is a behavior of $\mathbb S$.

*Proof shape.* Minimal counterexample over the first deviating index of a run (both deviation polarities: a step $\mathbb S$ cannot match; a specification-enabled step $\mathbb I$ cannot offer). The matched prefix gives the reachability bridge: the deviating window's signature is reachable *in $\mathbb S$* because the prefix agrees; Lemma 1 transports the deviation to the canonical realization $\rho_{r,s}$; Lemma 2 makes it fail there, contradicting $\mathbb I \models T^\star$. $\blacksquare$

### 6.5 Termination, and progress without acyclicity

**Theorem 5 (generalized progress; strengthens [SZC26] Thm. 66).** Every maximal lifecycle sequence of $\mathbb S$ is finite — *without* the acyclicity hypothesis on the provider precedence relation $\prec$.

*Proof shape.* An $\omega$-provenance invariant shows every committed edge points at a fiber installed at commitment time; a *frozen-cycle* lemma then shows no member of a co-present $\prec$-cycle is ever installed (first-co-presence freshness plus instantaneous propagation of well-formedness, Def. 58(2,4)); a frozen cone extends this to everything a cycle supports. Outside the frozen cone, the per-fiber and attribution counting bounds internal to Thm. 66's proof are re-proved standalone, and infinite descent closes the argument. The calculus thus quiesces on cyclic configurations not by the theorem's bound but by unsatisfiability — the cycle freezes. $\blacksquare$

**Theorem 6 (termination direction).** For $\mathbb I \in \mathfrak I_{\mathrm{CF}}$ with $\mathbb I \models T^\star$: $\mathbb I$ diverges only where $\mathbb S$ does. Untagged stuttering is excluded by CF1's tagging totality with CF6; the ranking of Theorem 5 transfers along the step matching of Theorem 4.

Termination-sensitivity is not decorative: necessity survives its deletion, sufficiency does not (two counterexamples in the artifact).

### 6.6 Assembly

Necessity: if $\mathbb I \mathrel{\mathbf{conf}} \mathbb S$, each canonical experiment's outcome set equals $\mathbb S$'s by the bisimulation, so every $V_{r,s}$ passes and no settle diverges. Sufficiency: Theorems 4 and 6 assemble the observation bisimulation clause by clause. $\qed$

---

## 7. Mechanization and Exhaustive Exploration

Three executable artifacts ground the theory; we report exact status.

**Exhaustive schedules (complete).** The reference semantics implements the calculus's nondeterminism as a *choice oracle*: wherever more than one rule is applicable, the oracle picks. A mixed-radix enumerating driver explores every oracle sequence of every concrete test scenario. Of the 32 obligation scenarios, 25 are schedule-deterministic; the largest choice tree has 924 schedules; all trees are enumerated to completion. Soundness of the suite on $\mathbb S$ and the entire deviant matrix of §8 are certified under this enumeration — the schedule quantifier in "$\models$" is discharged exactly, not sampled.

**Bounded state-space explorer (in progress).** A normalized all-successor BFS over the reference semantics at bound (4 fibers, 2 keys, 5 steps) with canonicalization of names, keys, and values, generating: the reachable signature sets per rule (an independent check of §5.2's reachability column, including its six negative claims), a generated bounded suite $T_B$ with shortest access sequences, the coverage matrix of the existing 32 tests against reachable signatures, and the deviant kill matrix of the generated suite. At the time of writing the pipeline (normalization with self-test, audit, generation, kill-matrix) is validated and the full-catalog exploration runs are executing; results will accompany the artifact.

**Lean 4 mechanization (in progress).** The bounded theory in core Lean (no external libraries): the calculus at a finite bound as a decidable successor function; equivariance; finiteness of the configuration type; explorer soundness and completeness; the bounded characterization by reflection; the transport lemma as the *single named axiom* whose paper proof is Lemma 1; and the conditional final theorem. Status at submission is recorded in the artifact's `PROOF_STATUS.md`; nothing in §6 depends on it — the dependency runs the other way.

---

## 8. Evaluation of the Current Cordis TypeScript Implementation

### 8.1 Targets and instruments

We evaluate with the concrete 32-obligation suite (the predecessor and material of $T^\star$), each obligation pinned to a clause of the calculus, under the exhaustive-schedule harness, against: (i) the reference semantics (soundness control); (ii) *Cordis-aligned*: the vendored build carrying the prior audit's calculus-alignment fixes; (iii) *Cordis-upstream*: `@deepseek-ai/cordis` 4.0.1 as published; (iv) the upstream build deployed as *two nodes* joined by the `cordis-node` projection layer (in-process transports, mutual mounts, component placement alternating across nodes, observation through projection). Necessity is instrumented by a family of 27 *semantic deviants* of the reference semantics, each negating one clause (guard dropped; accumulator FIFO; $\sigma_\gamma$ over installed fibers; re-entry from $\mathsf{Inactive}(\xi)$; live-view reads; …) — all clause-factored, hence inside the class the theorem quantifies over.

### 8.2 Results

| target | result |
| --- | --- |
| reference semantics | 32/32 |
| Cordis-aligned build | **32/32** |
| Cordis-upstream 4.0.1 | 28/32 |
| two-node distributed (upstream) | 28/32 — the same four |
| deviant family (27) | all killed; 14 obligations essential |

**The four upstream divergences.** *(1, 2) Unload-guard ordering* (two obligations): provider inverses run concurrently with, and before, dependents' guarded teardown — the guard is implemented one level too low (inside the provision effect's own disposer, while the fiber's unload starts all disposers at once). The observed event words realize the guard-deviant derivation of the necessity analysis nearly letter for letter. *(3) Declared disjointness* unenforced at insertion. *(4) Escaped failure outcome* (previously unknown): after a failed first activation, a later `update()` of the by-then recovered, Active fiber releases the *first* episode's error as a process-level unhandled rejection; the calculus requires $\xi$ recorded on the fiber and nothing to escape. States and effect traces are otherwise correct, which is why no state-based audit had found it. All four are fixed in the aligned build, whose 32/32 stands under complete schedule enumeration.

**What 32/32 does and does not claim.** By Theorem 2, passing certifies conformance *given* $\mathbb I \in \mathfrak I_{\mathrm{CF}}$; the CF obligations are audit items on the TypeScript source (no cardinality branching, per-key folds, one accumulator operator, fair scheduler), constructed for the abstraction clause and asserted — not proved — for the rest. The evaluation therefore reads: *the aligned build is conformant relative to a stated, checkable audit obligation; the published build is non-conformant outright* (a single failed obligation refutes membership of the conformant class with no further hypothesis).

**Distribution.** Under the equivalence contract of the `cordis-node` projection layer (established in its own companion verification), conformance transfers to distributed deployments by composition. Empirically, the two-node deployment fails exactly the upstream build's four obligations: the difference attributable to distribution on this suite is empty — with genuine cross-node execution (provider on one node, dependent on the other, satisfied through projection).

---

## 9. Discussion

**Findings about the source paper.** The construction returned three corrections to [SZC26]: **(PB-1)** Table 2 maps Def. 23's $\mathrm{set}(k,v)$ to `ctx.set`; the primitive carrying that operation's precondition and inverse is `ctx.provide`, while `ctx.set` is a value operation on an existing binding. **(PB-2)** For in-place overwrite by an Active provider, §5.1.3 prescribes "not observed" while Thm. 63(3) forces observed replacement if the operation is admitted at all; the calculus is silent, the two prose commitments contradict, and our suite pins the dichotomy any extension must satisfy (never a torn episode). **(PB-3)** Algorithm 10 replaces a component by `dispose()` immediately followed by `use()`, racing O-Insert's own disjointness premise; the reference semantics loses that race under adversarial scheduling, latching a spurious failure — the staged retire–drain–insert is the form whose premises hold at every step.

**What the theory added beyond testing folklore.** Three things. The impossibility theorem plus $\mathfrak I_{\mathrm{CF}}$ converts "we tested it" into a two-part claim with an explicit audit residue. The masking proposition shows that observation vocabularies are part of the theorem statement: without certificates, some deviations are not just unkilled but *unkillable*, and the correct response is a vocabulary extension, not a bigger suite. And the frozen-cycle progress theorem shows the calculus is better-behaved than its own metatheory claimed: cyclic dependency configurations quiesce by freezing, so the acyclicity hypothesis of Thm. 66 can be deleted.

**Limitations.** Membership in $\mathfrak I_{\mathrm{CF}}$ is assumed of implementations and audited, not tested — Theorem 1 shows this is not a weakness of our suite but of finite testing. The hand proofs are unmechanized; the Lean track isolates precisely one axiom (transport) and is in progress. The six unrealizability proofs and the reachability column await independent confirmation by the explorer. The evaluation's schedule exhaustion applies to the reference semantics; for the TypeScript builds, schedules are exercised through the real event loop and quantified by CF6. The distributed result is conditional on the projection layer's own contract.

---

## 10. Related Work

**Testing from formal specifications.** Gaudel's theory [Gau95] established finite completeness relative to uniformity and regularity hypotheses; $\mathfrak I_{\mathrm{CF}}$ is those hypotheses made concrete for a lifecycle calculus, and Theorem 1 is the classical diagonalization in our setting. Tretmans' **ioco** theory [Tre96, Tre08] gives sound and exhaustive suites for LTSs with quiescence; our settle observation plays $\delta$'s role, and our proofs take a simulation form because the calculus's own invariance lemma is natively an up-to technique. Complete test suites for FSM equivalence (the W-method [Cho78]) inspire the characterization shape; our setting differs by unbounded state (hence signatures rather than state counting), nondeterminism (hence outcome sets over fair schedulers), and refusals.

**Mutation analysis.** Adequacy against deviants follows DeMillo–Lipton–Sayward [DLS78]; mutating an executable *specification* follows specification-mutation work [BOY00]; subsumption among tests is documented in the surveys [JH11, PAO17] — our masking proposition gives one mechanism of unkillability a proof.

**Executable semantics.** Validating a semantics by executing it against suites is the semantics-engineering methodology [Fel09] and the K framework's practice [RŞ10]; our reference interpreter with an enumerable scheduling oracle is that methodology plus exhaustive schedule coverage.

**Conformance of module and plugin systems.** De-facto conformance suites (e.g. ECMAScript's test262) carry no completeness theorem; mechanized module-system metatheory verifies calculi, not implementations' fidelity to them. We are not aware of a prior finite characterization theorem for a dynamic-composition runtime.

---

## 11. Conclusion

The question "does this implementation follow the calculus?" has an exact answer. Unrestricted, no finite suite answers it. Restricted to clause-factored implementations — a class whose obligations are auditable against source code and whose definition is forced by the impossibility theorem — a suite of one canonical experiment per reachable atomic signature is both sufficient and necessary: $\mathbb I \mathrel{\mathbf{conf}} \mathbb S \iff \mathbb I \models T^\star$. The signature alphabets are finite and enumerated (92 occurrences; 86 reachable; 6 proved unrealizable); the proof is by hand in the source paper's own style, and en route strengthens that paper's progress theorem and corrects three of its claims. Applied to Cordis, the theory locates four defects in the published build — one invisible to state-based auditing — certifies the aligned build relative to a stated audit residue, and shows the distribution layer preserving the verdict wholesale. The remaining distance to a machine-checked artifact is a single named axiom and a bounded model, both under construction; the mathematics no longer waits on them.

---

## Appendix A. Artifact and Reproduction

The artifact accompanies the paper in the same repository: `formal/signatures.md` (the 92-occurrence tables, finiteness and reachability proofs, 60 canonical scripts); `formal/proofs.md` (the complete proofs of Theorems 3–6 and the assembly); `formal/explorer/` (the bounded explorer) and `formal/lean/` (the mechanization), each with status files; `proof/` (the executable reference semantics, the 32-obligation suite, the 27 deviants, and the harnesses). Reproduction:

```sh
cd paper/proof
MODEL_EXHAUST=1 node --test tests/*.test.mjs    # all schedules
PROOF_TARGET=cordis node --test tests/*.test.mjs
PROOF_TARGET=cordis CORDIS_LIB=<build>/lib/index.js node --test tests/*.test.mjs
node run-necessity.mjs                           # deviant matrix
PROOF_TARGET=cordis-node node --test tests/*.test.mjs
```

Node ≥ 22; no dependencies; the deviant matrix's exit code certifies adequacy and baseline soundness.

## Appendix B. Signature Table Excerpt

By way of sample, the L-Unload alphabet (12 occurrences): the scalar occurrence records $(\theta_n = \mathsf{Unloading}$, reliance-witness present?, outcome class $\in \{\bot, \xi\}$, $\tau$, post-target class $\in \{\bot, \text{satisfiable}\})$ with the well-formed $\tau \times$ post-target blocks reduced to three; witness occurrences record each reliance edge (installed dependent, committed key, equality pattern); per-item occurrences record each accumulator entry's inverse class $\in \{\mathsf{provide}^{-1}, \mathsf{track}^{-1}, \mathsf{register}^{-1}, \mathsf{read\text{-}on\text{-}revert}\}$. The guard-blocked signature's canonical experiment retires a provider under an installed consumer whose tracked inverse reads the provided key; its verdict asserts the consumer's read event, its precedence over every provider inverse, and the final disposal — the experiment that convicts the published build.

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026. (`../paper.pdf`)
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model based testing with labelled transition systems.* In *Formal Methods and Testing*, LNCS 4949, 2008.
- [Cho78] T. S. Chow. *Testing software design modeled by finite-state machines.* IEEE TSE 4(3), 1978.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on test data selection.* IEEE Computer 11(4), 1978.
- [BOY00] P. E. Black, V. Okun, Y. Yesha. *Mutation operators for specifications.* ASE 2000.
- [JH11] Y. Jia, M. Harman. *An analysis and survey of the development of mutation testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis, Y. Jia, M. Harman, et al. *Mutation testing advances.* Advances in Computers, 2017.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An overview of the K semantic framework.* JLAP 79(6), 2010.
