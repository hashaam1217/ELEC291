/*
   961017-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
  unsigned char z = 0;

  do ;
  while (--z > 0);
  return;
}

