/*
   20020127-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* This used to fail on h8300.  */

unsigned long
foo (unsigned long n)
{
  return (~n >> 3) & 1;
}

void
testTortureExecute (void)
{
  if (foo (1 << 3) != 0)
    ASSERT (0);;

  if (foo (0) != 1)
    ASSERT (0);;
}

