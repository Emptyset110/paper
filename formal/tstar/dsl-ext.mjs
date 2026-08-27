// T* — DSL extensions.
//
// The canonical scripts of D1 (`../signatures.md` §§1.4–14.3) are written in
// the component/step vocabulary of `../../proof/src/dsl.mjs`. That module is
// imported unchanged; this file adds only what the canonical scripts need and
// it does not provide:
//
//   1. `raiseUnless(f, x)` — the §2.2 step constructor D1 §5.1 T11 / §8.1 X3
//      require. The adapters already interpret `{ do: 'raiseUnless' }`; the
//      builder was simply missing.
//   2. `trackReadOnRevert(k, t)` — the A7 grammar extension. D1 §10.3 records
//      that §2.2's step grammar has no inverse that *reads*, while Def. 48
//      clause 2 licenses one and S-Unl-6 (U8) depends on it. Both adapters
//      already interpret `{ do: 'trackReadOnRevert' }`.
//   3. An **orchestration-script vocabulary**. D1 writes ρ as a sequence of
//      `insert / retire / update / setval / isolate / intercept / settle`
//      inputs; `dsl.mjs` covers only component data. These builders make the
//      orchestration half of ρ data too, so a script is fully declarative.
//   4. The two extensions the alphabet audit (`../alphabet-audit.md`) needs,
//      both of which are *script notation for a capability the harness already
//      had*, not new machinery:
//      - `atEvent(ε, λ)` — the audit's §3.5 form `at ε do λ`: deliver the
//        orchestration input λ synchronously at the first occurrence of ε
//        during the next settle. Letters D7, W4 and W5 are windows at
//        *non-quiescent* configurations, which §5.4's `ρ ::= λ … | settle`
//        notation cannot address; Definition 3 clause 1 makes them
//        conformance-relevant all the same. ε ranges over the ordinary event
//        vocabulary and, via `cert(r, n)`, over the rule-certificate channel —
//        which only the reference model has, so a certificate-anchored script
//        is *not presentable* on a certificate-erased target (§5.4's
//        vocabulary proviso, applied to the driving half of an experiment
//        rather than to the observing half).
//      - `readLabel(n, k)` — the audit's §3.6 environment read label
//        `read(n,k)` of Definition 2′, closing GAP-10. It is the paper's §9
//        interface-scope limitation lifted by one channel: the adapters
//        already expose the per-fiber proxy-mediated read as `readVia`, and
//        the label makes it an orchestration input, with its own premise
//        (n ∈ dom F_γ, occurrence A8) and its own rd/rderr letters.
//   5. Two *harness* devices with no counterpart in the paper's script syntax,
//      both documented in README.md §"DSL extensions":
//      - `pin(marker, action)` — schedule pinning. Three canonical scripts
//        (S-Beg-5, S-Div-1, S-Div-3) realize their target occurrence only on a
//        schedule the reference model's FIFO strategy does not take. `pin`
//        arms an orchestration action on a trace marker (the one-shot watcher
//        of `createTrace`), which selects the derivation's canonical branch
//        without changing the pointed configuration.
//      - `snapshot(tag)` — a mid-settle report read, needed where the target
//        occurrence is a *blocking* one whose observation is the persistence
//        of a fiber at a moment strictly inside a settle (S-Rem-5 / M7).

export {
  component, provide, track, read, setValue, register, raise, mark,
  STATES, inOrder, at, count, createTrace,
} from '../../proof/src/dsl.mjs'

// ---- step constructors (component half of ρ) ------------------------------

/** §2.2 `raiseUnless(f, x)`: lands iff the entry's cfg carries the flag. */
export const raiseUnless = (flag, message) => ({ do: 'raiseUnless', flag, message })

/** A7 extension: a track whose *inverse* reads `k` through the committed view. */
export const trackReadOnRevert = (key, tag) => ({ do: 'trackReadOnRevert', key, tag })

// ---- orchestration inputs (Λ_orch half of ρ) ------------------------------

/** `insert(π, c, cfg)`. `parent` names a previously inserted component; the
 *  ambient isolation/interception derivations in force are applied on top. */
export const insert = (name, options = {}) => ({ do: 'insert', name, ...options })

/** `retire(n)`. Refused (premise n ∈ dom F_γ) when the name has been removed. */
export const retire = (name, options = {}) => ({ do: 'retire', name, ...options })

/** `settle` — run lifecycle and removal rules to quiescence (D1 A1 reading). */
export const settle = (options = {}) => ({ do: 'settle', ...options })

/** `update(n, cfg)` — the A3 extension input (D1 §17-A3, Dev-7). */
export const update = (name, config, options = {}) => ({ do: 'update', name, config, ...options })

/** `setval(n, k, v)` — the orchestration form of the Def. 24 A_k operation. */
export const setval = (name, key, value, options = {}) => ({ do: 'setval', name, key, value, ...options })

/** `isolate(k, r)` — Def. 28/29; derives the ambient context for later inserts. */
export const isolate = (key, realm, options = {}) => ({ do: 'isolate', key, realm, ...options })

/** `intercept(k, ν)` — Def. 31; derives the ambient context for later inserts. */
export const intercept = (key, config, options = {}) => ({ do: 'intercept', key, config, ...options })

// ---- observation inputs ---------------------------------------------------

/** Read Def. 31's merged metadata at a fiber: σ(k)(d(k) ⊕_k ι(k)) with
 *  `base` supplying d(k). Recorded under `merged:<name>:<key>`. */
export const merged = (name, key, base, options = {}) => ({ do: 'merged', name, key, base, ...options })

/** External Def.-23 `get` through a fiber's context (Algorithm 6 discipline).
 *  Recorded under `extread:<name>:<key>`; a pure observation, never refused.
 *  Kept for the pre-closure entries; new scripts use `readLabel`. */
export const readVia = (name, key, options = {}) => ({ do: 'readVia', name, key, ...options })

// ---- Definition 2′: the environment read label (audit §3.6, GAP-10) -------

/**
 * `read(n, k)` — the seventh Λ_orch label. Runs Algorithm 6 from `n`'s
 * resolution context; Ψ = id_Γ and the edit is the identity, which is why it
 * adds a label without adding a row to Table 1. Its premise is
 * n ∈ dom(F_γ) ∪ {root} (occurrence A8 when it fails); it emits the same
 * rd(n,k,v) / rderr(n,k,ε) letters a `read` *step* emits.
 *
 * The harness delivers the input and records what the target did — it does
 * **not** pre-check the premise the way the O-Retire convention does (README
 * §"Harness conventions"), because A8 exists precisely to test whether the
 * target consults it.
 */
export const readLabel = (name, key, options = {}) => ({ do: 'readLabel', name, key, ...options })

// ---- audit §3.5: the anchored-input notation `at ε do λ` -------------------

const CERT_PREFIX = {
  'L-Begin': 'begin',
  'L-Leave': 'leave',
  'L-Divert': 'divert',
  'L-Raise': 'raise',
  'CO-Prov': 'provide',
}

/** `cert(r, n)` — the rule-certificate anchor of §3.5's ε ∈ E ∪ {cert(r,n)}.
 *  Only the reference model emits this channel (§5.4's vocabulary proviso). */
export const cert = (rule, name) => `${CERT_PREFIX[rule] ?? rule}:${name}`

/** `at ε do λ` — deliver λ synchronously at the first occurrence of ε during
 *  the next settle. Obligation (D-F): ε must be produced on every fair
 *  schedule of the script, so that the attempt point is determinate; the
 *  script must say why in its `anchorNote`, and `tstar.test.mjs` enforces it. */
export const atEvent = (event, action, options = {}) => ({ do: 'anchor', at: event, then: action, ...options })

// ---- harness devices ------------------------------------------------------

/** Arm `action` to run synchronously the first time `marker` is traced. */
export const pin = (marker, action, options = {}) => ({ do: 'pin', marker, then: action, ...options })

/** Record the live report under `tag` at the point this action runs. */
export const snapshot = (tag) => ({ do: 'snapshot', tag })
