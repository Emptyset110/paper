# Reachable occurrence signatures (bound tag: sat2)

States (normalized): 7150 — expanded: 7150, edges: 47719 (refusal edges: 7350), quiescent: 97, internal cycle: false, truncated: false, wall-clock: 1.0s

## O-Insert — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 125 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 250 |

## O-Retire — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 1326 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 7 | 428 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 1980 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 1115 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 4 | 1888 |

## O-Remove — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 1326 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 1980 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 2588 |
| O-Remove.4 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 1115 |
| O-Remove.5 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 8 | 428 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 2230 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 7 | 856 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 2652 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 3960 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 3620 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 6 | 856 |

## L-Begin — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 323 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 1115 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 7 | 428 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 8 | 428 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 36 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":[]}` | 1 | 756 |

## L-Iter — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 368 |
| L-Iter.2 | fired | `{"stepClass":"track"}` | 6 | 24 |

## L-Raise — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 136 |

## L-Finish — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide"]}` | 3 | 728 |
| L-Finish.2 | fired | `{"acc":["track"]}` | 7 | 24 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 728 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 728 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["track"]}` | 8 | 44 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["track"]}` | 8 | 64 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":[]}` | 3 | 548 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 568 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 864 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 884 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 904 |

## L-Unload — 12 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 120 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 180 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 1092 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 728 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 30 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 9 | 66 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 9 | 24 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 30 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 822 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 528 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 428 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 428 |

## A-Set — 23 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 36 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 36 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 30 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 30 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 72 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 72 |
| A-Set.7 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 60 |
| A-Set.8 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 60 |
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 60 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 60 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 60 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 60 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 1092 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 1092 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 1092 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 1092 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 5 | 910 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 6 | 910 |
| A-Set.19 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 8 | 132 |
| A-Set.20 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 7 | 856 |
| A-Set.21 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 1776 |
| A-Set.22 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 2230 |
| A-Set.23 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 4 | 2356 |

