/*
   pr35231.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
foo(int bits_per_pixel, int depth)
{
  if ((bits_per_pixel | depth) == 1)
    ASSERT (0);
  return bits_per_pixel;
}

void
testTortureExecute (void)
{
  if (foo(2, 0) != 2)
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
  return "cases_gcc\\gcc-torture-execute-pr35231";
}
