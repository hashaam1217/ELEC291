/*
   20000412-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if !(defined (__C51_mcs51) || defined (__C51_hc08) || defined (__C51_s08) || defined (__C51_ds390))
int f(int a,int *y)
{
  int x = a;

  if (a==0)
    return *y;

  return f(a-1,&x);
}
#endif

void
testTortureExecute (void)
{
#if !(defined (__C51_mcs51) || defined (__C51_hc08) || defined (__C51_s08) || defined (__C51_ds390))
  if (f (10, (int *) 0) != 1)
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
  return "cases_gcc\\gcc-torture-execute-20000412-2";
}
