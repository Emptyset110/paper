/-
  Bounded/Cutoff.lean — Theorem E (the cutoff, as the single named axiom) and
  Theorem F (the final conditional characterization).

  Everything in Bounded/Charact.lean is about the *explored* part of the
  bounded domain: `visited` is the reachable set (Theorem C), and Theorem D
  characterizes agreement on the generated suite `suite` (= T_B) in terms of
  certified observation bisimulation from γ₀.  All of that is unconditional.

  What no finite computation in this development establishes is the step from
  "agrees with the specification at every *reachable* bounded window" to
  "agrees with the specification at every bounded configuration".  That step
  is exactly the paper's Lemma 4 (transport, §6.2): a clause-factored
  implementation consults nothing but the normalized occurrence multiset
  κ_r(W), so a decision pinned at one window is pinned at every κ-equal
  window — including windows of configurations the explorer never visits.

  It is stated here as ONE axiom, `transport_cutoff`, and nothing else in the
  development is axiomatic.  Theorem F is derived from it together with
  Theorem D.
-/
import Bounded.Charact

namespace Bounded

/-- Bounded conformance: the implementation and the specification agree at
    *every* configuration of the bounded domain and every probe label —
    reachable or not.  This is strictly stronger than `Bisimilar`, which only
    constrains the part of the domain reachable from γ₀. -/
def ConfB (fI : SigR → Dec) : Prop :=
  ∀ (a : Act) (γ : Config), implStep fI a γ = specStep a γ

/-! ### Theorem E — the cutoff axiom -/

/--
  **Theorem E (transport / cutoff).  THE SINGLE NAMED AXIOM.**

  Paper correspondence: Lemma 4 (transport), §6.2, clauses (1)–(3), consumed
  as in Remark 2 — "the suite pins `f_r^I` at the canonical window, and
  transport carries the per-occurrence pin everywhere".

  Statement: for a clause-factored bounded implementation — one that decides
  through the shared signature abstraction `sig` by a table `fI` and
  reconstructs with the shared operator `liftStep`, which is precisely the
  shape of `implStep fI` — agreement of the decision table with the
  specification's at every *reachable* window implies agreement of the
  successor functions at every bounded configuration.

  Why this is not mechanized.  The conclusion quantifies over the whole of
  `Config`, whose cardinality at the shipped bound is around 10^44 (Theorem B
  gives finiteness, not tractability), and over signatures that the reachable
  windows never exhibit.  The paper's proof does not enumerate either: it
  argues that both sides factor through κ, that a decision is a function of
  the occurrence multiset alone, and that `liftStep` is the same operator on
  both sides so the frames correspond automatically.  That argument is on
  paper; this axiom is its interface.
-/
axiom transport_cutoff (fI : SigR → Dec) : AgreesOnReach fI → ConfB fI

/-! ### Consequences -/

/-- A totally agreeing implementation is literally the specification's
    successor function. -/
theorem confB_eq (fI : SigR → Dec) (h : ConfB fI) : implStep fI = specStep :=
  funext fun a => funext fun γ => h a γ

/-- **Theorem F (final conditional characterization).**

    For every clause-factored bounded implementation the following are
    equivalent, unconditionally:

    * it passes the generated bounded suite T_B (`AgreesOnTB`);
    * it is certified-observation-bisimilar to the specification from γ₀
      (`Bisimilar · fS`) — the bounded reading of `I conf S`;
    * its decision table agrees with the specification's at every reachable
      window (`AgreesOnReach`).

    Modulo the cutoff axiom (Theorem E) they further imply agreement on the
    *whole* bounded domain, `ConfB`.

    The last implication is one-directional on purpose.  `ConfB` does **not**
    imply the others: `liftStep` is not injective in its decision argument, so
    two tables can induce the same successor function everywhere while
    differing on a signature whose window makes the difference inert (for
    instance `fire std` versus `fire fifoAcc` at a signature that forces an
    empty accumulator).  The suite sees the difference because it compares
    transition certificates; the successor function does not.  This is the
    table-level shadow of `reflect_fails`. -/
theorem theoremF (fI : SigR → Dec) :
    (AgreesOnTB fI ↔ Bisimilar fI fS) ∧
    (AgreesOnTB fI ↔ AgreesOnReach fI) ∧
    (AgreesOnTB fI → ConfB fI) :=
  ⟨theoremD fI, agreesOnTB_iff_reach fI,
    fun h => transport_cutoff fI (agree_pointwise fI h)⟩

/-- **Theorem F, the paper's reading.**  A clause-factored bounded
    implementation conforms to the specification (certified observation
    bisimulation on the bounded domain) **iff** it passes the generated suite
    T_B.  Unconditional; this is Theorem D restated. -/
theorem conformance_iff_passes_suite (fI : SigR → Dec) :
    Bisimilar fI fS ↔ AgreesOnTB fI :=
  (theoremD fI).symm

/-- **Theorem F, the cutoff strengthening.**  Modulo `transport_cutoff`,
    passing T_B additionally forces agreement at every configuration of the
    bounded domain, reachable or not. -/
theorem passes_suite_implies_confB (fI : SigR → Dec) :
    AgreesOnTB fI → ConfB fI := (theoremF fI).2.2

end Bounded
