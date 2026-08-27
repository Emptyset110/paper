# Reachable occurrence signatures (bound tag: A2c)

States (normalized): 30765 — expanded: 30765, edges: 92343 (refusal edges: 199), quiescent: 463, internal cycle: false, truncated: false, wall-clock: 2.1s

## O-Insert — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Insert.1 | fired | `{"parent":"live","declaredConflict":false,"realm":"isolated"}` | 1 | 7 |
| O-Insert.2 | fired | `{"parent":"live","declaredConflict":false,"realm":"root"}` | 1 | 252 |
| O-Insert.3 | fired | `{"parent":"retired","declaredConflict":false,"realm":"isolated"}` | 2 | 9 |
| O-Insert.4 | fired | `{"parent":"retired","declaredConflict":false,"realm":"root"}` | 2 | 104 |
| O-Insert.5 | fired | `{"parent":"root","declaredConflict":false,"realm":"isolated"}` | 0 | 396 |
| O-Insert.6 | fired | `{"parent":"root","declaredConflict":false,"realm":"root"}` | 0 | 3354 |
| O-Insert.7 | refused | `{"parent":"root","declaredConflict":true,"realm":"root"}` | 1 | 14 |

## O-Retire — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Retire.1 | fired | `{"stateClass":"active","again":false}` | 4 | 6213 |
| O-Retire.2 | fired | `{"stateClass":"failed","again":false}` | 4 | 2040 |
| O-Retire.3 | fired | `{"stateClass":"loading","again":false}` | 2 | 12186 |
| O-Retire.4 | fired | `{"stateClass":"pending","again":false}` | 1 | 6748 |
| O-Retire.5 | fired | `{"stateClass":"unloading","again":false}` | 3 | 2267 |
| O-Retire.6 | fired | `{"stateClass":"active","again":true}` | 9 | 185 |
| O-Retire.7 | fired | `{"stateClass":"disposed","again":true}` | 7 | 185 |
| O-Retire.8 | fired | `{"stateClass":"loading","again":true}` | 7 | 370 |
| O-Retire.9 | fired | `{"stateClass":"pending","again":true}` | 6 | 185 |
| O-Retire.10 | fired | `{"stateClass":"unloading","again":true}` | 8 | 350 |

## O-Remove — 9 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| O-Remove.1 | disabled | `{"stateClass":"active","hasChild":false}` | 5 | 4329 |
| O-Remove.2 | disabled | `{"stateClass":"reloading","hasChild":false}` | 3 | 10108 |
| O-Remove.3 | disabled | `{"stateClass":"unloading","hasChild":false}` | 4 | 12181 |
| O-Remove.4 | disabled | `{"stateClass":"active","hasChild":true}` | 5 | 1895 |
| O-Remove.5 | disabled | `{"stateClass":"inactive","hasChild":true}` | 3 | 1384 |
| O-Remove.6 | disabled | `{"stateClass":"reloading","hasChild":true}` | 4 | 2095 |
| O-Remove.7 | disabled | `{"stateClass":"unloading","hasChild":true}` | 5 | 2185 |
| O-Remove.8 | fired | `{"stateClass":"inactive","outcome":"bot"}` | 2 | 6539 |
| O-Remove.9 | fired | `{"stateClass":"inactive","outcome":"xi"}` | 5 | 1940 |

## L-Begin — 7 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Begin.1 | disabled | `{"outcome":"bot","retired":false,"inject":["provided","unprovided"]}` | 5 | 10 |
| L-Begin.2 | disabled | `{"outcome":"bot","retired":false,"inject":["unprovided"]}` | 1 | 1748 |
| L-Begin.3 | disabled | `{"outcome":"bot","retired":true}` | 2 | 7823 |
| L-Begin.4 | disabled | `{"outcome":"xi","retired":false}` | 4 | 2040 |
| L-Begin.5 | disabled | `{"outcome":"xi","retired":true}` | 5 | 2040 |
| L-Begin.6 | fired | `{"outcome":"bot","inject":["provided"]}` | 5 | 52 |
| L-Begin.7 | fired | `{"outcome":"bot","inject":[]}` | 1 | 4753 |

## L-Iter — 10 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Iter.1 | fired | `{"stepClass":"provide-fresh"}` | 2 | 1622 |
| L-Iter.2 | fired | `{"stepClass":"read-committed-ancestor"}` | 8 | 80 |
| L-Iter.3 | fired | `{"stepClass":"read-committed-self"}` | 6 | 12 |
| L-Iter.4 | fired | `{"stepClass":"read-undeclared-np"}` | 2 | 255 |
| L-Iter.5 | fired | `{"stepClass":"read-undeclared-p"}` | 6 | 10 |
| L-Iter.6 | fired | `{"stepClass":"register"}` | 2 | 175 |
| L-Iter.7 | fired | `{"stepClass":"setval-own-eq"}` | 3 | 226 |
| L-Iter.8 | fired | `{"stepClass":"setval-own-neq"}` | 3 | 226 |
| L-Iter.9 | fired | `{"stepClass":"track"}` | 2 | 2384 |
| L-Iter.10 | fired | `{"stepClass":"track-rrev"}` | 6 | 10 |

## L-Raise — 5 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Raise.1 | fired | `{"stepClass":"raise","acc":["provide"]}` | 3 | 226 |
| L-Raise.2 | fired | `{"stepClass":"raise","acc":["track"]}` | 3 | 265 |
| L-Raise.3 | fired | `{"stepClass":"flag-fail","acc":[]}` | 2 | 265 |
| L-Raise.4 | fired | `{"stepClass":"provide-conflict","acc":[]}` | 5 | 228 |
| L-Raise.5 | fired | `{"stepClass":"setval-foreign","acc":[]}` | 2 | 265 |

## L-Finish — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Finish.1 | fired | `{"acc":["provide","track"]}` | 4 | 236 |
| L-Finish.2 | fired | `{"acc":["provide"]}` | 3 | 1154 |
| L-Finish.3 | fired | `{"acc":["retire"]}` | 3 | 2085 |
| L-Finish.4 | fired | `{"acc":["rrev"]}` | 7 | 10 |
| L-Finish.5 | fired | `{"acc":["track"]}` | 3 | 1618 |
| L-Finish.6 | fired | `{"acc":[]}` | 3 | 357 |

## L-Divert — 6 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Divert.1 | fired | `{"trigger":"target-bot","acc":["provide","track"]}` | 5 | 246 |
| L-Divert.2 | fired | `{"trigger":"target-bot","acc":["provide"]}` | 4 | 2078 |
| L-Divert.3 | fired | `{"trigger":"target-bot","acc":["retire"]}` | 4 | 2200 |
| L-Divert.4 | fired | `{"trigger":"target-bot","acc":["rrev"]}` | 8 | 20 |
| L-Divert.5 | fired | `{"trigger":"target-bot","acc":["track"]}` | 4 | 2317 |
| L-Divert.6 | fired | `{"trigger":"target-bot","acc":[]}` | 3 | 5449 |

## L-Leave — 2 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Leave.1 | disabled | `{"trigger":"view-stable"}` | 4 | 5952 |
| L-Leave.2 | fired | `{"trigger":"target-bot"}` | 5 | 6300 |

## L-Unload — 21 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| L-Unload.1 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide","track"]}` | 9 | 112 |
| L-Unload.2 | disabled | `{"relied":true,"outcome":"bot","retired":true,"acc":["provide"]}` | 8 | 456 |
| L-Unload.3 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 11 | 5 |
| L-Unload.4 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide","track"],"obs":["track"],"postTarget":"bot"}` | 6 | 251 |
| L-Unload.5 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 10 | 5 |
| L-Unload.6 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 1887 |
| L-Unload.7 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["provide"],"obs":[],"postTarget":"bot"}` | 5 | 226 |
| L-Unload.8 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["provide"],"obs":[],"postTarget":"sat"}` | 4 | 226 |
| L-Unload.9 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 10 | 50 |
| L-Unload.10 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["retire"],"obs":[],"postTarget":"bot"}` | 5 | 1965 |
| L-Unload.11 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 10 | 5 |
| L-Unload.12 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["rrev"],"obs":["rrev"],"postTarget":"bot"}` | 9 | 15 |
| L-Unload.13 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track","track"],"postTarget":"bot"}` | 6 | 265 |
| L-Unload.14 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 10 | 5 |
| L-Unload.15 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 2047 |
| L-Unload.16 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":["track"],"obs":["track"],"postTarget":"bot"}` | 5 | 265 |
| L-Unload.17 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":["track"],"obs":["track"],"postTarget":"sat"}` | 4 | 265 |
| L-Unload.18 | fired | `{"relied":false,"outcome":"bot","retired":false,"acc":[],"obs":[],"postTarget":"bot"}` | 9 | 26 |
| L-Unload.19 | fired | `{"relied":false,"outcome":"bot","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 5022 |
| L-Unload.20 | fired | `{"relied":false,"outcome":"xi","retired":true,"acc":[],"obs":[],"postTarget":"bot"}` | 4 | 1675 |
| L-Unload.21 | fired | `{"relied":false,"outcome":"xi","retired":false,"acc":[],"obs":[],"postTarget":"sat"}` | 3 | 1675 |

## A-Read — 4 reachable signatures

| # | decision | fields | first depth | edge occurrences |
|---|---|---|---|---|
| A-Read.1 | fired | `{"cls":"committed-ancestor"}` | 8 | 80 |
| A-Read.2 | fired | `{"cls":"committed-self"}` | 6 | 32 |
| A-Read.3 | fired | `{"cls":"undeclared-np"}` | 2 | 255 |
| A-Read.4 | fired | `{"cls":"undeclared-p"}` | 6 | 10 |

