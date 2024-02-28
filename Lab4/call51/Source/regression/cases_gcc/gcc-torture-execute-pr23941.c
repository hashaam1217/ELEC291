/*
   pr15262.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

#include <float.h>

extern void abort (void);
double d = FLT_MIN / 2.0;

void
testTortureExecute (void)
{
  double x = FLT_MIN / 2.0;
  if (x != d)
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
  return "cases_gcc\\gcc-torture-execute-pr23941";
}
