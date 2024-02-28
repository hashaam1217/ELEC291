/*
   20000113-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct x { 
  unsigned x1:1;
  unsigned x2:2;
  unsigned x3:3;
};
   
void foobar (int x, int y, int z)
{
  struct x a = {x, y, z};
  struct x b = {x, y, z};
  struct x *c = &b;

  c->x3 += (a.x2 - a.x1) * c->x2;
  if (a.x1 != 1 || c->x3 != 5)
    ASSERT (0);
  return;
}

void
testTortureExecute (void)
{
  foobar (1, 2, 3);
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
  return "cases_gcc\\gcc-torture-execute-20000113-1";
}
