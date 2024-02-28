/*
   931012-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f (int b, int c)
{
  if (b != 0 && b != 1 && c != 0)
    b = 0;
  return b;
}

void
testTortureExecute (void)
{
  if (!f (1, 2))
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
  return "cases_gcc\\gcc-torture-execute-931012-1";
}
