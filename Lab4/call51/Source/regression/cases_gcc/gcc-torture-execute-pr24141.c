/*
   pr24141.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// reduced testcase, compile with -O2. Also, with --disable-checking
// gcc produces wrong code.

int i;

void g (void)
{
  i = 1;
}

void f (int a, int b)
{
  int c = 0;
  if (a == 0)
    c = 1;
  if (c)
    return;
  if (c == 1)
    c = 0;
  if (b == 0)
    c = 1;
  if (c)
    g ();
}

void
testTortureExecute (void)
{
  f (1, 0);
  if (i != 1)
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
  return "cases_gcc\\gcc-torture-execute-pr24141";
}
