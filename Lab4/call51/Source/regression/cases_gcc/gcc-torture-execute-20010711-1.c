/*
   20010711-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

void foo (int *a) {}

void
testTortureExecute (void)
{
  int a;
  if (&a == 0)
    ASSERT (0);
  else
    {
      foo (&a);
      return;
    }
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
  return "cases_gcc\\gcc-torture-execute-20010711-1";
}
