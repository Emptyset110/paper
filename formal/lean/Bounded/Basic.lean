/-
  Bounded/Basic.lean — foundation: a mathlib-free finite-enumeration class
  (`FinEnum`), decidability of finite quantifiers, and bounded lists.

  Deliverable D4 of the two-track proof program (see ../../MASTER.md).
  Core Lean only; no external dependencies.
-/

namespace Bounded

/-- A type with a complete (not necessarily duplicate-free) enumeration.
    This is the mathlib-free stand-in for `Fintype`; Theorem B provides the
    instance for the configuration type. -/
class FinEnum (α : Type) : Type where
  all : List α
  complete : ∀ x : α, x ∈ all

export FinEnum (all complete)

instance : FinEnum Bool :=
  ⟨[false, true], by intro x; cases x <;> simp⟩

instance : FinEnum Unit := ⟨[()], by intro x; cases x; simp⟩

/-- Enumeration of `Fin n`. -/
def finList : (n : Nat) → List (Fin n)
  | 0 => []
  | n + 1 => (0 : Fin (n + 1)) :: (finList n).map Fin.succ

theorem finList_complete : ∀ {n : Nat} (x : Fin n), x ∈ finList n := by
  intro n
  induction n with
  | zero => intro x; exact absurd x.2 (Nat.not_lt_zero _)
  | succ n ih =>
    intro x
    cases x using Fin.cases with
    | zero => exact List.mem_cons_self ..
    | succ i => exact List.mem_cons_of_mem _ (List.mem_map_of_mem (ih i))

instance (n : Nat) : FinEnum (Fin n) := ⟨finList n, finList_complete⟩

instance [FinEnum α] : FinEnum (Option α) :=
  ⟨none :: (all (α := α)).map some, by
    intro x
    cases x with
    | none => exact List.mem_cons_self ..
    | some a => exact List.mem_cons_of_mem _ (List.mem_map_of_mem (complete a))⟩

instance [FinEnum α] [FinEnum β] : FinEnum (α × β) :=
  ⟨(all (α := α)).flatMap fun a => (all (α := β)).map fun b => (a, b), by
    intro ⟨a, b⟩
    exact List.mem_flatMap.mpr ⟨a, complete a, List.mem_map_of_mem (complete b)⟩⟩

instance [FinEnum α] [FinEnum β] : FinEnum (α ⊕ β) :=
  ⟨(all (α := α)).map Sum.inl ++ (all (α := β)).map Sum.inr, by
    intro x
    cases x with
    | inl a => exact List.mem_append_left _ (List.mem_map_of_mem (complete a))
    | inr b => exact List.mem_append_right _ (List.mem_map_of_mem (complete b))⟩

/-- Finite universal quantification is decidable from an enumeration.

    PRIORITY.  This must be `low`: `∀ x ∈ l, p x` unfolds to `∀ x, x ∈ l → p x`
    and would otherwise be resolved here — enumerating the whole of `α` —
    instead of by `List.decidableBAll`, which walks only `l`.  At `α = Config`
    that difference is the difference between 15,173 states and 10^44. -/
instance (priority := low) decidableBallFinEnum [FinEnum α] (p : α → Prop)
    [DecidablePred p] :
    Decidable (∀ x : α, p x) :=
  decidable_of_iff (∀ x ∈ all (α := α), p x)
    ⟨fun h x => h x (complete x), fun h x _ => h x⟩

/-- Finite existential quantification is decidable from an enumeration.
    Low priority, for the reason given above. -/
instance (priority := low) decidableBexFinEnum [FinEnum α] (p : α → Prop)
    [DecidablePred p] :
    Decidable (∃ x : α, p x) :=
  decidable_of_iff (∃ x ∈ all (α := α), p x)
    ⟨fun ⟨x, _, hp⟩ => ⟨x, hp⟩, fun ⟨x, hp⟩ => ⟨x, complete x, hp⟩⟩

/-- Decidable equality for functions out of a `FinEnum` type. -/
instance decEqFinEnumFun [FinEnum α] [DecidableEq β] : DecidableEq (α → β) :=
  fun f g =>
    decidable_of_iff (∀ x : α, f x = g x)
      ⟨funext, fun h x => congrFun h x⟩

/-- Enumeration of function types out of a `FinEnum` domain, built pointwise
    over the domain's enumeration.  `allFun` extends a list of partial choices
    (functions) one domain point at a time. -/
def funUpdate [DecidableEq α] (f : α → β) (x : α) (v : β) : α → β :=
  fun y => if y = x then v else f y

def allFunAux [DecidableEq α] [FinEnum β] (dflt : β) : List α → List (α → β)
  | [] => [fun _ => dflt]
  | x :: xs =>
    (allFunAux dflt xs).flatMap fun f =>
      (all (α := β)).map fun v => funUpdate f x v

theorem allFunAux_complete [DecidableEq α] [FinEnum β] (dflt : β)
    (xs : List α) (f : α → β) :
    ∃ g ∈ allFunAux (α := α) dflt xs, ∀ x ∈ xs, g x = f x := by
  induction xs with
  | nil => exact ⟨fun _ => dflt, List.mem_cons_self .., by intro x hx; cases hx⟩
  | cons x xs ih =>
    obtain ⟨g, hg, hgx⟩ := ih
    refine ⟨funUpdate g x (f x), ?_, ?_⟩
    · exact List.mem_flatMap.mpr ⟨g, hg, List.mem_map_of_mem (complete (f x))⟩
    · intro y hy
      by_cases hyx : y = x
      · subst hyx; simp [funUpdate]
      · cases hy with
        | head => exact absurd rfl hyx
        | tail _ hy => simpa [funUpdate, hyx] using hgx y hy

instance finEnumFun [DecidableEq α] [FinEnum α] [FinEnum β] [Inhabited β] :
    FinEnum (α → β) :=
  ⟨allFunAux (default : β) (all (α := α)), by
    intro f
    obtain ⟨g, hg, hgx⟩ := allFunAux_complete (α := α) (β := β) default (all (α := α)) f
    have : g = f := funext fun x => hgx x (complete x)
    exact this ▸ hg⟩

/-- Lists over `α` of length at most `n`. -/
def listsLE (α : Type) [FinEnum α] : Nat → List (List α)
  | 0 => [[]]
  | n + 1 =>
    [] :: (all (α := α)).flatMap fun a => (listsLE α n).map fun l => a :: l

theorem listsLE_complete [FinEnum α] :
    ∀ (n : Nat) (l : List α), l.length ≤ n → l ∈ listsLE α n := by
  intro n
  induction n with
  | zero =>
    intro l hl
    have : l = [] := List.eq_nil_of_length_eq_zero (Nat.le_zero.mp hl)
    simp [this, listsLE]
  | succ n ih =>
    intro l hl
    cases l with
    | nil => exact List.mem_cons_self ..
    | cons a l =>
      refine List.mem_cons_of_mem _ (List.mem_flatMap.mpr ⟨a, complete a, ?_⟩)
      exact List.mem_map_of_mem (ih l (Nat.le_of_succ_le_succ hl))

/-- Bounded lists: lists of length at most `n`.  Used for scripts and
    accumulators so that fibers form a finite type. -/
def BList (α : Type) (n : Nat) : Type := { l : List α // l.length ≤ n }

namespace BList

instance [DecidableEq α] : DecidableEq (BList α n) :=
  fun a b =>
    decidable_of_iff (a.val = b.val) ⟨Subtype.ext, fun h => congrArg Subtype.val h⟩

instance [Hashable α] : Hashable (BList α n) := ⟨fun l => hash l.val⟩

instance [FinEnum α] : FinEnum (BList α n) :=
  ⟨(listsLE α n).attach.filterMap fun l =>
      if h : l.val.length ≤ n then some ⟨l.val, h⟩ else none, by
    intro ⟨l, hl⟩
    apply List.mem_filterMap.mpr
    refine ⟨⟨l, listsLE_complete n l hl⟩, List.mem_attach _ _, ?_⟩
    simp [hl]⟩

def nil : BList α n := ⟨[], Nat.zero_le n⟩

/-- Truncating push at the back: a no-op when the bound is full.  The bound is
    never hit on specification runs (accumulator growth is dominated by script
    consumption); see PROOF_STATUS.md, deviations. -/
def push (l : BList α n) (x : α) : BList α n :=
  if h : l.val.length + 1 ≤ n then ⟨l.val ++ [x], by simpa using h⟩ else l

def head? (l : BList α n) : Option α := l.val.head?

def tail (l : BList α n) : BList α n :=
  ⟨l.val.tail, by have := l.property; rw [List.length_tail]; omega⟩

def isEmpty (l : BList α n) : Bool := l.val.isEmpty

def map (f : α → β) (l : BList α n) : BList β n :=
  ⟨l.val.map f, by simpa using l.property⟩

@[simp] theorem map_val (f : α → β) (l : BList α n) :
    (map f l).val = l.val.map f := rfl

end BList

end Bounded
