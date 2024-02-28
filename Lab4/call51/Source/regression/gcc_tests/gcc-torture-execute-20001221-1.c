/*
   20001221-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 184
#endif

void
testTortureExecute (void)
{
// TODO: Enable when more ports support long long!
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  unsigned long long a;
  if (! (a = 0xfedcba9876543210ULL))
    ASSERT (0);
  return;
#endif
}

