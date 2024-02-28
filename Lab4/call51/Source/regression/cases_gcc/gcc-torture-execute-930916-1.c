/*
   930916-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void f (unsigned n)
{
  if ((int) n >= 0)
    ASSERT (0);
}

void
testTortureExecute (void)
{
  unsigned x = ~0;
  f (x);
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
  return "cases_gcc\\gcc-torture-execute-930916-1";
}
