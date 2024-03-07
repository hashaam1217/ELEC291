/*
   bug2956580.c
 */

#include "../fwk/include/testfwk.h"

// no need to call this, it generates compiler error:
//   error 33: Attempt to assign value to a constant variable (=)
char foo(const char* s)
{
	char a[1];
	const char* ss = s;
	// The value of the constant variable 's' is not modified rather the pointer is incremented for which C51 seems to throw error.
	// In reality it was the iTemp for *++s that was considered const but needs to be assigned.
	a[*++s] |= 1;
	return 0;
}

void
testBug (void)
{
	ASSERT (1);
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
  return "cases_sdcc_bugs\\bug2956580";
}