/*
   pr41317.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct A
{
  int i;
};
struct B
{
  struct A a;
  int j;
};

static void
foo (struct B *p)
{
  ((struct A *)p)->i = 1;
}

void
testTortureExecute (void)
{
  struct A a;
  a.i = 0;
  foo ((struct B *)&a);
  if (a.i != 1)
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
  return "cases_gcc\\gcc-torture-execute-pr41317";
}
