// T* — the observation an experiment produces.
//
// §5.4 of the manuscript: a canonical experiment "drives the system, by an
// explicit orchestration script over explicit component data, to a pointed
// configuration realizing s, lets the attempt at r occur (directly for
// orchestration rules; by settling for lifecycle rules), and asserts
// ≡-equality of the implementation's outcome set with the specification's at
// that point — certificates included."
//
// This module realizes the first half: it interprets a script's Λ_orch
// program against any adapter and records the observation V_{r,s} is stated
// over. §6.3 enumerates exactly what that observation must carry:
//
//   * enablement or refusal of the attempted input, with its reason,
//   * the rule certificate,
//   * the ordinary event word, in order,
//   * the normalized successor report after settling,
//   * termination.
//
// realized here as, respectively: `refusals` / `steps[].refused`,
// `certWord`, `word`, `states` + `errors` + `store` + `storeLenient`, and the
// adapters' own settle timeout (a hang or `Diverge` fails the script, §6.3
// case (e)).
//
// **Vocabulary split.** Theorem 2 is stated for the certificate-instrumented
// vocabulary, with a proviso (§5.4, §6.3) for the certificate-erased one. The
// reference model emits rule certificates (`begin/leave/divert/raise` and the
// provision write `provide:`); a real Cordis build has no certificate channel.
// So the observation separates `word` (the ordinary events every target
// emits) from `certWord` (model-only). Cross-target ≡-comparison uses `word`;
// clauses that read `certWord` are declared `kind: 'certificate'` and are
// evaluated only where the channel exists.

const ORDINARY = /^(active|deactivated|apply|revert|read|readfail|revertread|revertreadfail|setvalue|registered|flagged|mark):/
const CERTIFICATE = /^(begin|leave|divert|raise|provide):/

/** Value rendering shared with the adapters' `read:` letters. */
function render(value) {
  if (value === undefined) return 'undefined'
  try {
    return JSON.stringify(value)
  } catch {
    return String(value)
  }
}

/** Ordinary event word: the letters every adapter emits, in order. */
export function ordinaryWord(trace) {
  return trace.filter(entry => ORDINARY.test(entry))
}

/** Rule-certificate word: emitted by the reference model only. */
export function certificateWord(trace) {
  return trace.filter(entry => CERTIFICATE.test(entry))
}

/** Normalize a refusal into the premise class it convicts. */
export function classifyRefusal(error) {
  const message = String(error?.message ?? error)
  if (error?.code === 'NO_SUCH_ENTRY') return 'NOT_REGISTERED'
  // The n ∈ dom(F_γ) premise, shared by O-Retire (R4), O-Update (W6),
  // CO-Prov's orchestration form (P7) and the read label (A8). Definition 7
  // gives one block(ϱ) per premise *schema*, so all four speak one reason.
  if (/no such entry|not in the registry|no longer registered|unknown entry|unknown name/i.test(message)) return 'NOT_REGISTERED'
  if (/already declared|already provided|provision .* already/i.test(message)) return 'PROVISION_CONFLICT'
  if (/without provide|cannot set/i.test(message)) return 'NO_OWN_BINDING'
  if (/removed fiber|INACTIVE_EFFECT|inactive context|inactive|disposed/i.test(message)) return 'PARENT_ABSENT'
  return 'REFUSED'
}

function accessCode(error) {
  const message = String(error?.message ?? error)
  if (error?.code === 'NO_SUCH_ENTRY') return 'NOT_REGISTERED'
  if (/no such entry|not in the registry|no longer registered/i.test(message)) return 'NOT_REGISTERED'
  if (error?.code) return error.code
  if (/in inactive context/.test(message)) return 'INACTIVE_ACCESS'
  if (/without inject/.test(message)) return 'UNDECLARED_ACCESS'
  return 'ERR'
}

/**
 * Interpret one canonical script against one system.
 *
 * `script.components()` is called fresh per run (adapters key plugin identity
 * off the spec object, so sharing specs across runs would leak state).
 */
export async function observe(sys, script) {
  const comps = script.components()
  const handles = Object.create(null)
  const ambient = [] // isolate/intercept derivations in force, in order
  const steps = []
  const anchors = [] // `at ε do λ` records, for the (D-F) determinacy check
  const snaps = Object.create(null)
  const extras = Object.create(null)
  const refusals = []

  const liveStates = () => {
    const out = {}
    for (const name of Object.keys(handles)) out[name] = sys.state(handles[name])
    return out
  }

  const probeKeys = script.keys ?? ['k1', 'k2']
  const probeStore = () => Object.fromEntries(probeKeys.map(k => [k, sys.readKey(k)]))
  const probeStoreLenient = () => Object.fromEntries(probeKeys.map(k => [k, sys.readKeyLenient(k)]))

  const ctxFor = (parent) => {
    let ctx = parent ? sys.childCtx(handles[parent]) : null
    for (const op of ambient) {
      ctx = op.kind === 'isolate'
        ? sys.isolateCtx(ctx, op.key, op.arg)
        : sys.interceptCtx(ctx, op.key, op.arg)
    }
    return ctx
  }

  const record = (action, pinned) => {
    const rec = {
      do: action.do,
      target: action.name ?? action.key ?? action.tag ?? null,
      tag: action.tag ?? null,
      pinned: Boolean(pinned),
      statesBefore: liveStates(),
      wordBefore: ordinaryWord(sys.trace).length,
      refused: false,
      reason: null,
    }
    steps.push(rec)
    return rec
  }

  const refuse = (rec, action, reason) => {
    rec.refused = true
    rec.reason = reason
    refusals.push({ action: action.do, target: rec.target, reason, tag: action.tag ?? null, states: rec.statesBefore })
  }

  // Synchronous actions — the only ones a `pin` may arm, since watchers run
  // inside a trace push (i.e. inside an iteration).
  const performSync = (action, rec) => {
    switch (action.do) {
      case 'retire': {
        if (rec.statesBefore[action.name] === 'disposed') {
          // O-Retire premise n ∈ dom(F_γ) fails: the name left the registry.
          refuse(rec, action, 'NOT_REGISTERED')
          return
        }
        sys.retire(handles[action.name])
        return
      }
      case 'update':
        sys.update(handles[action.name], action.config)
        return
      case 'setval':
        sys.setOwn(handles[action.name], action.key, action.value)
        return
      case 'isolate':
        ambient.push({ kind: 'isolate', key: action.key, arg: action.realm })
        return
      case 'intercept':
        ambient.push({ kind: 'intercept', key: action.key, arg: action.config })
        return
      case 'snapshot':
        // A mid-settle read of the report. `storeLenient` is the one that means
        // anything strictly inside a settle: σ_γ unions ACTIVE tables only, so a
        // binding a still-Reloading fiber has already provided is invisible to
        // the strict probe (that is B6's content) and visible to the lenient one.
        snaps[action.tag] = { states: rec.statesBefore, store: probeStore(), storeLenient: probeStoreLenient() }
        return
      case 'insert':
        handles[action.name] = sys.insert(ctxFor(action.parent ?? null), comps[action.name], action.config)
        return
      case 'merged':
        extras[`merged:${action.name}:${action.key}`] = sys.interceptMerged(handles[action.name], action.key, action.base)
        return
      case 'readVia': {
        try {
          extras[`extread:${action.name}:${action.key}`] = { ok: true, value: sys.readVia(handles[action.name], action.key) }
        } catch (error) {
          extras[`extread:${action.name}:${action.key}`] = { ok: false, code: accessCode(error) }
        }
        return
      }
      case 'readLabel': {
        // Definition 2′'s read(n,k). The premise n ∈ dom(F_γ) is NOT pre-checked
        // here (contrast `retire` above): the whole content of A8 is whether the
        // target consults it, so the input is delivered and the response
        // recorded. A refused read emits nothing; an accepted one emits the
        // rd/rderr letter of §3.6.1.
        const slot = `read:${action.name}:${action.key}`
        try {
          const value = sys.readVia(handles[action.name], action.key)
          extras[slot] = { ok: true, value }
          sys.trace.push(`read:${action.name}:${action.key}=${render(value)}`)
        } catch (error) {
          const code = accessCode(error)
          extras[slot] = { ok: false, code }
          if (code === 'NOT_REGISTERED') refuse(rec, action, 'NOT_REGISTERED')
          else sys.trace.push(`readfail:${action.name}:${action.key}:${code}`)
        }
        return
      }
      case 'pin':
        sys.trace.when(action.marker, () => {
          const inner = record(action.then, true)
          try {
            performSync(action.then, inner)
          } catch (error) {
            refuse(inner, action.then, classifyRefusal(error))
          }
          inner.wordAfter = ordinaryWord(sys.trace).length
        })
        return
      case 'anchor':
        // The audit's §3.5 `at ε do λ`. Same one-shot watcher as `pin`; the
        // difference is intent, and it is load-bearing: a `pin` steers the
        // schedule of a script whose printed ρ is quiescent-only, whereas an
        // anchor IS the printed ρ — the input belongs at a non-quiescent
        // configuration and Definition 3 clause 1 quantifies over it.
        rec.armed = action.at
        rec.fired = false
        anchors.push(rec)
        sys.trace.when(action.at, () => {
          rec.fired = true
          const inner = record(action.then, true)
          inner.anchor = action.at
          try {
            performSync(action.then, inner)
          } catch (error) {
            refuse(inner, action.then, classifyRefusal(error))
          }
          inner.wordAfter = ordinaryWord(sys.trace).length
        })
        return
      default:
        throw new Error(`unknown orchestration action: ${action.do}`)
    }
  }

  for (const action of script.program) {
    const rec = record(action, false)
    try {
      if (action.do === 'settle') await sys.settle()
      else performSync(action, rec)
    } catch (error) {
      refuse(rec, action, classifyRefusal(error))
    }
    rec.wordAfter = ordinaryWord(sys.trace).length
  }

  const trace = [...sys.trace]
  const states = liveStates()
  const errors = {}
  for (const name of Object.keys(handles)) {
    if (states[name] !== 'failed') {
      errors[name] = null
      continue
    }
    try {
      const error = await sys.error(handles[name])
      errors[name] = String(error?.message ?? error ?? '')
    } catch (error) {
      errors[name] = String(error?.message ?? error ?? '')
    }
  }

  const store = probeStore()
  const storeLenient = probeStoreLenient()

  return {
    id: script.id,
    kind: sys.kind,
    trace,
    word: ordinaryWord(trace),
    certWord: certificateWord(trace),
    states,
    errors,
    store,
    storeLenient,
    refusals,
    steps,
    snaps,
    extras,
    anchors: anchors.map(a => ({ at: a.armed, fired: a.fired })),
    /** Did the `at ε do λ` armed on ε deliver its input? (obligation (D-F)) */
    fired(event) {
      return anchors.some(a => a.armed === event && a.fired)
    },
    /** The step tagged `tag` in the program (the derivation's ★, usually). */
    at(tag) {
      return steps.find(step => step.tag === tag)
    },
    /** The mid-settle report recorded under `tag`. */
    snap(tag) {
      return snaps[tag]
    },
  }
}

/**
 * The report half of the observation — the fields §6.3 calls "the prescribed
 * normalized successor report after settling", plus refusals. This is what the
 * ≡-comparison uses on schedule-dependent scripts, where the *word* legitimately
 * varies across the specification's own fair schedules but the report does not
 * (Appendix E's per-item schedule notes).
 */
export function report(obs) {
  return {
    states: obs.states,
    errors: Object.fromEntries(Object.entries(obs.errors).map(([k, v]) => [k, v === null ? null : 'ξ'])),
    store: obs.store,
    storeLenient: obs.storeLenient,
    refusals: obs.refusals.map(r => ({ action: r.action, target: r.target, reason: r.reason })),
    extras: obs.extras,
  }
}
