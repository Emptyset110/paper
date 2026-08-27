// Preload (via `node --import`) for audit runs of the untouched 32-test
// suite: installs the redirect loader and a certificate collector; on exit,
// writes the deduplicated signature keys seen during the process to
// process.env.CERT_OUT.

import { register } from 'node:module'
import { writeFileSync } from 'node:fs'
import { sigKey } from './sig.mjs'

register('./redirect-loader.mjs', import.meta.url)

const seen = new Map() // sigKey -> count
globalThis.__MODEL_CERT_HOOK__ = (cert) => {
  const k = sigKey(cert)
  seen.set(k, (seen.get(k) ?? 0) + 1)
}

process.on('exit', () => {
  if (process.env.CERT_OUT) {
    writeFileSync(process.env.CERT_OUT, JSON.stringify([...seen.entries()], null, 1))
  }
})
