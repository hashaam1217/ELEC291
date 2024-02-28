/*
   921202-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports long long constants!
#if 0
int
f(long long x)
{
  x >>= 8;
  return x & 0xff;
}
#endif

void
testTortureExecute (void)
{
#if 0
  if (f(0x0123456789ABCDEFLL) != 0xCD)
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
  return "cases_gcc\\gcc-torture-execute-921202-2";
}
