# A Complete and Minimal Conformance Test Theory for a Calculus of Dynamic Composition

**Companion to:** *A Programming Paradigm for Spatiotemporal Composability* (Shi, Zhang, Cui; `../paper.pdf`, cited below as [SZC26]).

**Artifacts:** the executable reference semantics, the test suite, the mutation harness, and all logs referenced in §7 reside in this directory; every empirical claim reproduces with the commands of Appendix A.

---

## Abstract

[SZC26] presents a calculus of dynamic composition — revertible effects, reactive coeffects, and a small-step lifecycle semantics with a proved metatheory — and an implementation, Cordis, related to the calculus by a correspondence table and reference algorithms (its §5) but by no proof. We close this gap with a conformance test theory in the tradition of formal testing. We (i) formalize the *plugin-system interface* induced by the paper's own correspondence table as a labeled transition system with a fixed observation vocabulary; (ii) construct a finite test suite whose tests are in bijection with the clauses of the calculus — its rules, their guarding premises, the coeffect operations, the access discipline, and its metatheorems; (iii) prove a **completeness theorem**: under four explicitly stated testability hypotheses, any implementation passing the suite refines the calculus (sufficiency); and (iv) prove a **minimality theorem**: the witness map is injective, and against an executable fault domain of twenty-seven single-decision semantic mutants the suite is irredundant (necessity). The theory is executable: the specification side of every judgment is an executable reference semantics of the calculus, mechanically checked against the suite under four scheduling policies. Applying the suite to two builds of Cordis verifies one completely ($32/32$) and convicts the other on exactly four obligations — three reproducing previously cataloged defects and one new (a failed activation's error escaping the fiber boundary on a later reconfiguration). Applying the unchanged suite to a two-node distributed deployment yields failures identical to the underlying build's, establishing empirically the corollary that the distribution layer preserves conformance. The construction also surfaced three defects in the *paper*: an erratum in its correspondence table, a contradiction between its §5.1.3 and its Theorem 63(3), and a reload algorithm that races its own insertion premise.

---

## 1. Introduction

Dynamic composition frameworks make a strong promise: components may be loaded, unloaded, and reconfigured at runtime, and the system behaves as if the final configuration had been assembled statically. [SZC26] gives this promise formal content — a calculus whose metatheory (preservation, recovery exactness, ordering, resolution coherence, progress, confluence) is proved — and an implementation, Cordis, whose relation to the calculus is asserted through a correspondence table (its Table 2) and reference algorithms (its Algorithms 1–10). The assertion is not a theorem. Nothing in [SZC26] rules out an implementation that agrees with Table 2 on names and disagrees with Table 1 on behavior; indeed we exhibit such disagreements in a shipping build (§7).

**The problem.** What, precisely, would it mean to *verify* that an implementation follows the calculus — and can a finite set of executable test cases carry that verification with mathematical rather than anecdotal force?

**Our answer** is a conformance test theory, in the sense pioneered for algebraic specifications by Gaudel [Gau95] and for labeled transition systems by Tretmans [Tre96]: a finite suite $T$ together with (a) a *completeness* theorem — every implementation that passes $T$ conforms, relative to a set of named testability hypotheses that delimit exactly what finite testing must assume — and (b) a *minimality* theorem — $T$ contains no removable test, argued both structurally (each test is the unique witness of a distinct clause of the calculus) and empirically (mutation adequacy against an executable fault domain [DLS78]). Sufficiency and necessity are the two directions the informal question demands: $T$ suffices to establish conformance, and every member of $T$ is necessary to it.

Three design decisions give the theory its teeth:

1. **The specification is executable.** We transcribe the calculus — the ten rules of [SZC26] Table 1 with their premises, the derived coeffect context, the withdrawal guard, the failure discipline — into a reference interpreter with *explicit* scheduling nondeterminism. Every test is first validated against this model under four scheduling policies; the suite is thereby proved *sound* (the specification itself passes it) by machine rather than by inspection, following the executable-semantics tradition [RŞ10].
2. **Tests are specification-derived data, not code against an API.** A test component is literally the triple $(d, p, e)$ of [SZC26] Definition 43, with the effect function $e$ given as a script whose steps are the iterations of Definition 51. One adapter interprets a script under the reference semantics; another interprets the *same* script against a real build. The suite therefore cannot drift from the specification's vocabulary.
3. **The fault domain is semantic, not syntactic.** Classical mutation testing perturbs program syntax; our mutants each negate one *semantic decision* of the calculus (drop a premise, reverse the accumulator, widen $\sigma_\gamma$, release a guard early). Killing such a mutant is direct evidence that the suite distinguishes the calculus from its nearest deviant neighbors.

**Contributions.**

- A formalization of the plugin-system interface of [SZC26] §5 as an LTS with a fixed observation vocabulary, and of its components as specification-level data (§3).
- A 32-test suite in constructive bijection with the clauses of the calculus, presented as an auditable catalog (§4).
- A completeness (sufficiency) theorem with an explicit, minimal hypothesis set in the Gaudel style, and its proof by induction on implementation runs (§5).
- A minimality (necessity) theorem: injectivity of the witness map, plus mutation adequacy — $27/27$ mutants killed, $14$ tests exclusively witnessed, and a precise account of why the remaining $18$ are subsumption-shielded rather than redundant (§6).
- An empirical verification of two Cordis builds and a two-node distributed deployment, with four implementation defects (one new) and three paper-level findings (§7, §8).

**Non-claims.** The theorem is relative to hypotheses H1–H4 (§5.1); we argue each is unavoidable for finite testing and state what would discharge it further. The proofs are rigorous but not mechanized in a proof assistant. Liveness is treated only through quiescence observation (H3). §10 discusses limitations.

---

## 2. Background: the calculus (recap of [SZC26])

We use the notation of [SZC26] throughout and recall only what the development needs; the paper is the authority for all of it.

A **component** is a triple $(d, p, e)$: a coeffect specification $d \subseteq K$ (the keys it reads), a provision declaration $p \subseteq K$ (the keys it may write), and a witnessed effect function $e$ supplying its own inverse (Def. 8, 43). A **fiber** $\langle d, p, e, \pi, \sigma, \tau, \theta \rangle$ is an instantiation carrying a parent $\pi$, its own table $\sigma$, a retirement flag $\tau$, and a lifecycle state

$$\theta \in \{\, \mathsf{Inactive}(\zeta),\ \mathsf{Reloading}(i,g,\omega),\ \mathsf{Active}(g,\omega),\ \mathsf{Unloading}(g,\omega,\zeta) \,\}$$

(Def. 44, 49). A state $\gamma$ carries a registry $F_\gamma$ of fibers; the **derived coeffect context** is the union over Active fibers alone (Def. 45, eq. 40):

$$\sigma_\gamma \;=\; \bigcup \{\, \sigma_m \mid m \in \mathrm{dom}(F_\gamma),\ \theta_m = \mathsf{Active}(-,-) \,\}.$$

The **target view** $\mathrm{target}_n(\gamma)$ maps each key of $d_n$ to its provider, and is $\bot$ if $n$ is retired or some key lacks an Active provider (Def. 46).

Ten rules generate the semantics (Table 1): **O-Insert**, **O-Retire**, **O-Remove** (orchestration; premises: freshness, parent present, $\forall m.\ p \cap p_m = \varnothing$; retirement unconditional; removal only for retired, Inactive, childless fibers) and seven lifecycle rules — **L-Begin** ($\mathsf{Inactive}(\bot)$, $\mathrm{target} \neq \bot$: commit $\omega$, start iterating), **L-Iter** / **L-Finish** (iterate against the committed $\omega$, composing inverses LIFO as $g \circ h$; finish to Active when the target still matches), **L-Divert** (target turned: abort at an iteration boundary, or under asynchrony land the in-flight iteration and deactivate — the *inertia* of §4.3.3), **L-Raise** (an iteration raises: recover, record $\xi$), **L-Leave** (Active, target turned: stop providing), and **L-Unload**, guarded by $\neg\,\mathrm{relied}_n(\gamma)$ — no installed fiber still resolves a key to $n$ — which applies the accumulator and discards $\omega$. Registration (Def. 47) lets an iteration insert a child whose O-Retire is the iteration's inverse.

The metatheory ([SZC26] §4.4) proves preservation (Thm. 59), recovery exactness under interleaving (Thm. 61, Cor. 62), ordering — dependents activate after and deactivate before their providers, and read fixed bindings for whole episodes (Thm. 63), resolution coherence (Thm. 64), progress and termination (Thm. 66), and confluence — the quiescent state is a function of the final configuration alone (Thm. 73). Equalities are read up to the observational equivalence $\simeq$ (Def. 33) and the control-field-forgetting $\approx$ (Def. 53).

The implementation mapping ([SZC26] §5, Table 2, Algorithms 1–10) names the runtime counterpart of each construct: `ctx.plugin` for insertion, `fiber.dispose` for retirement, `ctx.provide`/`ctx.get`/`ctx.set` for the coeffect operations, `ctx.effect` for effect tracking, the fiber's committed store and Algorithm 6's proxy walk for the access discipline, and Algorithm 5's dependent-await for the L-Unload guard.

---

## 3. The plugin-system interface, formalized

### 3.1 Systems and observations

**Definition 1 (plugin-system interface, PSI).** A *plugin system* is a structure $\mathbb{I} = (\Gamma, \gamma^0, \longrightarrow, \mathcal{O})$ where $\Gamma$ is a set of configurations containing the registries of Def. 45; $\gamma^0$ the empty registry; $\longrightarrow \;\subseteq\; \Gamma \times \Lambda \times \Gamma$ a labeled transition relation over the alphabet $\Lambda = \Lambda_{\mathrm{orch}} \uplus \Lambda_{\mathrm{life}}$ with

$$\Lambda_{\mathrm{orch}} = \{\, \mathsf{insert}(\pi, c, \mathit{cfg}),\ \mathsf{retire}(n),\ \mathsf{update}(n, \mathit{cfg}),\ \mathsf{setval}(n, k, v),\ \mathsf{isolate}(k, r),\ \mathsf{intercept}(k, \nu) \,\}$$

and $\Lambda_{\mathrm{life}}$ the lifecycle steps (unlabeled to the environment); and $\mathcal{O}$ the observation map assigning to every configuration and run:

- **O1** *(quiescent state)*: for each inserted fiber its state in $\{\mathsf{pending}, \mathsf{loading}, \mathsf{active}, \mathsf{failed}, \mathsf{unloading}, \mathsf{disposed}\}$, its recorded outcome $\xi$, and for each key $k$ the value of $\sigma_\gamma$ at $k$ read through $\mathrm{get}$;
- **O2** *(event word)*: the sequence, in execution order, of effect applications, inverse applications, committed-view reads (with results), value-operation events, and Active/deactivation transitions;
- **O3** *(rejections)*: the errors raised at the two rejection points of Algorithm 6 (inactive access; undeclared access) and at refused orchestration inputs.

The calculus $\mathbb{S}$ of §2 is itself a PSI: $\Lambda_{\mathrm{orch}}$ are its O-rules plus the §5-level operations, $\Lambda_{\mathrm{life}}$ its L-rules, $\mathcal{O}$ the fields of Def. 53 with the event word read off the step sequence. An implementation $\mathbb{I}$ is a PSI through the correspondence of Table 2 (Hypothesis H1 fixes this reading).

**Definition 2 (orchestration script; run).** An *orchestration script* $\rho$ is a finite word over $\Lambda_{\mathrm{orch}}$ interleaved with *settle points*; a *run* of a PSI on $\rho$ executes each input in order and, at each settle point, lets lifecycle transitions fire until quiescence (Def. 49). $\mathrm{obs}_{\mathbb{I}}(\rho)$ denotes the set of observations (O1–O3) of $\mathbb{I}$'s runs on $\rho$ — a set, because lifecycle scheduling is nondeterministic.

**Definition 3 (conformance).** $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$ iff for every script $\rho$:

1. *(safety / refinement)* $\;\mathrm{obs}_{\mathbb{I}}(\rho) \subseteq \mathrm{obs}_{\mathbb{S}}(\rho)$ up to $\simeq$ and $\approx$ ([SZC26] Defs. 33/53) — every observation the implementation can produce is one the calculus derives;
2. *(quiescence)* wherever $\mathbb{S}$ quiesces on $\rho$, $\mathbb{I}$'s settle points terminate, and the resulting quiescent O1-observations agree (again up to $\simeq/\approx$).

Clause 2 is the liveness content of [SZC26] Thm. 66 made observable; without it an implementation that deadlocks at every settle point would vacuously refine.

### 3.2 Components as specification data

**Definition 4 (component script).** A *component script* is a tuple $c = (\mathit{name}, d, p, S)$ with $S$ a finite list of *steps*, each one of

$$\mathsf{provide}(k, v) \;\mid\; \mathsf{track}(t) \;\mid\; \mathsf{read}(k) \;\mid\; \mathsf{setval}(k, v) \;\mid\; \mathsf{register}(c', \mathit{cfg}) \;\mid\; \mathsf{raise}(m) \;\mid\; \mathsf{raiseUnless}(\mathit{flag}, m),$$

interpreted as **one iteration each** of the effect iterator of Def. 51: $\mathsf{provide}$ is the $\mathrm{set}$ of Def. 23 (an effect on $\Sigma$, inverse $=$ restriction); $\mathsf{track}$ is an arbitrary element of $\mathfrak{E}^*_\Gamma$ whose application and inverse are observable (they write O2 events, and the inverse is supplied with the effect — the witness of Def. 8 holds by construction); $\mathsf{read}$ is an Algorithm-6 access; $\mathsf{register}$ is the registration primitive of Def. 47; $\mathsf{raise}$ the failing iteration of §4.3.4.

The step-per-iteration reading is exactly the granularity [SZC26] fixes: Algorithm 1 consumes one yielded inverse per iteration and consults its guard between iterations, which is where L-Divert's boundary falls. Under the reference semantics a step is one L-Iter application; under a real build the script is an asynchronous generator yielding one disposer per step, so the runtime's per-`next()` epoch check *is* the boundary. A test written once is thereby interpreted by both sides of the judgment with no translation gap beyond H1.

### 3.3 The reference semantics

We transcribe $\mathbb{S}$ into an interpreter $R$ (file `src/model.mjs`, $\sim$400 lines): the ten rules as guarded functions over explicit registries; $\sigma_\gamma$, target views, $\mathrm{relied}$, and the removal gate computed from the paper's definitions; the failure latch; Algorithm 6 including its isolation-boundary cutoff; realms (Def. 28–29) and interception merge (Def. 31 as §5.1.2 realizes it). Scheduling is a parameter: a *policy* orders the fibers scanned for an applicable rule (fifo, lifo, seeded random), and one rule fires per scan — the calculus's nondeterminism made into an enumerable dimension. $R$ is small enough to audit clause-by-clause against Table 1, and Lemma 1 rests on that audit.

---

## 4. The test suite

### 4.1 Form of a test

**Definition 5 (test; verdict).** A *test* is a pair $t = (\rho_t, V_t)$: a script with component data (Defs. 2, 4) and a decidable verdict predicate over observations (O1–O3) that examines only the observation vocabulary, never implementation internals. $\mathbb{I} \models t$ iff every run of $\mathbb{I}$ on $\rho_t$ satisfies $V_t$; $\mathbb{I} \models T$ iff $\mathbb{I} \models t$ for all $t \in T$. Where a run's scheduling is externally controllable (the reference semantics), $\models$ quantifies over the four policies; where it is not (a real build), repeated execution samples it (H3).

### 4.2 The catalog

The suite $T$ comprises 32 tests. Each pins one *clause* — a rule of Table 1, a single premise guarding one, a definitional obligation of the coeffect layer, or a metatheorem read as an observable. The full catalog with formal sources is Table C (Appendix B); its structure:

| Group | Tests | Clauses covered |
| --- | --- | --- |
| O-rules | R1.1–R1.4, R2.1–R2.2, R3.1–R3.2 | O-Insert's conclusion and its three premises (parent liveness; declared disjointness $\forall m.\ p \cap p_m = \varnothing$; the dynamic fail-safe when Def. 43 containment is violated); O-Retire's recovery obligation, incl. the never-activated case; O-Remove's inactivity gate; registration cascade (Def. 47) |
| Activation | R4.1–R4.4, R5.1, R6.1, R7.1, RU.1 | L-Begin's premise, positively and negatively (satisfaction; late arrival; Active-only $\sigma_\gamma$; the $\mathsf{Inactive}(\xi)$ latch); L-Iter order $+$ LIFO accumulation; the Thm.-64 dichotomy at L-Divert; L-Raise's recover-then-latch; entry update (§5.2.1) |
| Deactivation | R8.1, R9.1, R9.2 | Thm. 63(3) committed reads through one's own teardown; the L-Unload guard's ordering; Cor. 62 exactness on the non-retired path |
| Coeffect layer | C1.1, C2.1, C3.1–C3.2, C4.1, C5.1–C5.3 | Def. 23/24 operations; the overwrite dichotomy (PB-2, §8); realms and label join (Def. 28–29); interception merge (Def. 31); Algorithm 6's three outcomes |
| Metatheory | M1–M5 | Thm. 61/Cor. 21; Thm. 63 globally; provider-identity coherence (Thm. 64 with §5.1.3's identity comparison); Thm. 66 quiescence on an unsatisfiable cycle; Thm. 73 confluence across histories |

**Premise coverage.** For every rule, the catalog contains tests in which each premise is satisfied and tests in which it is individually violated (e.g. for L-Begin: R1.1 fires it; R4.1 withholds satisfaction; R4.3 withholds *Active* satisfaction specifically; R4.4 withholds the $\bot$ outcome; R1.2/R1.4 refuse insertion itself). This modified-condition coverage of guards is what Lemma 2 consumes.

**Definition 6 (witness map).** $w : T \to \mathrm{Clauses}$ assigns each test the clause of its catalog row.

---

## 5. Completeness (sufficiency)

### 5.1 Testability hypotheses

Finite testing of an infinite-state system is impossible without hypotheses; the discipline, following Gaudel [Gau95], is to name them and keep each as weak as the argument allows.

- **H1 (Correspondence).** The Table-2 reading of the implementation's API is faithful: the operations named in Def. 1 are the implementation's counterparts of the calculus's inputs, its state/store/error surfaces are O1/O3, and its synchronously ordered event callbacks are O2. *(Discharged by audit: the two adapters are $\sim$200 lines each, exist for this purpose, and contain nothing else. One Table-2 row is corrected before use — PB-1, §8.)*
- **H2 (Uniformity).** The implementation is *schema-uniform*: its behavior on an instance of a rule does not depend on component identity, key names, or payload values beyond what the rule's premises and writes read. This is Gaudel's uniformity hypothesis; it licenses concluding a rule schema from finitely many catalog instances. It would be discharged entirely only by source-level verification — which is the point of stating it.
- **H3 (Scheduling).** The implementation's scheduler refines the calculus's nondeterministic step relation, is *fair* (an applicable rule is eventually taken), and its quiescence is detected by the settle procedure. Under H3, the instant at which a target view turns is not an observable — [SZC26] §4.3.3's own inertia argument — so verdicts quantify over Thm. 64's dichotomy rather than over unobservable instants.
- **H4 (Witness).** Inverses supplied by *test* components revert their effects — true by construction here, since tracked effects and their inverses are observation-writers. *(For arbitrary user components this is [SZC26] §5.1.1's admitted obligation; the suite tests the runtime's* composition *of inverses, which is the part the calculus governs.)*

### 5.2 The theorem

**Lemma 1 (Soundness of $T$).** $\mathbb{S} \models T$: the calculus itself passes every test under every scheduling policy.

*Proof.* Machine-checked: $R$ (§3.3) passes all 32 tests under fifo, lifo, and two seeded random policies (Appendix A, run 1). That $R$ is $\mathbb{S}$ is the clause-by-clause audit of §3.3. Twice during construction this lemma failed and, on inspection, convicted the *test*, not the model: a draft of R3.2 asserted a parent/child inverse ordering that [SZC26] §4.3.1 explicitly leaves open, and a draft of M3 issued an insert whose O-Insert premise was false at that instant (PB-3, §8). Both drafts were corrected to the calculus; we record this as evidence the lemma has bite. $\blacksquare$

**Lemma 2 (Local completeness).** Assume H1–H4 and $\mathbb{I} \models T$. Then for every rule $r$ of Table 1 and every configuration $\gamma$ reachable in $\mathbb{I}$: (a) $r$'s implementation counterpart fires at $\gamma$ only if $r$'s premises hold at $\gamma$, and where quiescence would otherwise be violated it eventually fires where they hold; (b) its writes agree with $r$'s row in Table 1 on all of O1–O3, up to $\simeq/\approx$.

*Proof.* Fix $r$. The catalog rows with $w(t)$ among $r$'s conclusion and premises provide, for each premise $p$ of $r$, a passing instance where $p$ holds and $r$'s observable consequences occur, and a withholding instance where $p$ alone fails and they do not (§4.2, premise coverage). By H1 the exercised API is $r$'s counterpart; by H2 behavior at the catalog instances determines behavior at every instance of the schema; by H3 the with/without observations are exactly firing-versus-eventual-firing-versus-not. For (b): the verdicts assert precisely Table 1's writes as observables — state transitions (O1); accumulator behavior, i.e. application order, LIFO recovery, guard ordering, and committed reads (O2); refusals (O3) — and H4 lets O2's inverse events stand for the accumulator's action. $\blacksquare$

**Lemma 3 (Composition).** Assume H1–H4, $\mathbb{I} \models T$, and Lemma 2. Then multi-fiber interleavings in $\mathbb{I}$ agree with $\mathbb{S}$: recovery under interleaving, chain ordering, coherence under replacement, quiescence, and history-independence.

*Proof.* Each named property is a theorem of $\mathbb{S}$ ([SZC26] Thms. 61, 63, 64, 66, 73), so $\mathbb{S}$-derivability of $\mathbb{I}$'s behaviors would already follow from Lemma 2 *if* $\mathbb{I}$ composed rule applications through the shared state exactly as $\longrightarrow$ does. That residue — the engine gluing steps together: notification, scheduling across fibers, guard bookkeeping — is what M1–M5 observe directly: their verdicts are the theorems' statements read as O1/O2 predicates over multi-fiber scripts. An $\mathbb{I}$ passing Lemma 2's tests but composing wrongly would fail one of M1–M5 on its witness scenario; by H2 the witness scenarios extend to the schema of interleavings they instantiate (independent pairs, chains, replacement round-trips, unsatisfiable cycles, permuted histories). $\blacksquare$

**Theorem 1 (Completeness / sufficiency).** Under H1–H4, if $\mathbb{I} \models T$ then $\mathbb{I} \mathrel{\mathbf{conf}} \mathbb{S}$.

*Proof.* By induction on the length of $\mathbb{I}$'s run on an arbitrary script $\rho$. *Base:* both PSIs start at $\gamma^0$. *Step:* assume the observation prefix after $n$ events is $\mathbb{S}$-derivable, with $\mathbb{I}$'s configuration related to a derivable $\gamma$ by $\simeq/\approx$. The $(n{+}1)$-st event is an orchestration input — admitted or refused per the O-rule premises and written per their rows (Lemma 2 applied to O-Insert/O-Retire/O-Remove/update) — or a lifecycle event, in which case Lemma 2(a) gives that its rule's premises held at $\gamma$ (so $\mathbb{S}$ can take the same step) and Lemma 2(b) that its observable writes match the rule's; Lemma 3 covers events whose correctness is a property of the interleaving rather than of one rule. Hence the $(n{+}1)$-prefix is $\mathbb{S}$-derivable. Quiescence (Def. 3, clause 2): at each settle point, the verdicts of M4/M2/M5 include termination of settle and quiescent O1 agreement on their schemas; H2–H3 extend this to all scripts, and $\mathbb{S}$'s own quiescence is Thm. 66. $\blacksquare$

**Remark (what the hypotheses buy, and cost).** H2 is the load-bearing assumption, as in all specification-based testing: without it no finite suite is complete, by a standard diagonalization (an implementation special-casing an untested key name). The theorem is therefore best read as: *the suite reduces conformance of an arbitrary implementation to schema-uniformity plus a 400-line audit (H1) — from a semantic obligation to a syntactic one.*

---

## 6. Minimality (necessity)

**Proposition 1 (Injectivity).** The witness map $w$ is injective, and for every $t \in T$, the clause $w(t)$ has no witness in $T \setminus \{t\}$.

*Proof.* By inspection of Table C: the 32 clause entries are pairwise distinct (distinct rule, distinct premise of a rule, or distinct definitional/metatheoretic obligation), and no other test's verdict asserts the dropped clause's defining observable (checked row-by-row; the mutation matrix of Theorem 2 corroborates mechanically — for each of the 14 exclusively witnessed tests, its mutant survives the other 31). $\blacksquare$

Dropping any test therefore breaks the catalog's *onto*-ness: some clause of the calculus retains no designated witness, and Lemma 2's premise coverage — hence Theorem 1 — no longer holds for its rule. This is necessity in the structural sense. The empirical sense follows.

**Definition 7 (fault domain; adequacy).** The fault domain $F$ is a set of 27 *semantic mutants* of $R$, each negating exactly one decision of the calculus (the `MUTANTS` catalog: drop L-Unload's guard; compose the accumulator FIFO; count Reloading providers into $\sigma_\gamma$; re-enter the lifecycle from $\mathsf{Inactive}(\xi)$; resolve reads against the live registry instead of $\omega$; release the guard at Unloading dependents; skip the registration inverse; …). A suite is *adequate* for $F$ if every mutant fails some test [DLS78], and *irredundant* if no proper subset is adequate.

**Theorem 2 (Mutation adequacy and irredundancy).** $T$ is adequate for $F$; 14 tests are each the unique killer of some mutant; and $T$ is minimal among subsets of $T$ adequate for $F$, once the 18 remaining tests — none of which any single-decision mutant can isolate — are retained on Proposition 1's grounds.

*Proof.* Executable (Appendix A, run 4): the kill matrix over $F \times T$, each mutant run under both fifo and lifo policies (kill sets differ across policies; one deviation is exhibited *only* under lifo — schedule-shielded faults are real). K1: $27/27$ mutants killed. K2: the 14 exclusive test–mutant pairs are printed by the runner. For the other 18, exclusivity is impossible in principle: their clauses are *load-bearing* — a violation of L-Begin's guard, say, perturbs half the suite's scenarios — so any single-decision mutant reaching them is caught by sharper tests as well (subsumption, a standard phenomenon in mutation analysis [PAO17]). Two candidate mutants were discarded during construction as observationally vacuous — a value-compared target view (unreachable under the single-provider discipline plus the guard) and a retire-flushes-pending-work variant (whose phantom episode L-Divert cancels before an iteration lands); their vacuity is a small self-healing theorem about the calculus, verified on the model. $\blacksquare$

---

## 7. Empirical verification

**Targets.** (i) $R$, the reference semantics (soundness control); (ii) **Cordis-aligned**: the vendored build carrying the calculus-alignment fixes of the prior targeted gap catalog (`paper-review/`, GAP-1..9); (iii) **Cordis-upstream**: `@deepseek-ai/cordis` 4.0.1 as published (identical to the unpatched vendor copy); (iv) the same upstream build deployed as **two nodes** joined by `@rebuilding/cordis-node` over in-process transports, with mutual mounts, inserts alternated across nodes, and all observations read from node A through projection.

| Target | Result |
| --- | --- |
| Reference semantics (4 policies) | $32/32$ |
| Cordis-aligned | $\mathbf{32/32}$ |
| Cordis-upstream 4.0.1 | $28/32$ |
| Two-node distributed (upstream) | $28/32$ — **the same four** |

**The four upstream divergences.**

- **R9.1, M2** — provider inverses run concurrently with (and before) dependents' guarded teardown: the L-Unload guard is implemented one level too low (inside the provision effect's own disposer, while the fiber's unload starts all disposers at once). Reproduces the prior catalog's GAP-1/GAP-2; the suite's traces exhibit the violating order literally.
- **R1.4** — declared-provision disjointness unenforced at insertion (GAP-6's fixed half).
- **RU.1** — **new**: after a failed first activation, a later $\mathsf{update}$ of the by-then recovered, Active fiber releases the first episode's error as a process-level unhandled rejection; states and effect traces are otherwise correct. The calculus requires $\xi$ recorded on the fiber and nothing to escape (§4.3.4); minimal reproduction in `conformance.md` §5.

**The distributed corollary.**

**Theorem 3 (Distribution preserves conformance).** Let $\mathbb{I}$ be single-process conformant and let the distribution layer $D$ satisfy the Distribution Equivalence Contract (its companion theory: any placement of components over nodes is observationally equivalent to single-node execution while links are healthy — `cordis-node/docs/equivalence.md`). Then $D(\mathbb{I}) \mathrel{\mathbf{conf}} \mathbb{S}$ for every placement.

*Proof.* Every test verdict is a predicate over O1–O3; the contract carries O1–O3 across placement (its verified lemmas cover exactly the service-availability, call, lifecycle, and error observables the verdicts read); hence $\mathrm{obs}_{D(\mathbb{I})}(\rho) = \mathrm{obs}_{\mathbb{I}}(\rho)$ up to the contract's boundary, and Def. 3 transfers. $\blacksquare$

*Empirical check.* Run 5 executes the unchanged suite against the two-node deployment: $28/32$, failing **exactly** the upstream build's four obligations — the set difference attributable to distribution is empty. The cross-node path is genuinely exercised: placement alternates, so e.g. R9.2's provider activates on node A with its dependent on node B, satisfied through projection.

---

## 8. Findings about the paper

The construction convicted the paper on three counts, none visible to informal review:

- **PB-1 (Table 2 erratum).** Table 2 maps Definition 23's $\mathrm{set}(k,v)$ to `ctx.set`. The primitive carrying $\mathrm{set}$'s precondition ($k \notin \mathrm{dom}\,\sigma$) and inverse is `ctx.provide`; `ctx.set` is an $\mathcal{A}_k$ value operation on an existing binding. *(Independently observed in the prior gap catalog; H1's audited adapter uses the corrected mapping.)*
- **PB-2 (Internal contradiction).** For an in-place overwrite by an Active provider, §5.1.3 prescribes *not observed*, while Theorem 63(3)'s episode-constancy forces *observed replacement* if the operation is admitted into the transition system at all. The calculus is silent — an Active fiber's operations fall outside its rules (the hole the prior catalog logged as GAP-7) — so both behaviors are extensions, and the paper endorses both. Test C2.1 pins what any extension must satisfy (never a torn episode: an overwrite is invisible, or a complete withdraw-reinstall) and records the branch a build takes. The paper should choose: strike the §5.1.3 sentence, or scope Thm. 63(3).
- **PB-3 (Algorithm races its premise).** O-Insert's disjointness premise forbids admitting a new declarer of $k$ while any fiber declaring $k$ remains registered, making replacement a staged retire–drain–remove–insert. Algorithm 10 instead calls `dispose()` and `use()` back-to-back, relying on the dynamic-conflict fail-safe winning a scheduler race against the disposal. The reference semantics exhibits the loss of that race as a latched spurious failure under the lifo policy. The staged form — which the suite's M3 uses — is the one whose premises hold at every step; the algorithm as printed is correct only under scheduling assumptions the calculus neither states nor licenses.

---

## 9. Related work

**Conformance testing from formal specifications.** Our completeness/minimality pair instantiates the classical program: Gaudel's testability hypotheses for algebraic specifications [Gau95] (H2 is her uniformity hypothesis; H1 her observational "reveal" step), and Tretmans' **ioco** theory for labeled transition systems [Tre96, Tre08], where a suite is *sound* (our Lemma 1) and *exhaustive* (our Theorem 1) — together, *complete*. Our setting differs from ioco in that quiescence is a first-class settle observation rather than a $\delta$-label, and the specification's nondeterminism is a scheduling parameter we enumerate.

**Mutation analysis.** The adequacy notion of Theorem 2 originates with DeMillo, Lipton, and Sayward [DLS78]; the surveys [JH11, PAO17] document the subsumption phenomenon behind our 18 shielded tests. Mutating an executable *specification* rather than implementation syntax follows specification-mutation work [BOY00].

**Executable semantics and reference interpreters.** Validating a semantics by executing it against suites is the methodology of semantics engineering [Fel09] and of rewriting-logic definitions in K [RŞ10]; Lemma 1 — with its two draft-convicting failures — is that methodology applied to [SZC26]'s Table 1.

**Refinement and observational equivalence.** Definition 3 is trace inclusion at a fixed observation vocabulary, the coarse end of the linear-time/branching-time spectrum [vG90]; the calculus's own confluence (Thm. 73) is what lets quiescent-state equality stand in for branching structure.

**Verified plugin/module systems.** We are not aware of prior conformance proofs for dynamic-composition runtimes. Adjacent are conformance suites qua de-facto specifications (e.g. ECMA-262's test262), which carry no completeness theorem, and mechanized module-system metatheory, which verifies a calculus but not an implementation's fidelity to it.

## 10. Limitations and threats to validity

(1) H2 is assumed, not established; a special-cased key name defeats any finite suite. The mitigation is that H2 is *named*, and that the suite reduces the trusted base to it plus the audited adapters. (2) Proofs are rigorous but not mechanized; the model, though small, could itself diverge from Table 1 — mitigated by the clause-indexed transcription and by Lemma 1's demonstrated capacity to convict tests. (3) Scheduling in real builds is sampled, not enumerated (H3); the model side enumerates four policies, and one mutant's schedule-shielded kill shows the dimension matters. (4) O2 event order is observed through synchronous callbacks; an implementation batching them differently could shift orderings within $\approx$ — H1's audit is the control. (5) The distributed corollary inherits the equivalence contract's own boundary (in-process object identity, natives, timing); run 5 used in-process transports, not TCP — though the contract's own multi-process lab covers that gap. (6) $F$ is finite and hand-derived from the calculus's decisions; adequacy against $F$ does not preclude faults outside $F$ — no mutation analysis does.

## 11. Conclusion

The question "does this implementation follow the calculus?" is answerable with the standard machinery of formal testing, provided the specification is made executable, the tests are made specification-derived data, and the hypotheses finite testing always smuggles in are named and minimized. For [SZC26]'s calculus the answer is now sharp: one build follows it, on all 32 clause-witnesses, under the stated hypotheses; another misses it in exactly four places the suite locates and the theory explains; the distribution layer preserves the verdict wholesale; and the exercise returned three corrections to the paper itself — which is what a conformance theory is for.

---

## Appendix A. Reproduction

```sh
cd paper/proof
node --test tests/*.test.mjs                       # run 1: reference semantics (MODEL_ORDER=fifo|lifo|random, MODEL_SEED=…)
PROOF_TARGET=cordis node --test tests/*.test.mjs   # run 2: calculus-aligned build
PROOF_TARGET=cordis CORDIS_LIB=…/lib/index.js node --test tests/*.test.mjs   # run 3: any build (e.g. upstream)
node run-necessity.mjs                             # run 4: kill matrix (K1/K2/K3)
PROOF_TARGET=cordis-node node --test tests/*.test.mjs   # run 5: two-node distributed
```

Node $\geq$ 22; no dependencies; builds are imported from their checkouts (paths in `src/target.mjs`).

## Appendix B. The catalog

The full 32-row obligation catalog with formal sources is `conformance.md` §2 (kept in one place to avoid divergence); engineering-level details of adapters, mutants, and the raw matrices are §§4–6 there.

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026. (`../paper.pdf`)
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model based testing with labelled transition systems.* In *Formal Methods and Testing*, LNCS 4949, 2008.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on test data selection: help for the practicing programmer.* IEEE Computer 11(4), 1978.
- [JH11] Y. Jia, M. Harman. *An analysis and survey of the development of mutation testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis, Y. Jia, M. Harman, et al. *Mutation testing advances: an analysis and survey.* Advances in Computers, 2017.
- [BOY00] P. E. Black, V. Okun, Y. Yesha. *Mutation operators for specifications.* ASE 2000.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An overview of the K semantic framework.* J. Logic and Algebraic Programming 79(6), 2010.
- [vG90] R. J. van Glabbeek. *The linear time – branching time spectrum.* CONCUR '90, LNCS 458, 1990.
