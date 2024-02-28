/*
   20030606-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

int * foo (int *x, int b)
{

  *(x++) = 55;
  if (b)
    *(x++) = b;

  return x;
}

void
testTortureExecute (void)
{
  int a[5];

  memset (a, 1, sizeof (a));

  if (foo (a, 0) - a != 1 || a[0] != 55 || a[1] != a[4])
    ASSERT (0);

  memset (a, 1, sizeof (a));

  if (foo (a, 2) - a != 2 || a[0] != 55 || a[1] != 2)
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
  return "cases_gcc\\gcc-torture-execute-20030606-1";
}
