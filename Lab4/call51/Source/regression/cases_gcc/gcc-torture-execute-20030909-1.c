/*
   20030909-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void test(int x, int y)
{
  if (x == y)
    ASSERT (0);
}

void foo(int x, int y)
{
  if (x == y)
    goto a;
  else
    {
a:;
      if (x == y)
	goto b;
      else
	{
b:;
	  if (x != y)
	    test (x, y);
	}
    }
}

void
testTortureExecute (void)
{
  foo (0, 0);

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
  return "cases_gcc\\gcc-torture-execute-20030909-1";
}
