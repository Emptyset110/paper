# Reachable occurrence signatures (bound tag: dep3)

States (normalized): 558748 — expanded: 558748, edges: 5495264 (refusal edges: 1031008), quiescent: 1729, internal cycle: false, truncated: false, wall-clock: 213.6s

## O-Insert — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 10412 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 41648 |

## O-Retire — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 156228 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 7 | 59220 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 192324 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 156346 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 4 | 230076 |

## O-Remove — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 156228 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 192324 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 307378 |
| O-Remove.4 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 156346 |
| O-Remove.5 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 8 | 59220 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 312692 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 7 | 118440 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 312456 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 384648 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 441950 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 6 | 95504 |

## L-Begin — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["provided","unprovided"]}` | 5 | 6276 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 73642 |
| L-Begin.3 | disabled | `{"outcome":"bot","retired":true}` | 2 | 156346 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":false}` | 7 | 59220 |
| L-Begin.5 | disabled | `{"outcome":"xi","retired":true}` | 8 | 59220 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 13104 |
| L-Begin.7 | fired | `{"outcome":"bot","inject":[]}` | 1 | 63324 |

## L-Iter — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 27928 |
| L-Iter.2 | fired | `{"stepClass":"track"}` | 7 | 3744 |
| L-Iter.3 | fired | `{"stepClass":"track-rrev"}` | 6 | 4296 |

## L-Raise — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 18584 |

## L-Finish — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide","track"]}` | 8 | 3600 |
| L-Finish.2 | fired | `{"acc":["provide"]}` | 3 | 47744 |
| L-Finish.3 | fired | `{"acc":["rrev"]}` | 7 | 4296 |
| L-Finish.4 | fired | `{"acc":["track"]}` | 12 | 144 |

## L-Divert — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide","track"]}` | 9 | 6660 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide","track"]}` | 9 | 9720 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 54404 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 57464 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":["rrev"]}` | 8 | 7976 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":["rrev"]}` | 8 | 11656 |
| L-Divert.7 | fired | `{"trigger":"stale","acc":["track"]}` | 13 | 504 |
| L-Divert.8 | fired | `{"trigger":"target-bot","acc":["track"]}` | 13 | 864 |
| L-Divert.9 | fired | `{"trigger":"stale","acc":[]}` | 3 | 58672 |
| L-Divert.10 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 66392 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 96452 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 104152 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 111852 |

## L-Unload — 22 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide","track"]}` | 13 | 1620 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide","track"]}` | 13 | 1980 |
| L-Unload.3 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 43548 |
| L-Unload.4 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 65322 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 11 | 4590 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 10 | 9990 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"sat"}` | 10 | 3600 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 10 | 4590 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 81606 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 51344 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 10 | 5520 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 9 | 11964 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"sat"}` | 9 | 4296 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 15 | 540 |
| L-Unload.15 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 14 | 756 |
| L-Unload.16 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 14 | 144 |
| L-Unload.17 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 11580 |
| L-Unload.18 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 88008 |
| L-Unload.19 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 50952 |
| L-Unload.20 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 12 | 3300 |
| L-Unload.21 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 47752 |
| L-Unload.22 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 44452 |

## A-Set — 35 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","loading"]}` | 10 | 2160 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","loading"]}` | 11 | 2160 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","loading"]}` | 12 | 1800 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","loading"]}` | 13 | 1800 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","unloading"]}` | 12 | 2268 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","unloading"]}` | 13 | 2268 |
| A-Set.7 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","unloading"]}` | 13 | 2220 |
| A-Set.8 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","unloading"]}` | 14 | 2220 |
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 8262 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 8262 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 6885 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 6885 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading","unloading"]}` | 10 | 4860 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading","unloading"]}` | 11 | 4860 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading","unloading"]}` | 11 | 4740 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading","unloading"]}` | 12 | 4740 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 21582 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 21582 |
| A-Set.19 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 17985 |
| A-Set.20 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 17985 |
| A-Set.21 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 20862 |
| A-Set.22 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 20862 |
| A-Set.23 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 20805 |
| A-Set.24 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 20805 |
| A-Set.25 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 71616 |
| A-Set.26 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 71616 |
| A-Set.27 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 71616 |
| A-Set.28 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 71616 |
| A-Set.29 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 5 | 59680 |
| A-Set.30 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 6 | 59680 |
| A-Set.31 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 8 | 49236 |
| A-Set.32 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 7 | 118440 |
| A-Set.33 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 241416 |
| A-Set.34 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 312692 |
| A-Set.35 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 4 | 309224 |

## A-Read — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-self"}` | 9 | 21780 |

