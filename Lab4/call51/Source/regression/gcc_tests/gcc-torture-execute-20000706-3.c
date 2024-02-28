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

