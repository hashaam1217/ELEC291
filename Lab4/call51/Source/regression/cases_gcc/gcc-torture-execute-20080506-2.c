/*
   20080506-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR middle-end/36013 */

void
foo (int **restrict p, int **restrict q)
{
  *p[0] = 1;
  *q[0] = 2;
  if (*p[0] != 2)
    ASSERT (0);
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && (__GNUC__ < 5))
  int a;
  int *p1 = &a, *p2 = &a;
  foo (&p1, &p2);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-20080506-2";
}
