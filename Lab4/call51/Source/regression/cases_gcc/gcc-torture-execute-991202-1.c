/*
   991202-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int x, y;

void
testTortureExecute (void)
{
  x = 2;
  y = x;
  do
    {
      x = y;
      y = 2 * y;
    }
  while ( ! ((y - x) >= 20));
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
  return "cases_gcc\\gcc-torture-execute-991202-1";
}
