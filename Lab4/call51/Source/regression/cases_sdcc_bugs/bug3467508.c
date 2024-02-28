/*
   bug1665511.c

   Cast of integer literals to pointer behaved differently than cast from integer.
*/

#include "../fwk/include/testfwk.h"

void testBug(void)
{
	volatile int i = -1;
	ASSERT((void *)(i) == (void *)(-1));
}


void
__runSuite(void)
{
  __prints("Running testBug\n");
  testBug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug3467508";
}
