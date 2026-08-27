// Target selection for the conformance suite.
//
//   PROOF_TARGET=model            (default) the reference model
//   PROOF_TARGET=cordis           a real build; CORDIS_LIB selects it:
//     CORDIS_LIB=<path to lib/index.js>
//     default: the calculus-aligned build in deepseek-harness/vendor/cordis
//   MODEL_MUTANT=<name>           model only: run a semantic mutant
//   MODEL_ORDER=fifo|lifo|random  model only: scheduler strategy
//   MODEL_SEED=<n>                model only: seed for random order

import { createModelSystem } from './adapter-model.mjs'
import { createCordisSystem } from './adapter-cordis.mjs'
import { createDistributedSystem } from './adapter-distributed.mjs'

export const HARNESS_LIB = new URL('../../../deepseek-harness/vendor/cordis/lib/index.js', import.meta.url).href
export const UPSTREAM_LIB = new URL(
  '../../../cordis-plugins/cordis-node/node_modules/.pnpm/@deepseek-ai+cordis@4.0.1_@deepseek-ai+cordis-plugin-include@1.0.6_@deepseek-ai+cordis-plugin-loader@1.0.2/node_modules/@deepseek-ai/cordis/lib/index.js',
  import.meta.url,
).href

/** Create the system under test from the environment. */
export async function createSystem() {
  const target = process.env.PROOF_TARGET ?? 'model'
  if (target === 'model') {
    return createModelSystem({
      mutant: process.env.MODEL_MUTANT || null,
      order: process.env.MODEL_ORDER || 'fifo',
      seed: Number(process.env.MODEL_SEED ?? 1),
    })
  }
  if (target === 'cordis') {
    return createCordisSystem(process.env.CORDIS_LIB || HARNESS_LIB)
  }
  if (target === 'cordis-node') {
    return createDistributedSystem()
  }
  throw new Error(`unknown PROOF_TARGET: ${target}`)
}
