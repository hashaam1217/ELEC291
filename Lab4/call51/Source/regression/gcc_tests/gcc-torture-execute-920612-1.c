/*
   920612-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f(int j)
{
  return ++j > 0;
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && (__GNUC__ < 5))
  if(f ((~0U) >> 1))
    ASSERT(0);
  return;
#endif
}

