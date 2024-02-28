/*
   20080506-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR middle-end/36137 */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && (__GNUC__ < 5))
  unsigned int u;
  int i = -1;

  u = MAX ((unsigned int) MAX (i, 0), 1);
  if (u != 1)
    ASSERT (0);

  u = MIN ((unsigned int) MAX (i, 0), (unsigned int) i);
  if (u != 0)
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
  return "cases_gcc\\gcc-torture-execute-20080506-1";
}
