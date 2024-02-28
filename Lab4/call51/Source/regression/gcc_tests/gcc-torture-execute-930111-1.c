/*
   930111-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Some ports do not support long long yet.
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
int
wwrite(long long i);
#endif

void
testTortureExecute (void)
{
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  if (wwrite((long long) 0) != 123)
    ASSERT(0);
  return;
#endif
}

#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
int
wwrite(long long i)
{
  switch(i)
    {
    case 3:
    case 10:
    case 23:
    case 28:
    case 47:
      return 0;
    default:
      return 123;
    }
}
#endif
