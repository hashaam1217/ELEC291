/*
   20071216-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR rtl-optimization/34490 */

static int x;

int
bar (void)
{
  return x;
}

int
foo (void)
{
  long int b = bar ();
  if ((unsigned long) b < -4095L)
    return b;
  if (-b != 38)
    b = -2;
  return b + 1;
}

void
testTortureExecute (void)
{
  x = 26;
  if (foo () != 26)
    ASSERT (0);
  x = -39;
  if (foo () != -1)
    ASSERT (0);
  x = -38;
  if (foo () != -37)
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
  return "cases_gcc\\gcc-torture-execute-20071216-1";
}
