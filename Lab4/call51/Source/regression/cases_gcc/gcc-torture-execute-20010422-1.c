/*
   20010422-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned int foo(unsigned int x)
{
  if (x < 5)
    x = 4;
  else
    x = 8;
  return x;
}

void
testTortureExecute (void)
{
  if (foo (8) != 8)
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
  return "cases_gcc\\gcc-torture-execute-20010422-1";
}
