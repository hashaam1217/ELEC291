/*
   930429-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

const char *
f (const char *p)
{
  short x = *p++ << 16;
  return p;
}

void
testTortureExecute (void)
{
  const char *p = "";
  if (f (p) != p + 1)
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
  return "cases_gcc\\gcc-torture-execute-930429-1";
}
