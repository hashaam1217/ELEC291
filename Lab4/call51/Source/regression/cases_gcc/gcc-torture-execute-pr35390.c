/*
   pr35390.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned int foo (int n)
{
  return ~((unsigned int)~n);
}

void
testTortureExecute (void)
{
  if (foo(0) != 0)
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
  return "cases_gcc\\gcc-torture-execute-pr35390";
}