/*
   struct-ini-4.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct s {
  int a[3];
  int c[3];
};

struct s s = {
  .c = {1, 2, 3}
};

void
testTortureExecute (void)
{
  if (s.c[0] != 1)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-struct-ini-4";
}
