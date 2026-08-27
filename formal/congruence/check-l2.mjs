// Every level-2 split must differ ONLY in frame data (Remark 1): the emission
// word's order/multiplicity, the iterator position, or the accumulator's
// length/order.  A level-2 split differing in anything else would mean the
// level-1 fold is hiding a real difference.
import { readFileSync, readdirSync } from 'node:fs'
const FRAME = /^(.*\.)(iterAt|accLen|accOrder):/
let bad = 0, tot = 0
for (const f of readdirSync('out').filter(x => x.startsWith('cong-') && x.endsWith('.json'))) {
  const j = JSON.parse(readFileSync(`out/${f}`, 'utf8'))
  for (const s of j.splitsLevel2 ?? []) {
    tot += 1
    const rs = s.results.map(r => r.result)
    const nonFrameU = rs.map(r => JSON.stringify(r.u.filter(e => !FRAME.test(e))))
    const heads = rs.map(r => JSON.stringify([r.d, r.r, r.n]))
    const emitSets = rs.map(r => JSON.stringify([...new Set(r.e)].sort()))
    const ok = new Set(nonFrameU).size === 1 && new Set(heads).size === 1 && new Set(emitSets).size === 1
    if (!ok) { bad += 1; console.log(`NON-FRAME L2 SPLIT in ${f}: ${s.rule} {${s.kappa}}`); for (const r of rs) console.log('   ', JSON.stringify(r)) }
  }
}
console.log(`level-2 splits inspected: ${tot}; differing in anything but frame data: ${bad}`)
