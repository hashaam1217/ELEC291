/*
   20000605-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct F { int i; };

void f1(struct F *x, struct F *y)
{
  int timeout = 0;
  for (; ((const struct F*)x)->i < y->i ; x->i++)
    if (++timeout > 5)
      ASSERT (0);
}

void
testTortureExecute (void)
{
  struct F x, y;
  x.i = 0;
  y.i = 1;
  f1 (&x, &y);
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
  return "cases_gcc\\gcc-torture-execute-20000605-2";
}
