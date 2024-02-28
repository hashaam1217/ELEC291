/*
   20031211-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif


struct a { unsigned int bitfield : 1; };

unsigned int x;

void
testTortureExecute (void)
{
  struct a a = {0};
  x = 0xbeef;
  a.bitfield |= x;
  if (a.bitfield != 1)
    ASSERT (0);
  return;
}


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20031211-1";
}
