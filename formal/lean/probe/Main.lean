import Bounded.Enum
open Bounded

def succsOf' (γ : Config) : List (Act × Config) :=
  catalogActs.filterMap fun a => (specStep a γ).map fun p => (a, p.2)

partial def bfs (frontier : List (Config × List Act))
    (seen : Std.HashMap Config (List Act)) (acc : List (Config × List Act)) :
    Std.HashMap Config (List Act) × List (Config × List Act) :=
  match frontier with
  | [] => (seen, acc)
  | (γ, w) :: rest =>
    let (newSeen, newOnes) :=
      (succsOf' γ).foldl (fun (s, ns) ac =>
        if s.contains ac.2 then (s, ns)
        else (s.insert ac.2 (w ++ [ac.1]), (ac.2, w ++ [ac.1]) :: ns)) (seen, [])
    bfs (rest ++ newOnes.reverse) newSeen (acc ++ newOnes.reverse)

def cat (cs : List Component) : List Act :=
  (allSlots.flatMap fun n => cs.map (Act.oInsert n)) ++
  (allSlots.map Act.oRetire) ++ (allSlots.map Act.oRemove) ++
  (allSlots.map Act.lBegin) ++
  (allSlots.flatMap fun n => (none :: allSlots.map some).map (Act.lIter n)) ++
  (allSlots.map Act.lFinish) ++ (allSlots.map Act.lDivert) ++
  (allSlots.map Act.lRaise) ++ (allSlots.map Act.lLeave) ++ (allSlots.map Act.lUnload)

def main : IO Unit := do
  IO.println s!"catalogActs = {catalogActs.length}"
  let t0 ← IO.monoMsNow
  let (seen, ps) := bfs [(emptyConfig, [])]
      (Std.HashMap.emptyWithCapacity.insert emptyConfig []) [(emptyConfig, [])]
  let t1 ← IO.monoMsNow
  IO.println s!"states = {seen.size} pairs={ps.length} bfs ms = {t1 - t0}"
  -- cost of the list-membership closure check
  let vs := ps.map (·.1)
  let t2 ← IO.monoMsNow
  let ok := vs.all fun γ => (succsOf' γ).all fun q => vs.contains q.2
  let t3 ← IO.monoMsNow
  IO.println s!"list closure check = {ok}  ms = {t3 - t2}"
  let t4 ← IO.monoMsNow
  let tot := vs.foldl (fun n γ => n + (succsOf' γ).length) 0
  let t5 ← IO.monoMsNow
  IO.println s!"edges = {tot} ms={t5-t4}"
