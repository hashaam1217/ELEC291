/*
   loop-9.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c89
#endif

/* Source: Neil Booth, from PR # 115.  */

int false()
{
  return 0;
}

void
testTortureExecute (void)
{
  int count = 0;

  while (false() || count < -123)
    ++count;

  if (count)
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
  return "cases_gcc\\gcc-torture-execute-loop-9";
}