/*
   pr47299.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR rtl-optimization/47299 */

unsigned short
foo (unsigned char x)
{
  return x * 255;
}

void
testTortureExecute (void)
{
  if (foo (0x40) != 0x3fc0)
    ASSERT (0);
  return;
}

