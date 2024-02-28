/*
   20000706-3.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int c;

void baz(int *p)
{
  c = *p;
}

void bar(int b)
{
  if (c != 1 || b != 2)
    ASSERT(0);
}

void foo(int a, int b)
{
  baz(&a);
  bar(b);
}

void
testTortureExecute (void)
{
  foo(1, 2);
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
  return "cases_gcc\\gcc-torture-execute-20000706-3";
}
