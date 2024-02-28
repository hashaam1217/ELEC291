/*
   961026-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
test (int arg)
{
  if (arg > 0 || arg == 0)
    return 0;
  return -1;
}

void
testTortureExecute (void)
{
  if (test (0) != 0)
    ASSERT (0);
  if (test (-1) != -1)
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
  return "cases_gcc\\gcc-torture-execute-961026-1";
}
