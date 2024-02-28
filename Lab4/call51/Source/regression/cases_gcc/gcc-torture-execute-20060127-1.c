/*
   20060127-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when long long comes to these ports!
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
void
f (long long a)
{
  if ((a & 0xffffffffLL) != 0)
    ASSERT (0);
}

long long a = 0x1234567800000000LL;
#endif

void
testTortureExecute (void)
{
// TODO: Enable when long long literals are supported!
#if 0
  f (a);
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
  return "cases_gcc\\gcc-torture-execute-20060127-1";
}
