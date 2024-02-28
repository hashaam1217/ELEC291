/*
   921207-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f(void)
{
  unsigned b = 0;

  if (b > ~0U)
    b = ~0U;

  return b;
}
void
testTortureExecute (void)
{
  if (f()!=0)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-921207-1";
}
