/*
   20060110-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when long long comes to these ports!
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
long long 
f (long long a) 
{ 
  return (a << 32) >> 32; 
} 
long long a = 0x1234567876543210LL;
long long b = (0x1234567876543210LL << 32) >> 32;
#endif

void
testTortureExecute (void)
{
// TODO: Enable when C51 supports unsigned long long constants!
#if 0
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  if (f (a) != b)
    ASSERT (0);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-20060110-1";
}
