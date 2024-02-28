/*
   20000523-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
// Todo: Enable when C51 supports long long constants!
#if 0
  long long   x;
  int         n;

  if (sizeof (long long) < 8)
    return;
  
  n = 9;
  x = (((long long) n) << 55) / 0xff; 

  if (x == 0)
    ASSERT (0);

  x = (((long long) 9) << 55) / 0xff;

  if (x == 0)
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
  return "cases_gcc\\gcc-torture-execute-20000523-1";
}
