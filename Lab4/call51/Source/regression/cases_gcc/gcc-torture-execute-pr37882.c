/*
   pr37882.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR middle-end/37882 */

struct S
{
  unsigned char b : 3;
} s;

void
testTortureExecute (void)
{
  s.b = 4;
  if (s.b > 0 && s.b < 4)
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
  return "cases_gcc\\gcc-torture-execute-pr37882";
}
