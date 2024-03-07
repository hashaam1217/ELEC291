/*
   921016-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
#ifndef __C51_pic16 // TODO: enable when the pic16 ports supports bitfields of size greater than 8 bits!
  int j=1081;
  struct
    {
      signed int m:11;
   } l;
  if((l.m = j) == j)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-921016-1";
}