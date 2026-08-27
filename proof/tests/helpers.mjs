import { createSystem } from '../src/target.mjs'

/** Run one scenario against a fresh system; always dispose. */
export async function withSystem(fn) {
  const sys = await createSystem()
  try {
    await fn(sys)
  } finally {
    await sys.dispose()
  }
}
