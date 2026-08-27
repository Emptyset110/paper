/-
  Bounded/Calc.lean — the bounded calculus state space.

  Faithful to [SZC26] Table 1 / Definitions 43–51 (paper.pdf pp. 28–38) with
  the operational reading of `proof/src/model.mjs`, at the tightened bound

      B = (3 fiber slots, 2 keys, 2 values, 2 tags,
           scripts of length ≤ 3 over the fixed step grammar,
           accumulators of length ≤ 3, register depth 1).

  Finite maps over keys and slots are represented as record tuples (`KMap`,
  `SMap`) rather than functions, so that derived decidable equality is fast
  executable code — the explorer and the `native_decide` checks depend on it.
  `Config` is a finite type (Theorem B, Bounded/Enum.lean) with decidable
  equality.
-/
import Bounded.Perm

namespace Bounded

/-- A total map over the two keys, as a pair. -/
structure KMap (α : Type) where
  k0 : α
  k1 : α
deriving DecidableEq, Repr, Hashable

namespace KMap

def get (m : KMap α) (k : Key) : α := if k.val = 0 then m.k0 else m.k1

def set (m : KMap α) (k : Key) (v : α) : KMap α :=
  if k.val = 0 then { m with k0 := v } else { m with k1 := v }

def const (v : α) : KMap α := ⟨v, v⟩

def ofFun (g : Key → α) : KMap α := ⟨g 0, g 1⟩

/-- The key-swap action (the nontrivial key permutation). -/
def kswap (m : KMap α) : KMap α := ⟨m.k1, m.k0⟩

def map (f : α → β) (m : KMap α) : KMap β := ⟨f m.k0, f m.k1⟩

@[simp] theorem get_zero (m : KMap α) : m.get 0 = m.k0 := rfl
@[simp] theorem get_one (m : KMap α) : m.get 1 = m.k1 := rfl

theorem ext_iff {m m' : KMap α} : m = m' ↔ ∀ k, m.get k = m'.get k := by
  constructor
  · intro h k; rw [h]
  · intro h
    cases m; cases m'
    have h0 := h 0
    have h1 := h 1
    simp only [get_zero, get_one] at h0 h1
    cases h0; cases h1; rfl

end KMap

instance [FinEnum α] : FinEnum (KMap α) :=
  ⟨(all (α := α × α)).map fun p => ⟨p.1, p.2⟩, by
    intro ⟨a, b⟩
    exact List.mem_map.mpr ⟨(a, b), complete _, rfl⟩⟩

/-- A total map over the three slots, as a triple. -/
structure SMap (α : Type) where
  s0 : α
  s1 : α
  s2 : α
deriving DecidableEq, Repr, Hashable

namespace SMap

def get (m : SMap α) (n : Slot) : α :=
  match n.val with
  | 0 => m.s0
  | 1 => m.s1
  | _ => m.s2

def set (m : SMap α) (n : Slot) (v : α) : SMap α :=
  match n.val with
  | 0 => { m with s0 := v }
  | 1 => { m with s1 := v }
  | _ => { m with s2 := v }

def const (v : α) : SMap α := ⟨v, v, v⟩

@[simp] theorem get_zero (m : SMap α) : m.get 0 = m.s0 := rfl
@[simp] theorem get_one (m : SMap α) : m.get 1 = m.s1 := rfl
@[simp] theorem get_two (m : SMap α) : m.get 2 = m.s2 := rfl

theorem slot_cases (P : Slot → Prop) (h0 : P 0) (h1 : P 1) (h2 : P 2) :
    ∀ n : Slot, P n := by
  intro n
  match n with
  | ⟨0, _⟩ => exact h0
  | ⟨1, _⟩ => exact h1
  | ⟨2, _⟩ => exact h2

theorem ext_iff {m m' : SMap α} : m = m' ↔ ∀ n, m.get n = m'.get n := by
  constructor
  · intro h n; rw [h]
  · intro h
    cases m; cases m'
    have h0 := h 0
    have h1 := h 1
    have h2 := h 2
    simp only [get_zero, get_one, get_two] at h0 h1 h2
    cases h0; cases h1; cases h2; rfl

@[simp] theorem get_set_same (m : SMap α) (n : Slot) (v : α) :
    (m.set n v).get n = v := by
  refine slot_cases (fun n => (m.set n v).get n = v) rfl rfl rfl n

theorem get_set_other (m : SMap α) {n n' : Slot} (v : α) (h : n' ≠ n) :
    (m.set n v).get n' = m.get n' := by
  revert h
  refine slot_cases (fun n => n' ≠ n → (m.set n v).get n' = m.get n') ?_ ?_ ?_ n <;>
    · intro h
      refine slot_cases (fun n' => n' ≠ _ → (SMap.set m _ v).get n' = m.get n')
        ?_ ?_ ?_ n' h <;> intro hh <;> first | rfl | exact absurd rfl hh

end SMap

instance [FinEnum α] : FinEnum (SMap α) :=
  ⟨(all (α := α × α × α)).map fun p => ⟨p.1, p.2.1, p.2.2⟩, by
    intro ⟨a, b, c⟩
    exact List.mem_map.mpr ⟨(a, b, c), complete _, rfl⟩⟩

/-- The step grammar of §2.2 of the companion paper, restricted to the
    bounded alphabets.  `register` registers the one fixed child component
    (`childComp`), enforcing register depth 1. -/
inductive Step where
  | provide (k : Key) (v : Val)
  | track (t : Tag)
  | read (k : Key)
  | setval (k : Key) (v : Val)
  | register
  | raise
deriving DecidableEq, Repr, Hashable

instance : FinEnum Step :=
  ⟨(all (α := Key × Val)).map (fun p => .provide p.1 p.2) ++
   (all (α := Tag)).map .track ++
   (all (α := Key)).map .read ++
   (all (α := Key × Val)).map (fun p => .setval p.1 p.2) ++
   [.register, .raise], by
    intro s
    cases s with
    | provide k v =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_map_of_mem (complete (k, v))
    | track t =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_append_left _ <| List.mem_append_right _ <|
        List.mem_map_of_mem (complete t)
    | read k =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_append_right _ <| List.mem_map_of_mem (complete k)
    | setval k v =>
      exact List.mem_append_left _ <| List.mem_append_right _ <|
        List.mem_map_of_mem (complete (k, v))
    | register => exact List.mem_append_right _ (by simp)
    | raise => exact List.mem_append_right _ (by simp)⟩

/-- Scripts: at most 3 steps (bound N_s). -/
abbrev Script := BList Step 3

/-- Key sets (declared dependencies / provisions), as characteristic maps. -/
abbrev KSet := KMap Bool

/-- A component (Def. 43): dependencies `d`, provisions `p`, and the effect
    script `e` (the witnessed effect function, reified as test-component data). -/
structure Component where
  deps : KSet
  provs : KSet
  script : Script
deriving DecidableEq, Hashable

/-- Outcome ζ ∈ {⊥, ξ} (Def. 49). -/
inductive Outcome where
  | ok  -- ⊥ : clean
  | err -- ξ : failed
deriving DecidableEq, Repr, Hashable

/-- Committed / target views ω : d → 𝔑, partial over the two keys (Def. 44/46). -/
abbrev View := KMap (Option Slot)

/-- Accumulator entries: the inverse tokens an iteration can push
    (provide⁻¹, track's witnessed inverse, register's O-Retire inverse;
    Def. 47 and Def. 51). -/
inductive Inv where
  | unprovide (k : Key)
  | untrack (t : Tag)
  | retireChild (s : Slot)
deriving DecidableEq, Repr, Hashable

/-- Accumulators: applied in reverse (LIFO) order by L-Unload.  Bounded by
    the script length. -/
abbrev Acc := BList Inv 3

/-- Lifecycle state Θ (Def. 49):
    Inactive(ζ) | Reloading(i,g,ω) | Active(g,ω) | Unloading(g,ω,ζ). -/
inductive LState where
  | inactive (o : Outcome)
  | reloading (remaining : Script) (acc : Acc) (view : View)
  | active (acc : Acc) (view : View)
  | unloading (acc : Acc) (view : View) (o : Outcome)
deriving DecidableEq, Hashable

namespace LState

def isActive : LState → Bool
  | .active .. => true
  | _ => false

/-- The committed view, when installed (Def. 49: installed ⇔ carries ω). -/
def viewOf : LState → Option View
  | .inactive _ => none
  | .reloading _ _ ω => some ω
  | .active _ ω => some ω
  | .unloading _ ω _ => some ω

def isInstalled (s : LState) : Bool := (s.viewOf).isSome

end LState

/-- A fiber (Def. 44): component data, parent pointer, retirement flag τ,
    own coeffect table σ_n, and lifecycle state θ. -/
structure Fiber where
  comp : Component
  parent : Option Slot
  retired : Bool
  table : KMap (Option Val)
  st : LState
deriving DecidableEq, Hashable

/-- A registry state γ (Def. 45): the finite map from slots to fibers. -/
def Config : Type := SMap (Option Fiber)

instance : DecidableEq Config := inferInstanceAs (DecidableEq (SMap (Option Fiber)))

/-- The empty registry γ₀. -/
def emptyConfig : Config := SMap.const none

/-- Registry lookup γ(n). -/
def Config.get (γ : Config) (n : Slot) : Option Fiber := SMap.get γ n

/-- Point update γ[n ↦ x]. -/
def upd (γ : Config) (n : Slot) (x : Option Fiber) : Config := SMap.set γ n x

@[simp] theorem upd_same (γ : Config) (n : Slot) (x : Option Fiber) :
    (upd γ n x).get n = x := SMap.get_set_same γ n x

theorem upd_other (γ : Config) {n m : Slot} (x : Option Fiber) (h : m ≠ n) :
    (upd γ n x).get m = γ.get m := SMap.get_set_other γ x h

/- ------------------------------------------------------------------ -/
/- Derived notions read off the registry (Defs. 45, 46, 49, 50).       -/
/- ------------------------------------------------------------------ -/

/-- Does slot `n` hold an Active fiber whose table carries `k`?
    (The provider property behind σ_γ, Def. 45 eq. (40).) -/
def provP (γ : Config) (n : Slot) (k : Key) : Bool :=
  match γ.get n with
  | some f => f.st.isActive && (f.table.get k).isSome
  | none => false

/-- provider_k(γ): the Active fiber providing `k`, by least-slot scan.
    Under the single-source discipline (`WF`) the choice is unique, so the
    scan order is immaterial (used by Theorem A). -/
def providerOf (γ : Config) (k : Key) : Option Slot :=
  allSlots.find? (fun n => provP γ n k)

/-- The visible coeffect store σ_γ: each key's value at its Active provider. -/
def storeOf (γ : Config) (k : Key) : Option Val :=
  match providerOf γ k with
  | some n =>
    match γ.get n with
    | some f => f.table.get k
    | none => none
  | none => none

/-- Well-formedness: the single-source discipline of Def. 43/45 — every key
    has at most one Active provider.  Maintained by O-Insert's disjointness
    premise; checked for every explored state (Charact.lean). -/
def WF (γ : Config) : Prop :=
  ∀ (k : Key) (n m : Slot), provP γ n k = true → provP γ m k = true → n = m

instance : DecidablePred WF := fun γ =>
  inferInstanceAs (Decidable (∀ _ _ _, _ → _ → _))

/-- γ ⊨ d_n : every declared key has an Active provider (Def. 46). -/
def satisfied (γ : Config) (f : Fiber) : Bool :=
  allKeys.all fun k => !f.comp.deps.get k || (providerOf γ k).isSome

/-- The partial resolution of `f`'s declared keys — target view content
    where providers exist.  Used by `lift` so that deviant tables firing
    L-Begin at unsatisfied signatures still have a well-defined update. -/
def partialTarget (γ : Config) (f : Fiber) : View :=
  KMap.ofFun fun k => if f.comp.deps.get k then providerOf γ k else none

/-- target_n(γ) (Def. 46 eq. (41), read on the Def.-49 state space):
    `none` is ⊥ — retirement or unsatisfied dependencies. -/
def targetOf (γ : Config) (n : Slot) : Option View :=
  match γ.get n with
  | none => none
  | some f =>
    if f.retired then none
    else if satisfied γ f then some (partialTarget γ f) else none

/-- relied_n(γ) (Def. 50 eq. (46)): some other installed fiber resolves a
    key to `n` through its committed view. -/
def reliedUpon (γ : Config) (n : Slot) : Bool :=
  allSlots.any fun m =>
    m != n &&
    match γ.get m with
    | some f =>
      match f.st.viewOf with
      | some ω => allKeys.any fun k => ω.get k == some n
      | none => false
    | none => false

/-- Does `n` have a child in the registry (O-Remove's premise ∀m. π_m ≠ n)? -/
def hasChild (γ : Config) (n : Slot) : Bool :=
  allSlots.any fun m =>
    match γ.get m with
    | some f => f.parent == some n
    | none => false

/-- quiet(γ) (Def. 49 eq. (45)). -/
def quietAt (γ : Config) (n : Slot) : Bool :=
  match γ.get n with
  | none => true
  | some f =>
    match f.st with
    | .inactive o => o == .err || (targetOf γ n).isNone
    | .active _ ω =>
      match targetOf γ n with
      | some t => decide (t = ω)
      | none => false
    | _ => false

def quiet (γ : Config) : Bool := allSlots.all (quietAt γ)

/- ------------------------------------------------------------------ -/
/- The access discipline for `read` steps (Algorithm 6, model.mjs      -/
/- readCommitted): committed view first, then declared-but-uncommitted -/
/- (IA), then the parent chain, then undeclared (UD).                  -/
/- ------------------------------------------------------------------ -/

inductive ReadRes where
  | ok (v : Val) (ancestor : Bool)
  | ia   -- INACTIVE_ACCESS
  | ud   -- UNDECLARED_ACCESS
deriving DecidableEq, Repr, Hashable

/-- Fuel-bounded parent walk (chains have length ≤ 2 at register depth 1;
    fuel 4 is safely above any chain the bounded registry can hold). -/
def readC (γ : Config) : Nat → Slot → Key → Bool → ReadRes
  | 0, _, _, _ => .ud
  | fuel + 1, n, k, anc =>
    match γ.get n with
    | none => .ud
    | some f =>
      -- key not resolved at this level: declared ⇒ IA, else walk to the parent
      let miss : ReadRes :=
        if f.comp.deps.get k then .ia
        else
          match f.parent with
          | some par => readC γ fuel par k true
          | none => .ud
      match f.st.viewOf with
      | some ω =>
        match ω.get k with
        | some p =>
          match γ.get p with
          | some pf =>
            match pf.table.get k with
            | some v => .ok v anc
            | none => .ia
          | none => .ia
        | none => miss
      | none => miss

end Bounded
