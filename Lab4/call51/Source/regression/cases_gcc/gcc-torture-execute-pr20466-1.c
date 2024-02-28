/*
   pr20466-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f (int **, int *, int *, int **, int **);
int
f (int **ipp, int *i1p, int *i2p, int **i3, int **i4)
{
  **ipp = *i1p;
  *ipp = i2p;
  *i3 = *i4;
  **ipp = 99;
  return 3;
}

void
testTortureExecute (void)
{
  int i = 42, i1 = 66, i2 = 1, i3 = -1, i4 = 55;
  int *ip = &i;
  int *i3p = &i3;
  int *i4p = &i4;
#if 0
  f (&ip, &i1, &i2, &i3p, &i4p);
  if (i != 66 || ip != &i2 || i2 != 99 || i3 != -1 || i3p != i4p || i4 != 55)
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
  return "cases_gcc\\gcc-torture-execute-pr20466-1";
}
