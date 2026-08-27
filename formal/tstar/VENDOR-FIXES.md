# T\* against the calculus-aligned build — triage, fixes, residue

Target: `deepseek-harness/vendor/cordis` (source-vendored, built to `lib/index.js`
by `tsc -b` + `tsdown --filter @deepseek-ai/cordis`).

```
59 / 75 scripts,  86 / 103 letters     →     73 / 75 scripts,  98 / 103 letters
```

The reference model stays at 75/75 and 103/103; nothing under `paper/formal/tstar`
or `paper/proof` was modified. Every change is in
`deepseek-harness/vendor/cordis/src/` and is logged as entry 22 of
`deepseek-harness/vendor/README.md`.

Reproduce:

```bash
cd paper/formal/tstar && PROOF_TARGET=cordis node run-tstar.mjs
cd paper/proof       && PROOF_TARGET=cordis node --test tests/*.test.mjs   # 108/108
cd paper/proof       && MODEL_EXHAUST=1 node --test tests/*.test.mjs       # 108/108
cd paper-review      && node counterexamples/run-all.mjs                   # unchanged
```

---

## 1. Triage

| finding | scripts | verdict | grounds |
| --- | --- | --- | --- |
| **F1** deactivation of a never-activated fiber | S-Ins-3, S-Ret-1, S-Ret-3, S-Ret-4, S-Rem-1, S-Rem-3, S-Beg-3 | **genuine defect — fixed** | §2.1 |
| **F2** parent/child teardown order inverted | S-Unl-5 | **genuine defect — fixed** | §2.4 |
| **F3** orchestrator-inserted child disposed with its parent | S-It-4 | **mapping gap — confirmed, not fixed** | §3.1 |
| **F4** A4 resolved at the label level | S-Rai-3 | **genuine defect — fixed** | §2.6 |
| **F6** D3's canonical branch not selectable | — (coverage) | **not a defect — refined** | §3.3 |
| **F8** `update` at a Reloading fiber forces no re-resolution | S-Div-4 | **genuine defect — fixed** | §2.3 |
| **F9** `update` gated on liveness, not the registry | S-Upd-3, S-Upd-5 | **genuine defect — fixed** | §2.2 |
| **F10** the registry premise unread by `setval` and the read label | S-Set-1, S-Acc-2 | **genuine defect — fixed** | §2.2 |
| **F11** W5 not presentable | S-Upd-4 | **notation limit — confirmed, not fixable** | §3.2 |
| *(new)* M7's registry witness | S-Rem-5 | **genuine defect exposed by F2's fix — fixed** | §2.5 |

No T\* failure convicted the suite. Every script that failed on this build failed
for a reason the calculus decides against the build, except S-It-4 (unreachable
through Cordis's interface) and S-Upd-4 (unreachable through the ordinary event
vocabulary) — and neither of those is a wrong script or a wrong verdict: both are
correctly derived experiments whose *presentation* the implementation cannot
support, which is what the suite already reports them as.

---

## 2. The fixes

Each cites the clause it implements, the file and line, and the observed word
before and after. `spec:` is the reference model's word for the same script.

### 2.1 F1 — a fiber that never began is removed with no event

**Clause.** L-Unload's first premise is `θ_n = Unloading⟨g; ω; ζ⟩` ([SZC26]
Table 1; the checklist at `derivations.md` E.0.3). A fiber still `Inactive(−)`
does not match it, and never enters `Unloading`: the only rules writing that
constructor are L-Leave (from `Active`) and L-Raise (from `Reloading`). Its
removal is O-Remove, whose row carries `Ψ = id_Γ` and emits nothing —
E.OT.R1(4), E.OT.R4(4), E.LB.B4(4), E.OM.M4(6), E.OI.I3(4).

This refutes the reading the suite's F1 offers as an alternative ("L-Unload read
as applicable with an empty accumulator to any Inactive fiber being removed"):
that reading contradicts L-Unload's own first premise, and the reference model —
the executable specification, 75/75 — implements the premise as written
(`model.mjs` `removePass`, which deletes the entry with no trace push).

**Change.** `fiber.ts:298` and `fiber.ts:772`.

- The child disposer's inverse used to force `_updateState(() => { … return FiberState.UNLOADING })`
  when the fiber had no in-flight transition, purely so the pre-activation
  accumulator would be drained. It now assigns `this.inertia = this._unload()`
  directly: the drain happens, the `UNLOADING` marker does not.
- `_reload()` now records whether the episode reached its first checkpoint
  (`began`). An episode invalidated before it executed a single step committed no
  `ω` and accumulated nothing, so its teardown returns the fiber to `PENDING`,
  not to `UNLOADING`.

Both paths were publishing an `internal/status` transition *out of* `UNLOADING`,
which every observer (and the suite's adapter) reads as a deactivation.

**Trace.** S-Ret-3 (`insert(root,P); settle; retire(P); settle`, `P = (∅,∅,[raise(x)])`):

```
spec:   deactivated:P
before: deactivated:P | deactivated:P      ← the raise's, then the removal's
after:  deactivated:P
```

S-Ret-4 / S-Ins-3 / S-Beg-3 (`insert(root,P); retire(P); settle; …`):

```
spec:   (empty)
before: deactivated:P
after:  (empty)
```

### 2.2 F9 + F10 — the registry premise replaces liveness

**Clause.** Table 1 attaches exactly one premise to a name-taking orchestration
input, and it is `n ∈ dom(F_γ)` — [SZC26] p. 32, "O-Retire has `n ∈ dom(F_γ)` as
its only premise", which the audit extends by parity to `update` (W6), the
`A_k` operation (P7) and Definition 2′'s read label (A8). Definition 7 gives one
`block(ϱ)` per premise *schema* and Definition 3 clause 1 compares the reasons,
so all four owe the same refusal. Retirement does not fail the premise: only
O-Remove writes `γ ∖ n`, so an `Unloading` entry is still in the registry and
the input is *enabled* there (W4). The reference model states the mapping
outright (`model.mjs` `inRegistry`, `Model.noSuchEntry`).

**Change.** New `CordisError` code `NO_SUCH_ENTRY` (`fiber.ts:173`) and
`Fiber.assertRegistered()` (`fiber.ts:405`), which fails only at
`FiberState.DISPOSED` — the state this runtime reaches exactly when the unload
has settled, i.e. where O-Remove fires. Three call sites:

- `fiber.ts:961` — `Fiber.update()` opened with `assertActive()` (`uid !== null`),
  which fails at *retirement*, not at removal. It now checks the registry, and a
  retired entry short-circuits after recording the config: `target_n(γ) = ⊥` by
  Definition 46, so no L-Begin can follow and re-deriving the epoch would
  restart a fiber the registry is about to drop.
- `reflect.ts:275` — `ReflectService.set()` reached Definition 24's own
  precondition first and reported "no own binding" for a name that has no entry
  at all.
- `reflect.ts:164` — the proxy `get` trap ran Algorithm 6 from the removed
  entry's own declaration and answered `INACTIVE_ACCESS`. Algorithm 6 is run
  *from `n`'s resolution context*, and a removed name has none.

**Traces.**

```
S-Upd-3 (W4)  spec   refusals []
              before refusals [{update, P, PARENT_ABSENT}]      ← the whole divergence
              after  refusals []

S-Upd-5 (W6)  spec   refusals [{update, P, NOT_REGISTERED}]
              before refusals [{update, P, PARENT_ABSENT}]
              after  refusals [{update, P, NOT_REGISTERED}]

S-Set-1 (P7)  spec   refusals [{setval, P, NOT_REGISTERED}]
              before refusals [{setval, P, NO_OWN_BINDING}]
              after  refusals [{setval, P, NOT_REGISTERED}]

S-Acc-2 (A8)  spec   … | active:C | deactivated:C
                     read:C:k1 = {ok:false, NOT_REGISTERED}; refusals [{readLabel, C, NOT_REGISTERED}]
              before … | active:C | deactivated:C | readfail:C:k1:INACTIVE_ACCESS
                     read:C:k1 = {ok:false, INACTIVE_ACCESS}; refusals []
              after  matches spec — a refused read emits nothing (D5 §3.6.5)
```

### 2.3 F8 — `update` at a Reloading fiber forces re-resolution

**Clause.** D7: `update(n,cfg)` delivered while `θ_n = Reloading` makes the
fiber's next iteration boundary divergent — a third L-Divert trigger beside
⊥-target and changed-provider. Definition 3 clause 1 quantifies over accepted
orchestration labels, so an input that is accepted and then dropped is the one
outcome it excludes. `model.mjs` implements it by testing the restart mark
*before* computing `targetOf`.

**Change.** `fiber.ts:215` adds a per-fiber restart mark; `fiber.ts:705` folds it
into the epoch digest `_refresh()` computes; `fiber.ts:979` bumps it in
`update()`'s non-`ACTIVE` branch. Without it the branch's
`_setEpoch(INACTIVE); _refresh()` is a no-op at a Reloading fiber: the declared
injections still resolve to the same implementations, so the re-derivation
reproduces the running epoch, `_reload()`'s checkpoint sees no change, and the
episode continues with the old config. (The aligned build wrote the new entry
and dropped it; upstream wrote it to the `ctx.plugin()` wrapper and never
reached the fiber at all.)

With the mark, the epoch differs, so `_execute()`'s iterator guard aborts at the
next boundary, `_reload()`'s tail routes into `_unload()` — which recovers the
accumulator — and `_unload()`'s tail routes back into `_reload()`, which
re-resolves the config. Three episodes, one recovery.

**Trace.** S-Div-4 (`P = (∅,∅,[mark(m0), track(a), track(b)])`, two anchored updates):

```
spec:   mark:P:m0 | deactivated:P | mark:P:m0 | apply:P:a | revert:P:a
        | deactivated:P | mark:P:m0 | apply:P:a | apply:P:b | active:P
before: mark:P:m0 | apply:P:a | apply:P:b | active:P
after:  identical to spec
```

D12's clause (first divert carries no `inv` between the two begins) and D9's
(second divert recovers `track⁻¹` and discards the held `track(b)`) both hold.

### 2.4 F2 — the registration inverse retires the child without draining it

**Clause.** E.LU.U7(10)–(13). Definition 47 makes a registration's inverse an
**O-Retire on the child**, whose entire effect is `τ_child ↦ ⊤`. L-Unload at the
owner is one transition: it applies the accumulator and then writes
`θ_owner ↦ Inactive`, emitting the owner's deactivation. The child's L-Leave
(13) and L-Unload (14) are separate, later steps. The stated verdict is
`deact(G) < inv(C,b)` — "the child is reached one level at a time (p. 32)" — and
§4.3.1 licenses it explicitly: a parent may run its inverse while a child of it
is still Unloading.

This is the one finding the suite says it cannot decide (F2's second horn: that
E.LU.U7's verdict overreaches). It does not overreach: L-Unload's row writes
`θ_n` in the same step that applies `g`, so no ordering *other* than
`deact(owner) < inv(child, …)` is derivable, and the older 32-obligation suite's
waiver (`rules-o.test.mjs` R3.2) is a waiver of an assertion, not evidence that
the calculus permits both.

**Change.** `fiber.ts:298` (the deferral), `fiber.ts:809`–`fiber.ts:833`
(`_deferDrain`, `_drainChildren`, `_drainRetired`), `fiber.ts:880`–`fiber.ts:913`
(the unload sequence).

- A child's disposer, when it runs as an item of the owner's accumulator
  (`_collecting`), hands its teardown to the owner and returns. Cordis's previous
  inverse ran the child's whole `_setEpoch(INACTIVE)` → `_unload()` →
  `await inertia` inline, which is why the subtree was fully torn down before the
  owner's state write.
- The retirement still takes effect at once: `this._runner.epoch = INACTIVE`
  records `target_n(γ) = ⊥` (Definition 46) without driving the transition, so a
  child whose episode is still running diverges at its next boundary and can no
  longer reach L-Finish, whose premise is `target_n(γ) = ω`.
- The owner starts the deferred teardowns after `_updateState()`, and keeps them
  inside its own `_unload()` promise (bridged through `this.inertia`), so
  `dispose()` still settles only once the subtree has gone.
- A fiber that will *re-begin* drains them **before** its state write instead:
  the new episode must not race children the aborted one retired.

**Trace.** S-Unl-5 (`G = (∅,∅,[register(C)])`, `C = (∅,∅,[track(b)])`;
`insert(root,G); settle; retire(G); settle`):

```
spec:   registered:G:C | active:G | apply:C:b | active:C | deactivated:G | revert:C:b | deactivated:C
before: registered:G:C | apply:C:b | active:G | active:C | revert:C:b | deactivated:C | deactivated:G
after:  registered:G:C | apply:C:b | active:G | active:C | deactivated:G | revert:C:b | deactivated:C
```

(The `active:G` / `apply:C:b` transposition is E.OM.M7(4)'s stated schedule
freedom; the script declares its word non-invariant.)

### 2.5 M7 — O-Remove's childlessness premise is a registry state

**Clause.** E.OM.M7(11)–(12): after L-Unload at `G`, `θ_G = Inactive(⊥)` and
`τ_G = ⊤`, but O-Remove is **blocked** by the witness `π_C = G`, so `G` persists
in `dom(F_γ)` until `C` is removed. The reference model reports that
configuration as `pending` (`stateOf`: not removed, `inactive`, no outcome).

**Why it is here.** §2.4's fix exposed it. Once the owner writes its own state
before the child's inverses run, that write lands while the child is still an
entry — and Cordis's `_getState()` mapped `uid === null` straight to `DISPOSED`,
i.e. to "removed". S-Rem-5 (M7), which had been passing, then failed its
snapshot clause: *"G is retired and Inactive while its registered child C is
still tearing down, and must NOT yet have left the registry."* Without this
change §2.4 is a wash — one script gained, one lost.

**Change.** `fiber.ts:656`. `_getState()` returns `PENDING` while `_retired` is
non-empty, and `DISPOSED` once the deferred children are gone. `assertRegistered()`
(§2.2) reads the same state, so `update`/`setval`/reads at `G` are correctly
*enabled* during that window, which is what the calculus says.

**Trace.** S-Rem-5, mid-settle snapshot at `inv(C,b)`:

```
spec:   states.G = pending      (Inactive(⊥), τ=⊤, still an entry)
before: states.G = disposed     (only after §2.4; before §2.4 the snapshot fell
                                 inside G's UNLOADING and read 'unloading')
after:  states.G = pending, final states.G = disposed
```

### 2.6 F4 — O-Insert's disjointness premise is decided by the declared key

**Decision: the calculus mandates the key-level test, and this build was wrong.**

**Clause.** [SZC26] Table 1's O-Insert row: "declared disjointness
`∀m. p ∩ p_m = ∅`" (`paper.md` §5 summary), refined in Appendix C.1 to *"one
conflict-witness occurrence `conflict(k-pattern)` for each pair `(m,k)` with
`k ∈ p ∩ p_m`"*. `p` and `p_m` are **key** sets; no premise of O-Insert reads
Definition 28's realm table or the store. E.LR.X4(3) and (7) state it twice and
draw the consequence: with `isolate(k1,r1); isolate(k2,r1)`, `{k2} ∩ {k1} = ∅`,
so the insert **passes**, and the collision surfaces where the calculus puts it —
Definition 23's set precondition failing at the joined label inside the
offender's own iteration, an ordinary raise at the offender (X4). `model.mjs`'s
`insert()` implements exactly that: the premise loop is over
`(other.spec.provide ?? []).includes(key)`, realm-blind, while the `provide`
*step* compares labels.

Upstream is right here and the aligned build's earlier repair over-shot: it
refused at the storage label, so the offender never ran and X4 became
unreachable.

**Change.** `registry.ts:339`. `_resolveProvisions()` no longer refuses on an
existing store binding (a binding installed by an undeclared `ctx.provide()`
contributes to no `p_m`), and a claim conflicts only when the *declared name*
matches.

**Trace.** S-Rai-3 (`P = (∅,{k1},[provide(k1,v1)])`, `Q = (∅,{k2},[provide(k2,v2)])`,
both keys isolated to realm `r1`):

```
spec:   active:P | deactivated:Q      states {P: active, Q: failed}   refusals []
before: active:P                      states {P: active, Q: ⊥}
                                      refusals [{insert, Q, PROVISION_CONFLICT}]
after:  active:P | deactivated:Q      states {P: active, Q: failed}   refusals []
```

**Divergence retained, deliberately.** The premise as literally stated is
realm-blind in *both* directions: it also refuses the same key declared in two
separate realms. This build keeps the claim scoped to the realm, so
`root.isolate('svc')` + a second declared provider of `svc` is still legal. No
T\* script exercises that direction, and enforcing it would defeat Definition 28's
own purpose — it is the capability the loader's `isolate` entry option exists to
offer (`vendor/loader/src/config/isolate.ts`), and `paper-review`'s `ce6.mjs`
probe A2 asserts it. The literal reading was implemented and measured: it passes
T\* identically (73/75) and flips GAP-6 to PRESENT. **This is the one place where
the build knowingly diverges from the premise as written**, and the paper should
record it under A4: premise (iv) has no clause relating `p` to `ρ`, and a realm
system needs one.

---

## 3. Confirmed non-defects

### 3.1 F3 — S-It-4 / T7 is a mapping gap (confirmed)

T7 needs a fiber `C` with `π_C = G` that is **not** in `G`'s accumulator: an
orchestrator's O-Insert under `π = G`, as opposed to Definition 47's
registration by `G`'s effect function, which pushes `reg⁻(C)` into `g_G`.

Confirmed unreachable. In this runtime the fiber tree *is* the ownership tree:
`RegistryService.plugin()` constructs `new Fiber(this.ctx, …)`, and `Fiber`'s
constructor unconditionally registers the child's disposer on `parent.fiber`
(`fiber.ts:277`, `this.dispose = parent.fiber.effect(…)`). There is no
parameter, no second entry point, and no derived context whose `.fiber` differs
from its lexical owner — `isolate()`/`intercept()` derive contexts *from* a
fiber, they do not reparent one. Algorithm 6's walk follows the same chain
(`reflect.ts:177`, `fiber = fiber.parent.fiber`), so the two notions cannot be
separated even in principle without new public API.

Not fixed: adding an API for a distinction no existing caller can express is not
a minimal conformance fix, and the suite's adapter would not reach it (its
`insert` is `context.plugin(...)`). The correct home is D1 §15's unrealizable
column *for implementations*, exactly as the suite's F3 proposes.

Residual failure (unchanged from the baseline):

```
spec: active:P | active:Q | active:G | read:C:k1="v1" | active:C | deactivated:G
      | deactivated:P | deactivated:C | deactivated:Q | active:Q2
      | readfail:C:k1:INACTIVE_ACCESS | active:C
impl: active:P | active:Q | active:G | read:C:k1="v1" | active:C | deactivated:C
      | deactivated:G | deactivated:Q | deactivated:P | active:Q2
```

`C` ends `disposed` where the specification has it `active`; the T7 read never
happens because `C` did not survive `G`.

### 3.2 F11 — S-Upd-4 / W5 is a notation limit (confirmed)

Confirmed on this build. `P = (∅,{k1},[provide(k1,v1), raise(x)])`; the window
runs from L-Raise to L-Unload. In the runtime that is
`_execute()` rejecting → `_reload()`'s catch → `_updateState()` → `_unload()`,
with no ordinary event in between: the `provide` inverse emits nothing, and no
other fiber exists. The suite's own argument (the only rule that can delay
L-Unload is the reliance guard, and no fiber can hold a committed edge to a
fiber that raised during its own Reloading) is a statement about the
*specification*, so no build can do better. The runner reports it as
**not presented**, not as a failure, which is the right status.

### 3.3 F6 — D3 and D10 are coverage gaps (confirmed, with a sharper cause)

Both scripts **pass**; only their `Branch` letters go unrealized. Confirmed as
not a conformance violation — but the suite's stated cause ("a microtask-ordering
artifact of the schedule pin") is not quite it, and the pin is not to blame.

- **D10 / S-Div-6.** The pin fires `retire(Q)` synchronously inside `G`'s
  `register(K)` step, and it does invalidate `G`'s epoch synchronously, so `G`
  diverts at the very next boundary with `g = [register⁻¹]` — `apply:G:g1` never
  occurs, exactly as the letter requires. What the branch also requires is that
  `K` never begin. `K`'s own `_reload()` checkpoint was queued when
  `ctx.plugin(K)` ran, and it resumes before `G`'s teardown reaches `K`'s
  wrapper. In calculus terms: at that configuration both `L-Begin@K` and
  `L-Divert@G` are enabled and this runtime schedules `L-Begin@K` first. Both are
  fair schedules and `Out(ρ)` contains both, so this is coverage, not conformance.

- **D3 / S-Div-3.** Sharper: the letter is missed because **the accumulator is
  not applied atomically**. `_unload()`'s per-item `revert()` opens with
  `await Promise.resolve()` (it exists to force an async stack trace), so between
  `inv(G,a)` and `reg⁻(C)` the runtime yields, and `C`'s episode advances
  `apply:C:c` and reaches Active *before* `reg⁻(C)` sets `τ_C = ⊤`. In the
  calculus L-Unload@G is one transition, so that intermediate configuration does
  not exist and `C` is retired before its next boundary. Observed:

  ```
  spec: … | apply:C:b | revert:G:a | deactivated:G | revert:C:b | deactivated:C
  impl: … | apply:C:b | revert:G:a | apply:C:c | active:C | deactivated:G | …
  ```

  Not fixed. Closing it means applying the whole accumulator without yielding,
  which is impossible in general (an inverse may be genuinely async) and would
  trade the `composeError` async-stack diagnostics that the U-scripts' ordering
  clauses depend on. It is the same asynchrony question [SZC26] §4.3.3 and
  ambiguity A9 leave open, and it is the honest place to record it — not as a
  pin artifact.

---

## 4. What remains failing

| script | letter | why |
| --- | --- | --- |
| S-It-4 | T7 (with A3) | §3.1 — unreachable through Cordis's interface; needs new public API, not a fix |
| S-Upd-4 | W5 | §3.2 — not presentable without a certificate channel; reported as *not presented* |

Uncovered letters: `A3, T7` (§3.1), `W5` (§3.2), `D3, D10` (§3.3, coverage on
this schedule — the scripts conform). Every other letter of the 103 is realized.

---

## 5. Sibling work (harness-side, **not applied**)

`pnpm run test` at the harness root: **13506 passed, 9 failed**. Three of the
nine fail on a clean tree as well (`packages/context/agent-instructions`,
`packages/skill/skill-filesystem`, `scripts/install-lefthook.spec.ts`) and two
more (`packages/typert/loader`, `packages/llm/llm-deepseek`) are order-dependent
flakes seen in only one of two baseline runs. The remaining **six** are caused by
these fixes, each attributed by bisection (rebuild with the single change
disabled):

| test | cause | required change |
| --- | --- | --- |
| `packages/core/agent-loop/tests/scope-lifecycle.spec.ts:593` | §2.2 | the regex `/agent loop is not active\|inactive context/` must also accept `no such entry`. Behavior is unchanged — the call still fails loud with no orphan; only the reason is now the one Definition 7 owes for a removed entry. |
| `packages/subagent/subagent-spawn-in-process/tests/subagent-spawn-in-process.spec.ts:461` | §2.2 | same: `/inactive context/` → also accept `no such entry`. The test's own name says "DISPOSING", but it awaits `parentHandle.dispose()` first, so the parent is *removed*, and "never again" is the correct reason. |
| `packages/settings/settings/tests/settings.spec.ts` — "stays silent when the consumer itself unloads" and "…for a stored change that lands while the consumer unloads" | §2.5 | `isUnloading()` at `packages/settings/settings/src/index.ts:823` mirrors `FiberState` as `{UNLOADING, DISPOSED}`, and §2.5 adds a third state a retiring fiber can be in. The exact test for "my fiber is going away" is the retirement flag: `ctx.fiber.uid === null`. The helper's own comment already notes the mirror is a value copy of a const enum. |
| `packages/core/agent-loop/tests/config-session-id.spec.ts` — "cancels an exact-id reload while the prior lifecycle is still draining" and "waits for a draining exact-id lifecycle during an overlapping reload" | §2.4 | These encode the pre-fix teardown order: a child's gated async cleanup used to block the owner's *remaining* inverses, so the agent stayed in `ctx.agents` for the width of the gate. E.LU.U7 and §4.3.1 say the owner applies its whole accumulator and deactivates first, so `ctx.agents.get(sessionId)` is now `undefined` while the agent drains. **This is a real behavioral change, not a message change**, and it is worth a decision: if the harness needs the registry entry to outlive the child's teardown, it should be released by an effect on the *agent's* fiber rather than on the loop's — which is also what Definition 47 describes. Reported rather than applied. |

None of the six is a regression against the calculus; all six are places where
harness code encodes the behavior the calculus says was wrong. They are reported
rather than applied because `packages/` is outside this change's remit and is
edited concurrently.

`paper-review/counterexamples/run-all.mjs` is unchanged by all six fixes
(GAP-1/2/3/6/9 ABSENT, GAP-4/5/7/8 PRESENT), including GAP-6, whose probe A2
motivated the realm scoping retained in §2.6.
