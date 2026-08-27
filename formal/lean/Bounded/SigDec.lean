/-
  Bounded/SigDec.lean — the ten rules in clause-factored form.

  The ten rules of Table 1 (O-Insert, O-Retire, O-Remove, L-Begin, L-Iter,
  L-Finish, L-Divert, L-Raise, L-Leave, L-Unload) are encoded as

      specStep a γ = liftStep a γ (fS (sig a γ))

  exactly the CF3 shape of the companion paper (Definition 4): `sig` computes
  the normalized atomic rule signature of the window (name-free guard atoms
  and step classes), the table `fS : SigR → Dec` decides, and `liftStep`
  reconstructs the concrete update from the window.  A bounded implementation
  is the same composite with an arbitrary table (Charact.lean).

  Determinism note: per label the successor is a function; the calculus's
  nondeterminism is the choice of enabled label, which the explorer
  enumerates exhaustively.
-/
import Bounded.Calc

namespace Bounded

/-- The ten rules. -/
inductive Rule where
  | oInsert | oRetire | oRemove
  | lBegin | lIter | lFinish | lDivert | lRaise | lLeave | lUnload
deriving DecidableEq, Repr

/-- Transition labels.  Orchestration rules are input-labeled; lifecycle
    rules are system steps.  `oInsert` carries its target slot and component
    (the name choice made explicit, so renamings act on labels — Theorem A);
    `lIter` carries the slot a registered child would occupy (`creg`), for
    the same reason. -/
inductive Act where
  | oInsert (n : Slot) (c : Component)
  | oRetire (n : Slot)
  | oRemove (n : Slot)
  | lBegin (n : Slot)
  | lIter (n : Slot) (creg : Option Slot)
  | lFinish (n : Slot)
  | lDivert (n : Slot)
  | lRaise (n : Slot)
  | lLeave (n : Slot)
  | lUnload (n : Slot)
deriving DecidableEq

def Act.rule : Act → Rule
  | .oInsert .. => .oInsert
  | .oRetire _ => .oRetire
  | .oRemove _ => .oRemove
  | .lBegin _ => .lBegin
  | .lIter .. => .lIter
  | .lFinish _ => .lFinish
  | .lDivert _ => .lDivert
  | .lRaise _ => .lRaise
  | .lLeave _ => .lLeave
  | .lUnload _ => .lUnload

/-- The bounded event alphabet.  Every abstract update is emitted
    (CF4, instrumentation faithfulness): in particular each accumulator
    inverse application is visible. -/
inductive Event where
  | inserted (n : Slot)
  | retiredEv (n : Slot)
  | removedEv (n : Slot)
  | began (n : Slot)
  | provided (n : Slot) (k : Key)
  | applied (n : Slot) (t : Tag)
  | readOk (n : Slot) (k : Key) (v : Val)
  | readFail (n : Slot) (k : Key) (ia : Bool)
  | setv (n : Slot) (k : Key) (v : Val)
  | registered (n : Slot) (child : Slot)
  | raised (n : Slot)
  | activated (n : Slot)
  | diverted (n : Slot)
  | leftEv (n : Slot)
  | reverted (n : Slot) (t : Tag)
  | unprovided (n : Slot) (k : Key)
  | childRetired (n : Slot) (child : Slot)
  | deactivated (n : Slot)
deriving DecidableEq, Repr

abbrev Ev := List Event

/- ------------------------------------------------------------------ -/
/- Signature atoms.                                                    -/
/- ------------------------------------------------------------------ -/

inductive StCls where
  | absent | inactOk | inactErr | reload | activeS | unloadOk | unloadErr
deriving DecidableEq, Repr

def stClsOf : Option Fiber → StCls
  | none => .absent
  | some f =>
    match f.st with
    | .inactive .ok => .inactOk
    | .inactive .err => .inactErr
    | .reloading .. => .reload
    | .active .. => .activeS
    | .unloading _ _ .ok => .unloadOk
    | .unloading _ _ .err => .unloadErr

def retiredOf : Option Fiber → Bool
  | none => false
  | some f => f.retired

/-- Target-vs-committed-view relation. -/
inductive TRel where
  | bot | eq | ne
deriving DecidableEq, Repr

def tRelOf (γ : Config) (n : Slot) : TRel :=
  match γ.get n with
  | none => .bot
  | some f =>
    match targetOf γ n with
    | none => .bot
    | some t =>
      match f.st.viewOf with
      | some ω => if t = ω then .eq else .ne
      | none => .ne

/-- Read outcome classes for the L-Iter alphabet. -/
inductive ReadCls where
  | own | ancestor | ia | ud
deriving DecidableEq, Repr

/-- Step-constructor classes for the L-Iter / L-Raise alphabet. -/
inductive StepSig where
  | provideFresh | provideConflict
  | trackC
  | readCls (c : ReadCls)
  | setOwn | setMissing
  | regOk | regBad
  | raiseC
  | mismatch
deriving DecidableEq, Repr

/-- Dynamic provision conflict: some other present fiber's table already
    carries `k` (model.mjs `execute/provide`). -/
def dynConflict (γ : Config) (n : Slot) (k : Key) : Bool :=
  allSlots.any fun m =>
    m != n &&
    match γ.get m with
    | some f => (f.table.get k).isSome
    | none => false

def classifyCore (γ : Config) (n : Slot) (f : Fiber) : Step → StepSig
  | .provide k _ => if dynConflict γ n k then .provideConflict else .provideFresh
  | .track _ => .trackC
  | .read k =>
    match readC γ 4 n k false with
    | .ok _ anc => .readCls (if anc then .ancestor else .own)
    | .ia => .readCls .ia
    | .ud => .readCls .ud
  | .setval k _ => if (f.table.get k).isSome then .setOwn else .setMissing
  | .register => if allSlots.any (fun m => (γ.get m).isNone) then .regOk else .regBad
  | .raise => .raiseC

/-- Classification for an `lIter` label: the register alternative must name a
    free child slot; any mismatch between the label's `creg` and the head
    constructor is inert. -/
def classifyIter (γ : Config) (n : Slot) (f : Fiber) (creg : Option Slot) :
    Step → StepSig
  | .register =>
    match creg with
    | some cs => if (γ.get cs).isNone then .regOk else .regBad
    | none => .mismatch
  | s =>
    match creg with
    | some _ => .mismatch
    | none => classifyCore γ n f s

/-- Is `k` provided by some installed (not necessarily Active) fiber?
    (Distinguishes the `installed-only-provided` L-Begin class.) -/
def instProvided (γ : Config) (k : Key) : Bool :=
  allSlots.any fun m =>
    match γ.get m with
    | some f => f.st.isInstalled && (f.table.get k).isSome
    | none => false

/-- L-Begin satisfaction classes present among declared keys:
    (Active-provided, installed-only-provided, unprovided). -/
def satClsOf (γ : Config) (f : Fiber) : Bool × Bool × Bool :=
  ( allKeys.any fun k => f.comp.deps.get k && (providerOf γ k).isSome,
    allKeys.any fun k =>
      f.comp.deps.get k && !(providerOf γ k).isSome && instProvided γ k,
    allKeys.any fun k =>
      f.comp.deps.get k && !(providerOf γ k).isSome && !instProvided γ k )

def isUnprovideI : Inv → Bool
  | .unprovide _ => true
  | _ => false

def isUntrackI : Inv → Bool
  | .untrack _ => true
  | _ => false

def isRetireChildI : Inv → Bool
  | .retireChild _ => true
  | _ => false

/-- Accumulator inverse classes present. -/
def accClsOf (acc : Acc) : Bool × Bool × Bool :=
  (acc.val.any isUnprovideI, acc.val.any isUntrackI, acc.val.any isRetireChildI)

/-- The normalized atomic rule signature (Definition 3 of the companion
    paper, bounded): name-free guard atoms, step classes, and occurrence
    classes.  Irrelevant fields hold canonical defaults per rule. -/
structure SigR where
  rule : Rule
  present : Bool := false
  stCls : StCls := .absent
  retiredB : Bool := false
  tRel : TRel := .bot
  headStep : Option StepSig := none
  remEmpty : Bool := true
  reliedB : Bool := false
  hasChild : Bool := false
  slotFree : Bool := false
  provConf : Bool := false
  parentLive : Bool := true
  accCls : Bool × Bool × Bool := (false, false, false)
  satCls : Bool × Bool × Bool := (false, false, false)
deriving DecidableEq, Repr

/-- Head-step and iteration data of a reloading fiber, shared by the `sig`
    clauses below. -/
def remOf (x : Option Fiber) : Option Script :=
  match x with
  | some f =>
    match f.st with
    | .reloading rem _ _ => some rem
    | _ => none
  | none => none

def accOf (x : Option Fiber) : Option Acc :=
  match x with
  | some f =>
    match f.st with
    | .reloading _ acc _ => some acc
    | .unloading acc _ _ => some acc
    | _ => none
  | none => none

def remEmptyOf (x : Option Fiber) : Bool :=
  match remOf x with
  | some rem => rem.isEmpty
  | none => true

def accClsOfOpt (x : Option Fiber) : Bool × Bool × Bool :=
  match accOf x with
  | some acc => accClsOf acc
  | none => (false, false, false)

/-- κ_r: the signature of the window of label `a` at state `γ`. -/
def sig (a : Act) (γ : Config) : SigR :=
  match a with
  | .oInsert n c =>
    { rule := .oInsert
      slotFree := (γ.get n).isNone
      provConf := allSlots.any fun m =>
        match γ.get m with
        | some f => allKeys.any fun k => c.provs.get k && f.comp.provs.get k
        | none => false
      parentLive := true }
  | .oRetire n =>
    { rule := .oRetire
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      retiredB := retiredOf (γ.get n) }
  | .oRemove n =>
    { rule := .oRemove
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      retiredB := retiredOf (γ.get n)
      hasChild := hasChild γ n }
  | .lBegin n =>
    { rule := .lBegin
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      retiredB := retiredOf (γ.get n)
      tRel := tRelOf γ n
      satCls :=
        match γ.get n with
        | some f => satClsOf γ f
        | none => (false, false, false) }
  | .lIter n creg =>
    { rule := .lIter
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      tRel := tRelOf γ n
      headStep :=
        match γ.get n with
        | some f =>
          match f.st with
          | .reloading rem _ _ => (rem.head?).map (classifyIter γ n f creg)
          | _ => none
        | none => none
      remEmpty := remEmptyOf (γ.get n)
      accCls := accClsOfOpt (γ.get n) }
  | .lFinish n =>
    { rule := .lFinish
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      tRel := tRelOf γ n
      remEmpty := remEmptyOf (γ.get n) }
  | .lDivert n =>
    { rule := .lDivert
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      tRel := tRelOf γ n
      accCls := accClsOfOpt (γ.get n) }
  | .lRaise n =>
    { rule := .lRaise
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      tRel := tRelOf γ n
      headStep :=
        match γ.get n with
        | some f =>
          match f.st with
          | .reloading rem _ _ => (rem.head?).map (classifyCore γ n f)
          | _ => none
        | none => none
      remEmpty := remEmptyOf (γ.get n)
      accCls := accClsOfOpt (γ.get n) }
  | .lLeave n =>
    { rule := .lLeave
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      tRel := tRelOf γ n }
  | .lUnload n =>
    { rule := .lUnload
      present := (γ.get n).isSome
      stCls := stClsOf (γ.get n)
      retiredB := retiredOf (γ.get n)
      reliedB := reliedUpon γ n
      accCls := accClsOfOpt (γ.get n) }

/- ------------------------------------------------------------------ -/
/- Decisions and the specification table.                              -/
/- ------------------------------------------------------------------ -/

/-- Update variants a clause-factored table may select; `std` is Table 1's
    update.  `fifoAcc` composes inverses in application order, `dropAcc`
    discards the accumulator — the deviant decisions of the MUTANTS family
    (`accumulator-fifo`, `divert-skips-recovery`, `raise-skips-recovery`). -/
inductive Variant where
  | std | fifoAcc | dropAcc
deriving DecidableEq, Repr

inductive Dec where
  | disabled
  | fire (v : Variant)
deriving DecidableEq, Repr

instance : FinEnum Variant := ⟨[.std, .fifoAcc, .dropAcc], by intro x; cases x <;> simp⟩

instance : FinEnum Dec :=
  ⟨.disabled :: (all (α := Variant)).map .fire, by
    intro x
    cases x with
    | disabled => exact List.mem_cons_self ..
    | fire v => exact List.mem_cons_of_mem _ (List.mem_map_of_mem (complete v))⟩

def allDecs : List Dec := all

/-- Step classes on which L-Iter lands. -/
def headOkB : Option StepSig → Bool
  | some .provideFresh => true
  | some .trackC => true
  | some (.readCls _) => true
  | some .setOwn => true
  | some .regOk => true
  | _ => false

/-- Step classes on which the iteration raises (L-Raise). -/
def headFailB : Option StepSig → Bool
  | some .provideConflict => true
  | some .setMissing => true
  | some .regBad => true
  | some .raiseC => true
  | _ => false

/-- The specification's decision table f_r^𝕊 : Σ_r → Decision_r —
    the guard conjunctions of Table 1, read off the signature alone. -/
def enabledS (s : SigR) : Bool :=
  match s.rule with
  | .oInsert => s.slotFree && !s.provConf && s.parentLive
  | .oRetire => s.present
  | .oRemove => s.present && s.retiredB &&
      (s.stCls == .inactOk || s.stCls == .inactErr) && !s.hasChild
  | .lBegin => s.present && s.stCls == .inactOk && s.tRel == .ne
  | .lIter => s.present && s.stCls == .reload && s.tRel == .eq &&
      !s.remEmpty && headOkB s.headStep
  | .lFinish => s.present && s.stCls == .reload && s.tRel == .eq && s.remEmpty
  | .lDivert => s.present && s.stCls == .reload && s.tRel != .eq
  | .lRaise => s.present && s.stCls == .reload && s.tRel == .eq &&
      !s.remEmpty && headFailB s.headStep
  | .lLeave => s.present && s.stCls == .activeS && s.tRel != .eq
  | .lUnload => s.present && (s.stCls == .unloadOk || s.stCls == .unloadErr) &&
      !s.reliedB

def fS (s : SigR) : Dec := if enabledS s then .fire .std else .disabled

/- ------------------------------------------------------------------ -/
/- The reconstruction operator lift_r.                                 -/
/- ------------------------------------------------------------------ -/

def freshFiber (c : Component) (parent : Option Slot) : Fiber :=
  { comp := c, parent := parent, retired := false
    table := KMap.const none, st := .inactive .ok }

/-- The one fixed component `register` instantiates (register depth 1).
    It reads k₀ undeclared (the ancestor-committed read class), applies a
    tracked effect, then raises — L-Raise with a nonempty accumulator. -/
def childComp : Component :=
  { deps := KMap.const false, provs := KMap.const false
    script := ⟨[.read 0, .track 0, .raise], by decide⟩ }

/-- One L-Iter landing (Def. 51): consume the head step, apply its effect,
    push its inverse.  Total: on step classes where the specification would
    instead raise, the landing is inert (deviant tables may select it). -/
def execStep (γ : Config) (n : Slot) (f : Fiber) (s : Step)
    (rem : Script) (acc : Acc) (ω : View) (creg : Option Slot) : Ev × Config :=
  match s with
  | .provide k v =>
    let f' := { f with table := f.table.set k (some v)
                       st := .reloading rem (acc.push (.unprovide k)) ω }
    ([.provided n k], upd γ n (some f'))
  | .track t =>
    ([.applied n t],
      upd γ n (some { f with st := .reloading rem (acc.push (.untrack t)) ω }))
  | .read k =>
    let ev : Event :=
      match readC γ 4 n k false with
      | .ok v _ => .readOk n k v
      | .ia => .readFail n k true
      | .ud => .readFail n k false
    ([ev], upd γ n (some { f with st := .reloading rem acc ω }))
  | .setval k v =>
    match f.table.get k with
    | some _ =>
      ([.setv n k v],
        upd γ n (some { f with table := f.table.set k (some v)
                               st := .reloading rem acc ω }))
    | none => ([], upd γ n (some { f with st := .reloading rem acc ω }))
  | .register =>
    match creg with
    | some cs =>
      if (γ.get cs).isNone then
        let γ1 := upd γ cs (some (freshFiber childComp (some n)))
        ([.registered n cs],
          upd γ1 n (some { f with st := .reloading rem (acc.push (.retireChild cs)) ω }))
      else ([], upd γ n (some { f with st := .reloading rem acc ω }))
    | none => ([], upd γ n (some { f with st := .reloading rem acc ω }))
  | .raise => ([], upd γ n (some { f with st := .reloading rem acc ω }))

/-- Apply one accumulator inverse (L-Unload's fold), emitting its event. -/
def applyInv (n : Slot) : Ev × Config → Inv → Ev × Config
  | (ev, γ), .unprovide k =>
    (ev ++ [.unprovided n k],
      match γ.get n with
      | some f => upd γ n (some { f with table := f.table.set k none })
      | none => γ)
  | (ev, γ), .untrack t => (ev ++ [.reverted n t], γ)
  | (ev, γ), .retireChild s =>
    (ev ++ [.childRetired n s],
      match γ.get s with
      | some f => upd γ s (some { f with retired := true })
      | none => γ)

/-- lift_r: reconstruct the full rule result from a decision.  Structural
    shape checks only (a fiber must exist to be updated; a slot must be free
    to be filled); every semantic guard lives in the table. -/
def liftStep (a : Act) (γ : Config) (d : Dec) : Option (Ev × Config) :=
  match d with
  | .disabled => none
  | .fire var =>
    match a with
    | .oInsert n c =>
      match γ.get n with
      | some _ => none
      | none => some ([.inserted n], upd γ n (some (freshFiber c none)))
    | .oRetire n =>
      match γ.get n with
      | some f => some ([.retiredEv n], upd γ n (some { f with retired := true }))
      | none => none
    | .oRemove n =>
      match γ.get n with
      | some _ => some ([.removedEv n], upd γ n none)
      | none => none
    | .lBegin n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .inactive _ =>
          some ([.began n],
            upd γ n (some { f with
              st := .reloading f.comp.script BList.nil (partialTarget γ f) }))
        | _ => none
      | none => none
    | .lIter n creg =>
      match γ.get n with
      | some f =>
        match f.st with
        | .reloading rem acc ω =>
          match rem.head? with
          | some s => some (execStep γ n f s rem.tail acc ω creg)
          | none => none
        | _ => none
      | none => none
    | .lFinish n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .reloading _ acc ω =>
          some ([.activated n], upd γ n (some { f with st := .active acc ω }))
        | _ => none
      | none => none
    | .lDivert n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .reloading _ acc ω =>
          let acc' := if var == .dropAcc then BList.nil else acc
          some ([.diverted n], upd γ n (some { f with st := .unloading acc' ω .ok }))
        | _ => none
      | none => none
    | .lRaise n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .reloading _ acc ω =>
          let acc' := if var == .dropAcc then BList.nil else acc
          some ([.raised n], upd γ n (some { f with st := .unloading acc' ω .err }))
        | _ => none
      | none => none
    | .lLeave n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .active acc ω =>
          some ([.leftEv n], upd γ n (some { f with st := .unloading acc ω .ok }))
        | _ => none
      | none => none
    | .lUnload n =>
      match γ.get n with
      | some f =>
        match f.st with
        | .unloading acc ω o =>
          let invs :=
            match var with
            | .std => acc.val.reverse
            | .fifoAcc => acc.val
            | .dropAcc => []
          let r := invs.foldl (applyInv n) ([], γ)
          let γ2 :=
            match r.2.get n with
            | some f' => upd r.2 n (some { f' with st := .inactive o })
            | none => r.2
          some (r.1 ++ [.deactivated n], γ2)
        | _ => none
      | none => none

/-- The specification LTS 𝕊, in clause-factored form (Lemma 2 of the
    companion paper holds definitionally in the bounded mechanization). -/
def specStep (a : Act) (γ : Config) : Option (Ev × Config) :=
  liftStep a γ (fS (sig a γ))

/- ------------------------------------------------------------------ -/
/- Observations.                                                       -/
/- ------------------------------------------------------------------ -/

inductive Status where
  | absent | pending | failed | loading | activeS | unloadingS
deriving DecidableEq, Repr

def statusOf : Option Fiber → Status × Bool
  | none => (.absent, false)
  | some f =>
    (match f.st with
     | .inactive .ok => .pending
     | .inactive .err => .failed
     | .reloading .. => .loading
     | .active .. => .activeS
     | .unloading .. => .unloadingS,
     f.retired)

/-- The per-state observation: lifecycle class and retirement per slot, the
    visible coeffect store, and quiescence.  Refusals are observed per label
    as `none` rows of the suite. -/
structure Obs where
  statuses : SMap (Status × Bool)
  store : KMap (Option Val)
  quiescent : Bool
deriving DecidableEq, Repr

def obs (γ : Config) : Obs :=
  { statuses := ⟨statusOf (γ.get 0), statusOf (γ.get 1), statusOf (γ.get 2)⟩
    store := KMap.ofFun (storeOf γ)
    quiescent := quiet γ }

/-- The observable content of one transition row. -/
def obsRow (x : Option (Ev × Config)) : Option (Ev × Obs) :=
  x.map fun p => (p.1, obs p.2)

/- ------------------------------------------------------------------ -/
/- The bounded component catalog and probe labels.                     -/
/- ------------------------------------------------------------------ -/

/-- Provider of k₀. -/
def cProv : Component :=
  ⟨KMap.const false, ⟨true, false⟩, ⟨[.provide 0 0], by decide⟩⟩

/-- Consumer of k₀: committed read, then two tracked effects — the witnessed
    inverses whose application order exhibits LIFO recovery (§5.3 of the
    companion paper, "accumulator order"). -/
def cCons : Component :=
  ⟨⟨true, false⟩, KMap.const false, ⟨[.read 0, .track 0, .track 1], by decide⟩⟩

/-- Registers the fixed child while depending on k₀ (register depth 1);
    with `childComp` this exercises registration, the reliance guard, the
    ancestor-committed read, and L-Raise with recovery. -/
def cReg : Component :=
  ⟨⟨true, false⟩, KMap.const false, ⟨[.register], by decide⟩⟩

/-- The shipped catalog.  Deviation log (PROOF_STATUS.md): `setval` and the
    second key/value are present in the step grammar and state space (and in
    Theorem A) but unexercised by the catalog — the state count at the full
    six-component catalog (157,230) exceeds what the kernel-adjacent checks
    can afford; this three-component catalog reaches 15,173 states. -/
def catalog : List Component := [cProv, cCons, cReg]

/-- The finite probe-label alphabet driving `Reachable` and the explorer. -/
def catalogActs : List Act :=
  (allSlots.flatMap fun n => catalog.map (Act.oInsert n)) ++
  (allSlots.map Act.oRetire) ++
  (allSlots.map Act.oRemove) ++
  (allSlots.map Act.lBegin) ++
  (allSlots.flatMap fun n => (none :: allSlots.map some).map (Act.lIter n)) ++
  (allSlots.map Act.lFinish) ++
  (allSlots.map Act.lDivert) ++
  (allSlots.map Act.lRaise) ++
  (allSlots.map Act.lLeave) ++
  (allSlots.map Act.lUnload)

end Bounded
