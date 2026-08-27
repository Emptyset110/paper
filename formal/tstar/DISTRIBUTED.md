# T\* across a process boundary — what `cordis-node` costs

```
single process,  fixed build          73 / 75 scripts,  98 / 103 letters
two nodes,       fixed build          70 / 75 scripts,  93 / 103 letters
two nodes,       upstream build       58 / 75 scripts,  83 / 103 letters   (the old baseline)
two nodes,       fixed build,
                 both plugins on one node
                                      73 / 75 scripts,  98 / 103 letters   (the control)
```

T\* has been run against the distributed target before, but always with the
published upstream `@deepseek-ai/cordis` 4.0.1 underneath, so its 17 failures
were the base's and the projection layer's mixed together and no statement
about distribution could be extracted from them. `VENDOR-FIXES.md` changed
that: the single-process build is now conformant at 73/75, so the inference is
finally clean —

> a script that **passes single-process on the fixed build** and **fails
> distributed on the fixed build** is a defect of `@rebuilding/cordis-node`
> itself.

That set has three members. This document names them, diagnoses each to the
projection mechanism responsible, and says for each whether the Distribution
Equivalence Contract (`cordis-plugins/cordis-node/docs/equivalence.md`) permits
the divergence.

---

## 1. Re-pointing the distributed target

`../../proof/src/adapter-distributed.mjs` hard-codes the Cordis it builds its
two nodes from —

```js
const CORDIS_FOR_NODE = new URL('../../../cordis-plugins/cordis-node/node_modules/@deepseek-ai/cordis/lib/index.js', import.meta.url).href
```

— which is the published 4.0.1. Worse, that is only half of it:
`@rebuilding/cordis-node`'s own compiled `lib/{projection,service,rpc,observer}.js`
import the **bare** specifier `@deepseek-ai/cordis`, which resolves from the
package's own `node_modules` to the same upstream copy. So `CORDIS_LIB` had no
effect on `PROOF_TARGET=cordis-node` at all, and could not have: two of the
three consumers never looked at it.

Both forms are answered by a module-resolution hook, which is the whole of the
change and lives here rather than in `paper/proof/`:

| file | contents |
| --- | --- |
| `cordis-lib-hook.mjs` | the `resolve` hook: pins the bare specifier and any resolution landing on `…/node_modules/@deepseek-ai/cordis/lib/index.js` to one URL, and reports every redirect and every *leak* |
| `use-cordis-lib.mjs` | the `--import` registrar; reads `CORDIS_LIB` with `target.mjs`'s own convention, default = the fixed vendored build |
| `assert-build.mjs` | checks that the pin took, three independent ways |
| `adapter-distributed-placed.mjs` | the co-location control (§6) |

```bash
cd paper/formal/tstar

# the distributed target on the FIXED build
PROOF_TARGET=cordis-node node --import ./use-cordis-lib.mjs run-tstar.mjs

# prove the pin took, before believing the run
TSTAR_LIB_LOG=/tmp/lib.log PROOF_TARGET=cordis-node \
  node --import ./use-cordis-lib.mjs assert-build.mjs

# the control: cordis-node installed, nothing crossing a link
PROOF_TARGET=cordis-node TSTAR_PLACEMENT=colocated \
  node --import ./use-cordis-lib.mjs run-tstar.mjs

# the old baseline, unchanged (no --import)
PROOF_TARGET=cordis-node node run-tstar.mjs
```

Nothing under `paper/proof/` is modified, and **`cordis-node` needs no
rebuild**: its `lib/` is a plain `tsc` output that imports Cordis by bare
specifier and keeps it external, so swapping the build is a resolution
question, not a compilation one. (`lib/` was confirmed current against `src/`
before the runs.)

### The pin is asserted, not assumed

`assert-build.mjs` refuses to let the run be interpreted on trust:

1. **Module graph.** The hook reports its importers. The run requires at least
   one redirect requested by `cordis-plugins/cordis-node/lib/*` (the projection
   layer) and one by `paper/proof/src/adapter-distributed.mjs` (the two nodes),
   and **zero leaks** to any other Cordis copy.
2. **Identity.** `@deepseek-ai/cordis` and the pinned URL must be one module
   instance. Cordis keys its internals by module-local symbols, so two
   instances would not merely be "a different build" — they would silently fail
   to interoperate.
3. **Behaviour, once per node.** Two fixes only the vendored build has, driven
   through the adapter's own `insert`, whose placement alternates between the
   two partition hosts, so each is checked on node A *and* on node B:
   - §2.1 (F1): a fiber inserted and retired before it ever activated is
     removed with **no** `deactivated` event;
   - §2.2 (F9): `update` at a removed entry is refused with **NO_SUCH_ENTRY /
     "no such entry"**, not with the liveness reason.

Observed:

```
pinned build: file:///…/deepseek-harness/vendor/cordis/lib/index.js
  ok   identity: `@deepseek-ai/cordis` === the pinned build
  ok   F1 §2.1: a never-activated fiber is removed with no `deactivated` (both nodes)
  ok   F9 §2.2: update at a removed entry on node A → NO_SUCH_ENTRY no such entry: …
  ok   F9 §2.2: update at a removed entry on node B → NO_SUCH_ENTRY no such entry: …
  ok   module graph: the PROJECTION layer imports the pinned build
  ok   module graph: the two NODES are built from the pinned build
  ok   module graph: 6 redirects, 0 leaks to another Cordis
```

Both refusals are the *registry* reason, which upstream cannot produce at all
(it answers `cannot create effect on inactive context`), so the third check is
a real discriminator and not a tautology.

---

## 2. What "distributed" means here

The adapter's placement rule (its own header states it) is: **root inserts
alternate between node A's and node B's partition host**; explicit contexts
(children, isolation, interception) stay where they are; and *every* σ_γ
observation reads **node A**, so a provider placed on B is visible to the
observer only through the projection.

Of the 75 scripts, **24 place components on both nodes** and 51 run entirely
inside node A's partition. The 51 are not wasted: they still run under two
booted nodes, a live loopback pair, mutual partition mounts and a running
observer, so they test that installing the projection layer changes nothing.
The 24 are where the contract is actually under test — and among them are the
provider/consumer pairs whose store reads cross the wire. `S-Unl-2`'s
`read:C:k1="v1"` is C on node B resolving a service provided by P on node A;
that letter is produced by the projection, not by Cordis.

The `A+B` column of the table below marks the 24.

---

## 3. The three-way table

`local` = `PROOF_TARGET=cordis` on the fixed vendored build (73/75).
`colo` = the distributed target with both plugins on node A (the control, §6).
`dist` = the distributed target with the adapter's alternating placement.
`upstr` = the old distributed baseline over upstream 4.0.1, for reference.
`ᵇ` = the script conforms but its canonical **branch** was not selected on that
target's schedule (a coverage gap of the run, not a verdict).

| script | rule | letters | place | local | colo | dist | upstr |
| --- | --- | --- | :-: | :-: | :-: | :-: | :-: |
| S-Ins-1 | O-Insert | I1,I4,I6 | A | pass | pass | pass | pass |
| S-Ins-2 | O-Insert | I2 | A | pass | pass | pass | pass |
| S-Ins-3 | O-Insert | I3 | A | pass | pass | pass | **FAIL** |
| **S-Ins-4** | O-Insert | I7 | A+B | pass | pass | **FAIL** | **FAIL** |
| S-Ret-1 | O-Retire | R1 | A | pass | pass | pass | **FAIL** |
| S-Ret-2 | O-Retire | R2 | A | pass | pass | pass | pass |
| S-Ret-3 | O-Retire | R3 | A | pass | pass | pass | **FAIL** |
| S-Ret-4 | O-Retire | R4 | A | pass | pass | pass | **FAIL** |
| S-Rem-1 | O-Remove | M1,M3,M6 | A | pass | pass | pass | **FAIL** |
| S-Rem-2 | O-Remove | M2 | A | pass | pass | pass | pass |
| S-Rem-3 | O-Remove | M4 | A | pass | pass | pass | **FAIL** |
| S-Rem-4 | O-Remove | M5 | A | pass | pass | pass | pass |
| S-Rem-5 | O-Remove | M7 | A | pass | pass | pass | pass |
| S-Beg-1 | L-Begin | B1,B3 | A | pass | pass | pass | pass |
| S-Beg-2 | L-Begin | B2 | A | pass | pass | pass | pass |
| S-Beg-3 | L-Begin | B4 | A | pass | pass | pass | **FAIL** |
| S-Beg-4 | L-Begin | B5 | A+B | pass | pass | pass | pass |
| S-Beg-5 | L-Begin | B6 | A+B | pass | pass | pass | pass |
| S-Beg-6 | L-Begin | B7 | A | pass | pass | pass | pass |
| S-It-1 | L-Iter | T1,T2,T4,T5 | A+B | pass | pass | pass | pass |
| S-It-2 | L-Iter | T3 | A | pass | pass | pass | pass |
| S-It-3 | L-Iter | T6 | A+B | pass | pass | pass | pass |
| *S-It-4* | L-Iter | T7 | A+B | **FAIL** | **FAIL** | **FAIL** | **FAIL** |
| S-It-5 | L-Iter | T8 | A | pass | pass | pass | pass |
| S-It-6 | L-Iter | T9 | A | pass | pass | pass | pass |
| S-It-7 | L-Iter | T10 | A | pass | pass | pass | pass |
| S-It-8 | L-Iter | T11 | A | pass | pass | pass | pass |
| S-Fin-1 | L-Finish | F1 | A | pass | pass | pass | pass |
| S-Fin-2 | L-Finish | F2 | A | pass | pass | pass | pass |
| S-Fin-3 | L-Finish | F3 | A+B | pass | pass | pass | pass |
| S-Div-1 | L-Divert | D1,D4,D5 | A+B | pass | pass | pass ᵇ | pass |
| S-Div-3 | L-Divert | D3 | A+B | pass ᵇ | pass | pass ᵇ | pass |
| S-Rai-1 | L-Raise | X1,X2,X6 | A | pass | pass | pass | pass |
| S-Rai-2 | L-Raise | X3 | A | pass | pass | pass | pass |
| S-Rai-3 | L-Raise | X4 | A | pass | pass | pass | pass |
| S-Rai-4 | L-Raise | X5 | A | pass | pass | pass | pass |
| S-Rai-5 | L-Raise | X7 | A | pass | pass | pass | pass |
| S-Rai-6 | L-Raise | X8 | A | pass | pass | pass | pass |
| S-Rai-7 | L-Raise | X9 | A | pass | pass | pass | pass |
| S-Lea-1 | L-Leave | V1,V3 | A | pass | pass | pass | pass |
| S-Lea-2 | L-Leave | V4 | A+B | pass | pass | pass | pass |
| S-Lea-3 | L-Leave | V5 | A | pass | pass | pass | pass |
| S-Unl-1 | L-Unload | U1,U3,U6,U10 | A | pass | pass | pass | pass |
| **S-Unl-2** | L-Unload | U2 | A+B | pass | pass | **FAIL** | **FAIL** |
| S-Unl-3 | L-Unload | U4 | A | pass | pass | pass | pass |
| S-Unl-4 | L-Unload | U5 | A | pass | pass | pass | pass |
| S-Unl-5 | L-Unload | U7 | A | pass | pass | pass | **FAIL** |
| S-Unl-6 | L-Unload | U8 | A+B | pass | pass | pass | pass |
| S-Unl-7 | L-Unload | U9 | A | pass | pass | pass | pass |
| S-Unl-8 | L-Unload | U11 | A+B | pass | pass | pass | pass |
| S-Unl-9 | L-Unload | U12 | A+B | pass | pass | pass | pass |
| S-Prov-1 | CO-Prov | P3 | A | pass | pass | pass | pass |
| S-Prov-2 | CO-Prov | P4 | A | pass | pass | pass | pass |
| S-Iso-1 | CO-Iso | S2 | A | pass | pass | pass | pass |
| S-Iso-2 | CO-Iso | S3 | A | pass | pass | pass | pass |
| S-Iso-3 | CO-Iso | S4 | A | pass | pass | pass | pass |
| S-Int-2 | CO-Int | N2 | A | pass | pass | pass | pass |
| S-Int-3 | CO-Int | N3 | A | pass | pass | pass | pass |
| S-Int-4 | CO-Int | N4 | A | pass | pass | pass | pass |
| S-Acc-1 | CO-Acc | A6 | A+B | pass | pass | pass | pass |
| S-Div-4 | L-Divert | D7,D9,D12 | A | pass | pass | pass | **FAIL** |
| S-Div-5 | L-Divert | D8,D9 | A+B | pass | pass | pass ᵇ | pass |
| S-Div-6 | L-Divert | D10 | A+B | pass ᵇ | pass | pass ᵇ | pass |
| S-Div-7 | L-Divert | D11 | A+B | pass | pass | pass ᵇ | pass |
| S-Div-8 | L-Divert | D12 | A+B | pass | pass | pass ᵇ | pass |
| S-Rai-8 | L-Raise | X10 | A+B | pass | pass | pass | pass |
| S-Lea-4 | L-Leave | V6 | A+B | pass | pass | pass | pass |
| S-Upd-1 | O-Update | W2 | A | pass | pass | pass | pass |
| S-Upd-2 | O-Update | W3 | A | pass | pass | pass | pass |
| **S-Upd-3** | O-Update | W4 | A+B | pass | pass | **FAIL** | **FAIL** |
| *S-Upd-4* | O-Update | W5 | A | n/p | n/p | n/p | n/p |
| S-Upd-5 | O-Update | W6 | A | pass | pass | pass | **FAIL** |
| S-Set-1 | CO-Prov | P7 | A | pass | pass | pass | **FAIL** |
| S-Acc-2 | CO-Acc | A8 | A+B | pass | pass | pass | **FAIL** |
| S-Acc-3 | CO-Acc | A4 | A+B | pass | pass | pass | pass |

**Classification of every difference between `local` and `dist`:**

| class | scripts | |
| --- | --- | --- |
| **(a) distribution defect** — passes local, fails distributed | **S-Ins-4** (I7), **S-Unl-2** (U2), **S-Upd-3** (W4) | §4, §5 |
| **(b) inherited** — fails both | *S-It-4* (T7, with A3) | §7 |
| **(c) not presentable** — the driving anchor does not exist on this target | *S-Upd-4* (W5) | §8 |

The distributed run is deterministic: two full runs produced verdict-identical
output, script for script.

---

## 4. Distribution defect 1 — the declared-provision premise stops at the node boundary

*Script:* **S-Ins-4** (I7, co-realizing I1 and I4). Mechanism: **snapshot
projection / catalog revision**. Contract clauses violated: *same service
availability*, *same lifecycle transitions*. **Not covered by any declared
boundary B1–B8 ⇒ a bug by the contract's own terms** ("an inequivalence that is
not here is a bug").

**The experiment.** `P = (∅,{k1},[provide(k1,v1)])`, `Q = (∅,{k1},[])`;
ρ = `insert(P); insert(Q)` with no settle between them — the load-bearing fact
(D1 §1.3) being that *declared* provisions block while P is still
Inactive(⊥). The specification refuses Q's insert on O-Insert premise (iv),
`∀m. p ∩ p_m = ∅`.

```
spec:   refusals [{insert, Q, PROVISION_CONFLICT}]
local:  refusals [{insert, Q, PROVISION_CONFLICT}]      (VENDOR-FIXES §2.6)
colo:   refusals [{insert, Q, PROVISION_CONFLICT}]
dist:   refusals []                                     ← both fibers load
```

**Root cause, located.** The premise is decided in Cordis by
`registry.ts::_resolveProvisions()`, which scans `Registry._provisions` — a
node-global map of *declared* claims, one entry per `plugin.provide` name, kept
by `_claimProvisions()`. `cordis-node` never contributes to it. Its
`FiberDescriptor` (`src/types.ts`) carries

```ts
services: readonly ServiceDescriptor[]     // the registrations that HAPPENED
```

and has no field for the remote plugin's *declared* provision set `p_m`. The
projection installs a remote service with
`serviceContext.reflect.provide(name, value, …)` on a shadow fiber
(`src/projection.ts::addService`), and `reflect.provide` is precisely the
**undeclared** runtime provision that `VENDOR-FIXES.md` §2.6 established
"contributes to no `p_m`". So the catalog projects **bindings, never
declarations**, and premise (iv) is evaluated per node over a strict subset of
the registry.

**It is not a race.** Adding a settle between the inserts — letting P go Active
and its provision fully project onto node B — does not change the answer:

```
after settle, k1 on A = v1
Q refused? null
trace [ 'active:P', 'active:Q' ]
```

**The observable consequence is split brain.** With both declarers admitted,
`P = (∅,{k1},[provide(k1,v1)])` on A and `Q = (∅,{k1},[provide(k1,v2)])` on B:

```
states       active   active
A sees k1 =  v1
B sees k1 =  v2
```

Two nodes of one composition disagree about who provides `k1`, where the
single-node run has exactly one `k1` and no `Q` at all. That is the contract's
first bullet — "a service is resolvable from a Context exactly when it is
resolvable in the single-node run" — failing, and nothing in B1–B8 licenses it.

**Not fixed, and why.** The obvious repair — give `FiberDescriptor` a
`declares: readonly string[]` field and have `createSkeleton` build the shadow
plugin with `provide: descriptor.declares` so the claim lands in the consuming
node's `Registry._provisions` — is not minimal, and it does not close the
script:

- it is a **protocol change** (a new descriptor field, both endpoints shipping
  together — the same class of change as the `proto` tag, but with semantics);
- it needs a **conflict policy** the contract does not have. On one node the
  premise has a total order: the second declarer is refused. Across a link there
  is no global order, and both nodes can be right about "I was first". A
  conflicting shadow would have to fail `mountContext.plugin(...)` **inside**
  `createSkeleton`, i.e. break the mount, rather than refuse the later plugin —
  a different observable from the single-node one, and arguably a worse one;
- and it would still not make S-Ins-4 pass, because that ρ deliberately has no
  settle. Deciding a *synchronous global* premise over an *asynchronous*
  catalog is not an implementation gap, it is the CAP-shaped core of the
  problem: at the instant Q is inserted on B, no protocol can have told B about
  a P inserted microseconds earlier on A.

The honest statement is therefore: **premise (iv) of O-Insert is not
distributable as written.** A distributed Cordis either weakens it to
eventual detection (project the declarations, refuse late, report a conflict)
or accepts split provision. `cordis-node` currently does the latter silently,
which is the part that is unambiguously wrong: whatever policy is chosen, the
condition is detectable once the catalog has converged, and it should not be
invisible.

---

## 5. Distribution defect 2 — the merged teardown order across the wire (contract boundary B5)

*Scripts:* **S-Unl-2** (U2) and **S-Upd-3** (W4) — one mechanism, two
witnesses. Mechanism: **remote effect ordering via catalog revision**.
**Explicitly permitted by declared boundary B5 ⇒ a contract boundary, not a
bug** — but it is a real divergence from the calculus, and this is the first
time it has been convicted by an experiment derived from the alphabet.

Both scripts have the same ρ (`insert(P); settle; insert(C); settle;
retire(P); settle`) and the same shape of components: **P declares k1 and holds
a tracked effect `a`; C injects k1 and holds a tracked effect `b`.** P lands on
node A, C on node B.

```
spec: apply:P:a | active:P | read:C:k1="v1" | apply:C:b | active:C | revert:C:b | deactivated:C | revert:P:a | deactivated:P
dist: apply:P:a | active:P | read:C:k1="v1" | apply:C:b | active:C | revert:P:a | revert:C:b | deactivated:C | deactivated:P
                                                                     ^^^^^^^^^^^^^^^^^^^^^^^
```

The convicted clause is E.LU.U2(13), *"the provider's unload is BLOCKED while an
installed consumer holds ω(k1)=P, so inv(C,b) precedes inv(P,a) and the k1
withdrawal — Theorem 63 as an event order"*. S-Upd-3 convicts the same order
from an `update` script (its own W4 content — "the update at an `Unloading`
fiber perturbs no event, no certificate and no report field" — is now
**satisfied**: the refusal that used to be the whole divergence was fixed by
`VENDOR-FIXES.md` §2.2, and the only residue is the guard order).

**B5, quoted:** *"The relative order of a provider's teardown and a remote
dependant's unload … On one node the provider's `provide` disposer and the
dependant's unload are one synchronous cascade. Across a link the provider's
node completes its own teardown and the dependant's node learns afterwards.
Suspending a remote dependant before the provider finishes would require a
distributed two-phase lifecycle protocol. Per-plugin order and settled state
are preserved; only the merged cross-plugin order is not."* This is that
sentence, observed.

**What is preserved, checked rather than assumed.** The failure is narrower
than "the reliance guard is gone", and three neighbouring scripts prove it —
all three have the *same* ρ, place P on A and C on B, and pass with words
identical to the specification's:

```
S-Unl-6 (U8) spec/dist: active:P | read:C:k1="v1" | apply:C:a | active:C | revertread:C:k1="v1" | deactivated:C | deactivated:P
S-Lea-2 (V4) spec/dist: active:P | read:C:k1="v1" | apply:C:a | active:C | revert:C:a | deactivated:C | deactivated:P
S-Unl-8 (U11) — identical
```

- `deactivated:C < deactivated:P` holds distributed, including inside S-Unl-2's
  own tail. The parent/child and provider/dependant **settled** order is right.
- S-Unl-6's `revertread:C:k1="v1"` — the A7 grammar extension, an inverse that
  *reads* — still resolves `k1` to `v1` while C tears down. The guard's
  observable content, "a dependant's inverse still sees the provision it
  relies on", survives the wire.
- Every disposer runs exactly once; C ends `pending` and P `disposed`, matching
  the specification's report field for field.

So exactly one thing is lost: the **interleaving of the two plugins' own
tracked inverses**, which is visible only when the provider *and* the remote
dependant both have one. S-Unl-2 and S-Upd-3 are the only two scripts of the 75
that arrange that, which is why they are the only two that fail.

**A caveat about the mechanism.** In S-Unl-6 the read succeeds distributed for
a *different reason* than in the specification: the specification blocks P's
L-Unload until C's inverse has run, whereas the projection lets P's provide
disposer run on A and C's inverse reads a still-unrevised projected binding on
B. The two coincide observationally at this scale, which is what conformance
asks for; they would not coincide if the teardown window were long enough for
the catalog revision to land first. B5 is the right place to record that, and
the availability extension already covers the degraded case.

**Not fixed.** The contract names the price: a distributed two-phase lifecycle
protocol. That is a design change to `cordis-node`, not a repair, and it is
declared, so it is out of scope here. What this run adds is the *evidence*: B5
is not a hypothetical residue, it is exactly and only the merged inverse
interleaving, and it costs T\* two scripts and two letters.

---

## 6. The control: cordis-node installed, nothing crossing a link

`TSTAR_PLACEMENT=colocated` (`adapter-distributed-placed.mjs`) is the
equivalence contract's own degenerate case — §(b)'s single-block set partition,
*"cordis-node is installed but nothing crosses a link"*. Both nodes still boot,
publish their partition, mount each other and stay connected over the loopback
pair; only the placement changes, every root insert going to node A's host. It
is installed by resolution override from `use-cordis-lib.mjs`, so the runner
and `target.mjs` are untouched.

```
73 / 75 scripts,  98 / 103 letters,  uncovered A3, D10, D3, T7, W5
```

That is **identical to the single-process run on the same build**, script for
script, letter for letter, including which two canonical branches the schedule
misses. Installing the projection layer, booting a second node, publishing,
mounting and running the observer costs **nothing**. Every difference in §3 is
bought by *placement*, which is what makes the three defects distribution
defects rather than "cordis-node defects".

---

## 7. Inherited — S-It-4 (T7, with A3)

Fails on all four targets, identically, for the reason `VENDOR-FIXES.md` §3.1
confirmed: `insert(G, C)` is `G.ctx.plugin(...)`, which is also the only
realization of Definition 47's registration, so an orchestrator-inserted child
cannot be separated from a child registered by its parent's effect function,
and C is disposed with G. `C` ends `disposed` where the specification has it
`active`. Distribution neither causes nor masks it; the distributed word
differs from the single-process one only in the position of the anti-diagonal
`deactivated` letters, which the script's clauses do not read.

---

## 8. Not presentable — S-Upd-4 (W5)

Unchanged from every other real target, and for a reason that is about the
vocabulary, not about the target. W5's input must land in the window between
L-Raise and L-Unload; no *ordinary* event occurs there on any fair schedule, so
ρ anchors on `cert(L-Raise, P)`, a rule certificate. §5.4's vocabulary proviso
binds the **driving** half of an experiment as well as the observing half: a
certificate-erased implementation cannot be *placed* in that window at all.

The projection boundary makes no difference to this: the certificate channel is
absent on one node and on two for the same reason. Stated precisely, the reason
S-Upd-4 is not presentable distributed is **not** that its driving anchor fails
to cross the projection — it is that the anchor does not exist on either side of
it. (Contrast W5 with D7 and W4, whose audit-§3.5 anchors were deliberately
re-rendered in the ordinary vocabulary and *are* presented and convicting on
every target, distributed included.)

---

## 9. Coverage, and the schedule difference that is not a defect

| target | letters | uncovered |
| --- | :-: | --- |
| local, fixed build | 98 / 103 | A3, D3, D10, T7, W5 |
| distributed, fixed build | **93 / 103** | A3, **D4**, **D8**, D3, D10, **D11**, **I7**, T7, **W4**, W5 |
| distributed, upstream | 83 / 103 | A3, A8, D4, D7, D8, D9, D10, D11, D12, I3, I7, M4, P7, R3, R4, T7, W1, W4, W5, W6 |

The five letters distribution costs split cleanly in two:

- **I7 and W4** are the two defects of §4 and §5.
- **D4, D8, D11** are **coverage, not conformance**. Six L-Divert scripts
  (S-Div-1, -3, -5, -6, -7, -8) report *letter-not-realized*: on the
  distributed schedule the target takes the non-diverting branch, which the
  specification's own outcome set contains. Single-process only S-Div-3 and
  S-Div-6 do. The extra microtask turns the observer and the loopback pair
  introduce shift the iteration boundary, so `L-Begin@K` wins the race against
  `L-Divert@G` more often. `D1, D5, D9, D12` survive because other passing
  scripts co-realize them; `D4, D8, D11` have no second witness.

One caveat on reading the coverage line: **U2 is *not* in the distributed
uncovered set even though S-Unl-2 fails**, because four passing scripts
co-realize it (S-Beg-5, S-Lea-2, S-Unl-6, S-Unl-8). Those scripts present the
U2 occurrence but their verdicts do not pin the merged inverse order — the very
thing §5 is about. The letter count therefore under-reports the B5 divergence,
and 93/103 should be read alongside §5, not instead of it.

---

## 10. What T\* does not reach

T\*'s alphabet is the calculus's: orchestration labels, lifecycle rules, the
store, and the effect-step vocabulary. Mapped onto the projection layer's
mechanisms, the run exercises

- **catalog revision and snapshot projection** — every `A+B` script's store
  read and every remote lifecycle transition goes through it (§4, §5);
- **service projection** (`addService` / `reflect.provide` on shadow fibers) —
  the `read:C:k1` letters;
- **remote effect ordering** — §5;
- **the reliance guard across the wire** — §5, from both directions.

It does **not** reach **RemoteRef relay** (P5/L5), **event and certificate
transport** (P6/L6 — T\*'s certificate channel is model-only and its ordinary
vocabulary has no dispatch letter), **value fidelity** (P2), **error
propagation** (P9), or the **availability extension** (P10): no script cuts a
link. Those remain the province of `cordis-node`'s own equivalence suite, whose
placement sweep covers them exhaustively over small cases. The two suites are
complementary — T\* indexes the *calculus's* occurrences, the equivalence suite
indexes the *projection's* primitives — and neither subsumes the other.

---

## 11. A sibling finding: cordis-node's own suite on the fixed base

Reported, not fixed; `cordis-node`'s source was not modified by this work.

```
cd cordis-plugins/cordis-node && pnpm test
  19 files, 222 passed | 1 expected fail (223)          ← on upstream 4.0.1, green

  same suite, `@deepseek-ai/cordis` aliased to the fixed vendored build:
  1 failed | 221 passed | 1 expected fail (223)
```

The one failure is
`tests/preparation-projection.spec.ts` → *"keeps the old revision visible while
preparing an update and cleans it only after the swap"*: `cleanupObservations`
has two entries where the test requires one. Instrumented, the fixed base
produces an extra prepare/cleanup cycle **for the same Loader revision**:

```
PREPARE 1 b8ae2c9d
PREPARE 2 fbb3f25a          ← gated
CLEANUP fbb3f25a visible b8ae2c9d      ← the extra pair
PREPARE 3 fbb3f25a
CLEANUP b8ae2c9d visible fbb3f25a      ← the one the test expects
```

Cause: `VENDOR-FIXES.md` §2.3 gives `Fiber.update()` a restart mark, so a
Loader entry update at a non-`ACTIVE` fiber now really does force a
re-resolution (that is D7, and it is the correct behaviour). The extra
lifecycle transition produces a second export snapshot while the first apply is
still awaiting the preparer's gate. `VirtualEntryPreparationManager` is
correctly keyed on `(node, export, entry, revision)` and refcounted
(`src/prepare.ts`), but the reuse test in
`projection.ts::prepareLoaderEntries` consults the **published**
`this.loaderEntries`, which still holds the old revision while a preparation is
in flight; the superseded apply's `acquire` then rejects on its abort signal,
drops the last reference, and rolls the record back before the newer apply
re-acquires it.

Not fixed here: the repair is in the abort/refcount interaction of the
preparation gate (either reuse in-flight records, or do not release on
supersession), the surrounding test asserts cleanup timing in the opposite
direction, and it is unrelated to T\*'s verdicts — the distributed suite scores
70/75 with or without it. It is flagged because it is the one place where the
fixed base changes an observable `cordis-node` currently contracts on, and it
should be settled before the fixed build becomes the default underneath the
projection layer.

---

## 12. Verdict

**Does `cordis-node` make Cordis plugins run multi-process conformantly?**

**Almost, and the residue is exactly one declared boundary plus one real bug.**

> **70 / 75** distributed on the fixed build, against **73 / 75** single
> process. Three scripts separate them.

- Two of the three — **S-Unl-2 (U2)** and **S-Upd-3 (W4)** — are one mechanism,
  the merged interleaving of a provider's and a remote dependant's own inverses,
  and the Distribution Equivalence Contract **declares it** as boundary **B5**
  with its price named (a distributed two-phase lifecycle protocol). They are a
  **contract boundary, not a bug**. What is new is the sharpness: the guard's
  *content* survives the wire — the settled order, the once-only disposers, and
  even an inverse that reads the provision it relies on (U8) are all preserved —
  and only the two-plugin inverse interleaving is lost. T\* is the first
  artifact to convict B5 with an experiment derived from the alphabet rather
  than asserted.
- One of the three — **S-Ins-4 (I7)** — is a **genuine defect**. O-Insert's
  declared-disjointness premise is decided node-locally because the catalog
  projects *bindings* and never *declarations*, and the visible consequence is
  split brain: two nodes of one composition resolve the same service name to
  different providers, silently, where the single-node run refuses the second
  declarer outright. No boundary B1–B8 covers it, so by the contract's own rule
  it is a bug. It is not cheaply fixable — it needs a descriptor field, a
  conflict policy the contract does not have, and even then the *synchronous*
  form of the premise that S-Ins-4 tests is undecidable across a link. The
  correct outcome is a decision recorded in the contract, not a patch: either
  project declarations and refuse late with a reported conflict, or state
  premise (iv) as node-local and say so.
- The remaining two non-passes are **not** distribution's: *S-It-4* (T7) fails
  identically on every target — Cordis's interface cannot present the pointed
  configuration — and *S-Upd-4* (W5) is not presentable in the ordinary event
  vocabulary on any real build, one node or two.
- The five letters lost (I7, W4 from the defects; D4, D8, D11 from the
  schedule) contain three that are **coverage, not conformance**: the
  distributed schedule takes the non-diverting branch of the L-Divert scripts,
  and the specification's outcome set contains that branch.
- And the strongest single number is the control: with `cordis-node` installed,
  two nodes booted, published, mounted and connected, but **nothing crossing a
  link**, the suite scores **73/75 and 98/103 — byte-identical to the
  single-process run.** The projection layer costs nothing until something is
  actually placed remotely.

For the paper: the distribution layer preserves the calculus's semantics on
**70 of the 75** canonical experiments and on **93 of the 103** reachable
occurrences, its two ordering failures fall inside a boundary it declared in
advance, and it has exactly **one undeclared inequivalence**, in O-Insert's
declared-disjointness premise. That is a defensible answer to "does cordis-node
preserve the semantics across processes" — with the qualification that T\*
drives only the calculus's own alphabet, and says nothing about the relay,
event-transport, value-fidelity and link-failure primitives that
`cordis-node`'s placement sweep covers separately.

---

## Reproduce

```bash
cd paper/formal/tstar
PROOF_TARGET=cordis                             node run-tstar.mjs   # 73/75
PROOF_TARGET=cordis-node TSTAR_LIB_LOG=/tmp/l   node --import ./use-cordis-lib.mjs assert-build.mjs
PROOF_TARGET=cordis-node                        node --import ./use-cordis-lib.mjs run-tstar.mjs   # 70/75
PROOF_TARGET=cordis-node TSTAR_PLACEMENT=colocated \
                                                node --import ./use-cordis-lib.mjs run-tstar.mjs   # 73/75
PROOF_TARGET=cordis-node                        node run-tstar.mjs   # 58/75, the upstream baseline

cd ../../../cordis-plugins/cordis-node && pnpm test                  # 222 passed, 1 expected fail
```
