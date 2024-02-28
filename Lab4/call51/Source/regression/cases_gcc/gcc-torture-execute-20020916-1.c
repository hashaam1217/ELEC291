/*
   20020916-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Distilled from try_pre_increment in flow.c.  If-conversion inserted
   new instructions at the wrong place on ppc.  */

int foo(int a)
{
  int x;
  x = 0;
  if (a > 0) x = 1;
  if (a < 0) x = 1;
  return x;
}

void
testTortureExecute (void)
{
  if (foo(1) != 1)
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
  return "cases_gcc\\gcc-torture-execute-20020916-1";
}
