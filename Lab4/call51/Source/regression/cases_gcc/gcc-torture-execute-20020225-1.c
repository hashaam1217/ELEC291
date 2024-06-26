/*
   20020225-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* This testcase failed at -O2 on powerpc64 due to andsi3 writing
   nonzero bits to the high 32 bits of a 64 bit register.  */

unsigned long foo (unsigned long base, unsigned int val)
{
  return base + (val & 0x80000001);
}

void testTortureExecute (void)
{
  if (foo (0L, 0x0ffffff0) != 0L)
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
  return "cases_gcc\\gcc-torture-execute-20020225-1";
}
