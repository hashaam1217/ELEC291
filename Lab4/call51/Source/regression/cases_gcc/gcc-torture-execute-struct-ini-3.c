/*
   struct-ini-3.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct
{
  unsigned int f1:1, f2:1, f3:3, f4:3, f5:2, f6:1, f7:1;
} result = {1, 1, 7, 7, 3, 1, 1};

void
testTortureExecute (void)
{
  if ((result.f3 & ~7) != 0 || (result.f4 & ~7) != 0)
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
  return "cases_gcc\\gcc-torture-execute-struct-ini-3";
}
