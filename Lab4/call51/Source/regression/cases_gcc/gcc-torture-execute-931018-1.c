/*
   931018-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c89
#endif

unsigned int a[/*0x1000*/20];
extern const unsigned long v;

void f (unsigned long a);

void
testTortureExecute (void)
{
  f (v);
  f (v);
  return;
}

void f (unsigned long a)
{
  if (a != 0xdeadbeefL)
    ASSERT (0);
}

const unsigned long v = 0xdeadbeefL;


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
  return "cases_gcc\\gcc-torture-execute-931018-1";
}
