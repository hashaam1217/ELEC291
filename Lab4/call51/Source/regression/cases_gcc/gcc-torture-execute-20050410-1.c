/*
   20050410-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int s = 200;
int
foo (void)
{
  return (signed char) (s - 100) - 5;
}
void
testTortureExecute (void)
{
  if (foo () != 95)
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
  return "cases_gcc\\gcc-torture-execute-20050410-1";
}
