/*
   921124-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#pragma disable_warning 85
#endif

int f(int x, double d1, double d2, double d3)
{
   return x;
}

void g(char *b, char *s, double x, double y, int i, int j)
{
  if (x != 1.0 || y != 2.0 || i != 3 || j != 4)
    ASSERT(0);
}

void
testTortureExecute (void)
{
  g("","", 1.0, 2.0, f(3, 0.0, 0.0, 0.0), f(4, 0.0, 0.0, 0.0));
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
  return "cases_gcc\\gcc-torture-execute-921124-1";
}