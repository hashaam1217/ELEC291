/*
   20050613-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/22043 */

struct A { int i; int j; int k; int l; };
struct B { struct A a; int r[1]; };
struct C { struct A a; int r[0]; };
struct D { struct A a; int r[]; };

void
foo (struct A *x)
{
  if (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    ASSERT (0);
}

void
testTortureExecute (void)
{
  struct B b;
  struct C c;
  struct D d;
  
  b.a.j = 5;
  c.a.j = 5;
  d.a.j = 5;

  foo (&b.a);
  foo (&c.a);
  foo (&d.a);

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
  return "cases_gcc\\gcc-torture-execute-20050613-1";
}
