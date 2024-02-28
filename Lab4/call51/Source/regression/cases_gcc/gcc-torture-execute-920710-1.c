/*
   920710-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
// Enable when C51 supports double and unsigned long long.
#if 0
  if ((double) 18446744073709551615ULL < 1.84467440737095e+19 ||
      (double) 18446744073709551615ULL > 1.84467440737096e+19)
    ASSERT(0);

  if (16777217L != (float)16777217e0)
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
  return "cases_gcc\\gcc-torture-execute-920710-1";
}
