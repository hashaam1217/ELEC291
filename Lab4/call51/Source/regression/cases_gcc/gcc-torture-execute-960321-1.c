/*
   960321-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

char a[10] = "deadbeef";

char
acc_a (long i)
{
  return a[i-2000000000L];
}

void
testTortureExecute (void)
{
  if (acc_a (2000000000L) != 'd')
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
  return "cases_gcc\\gcc-torture-execute-960321-1";
}
