# Reachable occurrence signatures (bound tag: A1)

States (normalized): 614 — expanded: 614, edges: 2100 (refusal edges: 345), quiescent: 49, internal cycle: false, truncated: false, wall-clock: 0.1s

## O-Insert — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 2 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 17 |

## O-Retire — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 44 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 4 | 7 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 113 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 51 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 3 | 75 |

## O-Remove — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 44 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 113 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 108 |
| O-Remove.4 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 51 |
| O-Remove.5 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 5 | 7 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 102 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 4 | 14 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 88 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 226 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 165 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 3 | 18 |

## L-Begin — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 12 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 51 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 4 | 7 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 5 | 7 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":[]}` | 1 | 39 |

## L-Iter — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"flag-pass"}` | 3 | 1 |
| L-Iter.2 | fired | `{"stepClass":"provide-fresh"}` | 2 | 14 |
| L-Iter.3 | fired | `{"stepClass":"read-undeclared-np"}` | 2 | 2 |
| L-Iter.4 | fired | `{"stepClass":"setval-own-eq"}` | 3 | 4 |
| L-Iter.5 | fired | `{"stepClass":"setval-own-neq"}` | 3 | 4 |
| L-Iter.6 | fired | `{"stepClass":"track"}` | 2 | 12 |

## L-Raise — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"raise","acc":["provide"]}` | 3 | 4 |
| L-Raise.2 | fired | `{"stepClass":"raise","acc":["track"]}` | 3 | 2 |
| L-Raise.3 | fired | `{"stepClass":"flag-fail","acc":[]}` | 2 | 1 |
| L-Raise.4 | fired | `{"stepClass":"setval-foreign","acc":[]}` | 2 | 2 |

## L-Finish — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide","track"]}` | 4 | 4 |
| L-Finish.2 | fired | `{"acc":["provide"]}` | 3 | 18 |
| L-Finish.3 | fired | `{"acc":["track"]}` | 3 | 4 |
| L-Finish.4 | fired | `{"acc":[]}` | 3 | 3 |

## L-Divert — 8 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide","track"]}` | 5 | 4 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide","track"]}` | 5 | 4 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 34 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 34 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":["track"]}` | 4 | 8 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":["track"]}` | 4 | 8 |
| L-Divert.7 | fired | `{"trigger":"stale","acc":[]}` | 3 | 30 |
| L-Divert.8 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 29 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 29 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 30 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 29 |

## L-Unload — 16 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 6 | 6 |
| L-Unload.2 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"sat"}` | 6 | 4 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 42 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 28 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 4 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 4 | 4 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track","track"],"postTarget":"bot"}` | 6 | 3 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track","track"],"postTarget":"sat"}` | 6 | 2 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 9 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 5 | 6 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 2 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 4 | 2 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 39 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 26 |
| L-Unload.15 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 3 |
| L-Unload.16 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 3 | 3 |

## A-Set — 11 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 30 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 36 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 54 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 60 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 4 | 44 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 5 | 44 |
| A-Set.7 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 4 | 22 |
| A-Set.8 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 4 | 14 |
| A-Set.9 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 112 |
| A-Set.10 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 102 |
| A-Set.11 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 3 | 95 |

## A-Read — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"undeclared-np"}` | 2 | 2 |

