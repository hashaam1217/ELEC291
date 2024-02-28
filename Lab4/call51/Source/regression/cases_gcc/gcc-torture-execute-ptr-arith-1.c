/*
   ptr-arith-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

const char *
f (const char *s, unsigned int i)
{
  return &s[i + 3 - 1];
}

void
testTortureExecute (void)
{
  const char *str = "abcdefghijkl";
  const char *x2 = f (str, 12);
  if (str + 14 != x2)
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
  return "cases_gcc\\gcc-torture-execute-ptr-arith-1";
}
