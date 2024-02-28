/*
   20051215-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR rtl-optimization/24899 */

int
foo (int x, int y, int *z)
{
  int a, b, c, d;

  a = b = 0;
  for (d = 0; d < y; d++)
    {
      if (z)
	b = d * *z;
      for (c = 0; c < x; c++)
	a += b;
    }

  return a;
}

void
testTortureExecute (void)
{
  if (foo (3, 2, 0) != 0)
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
  return "cases_gcc\\gcc-torture-execute-20051215-1";
}
