import { createSystem } from '../src/target.mjs'
import { createModelSystem } from '../src/adapter-model.mjs'

/**
 * Run one scenario against a fresh system; always dispose.
 *
 * With PROOF_TARGET=model and MODEL_EXHAUST set, the scenario is re-executed
 * once per schedule: the model consults a choice oracle at every state where
 * more than one rule is applicable, and this driver enumerates oracle
 * sequences in lexicographic order until the choice tree is exhausted or the
 * run budget (MODEL_EXHAUST, a number, or 5000 by default when set to 1) is
 * hit. The verdict must hold on EVERY explored schedule; an assertion failure
 * on any schedule fails the test. The exploration summary is printed as a
 * diagnostic line consumed by run-necessity.mjs.
 */
export async function withSystem(fn) {
  const exhaust = process.env.PROOF_TARGET !== 'cordis' && process.env.PROOF_TARGET !== 'cordis-node'
    && process.env.MODEL_EXHAUST
  if (!exhaust) {
    const sys = await createSystem()
    try {
      await fn(sys)
    } finally {
      await sys.dispose()
    }
    return
  }

  const budget = Number(exhaust) > 1 ? Number(exhaust) : 5000
  const baseOpts = {
    mutant: process.env.MODEL_MUTANT || null,
    order: process.env.MODEL_ORDER || 'fifo',
    seed: Number(process.env.MODEL_SEED ?? 1),
  }
  let oracle = []
  let runs = 0
  let truncated = false
  for (;;) {
    runs += 1
    const sys = await createModelSystem({ ...baseOpts, oracle })
    try {
      await fn(sys)
    } finally {
      await sys.dispose()
    }
    // Compute the lexicographic successor of `oracle` against the branch
    // factors this run met (standard mixed-radix increment).
    const radix = sys.model.branching
    const digits = radix.map((_, i) => oracle[i] ?? 0)
    let i = radix.length - 1
    while (i >= 0 && digits[i] + 1 >= radix[i]) i -= 1
    if (i < 0) break // choice tree exhausted
    oracle = digits.slice(0, i + 1)
    oracle[i] += 1
    if (runs >= budget) {
      truncated = true
      break
    }
  }
  if (process.env.MODEL_EXHAUST_REPORT) {
    console.log(`[exhaust] runs=${runs} ${truncated ? 'TRUNCATED' : 'complete'}`)
  }
}
