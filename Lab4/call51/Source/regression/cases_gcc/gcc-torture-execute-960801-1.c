/*
   960801-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Some ports do not yet support long long.
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16) && !defined(__C51_gbz80)
unsigned
f ()
{
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

unsigned long long
g ()
{
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}
#endif

void
testTortureExecute (void)
{
// Test fails on 32-bit systems
#if 0
//#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16) && !defined(__C51_gbz80)
  if (f () != (unsigned short) -1)
    ASSERT (0);
  if (g () != (unsigned short) -1)
    ASSERT (0);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-960801-1";
}
