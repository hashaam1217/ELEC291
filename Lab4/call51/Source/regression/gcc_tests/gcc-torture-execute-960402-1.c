/*
   960402-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports long long constants!
#if 0
f (signed long long int x)
{
  return x > 0xFFFFFFFFLL || x < -0x80000000LL;
}
#endif

void
testTortureExecute (void)
{
#if 0
  if (f (0) != 0)
    ASSERT (0);
  return;
#endif
}
