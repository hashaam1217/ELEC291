/*
   20000717-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports long long constants!
#if 0
static void
compare (long long foo)
{
  if (foo < 4294967297LL)
    ASSERT (0);
}
#endif

void
testTortureExecute (void)
{
#if 0
  compare (8589934591LL);
  return;
#endif
}


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20000717-2";
}
