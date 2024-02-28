/*
   20000313-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 127
#endif

/* I don't understand what the original test below is trying to do.  One thing is for sure,
a pointer without a memory space casting is incomplete in the 8051.

void
testTortureExecute (void)
{
  long winds = 0;

  while (winds != 0)
    {
      if (*(char *) winds)
	break;
    }

  if (winds == 0 || winds != 0 || *(char *) winds)
    return;

  ASSERT (0);
}
*/

void
testTortureExecute (void)
{
  volatile long winds = 0;

  while (winds != 0)
    {
      if (*(__xdata char *) winds)
	break;
    }

  if (winds == 0 || winds != 0 || *(__xdata char *) winds)
    return;

  ASSERT (0);
}


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 2;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20000314-1";
}
