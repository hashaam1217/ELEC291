/*
   bug2942247.c
*/

#include "../fwk/include/testfwk.h"


#pragma std_c5199

#define _Bool char

#ifndef __C51_WEIRD_BOOL
const _Bool foo[2] = {1, 2};

_Bool bar(void)
{
	return foo[1];	// Returned foo + 1 instead of foo[1].
}

_Bool bar2(void)
{
	_Bool foo[2] = {1, 2};
	return foo[1];	// Crashed c51.
}
#endif

void testBug(void)
{
#ifndef __C51_WEIRD_BOOL
	ASSERT(bar() == 1);
	ASSERT(bar2() == 1);
#endif
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
  return "cases_sdcc_bugs\\bug2942247";
}
