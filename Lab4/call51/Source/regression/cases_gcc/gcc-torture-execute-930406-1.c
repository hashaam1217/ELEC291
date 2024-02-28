/*
   930406-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

void f()
{
  int x = 1;
#ifndef __C51_mcs51
  char big[2048];
#else
  char big[2];
#endif

  {
  mylabel:
    x++;
    if (x != 3)
      goto mylabel;
  }
  return;
}

void
testTortureExecute (void)
{
  f();
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
  return "cases_gcc\\gcc-torture-execute-930406-1";
}
