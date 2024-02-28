/*
   950706-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f (int n)
{
  return (n > 0) - (n < 0);
}

void
testTortureExecute (void)
{
  if (f (-1) != -1)
    ASSERT (0);
  if (f (1) != 1)
    ASSERT (0);
  if (f (0) != 0)
    ASSERT (0);
  return;
}

