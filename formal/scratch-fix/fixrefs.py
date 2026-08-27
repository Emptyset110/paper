#!/usr/bin/env python3
import pathlib, sys
P = pathlib.Path('/home/rebuilding/Studio/cordis-dev/paper/formal/paper.md')
t = P.read_text()
R = [
    ('For in-place overwrite by an Active provider, §5.1.3 prescribes',
     'For in-place overwrite by an Active provider, [SZC26] §5.1.3 prescribes'),
    ('(read with $\\mathsf{Right}$ around the triple where §4.3.4 applies)',
     '(read with $\\mathsf{Right}$ around the triple where [SZC26] §4.3.4 applies)'),
    ('with the $\\mathsf{land}$-only restriction under the inertia of §4.3.3',
     'with the $\\mathsf{land}$-only restriction under the inertia of [SZC26] §4.3.3'),
    ('Authority order in case of doubt: [SZC26] Table 1 and the rule statements of §4.2–§4.3',
     'Authority order in case of doubt: [SZC26] Table 1 and its rule statements of §4.2–§4.3'),
    ("We adopt the reference semantics' reading: removal fires during settle whenever its premises hold, as the §5.2 loader does.",
     "We adopt the reference semantics' reading: removal fires during settle whenever its premises hold, as the loader of [SZC26] §5.2 does."),
    ('The two alternatives (abort the held iteration / let it land) are the rule\'s own disjunction; §4.3.3 restricts a host under inertia to the landing alternative.',
     'The two alternatives (abort the held iteration / let it land) are the rule\'s own disjunction; [SZC26] §4.3.3 restricts a host under inertia to the landing alternative.'),
    ('*between an iteration\'s launch and its landing* (§4.3.3 inertia)',
     '*between an iteration\'s launch and its landing* ([SZC26] §4.3.3 inertia)'),
    ("This is exactly the visibility half of §4.3.1's ordering promise.",
     "This is exactly the visibility half of [SZC26] §4.3.1's ordering promise."),
    ('with a note that its *unreachability* is itself Theorem 63\'s testable content',
     'with a note that its *unreachability* is itself Thm. 63\'s testable content'),
    ("Adopted reading (matching the reference semantics and §5.2's loader)",
     "Adopted reading (matching the reference semantics and the loader of [SZC26] §5.2)"),
    ("$\\Lambda_{\\mathrm{orch}}$'s update(n,cfg) (and the loader behavior of §5.2)",
     "$\\Lambda_{\\mathrm{orch}}$'s update(n,cfg) (and the loader behavior of [SZC26] §5.2)"),
    ("- **A9 — L-Divert's landing alternative needs asynchrony.** §4.3.3's inertia",
     "- **A9 — L-Divert's landing alternative needs asynchrony.** [SZC26] §4.3.3's inertia"),
    # notation note: disambiguate spelled-out Lemma citations
    ("numbered items without that prefix are this paper's.",
     "numbered items without that prefix are this paper's. Where the source paper's items are cited spelled out — its Lemmas 54–72, which have no standard abbreviation — the numbering ranges keep the reference unambiguous: this paper's Lemmas are 1–12, its Theorems 1–6, its Definitions 1–10, and no item of [SZC26] cited here falls in those ranges under the same spelling."),
]
miss = [a for a, _ in R if a not in t]
if miss:
    print('MISSING:', *[m[:70] for m in miss], sep='\n  '); sys.exit(1)
for a, b in R:
    t = t.replace(a, b, 1)
P.write_text(t)
print('ok')
