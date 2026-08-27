# Reachable occurrence signatures (bound tag: fail3)

States (normalized): 688484 — expanded: 688484, edges: 6943826 (refusal edges: 1255740), quiescent: 729, internal cycle: false, truncated: false, wall-clock: 280.3s

## O-Insert — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 14251 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 42753 |

## O-Retire — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 124422 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 5 | 85488 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 279162 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 172908 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 4 | 314528 |

## O-Remove — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 124422 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 279162 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 412532 |
| O-Remove.4 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 172908 |
| O-Remove.5 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 6 | 85488 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 345816 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 5 | 170976 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 248844 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 558324 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 507660 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 4 | 219400 |

## L-Begin — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 37800 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 172908 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 5 | 85488 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 6 | 85488 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 5220 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":[]}` | 1 | 129888 |

## L-Iter — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 44100 |
| L-Iter.2 | fired | `{"stepClass":"track"}` | 6 | 3480 |

## L-Raise — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"raise","acc":["provide"]}` | 3 | 24764 |
| L-Raise.2 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 42492 |

## L-Finish — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide"]}` | 3 | 61912 |
| L-Finish.2 | fired | `{"acc":["track"]}` | 7 | 3480 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 86676 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 86676 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["track"]}` | 8 | 6420 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["track"]}` | 8 | 9360 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":[]}` | 3 | 93012 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 95952 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 80008 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 82948 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 85888 |

## L-Unload — 14 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 15780 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 23670 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 130014 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 86676 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 24764 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 4 | 24764 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 4410 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 9 | 9630 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 9 | 3480 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 4410 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 139518 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 90072 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 84936 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 84936 |

## A-Set — 35 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","loading"]}` | 10 | 432 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","loading"]}` | 11 | 432 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","loading"]}` | 12 | 360 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","loading"]}` | 13 | 360 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","unloading"]}` | 12 | 360 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","unloading"]}` | 13 | 360 |
| A-Set.7 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","unloading"]}` | 13 | 360 |
| A-Set.8 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","unloading"]}` | 14 | 360 |
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 4302 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 4302 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 3585 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 3585 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading","unloading"]}` | 10 | 720 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading","unloading"]}` | 11 | 720 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading","unloading"]}` | 11 | 720 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading","unloading"]}` | 12 | 720 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 8820 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 8820 |
| A-Set.19 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 7350 |
| A-Set.20 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 7350 |
| A-Set.21 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 7290 |
| A-Set.22 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 7290 |
| A-Set.23 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 7350 |
| A-Set.24 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 7350 |
| A-Set.25 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 92868 |
| A-Set.26 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 92868 |
| A-Set.27 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 130014 |
| A-Set.28 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 130014 |
| A-Set.29 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 4 | 133109 |
| A-Set.30 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 5 | 133109 |
| A-Set.31 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 8 | 19260 |
| A-Set.32 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 5 | 170976 |
| A-Set.33 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 298296 |
| A-Set.34 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 345816 |
| A-Set.35 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 4 | 421392 |

