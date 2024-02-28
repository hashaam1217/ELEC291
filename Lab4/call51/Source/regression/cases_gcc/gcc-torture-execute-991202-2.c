/*
   991202-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f1 ()
{
  unsigned long x, y = 1;

  x = ((y * 8192) - 216) % 16;
  return x;
}

void
testTortureExecute (void)
{
  if (f1 () != 8)
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
  return "cases_gcc\\gcc-torture-execute-991202-2";
}
