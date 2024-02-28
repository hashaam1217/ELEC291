/*
   20021204-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 196
#endif

/* This test was miscompiled when using sibling call optimization,
   because X ? Y : Y - 1 optimization changed X into !X in place
   and haven't reverted it if do_store_flag was successful, so
   when expanding the expression the second time it was
   !X ? Y : Y - 1.  */

void foo (int x)
{
  if (x != 1)
    ASSERT (0);
}

int z;

void testTortureExecute (void)
{
  char *a = "test";
  char *b = a + 2;

  foo (z > 0 ? b - a : b - a - 1);
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
  return "cases_gcc\\gcc-torture-execute-20021204-1";
}
