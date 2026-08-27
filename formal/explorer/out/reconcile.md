# D3 ↔ D1 signature-vocabulary reconciliation

Explorer reachable signatures (tuple encoding): **146**

After applying α (project each tuple onto signatures.md's letter alphabet, dropping every dimension D1 gives no letter to): **74** distinct occurrence classes.

Collapse factor: 1.97×

Uncovered by the 32 tests, tuple encoding: **93**; after α: **29**

## Collapse per rule (how much the explorer refines D1)

| rule | explorer sigs | after α | fold factor | D1 \|Σ_r\| | D1 reachable |
|---|---|---|---|---|---|
| O-Insert | 7 | 5 | 1.4× | 7 | 6 |
| O-Retire | 10 | 4 | 2.5× | 4 | 4 |
| O-Remove | 9 | 5 | 1.8× | 7 | 7 |
| O-Update | 6 | 1 | 6.0× | — | — |
| L-Begin | 7 | 7 | 1.0× | 7 | 7 |
| L-Iter | 11 | 8 | 1.4× | 11 | 11 |
| L-Raise | 5 | 5 | 1.0× | 9 | 9 |
| L-Finish | 6 | 2 | 3.0× | 3 | 3 |
| L-Divert | 12 | 2 | 6.0× | 6 | 4 |
| L-Leave | 3 | 3 | 1.0× | 5 | 4 |
| L-Unload | 31 | 27 | 1.1× | 12 | 12 |
| A-Set | 35 | 2 | 17.5× | 6 | 6 |
| A-Read | 4 | 3 | 1.3× | 7 | 5 |
| **total** | **146** | **74** | **1.97×** | **92** | **86** |

## Largest α-fibres (one D1 class, many explorer signatures)

- **A-Set fired {P3}** — 30 explorer signatures
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"unloading",valueEq:false}`
  - … 27 more
- **O-Retire fired {R2}** — 6 explorer signatures
  - `O-Retire fired {again:false,stateClass:"active"}`
  - `O-Retire fired {again:false,stateClass:"loading"}`
  - `O-Retire fired {again:false,stateClass:"unloading"}`
  - … 3 more
- **L-Divert fired {D1,D3|D4,D5}** — 6 explorer signatures
  - `L-Divert fired {acc:["provide","track"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["provide"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["retire"],trigger:"target-bot"}`
  - … 3 more
- **O-Update fired {V5}** — 6 explorer signatures
  - `O-Update fired {installed:false,outcome:"bot",stateClass:"pending"}`
  - `O-Update fired {installed:false,outcome:"xi",stateClass:"failed"}`
  - `O-Update fired {installed:true,outcome:"bot",stateClass:"active"}`
  - … 3 more
- **L-Divert fired {D1,D5,V5@divert*}** — 6 explorer signatures
  - `L-Divert fired {acc:["provide","track"],trigger:"stale"}`
  - `L-Divert fired {acc:["provide"],trigger:"stale"}`
  - `L-Divert fired {acc:["rrev"],trigger:"stale"}`
  - … 3 more
- **L-Finish fired {F1,F3}** — 5 explorer signatures
  - `L-Finish fired {acc:["provide","track"]}`
  - `L-Finish fired {acc:["provide"]}`
  - `L-Finish fired {acc:["retire"]}`
  - … 2 more
- **A-Set refused {P4}** — 5 explorer signatures
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"active"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"failed"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"loading"}`
  - … 2 more
- **O-Remove disabled {M5,M6}** — 3 explorer signatures
  - `O-Remove disabled {hasChild:false,stateClass:"active"}`
  - `O-Remove disabled {hasChild:false,stateClass:"reloading"}`
  - `O-Remove disabled {hasChild:false,stateClass:"unloading"}`
- **O-Remove disabled {M5,M7}** — 3 explorer signatures
  - `O-Remove disabled {hasChild:true,stateClass:"active"}`
  - `O-Remove disabled {hasChild:true,stateClass:"reloading"}`
  - `O-Remove disabled {hasChild:true,stateClass:"unloading"}`
- **O-Insert fired {I2,I4,I6,S2|S3}** — 2 explorer signatures
  - `O-Insert fired {declaredConflict:false,parent:"live",realm:"isolated"}`
  - `O-Insert fired {declaredConflict:false,parent:"retired",realm:"isolated"}`
- **O-Insert fired {I2,I4,I6,S1}** — 2 explorer signatures
  - `O-Insert fired {declaredConflict:false,parent:"live",realm:"root"}`
  - `O-Insert fired {declaredConflict:false,parent:"retired",realm:"root"}`
- **O-Retire fired {R1}** — 2 explorer signatures
  - `O-Retire fired {again:false,stateClass:"pending"}`
  - `O-Retire fired {again:true,stateClass:"pending"}`

## D1 letters witnessed only as a CONFLATED class

8: D3, D4, V3, V4, S2, S3, A5, A6 — the explorer reaches the occurrence but its encoding cannot separate the D1 letters listed together (see α above: `D3|D4`, `V3|V4`, `A5|A6`, `S2|S3`, `A3|A4`).


## D1 letters with NO explorer witness

17 of 92: I3, I5, M2, B6, T7, D2, D6, X9, V2, S4, N1, N2, N3, N4, A3, A4, A7

Of these, the ones D1 itself declares interface-unrealizable are CONFIRMED negatives; the rest are explorer bound/generator gaps; three are realized by the coda tests appended to T_B outside the graph.

| letter | D1 status | in graph | in T_B coda | verdict |
|---|---|---|---|---|
| I3 | reachable | absent | TB.88 | covered outside the graph |
| I5 | **unrealizable** | absent | — | CONFIRMED absent |
| M2 | reachable | absent | — | GAP — not reached at the explored bound |
| B6 | reachable | absent | — | GAP — not reached at the explored bound |
| T7 | reachable | absent | — | GAP — not reached at the explored bound |
| D2 | **unrealizable** | absent | — | CONFIRMED absent |
| D6 | **unrealizable** | absent | — | CONFIRMED absent |
| X9 | reachable | absent | — | GAP — not reached at the explored bound |
| V2 | **unrealizable** | absent | — | CONFIRMED absent |
| S4 | reachable | absent | — | GAP — not reached at the explored bound |
| N1 | reachable | absent | — | GAP — not reached at the explored bound |
| N2 | reachable | absent | — | GAP — not reached at the explored bound |
| N3 | reachable | absent | — | GAP — not reached at the explored bound |
| N4 | reachable | absent | TB.89 | covered outside the graph |
| A3 | reachable | absent | — | GAP — not reached at the explored bound |
| A4 | **unrealizable** | absent | TB.90 / TB.91 | **realized by a coda test — CONTRADICTS the blanket D1 claim** |
| A7 | **unrealizable** | absent | — | CONFIRMED absent |

Coda detail:

- **I3**: TB.88 — O-Insert under a REMOVED parent (normalization erases the parent, so no graph state can offer it)
- **N4**: TB.89 — depth-2 nested intercept chain, nearest-wins (Def. 31 is a derived op no LTS transition invokes)
- **A4**: TB.90 / TB.91 — EXTERNAL Def.-23 read on a declared-but-uncommitted fiber (walk decides at self ⇒ PosClass = self)

## The closing ledger: how 86 and 146 relate

They count different things. D1 counts **alphabet letters** (`|Σ_r^reach|`); D3 counts **occurrence tuples** (realizable field records). Neither is wrong; the bridge is α.

| quantity | value |
|---|---|
| D1 letters, all rules (`|Σ_r|` summed) | 92 |
| − interface-unrealizable (I5, D2, D6, V2, A4, A7) | 6 |
| **= D1 reachable letters** | **86** |
| of those, witnessed in the explorer graph | 75 (67 separately + 8 only as a conflated pair) |
| of those, NOT witnessed in the graph | 11 |
|  · covered by a T_B coda test | 2 (I3, N4) |
|  · absence PREDICTED by D1 itself | 2 (B6, T7) |
|  · genuine generator gaps | 7 (M2, X9, S4, N1, N2, N3, A3) |
| explorer occurrence TUPLES over the same letters | 146 |
| distinct letter-SETS those tuples realize (α image) | 74 |

So: **75 of D1's 86 reachable letters are confirmed by exhaustive search**, 2 more by coda tests, 2 are absences D1 predicts, and **7 remain unreconciled** (generator gaps, listed above). The 146 is not a competing estimate of 86: it is the count of distinct field-records those letters combine into at the explored bound.

Genuine gaps in detail:

- **M2** — O-Remove RetClass τ=⊥ as a *blocking* letter: the explorer only offers `remove` where `removeEligible` holds, so the τ=⊥ refusal is never an offered action.
- **X9** — register⁻¹ present in a raise accumulator: needs a registrar shape that raises AFTER registering; no catalog shape does both.
- **S4** — isolate over an already-isolated key: the generator offers exactly one isolate context (k1↦r1) and never nests a second.
- **N1** — intercept MetaPat ε — A-Intercept has no LTS occurrence at all (interceptMerged is a derived op; log S7).
- **N2** — intercept MetaPat context-only — same reason as N1.
- **N3** — intercept MetaPat component⊕context — same reason as N1.
- **A3** — Algorithm-6 IA at an ANCESTOR: needs an orchestrator-inserted child that READS under a pending declaring parent; the child-insert probe uses shape T, which has no read step.

Expected-absence detail:

- **B6**: installed-only-provided: D1 §4.1 and report S8 both say no baseline σ realizes it (it is the `satisfied-by-installed-provider` MUTANT behaviour). Absence is the predicted result.
- **T7**: read-declared-uncommitted as an in-lifecycle STEP: this is A4's argument at step level — a fiber never executes a step while its own declared key is uncommitted. Absence is the predicted result.

## The six unrealizability claims

| id | D1 claim | separately witnessed | conflated witness | verdict |
|---|---|---|---|---|
| I5 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
| D2 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
| D6 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
| V2 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
| A4 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
| A7 | interface-unrealizable | no | no | absent — CONFIRMS D1 |
