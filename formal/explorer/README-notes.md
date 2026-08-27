# D3 working notes (internal; the deliverable report is ../explorer-report.md)

Pipeline:

1. `node selftest-norm.mjs` — normalization self-test.
2. `node run-explore.mjs --tag=<T> [--maxFibers --shapes --maxStates --timeBudgetMs --noUpdates --noSetowns --noIsolate --noChildInserts --noTb]`
   → out/signatures-<T>.{json,md}, out/tb-<T>.json
3. `node audit-32.mjs` → out/audit-32.json (32 spawned single-test runs of the
   untouched proof suite, instrumented via redirect-loader).
4. `node coverage.mjs out/signatures-<T1>.json [...]` → out/coverage.{json,md}
5. `node kill-tb.mjs out/tb-<T1>.json [...]` → out/kill-tb.json
6. Hand-suite matrix: `node ../../proof/run-necessity.mjs`
   (saved: out/hand-suite-kill-matrix.txt)
