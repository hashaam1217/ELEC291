/*
   941025-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

long f (long x, long y)
{
  return (x > 1) ? y : (y & 1);
}

void
testTortureExecute (void)
{
  if (f (2L, 0xdecadeL) != 0xdecadeL)
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
  return "cases_gcc\\gcc-torture-execute-941025-1";
}
