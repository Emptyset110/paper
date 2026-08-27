# Reachable occurrence signatures (bound tag: sat3)

States (normalized): 277063 — expanded: 277063, edges: 2760383 (refusal edges: 490532), quiescent: 453, internal cycle: false, truncated: false, wall-clock: 95.7s

## O-Insert — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 7321 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 14642 |

## O-Retire — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 72612 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 7 | 29028 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 107550 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 66833 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 4 | 115948 |

## O-Remove — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 72612 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 107550 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 155748 |
| O-Remove.4 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 66833 |
| O-Remove.5 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 8 | 29028 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 133666 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 7 | 58056 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 145224 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 215100 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 213640 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 6 | 58056 |

## L-Begin — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 17831 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 66833 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 7 | 29028 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 8 | 29028 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 4320 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":[]}` | 1 | 44682 |

## L-Iter — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 16004 |
| L-Iter.2 | fired | `{"stepClass":"track"}` | 6 | 2880 |

## L-Raise — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 13784 |

## L-Finish — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide"]}` | 3 | 31272 |
| L-Finish.2 | fired | `{"acc":["track"]}` | 7 | 2880 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 31272 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 31272 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["track"]}` | 8 | 5320 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["track"]}` | 8 | 7760 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":[]}` | 3 | 35108 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 37548 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 45968 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 48408 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 50848 |

## L-Unload — 12 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 12780 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 19170 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 46908 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 31272 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 3660 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 9 | 7980 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 9 | 2880 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 3660 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 52662 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 32668 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 29028 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 29028 |

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
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 3402 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 3402 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 2835 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 2835 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading","unloading"]}` | 10 | 720 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading","unloading"]}` | 11 | 720 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading","unloading"]}` | 11 | 720 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading","unloading"]}` | 12 | 720 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 7020 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 7020 |
| A-Set.19 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 5850 |
| A-Set.20 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 5850 |
| A-Set.21 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 5790 |
| A-Set.22 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 5790 |
| A-Set.23 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 5850 |
| A-Set.24 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 5850 |
| A-Set.25 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 46908 |
| A-Set.26 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 46908 |
| A-Set.27 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 46908 |
| A-Set.28 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 46908 |
| A-Set.29 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 5 | 39090 |
| A-Set.30 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 6 | 39090 |
| A-Set.31 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 8 | 15960 |
| A-Set.32 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 7 | 58056 |
| A-Set.33 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 121284 |
| A-Set.34 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 133666 |
| A-Set.35 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 4 | 161566 |

