/*
   920731-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f(int x){int i;for(i=0;i<8&&(x&1)==0;x>>=1,i++);return i;}
void
testTortureExecute (void){if(f(4)!=2)ASSERT(0);return;}


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
  return "cases_gcc\\gcc-torture-execute-920731-1";
}
