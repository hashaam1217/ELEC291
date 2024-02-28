/*
   20100827-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
foo (char *p)
{
  int h = 0;
  do
    {
      if (*p == '\0')
	break;
      ++h;
      if (p == 0)
	ASSERT (0);
      ++p;
    }
  while (1);
  return h;
}

void
testTortureExecute (void)
{
  if (foo("a") != 1)
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
  return "cases_gcc\\gcc-torture-execute-20100827-1";
}
