/*
   980526-3.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int compare(unsigned int x, unsigned int y)
{
   if (x==y)
     return 0;
   else
     return 1;
}
 
void
testTortureExecute (void)
{
 unsigned int i, j, k, l;
 i = 5; j = 2; k=0; l=2;
 if (compare(5%(~(unsigned) 2), i%~j) 
     || compare(0, k%~l))
    ASSERT(0);
 else
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
  return "cases_gcc\\gcc-torture-execute-980526-3";
}
