/*
   960909-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
ffs (int x)
{
  int mybit, mask;

  if (x == 0)
    return 0;

  for (mybit = 1, mask = 1; !(x & mask); mybit++, mask <<= 1)
    ;

  return mybit;
}

void f (int x)
{
  int y;
  y = ffs (x) - 1;
  if (y < 0) 
    ASSERT (0);
}

void
testTortureExecute (void)
{
  f (1);
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
  return "cases_gcc\\gcc-torture-execute-960909-1";
}
