/*
   950612-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
unsigned int
f1 (int diff)
{
  return ((unsigned int) (diff < 0 ? -diff : diff));
}

unsigned int
f2 (unsigned int diff)
{
  return ((unsigned int) ((signed int) diff < 0 ? -diff : diff));
}

unsigned long long
f3 (long long diff)
{
  return ((unsigned long long) (diff < 0 ? -diff : diff));
}

unsigned long long
f4 (unsigned long long diff)
{
  return ((unsigned long long) ((signed long long) diff < 0 ? -diff : diff));
}
#endif

void
testTortureExecute (void)
{
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16) && !defined(__C51_gbz80)
  int i;
  for (i = 0; i <= 10; i++)
    {
      if (f1 (i) != i)
	ASSERT (0);
      if (f1 (-i) != i)
	ASSERT (0);
      if (f2 (i) != i)
	ASSERT (0);
      if (f2 (-i) != i)
	ASSERT (0);
      if (f3 ((long long) i) != i)
	ASSERT (0);
      if (f3 ((long long) -i) != i)
	ASSERT (0);
      if (f4 ((long long) i) != i)
	ASSERT (0);
      if (f4 ((long long) -i) != i)
	ASSERT (0);
    }
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
  return "cases_gcc\\gcc-torture-execute-950612-1";
}
