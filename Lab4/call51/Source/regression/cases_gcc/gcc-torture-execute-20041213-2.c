/*
   20041213-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/18694

   The dominator optimization didn't take the PHI evaluation order
   into account when threading an edge.  */

void
foo (int i)
{
  int next_n = 1;
  int j = 0;

  for (; i != 0; i--)
    {
      int n;

      for (n = next_n; j < n; j++)
	next_n++;

      if (j != n)
	ASSERT (0);
    }
}

void
testTortureExecute (void)
{
  foo (2);
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
  return "cases_gcc\\gcc-torture-execute-20041213-2";
}
