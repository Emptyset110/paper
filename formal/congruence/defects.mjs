// The four D5 defect reproductions, run against the reference semantics
// (`../../proof/src/model.mjs`) — the executable specification itself.
//
// Each case prints the behaviour BEFORE the fix (recorded from
// `../scratch-audit/verify-scripts.mjs` against the unfixed file, quoted here
// verbatim so the change is auditable without reverting), the behaviour AFTER,
// and the clause of [SZC26] that decides it.  Exit status is non-zero if any
// case does not show the fixed behaviour.
//
//   node defects.mjs

import { Model } from '../../proof/src/model.mjs'
import { component, provide, track, read, raise } from '../../proof/src/dsl.mjs'

let failures = 0
const cases = []

function check(id, title, citation, before, expect, fn) {
  const m = new Model({})
  let got
  try { got = fn(m) } catch (error) { got = `THREW ${error.code ?? ''} ${error.message}` }
  const ok = got === expect
  if (!ok) failures += 1
  cases.push({ id, title, citation, before, after: got, expect, ok, trace: [...m.trace] })
}

const attempt = fn => {
  try { fn(); return 'accepted' } catch (error) { return `refused:${error.code ?? 'NO-CODE'}` }
}

// ---------------------------------------------------------------- defect 1
check(
  'D5-1', 'update(n, cfg) at n ∉ dom(F_γ)',
  '[SZC26] p. 31 (O-Retire) and p. 32: "O-Retire has n ∈ dom(F_γ) as its only '
  + 'premise" — the registry premise every name-taking orchestration input owes; '
  + 'Lemma 54(5): π, d, p, e come into existence with the entry and are never '
  + 'written again, so after γ \\ n there is no entry for `update` to rewrite. '
  + 'Letter W6 (alphabet-audit.md §3.4.1).',
  'accepted — silently rewrote a record with removed=true, uid=null, and cleared its outcome',
  'refused:NO_SUCH_ENTRY',
  m => {
    const P = component('P', { steps: [track('a')] })
    const p = m.insert(m.rootCtx, P); m.sweep()
    m.retire(p); m.sweep()
    return attempt(() => m.update(p, { z: 1 }))
  },
)

// ---------------------------------------------------------------- defect 2
check(
  'D5-2', 'read(n, k) at n ∉ dom(F_γ)',
  'Definition 2′ (alphabet-audit.md §3.6.1): the read label\'s premise is '
  + 'n ∈ dom(F_γ) ∪ {root}; Algorithm 6 ([SZC26] p. 61) runs from n\'s resolution '
  + 'context, and a removed name has none. Letter A8. The reason matters because '
  + 'Definition 3 clause 1 compares refusal reasons, and INACTIVE_ACCESS says '
  + '"not yet" where the truth is "never again".',
  'threw INACTIVE_ACCESS — served from the stale record\'s spec.inject',
  'refused:NO_SUCH_ENTRY',
  m => {
    const P = component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] })
    const C = component('C', { inject: ['k1'], steps: [read('k1')] })
    m.insert(m.rootCtx, P)
    const c = m.insert(m.rootCtx, C); m.sweep()
    m.retire(c); m.sweep()
    return attempt(() => m.readCommitted(c, 'k1'))
  },
)

// ---------------------------------------------------------------- defect 3
check(
  'D5-3', 'setval(n, k, v) at n ∉ dom(F_γ)',
  'Same registry premise, checked BEFORE Definition 24\'s own precondition: '
  + 'O-Remove clears σ_n ([SZC26] Table 1, O-Remove edits dom(F_γ); model '
  + 'removePass clears the table), so without the premise the input is refused '
  + 'with P4\'s reason ("no own binding") at a name that has no entry at all. '
  + 'Letter P7 (alphabet-audit.md §3.7.1).',
  'refused with P4\'s reason: `cannot set "k1" without provide`',
  'refused:NO_SUCH_ENTRY',
  m => {
    const P = component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] })
    const p = m.insert(m.rootCtx, P); m.sweep()
    m.retire(p); m.sweep()
    return attempt(() => m.setOwn(p, 'k1', 'v2'))
  },
)

// ---------------------------------------------------------------- defect 4
check(
  'D5-4a', 'the restart mark survives L-Unload (W4: update at a clean Unloading fiber)',
  '[SZC26] eq. 43: Θ_Γ := Inactive(ζ) | Reloading(i,g,ω) | Active(g,ω) | '
  + 'Unloading(g,ω,ζ) — Inactive(ζ) has no restart-mark constituent, and Table 1\'s '
  + 'L-Unload row writes θ_n ↦ Inactive(ζ) whole, so nothing of the Unloading '
  + 'state survives it. Lemma 54(2): ω_n ceases at L-Unload, so at Inactive there '
  + 'is no committed view for a "target ≠ ω" mark to mean anything against. A '
  + 'surviving mark makes L-Divert fire in the NEXT episode with its premise '
  + 'target_n(γ) ≠ ω false. Ambiguity A15, resolved as the audit\'s first option.',
  'P quiesced disposed with stale === true still set',
  'stale=false',
  m => {
    const P = component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), track('a')] })
    const C = component('C', { inject: ['k1'], steps: [read('k1'), track('b')] })
    const p = m.insert(m.rootCtx, P)
    m.insert(m.rootCtx, C); m.sweep()
    m.retire(p)
    m.trace.when('leave:P', () => m.update(p, { z: 1 }))
    m.sweep()
    return `stale=${p.stale}`
  },
)

check(
  'D5-4b', 'the spurious next-episode L-Divert (W5: update at an Unloading fiber carrying ξ)',
  'Same clause. The observable consequence: one orchestration input produced '
  + 'THREE episodes, the middle one a begin/divert/deactivate pair with no rule '
  + 'premise true at it. alphabet-audit.md §3.4.4 S-Upd-4 quotes the three-episode '
  + 'trace; after the fix that script observes two episodes.',
  'begin, provide, raise, deactivated, begin, DIVERT, deactivated, begin, provide, raise, deactivated  (3 episodes)',
  'begin:P,provide:P:k1,raise:P,deactivated:P,begin:P,provide:P:k1,raise:P,deactivated:P',
  m => {
    const P = component('P', { provide: ['k1'], steps: [provide('k1', 'v1'), raise('boom')] })
    const p = m.insert(m.rootCtx, P)
    m.trace.when('raise:P', () => m.update(p, { z: 1 }))
    m.sweep()
    void p
    return m.trace.join(',')
  },
)

// ---------------------------------------------------------------- regression guards
check(
  'GUARD-1', 'update at a LIVE name is unaffected',
  'W1/W2/W3 are unchanged; only the absent-entry premise was added.',
  'accepted', 'accepted',
  m => {
    const P = component('P', { steps: [track('a')] })
    const p = m.insert(m.rootCtx, P); m.sweep()
    return attempt(() => m.update(p, { z: 1 }))
  },
)

check(
  'GUARD-2', 'the failure-latch clear (GAP-4, letter W3) still fires',
  'The audit letters `update` at Inactive(ξ) as W3, whose decision IS the latch '
  + 'clear; the registry premise does not touch it.',
  'two complete episodes', 'two complete episodes',
  m => {
    const P = component('P', { steps: [track('a'), raise('boom')] })
    const p = m.insert(m.rootCtx, P); m.sweep()
    m.update(p, { z: 1 })
    m.sweep()
    return m.trace.filter(e => e === 'begin:P').length === 2 ? 'two complete episodes' : `?${m.trace.join(',')}`
  },
)

check(
  'GUARD-3', 'a read at a live but uncommitted declaring fiber is still INACTIVE_ACCESS (A4)',
  'The premise reads dom(F_γ) only; C5.3 / S-Acc-3 / TB.91 are unchanged.',
  'refused:INACTIVE_ACCESS', 'refused:INACTIVE_ACCESS',
  m => {
    const P = component('P', { provide: ['k1'], steps: [provide('k1', 'v1')] })
    const C = component('C', { inject: ['k1', 'k2'], steps: [track('c')] })
    m.insert(m.rootCtx, P)
    const c = m.insert(m.rootCtx, C); m.sweep()
    return attempt(() => m.readCommitted(c, 'k1'))
  },
)

for (const c of cases) {
  console.log(`\n--- ${c.id}  ${c.ok ? 'OK ' : 'FAIL'}  ${c.title}`)
  console.log(`    before : ${c.before}`)
  console.log(`    after  : ${c.after}`)
  if (!c.ok) console.log(`    EXPECTED: ${c.expect}`)
  console.log(`    calculus: ${c.citation}`)
  console.log(`    trace  : ${JSON.stringify(c.trace)}`)
}
console.log(`\n${cases.length - failures}/${cases.length} cases show the specified behaviour`)
process.exit(failures ? 1 : 0)
