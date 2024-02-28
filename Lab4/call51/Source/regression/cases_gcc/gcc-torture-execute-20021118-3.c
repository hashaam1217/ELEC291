/*
   20021118-3.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
foo (int x)
{
  if (x == -2 || -x - 100 >= 0)
    ASSERT (0);
  return 0;
}
           
void
testTortureExecute (void)
{
  foo (-3);
  foo (-99);
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
  return "cases_gcc\\gcc-torture-execute-20021118-3";
}
