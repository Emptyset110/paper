# Reachable occurrence signatures (bound tag: A3c)

States (normalized): 2337816 — expanded: 2034542, edges: 9334269 (refusal edges: 15804), quiescent: 3968, internal cycle: false, truncated: true, wall-clock: 2101.1s

## O-Insert — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"live","declaredConflict":false,"realm":"isolated"}` | 1 | 1289 |
| O-Insert.2 | fired | `{"parent":"live","declaredConflict":false,"realm":"root"}` | 1 | 47157 |
| O-Insert.3 | fired | `{"parent":"retired","declaredConflict":false,"realm":"isolated"}` | 2 | 1595 |
| O-Insert.4 | fired | `{"parent":"retired","declaredConflict":false,"realm":"root"}` | 2 | 20723 |
| O-Insert.5 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 39558 |
| O-Insert.6 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 334268 |
| O-Insert.7 | refused | `{"parent":"root","declaredConflict":true,"realm":"root"}` | 1 | 2371 |

## O-Retire — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 576862 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 4 | 147372 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 1387656 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 888475 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 3 | 189046 |
| O-Retire.6 | fired | `{"stateClass":"active","again":true}` | 9 | 4830 |
| O-Retire.7 | fired | `{"stateClass":"disposed","again":true}` | 7 | 12541 |
| O-Retire.8 | fired | `{"stateClass":"loading","again":true}` | 7 | 20928 |
| O-Retire.9 | fired | `{"stateClass":"pending","again":true}` | 6 | 17474 |
| O-Retire.10 | fired | `{"stateClass":"unloading","again":true}` | 8 | 13080 |

## O-Remove — 9 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 305061 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 956666 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 941170 |
| O-Remove.4 | disabled | `{"stateClass":"active","hasChild":true}` | 5 | 137311 |
| O-Remove.5 | disabled | `{"stateClass":"inactive","hasChild":true}` | 3 | 116006 |
| O-Remove.6 | disabled | `{"stateClass":"reloading","hasChild":true}` | 4 | 227061 |
| O-Remove.7 | disabled | `{"stateClass":"unloading","hasChild":true}` | 5 | 187672 |
| O-Remove.8 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 768009 |
| O-Remove.9 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 5 | 108486 |

## L-Begin — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["provided","unprovided"]}` | 5 | 3134 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 208441 |
| L-Begin.3 | disabled | `{"outcome":"bot","retired":true}` | 2 | 874671 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":false}` | 4 | 147372 |
| L-Begin.5 | disabled | `{"outcome":"xi","retired":true}` | 5 | 117830 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 16221 |
| L-Begin.7 | fired | `{"outcome":"bot","inject":[]}` | 1 | 638127 |

## L-Iter — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 155891 |
| L-Iter.2 | fired | `{"stepClass":"read-committed-ancestor"}` | 8 | 10103 |
| L-Iter.3 | fired | `{"stepClass":"read-committed-self"}` | 6 | 3376 |
| L-Iter.4 | fired | `{"stepClass":"read-undeclared-np"}` | 2 | 27654 |
| L-Iter.5 | fired | `{"stepClass":"read-undeclared-p"}` | 6 | 2917 |
| L-Iter.6 | fired | `{"stepClass":"register"}` | 2 | 31405 |
| L-Iter.7 | fired | `{"stepClass":"setval-own-eq"}` | 3 | 23220 |
| L-Iter.8 | fired | `{"stepClass":"setval-own-neq"}` | 3 | 23220 |
| L-Iter.9 | fired | `{"stepClass":"track"}` | 2 | 296514 |
| L-Iter.10 | fired | `{"stepClass":"track-rrev"}` | 6 | 2917 |

## L-Raise — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"raise","acc":["provide"]}` | 3 | 23220 |
| L-Raise.2 | fired | `{"stepClass":"raise","acc":["track"]}` | 3 | 27930 |
| L-Raise.3 | fired | `{"stepClass":"flag-fail","acc":[]}` | 2 | 30571 |
| L-Raise.4 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 56358 |
| L-Raise.5 | fired | `{"stepClass":"setval-foreign","acc":[]}` | 2 | 30365 |

## L-Finish — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide","track"]}` | 4 | 23258 |
| L-Finish.2 | fired | `{"acc":["provide"]}` | 3 | 112390 |
| L-Finish.3 | fired | `{"acc":["retire"]}` | 3 | 240592 |
| L-Finish.4 | fired | `{"acc":["rrev"]}` | 7 | 2597 |
| L-Finish.5 | fired | `{"acc":["track"]}` | 3 | 179365 |
| L-Finish.6 | fired | `{"acc":[]}` | 3 | 37191 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"target-bot","acc":["provide","track"]}` | 5 | 21210 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 188112 |
| L-Divert.3 | fired | `{"trigger":"target-bot","acc":["retire"]}` | 4 | 197157 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["rrev"]}` | 8 | 3940 |
| L-Divert.5 | fired | `{"trigger":"target-bot","acc":["track"]}` | 4 | 204722 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 585084 |

## L-Leave — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 563317 |
| L-Leave.2 | fired | `{"trigger":"target-bot"}` | 5 | 447612 |

## L-Unload — 23 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":false,"acc":["provide","track"]}` | 14 | 2 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide","track"]}` | 9 | 7661 |
| L-Unload.3 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 39696 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 11 | 429 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 6 | 16635 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 10 | 707 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 146085 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 18424 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 4 | 21093 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 10 | 2336 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 5 | 127478 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 10 | 711 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 9 | 2085 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track","track"],"postTarget":"bot"}` | 6 | 16036 |
| L-Unload.15 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 711 |
| L-Unload.16 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 143476 |
| L-Unload.17 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 21215 |
| L-Unload.18 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 4 | 24926 |
| L-Unload.19 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 5358 |
| L-Unload.20 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 466973 |
| L-Unload.21 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 12 | 30 |
| L-Unload.22 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 109850 |
| L-Unload.23 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 3 | 132538 |

## A-Read — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-ancestor"}` | 8 | 10103 |
| A-Read.2 | fired | `{"cls":"committed-self"}` | 6 | 6172 |
| A-Read.3 | fired | `{"cls":"undeclared-np"}` | 2 | 27654 |
| A-Read.4 | fired | `{"cls":"undeclared-p"}` | 6 | 2917 |

