// T* — the 60 canonical scripts ρ_{r,s}, as data.
//
// Source of truth: `../signatures.md` §§1.4–14.3 (the scripts) and
// `../derivations.md` Appendix E (the line-by-line derivation of each, with
// the pointed configuration marked ★ and the realized occurrence multiset
// stated). Every entry below records the chain the manuscript claims —
//
//     Table-1 rule  →  occurrence letter(s)  →  canonical script  →  test
//
// — in the fields `rule`, `letters`, `id`, and `source` (the Appendix E item
// and step number of the ★). Nothing here is derived from the 32-obligation
// suite of `../../proof/tests/`, which predates the theory and is not what the
// paper proves anything about.
//
// Shape of an entry:
//
//   id          D1's script id (S-Ins-1, …).
//   rule        the rule or operation family whose alphabet the script indexes.
//   letters     the *target* occurrence(s) realized at ★ (D1's §§1.3–14.3
//               reachability column). Co-realized letters are listed in
//               `alsoRealizes` and are not re-credited.
//   source      Appendix E item and ★ step, e.g. 'E.LB.B6(13)'.
//   components  () => { name: ComponentSpec } — built fresh per run.
//   program     the Λ_orch script ρ, in the vocabulary of `dsl-ext.mjs`.
//               The action realizing the ★ carries `tag: 'star'`.
//   keys        store keys the verdict reads (default k1, k2).
//   wordInvariant
//               false when Appendix E marks the *word* schedule-dependent; the
//               cross-target ≡-comparison then covers the report only and the
//               word obligations are carried by the script's own clauses
//               (obligation (D-G), §5.4). Requires `scheduleNote`.
//   scheduleNote
//               the Appendix E schedule note being cited, quoted in substance:
//               which rules are jointly enabled and why every branch reaches
//               the same report.
//   schedulePin when present: why the harness had to pin a schedule, and what
//               the printed ρ does instead. See README §"DSL extensions".
//   quiescent   false when ρ deliberately ends without a settle (its target is
//               a refusal), so the final `states` field is mid-flight and is
//               excluded from the ≡-comparison. See README finding F4.
//   note        anything a reader of the paper needs to check the entry.
//
// New entries are additive: push onto SCRIPTS (or a per-rule array) and the
// runner, the coverage report and the node:test wrapper pick them up with no
// other change. Ids must stay unique; `verdicts.mjs` keys off `id`. The full
// orchestration vocabulary of `dsl-ext.mjs` is imported here even where the
// present 60 do not use every builder (`mark`, `readVia`), because a new entry
// — for instance one indexing the *external* Def.-23 read Correction C5 says
// realizes A4 — will need them.

import {
  component, provide, track, read, setValue, register, raise, mark,
  raiseUnless, trackReadOnRevert,
  insert, retire, settle, update, setval, isolate, intercept, merged, readVia,
  readLabel, atEvent, cert,
  pin, snapshot,
} from './dsl-ext.mjs'

const SCRIPTS = []
const define = (entry) => { SCRIPTS.push(Object.freeze(entry)); return entry }

// ===========================================================================
// §1  O-Insert — Σ = {I1..I7}, reachable {I1,I2,I3,I4,I6,I7}, 4 scripts
// ===========================================================================

define({
  id: 'S-Ins-1',
  rule: 'O-Insert',
  letters: ['I1', 'I4', 'I6'],
  alsoRealizes: ['B1', 'B3', 'T1', 'T3', 'F1', 'P1', 'S1'],
  source: 'E.OI.I1(1)',
  components: () => ({ P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }) }),
  program: [insert('P', { tag: 'star' }), settle()],
})

define({
  id: 'S-Ins-2',
  rule: 'O-Insert',
  letters: ['I2'],
  alsoRealizes: ['I4', 'F2'],
  source: 'E.OI.I2(4)',
  components: () => ({ P: component('P', {}), C: component('C', {}) }),
  program: [insert('P'), settle(), insert('C', { parent: 'P', tag: 'star' }), settle()],
})

define({
  id: 'S-Ins-3',
  rule: 'O-Insert',
  letters: ['I3'],
  alsoRealizes: ['I4', 'R1', 'B4', 'M1', 'M3', 'M6'],
  source: 'E.OI.I3(5)',
  components: () => ({ P: component('P', {}), C: component('C', {}) }),
  program: [insert('P'), retire('P'), settle(), insert('C', { parent: 'P', tag: 'star' })],
  note: 'the final insert names a *removed* parent; the handle is retained so the '
    + 'attempt can be made at all — the refusal is the observation.',
})

define({
  id: 'S-Ins-4',
  rule: 'O-Insert',
  letters: ['I7'],
  alsoRealizes: ['I1', 'I4'],
  source: 'E.OI.I7(2)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    Q: component('Q', { provide: ['k1'] }),
  }),
  program: [insert('P'), insert('Q', { tag: 'star' })],
  quiescent: false,
  note: 'no settle between the inserts: the load-bearing fact (D1 §1.3) is that '
    + '*declared* provisions block, with P still Inactive(⊥).',
})

// ===========================================================================
// §2  O-Retire — Σ = {R1..R4}, all reachable, 4 scripts
// ===========================================================================

define({
  id: 'S-Ret-1',
  rule: 'O-Retire',
  letters: ['R1'],
  alsoRealizes: ['B7', 'M1', 'M3', 'M6'],
  source: 'E.OT.R1(3)',
  components: () => ({ C: component('C', { inject: ['k1'], steps: [read('k1')] }) }),
  program: [insert('C'), settle(), retire('C', { tag: 'star' }), settle()],
})

define({
  id: 'S-Ret-2',
  rule: 'O-Retire',
  letters: ['R2'],
  alsoRealizes: ['V1', 'V3', 'U1', 'U3', 'U6', 'U10', 'M1', 'M3', 'M6'],
  source: 'E.OT.R2(5)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle(), retire('P', { tag: 'star' }), settle()],
})

define({
  id: 'S-Ret-3',
  rule: 'O-Retire',
  letters: ['R3'],
  alsoRealizes: ['X1', 'X2', 'X6', 'U1', 'U4', 'U9', 'M4'],
  source: 'E.OT.R3(5)',
  components: () => ({ P: component('P', { steps: [raise('x')] }) }),
  program: [insert('P'), settle(), retire('P', { tag: 'star' }), settle()],
})

define({
  id: 'S-Ret-4',
  rule: 'O-Retire',
  letters: ['R4'],
  alsoRealizes: ['R1', 'B4', 'M1', 'M3', 'M6'],
  source: 'E.OT.R4(5)',
  components: () => ({ P: component('P', {}) }),
  program: [insert('P'), retire('P'), settle(), retire('P', { tag: 'star' })],
})

// ===========================================================================
// §3  O-Remove — Σ = {M1..M7}, all reachable, 5 scripts
// ===========================================================================

define({
  id: 'S-Rem-1',
  rule: 'O-Remove',
  letters: ['M1', 'M3', 'M6'],
  alsoRealizes: ['R1', 'B4'],
  source: 'E.OM.M1(4)',
  components: () => ({ C: component('C', { inject: ['k1'] }) }),
  program: [insert('C'), retire('C'), settle({ tag: 'star' })],
})

define({
  id: 'S-Rem-2',
  rule: 'O-Remove',
  letters: ['M2'],
  alsoRealizes: ['M5', 'M6', 'F2'],
  source: 'E.OM.M2(4)',
  components: () => ({ P: component('P', {}) }),
  program: [insert('P'), settle({ tag: 'star' })],
  note: 'the full window of the never-enabled removal is {M2, M5, M6} '
    + '(Correction C3); M2 is the credited, deciding-first-failing letter.',
})

define({
  id: 'S-Rem-3',
  rule: 'O-Remove',
  letters: ['M4'],
  alsoRealizes: ['M1', 'M6', 'R3', 'X1', 'X2', 'X6', 'U4'],
  source: 'E.OM.M4(6)',
  components: () => ({ P: component('P', { steps: [raise('x')] }) }),
  program: [insert('P'), settle(), retire('P', { tag: 'retire' }), settle({ tag: 'star' })],
})

define({
  id: 'S-Rem-4',
  rule: 'O-Remove',
  letters: ['M5'],
  alsoRealizes: ['M1', 'M6', 'V1', 'V3', 'U1', 'U3', 'U6', 'U10'],
  source: 'E.OM.M5(7)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle(), retire('P'), settle({ tag: 'star' })],
  note: 'a mid-settle blocking window; its observation is the certificate/event '
    + 'order inv(P,a) ≤ deact(P) < removal.',
})

define({
  id: 'S-Rem-5',
  rule: 'O-Remove',
  letters: ['M7'],
  alsoRealizes: ['M1', 'M3', 'M6', 'T10', 'U7', 'R2'],
  source: 'E.OM.M7(12)',
  wordInvariant: false,
  scheduleNote: 'E.OM.M7(4): after G registers C, {L-Iter @G, L-Begin @C} are both '
    + 'enabled and commute, so the interleaving of G\'s remaining steps with C\'s '
    + 'activation is free. The ★ window depends only on the final registry shape.',
  components: () => {
    const C = component('C', { steps: [track('b')] })
    return { C, G: component('G', { steps: [register(C), track('a')] }) }
  },
  program: [
    insert('G'), settle(), retire('G'),
    pin('revert:C:b', snapshot('m7')),
    settle({ tag: 'star' }),
  ],
  note: 'C is a *registered* child: it has no orchestration handle, so its report '
    + 'is observed through the word. M7 (blocked removal of a parent whose child '
    + 'is still present) is observed by the mid-settle snapshot at inv(C,b): G is '
    + 'Inactive and retired there, and must still be in the registry.',
})

// ===========================================================================
// §4  L-Begin — Σ = {B1..B7}, all reachable, 6 scripts
// ===========================================================================

define({
  id: 'S-Beg-1',
  rule: 'L-Begin',
  letters: ['B1', 'B3'],
  alsoRealizes: ['T1', 'T4', 'F1'],
  source: 'E.LB.B1(2)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Beg-2',
  rule: 'L-Begin',
  letters: ['B2'],
  alsoRealizes: ['B3', 'X1', 'X2', 'X7', 'U1', 'U4', 'U5'],
  source: 'E.LB.B2(6)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), raise('x')] }),
  }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Beg-3',
  rule: 'L-Begin',
  letters: ['B4'],
  alsoRealizes: ['B1', 'R1', 'M1', 'M3', 'M6'],
  source: 'E.LB.B4(3)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Beg-4',
  rule: 'L-Begin',
  letters: ['B5'],
  alsoRealizes: ['B1', 'B3', 'T1', 'T2', 'T5', 'F1', 'F3', 'A1', 'P5', 'N1'],
  source: 'E.LB.B5(6)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle({ tag: 'star' })],
})

define({
  id: 'S-Beg-5',
  rule: 'L-Begin',
  letters: ['B6'],
  alsoRealizes: ['B1', 'B3', 'B7', 'V1', 'V3', 'V4', 'U1', 'U2', 'U3', 'U5', 'U6', 'U9', 'U10', 'U11'],
  source: 'E.LB.B6(13)',
  wordInvariant: false,
  scheduleNote: 'E.LB.B6(11): at the second settle both L-Leave @P and L-Begin @C2 are '
    + 'enabled. B6 lives on the branch where P leaves first; on the other branch C2 '
    + 'begins, reads, and then unloads. Both are in Out(ρ) and reach the same report.',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), track('a')] }),
    C1: component('C1', { inject: ['k1'], steps: [read('k1')] }),
    C2: component('C2', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), insert('C1'), settle(),
    retire('P'), insert('C2'), settle({ tag: 'star' }),
  ],
  note: 'B6 is schedule-dependent (D1 §0 convention): it is realized on schedules '
    + 'that evaluate C2\'s begin attempt inside P\'s Unloading window. The report '
    + '(P disposed; C1, C2 pending; k1 absent) is schedule-invariant.',
})

define({
  id: 'S-Beg-6',
  rule: 'L-Begin',
  letters: ['B7'],
  alsoRealizes: ['B1', 'B3', 'M2'],
  source: 'E.LB.B7(2)',
  components: () => ({ C: component('C', { inject: ['k1'], steps: [read('k1')] }) }),
  program: [insert('C'), settle({ tag: 'star' })],
})

// ===========================================================================
// §5  L-Iter — Σ = {T1..T11}, all reachable, 8 scripts
// ===========================================================================

define({
  id: 'S-It-1',
  rule: 'L-Iter',
  letters: ['T1', 'T2', 'T4', 'T5'],
  alsoRealizes: ['B5', 'F1', 'F3', 'A1', 'P5', 'N1', 'S1'],
  source: 'E.LI.T1(7,8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [track('a'), read('k1')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-2',
  rule: 'L-Iter',
  letters: ['T3'],
  alsoRealizes: ['T1', 'P1', 'I6'],
  source: 'E.LI.T3(3)',
  components: () => ({ P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-3',
  rule: 'L-Iter',
  letters: ['T6'],
  alsoRealizes: ['T1', 'T10', 'A2', 'I2', 'F1', 'F3', 'B5'],
  source: 'E.LI.T6(10)',
  wordInvariant: false,
  scheduleNote: 'E.LI.T6(8): {L-Finish @G, L-Begin @C} are both enabled once G has '
    + 'registered C; both orders reach the ★ window, since G\'s committed view exists '
    + 'from its L-Begin on and is what C\'s read consults.',
  components: () => {
    const C = component('C', { steps: [read('k1')] })
    return {
      P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
      G: component('G', { inject: ['k1'], steps: [register(C)] }),
      C,
    }
  },
  program: [insert('P'), settle(), insert('G'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-4',
  rule: 'L-Iter',
  letters: ['T7'],
  alsoRealizes: ['T2', 'T6', 'A3', 'P6', 'I2', 'B5', 'B7', 'V1', 'V4', 'U1', 'U2', 'U3', 'U5', 'U9', 'U10', 'U11', 'F2'],
  source: 'E.LI.T7(35)',
  keys: ['k1', 'k2'],
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
    Q2: component('Q2', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
    G: component('G', { inject: ['k1'] }),
    C: component('C', { inject: ['k2'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), insert('Q'), settle(),
    insert('G'), settle(),
    insert('C', { parent: 'G' }), settle(),
    retire('P'), retire('Q'), settle(),
    insert('Q2'), settle({ tag: 'star' }),
  ],
  note: 'the subtlest reachability fact of D1 (§5.3): five components and five '
    + 'settles build a committed ancestor view, tear it down, and revive the reader '
    + 'so its read meets a *pending declarer* — Algorithm 6 line 5 at an ancestor.',
})

define({
  id: 'S-It-5',
  rule: 'L-Iter',
  letters: ['T8'],
  alsoRealizes: ['T1', 'A5', 'P6', 'F1'],
  source: 'E.LI.T8(3)',
  components: () => ({ X: component('X', { steps: [read('k1')] }) }),
  program: [insert('X'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-6',
  rule: 'L-Iter',
  letters: ['T9'],
  alsoRealizes: ['T1', 'T3', 'P3', 'F1'],
  source: 'E.LI.T9(4)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), setValue('k1', 'v2')] }),
  }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-7',
  rule: 'L-Iter',
  letters: ['T10'],
  alsoRealizes: ['T1', 'T4', 'I2', 'F1'],
  source: 'E.LI.T10(3)',
  wordInvariant: false,
  scheduleNote: 'E.LI.T10(4): {L-Finish @G, L-Begin @C} commute; the ★ precedes the '
    + 'branch.',
  components: () => {
    const C = component('C', { steps: [track('b')] })
    return { C, G: component('G', { steps: [register(C)] }) }
  },
  program: [insert('G'), settle({ tag: 'star' })],
})

define({
  id: 'S-It-8',
  rule: 'L-Iter',
  letters: ['T11'],
  alsoRealizes: ['T1', 'F1'],
  source: 'E.LI.T11(3)',
  components: () => ({ P: component('P', { steps: [raiseUnless('f', 'x')] }) }),
  program: [insert('P', { config: { f: true }, tag: 'star' }), settle()],
})

// ===========================================================================
// §6  L-Finish — Σ = {F1, F2, F3}, all reachable, 3 scripts
// ===========================================================================

define({
  id: 'S-Fin-1',
  rule: 'L-Finish',
  letters: ['F1'],
  alsoRealizes: ['B1', 'B3', 'T1', 'T4'],
  source: 'E.LF.F1(4)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Fin-2',
  rule: 'L-Finish',
  letters: ['F2'],
  alsoRealizes: ['B1', 'B3', 'M2'],
  source: 'E.LF.F2(3)',
  components: () => ({ P: component('P', {}) }),
  program: [insert('P'), settle({ tag: 'star' })],
  note: 'the degenerate 𝔈_Γ case of p. 36: the first iterator application already '
    + 'yields Nothing. The observation separating F2 from F1 is the *absence* of '
    + 'any app event before act(P).',
})

define({
  id: 'S-Fin-3',
  rule: 'L-Finish',
  letters: ['F3'],
  alsoRealizes: ['F1', 'B5', 'T5', 'A1'],
  source: 'E.LF.F3(8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle({ tag: 'star' })],
})

// ===========================================================================
// §7  L-Divert — Σ = {D1..D6}, reachable {D1, D3, D4, D5}, 2 scripts
//     (S-Div-2 withdrawn by the A10 unreachability argument, E.U.3)
// ===========================================================================

define({
  id: 'S-Div-1',
  rule: 'L-Divert',
  letters: ['D1', 'D4', 'D5'],
  alsoRealizes: ['B5', 'T2', 'T4', 'V1', 'V3', 'U1', 'U2', 'U3', 'U5', 'U6', 'U10', 'U11'],
  source: 'E.LD.D1(10)',
  wordInvariant: false,
  scheduleNote: 'E.LD.D1(6): three word classes are in Out(ρ) — C never begins; C '
    + 'begins and diverts (the canonical one); C finishes both tracks and then leaves. '
    + 'All quiesce at {P disposed, C pending}.',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [track('a'), track('b')] }),
  }),
  program: [
    insert('P'), settle(), insert('C'),
    pin('apply:C:a', retire('P')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'D1\'s printed ρ is `insert(root,P); settle; insert(root,C); retire(P); settle`, '
    + 'and Appendix E marks the D-occurrences schedule-dependent: the canonical schedule '
    + 'begins C, iterates once, and only then leaves P. The reference model\'s FIFO '
    + 'strategy takes branch (a) instead (P leaves before C ever begins), realizing no '
    + 'L-Divert window at all. The harness therefore arms retire(P) at the marker '
    + 'app(C,a), which places τ_P ↦ ⊤ at exactly the iteration boundary the canonical '
    + 'schedule uses. The pointed configuration and its window {D1, D4(k1), D5} are '
    + 'unchanged: the L-Divert premises read C\'s state and σ_γ, not when τ_P flipped.',
})

define({
  id: 'S-Div-3',
  rule: 'L-Divert',
  letters: ['D3'],
  alsoRealizes: ['D1', 'D5', 'T10', 'U7', 'M7', 'V1', 'V3', 'V4', 'B5', 'I6'],
  source: 'E.LD.D3(30)',
  wordInvariant: false,
  scheduleNote: 'E.LD.D3(22): D3 exists only on schedules where G\'s unload lands while '
    + 'C is Reloading. On the others C is retired while Inactive and never re-begins, or '
    + 'finishes first and leaves by V3. Every branch reaches the same report.',
  keys: ['k1', 'k2'],
  components: () => {
    const C = component('C', { inject: ['k2'], steps: [track('b'), track('c')] })
    return {
      Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
      Q2: component('Q2', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
      G: component('G', { steps: [register(C), track('a')] }),
      C,
    }
  },
  program: [
    insert('Q'), insert('G'), settle(),
    retire('Q'), settle(),
    insert('Q2'),
    pin('apply:C:b', retire('G')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'D1\'s ρ′ (the C1-corrected script) is `insert(root,Q); insert(root,G); '
    + 'settle; retire(Q); settle; insert(root,Q2); retire(G); settle`, with D3 realized '
    + 'only on schedules where G\'s unload lands while C is Reloading. Under FIFO the '
    + 'model leaves G first, retires C while it is still Inactive(⊥), and never reaches '
    + 'an L-Divert window — the branch `explorer-report.md` §11.6 also records. The '
    + 'harness arms retire(G) at app(C,b), i.e. after C has re-begun under Q2 and taken '
    + 'one iteration, which is step (27) of E.LD.D3 exactly.',
  note: 'C is a registered child: no orchestration handle, observed through the word.',
})

// ===========================================================================
// §8  L-Raise — Σ = {X1..X9}, all reachable, 7 scripts
// ===========================================================================

define({
  id: 'S-Rai-1',
  rule: 'L-Raise',
  letters: ['X1', 'X2', 'X6'],
  alsoRealizes: ['B1', 'B3', 'U1', 'U4', 'U9', 'B2'],
  source: 'E.LR.X1(3)',
  components: () => ({ P: component('P', { steps: [raise('x')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Rai-2',
  rule: 'L-Raise',
  letters: ['X3'],
  alsoRealizes: ['X1', 'X6', 'U1', 'U4', 'U9'],
  source: 'E.LR.X3(3)',
  components: () => ({ P: component('P', { steps: [raiseUnless('f', 'x')] }) }),
  program: [insert('P', { config: {} }), settle({ tag: 'star' })],
  note: 'the cfg={f} twin is S-It-8 (T11); the pair pins the flag test.',
})

define({
  id: 'S-Rai-3',
  rule: 'L-Raise',
  letters: ['X4'],
  alsoRealizes: ['X1', 'X6', 'P2', 'S3', 'U1', 'U4', 'U9', 'I6'],
  source: 'E.LR.X4(9)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
  }),
  program: [
    isolate('k1', 'r1'), isolate('k2', 'r1'),
    insert('P'), settle(),
    insert('Q'), settle({ tag: 'star' }),
  ],
  note: 'the A4 gap: O-Insert\'s premise is key-level ({k2} ∩ {k1} = ∅ passes), so the '
    + 'label-level collision at the joined realm r1 surfaces dynamically as Def. 23\'s '
    + 'set precondition failing — an ordinary raise at the offender. Both bindings live '
    + 'at r1, outside the root realm, so the *store* probe at root sees neither; the '
    + 'observation is that Q fails and P is untouched.',
})

define({
  id: 'S-Rai-4',
  rule: 'L-Raise',
  letters: ['X5'],
  alsoRealizes: ['X1', 'X6', 'P4', 'U1', 'U4', 'U9'],
  source: 'E.LR.X5(3)',
  components: () => ({ P: component('P', { steps: [setValue('k1', 'v2')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Rai-5',
  rule: 'L-Raise',
  letters: ['X7'],
  alsoRealizes: ['X1', 'X2', 'U1', 'U4', 'U5', 'B2'],
  source: 'E.LR.X7(4)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), raise('x')] }),
  }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Rai-6',
  rule: 'L-Raise',
  letters: ['X8'],
  alsoRealizes: ['X1', 'X2', 'U1', 'U4', 'U6', 'T4'],
  source: 'E.LR.X8(4)',
  components: () => ({ P: component('P', { steps: [track('a'), raise('x')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Rai-7',
  rule: 'L-Raise',
  letters: ['X9'],
  alsoRealizes: ['X1', 'X2', 'T10', 'U1', 'U4', 'U7', 'I2', 'R1', 'B4', 'M1', 'M3', 'M6'],
  source: 'E.LR.X9(4)',
  wordInvariant: false,
  scheduleNote: 'E.LR.X9(4): the ★ window is schedule-INVARIANT — the X-alphabet reads '
    + 'G\'s iterator and accumulator only — but the word is not, since C may or may not '
    + 'have activated before G raises.',
  components: () => {
    const C = component('C', { steps: [track('b')] })
    return { C, G: component('G', { steps: [register(C), raise('x')] }) }
  },
  program: [insert('G'), settle({ tag: 'star' })],
  note: 'the ★ window is schedule-INVARIANT (the X-alphabet reads G\'s iterator and '
    + 'accumulator only), but the *word* is not: C may or may not have activated '
    + 'before G raises. The report (G failed, C gone) is invariant.',
})

// ===========================================================================
// §9  L-Leave — Σ = {V1..V5}, reachable {V1, V3, V4, V5}, 3 scripts
//     (V2 unrealizable by the A10 argument, E.U.4)
// ===========================================================================

define({
  id: 'S-Lea-1',
  rule: 'L-Leave',
  letters: ['V1', 'V3'],
  alsoRealizes: ['R2', 'U1', 'U3', 'U6', 'U10', 'M1', 'M3', 'M6'],
  source: 'E.LL.V1(6)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Lea-2',
  rule: 'L-Leave',
  letters: ['V4'],
  alsoRealizes: ['V1', 'V3', 'U1', 'U2', 'U3', 'U5', 'U6', 'U10', 'U11', 'B5', 'T5', 'A1'],
  source: 'E.LL.V4(12)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), track('a')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Lea-3',
  rule: 'L-Leave',
  letters: ['V5'],
  alsoRealizes: ['V1', 'U1', 'U3', 'U6', 'U12', 'B1', 'B3', 'T4', 'F1'],
  source: 'E.LL.V5(6)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [insert('P'), settle(), update('P', { round: 2 }, { tag: 'star' }), settle()],
  note: 'the A3 extension: Λ_orch\'s update(n,cfg) has no Table-1 rule and is realized '
    + 'as a forced target divergence. The observation is the full bounce '
    + 'inv(P,a) < app(P,a) with two act(P) events.',
})

// ===========================================================================
// §10  L-Unload — Σ = {U1..U12}, all reachable, 9 scripts
// ===========================================================================

define({
  id: 'S-Unl-1',
  rule: 'L-Unload',
  letters: ['U1', 'U3', 'U6', 'U10'],
  alsoRealizes: ['V1', 'V3', 'R2', 'M1', 'M3', 'M6'],
  source: 'E.LU.U1(9)',
  components: () => ({ P: component('P', { steps: [track('a'), track('b'), track('c')] }) }),
  program: [insert('P'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Unl-2',
  rule: 'L-Unload',
  letters: ['U2'],
  alsoRealizes: ['U1', 'U3', 'U5', 'U6', 'U10', 'U11', 'V1', 'V3', 'V4', 'B5', 'T5', 'A1'],
  source: 'E.LU.U2(13)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), track('a')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), track('b')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Unl-3',
  rule: 'L-Unload',
  letters: ['U4'],
  alsoRealizes: ['U1', 'U6', 'X1', 'X2', 'X8', 'B2'],
  source: 'E.LU.U4(5)',
  components: () => ({ P: component('P', { steps: [track('a'), raise('x')] }) }),
  program: [insert('P'), settle({ tag: 'star' })],
  note: 'window {U1, U4, U6} and NO bookkeeping letter although τ=⊥ and the post-target '
    + 'is satisfiable — U10–U12 are conditioned on ζ=⊥ (Correction C2).',
})

define({
  id: 'S-Unl-4',
  rule: 'L-Unload',
  letters: ['U5'],
  alsoRealizes: ['U1', 'U3', 'U10', 'V1', 'V3', 'R2', 'T3', 'P1'],
  source: 'E.LU.U5(7)',
  components: () => ({ P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }) }),
  program: [insert('P'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Unl-5',
  rule: 'L-Unload',
  letters: ['U7'],
  alsoRealizes: ['U1', 'U3', 'U6', 'U10', 'M7', 'T10', 'V1', 'V3', 'R2'],
  source: 'E.LU.U7(10)',
  wordInvariant: false,
  scheduleNote: 'steps (1)-(7) are E.LI.T10(1)-(7) verbatim, carrying its schedule '
    + 'note: the child\'s activation may interleave with the parent\'s L-Finish.',
  components: () => {
    const C = component('C', { steps: [track('b')] })
    return { C, G: component('G', { steps: [register(C)] }) }
  },
  program: [insert('G'), settle(), retire('G'), settle({ tag: 'star' })],
  note: 'the register⁻¹ item performs Def. 47\'s O-Retire of the child; the child is '
    + 'reached "one level at a time" (p. 32), so deact(G) precedes inv(C,b).',
})

define({
  id: 'S-Unl-6',
  rule: 'L-Unload',
  letters: ['U8'],
  alsoRealizes: ['U1', 'U2', 'U3', 'U5', 'U10', 'U11', 'V1', 'V3', 'V4', 'B5', 'T5', 'A1'],
  source: 'E.LU.U8(14)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), trackReadOnRevert('k1', 'a')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle(), retire('P'), settle({ tag: 'star' })],
  note: 'realized in the A7-extended grammar only (D1 §10.3/§17-A7): §2.2 has no step '
    + 'constructor whose inverse reads, though Def. 48 clause 2 licenses one and this '
    + 'is exactly Thm. 63\'s content.',
})

define({
  id: 'S-Unl-7',
  rule: 'L-Unload',
  letters: ['U9'],
  alsoRealizes: ['U1', 'U3', 'U10', 'V1', 'V3', 'R2', 'F2', 'M1', 'M3', 'M6'],
  source: 'E.LU.U9(6)',
  components: () => ({ P: component('P', {}) }),
  program: [insert('P'), settle(), retire('P'), settle({ tag: 'star' })],
})

define({
  id: 'S-Unl-8',
  rule: 'L-Unload',
  letters: ['U11'],
  alsoRealizes: ['U1', 'U3', 'U6', 'U2', 'U5', 'U10', 'V1', 'V3', 'V4'],
  source: 'E.LU.U11(14)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), track('a')] }),
  }),
  program: [insert('P'), settle(), insert('C'), settle(), retire('P'), settle({ tag: 'star' })],
  note: 'shares S-Lea-2\'s ρ; the pointed rule and letter differ. The observation '
    + 'separating U11 from U12 is that NO re-begin certificate follows deact(C).',
})

define({
  id: 'S-Unl-9',
  rule: 'L-Unload',
  letters: ['U12'],
  alsoRealizes: ['U1', 'U3', 'U6', 'V1', 'V5', 'B5', 'T2', 'T4', 'F1', 'F3'],
  source: 'E.LU.U12(11)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [track('a')] }),
  }),
  program: [
    insert('P'), settle(), insert('C'), settle(),
    update('C', { round: 2 }), settle({ tag: 'star' }),
  ],
  note: 'D1\'s corrected ρ′ (editorial fix E1b): the first release reached U12 through a '
    + 'provider-replacement attempt that cannot realize it, because P2\'s insert follows '
    + 'the settle and C is already Inactive when P2 activates (a U11 window).',
})

// ===========================================================================
// §11  CO-Prov (Def. 23/24) — Σ = {P1..P6}, all reachable, 2 NEW scripts
//      P1 = S-It-2, P2 = S-Rai-3, P5 = S-It-1, P6 = S-It-5/S-It-4 (shared)
// ===========================================================================

define({
  id: 'S-Prov-1',
  rule: 'CO-Prov',
  letters: ['P3'],
  alsoRealizes: ['P1', 'T3'],
  source: 'E.CP.P3(5)',
  components: () => ({ P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }) }),
  program: [insert('P'), settle(), setval('P', 'k1', 'v2', { tag: 'star' }), settle()],
  note: 'the orchestration form of the Def. 24 A_k operation. The overwrite is '
    + 'episode-invisible (the A3/PB-2 reading D1 adopts from the model, flagged as the '
    + 'model\'s choice and not the paper\'s theorem).',
})

define({
  id: 'S-Prov-2',
  rule: 'CO-Prov',
  letters: ['P4'],
  alsoRealizes: ['F2'],
  source: 'E.CP.P4(4)',
  components: () => ({ P: component('P', {}) }),
  program: [insert('P'), settle(), setval('P', 'k1', 'v1', { tag: 'star' })],
})

// ===========================================================================
// §12  CO-Iso (Def. 28/29) — Σ = {S1..S4}, all reachable, 3 NEW scripts
//      S1 = every isolate-free script; S3's negative form = S-Rai-3
// ===========================================================================

define({
  id: 'S-Iso-1',
  rule: 'CO-Iso',
  letters: ['S2'],
  alsoRealizes: ['B1', 'B3', 'B7'],
  source: 'E.CS.S2(7)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [insert('P'), settle(), isolate('k1', 'r1'), insert('C'), settle({ tag: 'star' })],
  note: 'the Λ_orch isolate derives the ambient context for SUBSEQUENT inserts, so P '
    + 'resolves k1 at the shared realm and C at r1, where nothing provides.',
})

define({
  id: 'S-Iso-2',
  rule: 'CO-Iso',
  letters: ['S3'],
  alsoRealizes: ['B5', 'T5', 'A1', 'F3'],
  source: 'E.CS.S3(8)',
  keys: ['k1', 'k2'],
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k2'], steps: [read('k2')] }),
  }),
  program: [
    isolate('k1', 'r1'), isolate('k2', 'r1'),
    insert('P'), settle(),
    insert('C'), settle({ tag: 'star' }),
  ],
  note: 'C\'s declared k2 is satisfied through P\'s *different* key k1 at the shared '
    + 'realm r1 — Def. 28\'s transport, pinned against S-Iso-1\'s distinct-realm twin.',
})

define({
  id: 'S-Iso-3',
  rule: 'CO-Iso',
  letters: ['S4'],
  alsoRealizes: ['B1', 'B3', 'B7'],
  source: 'E.CS.S4(2)',
  components: () => ({ C: component('C', { inject: ['k1'], steps: [read('k1')] }) }),
  program: [
    isolate('k1', 'r1'), isolate('k1', 'r2', { tag: 'star' }),
    insert('C'), settle(),
  ],
  note: 'Def. 29 has NO precondition: an already-isolated key is reassigned, not '
    + 'refused. See verdicts.mjs for the half of D1 §12.3\'s stated verdict that this ρ '
    + 'cannot observe (finding F3 in README).',
})

// ===========================================================================
// §13  CO-Int (Def. 31) — Σ = {N1..N4}, all reachable, 3 NEW scripts
//      N1 = every intercept-free read (S-It-1)
// ===========================================================================

define({
  id: 'S-Int-2',
  rule: 'CO-Int',
  letters: ['N2'],
  alsoRealizes: ['B5', 'T5', 'A1'],
  source: 'E.CN.N2(8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), settle(),
    intercept('k1', { a: 1, b: 1 }),
    insert('C'), settle(),
    merged('C', 'k1', { base: true }, { tag: 'star' }),
  ],
  note: 'Def. 31\'s get evaluates σ(k)(d(k) ⊕_k ι(k)). The adapters expose that merge '
    + 'directly (`interceptMerged`), with d(k) supplied as the base argument; here '
    + 'd(k1) = ε, so MetaPat = context-only.',
})

define({
  id: 'S-Int-3',
  rule: 'CO-Int',
  letters: ['N3'],
  alsoRealizes: ['B5', 'T5', 'A1'],
  source: 'E.CN.N3(8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), settle(),
    intercept('k1', { b: 1, c: 1 }),
    insert('C', { config: { k1: { a: 2, b: 2 } } }), settle(),
    merged('C', 'k1', { a: 2, b: 2 }, { tag: 'star' }),
  ],
  note: 'both sides present: ⊕_k is right-biased, so on the overlapping field b the '
    + 'context entry wins and the disjoint fields merge.',
})

define({
  id: 'S-Int-4',
  rule: 'CO-Int',
  letters: ['N4'],
  alsoRealizes: ['B5', 'T5', 'A1'],
  source: 'E.CN.N4(8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), settle(),
    intercept('k1', { b: 1, c: 1 }),
    intercept('k1', { b: 2, d: 2 }),
    insert('C'), settle(),
    merged('C', 'k1', { a: 0 }, { tag: 'star' }),
  ],
  note: 'two nested context entries; right-bias makes the nearer/later one win the '
    + 'overlapping field — this is the experiment that kills `intercept-outer-wins`.',
})

// ===========================================================================
// §14  CO-Acc (Algorithm 6) — Σ = {A1..A7}, reachable {A1,A2,A3,A5,A6}, 1 NEW
//      A1 = S-It-1, A2 = S-It-3, A3 = S-It-4, A5 = S-It-5 (shared)
//      A4 unrealizable in-lifecycle (E.U.5, Correction C5); A7 spec-unreachable (E.U.6)
// ===========================================================================

define({
  id: 'S-Acc-1',
  rule: 'CO-Acc',
  letters: ['A6'],
  alsoRealizes: ['T1', 'T8', 'I2', 'B5', 'F1', 'F2', 'F3'],
  source: 'E.CA.A6(11)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    G: component('G', { inject: ['k1'] }),
    C: component('C', { steps: [read('k1')] }),
  }),
  program: [
    insert('P'), insert('G'), settle(),
    isolate('k1', 'r1'),
    insert('C', { parent: 'G' }), settle({ tag: 'star' }),
  ],
  note: 'the boundary must fall BETWEEN C and its parent: C is orchestrator-inserted '
    + 'under G after the isolate, so C resolves k1 at r1 while G resolves it at the '
    + 'shared realm. The walk stops at the mismatch and yields UD although G\'s '
    + 'committed view binds k1 and would otherwise have authorized the access '
    + '(contrast S-It-3\'s T6).',
})

// ===========================================================================
// §15  The alphabet-audit closure (`../alphabet-audit.md`, deliverable D5):
//      15 new canonical scripts, 16 new letters, one new alphabet Σ_O-Update.
//      92/86/60 → 108/103/75.
//
//      Traceability is the audit's §3 rather than Appendix E, because these
//      derivations were written there; `source` cites the audit section and
//      the derivation's own script name. A later integration pass folds §3
//      into Appendix D/E and the citations move with it.
// ===========================================================================

// ---- §15.1  L-Divert: D7 (GAP-1) and D8–D12 (GAP-2) -----------------------

define({
  id: 'S-Div-4',
  rule: 'L-Divert',
  letters: ['D7', 'D9', 'D12'],
  alsoRealizes: ['D1', 'D5', 'W1', 'T4', 'F1', 'B1', 'B3', 'U1', 'U3', 'U6', 'U9', 'U12'],
  source: 'D5 §3.1.4 (S-Div-4 + S-Div-4b, one experiment with two verdict clauses)',
  anchorNote: 'Both anchors are events P emits on every fair schedule: P is the only fiber, so '
    + 'no other rule competes and the attempt point is determinate — obligation (D-F), the '
    + 'audit\'s §3.5 correctness obligation for the `at ε do λ` form.',
  components: () => ({
    P: component('P', { steps: [mark('mark:P:m0'), track('a'), track('b')] }),
  }),
  program: [
    insert('P'),
    atEvent('mark:P:m0', update('P', { round: 2 }, { tag: 'star-empty' })),
    atEvent('apply:P:a', update('P', { round: 3 }, { tag: 'star-track' })),
    settle({ tag: 'star' }),
  ],
  note: 'GAP-1: `update(n,cfg)` forces a divergence at a RELOADING fiber — a third divergence '
    + 'trigger beside ⊥-target and changed-provider, which Appendix D letters at L-Leave (V5) '
    + 'and not at L-Divert. The audit prints two scripts, S-Div-4 (D7 with D9) and S-Div-4b '
    + '(D7 with D12), and counts them as ONE canonical experiment with two verdict clauses '
    + '(§3.1.4 "Counting convention"). They are run here as one ρ with two anchored updates: '
    + 'the first lands at P\'s first iteration boundary, where g = id_Γ (D12); the second lands '
    + 'in the re-begun episode after track(a), where g = track⁻¹ (D9). The `mark` step is the '
    + 'audit\'s cert(L-Begin,P) anchor rendered in the ORDINARY vocabulary so the experiment is '
    + 'presentable on a certificate-erased build; §2.2 item 3 excludes the mark class as an '
    + 'artifact precisely because it changes no field, so the accumulator at the first divert '
    + 'is still id_Γ.',
})

define({
  id: 'S-Div-5',
  rule: 'L-Divert',
  letters: ['D8', 'D9'],
  alsoRealizes: ['D1', 'D4', 'D5', 'B5', 'T2', 'T3', 'T4', 'P1', 'I6', 'V1', 'V3', 'U1', 'U2', 'U3', 'U5', 'U6', 'U10', 'U11'],
  source: 'D5 §3.1.4 (S-Div-5)',
  keys: ['k1', 'k2'],
  wordInvariant: false,
  scheduleNote: 'D5 §3.1.4: "the mechanism is S-Div-1\'s — at the second settle both C\'s '
    + 'L-Begin and Q\'s L-Leave are enabled, and the occurrence lies on the branch that begins '
    + 'C first." Every branch quiesces at {Q disposed, C pending, k1 absent}; the branches are '
    + 'enumerated exhaustively in `../scratch-audit/verify-divert.mjs`.',
  components: () => ({
    Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
    C: component('C', {
      inject: ['k2'], provide: ['k1'],
      steps: [provide('k1', 'v1'), track('a'), track('b')],
    }),
  }),
  program: [
    insert('Q'), settle(), insert('C'),
    pin('apply:C:a', retire('Q')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'The audit\'s ρ is `insert(root,Q); settle; insert(root,C); retire(Q); settle`, '
    + 'with the occurrence on the branch that begins C first. Under FIFO the reference model '
    + 'takes the other branch (Q leaves before C begins) and reaches no L-Divert window at all '
    + '— the same branch S-Div-1 has to pin. The harness therefore arms retire(Q) at app(C,a), '
    + 'i.e. after both provide(k1,v1) and track(a) have landed, which is exactly the pointed '
    + 'configuration of the derivation: g = track⁻¹ ∘ provide⁻¹. The L-Divert premises read '
    + 'C\'s state and σ_γ, not when τ_Q flipped.',
})

define({
  id: 'S-Div-6',
  rule: 'L-Divert',
  letters: ['D10'],
  alsoRealizes: ['D1', 'D4', 'D5', 'B5', 'T2', 'T10', 'I2', 'V1', 'V3', 'U1', 'U3', 'U6', 'U10'],
  source: 'D5 §3.1.4 (S-Div-6)',
  keys: ['k1', 'k2'],
  wordInvariant: false,
  scheduleNote: 'as S-Div-5: {L-Begin @G, L-Leave @Q} are jointly enabled at the second settle '
    + 'and the occurrence lies on the branch that begins G first.',
  components: () => {
    const K = component('K', { steps: [track('kk')] })
    return {
      Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
      G: component('G', { inject: ['k2'], steps: [register(K), track('g1')] }),
      K,
    }
  },
  program: [
    insert('Q'), settle(), insert('G'),
    pin('registered:G:K', retire('Q')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'as S-Div-5; the marker is G\'s registration rather than its track, so that the '
    + 'accumulator at the divert is register⁻¹ ALONE — the audit\'s window '
    + '{D1, D4(k2), D5, D10}, with G\'s first landed step being Def. 47\'s registration (T10).',
  note: 'the letter with teeth (D5 §3.1.4): L-Unload\'s application of register⁻¹ performs '
    + 'O-Retire(K), so the child registered by the host does NOT survive the host\'s aborted '
    + 'episode. Under `divert-skips-recovery` the same run leaves K Active — an orphan child '
    + 'outliving the episode that registered it. K has no orchestration handle, so it is '
    + 'observed through the word.',
})

define({
  id: 'S-Div-7',
  rule: 'L-Divert',
  letters: ['D11'],
  alsoRealizes: ['D1', 'D4', 'D5', 'B5', 'T2', 'T5', 'A1', 'V1', 'V3', 'U1', 'U3', 'U6', 'U10'],
  source: 'D5 §3.1.4 (S-Div-7)',
  keys: ['k1', 'k2'],
  wordInvariant: false,
  scheduleNote: 'as S-Div-5.',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
    C: component('C', {
      inject: ['k1', 'k2'],
      steps: [read('k1'), trackReadOnRevert('k1', 'a'), track('b')],
    }),
  }),
  program: [
    insert('P'), insert('Q'), settle(), insert('C'),
    pin('apply:C:a', retire('Q')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'as S-Div-5, armed at app(C,a) so that the read-on-revert inverse is in g when '
    + 'the divergence arrives.',
  note: 'the A7 grammar extension again (as S-Unl-6/U8): the teardown inverse READS its '
    + 'committed key during the DIVERTED teardown — Thm. 63\'s promise at the divert entry, '
    + 'the counterpart of S-Unl-6 at the leave entry.',
})

define({
  id: 'S-Div-8',
  rule: 'L-Divert',
  letters: ['D12'],
  alsoRealizes: ['D1', 'D4', 'D5', 'B5', 'T2', 'V1', 'V3', 'U1', 'U3', 'U6', 'U9', 'U10'],
  source: 'D5 §3.1.4 (S-Div-8)',
  keys: ['k1', 'k2'],
  wordInvariant: false,
  scheduleNote: 'as S-Div-5, on the branch where C\'s L-Begin fires and Q\'s L-Leave fires '
    + 'immediately after, so that C\'s very first post-begin window is already divergent.',
  components: () => ({
    Q: component('Q', { provide: ['k2'], steps: [provide('k2', 'v2')] }),
    C: component('C', { inject: ['k2'], steps: [mark('mark:C:m0'), track('a'), track('b')] }),
  }),
  program: [
    insert('Q'), settle(), insert('C'),
    pin('mark:C:m0', retire('Q')),
    settle({ tag: 'star' }),
  ],
  schedulePin: 'as S-Div-5. The marker must fall BEFORE any lettered step lands, since D12 is '
    + 'the empty-accumulator marker; the audit\'s printed ρ relies on the schedule alone. The '
    + 'harness gives C a leading `mark` step — §2.2 item 3 of the audit excludes that class as '
    + 'an artifact ("changes no field, satisfies no premise") and both adapters give it an '
    + 'identity inverse, so g = id_Γ at the divert exactly as the derivation requires.',
  note: 'the distinguishing subword is begin:C followed by divert:C, deact(C) with NO inv '
    + 'event between them, and C quiescing pending having applied nothing.',
})

// ---- §15.2  L-Raise: X10 (GAP-9) ------------------------------------------

define({
  id: 'S-Rai-8',
  rule: 'L-Raise',
  letters: ['X10'],
  alsoRealizes: ['X1', 'X2', 'B5', 'T5', 'A1', 'P5', 'U1', 'U4', 'U8', 'B2'],
  source: 'D5 §3.2.4 (S-Rai-8)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', {
      inject: ['k1'],
      steps: [read('k1'), trackReadOnRevert('k1', 'a'), raise('x')],
    }),
  }),
  program: [insert('P'), settle(), insert('C'), settle({ tag: 'star' })],
  note: 'GAP-9: InvClass has five values and L-Unload letters all five (U5–U9) while L-Raise '
    + 'lettered four (X6–X9). X10 is the missing read-on-revert item at a raise — at exactly '
    + 'U8\'s epistemic grade (real in Def. 48 clause 2, inexpressible in §2.2\'s printed step '
    + 'grammar, ambiguity A7).',
})

// ---- §15.3  L-Leave: V6 (GAP-8) -------------------------------------------

define({
  id: 'S-Lea-4',
  rule: 'L-Leave',
  letters: ['V6'],
  alsoRealizes: ['B5', 'T4', 'T5', 'A1', 'F1', 'F3', 'P1', 'P5'],
  source: 'D5 §3.3.4 (S-Lea-4)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), track('a')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), track('b')] }),
  }),
  program: [insert('P'), insert('C'), settle(), settle({ tag: 'star' })],
  note: 'GAP-8: the BLOCKING window of L-Leave. Appendix D letters the blocking valuation of '
    + 'every other row that has a reachable one (M2/M5/M7, B2/B4/B6/B7, U2); at Active with a '
    + 'stable view no rule fires at all, and every quiescent configuration containing an Active '
    + 'fiber realizes it (eq. 45\'s second clause read as a window). The experiment is the '
    + 'second settle: an implementation whose f^I_{L-Leave} passes on a stable window emits a '
    + 'spurious bounce, and nothing in the pre-closure alphabet indexed an experiment against '
    + 'it.',
})

// ---- §15.4  O-Update: W1–W6, a new alphabet (GAP-3/4/5/6/7) ---------------

define({
  id: 'S-Upd-1',
  rule: 'O-Update',
  letters: ['W2'],
  alsoRealizes: ['B7', 'M2'],
  source: 'D5 §3.4.4 (S-Upd-1)',
  components: () => ({ C: component('C', { inject: ['k1'], steps: [read('k1')] }) }),
  program: [
    insert('C'), settle(),
    update('C', { round: 2 }, { tag: 'star' }),
    settle({ tag: 'after' }),
  ],
  note: 'UpdClass = pending-entry: ¬installed, ζ=⊥. The entry is rewritten and nothing else — '
    + 'no episode exists to disturb. The verdict is precisely that emptiness: an implementation '
    + 'that bounces a pending fiber on `update` is separated here and nowhere else.',
})

define({
  id: 'S-Upd-2',
  rule: 'O-Update',
  letters: ['W3'],
  alsoRealizes: ['B1', 'B3', 'B2', 'X1', 'X2', 'X8', 'T4', 'U1', 'U4', 'U6'],
  source: 'D5 §3.4.4 (S-Upd-2)',
  components: () => ({ P: component('P', { steps: [track('a'), raise('x')] }) }),
  program: [
    insert('P'), settle(),
    update('P', { round: 2 }, { tag: 'star' }),
    settle({ tag: 'after' }),
  ],
  note: 'GAP-4, "the most consequential of the ten": UpdClass = failed-entry rewrites the entry '
    + 'AND clears the failure latch (ζ ↦ ⊥), lifting B2\'s block and letting the lifecycle be '
    + 're-entered from an error outcome — the very thing p. 38 says the calculus forbids. This '
    + 'is the only experiment in T* in which an Inactive(ξ) fiber is legitimately re-entered, '
    + 'and therefore the only one that pins where the boundary of "no re-entry from an error '
    + 'outcome" actually lies.',
})

define({
  id: 'S-Upd-3',
  rule: 'O-Update',
  letters: ['W4'],
  alsoRealizes: ['V1', 'V3', 'V4', 'U1', 'U2', 'U3', 'U5', 'U6', 'U10', 'U11', 'B5', 'T5', 'A1', 'M1', 'M3', 'M6'],
  source: 'D5 §3.4.4 (S-Upd-3)',
  anchorNote: 'ε = inv(C,b) is emitted on every fair schedule of this ρ: C\'s committed edge '
    + 'names P, so the reliance guard forces C\'s whole teardown to precede P\'s L-Unload, and '
    + 'P is therefore in Unloading at ε on every schedule (obligation (D-F)).',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), track('a')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1'), track('b')] }),
  }),
  program: [
    insert('P'), insert('C'), settle(),
    retire('P'),
    atEvent('revert:C:b', update('P', { round: 2 }, { tag: 'star' })),
    settle({ tag: 'after' }),
  ],
  note: 'GAP-5: UpdClass = unloading-clean. The audit anchors at cert(L-Leave,P); the harness '
    + 'anchors at the ORDINARY event inv(C,b), which selects the same window — P Unloading, '
    + 'installed, ζ=⊥ — and keeps the experiment presentable on a certificate-erased build. '
    + 'The verdict is stated over the observable outcome ONLY: the reference semantics also '
    + 'leaves a restart mark on the removed record that no Unloading-branch rule reads and '
    + 'L-Unload does not clear (ambiguity A15), and that residue is an artifact, not the '
    + 'letter\'s content.',
})

define({
  id: 'S-Upd-4',
  rule: 'O-Update',
  letters: ['W5'],
  alsoRealizes: ['X1', 'X7', 'U1', 'U3', 'U5', 'B1', 'B3', 'D1', 'D5', 'D12'],
  source: 'D5 §3.4.4 (S-Upd-4)',
  anchorVocabulary: 'certificate',
  anchorNote: 'ε = cert(L-Raise, P) is emitted on every fair schedule (P is the only fiber). '
    + 'It is a CERTIFICATE anchor and no ordinary-vocabulary substitute exists: in the '
    + 'reference semantics the window "Unloading carrying ξ" is entered by L-Raise and left by '
    + 'L-Unload with no ordinary event in between on any fair schedule, because the only rule '
    + 'that can delay L-Unload is the reliance guard and no fiber can hold a committed edge to '
    + 'a fiber that raised during its own Reloading. The experiment is therefore presentable '
    + 'only in the certificate-instrumented vocabulary — §5.4\'s proviso applied to the '
    + 'DRIVING half of an experiment. See README finding F10.',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), raise('x')] }),
  }),
  program: [
    insert('P'),
    atEvent(cert('L-Raise', 'P'), update('P', { round: 2 }, { tag: 'star' })),
    settle({ tag: 'after' }),
  ],
  note: 'GAP-6: UpdClass = unloading-failed. This is the only Λ_orch input that rewrites a θ '
    + 'constituent of a MID-TRANSITION fiber: ζ is cleared between L-Raise and L-Unload, so '
    + 'the unload window presents U3 where it would have presented U4 and — by correction C2 — '
    + 'the bookkeeping block U10–U12 becomes live where it was suppressed. Lemma 54(2)–(5) '
    + 'does not admit it: ζ is written by L-Raise and read by L-Unload and by nothing else.',
})

define({
  id: 'S-Upd-5',
  rule: 'O-Update',
  letters: ['W6'],
  alsoRealizes: ['R2', 'V1', 'V3', 'U1', 'U3', 'U6', 'U10', 'M1', 'M3', 'M6', 'B1', 'B3', 'T4', 'F1'],
  source: 'D5 §3.4.4 (S-Upd-5)',
  components: () => ({ P: component('P', { steps: [track('a')] }) }),
  program: [
    insert('P'), settle(), retire('P'), settle(),
    update('P', { round: 2 }, { tag: 'star' }),
  ],
  note: 'GAP-7: the n ∈ dom(F_γ) premise, which only O-Insert (I3) and O-Retire (R4) had a '
    + 'letter for. The specification decision for W6 is REFUSAL with the reason "no such '
    + 'entry", by parity with O-Retire\'s premise — the only premise Table 1 attaches to a '
    + 'name-taking orchestration input. The reference semantics does not refuse: it rewrites a '
    + 'record with removed === true and clears its outcome (audit §6 defect 1).',
})

// ---- §15.5  CO-Prov: P7 (GAP-7) -------------------------------------------

define({
  id: 'S-Set-1',
  rule: 'CO-Prov',
  letters: ['P7'],
  alsoRealizes: ['P1', 'T3', 'R2', 'V1', 'V3', 'U1', 'U3', 'U5', 'U10', 'M1', 'M3', 'M6'],
  source: 'D5 §3.7.3 (S-Set-1)',
  components: () => ({ P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }) }),
  program: [
    insert('P'), settle(), retire('P'), settle(),
    setval('P', 'k1', 'v2', { tag: 'star' }),
  ],
  note: 'GAP-7 at the A_k operation. The input IS refused in the reference semantics, but for '
    + 'P4\'s reason ("no own binding"), because O-Remove happens to clear the table first; the '
    + 'letter pins which reason the specification owes, and Definition 3 clause 1 compares '
    + 'refusal reasons (audit §6 defect 3).',
})

// ---- §15.6  CO-Acc: A8 (GAP-7) and A4 through the read label (GAP-10) -----

define({
  id: 'S-Acc-2',
  rule: 'CO-Acc',
  letters: ['A8'],
  alsoRealizes: ['A1', 'B5', 'T5', 'F3', 'P5', 'R2', 'V1', 'V3', 'U1', 'U3', 'U10', 'M1', 'M3', 'M6'],
  source: 'D5 §3.6.5 (S-Acc-2)',
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1'], steps: [read('k1')] }),
  }),
  program: [
    insert('P'), insert('C'), settle(),
    retire('C'), settle(),
    readLabel('C', 'k1', { tag: 'star' }),
  ],
  note: 'the read label\'s own premise. The specification decision is refusal with the reason '
    + '"no such entry" — NOT the INACTIVE_ACCESS the reference semantics returns from the '
    + 'stale record, because the two reasons license different client behaviour: one says "not '
    + 'yet", the other "never again" (audit §6 defect 2).',
})

define({
  id: 'S-Acc-3',
  rule: 'CO-Acc',
  letters: ['A4'],
  alsoRealizes: ['B7', 'M2', 'P1', 'T3'],
  source: 'D5 §3.6.5 (S-Acc-3)',
  keys: ['k1', 'k2'],
  components: () => ({
    P: component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] }),
    C: component('C', { inject: ['k1', 'k2'], steps: [track('c')] }),
  }),
  program: [
    insert('P'), insert('C'), settle(),
    readLabel('C', 'k1', { tag: 'star' }),
  ],
  note: 'GAP-10 closed: with read(n,k) in Λ_orch, Correction C5\'s A4 stops being '
    + '"unrealizable as a lifecycle window" and becomes an ordinary interface action — the one '
    + 'bookkeeping change §14.3 flagged and declined to apply for want of a label. C declares '
    + 'k1 AND k2, k2 has no provider, so target_C = ⊥ and C quiesces Inactive(⊥) with no '
    + 'committed view; the walk starts at C, line 4 misses and line 5 fires. What makes the '
    + 'occurrence non-trivial is that P is Active and k1 IS in σ_γ: the fiber is refused its '
    + 'own declared key because it has not committed to a provider. This ρ is the 32-suite\'s '
    + 'C5.3 and the explorer\'s coda TB.91, and it is the sole killer of the deviant '
    + '`proxy-skips-inactive-check` in either grounding artifact.',
})

// ===========================================================================

export const TSTAR_SCRIPTS = Object.freeze(SCRIPTS)

/** Index by id, for verdicts.mjs and the runner. */
export const SCRIPT_BY_ID = Object.freeze(Object.fromEntries(SCRIPTS.map(s => [s.id, s])))

/**
 * The reachable alphabet the suite claims to index: D1 §15's 86 letters, as
 * closed by the alphabet audit (`../alphabet-audit.md` §4.2) — **103**.
 *
 * The delta, all of it additive (§4.1): L-Divert +D7 (GAP-1) and +D8..D12
 * (GAP-2); L-Raise +X10 (GAP-9); L-Leave +V6 (GAP-8); the new alphabet
 * Σ_O-Update = {W1..W6} (GAP-3/4/5/6/7); CO-Prov +P7 and CO-Acc +A8 (GAP-7);
 * and A4 leaves the unrealizable column, reached through the read label of
 * Definition 2′ (GAP-10, Correction C5 applied).
 */
export const REACHABLE_ALPHABET = Object.freeze({
  'O-Insert': ['I1', 'I2', 'I3', 'I4', 'I6', 'I7'],
  'O-Retire': ['R1', 'R2', 'R3', 'R4'],
  'O-Remove': ['M1', 'M2', 'M3', 'M4', 'M5', 'M6', 'M7'],
  'O-Update': ['W1', 'W2', 'W3', 'W4', 'W5', 'W6'],
  'L-Begin': ['B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7'],
  'L-Iter': ['T1', 'T2', 'T3', 'T4', 'T5', 'T6', 'T7', 'T8', 'T9', 'T10', 'T11'],
  'L-Finish': ['F1', 'F2', 'F3'],
  'L-Divert': ['D1', 'D3', 'D4', 'D5', 'D7', 'D8', 'D9', 'D10', 'D11', 'D12'],
  'L-Raise': ['X1', 'X2', 'X3', 'X4', 'X5', 'X6', 'X7', 'X8', 'X9', 'X10'],
  'L-Leave': ['V1', 'V3', 'V4', 'V5', 'V6'],
  'L-Unload': ['U1', 'U2', 'U3', 'U4', 'U5', 'U6', 'U7', 'U8', 'U9', 'U10', 'U11', 'U12'],
  'CO-Prov': ['P1', 'P2', 'P3', 'P4', 'P5', 'P6', 'P7'],
  'CO-Iso': ['S1', 'S2', 'S3', 'S4'],
  'CO-Int': ['N1', 'N2', 'N3', 'N4'],
  'CO-Acc': ['A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A8'],
})

/**
 * Occurrences proved interface-unrealizable; no script may claim them.
 * The audit's closure shrinks this set by one and by one only (§4.2): A4
 * leaves it, because Definition 2′'s read label makes the external access an
 * interface action, and nothing enters it — every new letter is reachable.
 */
export const UNREALIZABLE = Object.freeze({
  I5: 'E.U.1 — names are system-drawn',
  D6: 'E.U.2 — the landing alternative needs the asynchrony layer',
  D2: 'E.U.3 — a live committed edge pins its provider',
  V2: 'E.U.4 — same argument at L-Leave',
  A7: 'E.U.6 — the reliance guard is exactly what prevents it (Thm. 63)',
})
