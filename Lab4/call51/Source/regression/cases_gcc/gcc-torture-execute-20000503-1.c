/*
   20000503-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned long
sub (int a)
{
  return ((0 > a - 2) ? 0 : a - 2) * sizeof (long);
}

void
testTortureExecute (void)
{
  if (sub (0) != 0)
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
  return "cases_gcc\\gcc-torture-execute-20000503-1";
}