/*
   pr42512.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

short g_3;

void
testTortureExecute (void)
{
    int l_2;
    for (l_2 = -1; l_2 != 0; l_2 = (unsigned char)(l_2 - 1))
      g_3 |= l_2;
    if (g_3 != -1)
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
  return "cases_gcc\\gcc-torture-execute-pr42512";
}
