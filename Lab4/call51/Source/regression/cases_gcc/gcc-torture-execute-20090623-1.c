/*
   20090623-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int *restrict x;

int foo (int y)
{
  *x = y;
  return *x;
}

void
testTortureExecute (void)
{
  int i = 0;
  x = &i;
  if (foo(1) != 1)
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
  return "cases_gcc\\gcc-torture-execute-20090623-1";
}
