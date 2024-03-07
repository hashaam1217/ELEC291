/*
   20070212-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f(int k, int i1, int j1)
{
  int *f1;
  if(k)
   f1 = &i1;
  else
   f1 = &j1;
  i1 = 0;
  return *f1;
}

void
testTortureExecute (void)
{
  if (f(1, 1, 2) != 0)
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
  return "cases_gcc\\gcc-torture-execute-20070212-2";
}