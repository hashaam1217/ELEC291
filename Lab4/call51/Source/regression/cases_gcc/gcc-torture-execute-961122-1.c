/*
   961122-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports long long constants!
#if 0
long long acc;

addhi (short a)
{
  acc += (long long) a << 32;
}

subhi (short a)
{
  acc -= (long long) a << 32;
}
#endif

void
testTortureExecute (void)
{
#if 0
  acc = 0xffff00000000ll;
  addhi (1);
  if (acc != 0x1000000000000ll)
    ASSERT (0);
  subhi (1);
  if (acc != 0xffff00000000ll)
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
  return "cases_gcc\\gcc-torture-execute-961122-1";
}
