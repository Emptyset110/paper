# Reachable occurrence signatures (bound tag: regB)

States (normalized): 19707 — expanded: 19707, edges: 87654 (refusal edges: 434), quiescent: 46, internal cycle: false, truncated: false, wall-clock: 20.9s

## O-Insert — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"live","declaredConflict":false,"realm":"root"}` | 6 | 200 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 518 |
| O-Insert.3 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 549 |

## O-Retire — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 10755 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 7 | 1316 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 10416 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 5256 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 6 | 2712 |
| O-Retire.6 | fired | `{"stateClass":"active","again":true}` | 13 | 434 |
| O-Retire.7 | fired | `{"stateClass":"disposed","again":true}` | 11 | 408 |
| O-Retire.8 | fired | `{"stateClass":"loading","again":true}` | 11 | 868 |
| O-Retire.9 | fired | `{"stateClass":"pending","again":true}` | 10 | 434 |
| O-Retire.10 | fired | `{"stateClass":"unloading","again":true}` | 12 | 434 |

## O-Remove — 9 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 8421 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 8626 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 13273 |
| O-Remove.4 | disabled | `{"stateClass":"active","hasChild":true}` | 9 | 2913 |
| O-Remove.5 | disabled | `{"stateClass":"inactive","hasChild":true}` | 10 | 1955 |
| O-Remove.6 | disabled | `{"stateClass":"reloading","hasChild":true}` | 8 | 2943 |
| O-Remove.7 | disabled | `{"stateClass":"unloading","hasChild":true}` | 9 | 2943 |
| O-Remove.8 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 6228 |
| O-Remove.9 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 8 | 1316 |

## L-Begin — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 1473 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 8183 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 7 | 1316 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 8 | 1316 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 199 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":[]}` | 1 | 3150 |

## L-Iter — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 972 |
| L-Iter.2 | fired | `{"stepClass":"read-committed-ancestor"}` | 8 | 1702 |
| L-Iter.3 | fired | `{"stepClass":"register"}` | 6 | 200 |

## L-Raise — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 476 |

## L-Finish — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide"]}` | 3 | 918 |
| L-Finish.2 | fired | `{"acc":["retire"]}` | 7 | 2181 |
| L-Finish.3 | fired | `{"acc":[]}` | 9 | 1702 |

## L-Divert — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 918 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["retire"]}` | 8 | 4748 |
| L-Divert.3 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 7300 |

## L-Leave — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 9041 |
| L-Leave.2 | fired | `{"trigger":"target-bot"}` | 5 | 12614 |

## L-Unload — 8 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 5684 |
| L-Unload.2 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 1273 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 10 | 1163 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 9 | 3151 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 117 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 4475 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 1316 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 1315 |

## A-Read — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-ancestor"}` | 8 | 1702 |

