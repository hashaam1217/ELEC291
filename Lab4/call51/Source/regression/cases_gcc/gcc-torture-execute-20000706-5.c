/*
   20000706-5.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports.
#if 0
struct baz { int a, b, c; };

struct baz *c;

void bar(int b)
{
  if (c->a != 1 || c->b != 2 || c->c != 3 || b != 4)
    ASSERT(0);
}

void foo(struct baz a, int b)
{
  c = &a;
  bar(b);
}
#endif

void
testTortureExecute (void)
{
#if 0
  struct baz a;
  a.a = 1;
  a.b = 2;
  a.c = 3;
  foo(a, 4);
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
  return "cases_gcc\\gcc-torture-execute-20000706-5";
}
