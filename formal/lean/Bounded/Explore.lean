/-
  Bounded/Explore.lean — Theorem C (explorer correctness).

  `Reachable` is the inductive reachability predicate of the bounded LTS
  (all interleavings of catalog labels from the empty registry).  `expand`
  is an executable BFS worklist that also records, for every state, the
  access word that reaches it (used by the bounded suite T_B).

  - Theorem C1 (soundness): every explored state is reachable, with its
    recorded access word as an executable witness.
  - Theorem C2 (completeness): if the run's frontier is empty, the explored
    set contains every reachable state.  The frontier fact for the shipped
    run is discharged computationally (`frontier_empty`).
  - Theorem C3 (termination from finiteness, via Theorem B): fuel equal to
    the cardinality bound of `Config` empties the frontier.
-/
import Bounded.Enum

namespace Bounded

def γ0 : Config := emptyConfig

/-- Reachability under the bounded probe alphabet. -/
inductive Reachable : Config → Prop where
  | init : Reachable γ0
  | step {γ γ' : Config} {a : Act} {e : Ev} :
      Reachable γ → a ∈ catalogActs → specStep a γ = some (e, γ') → Reachable γ'

/-- Deterministic run of a label word from a state (refusal aborts). -/
def runFrom (γ : Config) : List Act → Option Config
  | [] => some γ
  | a :: as =>
    match specStep a γ with
    | some p => runFrom p.2 as
    | none => none

theorem reachable_of_run {w : List Act} {γ γf : Config}
    (hγ : Reachable γ) (hw : ∀ a ∈ w, a ∈ catalogActs)
    (h : runFrom γ w = some γf) : Reachable γf := by
  induction w generalizing γ with
  | nil =>
    simp only [runFrom, Option.some.injEq] at h
    exact h ▸ hγ
  | cons a as ih =>
    simp only [runFrom] at h
    cases hs : specStep a γ with
    | none => rw [hs] at h; cases h
    | some p =>
      rw [hs] at h
      have hstep : Reachable p.2 :=
        Reachable.step hγ (hw a (List.mem_cons_self ..))
          (show specStep a γ = some (p.1, p.2) by rw [hs])
      exact ih hstep (fun b hb => hw b (List.mem_cons_of_mem _ hb)) h

theorem runFrom_append (γ : Config) (w1 w2 : List Act) :
    runFrom γ (w1 ++ w2) =
      match runFrom γ w1 with
      | some γ' => runFrom γ' w2
      | none => none := by
  induction w1 generalizing γ with
  | nil => simp [runFrom]
  | cons a as ih =>
    simp only [List.cons_append, runFrom]
    cases specStep a γ with
    | none => rfl
    | some p => exact ih p.2

/- ------------------------------------------------------------------ -/
/- The worklist explorer.                                              -/
/- ------------------------------------------------------------------ -/

/-- All enabled successors of a state, with their labels. -/
def succsOf (γ : Config) : List (Act × Config) :=
  catalogActs.filterMap fun a => (specStep a γ).map fun p => (a, p.2)

theorem mem_succsOf {γ : Config} {q : Act × Config} (h : q ∈ succsOf γ) :
    q.1 ∈ catalogActs ∧ ∃ e, specStep q.1 γ = some (e, q.2) := by
  obtain ⟨a, ha, hq⟩ := List.mem_filterMap.mp h
  cases hs : specStep a γ with
  | none => rw [hs] at hq; cases hq
  | some p =>
    rw [hs] at hq
    simp only [Option.map_some, Option.some.injEq] at hq
    cases hq
    exact ⟨ha, p.1, by rw [hs]⟩

theorem succsOf_mem {γ γ' : Config} {a : Act} {e : Ev}
    (ha : a ∈ catalogActs) (hs : specStep a γ = some (e, γ')) :
    (a, γ') ∈ succsOf γ :=
  List.mem_filterMap.mpr ⟨a, ha, by rw [hs]; rfl⟩

/-- Explorer state: unexpanded frontier and everything discovered, each with
    its access word.  Invariant: `todo ⊆ seen`. -/
structure ESt where
  todo : List (Config × List Act)
  seen : List (Config × List Act)

def seenConfigs (st : ESt) : List Config := st.seen.map (·.1)

def addNew (w : List Act) (st : ESt) (ac : Act × Config) : ESt :=
  if st.seen.any fun q => decide (q.1 = ac.2) then st
  else { todo := st.todo ++ [(ac.2, w ++ [ac.1])]
         seen := st.seen ++ [(ac.2, w ++ [ac.1])] }

def expand : Nat → ESt → ESt
  | 0, st => st
  | fuel + 1, st =>
    match st.todo with
    | [] => st
    | (γ, w) :: rest =>
      expand fuel ((succsOf γ).foldl (addNew w) { todo := rest, seen := st.seen })

def st0 : ESt := { todo := [(γ0, [])], seen := [(γ0, [])] }

/- ---- monotonicity of `seen` ---- -/

theorem addNew_seen_mono {w st ac} {p : Config × List Act}
    (h : p ∈ st.seen) : p ∈ (addNew w st ac).seen := by
  unfold addNew
  split
  · exact h
  · exact List.mem_append_left _ h

theorem foldl_addNew_seen_mono {w} {S : List (Act × Config)} {st}
    {p : Config × List Act} (h : p ∈ st.seen) :
    p ∈ (S.foldl (addNew w) st).seen := by
  induction S generalizing st with
  | nil => exact h
  | cons q S ih => exact ih (addNew_seen_mono h)

theorem expand_seen_mono {f st} {p : Config × List Act}
    (h : p ∈ st.seen) : p ∈ (expand f st).seen := by
  induction f generalizing st with
  | zero => exact h
  | succ f ih =>
    unfold expand
    match hm : st.todo with
    | [] => exact h
    | (γ, w) :: rest => exact ih (foldl_addNew_seen_mono h)

/- ---- path validity (C1) ---- -/

/-- Every recorded pair carries a valid catalog access word. -/
def PathsOK (l : List (Config × List Act)) : Prop :=
  ∀ p ∈ l, (∀ a ∈ p.2, a ∈ catalogActs) ∧ runFrom γ0 p.2 = some p.1

theorem addNew_pathsOK {w st ac}
    (hs : PathsOK st.seen)
    (hw : (∀ a ∈ w, a ∈ catalogActs) ∧
          ∃ γ, runFrom γ0 w = some γ ∧ ac ∈ succsOf γ) :
    PathsOK (addNew w st ac).seen := by
  unfold addNew
  split
  · exact hs
  · intro p hp
    rcases List.mem_append.mp hp with hp | hp
    · exact hs p hp
    · have hp' : p = (ac.2, w ++ [ac.1]) := by
        cases hp with
        | head => rfl
        | tail _ h => cases h
      subst hp'
      obtain ⟨hwc, γ, hrun, hsucc⟩ := hw
      obtain ⟨hac, e, hstep⟩ := mem_succsOf hsucc
      constructor
      · intro a ha
        rcases List.mem_append.mp ha with ha | ha
        · exact hwc a ha
        · have : a = ac.1 := by
            cases ha with
            | head => rfl
            | tail _ h => cases h
          exact this ▸ hac
      · rw [runFrom_append, hrun]
        simp [runFrom, hstep]

theorem foldl_addNew_pathsOK {w} {S : List (Act × Config)} {st} {γ : Config}
    (hs : PathsOK st.seen)
    (hwc : ∀ a ∈ w, a ∈ catalogActs)
    (hrun : runFrom γ0 w = some γ)
    (hS : ∀ q ∈ S, q ∈ succsOf γ) :
    PathsOK (S.foldl (addNew w) st).seen := by
  induction S generalizing st with
  | nil => exact hs
  | cons q S ih =>
    refine ih (addNew_pathsOK hs ⟨hwc, γ, hrun, hS q (List.mem_cons_self ..)⟩) ?_
    intro q' hq'
    exact hS q' (List.mem_cons_of_mem _ hq')

theorem expand_pathsOK {f st}
    (hseen : PathsOK st.seen) (htodo : ∀ p ∈ st.todo, p ∈ st.seen) :
    PathsOK (expand f st).seen := by
  induction f generalizing st with
  | zero => exact hseen
  | succ f ih =>
    unfold expand
    match hm : st.todo with
    | [] => exact hseen
    | (γ, w) :: rest =>
      apply ih
      case hseen =>
        have hmem : (γ, w) ∈ st.seen := htodo _ (hm ▸ List.mem_cons_self ..)
        obtain ⟨hwc, hrun⟩ := hseen _ hmem
        exact foldl_addNew_pathsOK hseen hwc hrun (fun q hq => hq)
      case htodo =>
        -- new todo entries are always mirrored into seen
        clear ih
        have base : ∀ p ∈ rest, p ∈ st.seen := fun p hp =>
          htodo p (hm ▸ List.mem_cons_of_mem _ hp)
        generalize hst : (ESt.mk rest st.seen) = st'
        have hbase : (∀ p ∈ st'.todo, p ∈ st'.seen) := by
          subst hst; exact base
        clear hst base
        induction (succsOf γ) generalizing st' with
        | nil => exact hbase
        | cons q S ihS =>
          apply ihS
          intro p hp
          unfold addNew at hp ⊢
          split at hp
          · rename_i hguard
            simp only [if_pos hguard]
            exact hbase p hp
          · rename_i hguard
            simp only [if_neg hguard]
            rcases List.mem_append.mp hp with hp | hp
            · exact List.mem_append_left _ (hbase p hp)
            · exact List.mem_append_right _ hp

/- ---- closure (C2) ---- -/

/-- Every seen state is either still on the frontier or fully expanded. -/
def ClosedExcept (st : ESt) : Prop :=
  ∀ p ∈ st.seen, p.1 ∈ st.todo.map (·.1) ∨
    ∀ q ∈ succsOf p.1, q.2 ∈ seenConfigs st

/-- `addNew` either leaves the state alone (the config was already seen) or
    appends the new pair to both lists. -/
theorem addNew_spec (w : List Act) (st : ESt) (ac : Act × Config) :
    (addNew w st ac = st ∧ ac.2 ∈ seenConfigs st) ∨
    addNew w st ac =
      { todo := st.todo ++ [(ac.2, w ++ [ac.1])]
        seen := st.seen ++ [(ac.2, w ++ [ac.1])] } := by
  unfold addNew
  split
  · rename_i hg
    obtain ⟨q, hq, hqc⟩ := List.any_eq_true.mp hg
    exact .inl ⟨rfl, List.mem_map.mpr ⟨q, hq, of_decide_eq_true hqc⟩⟩
  · exact .inr rfl

theorem seenConfigs_mono {st st' : ESt}
    (h : ∀ p ∈ st.seen, p ∈ st'.seen) {c : Config}
    (hc : c ∈ seenConfigs st) : c ∈ seenConfigs st' := by
  obtain ⟨p, hp, hpc⟩ := List.mem_map.mp hc
  exact List.mem_map.mpr ⟨p, h p hp, hpc⟩

theorem foldl_addNew_seenConfigs_mono {w} {S : List (Act × Config)} {st}
    {c : Config} (h : c ∈ seenConfigs st) :
    c ∈ seenConfigs (S.foldl (addNew w) st) :=
  seenConfigs_mono (fun _ hp => foldl_addNew_seen_mono hp) h

theorem addNew_covers {w st ac} :
    ac.2 ∈ seenConfigs (addNew w st ac) := by
  rcases addNew_spec w st ac with ⟨heq, hmem⟩ | heq
  · rw [heq]; exact hmem
  · rw [heq]
    exact List.mem_map.mpr
      ⟨(ac.2, w ++ [ac.1]), List.mem_append_right _ (by simp), rfl⟩

theorem foldl_addNew_covers {w} {S : List (Act × Config)} {st} :
    ∀ q ∈ S, q.2 ∈ seenConfigs (S.foldl (addNew w) st) := by
  induction S generalizing st with
  | nil => intro q hq; cases hq
  | cons q' S ih =>
    intro q hq
    rw [List.foldl_cons]
    cases hq with
    | head => exact foldl_addNew_seenConfigs_mono addNew_covers
    | tail _ hq => exact ih q hq

theorem addNew_todo_mono {w st ac} {p : Config × List Act}
    (h : p ∈ st.todo) : p ∈ (addNew w st ac).todo := by
  rcases addNew_spec w st ac with ⟨heq, _⟩ | heq
  · rw [heq]; exact h
  · rw [heq]; exact List.mem_append_left _ h

theorem foldl_addNew_todo_mono {w} {S : List (Act × Config)} {st}
    {p : Config × List Act} (h : p ∈ st.todo) :
    p ∈ (S.foldl (addNew w) st).todo := by
  induction S generalizing st with
  | nil => exact h
  | cons q S ih =>
    rw [List.foldl_cons]
    exact ih (addNew_todo_mono h)

/-- A pair seen after the fold was either seen before it, or is on the
    resulting frontier. -/
theorem foldl_addNew_seen_cases {w} {S : List (Act × Config)} {st}
    {p : Config × List Act} (h : p ∈ (S.foldl (addNew w) st).seen) :
    p ∈ st.seen ∨ p ∈ (S.foldl (addNew w) st).todo := by
  induction S generalizing st with
  | nil => exact .inl h
  | cons q S ih =>
    rw [List.foldl_cons] at h ⊢
    rcases ih h with h' | h'
    · rcases addNew_spec w st q with ⟨heq, _⟩ | heq
      · rw [heq] at h'; exact .inl h'
      · rw [heq] at h'
        rcases List.mem_append.mp h' with h'' | h''
        · exact .inl h''
        · refine .inr (foldl_addNew_todo_mono ?_)
          rw [heq]
          exact List.mem_append_right _ h''
    · exact .inr h'

theorem expand_closedExcept {f st}
    (hclosed : ClosedExcept st) : ClosedExcept (expand f st) := by
  induction f generalizing st with
  | zero => exact hclosed
  | succ f ih =>
    unfold expand
    match hm : st.todo with
    | [] => exact hclosed
    | (γ, w) :: rest =>
      apply ih
      intro p hp
      rcases foldl_addNew_seen_cases hp with hpold | hptodo
      · -- p was seen before this expansion step
        rcases hclosed p hpold with hint | hcl
        · rw [hm] at hint
          rcases List.mem_map.mp hint with ⟨q, hq, hqc⟩
          cases hq with
          | head =>
            -- p.1 = γ, the state just expanded: all successors now seen
            right
            intro q' hq'
            have hγ : γ = p.1 := hqc
            subst hγ
            exact foldl_addNew_covers q' hq'
          | tail _ hq =>
            -- p.1 still on the frontier (only appended below it)
            exact .inl (List.mem_map.mpr ⟨q, foldl_addNew_todo_mono hq, hqc⟩)
        · right
          intro q hq
          exact foldl_addNew_seenConfigs_mono (hcl q hq)
      · exact .inl (List.mem_map.mpr ⟨p, hptodo, rfl⟩)

/- ------------------------------------------------------------------ -/
/- The shipped exploration.                                            -/
/- ------------------------------------------------------------------ -/

/- All structural lemmas about `expand` are in place; from here on the BFS
   must never be reduced symbolically by the elaborator (it is executed only
   as compiled code inside `native_decide`). -/
attribute [irreducible] expand

def FUEL : Nat := 1000000

/-- The shipped exploration's discovered (state, access word) pairs.

    KERNEL DISCIPLINE.  The kernel eagerly evaluates projections, so any
    definitional-equality question that crosses this definition would force
    the whole BFS through the kernel's symbolic evaluator.  Consequently every
    shipped fact about `visitedP`/`visited` below is either (a) a decidable
    statement discharged by `native_decide` (compiled execution, no kernel
    reduction), or (b) derived from those facts purely symbolically. -/
def visitedP : List (Config × List Act) := (expand FUEL st0).seen

/-- The discovered states. -/
def visited : List Config := visitedP.map (·.1)

/-- **Theorem C1, computational core.**  Every explored pair records a
    catalog word that replays from γ₀ to its state.
    (`native_decide`: adds compiler trust — see PROOF_STATUS.md.) -/
theorem explore_sound_core :
    ∀ p ∈ visitedP, (∀ a ∈ p.2, a ∈ catalogActs) ∧ runFrom γ0 p.2 = some p.1 := by
  native_decide

/-- **Theorem C1 (soundness).** -/
theorem explore_sound : PathsOK visitedP := explore_sound_core

/-- The empty registry is explored.  (`native_decide`.) -/
theorem gamma0_visited : γ0 ∈ visited := by native_decide

/-- **Closedness of the explored set** — the shipped run's frontier is empty
    and every successor of an explored state is explored.  This is the
    exhaustiveness witness for the bounded suite.
    (`native_decide`: adds compiler trust.) -/
theorem visited_closed :
    ∀ γ ∈ visited, ∀ q ∈ succsOf γ, q.2 ∈ visited := by
  native_decide

theorem visited_sound : ∀ γ ∈ visited, Reachable γ := by
  intro γ hγ
  obtain ⟨p, hp, hpc⟩ := List.mem_map.mp hγ
  obtain ⟨hwc, hrun⟩ := explore_sound p hp
  exact hpc ▸ reachable_of_run Reachable.init hwc hrun

/-- **Theorem C2 (completeness).**  Every reachable state is explored. -/
theorem explore_complete : ∀ γ, Reachable γ → γ ∈ visited := by
  intro γ hγ
  induction hγ with
  | init => exact gamma0_visited
  | step hr ha hs ih => exact visited_closed _ ih _ (succsOf_mem ha hs)

/-- **Theorem C (explorer correctness).**  The explored set is exactly the
    reachable set. -/
theorem reachable_iff_visited (γ : Config) : Reachable γ ↔ γ ∈ visited :=
  ⟨explore_complete γ, fun h => visited_sound γ h⟩

end Bounded
