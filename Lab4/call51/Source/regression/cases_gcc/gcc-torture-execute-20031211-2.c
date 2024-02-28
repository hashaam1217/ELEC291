/*
   20031211-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct a
{
  unsigned int bitfield : 3;
};

void foo(unsigned int z);

void
testTortureExecute (void)
{
  struct a a;

  a.bitfield = 131;
  foo (a.bitfield);
  return;
}

void foo(unsigned int z)
{
  if (z != 3)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20031211-2";
}
