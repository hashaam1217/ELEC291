/*
   20011019-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct { int a; int b[5]; } x;
int *y;

int foo (void)
{
  return y - x.b;
}

void
testTortureExecute (void)
{
  y = x.b;
  if (foo ())
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
  return "cases_gcc\\gcc-torture-execute-20011019-1";
}
