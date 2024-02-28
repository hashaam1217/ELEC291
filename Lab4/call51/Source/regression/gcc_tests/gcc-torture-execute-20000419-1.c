/*
   20000419-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports passing of structs!
#if 0
struct foo { int a, b, c; };

void
brother (int a, int b, int c)
{
  if (a)
    ASSERT (0);
}

void
sister (struct foo f, int b, int c)
{
  brother ((f.b == b), b, c);
}
#endif

void
testTortureExecute (void)
{
#if 0
  struct foo f = { 7, 8, 9 };
  sister (f, 1, 2);
  return;
#endif
}

