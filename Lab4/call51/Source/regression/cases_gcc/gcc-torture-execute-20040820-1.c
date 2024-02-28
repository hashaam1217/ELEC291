/*
   20040820-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR rtl-optimization/17099 */

void
check (int a)
{
  if (a != 1)
    ASSERT (0);
}

void
test (int a, int b)
{
  check ((a ? 1 : 0) | (b ? 2 : 0));
}

void
testTortureExecute (void)
{
  test (1, 0);
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
  return "cases_gcc\\gcc-torture-execute-20040820-1";
}
