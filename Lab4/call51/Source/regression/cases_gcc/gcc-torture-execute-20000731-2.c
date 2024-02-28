/*
   20000731-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
    int i = 1;
    int j = 0;

    while (i != 1024 || j <= 0) {
        i *= 2;
        ++ j;
    }

    if (j != 10)
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
  return "cases_gcc\\gcc-torture-execute-20000731-2";
}
