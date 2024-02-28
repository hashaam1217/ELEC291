/*
   920929-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo: Enable when C51 supports VLA!
#if 0
/* REPRODUCED:RUN:SIGNAL MACHINE:sparc OPTIONS: */
f(int n)
{
int i;
double v[n];
for(i=0;i<n;i++)
v[i]=0;
}
#endif

void
testTortureExecute (void)
{
#if 0
f(100);
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
  return "cases_gcc\\gcc-torture-execute-920929-1";
}
