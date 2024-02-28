/*
   struct-ini-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct {
  int a:4;
  int :4;
  int b:4;
  int c:4;
} x = { 2,3,4 };

void
testTortureExecute (void)
{
  if (x.a != 2)
    ASSERT(0);
  if (x.b != 3)
    ASSERT(0);
  if (x.c != 4)
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
  return "cases_gcc\\gcc-torture-execute-struct-ini-2";
}
