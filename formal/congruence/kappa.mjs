// κ_r — the occurrence-multiset normalization of a window, computed directly
// from the model state.
//
// Letters follow `../signatures.md` §§1–14 as revised by `../alphabet-audit.md`
// §3 (the 16 new letters: D7–D12, X10, V6, W1–W6, P7, A8, and A4 lifted to
// reachable).  Unlike the explorer's α-projection (`explorer/reconcile.mjs`,
// `scratch-audit/alpha2.mjs`), which reads a certificate's field record and
// therefore CANNOT separate D3/D4, V3/V4, A3/A4, A5/A6 or S2/S3, this module
// reads the configuration and separates all of them — the finer κ is the
// stronger congruence hypothesis, and the one Appendix D's tables actually
// state.
//
// κ_r is a SET of letters (Remark 1: "κ_r(W) is a multiset and carries no
// order"; the per-item and per-key families contribute one letter per class
// regardless of how many items or keys realize the class — `alphabet-audit.md`
// §3.1.2, §8.2, §10.2).  Accumulator ORDER and LENGTH and the iterator
// POSITION are frame data of W and deliberately absent.

export const KEYS = ['k1', 'k2']

/**
 * REPAIR mode (`--repair`, or CONG_REPAIR=1) applies the one alphabet change
 * this deliverable's congruence check found to be owed, so that the check can
 * be re-run and the class seen to become singleton:
 *
 *   T4r — L-Iter over a step whose yielded inverse is a READ-ON-REVERT
 *         (Def. 48 clause 2; the A7 grammar extension), split off from T4,
 *         which the tables use for every `track`-shaped step.
 *
 * The audit letters the read-on-revert inverse everywhere it is APPLIED
 * (D11 at L-Divert, X10 at L-Raise, U8 at L-Unload) and nowhere it is MADE.
 */
export const REPAIR = process.env.CONG_REPAIR === '1' || process.argv.includes('--repair')

// ---- small readers over the model ---------------------------------------

export const outcomeClass = f => (f.outcome === null ? 'bot' : 'xi')

/** InvClass of one accumulator item (`signatures.md` §0, 5 values). */
const invClass = inv => inv.data?.kind ?? 'other'

const accClasses = f => [...new Set(f.accumulator.map(invClass))].sort()

/** dom(F_γ): the model's registry, minus what O-Remove has taken out. */
export const inRegistry = (m, f) => !!f && !f.removed && f.uid !== null && m.fibers.get(f.uid) === f

const liveFibers = m => [...m.fibers.values()].filter(f => !f.removed)

const hasChild = (m, f) => [...m.fibers.values()].some(o => !o.removed && o.parent === f)

/**
 * The realm letter owed to key k in fiber-context ctx (CO-Iso layer, §12.1):
 * S1 shared realm, S2 an isolated realm no other context names, S3 an
 * isolated realm two contexts share.
 */
function realmLetter(m, ctx, key) {
  const own = ctx.isolate[key]
  if (own === undefined) return 'S1'
  for (const other of m.fibers.values()) {
    if (other.removed || other.ctx === ctx) continue
    if (other.ctx.isolate[key] === own) return 'S3'
  }
  return 'S2'
}

/**
 * Algorithm 6's outcome AND the position at which the walk decided — the
 * PosClass the CO-Acc alphabet (§14.1) letters and the explorer's `classifyRead`
 * folds away.  Returns one of:
 *   committed-self | committed-ancestor | withdrawn
 *   inactive-declared-self | inactive-declared-ancestor
 *   undeclared-root | undeclared-isolation
 */
export function classifyReadFine(m, fiber, key) {
  let walk = fiber
  while (walk) {
    if (walk.committed?.has(key)) {
      const provider = m.fibers.get(walk.committed.get(key))
      const entry = provider?.table.get(m.labelOf(walk.ctx, key))
      if (entry) return walk === fiber ? 'committed-self' : 'committed-ancestor'
      return 'withdrawn'
    }
    if (walk.spec.inject.includes(key)) {
      return walk === fiber ? 'inactive-declared-self' : 'inactive-declared-ancestor'
    }
    if (walk.parent && m.labelOf(walk.ctx, key) !== m.labelOf(walk.parent.ctx, key)) {
      return 'undeclared-isolation'
    }
    walk = walk.parent
  }
  return 'undeclared-root'
}

const READ_LETTER = {
  'committed-self': 'A1',
  'committed-ancestor': 'A2',
  'inactive-declared-ancestor': 'A3',
  'inactive-declared-self': 'A4',
  'undeclared-root': 'A5',
  'undeclared-isolation': 'A6',
  withdrawn: 'A7',
}

/** The classifier the instrumented twin uses for the iterator's next step. */
export function classifyStep(m, fiber, step) {
  return m.classifyStep(fiber, step)
}

/** Step classes on which the iteration raises (Left(ξ)) rather than lands. */
export const RAISING = new Set(['raise', 'flag-fail', 'provide-conflict', 'setval-foreign'])

// ---- the ten rules + the four coeffect operations ------------------------

const ACC_D = { provide: 'D8', track: 'D9', retire: 'D10', rrev: 'D11' }
const ACC_X = { provide: 'X7', track: 'X8', retire: 'X9', rrev: 'X10' }
const ACC_U = { provide: 'U5', track: 'U6', retire: 'U7', rrev: 'U8' }

/**
 * κ for an O-Insert window: parent class, freshness, per-declared-key
 * disjointness, and the CO-Iso realm layer the derived context carries.
 */
export function kappaInsert(m, parentFiber, spec, ctx) {
  const L = new Set()
  L.add(!parentFiber ? 'I1' : (parentFiber.removed || parentFiber.uid === null) ? 'I3' : 'I2')
  L.add('I4') // the generator always draws a fresh name; I5 is unrealizable
  for (const key of spec.provide ?? []) {
    let conflict = false
    for (const other of m.fibers.values()) {
      if (!other.removed && (other.spec.provide ?? []).includes(key)) conflict = true
    }
    L.add(conflict ? 'I7' : 'I6')
  }
  for (const key of new Set([...(spec.provide ?? []), ...spec.inject])) {
    L.add(realmLetter(m, ctx, key))
  }
  return L
}

export function kappaRetire(m, f) {
  const L = new Set()
  if (!inRegistry(m, f)) L.add('R4')
  else if (f.state === 'inactive') L.add(f.outcome === null ? 'R1' : 'R3')
  else L.add('R2')
  return L
}

export function kappaRemove(m, f) {
  const L = new Set()
  L.add(f.retired ? 'M1' : 'M2')
  if (f.state === 'inactive') L.add(f.outcome === null ? 'M3' : 'M4')
  else L.add('M5')
  L.add(hasChild(m, f) ? 'M7' : 'M6')
  return L
}

export function kappaUpdate(m, f) {
  const L = new Set()
  if (!inRegistry(m, f)) L.add('W6')
  else if (!f.installed) L.add(f.outcome === null ? 'W2' : 'W3')
  else if (f.state === 'unloading') L.add(f.outcome === null ? 'W4' : 'W5')
  else L.add('W1')
  return L
}

export function kappaSetval(m, f, key) {
  const L = new Set()
  if (!inRegistry(m, f)) L.add('P7')
  else L.add(f.table.has(m.labelOf(f.ctx, key)) ? 'P3' : 'P4')
  return L
}

export function kappaBegin(m, f) {
  const L = new Set()
  L.add(f.outcome === null ? 'B1' : 'B2')
  L.add(f.retired ? 'B4' : 'B3')
  for (const key of f.spec.inject) L.add(m.providerOf(f.ctx, key) ? 'B5' : 'B7')
  return L
}

export function kappaIterate(m, f) {
  // Window: θ_n = Reloading, target_n(γ) = ω, and the iterator yields Just.
  const step = f.remaining[0]
  const cls = m.classifyStep(f, step)
  const L = new Set()
  if (RAISING.has(cls)) {
    L.add('X1')
    L.add({ raise: 'X2', 'flag-fail': 'X3', 'provide-conflict': 'X4', 'setval-foreign': 'X5' }[cls])
    if (cls === 'provide-conflict') L.add('P2')
    const acc = accClasses(f)
    if (!acc.length) L.add('X6')
    else for (const a of acc) L.add(ACC_X[a] ?? `X?${a}`)
    return { rule: 'L-Raise', letters: L, stepClass: cls }
  }
  L.add('T1')
  if (f.spec.inject.length) L.add('T2')
  const map = {
    'provide-fresh': 'T3', track: 'T4', 'track-rrev': REPAIR ? 'T4r' : 'T4', 'track-mutate': 'T4',
    'read-committed-self': 'T5', 'read-committed-ancestor': 'T6',
    'read-inactive-declared-p': 'T7', 'read-inactive-declared-np': 'T7',
    'read-undeclared-p': 'T8', 'read-undeclared-np': 'T8',
    'read-withdrawn': 'T5',
    'setval-own-eq': 'T9', 'setval-own-neq': 'T9',
    register: 'T10', 'flag-pass': 'T11', mark: 'T?mark',
  }
  L.add(map[cls] ?? `T?${cls}`)
  if (cls === 'provide-fresh') L.add('P1')
  if (cls.startsWith('read-committed')) L.add('P5')
  if (cls.startsWith('read-undeclared') || cls.startsWith('read-inactive')) L.add('P6')
  return { rule: 'L-Iter', letters: L, stepClass: cls }
}

export function kappaFinish(m, f) {
  const L = new Set()
  L.add(f.accumulator.length ? 'F1' : 'F2')
  if (f.spec.inject.length) L.add('F3')
  return L
}

export function kappaDivert(m, f) {
  const L = new Set()
  L.add('D1')
  if (f.stale) L.add('D7')
  else {
    const target = m.targetOf(f)
    if (target === null) L.add(f.retired ? 'D3' : 'D4')
    else L.add('D2') // per-key changed provider
  }
  L.add('D5') // the calculus's abort alternative; D6 (land) is unrealizable
  const acc = accClasses(f)
  if (!acc.length) L.add('D12')
  else for (const a of acc) L.add(ACC_D[a] ?? `D?${a}`)
  return L
}

export function kappaLeave(m, f) {
  const L = new Set()
  const target = f.stale ? Symbol.for('stale') : m.targetOf(f)
  if (!f.stale && m.sameView(target, f.committed)) { L.add('V6'); return L }
  L.add('V1')
  if (f.stale) L.add('V5')
  else if (target === null) L.add(f.retired ? 'V3' : 'V4')
  else L.add('V2')
  return L
}

export function kappaUnload(m, f) {
  const L = new Set()
  const relied = m.reliedUpon(f)
  L.add(relied ? 'U2' : 'U1')
  L.add(f.outcome === null ? 'U3' : 'U4')
  const acc = accClasses(f)
  if (!acc.length) L.add('U9')
  else for (const a of acc) L.add(ACC_U[a] ?? `U?${a}`)
  // Bookkeeping block (ζ = ⊥ only, correction C2), read off the window.
  if (!relied && f.outcome === null) {
    if (f.retired) L.add('U10')
    else L.add(m.targetOf(f) === null ? 'U11' : 'U12')
  }
  return L
}

export function kappaRead(m, f, key) {
  const L = new Set()
  if (!inRegistry(m, f)) { L.add('A8'); return L }
  const cls = classifyReadFine(m, f, key)
  L.add(READ_LETTER[cls])
  L.add(cls.startsWith('committed') ? 'P5' : 'P6')
  return L
}

// ---- window enumeration --------------------------------------------------

/**
 * Every window of every rule at a configuration.  A window is (rule, subject,
 * [operand]); the rule's own state-class premise fixes which fibers host one.
 * Blocking windows are included wherever Appendix D letters them (M2/M5/M7,
 * B2/B4/B6/B7, V6, U2) — a blocked decision is a decision.
 */
export function windows(m, opts) {
  const out = []
  const all = [...m.fibers.values()]
  const live = liveFibers(m)

  // O-Insert: the finite generator's offers (root ctx, isolated ctx, child ctx).
  for (const offer of opts.inserts ?? []) {
    out.push({ rule: 'O-Insert', kind: 'insert', offer })
  }

  for (const f of all) {
    const reg = inRegistry(m, f)
    // O-Retire / O-Update / CO-Prov setval take a name and nothing else, so
    // their windows include the absent-entry one (R4, W6, P7).
    out.push({ rule: 'O-Retire', kind: 'retire', f })
    out.push({ rule: 'O-Update', kind: 'update', f })
    out.push({ rule: 'CO-Prov', kind: 'setval', f, key: opts.setvalKey })
    for (const key of KEYS) out.push({ rule: 'CO-Acc', kind: 'read', f, key })
    if (!reg) continue

    out.push({ rule: 'O-Remove', kind: 'remove', f })

    switch (f.state) {
      case 'inactive':
        out.push({ rule: 'L-Begin', kind: 'life', f })
        break
      case 'reloading': {
        const target = f.stale ? Symbol.for('stale') : m.targetOf(f)
        if (f.stale || !m.sameView(target, f.committed)) out.push({ rule: 'L-Divert', kind: 'life', f })
        else if (f.remaining.length === 0) out.push({ rule: 'L-Finish', kind: 'life', f })
        else out.push({ rule: 'L-Iterate', kind: 'life', f })
        break
      }
      case 'active':
        out.push({ rule: 'L-Leave', kind: 'life', f })
        break
      case 'unloading':
        out.push({ rule: 'L-Unload', kind: 'life', f })
        break
    }
  }
  void live
  return out
}

/** κ of a window, plus the rule name κ predicts for the iteration window. */
export function kappaOf(m, w) {
  switch (w.rule) {
    case 'O-Insert': return { rule: 'O-Insert', letters: kappaInsert(m, w.offer.parentFiber, w.offer.spec, w.offer.ctx) }
    case 'O-Retire': return { rule: 'O-Retire', letters: kappaRetire(m, w.f) }
    case 'O-Remove': return { rule: 'O-Remove', letters: kappaRemove(m, w.f) }
    case 'O-Update': return { rule: 'O-Update', letters: kappaUpdate(m, w.f) }
    case 'CO-Prov': return { rule: 'CO-Prov', letters: kappaSetval(m, w.f, w.key) }
    case 'CO-Acc': return { rule: 'CO-Acc', letters: kappaRead(m, w.f, w.key) }
    case 'L-Begin': return { rule: 'L-Begin', letters: kappaBegin(m, w.f) }
    case 'L-Iterate': return kappaIterate(m, w.f)
    case 'L-Finish': return { rule: 'L-Finish', letters: kappaFinish(m, w.f) }
    case 'L-Divert': return { rule: 'L-Divert', letters: kappaDivert(m, w.f) }
    case 'L-Leave': return { rule: 'L-Leave', letters: kappaLeave(m, w.f) }
    case 'L-Unload': return { rule: 'L-Unload', letters: kappaUnload(m, w.f) }
    default: throw new Error(`no κ for ${w.rule}`)
  }
}
