/*
   960419-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static int i;

void
check(int x)
{
  if (!x)
    ASSERT(0);
}

void
testTortureExecute (void)
{
  int *p = &i;

  check(p != (void *)0);
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
  return "cases_gcc\\gcc-torture-execute-960419-1";
}
