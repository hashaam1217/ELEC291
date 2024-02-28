/*
   struct-ini-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0
struct S
{
  char f1;
  int f2[2];
};

struct S object = {'X', 8, 9};
#endif

void
testTortureExecute (void)
{
#if 0
  if (object.f1 != 'X' || object.f2[0] != 8 || object.f2[1] != 9)
    ASSERT (0);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-struct-ini-1";
}
