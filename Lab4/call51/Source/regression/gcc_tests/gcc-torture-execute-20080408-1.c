/*
   20080408-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
  short ssi = 126;
  unsigned short usi = 65280;
  int fail = !(ssi < usi);
  if (fail)
    ASSERT (0);
  return;
}

