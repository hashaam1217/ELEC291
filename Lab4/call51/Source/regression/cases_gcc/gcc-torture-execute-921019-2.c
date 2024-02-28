/*
   921019-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

void
testTortureExecute (void)
{
  double x,y=0.5;
  x=y/0.2;
  if(x!=x)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-921019-2";
}
