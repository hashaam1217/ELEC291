/*
   920506-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int l[]={0,1};

void
testTortureExecute (void){int*p=l;switch(*p++){case 0:return;case 1:break;case 2:break;case 3:case 4:break;}ASSERT(0);}

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
  return "cases_gcc\\gcc-torture-execute-920506-1";
}
