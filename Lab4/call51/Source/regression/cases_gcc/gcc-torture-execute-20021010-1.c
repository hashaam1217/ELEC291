/*
   20021010-1.c from the execute part of the gcc torture suite.
 */
 
#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <limits.h>

int
sub ()
{
  int dummy = 0, a = 16;

  if (a / INT_MAX / 16 == 0)
    return 0;
  else
    return a / INT_MAX / 16;
}

void
testTortureExecute (void)
{
  ASSERT (!(sub () != 0));

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
  return "cases_gcc\\gcc-torture-execute-20021010-1";
}
