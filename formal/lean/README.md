# `lean/` — Track L, the machine-checked bounded core (deliverable D4)

A Lean 4 mechanization of the bounded core of the finite-characterization
result: the calculus at a finite bound as a decidable successor function,
equivariance under renaming, finiteness of the configuration type, explorer
soundness and completeness, the bounded characterization theorem, and the
cutoff isolated as a single named axiom with the final theorem derived
conditionally on it.

**Core Lean only — no mathlib, no external packages.** `lake-manifest.json`
lists zero dependencies; the finite-enumeration infrastructure (`FinEnum`) is
built from scratch in `Bounded/Basic.lean`.

> Read [`PROOF_STATUS.md`](PROOF_STATUS.md) before citing anything from here.
> It lists every theorem with its status, the exact bound and state count
> mechanized, every `native_decide` (added compiler trust) and the one axiom,
> and a plain-language statement of what may and may not be concluded.

## Build

```sh
# one-time: install the toolchain manager (skip if you already have elan)
curl -sSfL https://elan.lean-lang.org/elan-init.sh | sh -s -- -y

# build (elan fetches leanprover/lean4:v4.33.1 as pinned in lean-toolchain)
lake build
```

Expected: `Build completed successfully (30 jobs).` — no errors, no warnings,
no `sorry`. A clean build takes about **5 minutes**; roughly 3½ of those are
the two `native_decide` checks for Theorem A (≈8.2 M equations each) and one
minute is the explorer certificate check.

If `lake` is not on your `PATH`, use `~/.elan/bin/lake`.

Incremental builds of a single module:

```sh
lake build Bounded.Enum      # Theorem B          (fast)
lake build Bounded.Explore   # Theorem C          (~1 min)
lake build Bounded.Charact   # Theorem D          (fast)
lake build Bounded.Cutoff    # Theorems E, F      (fast)
lake build Bounded.Equiv     # Theorem A          (~4 min)
```

## Checking the trust base yourself

```sh
cat > /tmp/audit.lean <<'EOF'
import Bounded
#print axioms Bounded.config_finite            -- Theorem B
#print axioms Bounded.theoremA                 -- Theorem A
#print axioms Bounded.reachable_iff_visited    -- Theorem C
#print axioms Bounded.theoremD                 -- Theorem D
#print axioms Bounded.theoremF                 -- Theorem F (uses the axiom)
#print axioms Bounded.conformance_iff_passes_suite
EOF
lake env lean /tmp/audit.lean
```

Anything named `…_native.native_decide.ax_1_1` is a compiled-evaluation
result (compiler trust); `Bounded.transport_cutoff` is the single deliberate
axiom. `Classical.choice` appears nowhere.

## Reproducing the state count outside the proof

```sh
lake build probe && ./.lake/build/bin/probe
```

Prints the reachable state count, edge count and longest access word for the
shipped catalog `[cProv, cCons, cReg]` (**15 173** states, 77 295 edges,
longest shortest-access word 34) and for each sub-catalog. This executable is
not part of the library and is not built by a bare `lake build`.

## Layout

| file | contents |
| ---- | -------- |
| `Bounded.lean` | the library root; imports everything below |
| `Bounded/Basic.lean` | `FinEnum` (mathlib-free finite enumeration), decidable finite quantifiers, bounded lists `BList` |
| `Bounded/Perm.lean` | the renaming groups: S₃ on slots, Z₂ on keys and on values; `Ren` |
| `Bounded/Calc.lean` | the bounded state space — `Step`, `Component`, `LState`, `Fiber`, `Config`, and the derived notions (`providerOf`, `targetOf`, `reliedUpon`, `quiet`, `readC`, `WF`) |
| `Bounded/SigDec.lean` | the ten rules in clause-factored form: the signature alphabet `SigR` and abstraction `sig`, the specification table `fS`, the reconstruction operator `liftStep`, `specStep`, observations, and the component catalog |
| `Bounded/Enum.lean` | **Theorem B** — finiteness of `Config` |
| `Bounded/Explore.lean` | **Theorem C** — the reachability relation, the verified worklist explorer, the shipped exploration and its certificate |
| `Bounded/Equiv.lean` | **Theorem A** — the renaming action and equivariance |
| `Bounded/Charact.lean` | **Theorem D** — transition certificates and the bounded characterization |
| `Bounded/Cutoff.lean` | **Theorem E** (the axiom) and **Theorem F** |
| `probe/Main.lean` | standalone state-space counter (not part of the library) |

## The headline statements

```lean
-- B, finiteness
theorem config_finite : ∀ γ : Config, γ ∈ (all : List Config)

-- A, equivariance (reachable domain, childComp-fixing renamings)
theorem theoremA :
    ∀ γ ∈ visited, ∀ r ∈ kRens, ∀ a ∈ catalogActs,
      specStep (renAct r a) (renConfig r γ) = (specStep a γ).map (renRow r)

-- C, explorer soundness + completeness
theorem reachable_iff_visited (γ : Config) : Reachable γ ↔ γ ∈ visited

-- D, bounded characterization
theorem theoremD (fI : SigR → Dec) : AgreesOnTB fI ↔ Bisimilar fI fS

-- E, the single axiom (paper Lemma 4, transport)
axiom transport_cutoff (fI : SigR → Dec) : AgreesOnReach fI → ConfB fI

-- F, the final characterization
theorem theoremF (fI : SigR → Dec) :
    (AgreesOnTB fI ↔ Bisimilar fI fS) ∧
    (AgreesOnTB fI ↔ AgreesOnReach fI) ∧
    (AgreesOnTB fI → ConfB fI)
```

## Context

- `../MASTER.md` — the two-track proof program; this directory is D4.
- `../paper.md` — §5.2 (Lemmas 1–3), §6.2 (transport), §6.3 (reflection and
  the necessity of certificates), §7 (mechanization status).
- `../../proof/src/model.mjs` — the executable reference semantics this
  mirrors.
