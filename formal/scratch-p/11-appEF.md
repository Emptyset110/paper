## Appendix E. Bounded State-Space Computations

This appendix contains the manual state-space computations produced concurrently with this manuscript: hand-executed bounded explorations of the reference semantics that enumerate reachable normalized configurations and per-rule windows at small bounds, confirm the reachability column of Appendix D (both its positive claims and its six negative claims, I5, D2, D6, V2, A4, A7), and exhibit the witness configurations the proofs point at — in particular a reachable $\prec$-cyclic configuration exercising Theorem 5's generality beyond [SZC26] Thm. 66. The computations are spliced in below.

<!-- SPLICE: derivations.md -->

## Appendix F. The Deviant Family

The 27 semantic deviants instrumenting necessity (§8.1) are defined in the reference semantics (`proof/src/model.mjs`, `MUTANTS`; Appendix A). Formally, each deviant $\mathbb S^{\mu}$ is the specification $\mathbb S$ with exactly one semantic decision negated — one entry (or one lift clause) of one rule's or operation's decision table replaced — all else unchanged. Every member is clause-factored (its modified decision is still a function of the occurrence data, combined by the specified lift), hence inside $\mathfrak I_{\mathrm{CF}}$: the family probes the theorem's necessity direction from within the class it quantifies over. The kill matrix (§8.2) certifies every member is distinguished by the suite under exhaustive schedule enumeration.

| # | deviant | negated clause | semantics (one line) |
| --- | --- | --- | --- |
| 1 | `insert-allows-disposed-parent` | O-Insert premise (ii) | inserts under a removed/absent parent are accepted instead of refused. |
| 2 | `insert-allows-duplicate-provider` | O-Insert premise (iv) | the declared-provision disjointness premise is unenforced at insertion. |
| 3 | `dynamic-conflict-ignored` | Def. 23 set precondition | a conflicting provide overwrites the standing binding instead of failing the offender (negates X4's Left). |
| 4 | `retire-discards-accumulator` | O-Retire / L-Unload routing | retirement jumps the fiber to Inactive directly, discarding the accumulator's inverses. |
| 5 | `remove-before-inactive` | O-Remove premise $\theta = \mathsf{Inactive}(-)$ | removal races the unload instead of following it. |
| 6 | `begin-without-deps` | L-Begin premise $\mathrm{target} \neq \bot$ | activation fires without $\gamma \vDash d_n$. |
| 7 | `satisfied-by-installed-provider` | eq. 40 | $\sigma_\gamma$ unions *installed* tables, not Active ones (negates B6's blocking). |
| 8 | `begin-from-failed` | L-Begin premise $\mathsf{Inactive}(\bot)$ | the lifecycle is re-entered from $\mathsf{Inactive}(\xi)$ (negates B2). |
| 9 | `accumulator-fifo` | eq. 48 / lift order | inverses composed and applied in application (FIFO) order instead of LIFO. |
| 10 | `no-commit-view` | L-Iter reads / Def. 46 | reads resolve against the live registry instead of the committed view $\omega$. |
| 11 | `divert-skips-recovery` | L-Divert conclusion | a diverted transition discards the accumulator instead of routing recovery through Unloading. |
| 12 | `raise-skips-recovery` | L-Raise / L-Unload routing | a raising iteration records the error without recovering (the accumulator never runs). |
| 13 | `failed-still-provides` | eq. 40 | $\mathsf{Inactive}(\xi)$ fibers keep their tables in $\sigma_\gamma$. |
| 14 | `leave-keeps-providing` | eq. 40 | Unloading fibers keep their tables in $\sigma_\gamma$ (negates L-Leave's derived withdrawal). |
| 15 | `unload-without-guard` | L-Unload premise $\neg\mathrm{relied}_n$ | the reliance guard is deleted; providers unload under installed dependents. |
| 16 | `unload-clears-view-early` | L-Unload write order | the committed view is dropped before the inverses run (negates U8 / Thm. 63's teardown read). |
| 17 | `unload-skips-child-retire` | Def. 47 inverse | the registration inverse forgets the child: no O-Retire of the registered fiber. |
| 18 | `overwrite-tears-episode` | Def. 24 / Thm. 63(3) | an in-place overwrite re-runs dependents without recovery (a torn episode; the PB-2 dichotomy violated). |
| 19 | `proxy-no-ancestry` | Algorithm 6 walk | the resolution walk omits the fiber-ancestry chain (negates A2/T6). |
| 20 | `isolate-shared` | Def. 29 | isolation resolves every realm to the shared one. |
| 21 | `intercept-outer-wins` | Def. 31 right-bias | the outermost intercept entry takes priority over the nearer one (negates N4). |
| 22 | `proxy-skips-inactive-check` | Algorithm 6 line 5 | the declared-uncommitted (IA) exit is dropped (negates T7/A3). |
| 23 | `proxy-allows-undeclared` | Algorithm 6 line 6 | the undeclared (UD) exit at root is dropped (negates T8/A5). |
| 24 | `guard-only-direct` | Def. 50 reading | the guard releases while dependents are merely Unloading rather than Inactive — transitive wait chains skipped. |
| 25 | `recovery-leaves-residue` | L-Unload lift (one $\mathsf{apply\mbox{-}inverse}$ item) | one binding survives the accumulator's application. |
| 26 | `refresh-misses-pending` | CF6 exactness / enabledness | a provider becoming Active does not re-enable pending L-Begin windows during the same settle. |
| 27 | `update-keeps-stale-binding` | the A3 update extension | provider replacement leaves dependents on the old committed provider (V5's bounce skipped for dependents). |

---

## References

- [SZC26] Y. Shi, W. Zhang, T. Cui. *A Programming Paradigm for Spatiotemporal Composability.* Preprint, 2026. (`../paper.pdf`)
- [Gau95] M.-C. Gaudel. *Testing can be formal, too.* TAPSOFT '95, LNCS 915, 1995.
- [Tre96] J. Tretmans. *Test generation with inputs, outputs and repetitive quiescence.* Software—Concepts and Tools 17(3), 1996.
- [Tre08] J. Tretmans. *Model based testing with labelled transition systems.* In *Formal Methods and Testing*, LNCS 4949, 2008.
- [Cho78] T. S. Chow. *Testing software design modeled by finite-state machines.* IEEE TSE 4(3), 1978.
- [DLS78] R. A. DeMillo, R. J. Lipton, F. G. Sayward. *Hints on test data selection.* IEEE Computer 11(4), 1978.
- [BOY00] P. E. Black, V. Okun, Y. Yesha. *Mutation operators for specifications.* ASE 2000.
- [JH11] Y. Jia, M. Harman. *An analysis and survey of the development of mutation testing.* IEEE TSE 37(5), 2011.
- [PAO17] M. Papadakis, Y. Jia, M. Harman, et al. *Mutation testing advances.* Advances in Computers, 2017.
- [Fel09] M. Felleisen, R. B. Findler, M. Flatt. *Semantics Engineering with PLT Redex.* MIT Press, 2009.
- [RŞ10] G. Roşu, T. F. Şerbănuţă. *An overview of the K semantic framework.* JLAP 79(6), 2010.
