/-
  Bounded/Charact.lean — Theorem D (bounded characterization).

  A *bounded implementation* is a successor function of the specification's
  type that is clause-factored: it decides through the computable signature
  abstraction `sig` by some table `fI : SigR → Dec` and reconstructs with the
  shared `liftStep` (obligation CF3 of the companion paper, as a hypothesis).
  `implStep fI` is exactly that composite, and `specStep = implStep fS`
  definitionally (bounded Lemma 2 / factorization).

  CERTIFICATES.  §6.3 of the paper proves that observation reflection is
  *false* in the event-and-report vocabulary alone: there is a rule aspect no
  script can observe, so equal event words and equal successor reports do not
  force equal transitions.  That failure is reproduced here as a machine
  checked fact (`reflect_fails`).  The paper's remedy is the one adopted
  here: a test row carries the *transition certificate* (r, ŝ, â) — the rule,
  its normalized signature, and the decision taken — alongside the ordinary
  observation, exactly as §5.4 defines the verdict V_{r,s}.  With
  certificates, reflection is not merely true but definitional, and Theorem D
  goes through structurally with no computational step.

  The bounded suite T_B is the explored graph presented as tests: for every
  explored state, its recorded access word extended by every probe label.
-/
import Bounded.Explore

namespace Bounded

/-- A clause-factored bounded implementation: table + shared lift + shared
    signature abstraction. -/
def implStep (fI : SigR → Dec) (a : Act) (γ : Config) : Option (Ev × Config) :=
  liftStep a γ (fI (sig a γ))

/-- The specification is itself clause-factored (bounded Lemma 2 — CF3 for 𝕊
    holds definitionally in this mechanization). -/
theorem specStep_factored : specStep = implStep fS := rfl

theorem implStep_fS (a : Act) (γ : Config) : implStep fS a γ = specStep a γ := rfl

/- ------------------------------------------------------------------ -/
/- Computational facts about the shipped exploration.                  -/
/- ------------------------------------------------------------------ -/

/-- Every explored state satisfies the single-source discipline (Def. 43/45):
    a key has at most one Active provider.  This is what makes the least-slot
    scan in `providerOf` canonical, and it is the hypothesis under which
    Theorem A's equivariance holds.
    (`native_decide`; adds compiler trust — see PROOF_STATUS.md.) -/
theorem wf_visited : ∀ γ ∈ visited, WF γ := by native_decide

/-- **Observation reflection fails without certificates** — the bounded,
    machine-checked instance of the paper's §6.3 negative result.  There are
    an explored state, a probe label, and a decision that produce the same
    event word and the same successor observation as the specification's
    decision, yet a different successor state.  Consequently the suite must
    compare certificates, not merely events and reports; see `rowOf` below.
    (`native_decide`; adds compiler trust — see PROOF_STATUS.md.) -/
theorem reflect_fails :
    ¬ (∀ p ∈ visitedP, ∀ a ∈ catalogActs, ∀ d : Dec,
        obsRow (liftStep a p.1 d) = obsRow (specStep a p.1) →
        liftStep a p.1 d = specStep a p.1) := by
  native_decide

/- ------------------------------------------------------------------ -/
/- Certificates and test trajectories.                                 -/
/- ------------------------------------------------------------------ -/

/-- A transition certificate (§5.4): the rule attempted, the normalized
    signature of its window, and the decision taken there. -/
abbrev Cert := Rule × SigR × Dec

def certOf (fI : SigR → Dec) (a : Act) (γ : Config) : Cert :=
  (a.rule, sig a γ, fI (sig a γ))

/-- One row of a test trajectory: the certificate, and the observable
    outcome — `none` for a refusal, `some (event word, successor
    observation)` otherwise. -/
abbrev Row := Cert × Option (Ev × Obs)

def rowOf (fI : SigR → Dec) (a : Act) (γ : Config) : Row :=
  (certOf fI a γ, obsRow (implStep fI a γ))

/-- The state a probe leaves behind: a refusal leaves the state unchanged. -/
def nextState (fI : SigR → Dec) (a : Act) (γ : Config) : Config :=
  match implStep fI a γ with
  | none => γ
  | some p => p.2

theorem nextState_none {fI : SigR → Dec} {a : Act} {γ : Config}
    (h : implStep fI a γ = none) : nextState fI a γ = γ := by
  unfold nextState; rw [h]

theorem nextState_some {fI : SigR → Dec} {a : Act} {γ : Config} {p : Ev × Config}
    (h : implStep fI a γ = some p) : nextState fI a γ = p.2 := by
  unfold nextState; rw [h]

/-- Observation trajectory of a label word: one row per label. -/
def runObs (fI : SigR → Dec) : Config → List Act → List Row
  | _, [] => []
  | γ, a :: as => rowOf fI a γ :: runObs fI (nextState fI a γ) as

/-- End state of a trajectory. -/
def runState (fI : SigR → Dec) : Config → List Act → Config
  | γ, [] => γ
  | γ, a :: as => runState fI (nextState fI a γ) as

/-- The bounded suite T_B: every explored state's access word, extended by
    every probe label. -/
def suite : List (List Act) :=
  visitedP.flatMap fun p => catalogActs.map fun a => p.2 ++ [a]

/-- Passing T_B: the implementation's trajectory — certificates included —
    equals the specification's on every suite word. -/
def AgreesOnTB (fI : SigR → Dec) : Prop :=
  ∀ w ∈ suite, runObs fI γ0 w = runObs fS γ0 w

/-- Agreement of the decision tables at every reachable window.  This is what
    the canonical experiments of T⋆ pin down (§5.4, Remark 2). -/
def AgreesOnReach (fI : SigR → Dec) : Prop :=
  ∀ γ ∈ visited, ∀ a ∈ catalogActs, fI (sig a γ) = fS (sig a γ)

/- ---- certificates force transitions ---- -/

/-- Reflection, with certificates: equal certificates give equal table values
    at the window. -/
theorem table_eq_of_cert {fI : SigR → Dec} {a : Act} {γ : Config}
    (h : certOf fI a γ = certOf fS a γ) : fI (sig a γ) = fS (sig a γ) :=
  congrArg (fun c => c.2.2) h

/-- …and equal table values give literally equal transitions, because both
    sides reconstruct with the same `liftStep`. -/
theorem step_eq_of_table {fI : SigR → Dec} {a : Act} {γ : Config}
    (h : fI (sig a γ) = fS (sig a γ)) : implStep fI a γ = implStep fS a γ := by
  show liftStep a γ (fI (sig a γ)) = liftStep a γ (fS (sig a γ))
  rw [h]

/- ---- basic trajectory lemmas ---- -/

theorem runObs_append (fI : SigR → Dec) (γ : Config) (u v : List Act) :
    runObs fI γ (u ++ v) =
      runObs fI γ u ++ runObs fI (runState fI γ u) v := by
  induction u generalizing γ with
  | nil => rfl
  | cons a as ih =>
    simp only [List.cons_append, runObs, runState]
    rw [ih]

theorem runObs_length (fI : SigR → Dec) (γ : Config) (w : List Act) :
    (runObs fI γ w).length = w.length := by
  induction w generalizing γ with
  | nil => rfl
  | cons a as ih => simp only [runObs, List.length_cons]; rw [ih]

theorem runState_runFrom {γ γf : Config} {w : List Act}
    (h : runFrom γ w = some γf) : runState fS γ w = γf := by
  induction w generalizing γ with
  | nil => simpa [runFrom, runState] using h
  | cons a as ih =>
    simp only [runFrom] at h
    simp only [runState]
    cases hs : specStep a γ with
    | none => rw [hs] at h; cases h
    | some p =>
      rw [hs] at h
      rw [nextState_some (fI := fS) (a := a) (γ := γ) (p := p) hs]
      exact ih h

theorem mem_visitedP_of_visited {γ : Config} (h : γ ∈ visited) :
    ∃ p ∈ visitedP, p.1 = γ := by
  obtain ⟨p, hp, hpc⟩ := List.mem_map.mp h
  exact ⟨p, hp, hpc⟩

/- ---- trajectory forcing ---- -/

/-- If a clause-factored implementation's certified trajectory from a visited
    state equals the specification's, then the two runs visit literally the
    same states, and stay inside the explored set. -/
theorem traj_forcing (fI : SigR → Dec) :
    ∀ (w : List Act) (γ : Config), γ ∈ visited →
      (∀ b ∈ w, b ∈ catalogActs) →
      runObs fI γ w = runObs fS γ w →
      runState fI γ w = runState fS γ w ∧ runState fS γ w ∈ visited := by
  intro w
  induction w with
  | nil => intro γ hγ _ _; exact ⟨rfl, hγ⟩
  | cons a as ih =>
    intro γ hγ hcat hobs
    have hacat : a ∈ catalogActs := hcat a (List.mem_cons_self ..)
    have hrest : ∀ b ∈ as, b ∈ catalogActs :=
      fun b hb => hcat b (List.mem_cons_of_mem _ hb)
    simp only [runObs, List.cons.injEq] at hobs
    have htab : fI (sig a γ) = fS (sig a γ) :=
      table_eq_of_cert (congrArg Prod.fst hobs.1)
    have hstep : implStep fI a γ = implStep fS a γ := step_eq_of_table htab
    have hnext : nextState fI a γ = nextState fS a γ := by
      unfold nextState; rw [hstep]
    have htail := hobs.2
    rw [hnext] at htail
    simp only [runState, hnext]
    cases hsp : implStep fS a γ with
    | none =>
      rw [nextState_none hsp] at htail ⊢
      exact ih γ hγ hrest htail
    | some q =>
      rw [nextState_some hsp] at htail ⊢
      have hvis : q.2 ∈ visited :=
        visited_closed γ hγ (a, q.2)
          (succsOf_mem hacat (show specStep a γ = some (q.1, q.2) by
            show implStep fS a γ = some (q.1, q.2); rw [hsp]))
      exact ih q.2 hvis hrest htail

/-- **Pointwise table agreement on the explored set, from T_B agreement.**
    Each explored state's access word is a suite prefix; the last row of the
    corresponding suite word carries the certificate at that state. -/
theorem agree_pointwise (fI : SigR → Dec) (hA : AgreesOnTB fI) :
    AgreesOnReach fI := by
  intro γ hγ a ha
  obtain ⟨p, hp, hpc⟩ := mem_visitedP_of_visited hγ
  obtain ⟨hwcat, hrun⟩ := explore_sound p hp
  have hw : p.2 ++ [a] ∈ suite :=
    List.mem_flatMap.mpr ⟨p, hp, List.mem_map.mpr ⟨a, ha, rfl⟩⟩
  have hobs := hA _ hw
  rw [runObs_append, runObs_append] at hobs
  have hlen : (runObs fI γ0 p.2).length = (runObs fS γ0 p.2).length := by
    rw [runObs_length, runObs_length]
  have hprefix : runObs fI γ0 p.2 = runObs fS γ0 p.2 :=
    List.append_inj_left hobs hlen
  have hforce := traj_forcing fI p.2 γ0 gamma0_visited hwcat hprefix
  have hspecend : runState fS γ0 p.2 = γ := hpc ▸ runState_runFrom hrun
  have hsuffix : runObs fI (runState fI γ0 p.2) [a] =
      runObs fS (runState fS γ0 p.2) [a] :=
    List.append_inj_right hobs hlen
  rw [hforce.1, hspecend] at hsuffix
  simp only [runObs, List.cons.injEq] at hsuffix
  exact table_eq_of_cert (congrArg Prod.fst hsuffix.1)

/-- Conversely, table agreement on the explored set gives trajectory equality
    on every catalog word replayed from an explored state (such a replay never
    leaves the explored set, by `visited_closed`). -/
theorem runObs_eq_of_agree (fI : SigR → Dec) (h : AgreesOnReach fI) :
    ∀ (w : List Act), (∀ b ∈ w, b ∈ catalogActs) →
      ∀ γ, γ ∈ visited → runObs fI γ w = runObs fS γ w := by
  intro w
  induction w with
  | nil => intro _ γ _; rfl
  | cons a as ih =>
    intro hcat γ hγ
    have hacat : a ∈ catalogActs := hcat a (List.mem_cons_self ..)
    have hrest : ∀ b ∈ as, b ∈ catalogActs :=
      fun b hb => hcat b (List.mem_cons_of_mem _ hb)
    have htab : fI (sig a γ) = fS (sig a γ) := h γ hγ a hacat
    have hstep : implStep fI a γ = implStep fS a γ := step_eq_of_table htab
    have hrow : rowOf fI a γ = rowOf fS a γ := by
      show (certOf fI a γ, obsRow (implStep fI a γ))
          = (certOf fS a γ, obsRow (implStep fS a γ))
      rw [hstep]
      show ((a.rule, sig a γ, fI (sig a γ)), _) = ((a.rule, sig a γ, fS (sig a γ)), _)
      rw [htab]
    have hnext : nextState fI a γ = nextState fS a γ := by
      unfold nextState; rw [hstep]
    simp only [runObs]
    rw [hrow, hnext]
    refine congrArg _ ?_
    cases hsp : implStep fS a γ with
    | none => rw [nextState_none hsp]; exact ih hrest γ hγ
    | some q =>
      rw [nextState_some hsp]
      have hvis : q.2 ∈ visited :=
        visited_closed γ hγ (a, q.2)
          (succsOf_mem hacat (show specStep a γ = some (q.1, q.2) by
            show implStep fS a γ = some (q.1, q.2); rw [hsp]))
      exact ih hrest q.2 hvis

theorem suite_words_catalog : ∀ w ∈ suite, ∀ b ∈ w, b ∈ catalogActs := by
  intro w hw b hb
  obtain ⟨p, hp, hmap⟩ := List.mem_flatMap.mp hw
  obtain ⟨a, ha, hwa⟩ := List.mem_map.mp hmap
  subst hwa
  rcases List.mem_append.mp hb with hb | hb
  · exact (explore_sound p hp).1 b hb
  · cases hb with
    | head => exact ha
    | tail _ h => cases h

/- ------------------------------------------------------------------ -/
/- Observation bisimulation on the bounded domain.                     -/
/- ------------------------------------------------------------------ -/

/-- Certified observation bisimulation for the bounded (deterministic-per-
    label) systems: related states are observation-equal and match every probe
    label — equal certificates, equal refusals, equal event words, related
    successors.  This is the bounded reading of `conf` (§3): termination is
    not at issue because every probe is a single step. -/
def IsBisim (f g : SigR → Dec) (R : Config → Config → Prop) : Prop :=
  ∀ c1 c2, R c1 c2 →
    obs c1 = obs c2 ∧
    ∀ a ∈ catalogActs,
      certOf f a c1 = certOf g a c2 ∧
      ((implStep f a c1 = none ∧ implStep g a c2 = none) ∨
        (∃ e c1' c2', implStep f a c1 = some (e, c1') ∧
          implStep g a c2 = some (e, c2') ∧ R c1' c2'))

def Bisimilar (f g : SigR → Dec) : Prop := ∃ R, IsBisim f g R ∧ R γ0 γ0

/-- Bisimilar states have equal certified trajectories on catalog words. -/
theorem bisim_runObs {f g R} (hR : IsBisim f g R) :
    ∀ (w : List Act), (∀ b ∈ w, b ∈ catalogActs) →
      ∀ c1 c2, R c1 c2 → runObs f c1 w = runObs g c2 w := by
  intro w
  induction w with
  | nil => intro _ c1 c2 _; rfl
  | cons a as ih =>
    intro hcat c1 c2 hc
    have hrest : ∀ b ∈ as, b ∈ catalogActs :=
      fun b hb => hcat b (List.mem_cons_of_mem _ hb)
    obtain ⟨hcert, hmatch⟩ := (hR c1 c2 hc).2 a (hcat a (List.mem_cons_self ..))
    simp only [runObs]
    rcases hmatch with ⟨h1, h2⟩ | ⟨e, c1', c2', h1, h2, hr⟩
    · have hrow : rowOf f a c1 = rowOf g a c2 := by
        show (certOf f a c1, obsRow (implStep f a c1))
            = (certOf g a c2, obsRow (implStep g a c2))
        rw [hcert, h1, h2]
      rw [hrow, nextState_none h1, nextState_none h2]
      exact congrArg _ (ih hrest c1 c2 hc)
    · have hobs : obs c1' = obs c2' := (hR c1' c2' hr).1
      have hrow : rowOf f a c1 = rowOf g a c2 := by
        show (certOf f a c1, obsRow (implStep f a c1))
            = (certOf g a c2, obsRow (implStep g a c2))
        rw [hcert, h1, h2]
        show (certOf g a c2, some (e, obs c1')) = (certOf g a c2, some (e, obs c2'))
        rw [hobs]
      rw [hrow, nextState_some h1, nextState_some h2]
      exact congrArg _ (ih hrest c1' c2' hr)

/-- **Theorem D (bounded characterization).**  A clause-factored bounded
    implementation agrees with the specification on the bounded suite T_B
    iff it is certified-observation-bisimilar to the specification on the
    bounded domain.  Proved structurally; no computational step. -/
theorem theoremD (fI : SigR → Dec) :
    AgreesOnTB fI ↔ Bisimilar fI fS := by
  constructor
  · intro hA
    have hreach : AgreesOnReach fI := agree_pointwise fI hA
    refine ⟨fun c1 c2 => c1 = c2 ∧ c1 ∈ visited, ?_, rfl, gamma0_visited⟩
    intro c1 c2 hc
    obtain ⟨rfl, hvis⟩ := hc
    refine ⟨rfl, ?_⟩
    intro a ha
    have htab : fI (sig a c1) = fS (sig a c1) := hreach c1 hvis a ha
    have hstep : implStep fI a c1 = implStep fS a c1 := step_eq_of_table htab
    have hcert : certOf fI a c1 = certOf fS a c1 := by
      show (a.rule, sig a c1, fI (sig a c1)) = (a.rule, sig a c1, fS (sig a c1))
      rw [htab]
    refine ⟨hcert, ?_⟩
    cases hsp : implStep fS a c1 with
    | none => exact .inl ⟨hstep.trans hsp, rfl⟩
    | some q =>
      have hq : implStep fS a c1 = some (q.1, q.2) := hsp
      exact .inr ⟨q.1, q.2, q.2, hstep.trans hq, rfl, rfl,
        visited_closed c1 hvis (a, q.2) (succsOf_mem ha hq)⟩
  · intro ⟨R, hR, hR0⟩ w hw
    exact bisim_runObs hR w (suite_words_catalog w hw) γ0 γ0 hR0

/-- T_B agreement is equivalent to table agreement at every reachable window
    (both directions unconditional). -/
theorem agreesOnTB_iff_reach (fI : SigR → Dec) :
    AgreesOnTB fI ↔ AgreesOnReach fI := by
  refine ⟨agree_pointwise fI, fun h w hw => ?_⟩
  exact runObs_eq_of_agree fI h w (suite_words_catalog w hw) γ0 gamma0_visited

end Bounded
