#!/bin/sh
# The congruence portfolio: the explorer's own bound family (explorer-report.md
# §4), re-run as κ-congruence checks.  Each run is independent; the verdict is
# the union.
set -e
N="node --max-old-space-size=8000 run-congruence.mjs"
$N --tag=A1    --maxFibers=1 --maxStates=500000
$N --tag=A2c   --maxFibers=2 --noUpdates --noSetowns --maxStates=500000
$N --tag=A2w   --maxFibers=2 --maxStates=300000 --timeBudgetMs=1200000
$N --tag=sat3  --maxFibers=3 --shapes=P,C --maxStates=400000 --timeBudgetMs=1200000
$N --tag=dep3  --maxFibers=3 --shapes=P,M,CC,CRR --maxStates=400000 --timeBudgetMs=1200000
$N --tag=fail3 --maxFibers=3 --shapes=P,FP,C --maxStates=400000 --timeBudgetMs=1200000
$N --tag=regB  --maxFibers=3 --shapes=P,A --noChildInserts --noUpdates --noSetowns --maxStates=400000 --timeBudgetMs=1200000
$N --tag=regA  --maxFibers=3 --shapes=P,A --maxStates=300000 --timeBudgetMs=1200000
$N --tag=A3c   --maxFibers=3 --noUpdates --noSetowns --maxStates=300000 --timeBudgetMs=1200000
