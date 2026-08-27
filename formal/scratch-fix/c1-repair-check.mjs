// Does E.LD.D3's corrected script (retire Q, settle, insert Q2, retire G, settle)
// survive where the explorer's "obvious repair" (retire Q AND G, then settle) fails?
// Read-only: imports the explorer's model, modifies nothing.
import { Model } from '../explorer/model.mjs'

const provide = (key, value) => ({ do: 'provide', key, value })
const track = (tag) => ({ do: 'track', tag })
const register = (spec) => ({ do: 'register', spec })

const C = { name: 'C', inject: ['k2'], steps: [track('b'), track('c')], provide: [] }
const Q = { name: 'Q', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const Q2 = { name: 'Q2', inject: [], steps: [provide('k2', 'v2')], provide: ['k2'] }
const G = { name: 'G', inject: [], steps: [register(C), track('a')], provide: [] }

const show = m => [...m.fibers.values()]
  .filter(f => !f.removed)
  .map(f => `${f.spec.name}:${f.state}${f.retired ? '(τ)' : ''}`).join(' ') || '(none)'

const m = new Model({})
const certs = []
m.cert = c => certs.push(`${c.rule} ${c.decision} ${JSON.stringify(c.fields)}`)
const events = []
if ('emit' in m) { /* noop */ }

const q = m.insert(m.rootCtx, Q)
const g = m.insert(m.rootCtx, G)
m.sweep()
console.log('after settle 1        :', show(m))

m.retire(q)
m.sweep()
console.log('after retire(Q)+settle:', show(m))

certs.length = 0
let q2
try {
  q2 = m.insert(m.rootCtx, Q2)
  console.log('insert(root, Q2)      : ACCEPTED')
} catch (e) {
  console.log('insert(root, Q2)      : REFUSED —', e.message)
  process.exit(1)
}
m.retire(g)
m.sweep()
console.log('after retire(G)+settle:', show(m))
console.log('\ncertificates after Q2 insert:')
for (const c of certs) console.log('  ', c)
const divert = certs.filter(c => c.startsWith('L-Divert'))
console.log('\nL-Divert certificates :', divert.length ? divert.join(' | ') : 'NONE on this schedule')
console.log('trace:', (m.trace ?? []).join(' '))
