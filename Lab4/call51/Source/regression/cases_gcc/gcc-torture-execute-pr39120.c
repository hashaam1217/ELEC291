/*
   pr39120.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0
C51 urrently cannot return aggregates TODO: Enable later.
struct X { int *p; } x;

struct X
foo(int *p) { struct X x; x.p = p; return x; }

void
bar() { *x.p = 1; }
#endif

void
testTortureExecute (void)
{
#if 0
  int i = 0;
  x = foo(&i);
  bar();
  if (i != 1)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-pr39120";
}
