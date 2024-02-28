/*
   20001027-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int x,*p=&x;

void
testTortureExecute (void)
{
#if 0
  int i=0;
  x=1;
  *p=2;
  if (x != 2)
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
  return "cases_gcc\\gcc-torture-execute-20001027-1";
}
