/*
   921208-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

#if !defined(__C51_hc08) && !defined(__C51_s08)
double
f(double x)
{
  return x*x;
}

double
Int(double (*f)(double), double a)
{
  return (*f)(a);
}
#endif

void
testTortureExecute (void)
{
#if !defined(__C51_hc08) && !defined(__C51_s08)
  if (Int(&f,2.0) != 4.0)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-921208-1";
}
