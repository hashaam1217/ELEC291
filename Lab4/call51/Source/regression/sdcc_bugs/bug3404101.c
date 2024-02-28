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

