#!/usr/bin/env python3
"""Splice derivations.md (Appendix E) into paper.md at the SPLICE marker,
adapting headings and cross-references to the paper's unified scheme."""
import re, sys, pathlib

BASE = pathlib.Path('/home/rebuilding/Studio/cordis-dev/paper/formal')
src = (BASE / 'derivations.md').read_text()
paper = (BASE / 'paper.md').read_text()

lines = src.split('\n')

# ---------------------------------------------------------------- 1. preamble
# Drop derivations.md's own H1 title + italic preamble + the following rule.
# The file starts:
#   # Appendix E. ...\n\n*Companion ... §§1.4–14.3.*\n\n---\n\n## E.0 Conventions
i = next(n for n, l in enumerate(lines) if l.startswith('## E.0 Conventions'))
body = lines[i:]

PREAMBLE = """*This appendix carries out, by hand, the state-space computations that
Appendix D's script index only outlines: for every canonical script
$\\rho_{r,s}$ of Appendix D (all 60) an explicit configuration sequence
$\\gamma_0 \\to \\gamma_1 \\to \\cdots \\to \\gamma_k$, one line per rule
application, each line checkable against the rule statements of [SZC26]
§4.2–§4.3 (pp. 31–38; summarized in Table 1) with nothing else at hand;
and for each of Appendix D's six interface-unrealizable occurrences a
complete invariant proof. Internal references Def. 43–53, Thm. 63/66 are
to [SZC26]; the occurrence ids I1–I7, R1–R4, M1–M7, B1–B7, T1–T11,
F1–F3, D1–D6, X1–X9, V1–V5, U1–U12, P1–P6, S1–S4, N1–N4, A1–A7 and the
script ids S-⋆ are Appendix D's (D.1–D.14). Item ids of the form
E.LB.B6 are cited from Appendix D and from §6.5; the artifact source of
this appendix is `formal/derivations.md` (Appendix A).*"""

text = '\n'.join(body)

# ------------------------------------------------------- 2. heading demotion
out, infence = [], False
for l in text.split('\n'):
    if l.startswith('```'):
        infence = not infence
        out.append(l); continue
    if not infence and re.match(r'^### ', l):
        out.append('#' + l)
    elif not infence and re.match(r'^## ', l):
        out.append('#' + l)
    else:
        out.append(l)
text = '\n'.join(out)

# ------------------------------------------- 3. the "Corrections" block header
text = text.replace(
    "---\n\n### Corrections to D1 (read first)\n",
    "#### E.0.5 Corrections to Appendix D (read first)\n", 1)

# ------------------------------------------------- 4. cross-reference rewrites
REPL = [
    # E.0 conventions
    ("are the A3-extension inputs (D1 §17).",
     "are the A3-extension inputs (D.16, ambiguity A3)."),
    ("in the §2.2 script syntax.", "in Definition 2's script syntax."),
    ('event. Blocking occurrences (D1\'s "refusing"/"blocking" letters) are',
     'event. Blocking occurrences (Appendix D\'s "refusing"/"blocking" letters) are'),
    ("lifecycle steps and O-Remove (D1 A1 reading) until quiet(γ) (eq. 45).",
     "lifecycle steps and O-Remove (D.16's A1 reading) until quiet(γ) (eq. 45)."),
    ("Algorithm 6 (the access walk, with D1's A6 landing convention and A8",
     "Algorithm 6 (the access walk, with D.16's A6 landing convention and A8"),
    ("the item says so explicitly, per D1 §0's convention; the verdict",
     "the item says so explicitly, per D.0's convention; the verdict"),
    # corrections block (read first)
    ("- **C1 (error — S-Div-3 / signature D3).** D1's printed script",
     "- **C1 (error — S-Div-3 / signature D3).** The script printed for\n  S-Div-3 in the draft signature tables (deliverable D1,\n  `signatures.md` §7.4),"),
    ("  the fact D1 itself establishes at §1 (I7:",
     "  the fact D.1 itself establishes (I7:"),
    ("- **C2 (reading — U10–U12 bookkeeping).** D1's S-Unl-3 window is",
     "- **C2 (reading — U10–U12 bookkeeping).** D.10's S-Unl-3 window was"),
    ("  every D1 window listing: **U10–U12 are conditioned on ζ=⊥**; a ζ=ξ",
     "  every window listing of Appendix D: **U10–U12 are conditioned on\n  ζ=⊥**; a ζ=ξ"),
    ('  D1\'s claim "S-Rem-2 realizes M2" stands; the full multiset is stated',
     '  D.3\'s claim "S-Rem-2 realizes M2" stands; the full multiset is stated'),
    ("  at E.OM.M2. Not an error — D1 §0 allows co-realization — but the",
     "  at E.OM.M2. Not an error — D.0 allows co-realization — but the"),
    # body items
    ("fact (D1 §1.3): P is In(⊥) — *declared* provisions block, no settle or",
     "fact (D.1): P is In(⊥) — *declared* provisions block, no settle or"),
    ("membership only; the state class is write-aspect bookkeeping (D1 §2).",
     "membership only; the state class is write-aspect bookkeeping (D.2)."),
    ("raise(x)) ✓; no view premise (D1 A2).",
     "raise(x)) ✓; no view premise (D.16's A2)."),
    ("Per D1's A1 reading, O-Remove fires during settle whenever its premises",
     "Per D.16's A1 reading, O-Remove fires during settle whenever its premises"),
    ("freedom** — the B6 occurrence is *schedule-dependent* (D1 §0",
     "freedom** — the B6 occurrence is *schedule-dependent* (D.0"),
    ("the canonical branch, as D1's sketch says.",
     "the canonical branch, as D.4's script note says."),
    ("matches neither of D1's printed F-atoms; per the Correction-C4",
     "matches neither of the draft F-atoms; per the Correction-C4"),
    ("reachability fact of D1 (§5.3), now fully checked: three settles build",
     "reachability fact of Appendix D (D.5), now fully checked: three settles build"),
    ("V_{LD,D1} accepts the set. The exhaustive explorer (D3 deliverable)\nmust visit all three, as D1's sketch demands.",
     "V_{LD,D1} accepts the set. The exhaustive explorer (§7)\nmust visit all three, as D.7's script note demands."),
    ("(D1's printed ρ puts `insert(root, Q2)` before any settle following",
     "(The draft script of D1 §7.4 put `insert(root, Q2)` before any settle following"),
    ("Table-1 rule — flagged per D1 Dev-7/A3).",
     "Table-1 rule — flagged per D.16's A3)."),
    ("realized in the A7-extended grammar only (D1 §10.3/§17-A7).",
     "realized in the A7-extended grammar only (D.10; D.16's A7)."),
    ("### E.LU.U12 — signature U12 (script S-Unl-9, D1's corrected ρ′)",
     "#### E.LU.U12 — signature U12 (script S-Unl-9, the corrected ρ′)"),
    ("(D1 §10.4 already replaces its first attempt by this ρ′; the first",
     "(D.10 states this ρ′; the draft's first"),
    ("such by D1. Deterministic.", "such by Appendix D. Deterministic."),
    ("⊕_k folds every deeper chain to this pattern (D1 §13.1).",
     "⊕_k folds every deeper chain to this pattern (D.13)."),
    ("registry — D1's definition of reachability (§0). Proofs are by",
     "registry — Appendix D's definition of reachability (D.0, obligation\n(D-B)). Proofs are by"),
    ("set/provide landing, whose precondition — the reading D1 §8 fixes at",
     "set/provide landing, whose precondition — the reading D.8 fixes at"),
    ("extension. (D1 A10, now proved rather than sketched.) ∎",
     "extension. (D.16's A10, now proved rather than sketched.) ∎"),
    ("the word inv(P,c) < inv(P,b) < inv(P,a) < deact(P) is PAPER_REWRITE\n§5.3's accumulator-order canonical test (kills accumulator-fifo).",
     "the word inv(P,c) < inv(P,b) < inv(P,a) < deact(P) is obligation\n(D-G)'s accumulator-order canonical test (kills accumulator-fifo)."),
    ("the instrumented 𝕊 (Def. 2 of the manuscript: script components, one",
     "the instrumented 𝕊 (Definition 2: script components, one"),
    ("(the atomicity Def. 2 fixes); the post-state",
     "(the atomicity Definition 2 fixes); the post-state"),
    ("Def. 2 (the Future layer) breaks BND exactly at the launch/landing",
     "Definition 2 (the Future layer) breaks BND exactly at the launch/landing"),
    ('once (the "committed-edge-pins-provider" lemma of manuscript §5.2).',
     'once (the "committed-edge-pins-provider" lemma of §5.3).'),
    ("(the reliance guard, §4.3.1).", "(the reliance guard, [SZC26] §4.3.1)."),
    ("This is the visibility half of §4.3.1's ordering promise, reappearing",
     "This is the visibility half of [SZC26] §4.3.1's ordering promise, reappearing"),
    ("**Inertia restriction.** §4.3.3 (p. 37):",
     "**Inertia restriction.** [SZC26] §4.3.3 (p. 37):"),
    ('makes possible"; the landing alternative is "where §4.3.3 is',
     'makes possible"; the landing alternative is "where [SZC26] §4.3.3 is'),
    ("deactivation-chains-into-activation composite, §4.3.3).",
     "deactivation-chains-into-activation composite, [SZC26] §4.3.3)."),
    ("`trackReadOnRevert` is the A7 extension of the §2.2 step grammar: its",
     "`trackReadOnRevert` is the A7 extension of Definition 2's step grammar: its"),
    # E.98
    ("### E.98 Corrections and clarifications to D1 (detail)",
     "### E.98 Corrections and clarifications to the draft signature tables (detail)"),
    ("**C1 (error): S-Div-3 does not reach D3; corrected script supplied.**\nD1 §7.4's printed ρ is",
     "**C1 (error): S-Div-3 does not reach D3; corrected script supplied.**\nThe ρ printed for S-Div-3 in the draft tables (D1, `signatures.md`\n§7.4) is"),
    ("and declared keys — D1 §1, Table 1 premise (iv) over",
     "and declared keys — D.1, Table 1 premise (iv) over"),
    ("refusal D1's own S-Ins-4 canonizes.", "refusal D.1's own S-Ins-4 canonizes."),
    ("{D1, D3, D5} at E.LD.D3(30); D1's component data is unchanged.\nD1 §7.4, §15 (script count unchanged: 2) and the D3 reachability row\nshould cite ρ′.",
     "{D1, D3, D5} at E.LD.D3(30); the component data is unchanged.\nD.7, D.15 (script count unchanged: 2) and the D3 reachability row\ncite ρ′; the correction is applied in this paper and in the artifact."),
    ("**C2 (reading): U10–U12 are conditioned on ζ=⊥.** D1 §10.1 defines",
     "**C2 (reading): U10–U12 are conditioned on ζ=⊥.** D.10 defines"),
    ("U10–U12 as the τ × post-target bookkeeping blocks; §10.4's S-Unl-3",
     "U10–U12 as the τ × post-target bookkeeping blocks; the draft's S-Unl-3"),
    ("B2. D1 §10.1 should annotate U10–U12 with \"ζ=⊥ only\".",
     "B2. D.10 annotates U10–U12 with \"ζ=⊥ only\"; the correction is applied\nin this paper and in the artifact."),
    ("(E.OM.M2(4)), of which D1 credits M2. Consistent with D1's\nsharing convention; stated for checkability.",
     "(E.OM.M2(4)), of which D.3 credits M2. Consistent with Appendix D's\nsharing convention; stated for checkability, and stated in D.3."),
    ("**C4 (alphabet imprecision): the F1/F2 split.** D1 §6.1 splits",
     "**C4 (alphabet imprecision): the F1/F2 split.** The draft tables split"),
    ("inside the letter, not as its definition. D1 §6.1's F1 atom should\nread \"after ≥ 1 landed iteration\" *simpliciter*. No script or\nreachability claim changes.",
     "inside the letter, not as its definition. D.6's F1 atom reads\n\"after ≥ 1 landed iteration\" *simpliciter*; the correction is applied\nin this paper and in the artifact. No script or reachability claim\nchanges."),
    ("**E1 (editorial).** D1 §4.4's S-Beg-5 retains an abandoned draft\nfragment (\"`retire(C2)?` — no: …\") before its final ρ; E.LB.B6\nderives the final ρ. D1 §10.4's S-Unl-9 similarly self-corrects\nmid-paragraph to ρ′; E.LU.U12 derives ρ′. Both should be cleaned to\nstate only the surviving script.",
     "**E1 (editorial).** The draft's S-Beg-5 retained an abandoned draft\nfragment (\"`retire(C2)?` — no: …\") before its final ρ; E.LB.B6\nderives the final ρ. The draft's S-Unl-9 similarly self-corrected\nmid-paragraph to ρ′; E.LU.U12 derives ρ′. Both are cleaned in the\nartifact to state only the surviving script; D.4 and D.10 print only\nthe surviving scripts."),
    # E.99
    ("Every reachable occurrence of D1 §15's summary (86) has exactly one",
     "Every reachable occurrence of D.15's summary (86) has exactly one"),
    ("**Item count check against D1 §15.**", "**Item count check against D.15.**"),
    ("CO-Acc 1 new — **60 items**, matching D1's 60 canonical scripts",
     "CO-Acc 1 new — **60 items**, matching Appendix D's 60 canonical scripts"),
    ("E.U.3 (D2), E.U.4 (V2), E.U.5 (A4), E.U.6 (A7) — matching D1 §15's\nsix negatives. The explorer deliverable (D3) cross-checks both\ncolumns at bound B₀.",
     "E.U.3 (D2), E.U.4 (V2), E.U.5 (A4), E.U.6 (A7) — matching D.15's\nsix negatives. The bounded explorer of §7 cross-checks both columns\nat its bound; §7 reports which of the six it independently confirms\nand which lie outside its signature vocabulary."),
    ("Out(ρ′) collects all interleavings; the explorer must confirm.",
     "Out(ρ′) collects all interleavings; the explorer of §7 collects them."),
]

missing = []
for a, b in REPL:
    if a not in text:
        missing.append(a[:60])
    text = text.replace(a, b, 1)

if missing:
    print("MISSING PATTERNS:", file=sys.stderr)
    for m in missing:
        print("  ", m, file=sys.stderr)
    sys.exit(1)

# residual D1-as-deliverable check (occurrence id D1 is legitimate)
for m in re.finditer(r"D1(?![-–—0-9])", text):
    ctx = text[max(0, m.start() - 40):m.start() + 40].replace('\n', ' ')
    if re.search(r"D1 §7\.4|deliverable D1|\(D1, `signatures", ctx):
        continue
    if re.search(r"\{D1|D1,|D1\}|V_\{LD,D1\}|E\.LD\.D1|\| D1 \||\*\*D1\*\*|D1 branch|D1\(|signature D1", ctx):
        continue
    print("RESIDUAL D1:", ctx, file=sys.stderr)

# trailing blank lines
text = text.rstrip() + '\n'

block = PREAMBLE + '\n\n' + text

MARK = '<!-- SPLICE: derivations.md -->'
assert MARK in paper
paper = paper.replace(MARK, block, 1)
(BASE / 'paper.md').write_text(paper)
print('spliced; paper lines =', paper.count('\n') + 1)
