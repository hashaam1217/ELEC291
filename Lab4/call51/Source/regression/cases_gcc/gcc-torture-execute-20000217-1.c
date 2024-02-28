/*
   20000217-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned short int showbug(unsigned short int *a, unsigned short int *b)
{
        *a += *b -8;
        return (*a >= 8);
}

void
testTortureExecute (void)
{
        unsigned short int x = 0;
        unsigned short int y = 10;

        if (showbug(&x, &y) != 0)
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
  return "cases_gcc\\gcc-torture-execute-20000217-1";
}
