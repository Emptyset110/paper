/-
  Bounded/Enum.lean — Theorem B (finiteness).

  The bounded configuration type is finite: `FinEnum Config` is constructed
  from complete enumerations of every component type (no mathlib `Fintype`;
  the class is Bounded/Basic.lean's `FinEnum`, whose field `complete` is the
  finiteness witness ∀ γ, γ ∈ all).  Nothing here is ever evaluated — the
  instance is used abstractly (e.g. by the cardinality-fuel bound in
  Explore.lean).
-/
import Bounded.SigDec

namespace Bounded

instance : FinEnum Outcome := ⟨[.ok, .err], by intro x; cases x <;> simp⟩

instance : FinEnum Component :=
  ⟨(all (α := KSet × KSet × Script)).map fun t => ⟨t.1, t.2.1, t.2.2⟩, by
    intro ⟨d, p, s⟩
    exact List.mem_map.mpr ⟨(d, p, s), complete _, rfl⟩⟩

instance : FinEnum Inv :=
  ⟨(all (α := Key)).map .unprovide ++ (all (α := Tag)).map .untrack ++
    (all (α := Slot)).map .retireChild, by
    intro x
    cases x with
    | unprovide k =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_map_of_mem (complete k)
    | untrack t =>
      exact List.mem_append_left _ <| List.mem_append_right _ <|
        List.mem_map_of_mem (complete t)
    | retireChild s =>
      exact List.mem_append_right _ <| List.mem_map_of_mem (complete s)⟩

instance : FinEnum LState :=
  ⟨(all (α := Outcome)).map .inactive ++
    ((all (α := Script × Acc × View)).map fun t => .reloading t.1 t.2.1 t.2.2) ++
    ((all (α := Acc × View)).map fun t => .active t.1 t.2) ++
    ((all (α := Acc × View × Outcome)).map fun t => .unloading t.1 t.2.1 t.2.2), by
    intro x
    cases x with
    | inactive o =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_append_left _ <| List.mem_map_of_mem (complete o)
    | reloading r a v =>
      exact List.mem_append_left _ <| List.mem_append_left _ <|
        List.mem_append_right _ <| List.mem_map.mpr ⟨(r, a, v), complete _, rfl⟩
    | active a v =>
      exact List.mem_append_left _ <| List.mem_append_right _ <|
        List.mem_map.mpr ⟨(a, v), complete _, rfl⟩
    | unloading a v o =>
      exact List.mem_append_right _ <| List.mem_map.mpr ⟨(a, v, o), complete _, rfl⟩⟩

instance : FinEnum Fiber :=
  ⟨(all (α := Component × Option Slot × Bool × KMap (Option Val) × LState)).map
      fun t => ⟨t.1, t.2.1, t.2.2.1, t.2.2.2.1, t.2.2.2.2⟩, by
    intro ⟨c, p, r, tb, s⟩
    exact List.mem_map.mpr ⟨(c, p, r, tb, s), complete _, rfl⟩⟩

/-- **Theorem B (finiteness).**  The bounded configuration type is finite:
    it carries a complete enumeration (and decidable equality, from
    Calc.lean).  `FinEnum.complete` is the witness `∀ γ : Config, γ ∈ all`. -/
instance finEnumConfig : FinEnum Config :=
  inferInstanceAs (FinEnum (SMap (Option Fiber)))

/-- Theorem B, restated explicitly. -/
theorem config_finite : ∀ γ : Config, γ ∈ (all : List Config) :=
  FinEnum.complete

end Bounded
