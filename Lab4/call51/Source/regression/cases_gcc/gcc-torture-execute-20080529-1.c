/*
   20080529-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR target/36362 */
#if !(defined (__GNUC__) && __GNUC__ < 5)
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
int
test (float c)
{
  return !!c * 7LL == 0;
}
#endif
#endif

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && __GNUC__ < 5)
#if !defined(__C51_mcs51) && !defined(__C51_hc08) && !defined(__C51_s08) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  if (test (1.0f) != 0)
    ASSERT (0);
#endif
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
  return "cases_gcc\\gcc-torture-execute-20080529-1";
}
