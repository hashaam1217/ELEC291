/*
   980424-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#ifndef __C51_mcs51
int i, a[99];

void f (int one)
{
  if (one != 1)
    ASSERT (0);
}

void
g ()
{
  f (a[i & 0x3f]);
}
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  a[0] = 1;
  i = 0x40;
  g ();
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
  return "cases_gcc\\gcc-torture-execute-980424-1";
}
