/*
   20090814-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
bar (int *a)
{
  return *a;
}
int i;
int
foo (int (*a)[2])
{
  return bar (&(*a)[i]);
}

int a[2];
void
testTortureExecute (void)
{
  a[0] = -1;
  a[1] = 42;
  i = 1;
  if (foo (&a) != 42)
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
  return "cases_gcc\\gcc-torture-execute-20090814-1";
}
