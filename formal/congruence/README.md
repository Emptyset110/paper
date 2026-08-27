# `formal/congruence/` — the κ_r-congruence check at a bound

`alphabet-audit.md` §5, layer 3, names the property that would turn the
paper's completeness *argument* into a *proof*, and says it is checkable at the
explorer's bound today:

> for each rule $r$, $\kappa_r(W) = \kappa_r(W') \Rightarrow \mathrm{result}_r(W) \equiv \mathrm{result}_r(W')$
> over all interface-reachable windows — **$\kappa_r$ is a congruence for the
> rule's observable result** … quotient the reachable window set by $\kappa_r$
> and check that each class has a single result. That check is cheap, it is not
> currently run, and it is the single highest-value next artifact.

This directory runs it. Nothing under `explorer/` or `tstar/` is modified;
`../../proof/src/model.mjs` (the reference semantics) is, and the four changes
are reproduced as prototype patches in `patch-model.mjs` so the instrumented
twin under `explorer/` stays in step without being edited.

## Files

| file | what |
| --- | --- |
| `kappa.mjs` | κ_r per rule, computed from the configuration, using the alphabets of `../signatures.md` as revised by `../alphabet-audit.md` §3 |
| `result.mjs` | result_r(W) at two levels: per-occurrence (frame quotiented out) and whole-rule |
| `patch-model.mjs` | re-applies this deliverable's `proof/src/model.mjs` fixes to `explorer/model.mjs` at load time |
| `run-congruence.mjs` | BFS over the LTS + the congruence check + a coda family for the absent-entry letters |
| `summarize.mjs` | unions the portfolio; a class singleton in every run can still split across runs |
| `check-l2.mjs` | asserts that every level-2 split differs only in frame data (Remark 1) |
| `defects.mjs` | the four defect reproductions, before/after, with the calculus citation for each |
| `portfolio.sh` | the bound family (the explorer's own, `../explorer-report.md` §4) |
| `REPORT.md` | the deliverable |
| `out/` | machine output: `cong-<tag>.json`, `SUMMARY.md`, `portfolio.log` |
| `out-nofix/`, `out-repair/` | the same check against the pre-fix semantics, and with the §4 alphabet repair applied |

## Running

```sh
cd paper/formal/congruence

node defects.mjs                    # the four specification fixes, before/after
sh portfolio.sh                     # ~20 min; writes out/cong-*.json
node summarize.mjs                  # writes out/SUMMARY.md
node check-l2.mjs                   # every level-2 split is frame data

# one bound, interactively
node run-congruence.mjs --tag=A2c --maxFibers=2 --noUpdates --noSetowns

# the one alphabet repair the check found to be owed (T4 → T4 / T4r)
node run-congruence.mjs --tag=A2c-rep --repair --maxFibers=2 --noUpdates --noSetowns

# the check against the PRE-fix reference semantics: the defects reappear as
# congruence counterexamples
CONG_NO_FIX=1 node run-congruence.mjs --tag=nofix --maxFibers=1
```

Node ≥ 22, no dependencies.

## What the two levels are

`../paper.md` §5 Remark 1 already says whole-rule congruence is false:

> κ_r(W) is a multiset and carries no order; the accumulator's composition
> order and the iterator's position are frame data of W, consumed by lift_r …
> a version claiming that κ-equal windows receive identical *whole-rule*
> results would be false for windows that agree as multisets but differ in
> accumulator order.

So the check is run at two granularities. **Level 1** quotients the frame away
and is the hypothesis Lemma 4(1)–(2) actually needs; congruence must hold
there, and a split is a counterexample. **Level 2** keeps the frame; splits
there are Remark 1's own prediction and are reported separately as
corroboration that the frame is where the paper says it is.
