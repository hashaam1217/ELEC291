/*
   20000801-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
foo (char *bp, unsigned n)
{
  register char c;
  register char *ep = bp + n;
  register char *sp;

  while (bp < ep)
    {
      sp = bp + 3;
      c = *sp;
      *sp = *bp;
      *bp++ = c;
      sp = bp + 1;
      c = *sp;
      *sp = *bp;
      *bp++ = c;
      bp += 2;
    }
}

void
testTortureExecute (void)
{
  int one = 1;

  if (sizeof(int) != 4 * sizeof(char))
    return;

  foo ((char *)&one, sizeof(one));
  foo ((char *)&one, sizeof(one));

  if (one != 1)
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
  return "cases_gcc\\gcc-torture-execute-20000801-1";
}
