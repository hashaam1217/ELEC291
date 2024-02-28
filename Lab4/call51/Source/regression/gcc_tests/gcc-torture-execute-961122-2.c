/*
   961122-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f (int a)
{
  return ((a >= 0 && a <= 10) && ! (a >= 0));
}

void
testTortureExecute (void)
{
  if (f (0))
    ASSERT (0);
  return;
}

