/*
   20000715-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned int foo(unsigned int a)
{
  return ((unsigned char)(a + 1)) * 4;
}

void
testTortureExecute (void)
{
  if (foo((unsigned char)~0))
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
  return "cases_gcc\\gcc-torture-execute-20000715-2";
}
