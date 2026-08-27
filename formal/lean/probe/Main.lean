import Std.Data.HashMap
import Bounded.SigDec
open Bounded

instance : Hashable Config := inferInstanceAs (Hashable (SMap (Option Fiber)))
instance : BEq Config := inferInstanceAs (BEq (SMap (Option Fiber)))

def cat (cs : List Component) : List Act :=
  (allSlots.flatMap fun n => cs.map (Act.oInsert n)) ++
  (allSlots.map Act.oRetire) ++ (allSlots.map Act.oRemove) ++
  (allSlots.map Act.lBegin) ++
  (allSlots.flatMap fun n => (none :: allSlots.map some).map (Act.lIter n)) ++
  (allSlots.map Act.lFinish) ++ (allSlots.map Act.lDivert) ++
  (allSlots.map Act.lRaise) ++ (allSlots.map Act.lLeave) ++ (allSlots.map Act.lUnload)

def succs (acts : List Act) (γ : Config) : List (Act × Config) :=
  acts.filterMap fun a => (specStep a γ).map fun p => (a, p.2)

partial def go (acts : List Act) (cap : Nat)
    (front back : List (Config × List Act))
    (seen : Std.HashMap Config Unit) (out : List (Config × List Act)) :
    Except Nat (List (Config × List Act)) :=
  if seen.size > cap then .error seen.size else
  match front with
  | [] =>
    match back.reverse with
    | [] => .ok out.reverse
    | f => go acts cap f [] seen out
  | (γ, w) :: rest =>
    let (seen', back', out') :=
      (succs acts γ).foldl (fun (s, b, o) ac =>
        if s.contains ac.2 then (s, b, o)
        else (s.insert ac.2 (), (ac.2, w ++ [ac.1]) :: b, (ac.2, w ++ [ac.1]) :: o))
        (seen, back, out)
    go acts cap rest back' seen' out'

def say (s : String) : IO Unit := do
  IO.println s
  (← IO.getStdout).flush

def run (name : String) (cs : List Component) (cap : Nat) : IO Unit := do
  say s!"-- start {name}"
  let acts := cat cs
  let t0 ← IO.monoMsNow
  match go acts cap [(emptyConfig, [])] []
      ((Std.HashMap.emptyWithCapacity : Std.HashMap Config Unit).insert emptyConfig ())
      [(emptyConfig, [])] with
  | .error k => say s!"{name}: |acts|={acts.length} EXCEEDED cap {cap} (>= {k})"
  | .ok ps =>
    let t1 ← IO.monoMsNow
    let vs := ps.map (·.1)
    let edges := vs.foldl (fun n γ => n + (succs acts γ).length) 0
    let maxw := ps.foldl (fun n p => max n p.2.length) 0
    let t2 ← IO.monoMsNow
    say s!"{name}: |acts|={acts.length} N={ps.length} edges={edges} maxWord={maxw} bfs={t1-t0}ms succ={t2-t1}ms"
    let t3 ← IO.monoMsNow
    let ok := vs.all fun γ => (succs acts γ).all fun q => vs.contains q.2
    let t4 ← IO.monoMsNow
    say s!"{name}: listClosure={ok} in {t4-t3}ms"

def main (args : List String) : IO Unit := do
  let cap := 400000
  let sel := args.head? |>.getD "all"
  if sel == "all" || sel == "1" then run "[cProv]" [cProv] cap
  if sel == "all" || sel == "2" then run "[cCons]" [cCons] cap
  if sel == "all" || sel == "3" then run "[cReg]" [cReg] cap
  if sel == "all" || sel == "4" then run "[cProv,cCons]" [cProv, cCons] cap
  if sel == "all" || sel == "5" then run "[cProv,cReg]" [cProv, cReg] cap
  if sel == "all" || sel == "6" then run "[cProv,cCons,cReg]" [cProv, cCons, cReg] cap
