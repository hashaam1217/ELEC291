/*
   loop-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int a[2];

void f (int b)
{
  unsigned int i;
  for (i = 0; i < b; i++)
    a[i] = i - 2;
}

void
testTortureExecute (void)
{
  a[0] = a[1] = 0;
  f (2);
  if (a[0] != -2 || a[1] != -1)
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
  return "cases_gcc\\gcc-torture-execute-loop-2";
}
