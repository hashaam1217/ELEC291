/*
   20090207-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int foo(int i)
{
  int a[32];
  a[1] = 3;
  a[0] = 1;
  a[i] = 2;
  return a[0];
}

void
testTortureExecute (void)
{
  if (foo (0) != 2
      || foo (1) != 1)
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
  return "cases_gcc\\gcc-torture-execute-20090207-1";
}
