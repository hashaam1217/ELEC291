/*
   960317-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f (unsigned bitcount, int mant)
{
  int mask = -1 << bitcount;
  {
    if (! (mant & -mask))
      goto ab;
    if (mant & ~mask)
      goto auf;
  }
ab:
  return 0;
auf:
  return 1;
}

void
testTortureExecute (void)
{
  if (f (0, -1))
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
  return "cases_gcc\\gcc-torture-execute-960317-1";
}
