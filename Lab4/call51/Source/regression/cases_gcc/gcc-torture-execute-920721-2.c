/*
   920721-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo. Enable when C51 supports VLA!
#if 0
void f(void){}
#endif

void
testTortureExecute (void)
{
#if 0
  int n=2;
  double x[n];
  f();
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
  return "cases_gcc\\gcc-torture-execute-920721-2";
}
