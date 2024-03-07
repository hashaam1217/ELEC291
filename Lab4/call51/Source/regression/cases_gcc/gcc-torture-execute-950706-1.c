/*
   950706-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f (int n)
{
  return (n > 0) - (n < 0);
}

void
testTortureExecute (void)
{
  if (f (-1) != -1)
    ASSERT (0);
  if (f (1) != 1)
    ASSERT (0);
  if (f (0) != 0)
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
  return "cases_gcc\\gcc-torture-execute-950706-1";
}