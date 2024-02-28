/*
   20020225-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static int 
ftest(int x)
{
  union 
    {
      int i;
      double d;
  } a;
  a.d = 0;
  a.i = 1;
  return x >> a.i;
}

void testTortureExecute (void)
{
  if (ftest (5) != 2)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20020225-2";
}
