# 32-test coverage against the reachable signature set

Reachable signatures (union over runs out/signatures-A2c.json, out/signatures-dep3.json, out/signatures-fail3.json, out/signatures-regA.json, out/signatures-regB.json, out/signatures-A1.json): 146

Exercised by at least one of the 32 tests: 53

**UNCOVERED reachable signatures: 93**

- **O-Insert** (3):
  - `O-Insert fired {declaredConflict:false,parent:"live",realm:"isolated"}`
  - `O-Insert fired {declaredConflict:false,parent:"retired",realm:"isolated"}`
  - `O-Insert fired {declaredConflict:false,parent:"retired",realm:"root"}`
- **O-Retire** (8):
  - `O-Retire fired {again:false,stateClass:"failed"}`
  - `O-Retire fired {again:false,stateClass:"loading"}`
  - `O-Retire fired {again:false,stateClass:"unloading"}`
  - `O-Retire fired {again:true,stateClass:"active"}`
  - `O-Retire fired {again:true,stateClass:"disposed"}`
  - `O-Retire fired {again:true,stateClass:"loading"}`
  - `O-Retire fired {again:true,stateClass:"pending"}`
  - `O-Retire fired {again:true,stateClass:"unloading"}`
- **O-Remove** (7):
  - `O-Remove disabled {hasChild:false,stateClass:"active"}`
  - `O-Remove disabled {hasChild:false,stateClass:"reloading"}`
  - `O-Remove disabled {hasChild:false,stateClass:"unloading"}`
  - `O-Remove disabled {hasChild:true,stateClass:"active"}`
  - `O-Remove disabled {hasChild:true,stateClass:"reloading"}`
  - `O-Remove disabled {hasChild:true,stateClass:"unloading"}`
  - `O-Remove fired {outcome:"xi",stateClass:"inactive"}`
- **O-Update** (4):
  - `O-Update fired {installed:false,outcome:"bot",stateClass:"pending"}`
  - `O-Update fired {installed:true,outcome:"bot",stateClass:"loading"}`
  - `O-Update fired {installed:true,outcome:"bot",stateClass:"unloading"}`
  - `O-Update fired {installed:true,outcome:"xi",stateClass:"unloading"}`
- **L-Begin** (1):
  - `L-Begin disabled {outcome:"xi",retired:true}`
- **L-Iter** (3):
  - `L-Iter fired {stepClass:"read-undeclared-np"}`
  - `L-Iter fired {stepClass:"setval-own-eq"}`
  - `L-Iter fired {stepClass:"setval-own-neq"}`
- **L-Raise** (3):
  - `L-Raise fired {acc:["provide"],stepClass:"raise"}`
  - `L-Raise fired {acc:[],stepClass:"flag-fail"}`
  - `L-Raise fired {acc:[],stepClass:"setval-foreign"}`
- **L-Divert** (11):
  - `L-Divert fired {acc:["provide","track"],trigger:"stale"}`
  - `L-Divert fired {acc:["provide","track"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["provide"],trigger:"stale"}`
  - `L-Divert fired {acc:["provide"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["retire"],trigger:"stale"}`
  - `L-Divert fired {acc:["retire"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["rrev"],trigger:"stale"}`
  - `L-Divert fired {acc:["rrev"],trigger:"target-bot"}`
  - `L-Divert fired {acc:["track"],trigger:"stale"}`
  - `L-Divert fired {acc:[],trigger:"stale"}`
  - `L-Divert fired {acc:[],trigger:"target-bot"}`
- **L-Unload** (19):
  - `L-Unload disabled {acc:["provide","track"],outcome:"bot",relied:true,retired:false}`
  - `L-Unload disabled {acc:["provide"],outcome:"bot",relied:true,retired:false}`
  - `L-Unload fired {acc:["provide","track"],obs:["track"],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["provide"],obs:[],outcome:"bot",postTarget:"bot",relied:false,retired:false}`
  - `L-Unload fired {acc:["provide"],obs:[],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["provide"],obs:[],outcome:"xi",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:["provide"],obs:[],outcome:"xi",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["retire"],obs:[],outcome:"bot",postTarget:"bot",relied:false,retired:false}`
  - `L-Unload fired {acc:["retire"],obs:[],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:["retire"],obs:[],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["rrev"],obs:["rrev"],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:["rrev"],obs:["rrev"],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["track"],obs:["track","track"],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["track"],obs:["track"],outcome:"xi",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:[],obs:[],outcome:"bot",postTarget:"bot",relied:false,retired:false}`
  - `L-Unload fired {acc:[],obs:[],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:[],obs:[],outcome:"bot",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:[],obs:[],outcome:"xi",postTarget:"bot",relied:false,retired:false}`
  - `L-Unload fired {acc:[],obs:[],outcome:"xi",postTarget:"bot",relied:false,retired:true}`
- **A-Set** (33):
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active","loading"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active","unloading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active","unloading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active","unloading"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active","unloading"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["active"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["active"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["loading","unloading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["loading","unloading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["loading","unloading"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["loading","unloading"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["loading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["loading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["loading"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["loading"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["unloading"],stateClass:"active",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["unloading"],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:["unloading"],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:["unloading"],stateClass:"unloading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:[],stateClass:"active",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:[],stateClass:"loading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:[],stateClass:"loading",valueEq:true}`
  - `A-Set fired {binding:"own",dependents:[],stateClass:"unloading",valueEq:false}`
  - `A-Set fired {binding:"own",dependents:[],stateClass:"unloading",valueEq:true}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"active"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"failed"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"loading"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"pending"}`
  - `A-Set refused {binding:"foreign",dependents:[],stateClass:"unloading"}`
- **A-Read** (1):
  - `A-Read fired {cls:"undeclared-np"}`

Signatures exercised by tests but OUTSIDE the explorer's reachable set (beyond the explored bound/generator): 11

- **O-Insert** (1):
  - `O-Insert refused {declaredConflict:false,parent:"removed",realm:"root"}`
- **L-Raise** (2):
  - `L-Raise fired {acc:["provide","track"],stepClass:"raise"}`
  - `L-Raise fired {acc:["track"],stepClass:"flag-fail"}`
- **L-Finish** (2):
  - `L-Finish fired {acc:["provide","rrev"]}`
  - `L-Finish fired {acc:["retire","track"]}`
- **L-Unload** (4):
  - `L-Unload fired {acc:["provide","rrev"],obs:["rrev"],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:["provide","track"],obs:["track","track"],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
  - `L-Unload fired {acc:["provide","track"],obs:["track"],outcome:"xi",postTarget:"sat",relied:false,retired:false}`
  - `L-Unload fired {acc:["retire","track"],obs:["track"],outcome:"bot",postTarget:"bot",relied:false,retired:true}`
- **A-Read** (1):
  - `A-Read fired {cls:"inactive-declared-p"}`
- **A-Intercept** (1):
  - `A-Intercept fired {entries:2}`

## Per-test coverage matrix

| test | reachable sigs exercised | outside-set sigs |
|---|---|---|
| R1.1 insert-activates-fresh | 6 | 0 |
| R1.2 insert-under-removed-parent-rejected | 10 | 1 |
| R1.3 dynamic-provision-conflict-fails-offender | 8 | 0 |
| R1.4 declared-provision-disjointness-at-insert | 6 | 0 |
| R2.1 retire-runs-recovery | 10 | 1 |
| R2.2 retire-pending-clean | 5 | 0 |
| R3.1 removal-follows-inactivity | 18 | 0 |
| R3.2 registration-cascade-recovers-children | 13 | 2 |
| R4.1 begin-requires-satisfaction | 2 | 0 |
| R4.2 provider-arrival-wakes-pending | 9 | 0 |
| R4.3 satisfaction-counts-active-only | 8 | 0 |
| R4.4 failure-latch-unchanged-env | 6 | 0 |
| R5.1 iteration-order-and-lifo-recovery | 10 | 0 |
| R6.1 divert-honors-target-change | 16 | 0 |
| R7.1 raise-recovers-then-latches | 5 | 2 |
| RU.1 update-restarts-with-new-config | 12 | 1 |
| R8.1 leaving-provider-reads-own-deps | 12 | 2 |
| R9.1 withdrawal-guard-orders-teardown | 18 | 0 |
| R9.2 recovery-exactness-on-deactivation | 16 | 0 |
| C1.1 provision-value-operations | 6 | 0 |
| C2.1 overwrite-observability-dichotomy | 9 | 0 |
| C3.1 isolation-independence | 10 | 0 |
| C3.2 isolation-label-join | 8 | 0 |
| C4.1 intercept-nearest-wins | 5 | 1 |
| C5.1 undeclared-access-rejected | 8 | 0 |
| C5.2 ancestry-authorized-access | 12 | 0 |
| C5.3 declared-inactive-access | 6 | 1 |
| M1 interleaved-recovery-independence | 11 | 0 |
| M2 dependency-ordering-chain | 16 | 0 |
| M3 provider-identity-coherence | 18 | 0 |
| M4 quiescence-on-unsatisfiable | 2 | 0 |
| M5 confluence-across-histories | 16 | 0 |
