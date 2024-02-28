/*
   920711-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

f(long a)
{
  return (--a > 0);
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && (__GNUC__ < 5))
  if(f (0x80000000L) == 0)
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
  return "cases_gcc\\gcc-torture-execute-920711-1";
}
