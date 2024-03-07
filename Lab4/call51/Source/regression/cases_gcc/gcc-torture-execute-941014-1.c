/*
   941014-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

int f (int a, int b) { }

void
testTortureExecute (void)
{
  unsigned long addr1;
  unsigned long addr2;

  addr1 = (unsigned long) &f;
  addr1 += 5;
  addr2 = 5 + (unsigned long) &f;

  if (addr1 != addr2)
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
  return "cases_gcc\\gcc-torture-execute-941014-1";
}