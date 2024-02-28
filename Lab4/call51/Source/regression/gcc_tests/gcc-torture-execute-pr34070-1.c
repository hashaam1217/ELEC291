/*
   pr34070-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int f(unsigned int x)
{
    return ((int)x) % 4;
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && defined (__GNUC_MINOR__) && (__GNUC__ < 5 && __GNUC_MINOR__ < 3))
  if (f(-1) != -1)
    ASSERT (0);
  return;
#endif
}

