/*
   bug-3034585.c
*/

#include "../fwk/include/testfwk.h"

void tst()
{
}

void m()
{
	void *a = tst;	/* This line failed to compile */
}

void testBug(void)
{
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
  return "cases_sdcc_bugs\\bug-3034585";
}
