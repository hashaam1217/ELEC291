/*
   20030401-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Testcase for PR fortran/9974.  This was a miscompilation of the g77
   front-end caused by the jump bypassing optimizations not handling
   instructions inserted on CFG edges.  */

int bar ()
{
  return 1;
}

void foo (int x)
{
  unsigned char error = 0;

  if (! (error = ((x == 0) || bar ())))
    bar ();
  if (! error)
    ASSERT (0);
}

void
testTortureExecute (void)
{
  foo (1);
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
  return "cases_gcc\\gcc-torture-execute-20030401-1";
}
