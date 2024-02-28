/*
   20000227-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static const unsigned char f[] = "\0\377";
static const unsigned char g[] = "\0ÿ";

void
testTortureExecute (void)
{
  if (sizeof f != 3 || sizeof g != 3)
    ASSERT (0);
  if (f[0] != g[0])
    ASSERT (0);
  if (f[1] != g[1])
    ASSERT (0);
  if (f[2] != g[2])
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
  return "cases_gcc\\gcc-torture-execute-20000227-1";
}
