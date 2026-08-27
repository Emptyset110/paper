/-
  Bounded/Equiv.lean — Theorem A (equivariance under renaming).

  A renaming `r : Ren` is a triple of independent permutations of slots
  (S₃), keys (Z₂) and values (Z₂); tags are fixed (Bounded/Perm.lean).  This
  file defines its action on every syntactic and semantic category of the
  bounded calculus, proves the structural core of Lemma 1/Lemma 2 of the
  paper (§5.2) — the provider predicate is equivariant and well-formedness is
  preserved — and then discharges full successor equivariance and
  κ-invariance of the signature abstraction over the reachable domain by
  compiled computation.

  One asymmetry is real and is recorded rather than hidden: `execStep`'s
  `register` case instantiates a *hard-wired* child component `childComp`,
  whose script names key 0.  A renaming that swaps the two keys therefore
  does not commute with registration.  Theorem A is stated for the subgroup
  of renamings that fix `childComp` — the twelve renamings with `kp = false`,
  i.e. all six slot permutations times both value permutations.  See
  PROOF_STATUS.md, "deviations".
-/
import Bounded.Explore

namespace Bounded

/-- Case analysis on the two keys, the analogue of `SMap.slot_cases`. -/
theorem key_cases (P : Key → Prop) (h0 : P 0) (h1 : P 1) : ∀ k : Key, P k := by
  intro k
  match k with
  | ⟨0, _⟩ => exact h0
  | ⟨1, _⟩ => exact h1

instance : FinEnum Ren :=
  ⟨(all (α := Perm3 × Bool × Bool)).map fun t => ⟨t.1, t.2.1, t.2.2⟩, by
    intro ⟨a, b, c⟩
    exact List.mem_map.mpr ⟨(a, b, c), complete _, rfl⟩⟩

/-- All 6 × 2 × 2 = 24 renamings. -/
def allRens : List Ren := all

/- ------------------------------------------------------------------ -/
/- The action on finite maps.                                          -/
/- ------------------------------------------------------------------ -/

namespace KMap

/-- Push a key-indexed map forward along `r`, transforming entries by `f`. -/
def ren (r : Ren) (f : α → α) (m : KMap α) : KMap α :=
  ⟨f (m.get (r.key 0)), f (m.get (r.key 1))⟩

theorem ren_get (r : Ren) (f : α → α) (m : KMap α) (k : Key) :
    (m.ren r f).get k = f (m.get (r.key k)) :=
  key_cases (fun k => (m.ren r f).get k = f (m.get (r.key k))) rfl rfl k

theorem ren_get' (r : Ren) (f : α → α) (m : KMap α) (k : Key) :
    (m.ren r f).get (r.key k) = f (m.get k) := by
  rw [ren_get, Ren.key_key]

end KMap

namespace SMap

/-- Push a slot-indexed map forward along `r`, transforming entries by `f`. -/
def ren (r : Ren) (f : α → α) (m : SMap α) : SMap α :=
  ⟨f (m.get (r.slotInv 0)), f (m.get (r.slotInv 1)), f (m.get (r.slotInv 2))⟩

theorem ren_get (r : Ren) (f : α → α) (m : SMap α) (n : Slot) :
    (m.ren r f).get n = f (m.get (r.slotInv n)) :=
  slot_cases (fun n => (m.ren r f).get n = f (m.get (r.slotInv n))) rfl rfl rfl n

theorem ren_get' (r : Ren) (f : α → α) (m : SMap α) (n : Slot) :
    (m.ren r f).get (r.slot n) = f (m.get n) := by
  rw [ren_get, Ren.slotInv_slot]

end SMap

/- ------------------------------------------------------------------ -/
/- The action on the calculus data.                                    -/
/- ------------------------------------------------------------------ -/

def renStep (r : Ren) : Step → Step
  | .provide k v => .provide (r.key k) (r.val v)
  | .track t => .track t
  | .read k => .read (r.key k)
  | .setval k v => .setval (r.key k) (r.val v)
  | .register => .register
  | .raise => .raise

def renScript (r : Ren) (s : Script) : Script := BList.map (renStep r) s

def renKSet (r : Ren) (m : KSet) : KSet := m.ren r id

def renTable (r : Ren) (m : KMap (Option Val)) : KMap (Option Val) :=
  m.ren r (Option.map r.val)

def renView (r : Ren) (ω : View) : View := ω.ren r (Option.map r.slot)

def renComponent (r : Ren) (c : Component) : Component :=
  { deps := renKSet r c.deps, provs := renKSet r c.provs,
    script := renScript r c.script }

def renInv (r : Ren) : Inv → Inv
  | .unprovide k => .unprovide (r.key k)
  | .untrack t => .untrack t
  | .retireChild s => .retireChild (r.slot s)

def renAcc (r : Ren) (a : Acc) : Acc := BList.map (renInv r) a

def renLState (r : Ren) : LState → LState
  | .inactive o => .inactive o
  | .reloading rem acc ω => .reloading (renScript r rem) (renAcc r acc) (renView r ω)
  | .active acc ω => .active (renAcc r acc) (renView r ω)
  | .unloading acc ω o => .unloading (renAcc r acc) (renView r ω) o

def renFiber (r : Ren) (f : Fiber) : Fiber :=
  { comp := renComponent r f.comp
    parent := f.parent.map r.slot
    retired := f.retired
    table := renTable r f.table
    st := renLState r f.st }

/-- The action on registry states: `(r·γ)(r·n) = r·(γ(n))`. -/
def renConfig (r : Ren) (γ : Config) : Config :=
  SMap.ren r (Option.map (renFiber r)) γ

def renAct (r : Ren) : Act → Act
  | .oInsert n c => .oInsert (r.slot n) (renComponent r c)
  | .oRetire n => .oRetire (r.slot n)
  | .oRemove n => .oRemove (r.slot n)
  | .lBegin n => .lBegin (r.slot n)
  | .lIter n creg => .lIter (r.slot n) (creg.map r.slot)
  | .lFinish n => .lFinish (r.slot n)
  | .lDivert n => .lDivert (r.slot n)
  | .lRaise n => .lRaise (r.slot n)
  | .lLeave n => .lLeave (r.slot n)
  | .lUnload n => .lUnload (r.slot n)

def renEvent (r : Ren) : Event → Event
  | .inserted n => .inserted (r.slot n)
  | .retiredEv n => .retiredEv (r.slot n)
  | .removedEv n => .removedEv (r.slot n)
  | .began n => .began (r.slot n)
  | .provided n k => .provided (r.slot n) (r.key k)
  | .applied n t => .applied (r.slot n) t
  | .readOk n k v => .readOk (r.slot n) (r.key k) (r.val v)
  | .readFail n k ia => .readFail (r.slot n) (r.key k) ia
  | .setv n k v => .setv (r.slot n) (r.key k) (r.val v)
  | .registered n c => .registered (r.slot n) (r.slot c)
  | .raised n => .raised (r.slot n)
  | .activated n => .activated (r.slot n)
  | .diverted n => .diverted (r.slot n)
  | .leftEv n => .leftEv (r.slot n)
  | .reverted n t => .reverted (r.slot n) t
  | .unprovided n k => .unprovided (r.slot n) (r.key k)
  | .childRetired n c => .childRetired (r.slot n) (r.slot c)
  | .deactivated n => .deactivated (r.slot n)

def renEv (r : Ren) (e : Ev) : Ev := e.map (renEvent r)

/-- The action on a transition row (emitted word, successor state). -/
def renRow (r : Ren) (p : Ev × Config) : Ev × Config :=
  (renEv r p.1, renConfig r p.2)

/- ------------------------------------------------------------------ -/
/- Structural core of Lemma 1 (§5.2): guard atoms are equivariant.      -/
/- ------------------------------------------------------------------ -/

theorem renConfig_get (r : Ren) (γ : Config) (n : Slot) :
    (renConfig r γ).get (r.slot n) = (γ.get n).map (renFiber r) :=
  SMap.ren_get' r (Option.map (renFiber r)) γ n

theorem renLState_isActive (r : Ren) (s : LState) :
    (renLState r s).isActive = s.isActive := by
  cases s <;> rfl

theorem renLState_viewOf (r : Ren) (s : LState) :
    (renLState r s).viewOf = (s.viewOf).map (renView r) := by
  cases s <;> rfl

theorem renLState_isInstalled (r : Ren) (s : LState) :
    (renLState r s).isInstalled = s.isInstalled := by
  cases s <;> rfl

theorem renTable_get (r : Ren) (m : KMap (Option Val)) (k : Key) :
    (renTable r m).get (r.key k) = (m.get k).map r.val :=
  KMap.ren_get' r (Option.map r.val) m k

theorem renKSet_get (r : Ren) (m : KSet) (k : Key) :
    (renKSet r m).get (r.key k) = m.get k :=
  KMap.ren_get' r id m k

/-- **Lemma 1, atom (1).**  The provider predicate — the atom behind σ_γ,
    `provider_k`, `target` and `relied` — is equivariant. -/
theorem provP_ren (r : Ren) (γ : Config) (n : Slot) (k : Key) :
    provP (renConfig r γ) (r.slot n) (r.key k) = provP γ n k := by
  have hg := renConfig_get r γ n
  unfold provP
  rw [hg]
  cases hf : γ.get n with
  | none => rfl
  | some f =>
    show ((renFiber r f).st.isActive && ((renFiber r f).table.get (r.key k)).isSome)
        = (f.st.isActive && (f.table.get k).isSome)
    show ((renLState r f.st).isActive && ((renTable r f.table).get (r.key k)).isSome)
        = (f.st.isActive && (f.table.get k).isSome)
    rw [renLState_isActive, renTable_get]
    cases f.table.get k <;> rfl

/-- **Lemma 2, well-formedness clause.**  The single-source discipline is
    preserved by every renaming. -/
theorem WF_ren (r : Ren) {γ : Config} (h : WF γ) : WF (renConfig r γ) := by
  intro k n m hn hm
  have en : provP (renConfig r γ) n k = provP γ (r.slotInv n) (r.key k) := by
    have := provP_ren r γ (r.slotInv n) (r.key k)
    rwa [Ren.slot_slotInv, Ren.key_key] at this
  have em : provP (renConfig r γ) m k = provP γ (r.slotInv m) (r.key k) := by
    have := provP_ren r γ (r.slotInv m) (r.key k)
    rwa [Ren.slot_slotInv, Ren.key_key] at this
  have hEq := h (r.key k) (r.slotInv n) (r.slotInv m) (en ▸ hn) (em ▸ hm)
  have := congrArg r.slot hEq
  rwa [Ren.slot_slotInv, Ren.slot_slotInv] at this

/- ------------------------------------------------------------------ -/
/- The subgroup that fixes the hard-wired child component.             -/
/- ------------------------------------------------------------------ -/

/-- `execStep`'s `register` case instantiates the fixed component
    `childComp`, whose script reads key 0.  Equivariance under a renaming
    therefore requires that renaming to fix `childComp`. -/
def renFixesChild (r : Ren) : Bool := decide (renComponent r childComp = childComp)

/-- The renamings under which the bounded successor function is equivariant:
    all six slot permutations times both value permutations. -/
def kRens : List Ren := allRens.filter renFixesChild

/-- Kernel-checked: exactly twelve of the twenty-four renamings fix
    `childComp`, namely those that do not swap the two keys. -/
theorem kRens_card : kRens.length = 12 := by decide

theorem kRens_kp : ∀ r ∈ kRens, r.kp = false := by decide

/- ------------------------------------------------------------------ -/
/- Theorem A.                                                          -/
/- ------------------------------------------------------------------ -/

/-- **Theorem A (equivariance of the successor function).**

    For every reachable bounded configuration γ, every renaming `r` fixing
    the hard-wired child component, and every probe label `a`:

        specStep (r·a) (r·γ) = (r·) <$> specStep a γ

    — the rule is enabled at the renamed window iff it is enabled at the
    original, and when enabled it emits the renamed event word and produces
    the renamed successor.  This is the bounded instance of the paper's
    Lemma 2 (§5.2, equivariance in all four sorts), for the three sorts the
    bound makes nontrivial.

    Discharged by compiled computation over the reachable domain
    (`native_decide`; adds compiler trust — see PROOF_STATUS.md).  The
    restriction to reachable γ is what makes the check finite *and* is where
    the single-source discipline holds: `providerOf` resolves ties by a
    least-slot scan, which is equivariant exactly when the provider is
    unique, i.e. under `WF` (`wf_visited` in Bounded/Charact.lean). -/
theorem theoremA :
    ∀ γ ∈ visited, ∀ r ∈ kRens, ∀ a ∈ catalogActs,
      specStep (renAct r a) (renConfig r γ) = (specStep a γ).map (renRow r) := by
  native_decide

/-- **Lemma 1 (κ-invariance of the signature abstraction), bounded form.**
    The normalized atomic rule signature is *name-free*: it is literally
    unchanged by renaming, not merely carried along.  This is the fact the
    clause-factored characterization consumes (a table `SigR → Dec` cannot
    tell renamed windows apart).

    Discharged by compiled computation over the reachable domain
    (`native_decide`). -/
theorem sig_invariant :
    ∀ γ ∈ visited, ∀ r ∈ kRens, ∀ a ∈ catalogActs,
      sig (renAct r a) (renConfig r γ) = sig a γ := by
  native_decide

/-- Corollary: the specification's decision is renaming-invariant, hence so
    is that of any clause-factored implementation (which reads the same
    signature). -/
theorem fS_sig_invariant :
    ∀ γ ∈ visited, ∀ r ∈ kRens, ∀ a ∈ catalogActs,
      fS (sig (renAct r a) (renConfig r γ)) = fS (sig a γ) := by
  intro γ hγ r hr a ha
  rw [sig_invariant γ hγ r hr a ha]

end Bounded
