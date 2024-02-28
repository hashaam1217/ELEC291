/*
   pr42544.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR c/42544 */

extern void abort (void);

void
testTortureExecute (void)
{
#if 0
TODO: Enable once C51 really support long long literals.
  signed short s = -1;
  if (sizeof (long long) == sizeof (unsigned int))
    return;
  if ((unsigned int) s >= 0x100000000ULL)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-pr42544";
}
