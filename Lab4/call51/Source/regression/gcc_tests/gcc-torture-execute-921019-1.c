/*
   921019-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void *foo[]={(void *)&("X"[0])};

void
testTortureExecute (void)
{
  if (((char*)foo[0])[0] != 'X')
    ASSERT (0);
  return;
}

