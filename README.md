# A Programming Paradigm for Spatiotemporal Composability

**[Read the paper (PDF)](paper.pdf)** · Draft of August 26, 2026

> This is a preprint under active revision. The content may change substantially; please cite the latest version and check back before relying on specific results.

## Abstract

Modern software—from plugin systems to self-evolving agent harnesses—increasingly requires _dynamic composition_, yet its formal foundations remain underdeveloped. We identify two orthogonal dimensions of the problem: _temporal composability_, the ability to completely revert a component's side effects upon removal, and _spatial composability_, the ability to declare and reactively manage inter-component dependencies.
We address the two dimensions by lifting classical effect and coeffect concepts to runtime mechanisms.
In particular, we formalize _revertible effects_, in which every context transformation carries an inverse that the runtime holds, establishing temporal composability local to one component.
We formalize _reactive coeffects_, in which every context change is classified against a component's coeffect specification to drive its activation and deactivation, establishing spatial composability local to one component.
We then unify the effect context and the coeffect context into a single context type and mediate every effect and coeffect through it, yielding a discipline we call the _context paradigm_; the mediation induces an observational equivalence up to which the effects of distinct components interleave without disturbing one another.
Combining these mechanisms into the notion of a _component_, we give a calculus of dynamic composition whose metatheory carries spatiotemporal composability from a single component to a whole system of interleaved components.
We implement these ideas in _Cordis_, a meta-framework of spatiotemporal composability that provides a core library with effect tracking and coeffect resolution, as well as a declarative component loader with configuration reconciliation and hot module replacement.

## Acknowledgments

We thank [@TZZheng](https://github.com/TZZheng) and [@thwfhk](https://github.com/thwfhk) for their feedback and corrections on earlier drafts of this paper.

## Contact

Questions, comments, and corrections about the paper are welcome by email: [shigma@cordis.io](mailto:shigma@cordis.io).
