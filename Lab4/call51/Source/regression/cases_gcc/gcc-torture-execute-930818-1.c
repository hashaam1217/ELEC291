/*
   930818-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

static double one = 1.0;

int f()
{
  int colinear;
  colinear = (one == 0.0);
  if (colinear)
    ASSERT (0);
  return colinear;
}
void
testTortureExecute (void)
{
  if (f()) ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-930818-1";
}
