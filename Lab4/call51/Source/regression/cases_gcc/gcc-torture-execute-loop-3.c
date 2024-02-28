/*
   loop-3.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

#include <limits.h>

int n = 0;

void g (int i)
{
  n++;
}

void f (int m)
{
  int i;
  i = m;
  do
    {
      g (i * INT_MAX / 2);
    }
  while (--i > 0);
}

void
testTortureExecute (void)
{
  f (4);
  if (n != 4)
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
  return "cases_gcc\\gcc-torture-execute-loop-3";
}
