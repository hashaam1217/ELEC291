/*
   ifcvt-onecmpl-abs-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int foo(int n)
{
  if (n < 0)
    n = ~n;

  return n;
}

void
testTortureExecute (void)
{
  if (foo (-1) != 0)
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
  return "cases_gcc\\gcc-torture-execute-ifcvt-onecmpl-abs-1";
}
