/*
   920721-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

long f(short a,short b){return (long)a/b;}
void
testTortureExecute (void){if(f(-32768,-1)!=32768L)ASSERT(0);else return;}

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
  return "cases_gcc\\gcc-torture-execute-920721-1";
}
