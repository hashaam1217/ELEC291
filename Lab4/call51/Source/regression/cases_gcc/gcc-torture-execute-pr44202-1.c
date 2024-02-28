/*
   pr44202-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
add512(int a, int *b)
{
  int c = a + 512;
  if (c != 0)
    *b = a;
  return c;
}

int
add513(int a, int *b)
{
  int c = a + 513;
  if (c == 0)
    *b = a;
  return c;
}

void
testTortureExecute (void)
{
  int b0 = -1;
  int b1 = -1;
  if (add512(-512, &b0) != 0 || b0 != -1 || add513(-513, &b1) != 0 || b1 != -513)
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
  return "cases_gcc\\gcc-torture-execute-pr44202-1";
}
