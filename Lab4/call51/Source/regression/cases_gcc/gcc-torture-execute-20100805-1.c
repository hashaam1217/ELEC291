/*
   20100805.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned int foo (unsigned int a, unsigned int b)
{
  unsigned i;
  a = a & 1;
  for (i = 0; i < b; ++i)
    a = a << 1 | a >> (sizeof (unsigned int) * 8 - 1);
  return a;
}

void
testTortureExecute (void)
{
  if (foo (1, sizeof (unsigned int) * 8 + 1) != 2)
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
  return "cases_gcc\\gcc-torture-execute-20100805-1";
}
