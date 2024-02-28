/*
   20050131-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Verify that we do not lose side effects on a MOD expression.  */

#include <stdlib.h>
#include <stdio.h>

int
foo (int a)
{
  int x = 0 % a++;
  return a;
}

void
testTortureExecute (void)
{
  if (foo (9) != 10)
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
  return "cases_gcc\\gcc-torture-execute-20050131-1";
}
