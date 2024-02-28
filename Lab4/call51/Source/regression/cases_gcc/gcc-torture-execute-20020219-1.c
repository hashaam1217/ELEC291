/*
   20020219-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Some ports do not yet support long long
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)

/* PR c/4308
   This testcase failed because 0x8000000000000000 >> 0
   was incorrectly folded into 0xffffffff00000000.  */

long long foo (void)
{
  long long C = 1ULL << 63, X;
  int Y = 32;
  X = C >> (Y & 31);
  return X;
}
#endif

void testTortureExecute (void)
{
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  if (foo () != 1ULL << 63)
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
  return "cases_gcc\\gcc-torture-execute-20020219-1";
}
