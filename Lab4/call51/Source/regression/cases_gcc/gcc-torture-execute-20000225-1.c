/*
   20000225-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
    int nResult;
    int b=0;
    int i = -1;

    do
    {
     if (b!=0) {
       ASSERT (0);
       nResult=1;
     } else {
      nResult=0;
     }
     i++;
     b=(i+2)*4;
    } while (i < 0);
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
  return "cases_gcc\\gcc-torture-execute-20000225-1";
}
