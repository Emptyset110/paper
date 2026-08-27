// result_r(W) — the observable result of attempting rule r at window W.
//
// Two levels, because the paper's own Remark 1 (`../paper.md` §5) says that
// whole-rule agreement across κ-equal windows is FALSE, and says exactly why:
//
//   "κ_r(W) is a multiset and carries no order; the accumulator's composition
//    order and the iterator's position are frame data of W, consumed by
//    lift_r. ... a version claiming that κ-equal windows receive identical
//    whole-rule results would be false for windows that agree as multisets
//    but differ in accumulator order."
//
// LEVEL 1 — the per-occurrence result: the result modulo frame data.  This is
//   the hypothesis Lemma 4(1)–(2) needs and the property `alphabet-audit.md`
//   §5 layer 3 names.  Congruence MUST hold here.
// LEVEL 2 — the whole-rule result: Level 1 plus the frame (accumulator length
//   and composition order, iterator position, emission word with order and
//   multiplicity).  Splits here are Remark 1's predicted splits; they are
//   reported separately and are not counterexamples.
//
// The result is assembled in the vocabulary of Table 1 (p. 40), and no finer:
//
//   * the ABSTRACT UPDATE is the value written to each field the rule's row
//     names (columns θ^{t+1} and "control fields edited"), stated as the write
//     and not as the change — Lemma 54(5) makes τ_n ↦ ⊤ the same write whether
//     or not τ_n was already ⊤, so an idempotent re-write is not a different
//     result;
//   * the ACCUMULATOR's update is the per-occurrence write (`push(c)`,
//     `clear`, `unchanged`), never the resulting composite: composing g ∘ h is
//     lift_r's job under CF3, not the occurrence's decision;
//   * FIBERS are named by their ROLE relative to the window's subject, since
//     names are atoms compared only for equality (Lemma 56, equivariance);
//   * KEYS are named by their class in the owning fiber's declaration, and the
//     per-key families are folded to one occurrence per class (§3.1.2);
//   * VALUES are dropped outright (CF2; Lemma 2, "no premise of any row
//     inspects a value").

// ---- roles ---------------------------------------------------------------

function ancestors(f) {
  const out = new Set()
  let w = f?.parent
  while (w) { out.add(w); w = w.parent }
  return out
}

/**
 * Role vocabulary for the fibers of a configuration relative to subject n.
 * Roles are composite (a fiber can be both an ancestor and a provider), which
 * is finer than picking a priority and therefore a stronger check.
 */
export function roleTable(m, subject) {
  const roles = new Map()
  const anc = ancestors(subject)
  const provs = new Set()
  if (subject?.committed) {
    for (const uid of subject.committed.values()) {
      const p = m.fibers.get(uid)
      if (p) provs.add(p)
    }
  }
  for (const f of m.fibers.values()) {
    const tags = []
    if (f === subject) tags.push('self')
    if (anc.has(f)) tags.push('anc')
    if (subject && ancestors(f).has(subject)) tags.push('desc')
    if (provs.has(f)) tags.push('prov')
    if (subject && f !== subject && f.committed) {
      for (const uid of f.committed.values()) if (uid === subject.uid) { tags.push('dep'); break }
    }
    roles.set(f, tags.length ? tags.join('+') : 'oth')
  }
  return roles
}

// ---- the abstract image of a fiber ---------------------------------------

/**
 * The fields of Definition 44/49 that Table 1's rows write, at Table 1's
 * granularity.  `iterAt`, `accOrder` and `accLen` are the frame.
 *
 * The table σ_n is recorded as the SET of declaration-classes of the keys it
 * binds.  Every key a fiber binds is one it provides (Def. 43: dom(σ_n) ⊆ p_n),
 * so the class is always `own`; the catalog's habit of omitting `provide:[k]`
 * on shapes that call `provide(k, v)` is a generator shortcut and not a
 * distinction the calculus can make, so it is not read here.
 *
 * The committed view ω_n is recorded as the set of declaration-classes of the
 * keys it binds and NOT by the provider names it carries: names are atoms
 * (Lemma 56), and ω is compared up to the renaming χ.
 */
function absFiber(m, f) {
  return {
    st: f.removed ? 'removed' : f.state,
    ret: f.retired ? 'T' : 'F',
    out: f.outcome === null ? 'bot' : 'xi',
    inst: f.committed !== null ? 'T' : 'F',
    stale: f.stale ? 'T' : 'F',
    view: f.committed === null
      ? 'none'
      : [...new Set([...f.committed.keys()].map(k => (f.spec.inject.includes(k) ? 'd' : 'x')))].sort().join(','),
    tbl: f.table.size ? 'own' : '',
    acc: f.accumulator.map(i => i.data?.kind ?? 'other'),
    iterAt: f.remaining === null ? '-' : String(f.spec.steps.length - f.remaining.length),
  }
}

/** Absolute (assignment-shaped) fields; the write is the post value. */
const ASSIGNED = ['st', 'ret', 'out', 'inst', 'stale', 'view']

/**
 * Fields each Table-1 row writes, always reported whether or not the write
 * changed anything.  `acc` and `tbl` are reported through their edit
 * vocabulary below; the rest are reported as post values.
 */
const WRITES = {
  'O-Insert': [],                                       // writes dom(F_γ)
  'O-Retire': ['ret'],                                  // τ_n ↦ ⊤
  'O-Remove': [],                                       // writes γ \ n
  'O-Update': ['stale', 'out'],                         // entry + restart mark + ζ-clear
  'CO-Prov': [],                                        // writes a value (CF2)
  'CO-Acc': [],                                         // Ψ = id_Γ, edit = id
  'L-Begin': ['st', 'inst', 'view', 'acc'],             // θ ↦ Reloading(e_n, id_Γ, ω)
  'L-Iter': ['acc'],                                    // θ ↦ Reloading(i', g∘h, ω)
  'L-Raise': ['st', 'out', 'acc'],                      // θ ↦ Unloading(g, ω, ξ)
  'L-Finish': ['st'],                                   // θ ↦ Active(g∘h, ω)
  'L-Divert': ['st', 'stale', 'acc'],                   // θ ↦ Unloading(g∘h, ω, ⊥)
  'L-Leave': ['st', 'stale'],                           // θ ↦ Unloading(g, ω, ⊥)
  // θ ↦ Inactive(ζ), Ψ = g.  `stale` is listed because eq. 43 gives
  // Inactive(ζ) no restart-mark constituent: the write erases it.  Before the
  // D5 defect fix it did not, and that is a κ-congruence counterexample —
  // see REPORT.md §3 and `node run-congruence.mjs --tag=X` with CONG_NO_FIX=1.
  'L-Unload': ['st', 'out', 'inst', 'view', 'acc', 'stale'],
}

/** The per-occurrence write to the accumulator, independent of what g held. */
function accWrite(pre, post) {
  if (pre.length === post.length && pre.every((x, i) => x === post[i])) return 'unchanged'
  if (post.length === pre.length + 1 && pre.every((x, i) => x === post[i])) return `push(${post[post.length - 1]})`
  if (post.length === 0) return 'clear'
  return `other(${pre.join('>')}=>${post.join('>')})`
}

function tblWrite(pre, post) {
  if (pre === post) return 'unchanged'
  return post === '' ? 'withdraw' : 'bind'
}

export function absState(m, roleOf) {
  const out = new Map()
  for (const [uid, f] of m.fibers) out.set(uid, { role: roleOf(f), a: absFiber(m, f) })
  return out
}

/**
 * The abstract update: what the step wrote, named by the ROLE of the fiber it
 * landed on.  Roles come from the pre-state, so the update is described
 * relative to the window, as Table 1's fifth column is.
 */
export function absDelta(pre, post, rule, subjectUid, { frame, force, retired }) {
  const edits = []
  // A refused or blocked attempt writes nothing (Ψ = id_Γ, edit = id), so the
  // row's write column is NOT forced there — only actual changes are reported.
  const written = new Set(force ? (WRITES[rule] ?? []) : [])
  for (const [uid, after] of post) {
    const before = pre.get(uid)
    if (!before) { edits.push(`+entry(${after.role}):st=${after.a.st},ret=${after.a.ret}`); continue }
    const role = before.role
    const isSubject = uid === subjectUid
    for (const k of ASSIGNED) {
      // τ_n ↦ ⊤ is also written by the O-Retire a registration inverse yields
      // (Def. 47), at a fiber that is not the window's subject; Lemma 54(5)
      // makes that write the same whether or not τ was already ⊤.
      const force = (isSubject && written.has(k)) || (k === 'ret' && retired?.has(uid))
      if (force || before.a[k] !== after.a[k]) edits.push(`${role}.${k}=${after.a[k]}`)
    }
    const aw = accWrite(before.a.acc, after.a.acc)
    if ((isSubject && written.has('acc')) || aw !== 'unchanged') edits.push(`${role}.acc:${aw}`)
    const tw = tblWrite(before.a.tbl, after.a.tbl)
    if (tw !== 'unchanged') edits.push(`${role}.tbl:${tw}`)
    if (frame) {
      if (before.a.iterAt !== after.a.iterAt) edits.push(`${role}.iterAt:${before.a.iterAt}->${after.a.iterAt}`)
      if (before.a.acc.length !== after.a.acc.length) edits.push(`${role}.accLen:${before.a.acc.length}->${after.a.acc.length}`)
      if (before.a.acc.join('>') !== after.a.acc.join('>')) edits.push(`${role}.accOrder:${before.a.acc.join('>')}->${after.a.acc.join('>')}`)
    }
  }
  for (const [uid, before] of pre) if (!post.has(uid)) edits.push(`-entry(${before.role})`)
  edits.sort()
  return edits
}

// ---- emissions -----------------------------------------------------------

const EVENT_KEYED = new Set(['provide', 'read', 'readfail', 'revertread', 'revertreadfail', 'setvalue'])

/**
 * One trace entry, name- and value-normalized.  `apply:P:a` and `apply:P:b`
 * are the same abstract emission: the tag is a value-sort atom (CF2), and
 * WHICH tracked effect ran is frame data, not an occurrence.
 */
function absEvent(entry, nameRole) {
  const parts = String(entry).split(':')
  const kind = parts[0]
  const role = nameRole(parts[1]) ?? '?'
  if (EVENT_KEYED.has(kind)) {
    const tail = kind === 'readfail' || kind === 'revertreadfail' ? `:${parts[3] ?? ''}` : ''
    return `${kind}@${role}:k${tail}`
  }
  return `${kind}@${role}`
}

// ---- refusal reasons -----------------------------------------------------

/** Normalize a thrown error to the refusal reason Definition 3 clause 1 compares. */
export function refusalCode(error) {
  if (error?.code) return error.code
  const msg = String(error?.message ?? error)
  if (msg.startsWith('NO_SUCH_ENTRY')) return 'NO_SUCH_ENTRY'
  if (msg.startsWith('INACTIVE_EFFECT')) return 'INACTIVE_EFFECT'
  if (/^provision ".*" already declared by /.test(msg)) return 'DECLARED_CONFLICT'
  if (/^service ".*" already provided by /.test(msg)) return 'DYNAMIC_CONFLICT'
  if (/^cannot set ".*" without provide$/.test(msg)) return 'NO_OWN_BINDING'
  if (/^unknown step: /.test(msg)) return 'UNKNOWN_STEP'
  const kind = error?.constructor?.name ?? 'Error'
  // A component `raise` is the calculus's Left(ξ); anything else is a harness
  // fault and must be visible as one rather than absorbed into ξ.
  return kind === 'Error' ? 'RAISE' : `HARNESS(${kind}:${msg})`
}

// ---- assembly ------------------------------------------------------------

export function buildResult({ rule, decision, refusal, note, events, pre, post, subjectUid, nameRole, retired }) {
  const abs = events.map(e => absEvent(e, nameRole))
  const head = { d: decision, r: refusal ?? null, n: note ?? null }
  const force = decision === 'fire'
  const l1 = JSON.stringify({
    ...head,
    e: [...new Set(abs)].sort(),
    u: absDelta(pre, post, rule, subjectUid, { frame: false, force, retired }),
  })
  const l2 = JSON.stringify({
    ...head,
    e: abs,
    u: absDelta(pre, post, rule, subjectUid, { frame: true, force, retired }),
  })
  return { l1, l2 }
}
