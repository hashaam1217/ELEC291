/*
   doloop-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>

volatile unsigned int i;

void
testTortureExecute (void)
{
  unsigned short z = 0;

  do ++i;
  while (--z > 0);
  if (i != USHRT_MAX + 1U)
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
  return "cases_gcc\\gcc-torture-execute-doloop-2";
}
