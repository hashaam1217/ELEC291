/*
   20040331-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>

/* PR c++/14755 */

void
testTortureExecute (void)
{
#if INT_MAX >= 2147483647
  struct { int count: 31; } s = { 0 };
  while (s.count--)
    ASSERT (0);
#elif INT_MAX >= 32767
  struct { int count: 15; } s = { 0 };
  while (s.count--)
    ASSERT (0);
#else
  /* Don't bother because __INT_MAX__ is too small.  */
#endif
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
  return "cases_gcc\\gcc-torture-execute-20040331-1";
}
