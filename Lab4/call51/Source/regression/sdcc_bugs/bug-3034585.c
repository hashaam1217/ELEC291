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

