// Search fair schedules of E.LD.D3's corrected script for an L-Divert at C.
// Read-only use of the explorer's model.
import { Model } from '../explorer/model.mjs'

const provide = (key, value) => ({ do: 'provide', key, value })
const track = (tag) => ({ do: 'track', tag })
const register = (spec) => ({ do: 'register', spec })

const C = { name: 'C', inject: ['k2'], steps: [track('b'), track('c')], provide: [] }
const Q = { name: 'Q', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const Q2 = { name: 'Q2', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const G = { name: 'G', inject: [], steps: [register(C), track('a')], provide: [] }

function run(oracle) {
  const m = new Model({ oracle })
  const certs = []
  m.cert = c => certs.push({ rule: c.rule, decision: c.decision, fields: c.fields })
  const q = m.insert(m.rootCtx, Q)
  const g = m.insert(m.rootCtx, G)
  m.sweep()
  m.retire(q)
  m.sweep()
  m.insert(m.rootCtx, Q2)
  m.retire(g)
  m.sweep()
  return { certs, trace: m.trace ?? [], branching: m.branching }
}

let found = null
let maxBranch = 0
for (let trial = 0; trial < 200000 && !found; trial++) {
  const oracle = Array.from({ length: 30 }, () => Math.floor(Math.random() * 4))
  let r
  try { r = run(oracle) } catch { continue }
  maxBranch = Math.max(maxBranch, r.branching.length)
  const d = r.certs.filter(c => c.rule === 'L-Divert')
  if (d.length) found = { oracle, r, d }
}

if (found) {
  console.log('L-DIVERT REACHED on a fair schedule')
  console.log('oracle:', found.oracle.join(''))
  for (const c of found.d) console.log('  cert:', c.rule, c.decision, JSON.stringify(c.fields))
  console.log('trace:', found.r.trace.join(' '))
} else {
  console.log('no L-Divert found in 200000 random schedules; max branch points seen:', maxBranch)
}
