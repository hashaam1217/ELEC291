/*
   20021120-3.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdio.h>

unsigned int foo (char *c, unsigned int x, unsigned int y)
{
  register unsigned int z;

  sprintf (c, "%d", x / y);
  z = x + 1;
  return z / (y + 1);
}

void
testTortureExecute (void)
{
  char c[16];

  if (foo (c, ~1U, 4) != (~0U / 5))
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
  return "cases_gcc\\gcc-torture-execute-20021120-3";
}
