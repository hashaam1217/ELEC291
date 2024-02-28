/*
   pr47155.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/47155 */

unsigned int a;
static signed char b = -127;
int c = 1;

void
testTortureExecute (void)
{
  a = b <= (unsigned char) (-6 * c);
  if (!a)
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
  return "cases_gcc\\gcc-torture-execute-pr47155";
}
