/*
   pr46909-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/46909 */

int
foo (int x)
{
  if ((x != 0 && x != 13) || x == 5 || x == 20)
    return 1;
  return -1;
}

void
testTortureExecute (void)
{
  int i;
  for (i = -10; i < 30; i++)
    if (foo (i) != 1 - 2 * (i == 0) - 2 * (i == 13))
      ASSERT (0);
  return;
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
  return "cases_gcc\\gcc-torture-execute-pr46909-2";
}
