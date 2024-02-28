/*
   991227-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

char* doit(int flag)
{
  return 1 + (flag ? "\0wrong\n" : "\0right\n");
}

void
testTortureExecute (void)
{
  char *result = doit(0);
  if (*result == 'r' && result[1] == 'i')
    return;
  ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-991227-1";
}
