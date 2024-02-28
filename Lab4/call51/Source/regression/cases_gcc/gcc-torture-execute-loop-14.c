/*
   loop-14.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int a3[3];

void f(int *a)
{
  int i;

  for (i=3; --i;)
    a[i] = 42 / i;
}

void
testTortureExecute (void)
{
  f(a3);

  if (a3[1] != 42 || a3[2] != 21)
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
  return "cases_gcc\\gcc-torture-execute-loop-14";
}
