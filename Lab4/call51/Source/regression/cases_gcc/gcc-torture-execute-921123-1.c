/*
   921123-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

f(short *p)
{
  short x = *p;
  return (--x < 0);
}

void
testTortureExecute (void)
{
  short x = -10;
  if (!f(&x))
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
  return "cases_gcc\\gcc-torture-execute-921123-1";
}
