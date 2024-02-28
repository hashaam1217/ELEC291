/*
   pr49281.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR target/49281 */

extern void abort (void);

int
foo (int x)
{
  return (x << 2) | 4;
}

int
bar (int x)
{
  return (x << 2) | 3;
}

void
testTortureExecute (void)
{
  if (foo (43) != 172 || foo (1) != 4 || foo (2) != 12)
    ASSERT (0);
  if (bar (43) != 175 || bar (1) != 7 || bar (2) != 11)
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
  return "cases_gcc\\gcc-torture-execute-pr49281";
}
