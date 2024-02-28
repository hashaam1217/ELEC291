/*
   20010221-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int n = 2;

void
testTortureExecute (void)
{
  int i, x = 45;

  for (i = 0; i < n; i++)
    {
      if (i != 0)
	x = ( i > 0 ) ? i : 0;
    }

  if (x != 1)
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
  return "cases_gcc\\gcc-torture-execute-20010221-1";
}
