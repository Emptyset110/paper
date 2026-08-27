/-
  Bounded/Charact.lean — Theorem D (bounded characterization).

  A *bounded implementation* is a successor function of the specification's
  type that is clause-factored: it decides through the computable signature
  abstraction `sig` by some table `fI : SigR → Dec` and reconstructs with the
  shared `liftStep` (obligation CF3 of the companion paper, as a hypothesis).

  The bounded suite T_B is the explored graph presented as tests: for every
  explored state, its recorded access word extended by every probe label; a
  test's observation is the trajectory of (event word, state observation)
  rows, refusals included as `none` rows.

  Theorem D: a clause-factored bounded implementation agrees with the
  specification on T_B's observations iff it is observation-bisimilar to the
  specification on the bounded domain.

  Finite ingredients discharged computationally (`native_decide`, listed in
  PROOF_STATUS.md): the frontier-empty fact for the shipped exploration and
  the observation-reflection check `reflectOK` (bounded CF4).
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

/- ------------------------------------------------------------------ -/
/- Computational facts about the shipped exploration.                  -/
/- ------------------------------------------------------------------ -/

/-- The shipped exploration terminates with an empty frontier.
    (Computational; adds compiler trust — see PROOF_STATUS.md.) -/
theorem frontier_empty : exploreResult.todo = [] := by native_decide

/-- **Observation reflection** (bounded CF4): at every explored state and
    probe label, decisions that lift to observably equal rows lift to equal
    transitions.  (Computational; adds compiler trust.) -/
theorem reflectOK : ∀ p ∈ visitedP, ∀ a ∈ catalogActs, ∀ d : Dec,
    obsRow (liftStep a p.1 d) = obsRow (specStep a p.1) →
    liftStep a p.1 d = specStep a p.1 := by native_decide

/-- Every explored state satisfies the single-source discipline (Def. 43/45).
    (Computational; adds compiler trust.) -/
theorem wf_visited : ∀ γ ∈ visited, WF γ := by native_decide

/- ------------------------------------------------------------------ -/
/- Test trajectories.                                                  -/
/- ------------------------------------------------------------------ -/

/-- Observation trajectory of a label word: one row per label — `none` for a
    refusal/disabled probe (the state is unchanged), `some (events, state
    observation)` otherwise. -/
def runObs (step : Act → Config → Option (Ev × Config)) :
    Config → List Act → List (Option (Ev × Obs))
  | _, [] => []
  | γ, a :: as =>
    match step a γ with
    | none => none :: runObs step γ as
    | some p => some (p.1, obs p.2) :: runObs step p.2 as

/-- End state of a trajectory (refusals leave the state unchanged). -/
def runState (step : Act → Config → Option (Ev × Config)) :
    Config → List Act → Config
  | γ, [] => γ
  | γ, a :: as =>
    match step a γ with
    | none => runState step γ as
    | some p => runState step p.2 as

/-- The bounded suite T_B: every explored state's access word, extended by
    every probe label. -/
def suite : List (List Act) :=
  visitedP.flatMap fun p => catalogActs.map fun a => p.2 ++ [a]

/-- Passing T_B: the implementation's observation trajectory equals the
    specification's on every suite word. -/
def AgreesOnTB (step : Act → Config → Option (Ev × Config)) : Prop :=
  ∀ w ∈ suite, runObs step γ0 w = runObs specStep γ0 w

/- ---- basic trajectory lemmas ---- -/

theorem runObs_append (step) (γ : Config) (u v : List Act) :
    runObs step γ (u ++ v) =
      runObs step γ u ++ runObs step (runState step γ u) v := by
  induction u generalizing γ with
  | nil => simp [runObs, runState]
  | cons a as ih =>
    simp only [List.cons_append, runObs, runState]
    cases step a γ with
    | none => simp only [ih]
    | some p => simp only [ih]

theorem runObs_length (step) (γ : Config) (w : List Act) :
    (runObs step γ w).length = w.length := by
  induction w generalizing γ with
  | nil => rfl
  | cons a as ih =>
    simp only [runObs]
    cases step a γ with
    | none => simp [ih]
    | some p => simp [ih]

theorem runState_runFrom {γ γf : Config} {w : List Act}
    (h : runFrom γ w = some γf) : runState specStep γ w = γf := by
  induction w generalizing γ with
  | nil => simpa [runFrom, runState] using h
  | cons a as ih =>
    simp only [runFrom] at h
    simp only [runState]
    cases hs : specStep a γ with
    | none => rw [hs] at h; cases h
    | some p => rw [hs] at h; exact ih h

/- ---- trajectory forcing (uses reflectOK) ---- -/

theorem mem_visitedP_of_visited {γ : Config} (h : γ ∈ visited) :
    ∃ p ∈ visitedP, p.1 = γ := by
  obtain ⟨p, hp, hpc⟩ := List.mem_map.mp h
  exact ⟨p, hp, hpc⟩

/-- If a clause-factored implementation's trajectory is observably equal to
    the specification's from a visited state, the trajectories are literally
    equal (states coincide throughout). -/
theorem traj_forcing (fI : SigR → Dec) :
    ∀ (w : List Act) (γ : Config), γ ∈ visited →
      (∀ b ∈ w, b ∈ catalogActs) →
      runObs (implStep fI) γ w = runObs specStep γ w →
      runState (implStep fI) γ w = runState specStep γ w ∧
        runState specStep γ w ∈ visited := by
  intro w
  induction w with
  | nil => intro γ hγ _ _; exact ⟨rfl, hγ⟩
  | cons a as ih =>
    intro γ hγ hcat hobs
    obtain ⟨p, hp, hpc⟩ := mem_visitedP_of_visited hγ
    have hacat : a ∈ catalogActs := hcat a (List.mem_cons_self ..)
    simp only [runObs] at hobs
    simp only [runState]
    cases hsp : specStep a γ with
    | none =>
      cases hsi : implStep fI a γ with
      | none =>
        rw [hsp, hsi] at hobs
        simp only [List.cons.injEq] at hobs
        exact ih γ hγ (fun b hb => hcat b (List.mem_cons_of_mem _ hb)) hobs.2
      | some q =>
        rw [hsp, hsi] at hobs
        simp at hobs
    | some q =>
      cases hsi : implStep fI a γ with
      | none =>
        rw [hsp, hsi] at hobs
        simp at hobs
      | some q' =>
        rw [hsp, hsi] at hobs
        simp only [List.cons.injEq, Option.some.injEq] at hobs
        -- observably equal rows at a visited state force equal transitions
        have hrow : obsRow (liftStep a γ (fI (sig a γ))) = obsRow (specStep a γ) := by
          show obsRow (implStep fI a γ) = obsRow (specStep a γ)
          rw [hsp, hsi]
          simp only [obsRow, Option.map_some]
          exact congrArg some (by
            have h1 := hobs.1
            exact Prod.ext (congrArg Prod.fst h1) (congrArg Prod.snd h1))
        have heq : implStep fI a γ = specStep a γ := by
          have := reflectOK p hp a hacat (fI (sig a γ)) (by rw [hpc]; exact hrow)
          rw [hpc] at this
          exact this
        have hq : q' = q := by
          rw [heq, hsp] at hsi
          exact (Option.some.injEq .. ▸ hsi.symm)
        subst hq
        have hvis : q.2 ∈ visited :=
          visited_closed frontier_empty γ hγ (a, q.2)
            (succsOf_mem hacat (show specStep a γ = some (q.1, q.2) by rw [hsp]))
        exact ih q.2 hvis (fun b hb => hcat b (List.mem_cons_of_mem _ hb)) hobs.2

/-- Pointwise transition agreement on the explored set, from T_B agreement. -/
theorem agree_pointwise (fI : SigR → Dec)
    (hA : AgreesOnTB (implStep fI)) :
    ∀ γ ∈ visited, ∀ a ∈ catalogActs, implStep fI a γ = specStep a γ := by
  intro γ hγ a ha
  obtain ⟨p, hp, hpc⟩ := mem_visitedP_of_visited hγ
  obtain ⟨hwcat, hrun⟩ := explore_sound p hp
  have hw : p.2 ++ [a] ∈ suite :=
    List.mem_flatMap.mpr ⟨p, hp, List.mem_map.mpr ⟨a, ha, rfl⟩⟩
  have hobs := hA _ hw
  have hcat : ∀ b ∈ p.2 ++ [a], b ∈ catalogActs := by
    intro b hb
    rcases List.mem_append.mp hb with hb | hb
    · exact hwcat b hb
    · cases hb with
      | head => exact ha
      | tail _ h => cases h
  rw [runObs_append, runObs_append] at hobs
  have hprefix : runObs (implStep fI) γ0 p.2 = runObs specStep γ0 p.2 := by
    have hlen : (runObs (implStep fI) γ0 p.2).length =
        (runObs specStep γ0 p.2).length := by
      rw [runObs_length, runObs_length]
    exact List.append_inj_left hobs hlen
  have hforce := traj_forcing fI p.2 γ0 gamma0_visited
    (fun b hb => hwcat b hb) hprefix
  have hspecend : runState specStep γ0 p.2 = γ := hpc ▸ runState_runFrom hrun
  -- the last rows agree
  have hsuffix : runObs (implStep fI) (runState (implStep fI) γ0 p.2) [a] =
      runObs specStep (runState specStep γ0 p.2) [a] :=
    List.append_inj_right hobs (by rw [runObs_length, runObs_length])
  rw [hforce.1, hspecend] at hsuffix
  simp only [runObs] at hsuffix
  cases hsp : specStep a γ with
  | none =>
    cases hsi : implStep fI a γ with
    | none => rw [hsp, hsi]
    | some q => rw [hsp, hsi] at hsuffix; simp at hsuffix
  | some q =>
    cases hsi : implStep fI a γ with
    | none => rw [hsp, hsi] at hsuffix; simp at hsuffix
    | some q' =>
      rw [hsp, hsi] at hsuffix
      simp only [List.cons.injEq, Option.some.injEq] at hsuffix
      have hrow : obsRow (liftStep a γ (fI (sig a γ))) = obsRow (specStep a γ) := by
        show obsRow (implStep fI a γ) = obsRow (specStep a γ)
        rw [hsp, hsi]
        simp only [obsRow, Option.map_some]
        exact congrArg some (Prod.ext (congrArg Prod.fst hsuffix.1)
          (congrArg Prod.snd hsuffix.1))
      have := reflectOK p hp a ha (fI (sig a γ)) (by rw [hpc]; exact hrow)
      rw [hpc] at this
      exact this

/- ------------------------------------------------------------------ -/
/- Observation bisimulation on the bounded domain.                     -/
/- ------------------------------------------------------------------ -/

/-- Observation bisimulation for the bounded (deterministic-per-label)
    systems: related states are observation-equal and match every probe
    label — equal refusals, equal event words, related successors. -/
def IsBisim (s1 s2 : Act → Config → Option (Ev × Config))
    (R : Config → Config → Prop) : Prop :=
  ∀ c1 c2, R c1 c2 →
    obs c1 = obs c2 ∧
    ∀ a ∈ catalogActs,
      (s1 a c1 = none ∧ s2 a c2 = none) ∨
      (∃ e c1' c2', s1 a c1 = some (e, c1') ∧ s2 a c2 = some (e, c2') ∧ R c1' c2')

def Bisimilar (s1 s2 : Act → Config → Option (Ev × Config)) : Prop :=
  ∃ R, IsBisim s1 s2 R ∧ R γ0 γ0

/-- Bisimilar states have equal observation trajectories on catalog words. -/
theorem bisim_runObs {s1 s2 R} (hR : IsBisim s1 s2 R) :
    ∀ (w : List Act), (∀ b ∈ w, b ∈ catalogActs) →
      ∀ c1 c2, R c1 c2 → runObs s1 c1 w = runObs s2 c2 w := by
  intro w
  induction w with
  | nil => intro _ c1 c2 _; rfl
  | cons a as ih =>
    intro hcat c1 c2 hc
    have htail := fun c1' c2' h =>
      ih (fun b hb => hcat b (List.mem_cons_of_mem _ hb)) c1' c2' h
    rcases (hR c1 c2 hc).2 a (hcat a (List.mem_cons_self ..)) with ⟨h1, h2⟩ | ⟨e, c1', c2', h1, h2, hr⟩
    · simp only [runObs, h1, h2]
      exact congrArg _ (htail c1 c2 hc)
    · simp only [runObs, h1, h2]
      have hobs : obs c1' = obs c2' := (hR c1' c2' hr).1
      rw [hobs]
      exact congrArg _ (htail c1' c2' hr)

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

/-- **Theorem D (bounded characterization).**  A clause-factored bounded
    implementation agrees with the specification on the bounded suite T_B
    iff it is observation-bisimilar to the specification on the bounded
    domain. -/
theorem theoremD (fI : SigR → Dec) :
    AgreesOnTB (implStep fI) ↔ Bisimilar (implStep fI) specStep := by
  constructor
  · intro hA
    refine ⟨fun c1 c2 => c1 = c2 ∧ c1 ∈ visited, ?_, rfl, gamma0_visited⟩
    intro c1 c2 hc
    obtain ⟨rfl, hvis⟩ := hc
    refine ⟨rfl, ?_⟩
    intro a ha
    have heq := agree_pointwise fI hA c1 hvis a ha
    cases hsp : specStep a c1 with
    | none => exact .inl ⟨heq.trans hsp, hsp⟩
    | some q =>
      refine .inr ⟨q.1, q.2, q.2, ?_, ?_, rfl, ?_⟩
      · rw [heq, hsp]
      · rw [hsp]
      · exact visited_closed frontier_empty c1 hvis (a, q.2)
          (succsOf_mem ha (show specStep a c1 = some (q.1, q.2) by rw [hsp]))
  · intro ⟨R, hR, hR0⟩
    intro w hw
    exact bisim_runObs hR w (suite_words_catalog w hw) γ0 γ0 hR0

end Bounded
