/*
   941101-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f ()
{
  int var = 7;

  if ((var/7) == 1)
    return var/7;
  return 0;
}

void
testTortureExecute (void)
{
  if (f () != 1)
    ASSERT (0);
  return;
}

