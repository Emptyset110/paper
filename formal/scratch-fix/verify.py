#!/usr/bin/env python3
"""Verification pass over paper.md: numbering, cross-references, math delimiters."""
import re, collections, pathlib

P = pathlib.Path('/home/rebuilding/Studio/cordis-dev/paper/formal/paper.md')
raw = P.read_text().split('\n')

# ---- strip fenced code blocks for math/reference checks ----------------
infence = False
mask = []           # True = ordinary prose line
for l in raw:
    if l.startswith('```'):
        infence = not infence
        mask.append(False); continue
    mask.append(not infence)

def prose():
    for i, l in enumerate(raw):
        if mask[i]:
            yield i + 1, l

text_prose = '\n'.join(l for i, l in enumerate(raw) if mask[i])

# ---- 1. numbering ------------------------------------------------------
KINDS = ['Definition', 'Theorem', 'Lemma', 'Proposition', 'Corollary', 'Remark']
decl = collections.defaultdict(list)
for ln, l in prose():
    for m in re.finditer(r'\*\*(' + '|'.join(KINDS) + r') (\d+)', l):
        decl[m.group(1)].append((int(m.group(2)), ln))
print('== declarations ==')
for k in KINDS:
    seq = decl[k]
    nums = [n for n, _ in seq]
    dup = [n for n, c in collections.Counter(nums).items() if c > 1]
    mono = all(nums[i] <= nums[i + 1] for i in range(len(nums) - 1))
    gaps = [n for n in range(1, (max(nums) if nums else 0) + 1) if n not in nums]
    print(f'{k:12} n={len(nums):3} max={max(nums) if nums else 0:3} '
          f'monotone={mono} dups={dup} missing={gaps}')

# ---- 2. cross-references ----------------------------------------------
print('\n== cross-references ==')
# section headings present
heads = {}
for ln, l in prose():
    m = re.match(r'^(#{2,4}) (.+)$', l)
    if m:
        heads[m.group(2).strip()] = ln
sections = set()
for h in heads:
    m = re.match(r'^(\d+(?:\.\d+)*)\.? ', h)
    if m: sections.add(m.group(1))
    m = re.match(r'^Appendix ([A-F])', h)
    if m: sections.add('App' + m.group(1))
    m = re.match(r'^([A-F]\.\d+)', h)
    if m: sections.add(m.group(1))
    m = re.match(r'^(E\.(?:[A-Z]{2}\.[A-Z]?\d+|U\.\d+|\d+(?:\.\d+)*))', h)
    if m: sections.add(m.group(1))

bad = collections.Counter()
for ln, l in prose():
    for m in re.finditer(r'§(\d+(?:\.\d+)*)', l):
        if m.group(1) not in sections:
            bad['§' + m.group(1)] += 1
    for m in re.finditer(r'(?<![A-Za-z0-9])([CDE]\.\d+(?:\.\d+)?)(?![0-9])', l):
        if m.group(1) not in sections:
            bad[m.group(1)] += 1
    for m in re.finditer(r'\b(E\.(?:[A-Z]{2}\.[A-Z]?\d+|U\.\d+))', l):
        if m.group(1) not in sections:
            bad[m.group(1)] += 1
    for m in re.finditer(r'Appendix ([A-Z])', l):
        if 'App' + m.group(1) not in sections:
            bad['Appendix ' + m.group(1)] += 1
print('unresolved section refs:', dict(bad) or 'none')

# numbered-item refs resolve
for kind in KINDS:
    have = {n for n, _ in decl[kind]}
    short = {'Theorem': 'Thm', 'Definition': 'Def', 'Proposition': 'Prop', 'Corollary': 'Cor'}
    missing = collections.Counter()
    for ln, l in prose():
        for m in re.finditer(rf'\b{kind}s? (\d+)(?:/(\d+))?', l):
            for g in m.groups():
                if g and int(g) not in have:
                    missing[int(g)] += 1
    if missing:
        print(f'  {kind}: refs with no declaration: {dict(missing)}')

# obligations and CF tags
for tag_re, universe in [(r'\(D-([A-Z])\)', set('ABCDEFGH')), (r'\bCF(\d)\b', set('1234567'))]:
    used = {m.group(1) for ln, l in prose() for m in re.finditer(tag_re, l)}
    extra = used - universe
    if extra: print('  unexpected tags:', tag_re, extra)

# script ids: every S-xxx cited must be defined somewhere in D or E
scripts = collections.Counter(m.group(0) for ln, l in prose()
                              for m in re.finditer(r'\bS-[A-Za-z]{3}-\d+\b', l))
print('  distinct script ids cited:', len(scripts))

# occurrence ids sanity: ids used vs alphabet tables
print('\n== suspicious phrases ==')
PAT = r'proof shape|see artifact|TODO|TBD|FIXME|\bXXX\b|to be (?:written|supplied|done)|omitted here|left to the reader|will accompany|forthcoming|placeholder|<!--'
for ln, l in prose():
    for m in re.finditer(PAT, l, re.I):
        print(f'  {ln}: …{l[max(0,m.start()-60):m.start()+80]}…')

# ---- 3. math delimiters ------------------------------------------------
print('\n== math delimiters ==')
display = 0
bad_inline = []
for ln, l in prose():
    # remove inline code spans
    s = re.sub(r'`[^`]*`', '', l)
    display += s.count('$$')
    s2 = s.replace('$$', '')
    if s2.count('$') % 2:
        bad_inline.append((ln, l[:100]))
print('  $$ count (should be even):', display, 'even' if display % 2 == 0 else 'ODD')
print('  lines with odd inline $:', len(bad_inline))
for ln, l in bad_inline[:20]:
    print(f'    {ln}: {l}')

# unbalanced \left \right, braces in math
for ln, l in prose():
    s = re.sub(r'`[^`]*`', '', l)
    if s.count('\\left') != s.count('\\right'):
        print(f'  left/right mismatch {ln}: {s[:90]}')

# ---- 4. structural -----------------------------------------------------
print('\n== structure ==')
print('  lines:', len(raw))
prev = 0
for ln, l in prose():
    m = re.match(r'^(#{1,4}) ', l)
    if m:
        lvl = len(m.group(1))
        if lvl > prev + 1 and prev:
            print(f'  heading level jump at {ln}: {l[:70]}')
        prev = lvl
# blank line before headings
for i, l in enumerate(raw):
    if mask[i] and re.match(r'^#{1,4} ', l) and i > 0 and raw[i-1].strip():
        print(f'  no blank line before heading {i+1}: {l[:60]}')
# table sanity: rows with inconsistent pipe counts
tbl = []
for i, l in enumerate(raw):
    if mask[i] and l.startswith('|'):
        tbl.append((i + 1, l.count('|')))
    else:
        if len(tbl) > 1:
            counts = collections.Counter(c for _, c in tbl)
            if len(counts) > 1:
                print(f'  ragged table near line {tbl[0][0]}: {dict(counts)}')
        tbl = []
