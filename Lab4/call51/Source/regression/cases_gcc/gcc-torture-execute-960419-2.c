/*
   960419-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#define SIZE 8

void
testTortureExecute (void)
{
  int a[SIZE] = {1};
  int i;

  for (i = 1; i < SIZE; i++)
    if (a[i] != 0)
      ASSERT(0);

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
  return "cases_gcc\\gcc-torture-execute-960419-2";
}
