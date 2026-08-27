// D3 ↔ D1 reconciliation (explorer-report.md §11).
//
// The explorer's signature key is a TUPLE: (rule, decision, full field
// record). signatures.md's Σ_r is a LETTER alphabet: each letter names one
// guard atom / constructor class / witness bit, and a window's occurrence
// multiset κ_r is a SET of letters. The two counts (146 vs 86) are counts of
// different things.
//
// This script computes the abstraction map α: explorer signature → set of
// D1 letters, applies it to the reachable union and to the uncovered set,
// and reports where α is non-injective (explorer refines D1), where α's
// image misses D1 letters (explorer coarsens or under-reaches), and which
// D1 letters have no explorer preimage at all.
//
// Usage: node reconcile.mjs out/signatures-<tag>.json ...
// Writes out/reconcile.json + out/reconcile.md.

import { readFileSync, writeFileSync } from 'node:fs'

const files = process.argv.slice(2)
if (!files.length) { console.error('usage: node reconcile.mjs out/signatures-*.json'); process.exit(2) }

// ---- D1 alphabets (signatures.md §§1.1–14.1), verbatim letter lists ------
const D1 = {
  'O-Insert': ['I1', 'I2', 'I3', 'I4', 'I5', 'I6', 'I7'],
  'O-Retire': ['R1', 'R2', 'R3', 'R4'],
  'O-Remove': ['M1', 'M2', 'M3', 'M4', 'M5', 'M6', 'M7'],
  'L-Begin': ['B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7'],
  'L-Iter': ['T1', 'T2', 'T3', 'T4', 'T5', 'T6', 'T7', 'T8', 'T9', 'T10', 'T11'],
  'L-Finish': ['F1', 'F2', 'F3'],
  'L-Divert': ['D1', 'D2', 'D3', 'D4', 'D5', 'D6'],
  'L-Raise': ['X1', 'X2', 'X3', 'X4', 'X5', 'X6', 'X7', 'X8', 'X9'],
  'L-Leave': ['V1', 'V2', 'V3', 'V4', 'V5'],
  'L-Unload': ['U1', 'U2', 'U3', 'U4', 'U5', 'U6', 'U7', 'U8', 'U9', 'U10', 'U11', 'U12'],
  'CO-Prov': ['P1', 'P2', 'P3', 'P4', 'P5', 'P6'],
  'CO-Iso': ['S1', 'S2', 'S3', 'S4'],
  'CO-Int': ['N1', 'N2', 'N3', 'N4'],
  'CO-Acc': ['A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7'],
}
const UNREALIZABLE = ['I5', 'D2', 'D6', 'V2', 'A4', 'A7']

// ---- α: explorer signature -> set of D1 letters --------------------------
// Only the dimensions D1 gives letters to are read; every other explorer
// field is a REFINEMENT the hand analysis deliberately folds away.
const accLetter = { provide: 'U5', track: 'U6', retire: 'U7', rrev: 'U8' }

function alpha(rule, decision, f) {
  const out = new Set()
  switch (rule) {
    case 'O-Insert': {
      out.add({ root: 'I1', live: 'I2', retired: 'I2', removed: 'I3' }[f.parent])
      out.add('I4')                                  // Fresh=fresh: every offered insert
      out.add(f.declaredConflict ? 'I7' : 'I6')
      // f.realm is NOT an O-Insert dimension in D1 — it is the CO-Iso layer.
      // The explorer offers exactly one isolate context (k1↦r1), so two
      // isolated inserts share r1: the class conflates S2 (distinct) and
      // S3 (joined). S4 (re-isolate) is never offered.
      out.add(f.realm === 'isolated' ? 'S2|S3' : 'S1')
      return out
    }
    case 'O-Retire': {
      if (f.stateClass === 'disposed') out.add('R4')
      else if (f.stateClass === 'pending') out.add('R1')
      else if (f.stateClass === 'failed') out.add('R3')
      else out.add('R2')
      // f.again has no D1 letter (explorer refinement).
      return out
    }
    case 'O-Remove': {
      if (decision === 'fired') { out.add('M1'); out.add(f.outcome === 'xi' ? 'M4' : 'M3'); out.add('M6') }
      else {
        if (f.stateClass === 'inactive') out.add('M3'); else out.add('M5')
        out.add(f.hasChild ? 'M7' : 'M6')
        if (f.stateClass === 'inactive' && !f.hasChild) out.add('M2')
      }
      return out
    }
    case 'O-Update': { out.add('V5'); return out }   // D1 files update under L-Leave V5
    case 'L-Begin': {
      out.add(f.outcome === 'xi' ? 'B2' : 'B1')          // Inactive(⊥) / Inactive(ξ)
      out.add(f.retired ? 'B4' : 'B3')                   // RetClass τ
      for (const c of f.inject ?? []) out.add(c === 'provided' ? 'B5' : 'B7')
      return out                                          // B6 = installed-only: mutant-only
    }
    case 'L-Iter': {
      out.add('T1'); out.add('T2')                       // window scalar + key-equal
      const m = {
        'provide-fresh': 'T3', track: 'T4', 'track-rrev': 'T4',
        'read-committed-self': 'T5', 'read-committed-ancestor': 'T6',
        'read-inactive-declared-p': 'T7', 'read-inactive-declared-np': 'T7',
        'read-undeclared-p': 'T8', 'read-undeclared-np': 'T8',
        'setval-own-eq': 'T9', 'setval-own-neq': 'T9',
        register: 'T10', 'flag-pass': 'T11',
      }
      out.add(m[f.stepClass] ?? ('T?' + f.stepClass))
      // CO-Prov layer letters for the same events (§11.1):
      if (f.stepClass === 'provide-fresh') out.add('P1')
      if (f.stepClass.startsWith('read-committed')) out.add('P5')
      if (f.stepClass.startsWith('read-undeclared') || f.stepClass.startsWith('read-inactive')) out.add('P6')
      return out
    }
    case 'L-Raise': {
      out.add('X1')
      const sm = { raise: 'X2', 'flag-fail': 'X3', 'provide-conflict': 'X4', 'setval-foreign': 'X5' }
      out.add(sm[f.stepClass] ?? ('X?' + f.stepClass))
      if (f.stepClass === 'provide-conflict') out.add('P2')
      const am = { provide: 'X7', track: 'X8', rrev: 'X8', retire: 'X9' }
      const acc = f.acc ?? []
      if (!acc.length) out.add('X6'); else for (const a of acc) out.add(am[a] ?? ('X?' + a))
      return out
    }
    case 'L-Finish': { out.add((f.acc ?? []).length ? 'F1' : 'F2'); out.add('F3'); return out }
    case 'L-Divert': {
      out.add('D1')
      // targetOf() returns null for BOTH τ-retirement and provider-withdrawal,
      // so the explorer's `target-bot` conflates D3 and D4 — a COARSENING.
      // `stale` is the orch-update restart, which D1 letters only at L-Leave (V5).
      out.add(f.trigger === 'target-diff' ? 'D2' : f.trigger === 'stale' ? 'V5@divert*' : 'D3|D4')
      out.add('D5')                                  // the model only ever aborts
      // f.acc has no L-Divert letter in D1 (it is the L-Raise/L-Unload dimension).
      return out
    }
    case 'L-Leave': {
      if (decision === 'disabled') { out.add('V1-disabled*'); return out }
      out.add('V1')
      out.add(f.trigger === 'target-diff' ? 'V2' : f.trigger === 'stale' ? 'V5' : 'V3|V4')
      return out
    }
    case 'L-Unload': {
      if (decision === 'disabled') { out.add('U2') } else { out.add('U1') }
      out.add(f.outcome === 'xi' ? 'U4' : 'U3')
      const acc = f.acc ?? []
      if (!acc.length) out.add('U9'); else for (const a of acc) out.add(accLetter[a] ?? ('U?' + a))
      if (decision === 'fired') out.add(f.retired ? 'U10' : f.postTarget === 'bot' ? 'U11' : 'U12')
      // f.obs (inverse ORDER pattern) is explicitly NOT a letter in D1 §10.2
      // ("item order [is] a property of ... the observation word").
      return out
    }
    case 'A-Set': {
      // setOwn is Def. 24's A_k overwrite: own binding present -> P3,
      // no own binding -> P4 (the explorer's `refused`).
      out.add(decision === 'refused' ? 'P4' : 'P3')
      // f.valueEq, f.dependents and f.stateClass have no CO-Prov letter.
      return out
    }
    case 'A-Read': {
      // classifyRead returns the SAME `undeclared-*` string whether the walk
      // died at the root boundary (A5) or at a realm mismatch (A6): another
      // COARSENING. The -p/-np witness is an orthogonal explorer refinement.
      const m = {
        'committed-self': 'A1', 'committed-ancestor': 'A2',
        'undeclared-p': 'A5|A6', 'undeclared-np': 'A5|A6',
        'inactive-declared-p': 'A3|A4', 'inactive-declared-np': 'A3|A4',
        withdrawn: 'A7',
      }
      out.add(m[f.cls] ?? ('A?' + f.cls))
      out.add(f.cls.startsWith('committed') ? 'P5' : 'P6')
      return out
    }
    case 'A-Intercept': { out.add(['N1', 'N2', 'N4'][Math.min(f.entries, 2)]); return out }
    default: { out.add('??' + rule); return out }
  }
}

// ---- load reachable union ------------------------------------------------
const reach = new Map()
for (const file of files) {
  const j = JSON.parse(readFileSync(file, 'utf8'))
  for (const [rule, sigs] of Object.entries(j.rules)) {
    for (const s of sigs) if (!reach.has(s.sig)) reach.set(s.sig, { rule, decision: s.decision, fields: s.fields })
  }
}
const cov = JSON.parse(readFileSync('out/coverage.json', 'utf8'))
const uncovered = new Set(cov.uncovered)

// ---- apply α -------------------------------------------------------------
const classOf = new Map()     // explorer sig -> canonical projected class string
const fibre = new Map()       // projected class -> [explorer sigs]
for (const [sig, v] of reach) {
  const letters = [...alpha(v.rule, v.decision, v.fields)].filter(Boolean).sort()
  const cls = `${v.rule} ${v.decision} {${letters.join(',')}}`
  classOf.set(sig, cls)
  if (!fibre.has(cls)) fibre.set(cls, [])
  fibre.get(cls).push(sig)
}

const projectedClasses = [...fibre.keys()].sort()
const projectedCovered = new Set()
for (const [sig, cls] of classOf) if (!uncovered.has(sig)) projectedCovered.add(cls)
const projectedUncovered = projectedClasses.filter(c => !projectedCovered.has(c))

// Letters witnessed by the explorer. A token like 'D3|D4' means the explorer
// REACHED the occurrence but its encoding cannot say which D1 letter it is —
// a conflated witness, not a separate one.
const separate = new Set()
const conflated = new Set()
for (const [, v] of reach) {
  for (const l of alpha(v.rule, v.decision, v.fields)) {
    if (!l) continue
    if (l.includes('|')) for (const p of l.split('|')) conflated.add(p)
    else if (!l.endsWith('*')) separate.add(l)
  }
}
const witnessed = new Set([...separate, ...conflated])

const allD1 = Object.values(D1).flat()
const missing = allD1.filter(l => !witnessed.has(l))
const conflatedOnly = allD1.filter(l => conflated.has(l) && !separate.has(l))

// ---- report --------------------------------------------------------------
let md = '# D3 ↔ D1 signature-vocabulary reconciliation\n\n'
md += `Explorer reachable signatures (tuple encoding): **${reach.size}**\n\n`
md += `After applying α (project each tuple onto signatures.md's letter alphabet, dropping every dimension D1 gives no letter to): **${projectedClasses.length}** distinct occurrence classes.\n\n`
md += `Collapse factor: ${(reach.size / projectedClasses.length).toFixed(2)}×\n\n`
md += `Uncovered by the 32 tests, tuple encoding: **${uncovered.size}**; after α: **${projectedUncovered.length}**\n\n`

md += '## Collapse per rule (how much the explorer refines D1)\n\n'
md += '| rule | explorer sigs | after α | fold factor | D1 \\|Σ_r\\| | D1 reachable |\n|---|---|---|---|---|---|\n'
const d1n = { 'O-Insert': [7, 6], 'O-Retire': [4, 4], 'O-Remove': [7, 7], 'O-Update': ['—', '—'], 'L-Begin': [7, 7], 'L-Iter': [11, 11], 'L-Finish': [3, 3], 'L-Divert': [6, 4], 'L-Raise': [9, 9], 'L-Leave': [5, 4], 'L-Unload': [12, 12], 'A-Set': [6, 6], 'A-Read': [7, 5], 'A-Intercept': [4, 4] }
const rulesSeen = [...new Set([...reach.values()].map(v => v.rule))]
const ORDER = ['O-Insert', 'O-Retire', 'O-Remove', 'O-Update', 'L-Begin', 'L-Iter', 'L-Raise', 'L-Finish', 'L-Divert', 'L-Leave', 'L-Unload', 'A-Set', 'A-Read', 'A-Intercept']
for (const r of ORDER) {
  if (!rulesSeen.includes(r)) continue
  const n = [...reach.values()].filter(v => v.rule === r).length
  const p = new Set([...classOf.entries()].filter(([s]) => reach.get(s).rule === r).map(([, c]) => c)).size
  const [a, b] = d1n[r] ?? ['?', '?']
  md += `| ${r} | ${n} | ${p} | ${(n / p).toFixed(1)}× | ${a} | ${b} |\n`
}
md += `| **total** | **${reach.size}** | **${projectedClasses.length}** | **${(reach.size / projectedClasses.length).toFixed(2)}×** | **92** | **86** |\n`

md += '\n## Largest α-fibres (one D1 class, many explorer signatures)\n\n'
const big = [...fibre.entries()].sort((a, b) => b[1].length - a[1].length).slice(0, 12)
for (const [cls, sigs] of big) {
  md += `- **${cls}** — ${sigs.length} explorer signatures\n`
  for (const s of sigs.slice(0, 3)) md += `  - \`${s}\`\n`
  if (sigs.length > 3) md += `  - … ${sigs.length - 3} more\n`
}

md += '\n## D1 letters witnessed only as a CONFLATED class\n\n'
md += `${conflatedOnly.length}: ${conflatedOnly.join(', ')} — the explorer reaches the occurrence but its encoding cannot separate the D1 letters listed together (see α above: \`D3|D4\`, \`V3|V4\`, \`A5|A6\`, \`S2|S3\`, \`A3|A4\`).\n\n`

// The four coda tests sit outside the LTS by construction (report §7, log
// S6/S7) but do realize D1 letters the graph cannot offer.
const CODA_LETTERS = {
  I3: 'TB.88 — O-Insert under a REMOVED parent (normalization erases the parent, so no graph state can offer it)',
  N4: 'TB.89 — depth-2 nested intercept chain, nearest-wins (Def. 31 is a derived op no LTS transition invokes)',
  A4: 'TB.90 / TB.91 — EXTERNAL Def.-23 read on a declared-but-uncommitted fiber (walk decides at self ⇒ PosClass = self)',
}

md += '\n## D1 letters with NO explorer witness\n\n'
md += `${missing.length} of ${allD1.length}: ${missing.join(', ')}\n\n`
md += 'Of these, the ones D1 itself declares interface-unrealizable are CONFIRMED negatives; the rest are explorer bound/generator gaps; three are realized by the coda tests appended to T_B outside the graph.\n\n'
md += '| letter | D1 status | in graph | in T_B coda | verdict |\n|---|---|---|---|---|\n'
for (const l of missing) {
  const un = UNREALIZABLE.includes(l)
  const coda = CODA_LETTERS[l]
  const verdict = coda
    ? (un ? '**realized by a coda test — CONTRADICTS the blanket D1 claim**' : 'covered outside the graph')
    : (un ? 'CONFIRMED absent' : 'GAP — not reached at the explored bound')
  md += `| ${l} | ${un ? '**unrealizable**' : 'reachable'} | absent | ${coda ? coda.split(' — ')[0] : '—'} | ${verdict} |\n`
}
md += '\nCoda detail:\n\n'
for (const [l, why] of Object.entries(CODA_LETTERS)) md += `- **${l}**: ${why}\n`

// ---- the 86-vs-146 closing ledger ---------------------------------------
// D1's 86 counts reachable ALPHABET LETTERS. The explorer's 146 counts
// reachable occurrence TUPLES. These are different quantities; the ledger
// below is the only arithmetic that closes between them.
const EXPECTED_ABSENT = {
  B6: 'installed-only-provided: D1 §4.1 and report S8 both say no baseline σ realizes it (it is the `satisfied-by-installed-provider` MUTANT behaviour). Absence is the predicted result.',
  T7: 'read-declared-uncommitted as an in-lifecycle STEP: this is A4\'s argument at step level — a fiber never executes a step while its own declared key is uncommitted. Absence is the predicted result.',
}
const d1Reachable = allD1.filter(l => !UNREALIZABLE.includes(l))
const witnessedReachable = d1Reachable.filter(l => witnessed.has(l))
const unwitnessedReachable = d1Reachable.filter(l => !witnessed.has(l))
const codaCovered = unwitnessedReachable.filter(l => CODA_LETTERS[l])
const expectedAbsent = unwitnessedReachable.filter(l => EXPECTED_ABSENT[l])
const genuineGaps = unwitnessedReachable.filter(l => !CODA_LETTERS[l] && !EXPECTED_ABSENT[l])

md += '\n## The closing ledger: how 86 and 146 relate\n\n'
md += 'They count different things. D1 counts **alphabet letters** (`|Σ_r^reach|`); D3 counts **occurrence tuples** (realizable field records). Neither is wrong; the bridge is α.\n\n'
md += `| quantity | value |\n|---|---|\n`
md += `| D1 letters, all rules (\`|Σ_r|\` summed) | ${allD1.length} |\n`
md += `| − interface-unrealizable (I5, D2, D6, V2, A4, A7) | ${UNREALIZABLE.length} |\n`
md += `| **= D1 reachable letters** | **${d1Reachable.length}** |\n`
md += `| of those, witnessed in the explorer graph | ${witnessedReachable.length} (${separate.size} separately + ${conflatedOnly.length} only as a conflated pair) |\n`
md += `| of those, NOT witnessed in the graph | ${unwitnessedReachable.length} |\n`
md += `|  · covered by a T_B coda test | ${codaCovered.length} (${codaCovered.join(', ')}) |\n`
md += `|  · absence PREDICTED by D1 itself | ${expectedAbsent.length} (${expectedAbsent.join(', ')}) |\n`
md += `|  · genuine generator gaps | ${genuineGaps.length} (${genuineGaps.join(', ')}) |\n`
md += `| explorer occurrence TUPLES over the same letters | ${reach.size} |\n`
md += `| distinct letter-SETS those tuples realize (α image) | ${projectedClasses.length} |\n`
md += `\nSo: **${witnessedReachable.length} of D1's ${d1Reachable.length} reachable letters are confirmed by exhaustive search**, ${codaCovered.length} more by coda tests, ${expectedAbsent.length} are absences D1 predicts, and **${genuineGaps.length} remain unreconciled** (generator gaps, listed above). The 146 is not a competing estimate of 86: it is the count of distinct field-records those letters combine into at the explored bound.\n\n`
md += 'Genuine gaps in detail:\n\n'
const GAP_WHY = {
  M2: 'O-Remove RetClass τ=⊥ as a *blocking* letter: the explorer only offers `remove` where `removeEligible` holds, so the τ=⊥ refusal is never an offered action.',
  X9: 'register⁻¹ present in a raise accumulator: needs a registrar shape that raises AFTER registering; no catalog shape does both.',
  S4: 'isolate over an already-isolated key: the generator offers exactly one isolate context (k1↦r1) and never nests a second.',
  N1: 'intercept MetaPat ε — A-Intercept has no LTS occurrence at all (interceptMerged is a derived op; log S7).',
  N2: 'intercept MetaPat context-only — same reason as N1.',
  N3: 'intercept MetaPat component⊕context — same reason as N1.',
  A3: 'Algorithm-6 IA at an ANCESTOR: needs an orchestrator-inserted child that READS under a pending declaring parent; the child-insert probe uses shape T, which has no read step.',
}
for (const l of genuineGaps) md += `- **${l}** — ${GAP_WHY[l] ?? 'unclassified'}\n`
md += '\nExpected-absence detail:\n\n'
for (const [l, why] of Object.entries(EXPECTED_ABSENT)) md += `- **${l}**: ${why}\n`

md += '\n## The six unrealizability claims\n\n'
md += '| id | D1 claim | separately witnessed | conflated witness | verdict |\n|---|---|---|---|---|\n'
for (const l of UNREALIZABLE) {
  md += `| ${l} | interface-unrealizable | ${separate.has(l) ? 'YES' : 'no'} | ${conflated.has(l) ? 'YES' : 'no'} | ${witnessed.has(l) ? '**WITNESSED — see report §11**' : 'absent — CONFIRMS D1'} |\n`
}

writeFileSync('out/reconcile.json', JSON.stringify({
  files,
  reachableTuples: reach.size,
  projectedClasses: projectedClasses.length,
  uncoveredTuples: uncovered.size,
  uncoveredProjected: projectedUncovered.length,
  projectedUncoveredList: projectedUncovered,
  witnessedSeparately: [...separate].sort(),
  witnessedConflatedOnly: conflatedOnly,
  missingLetters: missing,
  unrealizableWitnessed: UNREALIZABLE.filter(l => witnessed.has(l)),
  unrealizableConflated: UNREALIZABLE.filter(l => conflated.has(l)),
  ledger: {
    d1LettersTotal: allD1.length,
    d1Unrealizable: UNREALIZABLE.length,
    d1Reachable: d1Reachable.length,
    witnessedInGraph: witnessedReachable.length,
    unwitnessedInGraph: unwitnessedReachable.length,
    codaCovered, expectedAbsent, genuineGaps,
  },
  fibreSizes: Object.fromEntries([...fibre].map(([c, s]) => [c, s.length])),
  fibres: Object.fromEntries(fibre),
}, null, 1))
writeFileSync('out/reconcile.md', md)
console.log(`tuples=${reach.size} projected=${projectedClasses.length} fold=${(reach.size / projectedClasses.length).toFixed(2)}x`)
console.log(`uncovered: ${uncovered.size} tuples -> ${projectedUncovered.length} projected classes`)
console.log(`D1 letters witnessed separately: ${separate.size}; conflated-only (${conflatedOnly.length}): ${conflatedOnly.join(', ')}`)
console.log(`D1 letters missing (${missing.length}): ${missing.join(', ')}`)
console.log(`unrealizable letters WITNESSED (would contradict D1): ${UNREALIZABLE.filter(l => witnessed.has(l)).join(', ') || '(none)'}`)
console.log('written out/reconcile.json, out/reconcile.md')
