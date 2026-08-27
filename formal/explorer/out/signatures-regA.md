# Reachable occurrence signatures (bound tag: regA)

States (normalized): 631538 — expanded: 407815, edges: 4886365 (refusal edges: 959173), quiescent: 320, internal cycle: false, truncated: true, wall-clock: 1501.4s

## O-Insert — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"live","declaredConflict":false,"realm":"root"}` | 6 | 8588 |
| O-Insert.2 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 7569 |
| O-Insert.3 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 7694 |

## O-Retire — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 220470 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 7 | 15418 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 294533 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 175119 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 4 | 141318 |
| O-Retire.6 | fired | `{"stateClass":"active","again":true}` | 13 | 500 |
| O-Retire.7 | fired | `{"stateClass":"disposed","again":true}` | 11 | 2883 |
| O-Retire.8 | fired | `{"stateClass":"loading","again":true}` | 11 | 5249 |
| O-Retire.9 | fired | `{"stateClass":"pending","again":true}` | 10 | 6110 |
| O-Retire.10 | fired | `{"stateClass":"unloading","again":true}` | 12 | 1501 |

## O-Remove — 9 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 106530 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 145559 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 146569 |
| O-Remove.4 | disabled | `{"stateClass":"active","hasChild":true}` | 9 | 20305 |
| O-Remove.5 | disabled | `{"stateClass":"inactive","hasChild":true}` | 10 | 6785 |
| O-Remove.6 | disabled | `{"stateClass":"reloading","hasChild":true}` | 8 | 39484 |
| O-Remove.7 | disabled | `{"stateClass":"unloading","hasChild":true}` | 9 | 19281 |
| O-Remove.8 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 120332 |
| O-Remove.9 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 8 | 10446 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 290713 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 7 | 25864 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 345804 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 467745 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 269129 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 6 | 36854 |

## L-Begin — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 18022 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":true}` | 2 | 127117 |
| L-Begin.3 | disabled | `{"outcome":"xi","retired":false}` | 7 | 15418 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":true}` | 8 | 10446 |
| L-Begin.5 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 15345 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":[]}` | 1 | 130229 |

## L-Iter — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 24565 |
| L-Iter.2 | fired | `{"stepClass":"read-committed-ancestor"}` | 8 | 31003 |
| L-Iter.3 | fired | `{"stepClass":"register"}` | 6 | 8588 |

## L-Raise — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 23690 |

## L-Finish — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide"]}` | 3 | 35364 |
| L-Finish.2 | fired | `{"acc":["retire"]}` | 7 | 45164 |
| L-Finish.3 | fired | `{"acc":[]}` | 9 | 15990 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 28087 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 28085 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["retire"]}` | 8 | 32822 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["retire"]}` | 8 | 48166 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":[]}` | 3 | 69221 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 77000 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 151372 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 93369 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 101063 |

## L-Unload — 12 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 28507 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 37939 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 34566 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 24205 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 10 | 9482 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 9 | 20434 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"sat"}` | 9 | 12367 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 2995 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 56531 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 40106 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 7 | 15418 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 6 | 21436 |

## A-Set — 35 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","loading"]}` | 10 | 6460 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","loading"]}` | 11 | 2293 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","loading"]}` | 12 | 1033 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","loading"]}` | 13 | 231 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active","unloading"]}` | 12 | 1033 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active","unloading"]}` | 13 | 231 |
| A-Set.7 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active","unloading"]}` | 13 | 252 |
| A-Set.8 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active","unloading"]}` | 14 | 40 |
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 28079 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 15337 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 9088 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 4043 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading","unloading"]}` | 10 | 3457 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading","unloading"]}` | 11 | 1265 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading","unloading"]}` | 11 | 1265 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading","unloading"]}` | 12 | 405 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 56309 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 34112 |
| A-Set.19 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 21834 |
| A-Set.20 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 11620 |
| A-Set.21 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 20297 |
| A-Set.22 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 11036 |
| A-Set.23 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 11182 |
| A-Set.24 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 5453 |
| A-Set.25 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 47032 |
| A-Set.26 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 35239 |
| A-Set.27 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 50958 |
| A-Set.28 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 40578 |
| A-Set.29 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 5 | 33663 |
| A-Set.30 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 6 | 25108 |
| A-Set.31 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 8 | 83624 |
| A-Set.32 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 7 | 25864 |
| A-Set.33 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 376209 |
| A-Set.34 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 290713 |
| A-Set.35 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 4 | 180766 |

## A-Read — 1 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-ancestor"}` | 8 | 31003 |

