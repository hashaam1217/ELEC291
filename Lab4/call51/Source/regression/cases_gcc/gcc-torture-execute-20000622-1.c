/*
   20000622-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#pragma disable_warning 88
#endif

long foo(long a, long b, long c)
{
  if (a != 12 || b != 1 || c != 11)
    ASSERT (0);
  return 0;
}
long bar (long a, long b)
{
  return b;
}
void baz (long a, long b, void *c)
{
  long d;
  d = (long)c;
  foo(d, bar (a, 1), b);
}
void
testTortureExecute (void)
{
  baz (10, 11, (void *)12);
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
  return "cases_gcc\\gcc-torture-execute-20000622-1";
}
