/*
   loop-11.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#ifndef __C51_mcs51
static int a[199];

static void
foo ()
{
  int i;
  for (i = 198; i >= 0; i--)
    a[i] = i;
}
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  int i;
  foo ();
  for (i = 0; i < 199; i++)
    if (a[i] != i)
      ASSERT (0);
#endif
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
  return "cases_gcc\\gcc-torture-execute-loop-11";
}
