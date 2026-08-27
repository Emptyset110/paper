/-
  Bounded/Perm.lean — concrete permutation groups for the bounded alphabets:
  the six slot permutations (S₃ on `Fin 3`), and the two-element key and value
  permutation groups (`Bool`: swap or not).

  Because the groups are tiny and concrete, every group identity is proved by
  `decide` (a kernel-checked finite computation) — no axioms, no `native_decide`.
-/
import Bounded.Basic

namespace Bounded

abbrev Slot := Fin 3
abbrev Key := Fin 2
abbrev Val := Fin 2
abbrev Tag := Fin 2

def allSlots : List Slot := all
def allKeys : List Key := all

/-- The symmetric group on three slots, by exhaustive listing:
    identity, the three transpositions, and the two 3-cycles. -/
inductive Perm3 where
  | id | s01 | s02 | s12 | c012 | c021
deriving DecidableEq, Repr

instance : FinEnum Perm3 :=
  ⟨[.id, .s01, .s02, .s12, .c012, .c021], by intro x; cases x <;> simp⟩

namespace Perm3

/-- Action on slots. `c012` maps 0↦1, 1↦2, 2↦0. -/
def ap : Perm3 → Slot → Slot
  | .id, i => i
  | .s01, ⟨0, _⟩ => 1
  | .s01, ⟨1, _⟩ => 0
  | .s01, i => i
  | .s02, ⟨0, _⟩ => 2
  | .s02, ⟨2, _⟩ => 0
  | .s02, i => i
  | .s12, ⟨1, _⟩ => 2
  | .s12, ⟨2, _⟩ => 1
  | .s12, i => i
  | .c012, ⟨0, _⟩ => 1
  | .c012, ⟨1, _⟩ => 2
  | .c012, ⟨2, _⟩ => 0
  | .c012, i => i
  | .c021, ⟨0, _⟩ => 2
  | .c021, ⟨1, _⟩ => 0
  | .c021, ⟨2, _⟩ => 1
  | .c021, i => i

def inv : Perm3 → Perm3
  | .id => .id
  | .s01 => .s01
  | .s02 => .s02
  | .s12 => .s12
  | .c012 => .c021
  | .c021 => .c012

@[simp] theorem ap_inv_ap (p : Perm3) (i : Slot) : p.ap (p.inv.ap i) = i := by
  revert p i; decide

@[simp] theorem inv_ap_ap (p : Perm3) (i : Slot) : p.inv.ap (p.ap i) = i := by
  revert p i; decide

theorem ap_injective (p : Perm3) {i j : Slot} (h : p.ap i = p.ap j) : i = j := by
  have := congrArg p.inv.ap h
  simpa using this

theorem ap_surjective (p : Perm3) (j : Slot) : ∃ i, p.ap i = j :=
  ⟨p.inv.ap j, by simp⟩

@[simp] theorem inv_inv (p : Perm3) : p.inv.inv = p := by cases p <;> rfl

theorem ap_eq_iff (p : Perm3) (i j : Slot) : p.ap i = j ↔ i = p.inv.ap j := by
  constructor
  · intro h; subst h; simp
  · intro h; subst h; simp

end Perm3

/-- Key/value permutations on `Fin 2`: `false` = identity, `true` = swap.
    These groups are their own inverses. -/
def swap2 : Fin 2 → Fin 2
  | ⟨0, _⟩ => 1
  | ⟨1, _⟩ => 0
  | i => i

def ap2 (b : Bool) (k : Fin 2) : Fin 2 := if b then swap2 k else k

@[simp] theorem ap2_ap2 (b : Bool) (k : Fin 2) : ap2 b (ap2 b k) = k := by
  revert b k; decide

theorem ap2_injective (b : Bool) {i j : Fin 2} (h : ap2 b i = ap2 b j) : i = j := by
  have := congrArg (ap2 b) h
  simpa using this

theorem ap2_surjective (b : Bool) (j : Fin 2) : ∃ i, ap2 b i = j :=
  ⟨ap2 b j, by simp⟩

theorem ap2_eq_iff (b : Bool) (i j : Fin 2) : ap2 b i = j ↔ i = ap2 b j := by
  constructor
  · intro h; subst h; simp
  · intro h; subst h; simp

/-- A renaming: independent permutations of slots, keys, and values.
    Tags are left fixed (a deliberate tightening; see PROOF_STATUS.md). -/
structure Ren where
  sp : Perm3
  kp : Bool
  vp : Bool

namespace Ren

def slot (r : Ren) (n : Slot) : Slot := r.sp.ap n
def slotInv (r : Ren) (n : Slot) : Slot := r.sp.inv.ap n
def key (r : Ren) (k : Key) : Key := ap2 r.kp k
def val (r : Ren) (v : Val) : Val := ap2 r.vp v

@[simp] theorem slot_slotInv (r : Ren) (n : Slot) : r.slot (r.slotInv n) = n := by
  simp [slot, slotInv]

@[simp] theorem slotInv_slot (r : Ren) (n : Slot) : r.slotInv (r.slot n) = n := by
  simp [slot, slotInv]

@[simp] theorem key_key (r : Ren) (k : Key) : r.key (r.key k) = k := by
  simp [key]

@[simp] theorem val_val (r : Ren) (v : Val) : r.val (r.val v) = v := by
  simp [val]

theorem slot_injective (r : Ren) {i j : Slot} (h : r.slot i = r.slot j) : i = j :=
  r.sp.ap_injective h

theorem key_injective (r : Ren) {i j : Key} (h : r.key i = r.key j) : i = j :=
  ap2_injective r.kp h

theorem val_injective (r : Ren) {i j : Val} (h : r.val i = r.val j) : i = j :=
  ap2_injective r.vp h

theorem slot_eq_iff (r : Ren) (i j : Slot) : r.slot i = j ↔ i = r.slotInv j :=
  r.sp.ap_eq_iff i j

theorem key_eq_iff (r : Ren) (i j : Key) : r.key i = j ↔ i = r.key j :=
  ap2_eq_iff r.kp i j

end Ren

/-- Transport of finite Boolean quantifiers along a self-inverse reindexing:
    used to carry `∃ slot` / `∀ key` guards across a renaming. -/
theorem all_reindex {α : Type} [FinEnum α] (σ : α → α)
    (hσ : ∀ x, ∃ y, σ y = x) (p : α → Bool) :
    (all (α := α)).all (fun x => p (σ x)) = (all (α := α)).all p := by
  cases hp : (all (α := α)).all p with
  | true =>
    exact List.all_eq_true.mpr fun x _ =>
      List.all_eq_true.mp hp (σ x) (complete _)
  | false =>
    cases hq : (all (α := α)).all (fun x => p (σ x)) with
    | false => rfl
    | true =>
      exfalso
      have : (all (α := α)).all p = true :=
        List.all_eq_true.mpr fun x _ => by
          obtain ⟨y, hy⟩ := hσ x
          simpa [hy] using List.all_eq_true.mp hq y (complete y)
      rw [hp] at this
      cases this

theorem any_reindex {α : Type} [FinEnum α] (σ : α → α)
    (hσ : ∀ x, ∃ y, σ y = x) (p : α → Bool) :
    (all (α := α)).any (fun x => p (σ x)) = (all (α := α)).any p := by
  cases hp : (all (α := α)).any p with
  | true =>
    obtain ⟨x, _, hx⟩ := List.any_eq_true.mp hp
    obtain ⟨y, hy⟩ := hσ x
    exact List.any_eq_true.mpr ⟨y, complete y, by simpa [hy] using hx⟩
  | false =>
    cases hq : (all (α := α)).any (fun x => p (σ x)) with
    | false => rfl
    | true =>
      exfalso
      obtain ⟨y, _, hy⟩ := List.any_eq_true.mp hq
      have : (all (α := α)).any p = true :=
        List.any_eq_true.mpr ⟨σ y, complete _, hy⟩
      rw [hp] at this
      cases this

end Bounded
