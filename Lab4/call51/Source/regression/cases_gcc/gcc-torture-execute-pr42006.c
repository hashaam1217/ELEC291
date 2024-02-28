/*
   pr42006.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static unsigned int
my_add(unsigned int si1, unsigned int si2)
{
  return (si1 > (50-si2)) ? si1 : (si1 + si2);
}

static unsigned int
my_shift(unsigned int left, unsigned int right)
{
  return  (right > 100) ? left : (left >> right);
}

static int func_4(unsigned int p_6)
{
  int count = 0;
  for (p_6 = 1; p_6 < 3; p_6 = my_add(p_6, 1))
    {
      if (count++ > 1)
	ASSERT (0);

      if (my_shift(p_6, p_6))
	return 0;
    }
  return 0;
}

void
testTortureExecute (void)
{
  func_4(0);
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
  return "cases_gcc\\gcc-torture-execute-pr42006";
}
