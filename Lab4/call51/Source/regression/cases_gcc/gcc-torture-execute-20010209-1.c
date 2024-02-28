/*
   20010209-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports VLA!

#if 0
int b;
int foo (void)
{
  int x[b];
  int bar (int t[b])
  {
    int i;
    for (i = 0; i < b; i++)
      t[i] = i + (i > 0 ? t[i-1] : 0);
    return t[b-1];
  }
  return bar (x);
}
#endif

void
testTortureExecute (void)
{
#if 0
  b = 6;
  if (foo () != 15)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20010209-1";
}
