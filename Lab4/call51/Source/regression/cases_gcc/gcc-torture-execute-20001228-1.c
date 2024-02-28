/*
   20001228-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int foo1(void)
{
  union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;
  
  u.b = 0x01;
  return u.a[0];
}

int foo2(void)
{
  volatile union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;
  
  u.b = 0x01;
  return u.a[0];
}

void
testTortureExecute (void)
{
  if (foo1() != foo2())
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
  return "cases_gcc\\gcc-torture-execute-20001228-1";
}
