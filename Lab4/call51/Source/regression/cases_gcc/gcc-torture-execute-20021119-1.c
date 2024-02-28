/*
   20021119-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR 8639.  */

int foo (int i)
{
  int r;
  r = (80 - 4 * i) / 20;
  return r;
}
    
void
testTortureExecute (void)
{
  if (foo (1) != 3)
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
  return "cases_gcc\\gcc-torture-execute-20021119-1";
}
