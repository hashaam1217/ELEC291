/*
   930702-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

int fp (double a, int b) __reentrant
{
  if (a != 33 || b != 11)
    ASSERT (0);
  return (0);
}

void
testTortureExecute (void)
{
  int (*f) (double, int) __reentrant = fp;

  fp (33, 11);
  f (33, 11);
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
  return "cases_gcc\\gcc-torture-execute-930702-1";
}
