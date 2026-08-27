# Reachable occurrence signatures (bound tag: A2w)

States (normalized): 2500001 — expanded: 1806058, edges: 20063988 (refusal edges: 5348285), quiescent: 2941, internal cycle: false, truncated: true, wall-clock: 1982.3s

## O-Insert — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"live","declaredConflict":false,"realm":"isolated"}` | 1 | 31 |
| O-Insert.2 | fired | `{"parent":"live","declaredConflict":false,"realm":"root"}` | 1 | 19096 |
| O-Insert.3 | fired | `{"parent":"retired","declaredConflict":false,"realm":"isolated"}` | 2 | 34 |
| O-Insert.4 | fired | `{"parent":"retired","declaredConflict":false,"realm":"root"}` | 2 | 368 |
| O-Insert.5 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 1534 |
| O-Insert.6 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 12982 |
| O-Insert.7 | refused | `{"parent":"root","declaredConflict":true,"realm":"root"}` | 1 | 59 |

## O-Retire — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 489709 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 4 | 23977 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 1197417 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 618236 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 3 | 487961 |
| O-Retire.6 | fired | `{"stateClass":"active","again":true}` | 9 | 13584 |
| O-Retire.7 | fired | `{"stateClass":"disposed","again":true}` | 7 | 22929 |
| O-Retire.8 | fired | `{"stateClass":"loading","again":true}` | 7 | 46036 |
| O-Retire.9 | fired | `{"stateClass":"pending","again":true}` | 6 | 34985 |
| O-Retire.10 | fired | `{"stateClass":"unloading","again":true}` | 8 | 30612 |

## O-Remove — 9 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 257405 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 960176 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 650524 |
| O-Remove.4 | disabled | `{"stateClass":"active","hasChild":true}` | 5 | 166552 |
| O-Remove.5 | disabled | `{"stateClass":"inactive","hasChild":true}` | 3 | 58847 |
| O-Remove.6 | disabled | `{"stateClass":"reloading","hasChild":true}` | 4 | 272008 |
| O-Remove.7 | disabled | `{"stateClass":"unloading","hasChild":true}` | 5 | 187200 |
| O-Remove.8 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 749434 |
| O-Remove.9 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 5 | 19114 |

## O-Update — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Update.1 | fired | `{"installed":false,"outcome":"bot","stateClass":"pending"}` | 1 | 1374958 |
| O-Update.2 | fired | `{"installed":false,"outcome":"xi","stateClass":"failed"}` | 4 | 43678 |
| O-Update.3 | fired | `{"installed":true,"outcome":"bot","stateClass":"active"}` | 4 | 895186 |
| O-Update.4 | fired | `{"installed":true,"outcome":"bot","stateClass":"loading"}` | 2 | 2359100 |
| O-Update.5 | fired | `{"installed":true,"outcome":"bot","stateClass":"unloading"}` | 4 | 1241176 |
| O-Update.6 | fired | `{"installed":true,"outcome":"xi","stateClass":"unloading"}` | 3 | 62913 |

## L-Begin — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["provided","unprovided"]}` | 5 | 108 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 100720 |
| L-Begin.3 | disabled | `{"outcome":"bot","retired":true}` | 2 | 807694 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":false}` | 4 | 23977 |
| L-Begin.5 | disabled | `{"outcome":"xi","retired":true}` | 5 | 19701 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 2866 |
| L-Begin.7 | fired | `{"outcome":"bot","inject":[]}` | 1 | 463570 |

## L-Iter — 11 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"flag-pass"}` | 3 | 3813 |
| L-Iter.2 | fired | `{"stepClass":"provide-fresh"}` | 2 | 68847 |
| L-Iter.3 | fired | `{"stepClass":"read-committed-ancestor"}` | 8 | 8488 |
| L-Iter.4 | fired | `{"stepClass":"read-committed-self"}` | 6 | 132 |
| L-Iter.5 | fired | `{"stepClass":"read-undeclared-np"}` | 2 | 12573 |
| L-Iter.6 | fired | `{"stepClass":"read-undeclared-p"}` | 6 | 108 |
| L-Iter.7 | fired | `{"stepClass":"register"}` | 2 | 18763 |
| L-Iter.8 | fired | `{"stepClass":"setval-own-eq"}` | 3 | 10413 |
| L-Iter.9 | fired | `{"stepClass":"setval-own-neq"}` | 3 | 10413 |
| L-Iter.10 | fired | `{"stepClass":"track"}` | 2 | 182415 |
| L-Iter.11 | fired | `{"stepClass":"track-rrev"}` | 6 | 108 |

## L-Raise — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"raise","acc":["provide"]}` | 3 | 12493 |
| L-Raise.2 | fired | `{"stepClass":"raise","acc":["track"]}` | 3 | 9187 |
| L-Raise.3 | fired | `{"stepClass":"flag-fail","acc":[]}` | 2 | 5375 |
| L-Raise.4 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 2808 |
| L-Raise.5 | fired | `{"stepClass":"setval-foreign","acc":[]}` | 2 | 9188 |

## L-Finish — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide","track"]}` | 4 | 10474 |
| L-Finish.2 | fired | `{"acc":["provide"]}` | 3 | 48302 |
| L-Finish.3 | fired | `{"acc":["retire"]}` | 3 | 226903 |
| L-Finish.4 | fired | `{"acc":["rrev"]}` | 7 | 108 |
| L-Finish.5 | fired | `{"acc":["track"]}` | 3 | 98920 |
| L-Finish.6 | fired | `{"acc":[]}` | 3 | 17529 |

## L-Divert — 12 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"stale","acc":["provide","track"]}` | 5 | 7740 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide","track"]}` | 5 | 7829 |
| L-Divert.3 | fired | `{"trigger":"stale","acc":["provide"]}` | 4 | 71708 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 70703 |
| L-Divert.5 | fired | `{"trigger":"stale","acc":["retire"]}` | 4 | 224572 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":["retire"]}` | 4 | 168873 |
| L-Divert.7 | fired | `{"trigger":"stale","acc":["rrev"]}` | 8 | 198 |
| L-Divert.8 | fired | `{"trigger":"target-bot","acc":["rrev"]}` | 8 | 288 |
| L-Divert.9 | fired | `{"trigger":"stale","acc":["track"]}` | 4 | 119147 |
| L-Divert.10 | fired | `{"trigger":"target-bot","acc":["track"]}` | 4 | 192089 |
| L-Divert.11 | fired | `{"trigger":"stale","acc":[]}` | 3 | 308286 |
| L-Divert.12 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 430307 |

## L-Leave — 3 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 313836 |
| L-Leave.2 | fired | `{"trigger":"stale"}` | 5 | 283436 |
| L-Leave.3 | fired | `{"trigger":"target-bot"}` | 5 | 297914 |

## L-Unload — 30 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide","track"]}` | 9 | 3252 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide","track"]}` | 9 | 4715 |
| L-Unload.3 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide"]}` | 8 | 13397 |
| L-Unload.4 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 19285 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 11 | 135 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 6 | 9386 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"sat"}` | 6 | 6374 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 10 | 135 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 70313 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 5 | 49650 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 6967 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 4 | 9314 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 10 | 5131 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 5 | 166954 |
| L-Unload.15 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"sat"}` | 5 | 137610 |
| L-Unload.16 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 10 | 135 |
| L-Unload.17 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 9 | 297 |
| L-Unload.18 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"sat"}` | 9 | 108 |
| L-Unload.19 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track","track"],"postTarget":"bot"}` | 6 | 4587 |
| L-Unload.20 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track","track"],"postTarget":"sat"}` | 6 | 3135 |
| L-Unload.21 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 135 |
| L-Unload.22 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 158861 |
| L-Unload.23 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 5 | 53138 |
| L-Unload.24 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 4741 |
| L-Unload.25 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 4 | 6521 |
| L-Unload.26 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 1331 |
| L-Unload.27 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 369124 |
| L-Unload.28 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 4 | 151920 |
| L-Unload.29 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 16123 |
| L-Unload.30 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 3 | 19247 |

## A-Set — 23 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Set.1 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["active"]}` | 8 | 10062 |
| A-Set.2 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["active"]}` | 9 | 9201 |
| A-Set.3 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["active"]}` | 10 | 5240 |
| A-Set.4 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["active"]}` | 11 | 5473 |
| A-Set.5 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["loading"]}` | 6 | 17508 |
| A-Set.6 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["loading"]}` | 7 | 15671 |
| A-Set.7 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["loading"]}` | 8 | 8580 |
| A-Set.8 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["loading"]}` | 9 | 8349 |
| A-Set.9 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":["unloading"]}` | 8 | 8880 |
| A-Set.10 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":["unloading"]}` | 9 | 8408 |
| A-Set.11 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":["unloading"]}` | 9 | 6398 |
| A-Set.12 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":["unloading"]}` | 10 | 6609 |
| A-Set.13 | fired | `{"binding":"own","valueEq":false,"stateClass":"active","dependents":[]}` | 4 | 59189 |
| A-Set.14 | fired | `{"binding":"own","valueEq":true,"stateClass":"active","dependents":[]}` | 5 | 56266 |
| A-Set.15 | fired | `{"binding":"own","valueEq":false,"stateClass":"loading","dependents":[]}` | 3 | 146027 |
| A-Set.16 | fired | `{"binding":"own","valueEq":true,"stateClass":"loading","dependents":[]}` | 4 | 117798 |
| A-Set.17 | fired | `{"binding":"own","valueEq":false,"stateClass":"unloading","dependents":[]}` | 4 | 83919 |
| A-Set.18 | fired | `{"binding":"own","valueEq":true,"stateClass":"unloading","dependents":[]}` | 5 | 67275 |
| A-Set.19 | refused | `{"binding":"foreign","stateClass":"active","dependents":[]}` | 4 | 710001 |
| A-Set.20 | refused | `{"binding":"foreign","stateClass":"failed","dependents":[]}` | 4 | 43678 |
| A-Set.21 | refused | `{"binding":"foreign","stateClass":"loading","dependents":[]}` | 2 | 2095275 |
| A-Set.22 | refused | `{"binding":"foreign","stateClass":"pending","dependents":[]}` | 1 | 1374958 |
| A-Set.23 | refused | `{"binding":"foreign","stateClass":"unloading","dependents":[]}` | 3 | 1112246 |

## A-Read — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-ancestor"}` | 8 | 8488 |
| A-Read.2 | fired | `{"cls":"committed-self"}` | 6 | 672 |
| A-Read.3 | fired | `{"cls":"undeclared-np"}` | 2 | 12573 |
| A-Read.4 | fired | `{"cls":"undeclared-p"}` | 6 | 108 |

