/*
   pr49073.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"
#include <stdbool.h>

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/49073 */

int a[] = { 1, 2, 3, 4, 5, 6, 7 }, c;

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && defined (__GNUC_MINOR__) && (__GNUC__ < 5 && __GNUC_MINOR__ < 7))
  int d = 1, i = 1;
  _Bool f = 0;
  do
    {
      d = a[i];
      if (f && d == 4)
	{
	  ++c;
	  break;
	}
      i++;
      f = (d == 3);
    }
  while (d < 7);
  if (c != 1)
    ASSERT (0);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-pr49073";
}
