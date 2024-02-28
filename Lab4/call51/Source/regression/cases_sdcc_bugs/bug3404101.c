/*
   bug3404101.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdbool.h>

#ifndef __C51_WEIRD_BOOL
struct a
{
	bool a : 1;
};

void f(struct a *s)
{
	1 && s->a;	// Compilation failed: Logical op with bitfield boolean.
}
#endif

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
  return "cases_sdcc_bugs\\bug3404101";
}
