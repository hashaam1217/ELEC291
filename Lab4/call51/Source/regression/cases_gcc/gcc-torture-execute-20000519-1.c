/*
   20000519-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdarg.h>

int
bar (int a, va_list ap)
{
  int b;

  do
    b = va_arg (ap, int);
  while (b > 10);

  return a + b;
}

int
foo (int a, ...)
{
  va_list ap;

  va_start (ap, a);
  return bar (a, ap);
}

void
testTortureExecute (void)
{
  if (foo (1, 2, 3) != 3)
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
  return "cases_gcc\\gcc-torture-execute-20000519-1";
}
