/*
   931009-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void f ();

void
testTortureExecute (void)
{
  f ();
  return;
}

static void
g (int *out, int size, int lo, int hi)
{
  int j;

  for (j = 0; j < size; j++)
    out[j] = j * (hi - lo);
}


void f ()
{
  int a[2];

  g (a, 2, 0, 1);

  if (a[0] != 0 || a[1] != 1)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-931009-1";
}
