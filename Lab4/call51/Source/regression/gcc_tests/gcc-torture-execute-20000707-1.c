/*
   20000707-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo: Enable when C51 supports struct
#if 0
struct baz {
  int a, b, c;
};

void
foo (int a, int b, int c)
{
  if (a != 4)
    ASSERT (0);
}

void
bar (struct baz x, int b, int c)
{
  foo (x.b, b, c);
}
#endif

void
testTortureExecute (void)
{
#if 0
  struct baz x = { 3, 4, 5 };
  bar (x, 1, 2);
  return;
#endif
}

