/*
   960218-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int glob;

int g (int x)
{
  glob = x;
  return 0;
}

void f (int x)
{
  int a = ~x;
  while (a)
    a = g (a);
}

void
testTortureExecute (void)
{
  f (3);
  if (glob != -4)
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
  return "cases_gcc\\gcc-torture-execute-960218-1";
}
