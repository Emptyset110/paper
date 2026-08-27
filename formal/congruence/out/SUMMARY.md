# κ_r-congruence — portfolio union

| run | bound | states | windows | κ-classes | wall |
|---|---|---:|---:|---:|---:|
| A1 | 1 fibers, shapes=ALL | 588 | 4498 | 66 | 0.2s |
| A2c | 2 fibers, shapes=ALL, no update, no setval | 30765 | 508261 | 100 | 8.2s |
| A2w | 2 fibers, shapes=ALL | 300001 (trunc.) | 3523526 | 114 | 86.2s |
| A3c | 3 fibers, shapes=ALL, no update, no setval | 300000 (trunc.) | 3713532 | 82 | 72.7s |
| dep3 | 3 fibers, shapes=P,M,CC,CRR | 400003 (trunc.) | 8075008 | 83 | 209.3s |
| fail3 | 3 fibers, shapes=P,FP,C | 400000 (trunc.) | 6862427 | 63 | 185.6s |
| regA | 3 fibers, shapes=P,A | 300000 (trunc.) | 4440552 | 69 | 212.7s |
| regB | 3 fibers, shapes=P,A, no update, no setval, no child-insert | 19707 | 550362 | 62 | 26.7s |
| sat3 | 3 fibers, shapes=P,C | 235316 | 4914822 | 61 | 132.6s |

## Per rule, over the union

| rule | reachable windows | κ-classes | non-singleton result classes | classes split by frame only (L2) |
|---|---:|---:|---:|---:|
| O-Insert | 331436 | 8 | **0** | 0 |
| O-Retire | 4612590 | 4 | **0** | 0 |
| O-Remove | 4600267 | 12 | **0** | 0 |
| O-Update | 4612590 | 6 | **0** | 0 |
| L-Begin | 1163730 | 14 | **0** | 0 |
| L-Iter | 222869 | 11 | **1** | 2 |
| L-Raise | 123104 | 5 | **0** | 0 |
| L-Finish | 232218 | 4 | **0** | 2 |
| L-Divert | 897029 | 18 | **0** | 7 |
| L-Leave | 720970 | 4 | **0** | 0 |
| L-Unload | 1238415 | 23 | **0** | 2 |
| CO-Prov | 4612590 | 3 | **0** | 0 |
| CO-Acc | 9225180 | 6 | **0** | 0 |
| **total** | **32592988** | **118** | **1** | 13 |

Excluded harness faults (explorer state-encoding artifact, see REPORT.md §2.4): 1932

## Non-singleton classes (counterexamples to κ-congruence)

### L-Iter — κ = {T1,T2,T4} — 2 distinct results over 13102 windows

- run `A2c`, window {"rule":"L-Iterate","kind":"life","fIdx":0}
  - result: `{"d":"fire","r":null,"n":"L-Iter","e":["apply@self"],"u":["self.acc:push(track)"]}`
  - access: `[{"t":"insert","shape":"P","ctx":"root"},{"t":"life","f":0,"rule":"L-Begin"},{"t":"life","f":0,"rule":"L-Iter"},{"t":"life","f":0,"rule":"L-Finish"},{"t":"insert","shape":"C","ctx":"root"},{"t":"life","f":0,"rule":"L-Begin"}]`
- run `A2c`, window {"rule":"L-Iterate","kind":"life","fIdx":0}
  - result: `{"d":"fire","r":null,"n":"L-Iter","e":["apply@self"],"u":["self.acc:push(rrev)"]}`
  - access: `[{"t":"insert","shape":"P","ctx":"root"},{"t":"life","f":0,"rule":"L-Begin"},{"t":"life","f":0,"rule":"L-Iter"},{"t":"life","f":0,"rule":"L-Finish"},{"t":"insert","shape":"CRR","ctx":"root"},{"t":"life","f":0,"rule":"L-Begin"}]`

