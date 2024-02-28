/*
   990527-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int sum;

void
g (int i)
{
  sum += i;
}

void
f(int j)
{
  int i;

  for (i = 0; i < 9; i++)
    {
      j++;
      g (j);
      j = 9;
    }
}

void
testTortureExecute (void)
{
  f (0);
  if (sum != 81)
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
  return "cases_gcc\\gcc-torture-execute-990527-1";
}
