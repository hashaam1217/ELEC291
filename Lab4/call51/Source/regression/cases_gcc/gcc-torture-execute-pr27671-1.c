/*
   pr27671.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR rtl-optimization/27671.
   The combiner used to simplify "a ^ b == a" to "a" via
   simplify_relational_operation_1 in simplify-rtx.c.  */

/*extern void abort (void) __attribute__ ((noreturn));
extern void exit (int) __attribute__ ((noreturn));*/

static int
foo (int a, int b)
{
  int c = a ^ b;
  if (c == a)
    ASSERT (0);
}

void
testTortureExecute (void)
{
  foo (0, 1);
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
  return "cases_gcc\\gcc-torture-execute-pr27671-1";
}
