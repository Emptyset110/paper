// Occurrence-signature keys (D3 item 3).
//
// A certificate emitted by the instrumented model copy is
//   { rule, decision: 'fired'|'refused'|'disabled', fields: {...} }
// with `fields` drawn from MASTER.md's per-rule field drafts (see
// explorer-report.md "Signature fields as realized" + Deviations).
// This module gives certificates a canonical string key so signature sets
// can be deduplicated, tabulated, and compared across the explorer, the
// 32-test audit, and the generated-suite runner.

function stable(x) {
  if (Array.isArray(x)) return `[${x.map(stable).join(',')}]`
  if (x && typeof x === 'object') {
    const keys = Object.keys(x).filter(k => x[k] !== undefined).sort()
    return `{${keys.map(k => `${k}:${stable(x[k])}`).join(',')}}`
  }
  return JSON.stringify(x)
}

export function sigKey(cert) {
  return `${cert.rule} ${cert.decision} ${stable(cert.fields)}`
}

export const RULE_ORDER = [
  'O-Insert', 'O-Retire', 'O-Remove', 'O-Update',
  'L-Begin', 'L-Iter', 'L-Raise', 'L-Finish', 'L-Divert', 'L-Leave', 'L-Unload',
  'A-Set', 'A-Read', 'A-Intercept',
]
