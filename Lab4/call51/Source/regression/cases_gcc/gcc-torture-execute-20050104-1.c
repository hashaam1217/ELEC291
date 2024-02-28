/*
   20050104-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>

#if 0 // TODO: Enable when long long literals are supported!
/* PR tree-optimization/19060 */

static
long long min ()
{
  return -LLONG_MAX - 1;
}

void
foo (long long j)
{
  if (j > 10 || j < min ())
    ASSERT (0);
}
#endif

void
testTortureExecute (void)
{
#if 0
  foo (10);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-20050104-1";
}
