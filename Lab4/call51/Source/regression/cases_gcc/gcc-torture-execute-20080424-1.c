/*
   20080424-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/36008 */

__xdata int ggg[48][3][3] ;

void
bar (int x[3][3], int y[3][3])
{
  static int i;
  if (x != ggg[i + 8] || y != ggg[i++])
    ASSERT (0);
}

// inline functions are not working well in C51
static /*inline*/ void
foo (int x[][3][3])
{
  int i;
  for (i = 0; i < 8; i++)
    {
      int k = i + 8;
      bar (x[k], x[k - 8]);
    }
}

void
testTortureExecute (void)
{
  foo (ggg);
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
  return "cases_gcc\\gcc-torture-execute-20080424-1";
}
