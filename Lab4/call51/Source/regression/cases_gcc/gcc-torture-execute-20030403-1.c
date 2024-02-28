/*
   20030403-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* The non-destructive folder was always emitting >= when folding
   comparisons to signed_max+1.  */

#include <limits.h>

void
testTortureExecute (void)
{
  unsigned long count = 8;

  if (count > INT_MAX)
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
  return "cases_gcc\\gcc-torture-execute-20030403-1";
}
