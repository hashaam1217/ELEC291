/*
   20071011-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void foo(int *p)
{
  int x;
  int y;
  x = *p;
  *p = 0;
  y = *p;
  if (x != y)
    return;
  ASSERT (0);
}

void
testTortureExecute (void)
{
  int a = 1;
  foo(&a);
  return;
}
