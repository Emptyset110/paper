# A Finite Characterization of Plugin-System Conformance for Dynamic Composition

**Companion to:** *A Programming Paradigm for Spatiotemporal Composability* (Shi, Zhang, Cui; `../paper.pdf`, cited as [SZC26]). References of the form Def. 43 or Thm. 63 are to [SZC26]; references written as Definition 3 or Theorem 2 are internal.

**Artifact boundary.** The executable model, adapters, and the current 32-scenario regression catalog reside in this directory. This paper separates two claims that an artifact must not conflate: the mathematical existence of a finite characteristic suite, proved here for an explicitly defined implementation class, and the engineering question whether a particular adapter and catalog discharge all premises of that theorem.

---

## Abstract

The calculus of [SZC26] gives a small-step semantics for dynamically installed, retired, and reconfigured components. Cordis is presented as an implementation of that calculus, but a correspondence table between mathematical objects and program fields is not by itself an implementation theorem. We give such a theorem in the form appropriate to testing.

We first define the observable plugin-system interface induced by [SZC26] as an instrumented labeled transition system and define conformance by termination-sensitive observation equivalence, refusal agreement, and rule-level observation bisimulation. An unrestricted implementation cannot be characterized by any finite black-box suite: it may agree on every name and configuration appearing in the suite and deviate elsewhere. We therefore define the auditable class of **clause-factored implementations**. Its members admit a faithful abstraction into the calculus, are equivariant under renaming, factor rule decisions and updates through a finite set of normalized atomic rule signatures, expose every abstractly relevant update through the test instrumentation, and implement fair, exact settling.

For this class we construct a finite suite \(T^\star\), containing one canonical experiment for every reachable normalized rule signature. The main result is a biconditional:

\[
   \mathbb I \mathrel{\mathbf{conf}} \mathbb S
   \quad\Longleftrightarrow\quad
   \mathbb I \models T^\star .
\]

The left-to-right implication makes the suite necessary; the right-to-left implication makes it sufficient. The proof is not a leap from a few examples to arbitrary registries: it uses a stated finite-factorization audit and a canonical-realization lemma. Local transition agreement then yields an observation simulation for scripts of arbitrary finite size. We also describe how the existing 32-scenario Cordis catalog instantiates part of \(T^\star\), how its mutation results should be reported without claiming semantic minimality, and how the exercise exposed implementation defects and three inconsistencies in [SZC26].

---

## 1. Introduction

A plugin runtime is expected to make a strong promise: components may arrive, disappear, fail, and change dependencies while their effects behave as if each stable configuration had been assembled coherently. [SZC26] formalizes that promise with a registry calculus. Its rules describe insertion and retirement, activation and recovery, committed dependency views, provider withdrawal, and failure. Its metatheory proves recovery exactness, dependency ordering, resolution coherence, progress, and confluence under stated hypotheses.

The remaining question is an implementation question:

> When is a concrete plugin system an implementation of this calculus, and can that fact be reduced to a finite executable test judgment?

The phrase “a finite suite is complete” is dangerous unless its domain is explicit. No finite suite can characterize every program that happens to implement the same API. An implementation can inspect a key not used by the suite, branch on the fifth installed fiber, or deviate only for a dependency set larger than any tested one. Renaming invariance alone excludes the first trick, but not the cardinality tricks. A valid finite-testing theorem must therefore identify the finite quotient of behavior on which the implementation is assumed—or separately verified—to operate.

This paper makes that quotient explicit. Each rule of [SZC26] reads a finite collection of logical atoms: lifecycle-state tests, equality of committed and target views, satisfaction, retirement, freshness, childlessness, and reliance. Operations on finite maps additionally decompose pointwise over keys, while reliance and conflict checks decompose through existential witnesses. After names, keys, values, and effect tags are normalized, these atoms yield finitely many **atomic rule signatures**. A clause-factored implementation is one whose implementation of a rule is a lift of its behavior on these signatures, with no hidden dependence on registry size, spelling, allocation order, or unobserved fields.

That condition is not inferred from tests. It is a finite code-audit or verification obligation, analogous to the regularity and uniformity hypotheses in algebraic testing [Gau95]. Once discharged, however, testing supplies exactly the missing finite table: for every reachable signature, whether the rule is enabled, which abstract update it makes, which event it emits, and whether the resulting settle terminates. Equality of this table with the specification is both necessary and sufficient for conformance.

### Contributions

1. An instrumented LTS for the plugin-system boundary described by [SZC26] and a conformance relation covering traces, refusals, reports, and quiescence (§2–§3).
2. An impossibility proposition showing why unrestricted finite completeness cannot hold (§4.1).
3. The clause-factored implementation class, stated as checkable semantic obligations rather than an informal “no special cases” assumption (§4.2).
4. A constructive finite characteristic suite \(T^\star\) obtained from normalized rule signatures and canonical realizing scenarios (§5).
5. A necessary-and-sufficient conformance theorem for every admitted implementation, proved by table equality and observation simulation (§6).
6. A disciplined interpretation of the current 32-scenario Cordis suite: it is a valuable executable catalog and mutation study, but it becomes a complete instance of \(T^\star\) only after its signature-coverage and adapter audits are checked (§7).
7. An empirical case study and three corrections to the correspondence claimed in [SZC26] (§8–§9).

### Non-claims

The paper does not claim that arbitrary implementations are finitely testable. It does not infer the factorization audit from a successful run. It does not equate mutation adequacy with semantic minimality. It does not treat a finite selection of scheduler policies as exhaustive exploration. These distinctions are part of the theorem, not merely threats listed after it.

---

## 2. The specification and its observable boundary

### 2.1 The calculus

Fix countable, pairwise disjoint sets (K) of keys, \(\mathfrak N\) of fiber names, \(\mathbb V\) of values, and \(\mathbb T\) of effect tags. A component is a finite triple ((d,p,e)) as in Def. 43 of [SZC26]. A fiber has fields

\[
 \langle d,p,e,\pi,\sigma,\tau,\theta\rangle
\]

and lifecycle state

\[
\theta \in
\{\mathsf{Inactive}(\zeta),
  \mathsf{Reloading}(i,g,\omega),
  \mathsf{Active}(g,\omega),
  \mathsf{Unloading}(g,\omega,\zeta)\}.
\]

A registry state \(\gamma\) carries a finite map \(F_\gamma\) from names to fibers. The active coeffect context, target view, and reliance predicate are those of Defs. 45, 46, and 50:

\[
\sigma_\gamma
= \bigcup\{\sigma_m \mid \theta_m=\mathsf{Active}(-,-)\},
\]

\[
\mathrm{target}_n(\gamma)=
\begin{cases}
\bot,&\tau_n\lor\neg(\gamma\vDash d_n),\\
(k\in d_n)\mapsto\mathrm{provider}_k(\gamma),&\text{otherwise,}
\end{cases}
\]

\[
\mathrm{relied}_n(\gamma)
\iff
\exists m\ne n,\,k\in d_m.\;
\mathrm{installed}_m(\gamma)\land\omega_m(k)=n.
\]

The transition relation is generated by O-Insert, O-Retire, O-Remove and the seven lifecycle rules L-Begin, L-Iter, L-Finish, L-Divert, L-Raise, L-Leave, and L-Unload in Table 1 of [SZC26]. We write this specification LTS as \(\mathbb S\).

### 2.2 Components used by experiments

A test component is data rather than arbitrary host code:

\[
c=(\mathit{name},d,p,S),\qquad S\in\mathrm{Step}^*,
\]

where

\[
\begin{aligned}
\mathrm{Step} ::= {}& \mathsf{provide}(k,v)
\mid \mathsf{track}(t)
\mid \mathsf{read}(k)
\mid \mathsf{setval}(k,v)\\
&\mid \mathsf{register}(c,\mathit{cfg})
\mid \mathsf{raise}(x)
\mid \mathsf{raiseUnless}(f,x).
\end{aligned}
\]

Each step denotes one iterator landing of Def. 51. `track` supplies a witnessed inverse and is used to observe accumulation and recovery order. This language is finite in constructors even though its payload domains are countable.

### 2.3 Inputs and observations

The orchestration alphabet is

\[
\begin{aligned}
\Lambda_{\mathrm{orch}}=\{&
\mathsf{insert}(\pi,c,\mathit{cfg}),
\mathsf{retire}(n),
\mathsf{update}(n,\mathit{cfg}),\\
&\mathsf{setval}(n,k,v),
\mathsf{isolate}(k,r),
\mathsf{intercept}(k,\nu)\}.
\end{aligned}
\]

Lifecycle steps carry the internal label (\mathsf{life}(r,n)), naming their rule and acting fiber. The event alphabet is

\[
\begin{aligned}
\mathcal E ::= {}&
\mathsf{app}(n,t)\mid\mathsf{inv}(n,t)
\mid\mathsf{rd}(n,k,v)
\mid\mathsf{rderr}(n,k,\epsilon)\\
&\mid\mathsf{act}(n)\mid\mathsf{deact}(n)
\mid\mathsf{val}(n,k),
\end{aligned}
\]

with \(\epsilon\in\{\mathsf{IA},\mathsf{UD}\}\). A rejected orchestration input produces a refusal event. A test adapter additionally exposes an **abstract transition certificate**

\[
\mathsf{cert}(r,\widehat s,\widehat a),
\]

where \(\widehat s\) is the normalized atomic signature before a rule attempt and \(\widehat a\) is the normalized abstract update, or \(\mathsf{disabled}\). Certificates do not expose arbitrary implementation memory; they expose exactly the fields already named by the abstraction audit in §4.2. They can be produced by instrumentation, a reference monitor, or a verified adapter.

A quiescent report records, for every name introduced by the script, its lifecycle class and outcome, the visible coeffect store, and the refused-input log. A report may record a disposed name even after its registry entry has disappeared; this is test-harness history, not an extra calculus field.

### 2.4 Runs and termination-sensitive observations

An orchestration script is a finite word over \(\Lambda_{\mathrm{orch}}\cup\{\mathsf{settle}\}\). At `settle`, lifecycle rules execute until no lifecycle transition is enabled.

Unlike a trace semantics that silently drops divergence, the outcome of running \(\rho\) is one of

\[
\mathsf{Done}(w,q),\qquad
\mathsf{Refused}(w,\lambda,q),\qquad
\mathsf{Diverge}(w),
\]

where (w) contains ordinary events and certificates. Let (\mathrm{Out}_\mathbb X\(\rho\)) be the set of all outcomes over all schedulers admitted by \(\mathbb X\). Thus nontermination is an observable test failure rather than an empty behavior set.

---

## 3. Conformance

### 3.1 Observation equivalence

Let \(\equiv\) be the least equivalence satisfying:

- names, keys, values, and tags may be consistently renamed by a sort-preserving bijection;
- abstract states and reports may vary by the \(\simeq/\approx\) equivalences of [SZC26];
- instrumentation certificates are compared after the same normalization;
- ordinary event order is preserved exactly.

The last clause is intentional. LIFO recovery and provider-before-consumer ordering are temporal claims and must not disappear inside a state equivalence.

### 3.2 Definition of conformance

**Definition 1 (plugin-system conformance).** An implementation \(\mathbb I\) conforms to \(\mathbb S\), written

\[
\mathbb I\mathrel{\mathbf{conf}}\mathbb S,
\]

when there is an abstraction (A) as in §4.2 under which the two instrumented systems are observation-bisimilar. In particular, the bisimulation entails the following conditions for every finite orchestration script \(\rho\):

1. **Observation equivalence.** Every outcome of \(\mathbb I\) is \(\equiv\)-matched by an outcome of \(\mathbb S\), and every outcome of \(\mathbb S\) is matched by one of \(\mathbb I\).
2. **Termination agreement.** The two systems have the same terminating, refused, and divergent outcomes under fair scheduling.
3. **No hidden acceptance.** An orchestration input is refused by \(\mathbb I\) exactly when its corresponding specification premise is false under the abstraction of §4.2.

The instrumentation makes rule choice observable through certificates. Consequently an implementation of the calculus must offer every enabled calculus transition, even if its production scheduler deterministically selects one of them in a particular execution. A weaker trace-refinement relation is useful for safety verification, but it cannot make exact equality of the finite rule table a necessary condition and is not the conformance relation characterized in this paper.

### 3.3 Observation simulation

**Definition 2 (observation bisimulation).** Let

\[
A:\mathrm{Reach}(\mathbb I)\to\Gamma_\mathbb S
\]

map each reachable implementation state to an abstract registry. A relation (R_A) is an observation bisimulation if:

- (A(i_0)=s_0);
- each orchestration transition of \(\mathbb I\) is matched by the corresponding transition or refusal of \(\mathbb S\);
- each lifecycle transition tagged ((r,n)) is matched by the (r)-transition of \(\mathbb S\) at (n), with equivalent events and successor abstraction;
- conversely, every orchestration or lifecycle transition enabled by \(\mathbb S\) has a correspondingly labeled implementation transition or refusal with an (A)-related successor;
- quiescent states have equivalent reports;
- fair settling terminates or diverges on the same scripts in the two systems.

**Lemma 1 (bisimulation implies conformance).** If (R_A) is an observation bisimulation, then \(\mathbb I\mathrel{\mathbf{conf}}\mathbb S\).

*Proof.* Induct over finite prefixes in both directions, matching orchestration and lifecycle transitions using the second through fourth bisimulation clauses. At a completed settle, use report agreement. At a refused input, use refusal agreement. The last clause matches divergence sensitivity. The \(\simeq/\approx\)-invariance lemma of [SZC26] transports the next rule across equivalent specification states. ∎

---

## 4. What makes finite characterization possible

### 4.1 The unrestricted impossibility result

**Proposition 1 (no unrestricted finite characterization).** Let (T) be any finite suite whose scripts mention finitely many names and keys and whose registries have size at most (b). There exists an implementation \(\mathbb I_T\) that passes (T) but does not conform to \(\mathbb S\).

*Proof.* Define \(\mathbb I_T\) to agree with \(\mathbb S\) on every state whose registry has at most (b) entries, and to suppress L-Begin for a satisfied fiber when the registry has (b+1) entries. It passes every test in (T) and violates termination and the final report of a script that inserts (b+1) otherwise independent fibers. A variant may instead deviate only on a fresh key absent from (T). ∎

This proposition fixes the role of the assumptions below. They are not technical decoration: some restriction of this kind is logically necessary.

### 4.2 Clause-factored implementations

For a rule (r), let (W_r\(\gamma,n\)) contain exactly the abstract fields read or written by the rule. We do not assume that the set of such windows is finite. Instead we factor it.

**Definition 3 (atomic signature).** For each rule (r), an atomic-signature map

\[
\kappa_r:W_r\to\mathcal M_{\mathrm{fin}}(\Sigma_r)
\]

decomposes a window into occurrences drawn from a finite alphabet \(\Sigma_r\). Each occurrence records:

1. the truth value of every primitive guard atom of (r);
2. the constructor selected by an iterator step, if any;
3. the equality pattern among the finitely many names, keys, values, and tags read by that atomic decision;
4. whether an existential or universal map condition has a witness or counterexample;
5. the normalized abstract update expected on one representative key, edge, or accumulator item.

Thus (\kappa_r(W)) is a finite family of occurrences from \(\Sigma_r\), not one unbounded “whole-window signature.” Large finite maps are represented through their atomic entries. For example, target construction is a product of singleton-key provider decisions; provision conflict is an existential fold over singleton comparisons; and \(\mathrm{relied}_n\) is an existential fold over installed committed-view edges. The alphabet \(\Sigma_r\) is finite because the rule has finitely many guard atoms and constructors and because equality patterns on finite support are finite.

For each (r), a reconstruction operator

\[
\mathrm{lift}_r
\]

combines the per-atom decisions and updates into the full rule result. `lift` is specified by the same finite-map unions, restrictions, existential folds, and accumulator composition operators used by [SZC26].

**Definition 4 (clause-factored implementation).** An implementation \(\mathbb I\) is admitted, written \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\), if the following obligations hold.

- **CF1 — faithful abstraction and complete tagging.** A total (A:\mathrm{Reach}\(\mathbb I\)\to\Gamma_\mathbb S) maps the initial state to the initial registry, preserves the fields exposed in reports, and tags every externally relevant transition with exactly one orchestration operation or calculus rule. There are no untagged transitions that change an abstract field or emit a P1 event.
- **CF2 — equivariance.** Renaming names, keys, values, and tags before a transition renames its result and events in the same way. Reserved runtime constants are listed and fixed.
- **CF3 — signature factorization.** For every (r), enablement, refusal, abstract update, and emitted events are obtained by applying one implementation table
  \[
  f_r^{\mathbb I}:\Sigma_r\to\mathrm{Decision}_r
  \]
  pointwise and combining the results with \(\mathrm{lift}_r\). In particular, the table cannot inspect registry cardinality, allocation order, unnormalized spelling, or the number of irrelevant witnesses.
- **CF4 — observational reflection.** If an entry of \(f_r^{\mathbb I}\) differs from the specification table \(f_r^{\mathbb S}\), the canonical experiment for that entry produces a different certificate, refusal, event, or quiescent report. Instrumentation is synchronous at the abstract transition boundary.
- **CF5 — canonical reachability.** Every reachable signature \(s\in\Sigma_r^{\mathrm{reach}}\) has a finite canonical orchestration script \(\rho_{r,s}\) that reaches it from the empty registry. The construction is invariant under renaming.
- **CF6 — settling.** The scheduler is fair among enabled lifecycle rules; `settle` terminates exactly when a quiescent state is reached; and divergence is returned as \(\mathsf{Diverge}\), not omitted from the outcome set.
- **CF7 — witness fidelity.** The inverses supplied by test components implement the witnessed inverse relation used by the calculus. Their composition and invocation remain implementation behavior and are tested through \(f_{\mathrm{L\mbox{-}Iter}}^{\mathbb I}\) and \(f_{\mathrm{L\mbox{-}Unload}}^{\mathbb I}\).

CF3 is the central audit. A source-level discharge identifies the program function corresponding to each \(f_r^{\mathbb I}\), shows that loops over keys and fibers use only the specified fold, and rules out branches on collection size or identity. A proof assistant, refinement-type checker, or careful code audit may discharge it; ordinary black-box tests cannot.

### 4.3 Specification factorization

**Lemma 2 (the calculus is clause-factored).** \(\mathbb S\in\mathfrak I_{\mathrm{CF}}\).

*Proof.* CF1 is the identity abstraction. CF2 is Lemma 56 of [SZC26]. For CF3, inspect Table 1: scalar premises are Boolean guard atoms; target construction is pointwise over (d_n); conflict, childlessness, and reliance are finite folds; writes are field assignments, finite-map operations, one iterator landing, or application of the accumulated inverse. These are precisely the reconstruction operators. CF4 holds because the specification emits its own certificate. CF5 is constructive: fresh fibers realize scalar states, one provider and one consumer realize a committed edge, and one tracked step realizes an accumulator item; unreachable signatures are discarded. CF6 follows from the progress theorem on its stated finite, acyclic domain and is checked directly for canonical quiet states outside that domain. CF7 is the witnessed-effect premise of Def. 8. ∎

---

## 5. Construction of the finite characteristic suite

### 5.1 Tests and verdicts

**Definition 5 (termination-sensitive test).** A test is a pair (t=\(\rho,V\)), where \(\rho\) is a finite orchestration script and (V) is a decidable predicate on the complete finite outcome set of a canonical experiment. An implementation passes (t) when:

1. its test explorer visits every fair choice up to quiescence, refusal, a repeated normalized state, or the specification's finite transition bound for that canonical scenario; and
2. (V(\mathrm{Out}_{\mathbb I}\(\rho\))) holds.

Thus a timeout or \(\mathsf{Diverge}\) is a failure whenever the specification's canonical run terminates.

### 5.2 Canonical experiments

For each rule (r) and reachable signature \(s\in\Sigma_r^{\mathrm{reach}}\), CF5 supplies a script \(\rho_{r,s}\). Its final action attempts (r), directly for orchestration rules and by one lifecycle step followed by settling for lifecycle rules. The verdict (V_{r,s}) requires equality, up to \(\equiv\), with the complete specification outcome set. Equivalently, it requires:

- enablement or refusal equal to (f_r^{\mathbb S}(s));
- an equal normalized certificate;
- the prescribed ordinary event word;
- the prescribed normalized successor report after settling;
- termination whenever the specification terminates.

Define

\[
T^\star
=\{(\rho_{r,s},V_{r,s})
  \mid r\in\mathrm{Rules},\ s\in\Sigma_r^{\mathrm{reach}}\}.
\]

**Lemma 3 (finiteness).** \(T^\star\) is finite.

*Proof.* The rule and operation constructor set is finite. Each \(\Sigma_r\) consists of finitely many Boolean guard valuations, step constructors, and equality patterns on finite support. A finite union of finite sets is finite, and restricting to reachable signatures preserves finiteness. ∎

### 5.3 Two representative canonical tests

**Accumulator order.** Insert a dependency-free component (P) whose script is

\[
\mathsf{track}(a);\mathsf{track}(b);\mathsf{track}(c).
\]

Settle, retire (P), and settle again. The verdict requires

\[
\mathsf{app}(P,a)<\mathsf{app}(P,b)<\mathsf{app}(P,c)
\]

and

\[
\mathsf{inv}(P,c)<\mathsf{inv}(P,b)<\mathsf{inv}(P,a).
\]

This realizes the nonempty-accumulator entry of the L-Iter/L-Unload table. CF3 extends the checked binary composition operator to accumulators of arbitrary finite length; the test alone does not make that induction.

**Reliance guard.** Insert provider (P) for (k) and consumer (C) with committed view (\omega_C(k)=P). Give (C)'s inverse a read of (k). Retire (P). The verdict requires (C)'s committed read of (P)'s value before any inverse of (P), then disposal of (P). This realizes the positive-witness entry of the existential reliance fold. CF3 extends the singleton witness to arbitrary registries.

### 5.4 Canonical-realization table

A publishable artifact must contain, not merely reference, a table with the following columns for every element of \(T^\star\):

| Field | Required content |
| --- | --- |
| Rule and signature | (r), guard valuation, step constructor, equality pattern |
| Reachability | derivation from the empty registry or proof of unreachability |
| Script | complete orchestration and component data |
| Verdict | exact predicate on certificates, events, report, and termination |
| Specification derivation | Table-1 row or coeffect equation used |
| Adapter observation | concrete field/event producing each abstract observation |

The table is part of the proof because Lemma 4 below depends on its surjectivity onto reachable signatures.

**Lemma 4 (canonical realization).** Every reachable \(s\in\Sigma_r^{\mathrm{reach}}\) is realized by a row of the canonical table, and its verdict accepts exactly the decision (f_r^{\mathbb S}(s)).

*Proof obligation.* This is a finite row-by-row derivation. It may be checked by executable enumeration, provided the checker explores the full finite transition graph rather than selected fifo/lifo policies. The generated table and checker output are archived with the artifact. ∎

---

## 6. The finite characterization theorem

### 6.1 Table equality

**Lemma 5 (passing determines the implementation tables).** Let \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\). If \(\mathbb I\models T^\star\), then

\[
f_r^{\mathbb I}(s)=f_r^{\mathbb S}(s)
\]

for every rule (r) and reachable signature \(s\in\Sigma_r^{\mathrm{reach}}\).

*Proof.* Suppose the tables differ at ((r,s)). By Lemma 4, \(T^\star\) contains the canonical experiment (t_{r,s}). By CF3, the implementation uses the differing table entry in that experiment. By CF4, the difference is reflected in its certificate, refusal, ordinary event, successor report, or termination outcome. Hence (V_{r,s}) fails, contradicting \(\mathbb I\models T^\star\). ∎

### 6.2 From table equality to simulation

**Lemma 6 (table equality yields observation bisimulation).** Let \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\). If all reachable table entries agree with \(\mathbb S\), then (R_A) is an observation bisimulation.

*Proof.* Initial states agree by CF1. Consider a reachable implementation transition tagged by (r) at (n). Apply \(\kappa_r\) to its abstract window. Every resulting atomic-signature occurrence is reachable. Table equality gives the same enablement, refusal, update, and events as the specification at every occurrence. CF3 applies the same reconstruction operator to those atomic decisions, so the full abstract successor equals the specification successor up to \(\simeq/\approx\). The same table equality shows conversely that every specification transition is offered by the implementation. CF1 excludes abstractly relevant untagged transitions. Induction establishes report agreement at quiescence. CF6 gives agreement of fair settling and divergence. ∎

### 6.3 Necessity and sufficiency

**Theorem 1 (finite characterization).** For every clause-factored implementation \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\),

\[
\boxed{
\mathbb I\mathrel{\mathbf{conf}}\mathbb S
\quad\Longleftrightarrow\quad
\mathbb I\models T^\star
}
\]

on the orchestration and component language of §2 and the termination domain of [SZC26].

*Proof.*

**Only if (necessity).** Each (V_{r,s}) is the observation predicate of the complete finite outcome set of its canonical specification experiment. If \(\mathbb I\mathrel{\mathbf{conf}}\mathbb S\), observation bisimulation gives the same normalized outcomes, refusals, rule certificates, and termination behavior. Therefore every canonical verdict holds.

**If (sufficiency).** If \(\mathbb I\models T^\star\), Lemma 5 gives equality of all reachable rule tables. Lemma 6 constructs an observation simulation, and Lemma 1 yields \(\mathbb I\mathrel{\mathbf{conf}}\mathbb S\). ∎

This theorem is the intended sense in which the finite test set is a necessary and sufficient verification condition. The finite test run is not the whole verification: membership in \(\mathfrak I_{\mathrm{CF}}\) is a separately auditable premise. Conversely, the audit does not assume the rule table is correct; that finite table is exactly what the suite determines.

### 6.4 Corollaries

**Corollary 1 (metatheory transfer).** If \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\) passes \(T^\star\), every observation-level consequence of the [SZC26] rules—recovery exactness, ordering, coherence, progress, and confluence on each theorem's stated domain—holds for \(\mathbb I\).

Composite M-tests are therefore useful regression and diagnostic scenarios, but they are not additional axioms needed for completeness once local table equality has been established.

**Corollary 2 (distribution).** Let (D) be a distribution layer with a proved termination-sensitive observation bisimulation between (D\(\mathbb I\)) and \(\mathbb I\) for every script in §2's language. If \(\mathbb I\in\mathfrak I_{\mathrm{CF}}\) passes \(T^\star\), then (D\(\mathbb I\)\mathrel{\mathbf{conf}}\mathbb S).

*Proof.* Theorem 1 gives \(\mathbb I\mathrel{\mathbf{conf}}\mathbb S\). Compose the distribution bisimulation with the bisimulation of Lemma 6. ∎

Running the same finite suite on two nodes is supporting evidence for the premise about (D); it is not by itself a proof of that premise.

---

## 7. The current 32-scenario catalog

The artifact beside this paper contains 32 named scenarios covering orchestration, activation, recovery, coeffects, access control, and five composite metatheory examples. They are valuable for three distinct purposes:

1. **Regression:** they execute representative behaviors of Cordis and the reference model.
2. **Diagnosis:** their focused traces localize failures to rule guards or updates.
3. **Mutation adequacy:** they kill a catalog of 27 deliberately introduced semantic deviations.

These facts must be kept separate from the characteristic-suite theorem.

### 7.1 Relating the catalog to \(T^\star\)

To claim that the 32 scenarios are exactly \(T^\star\), the artifact must additionally generate and check:

- the complete finite signature sets \(\Sigma_r^{\mathrm{reach}}\);
- the mapping from every signature to a scenario and verdict;
- the full state-space exploration for each canonical scenario;
- the CF1–CF4 audit for each concrete target adapter.

If several signatures share one scenario, that is harmless: one test may contain several transition certificates. If a signature has no row, the catalog is not yet complete. Counting tests and counting clauses need not coincide.

### 7.2 Mutation results

Let (M) be the finite mutant family. The appropriate reported properties are:

- **adequacy:** every mutant in (M) is killed by at least one test;
- **exclusive detection:** a test is mutation-essential when some mutant is killed by that test alone;
- **subsumption:** a test may detect a clause while all of its mutants are also detected elsewhere.

An injective assignment from tests to clause names provides traceability, not semantic minimality. Therefore the present results should be stated as “all 27 mutants killed; 14 scenarios have an exclusive mutant” unless a separate minimization computation proves more. The title and Theorem 1 do not require a minimal suite; they require a finite characteristic suite.

### 7.3 Exhaustive scheduling

For a canonical finite experiment, universal verdicts require exploration of every enabled lifecycle choice. Fifo, lifo, and seeded-random policies are useful smoke tests but are not an enumeration theorem. The model checker should memoize normalized states and explore every successor until quiescence, refusal, a repeated state, or the scenario's proved transition bound. This produces:

- all possible event words needed by a universal verdict;
- an actual proof that a mutant passes all non-killing tests;
- a reproducible witness trace for every failure;
- detection of divergence through cycles or bound violation.

---

## 8. Cordis case study

The current artifact has been applied to a reference model, a calculus-aligned Cordis build, the published Cordis 4.0.1 build, and a two-node deployment. The reported regression outcomes are:

| Target | Current 32-scenario result |
| --- | --- |
| Reference executable model | 32/32 under the sampled policies |
| Cordis-aligned build | 32/32 |
| Cordis 4.0.1 | 28/32 |
| Two-node deployment over Cordis 4.0.1 | 28/32, with the same four failures |

These are test results, not yet applications of Theorem 1. A target is certified by Theorem 1 only when its clause-factorization and adapter audits are published and the catalog is shown to cover all reachable signatures.

The four observed upstream divergences are nevertheless concrete:

- **R9.1 and M2:** provider inverses may start before dependent teardown completes, corresponding to an L-Unload reliance guard placed below the point where recovery tasks are launched.
- **R1.4:** insertion does not enforce declared-provision disjointness.
- **RU.1:** after a failed activation and later successful update, the earlier rejection may escape as a process-level unhandled rejection.

The two-node run has the same failure set as its underlying single-node build. The justified empirical statement is therefore:

> On these 32 scenarios and this deployment configuration, the distribution layer introduced no additional observed divergence.

The stronger distribution corollary requires the simulation premise of Corollary 2.

---

## 9. Corrections to the source correspondence

The conformance exercise exposed three issues in [SZC26]. They are independent of whether the current catalog is already characteristic.

### PB-1: Table 2 maps the wrong primitive

Def. 23's partial `set(k,v)` adds a fresh binding and supplies an inverse. In Cordis this behavior is implemented by `ctx.provide`, not `ctx.set`. The latter mutates an existing binding and corresponds to an \(\mathcal A_k\) operation of Def. 24. Any CF1 abstraction audit must use the corrected row.

### PB-2: active overwrite has two incompatible descriptions

The calculus gives an Active fiber no transition that performs an in-place overwrite. The prose of §5.1.3 says such an overwrite is not observed by dependents, while episode value-fixity suggests that an admitted overwrite must either be excluded from the episode or cause a complete withdraw–reinstall transition. The source should select and formalize one extension. A conformance suite cannot resolve an underspecified choice by accepting both and still call the result conformance to one specification.

### PB-3: Algorithm 10 races O-Insert's premise

O-Insert requires declared provisions to be disjoint from every registered fiber. Algorithm 10 calls `dispose()` and `use()` back-to-back. If disposal is only a retirement request, the old declaration remains registered when the new insertion is attempted. Correct replacement under the calculus is staged:

\[
\mathsf{retire}\ ;\ \mathsf{settle\mbox{-}to\mbox{-}remove}\ ;\ \mathsf{insert}.
\]

Alternatively the calculus needs an atomic replacement rule with its own premises and proof.

---

## 10. Threats to validity and audit obligations

1. **Factorization is substantive.** CF3 excludes size-sensitive and global special cases. It must be demonstrated for each build; a successful test run does not establish it.
2. **Instrumentation can be wrong.** CF1 and CF4 place the adapter in the trusted base. Adapter code should be small, versioned, and reviewed field by field.
3. **Canonical signatures must be complete.** Omitting a guard atom or equality pattern invalidates Lemma 4. Signature generation should be derived from a machine-readable rule table.
4. **Finite-map decomposition must match the code.** A loop that is pointwise in the specification but branches on collection length in the implementation violates CF3.
5. **Scheduler exploration must be exhaustive.** Selected policies establish witnesses, not universal passing results.
6. **Metatheorem domains remain in force.** Progress and confluence transfer only under the acyclicity, finiteness, totality, and independence hypotheses stated by [SZC26].
7. **Real host code exceeds the test language.** Native callbacks, I/O, cancellation, garbage collection, and process failure require either additional signatures or an explicit boundary.
8. **Version claims require immutable artifacts.** Published results should record commit hashes, Node version, adapter hash, target package hash, and raw logs.

---

## 11. Related work

Gaudel's algebraic-testing framework [Gau95] supplies the essential methodological point: finite completeness is relative to regularity and uniformity hypotheses. Clause factorization makes those hypotheses concrete for the registry rules of [SZC26]. Tretmans' ioco theory [Tre96, Tre08] motivates the explicit treatment of refusals and quiescence; our relation is specialized to a known rule-tagged implementation boundary and is termination-sensitive. Mutation testing [DLS78, JH11, PAO17] evaluates a suite against a selected fault model but does not on its own prove completeness or minimality. Executable semantics frameworks such as PLT Redex [Fel09] and K [RŞ10] motivate deriving test oracles from operational rules. The distinctive contribution here is the finite signature quotient connecting a dynamic plugin calculus to a necessary-and-sufficient executable judgment for an audited implementation class.

---

## 12. Conclusion

The statement “Cordis implements the plugin-system calculus” has two different proof obligations. The first is structural: concrete transitions must admit a faithful, equivariant, clause-factored abstraction with exact instrumentation and settling. The second is finite and executable: the implementation's table on every reachable normalized rule signature must equal the calculus's table.

Neither obligation subsumes the other. The audit rules out hidden dimensions that no finite suite can see; the suite determines the semantic decisions that an audit should not simply assume. Together they yield the desired verification criterion:

\[
\mathbb I\in\mathfrak I_{\mathrm{CF}}
\quad\Longrightarrow\quad
\bigl(
\mathbb I\mathrel{\mathbf{conf}}\mathbb S
\iff
\mathbb I\models T^\star
\bigr).
\]

This is a finite necessary-and-sufficient characterization of plugin-system conformance, with its trusted boundary visible. The current Cordis catalog supplies substantial material for the canonical suite and has already found real implementation and specification defects. Completing its signature table, exhaustive scheduler exploration, and build audits would turn that material into a direct instance of the theorem.

---

## Appendix A. Artifact acceptance checklist

A release claiming application of Theorem 1 should include:

- [ ] a machine-readable list of rules, primitive guard atoms, and atomic update constructors;
- [ ] generated finite sets \(\Sigma_r^{\mathrm{reach}}\);
- [ ] a canonical script and exact verdict for every reachable signature;
- [ ] derivations or checked reachability traces for every row;
- [ ] exhaustive state-space results, including divergence detection;
- [ ] the CF1 adapter map, field by field;
- [ ] the CF2–CF3 source audit, including every loop/fold over fibers and keys;
- [ ] the CF4 observation-reflection audit;
- [ ] the CF6 scheduler and settle audit;
- [ ] immutable versions and raw logs for every tested build.

## Appendix B. Recommended artifact commands

The current harness should expose separate commands for three different judgments:

```sh
# Regression only: execute the named scenarios.
node --test --experimental-test-isolation=none tests/*.test.mjs

# Characteristic-suite proof: generate signatures/table and explore every
# finite successor, rather than sampling scheduling policies.
node generate-signatures.mjs
node check-canonical-suite.mjs

# Mutation study: report adequacy, exclusive killers, and redundant tests as
# separate results; fail if the requested property is false.
node run-necessity.mjs
```

The latter two commands name required artifact components; they must be supplied before the current 32-scenario catalog is advertised as the concrete \(T^\star\).

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026.
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model Based Testing with Labelled Transition Systems.* In *Formal Methods and Testing*, LNCS 4949, 2008.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on Test Data Selection.* IEEE Computer 11(4), 1978.
- [JH11] Y. Jia, M. Harman. *An Analysis and Survey of the Development of Mutation Testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis, Y. Jia, M. Harman, et al. *Mutation Testing Advances: An Analysis and Survey.* Advances in Computers, 2017.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An Overview of the K Semantic Framework.* Journal of Logic and Algebraic Programming 79(6), 2010.
