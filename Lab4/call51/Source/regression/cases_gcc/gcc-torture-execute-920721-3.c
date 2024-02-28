/*
   920721-3.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static inline fu (unsigned short data)
{
  return data;
}

void ru(int i)
{
   if(fu(i++)!=5)ASSERT(0);
   if(fu(++i)!=7)ASSERT(0);
}

static inline fs (signed short data)
{
  return data;
}

void rs(int i)
{
   if(fs(i++)!=5)ASSERT(0);
   if(fs(++i)!=7)ASSERT(0);
}


void
testTortureExecute (void)
{
  ru(5);
  rs(5);
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
  return "cases_gcc\\gcc-torture-execute-920721-3";
}
