/*
   980505-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static int f(int);

void
testTortureExecute (void)
{
   int f1, f2, x;
   x = 1; f1 = f(x);
   x = 2; f2 = f(x);
   if (f1 != 1 || f2 != 2)
     ASSERT (0);
   return;
}
static int f(int x) { return x; }


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
  return "cases_gcc\\gcc-torture-execute-980505-1";
}
