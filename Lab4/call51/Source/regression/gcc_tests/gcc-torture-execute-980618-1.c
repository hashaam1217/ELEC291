/*
   980618-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void func(int, int);

void
testTortureExecute (void)
{
        int x = 7;
        func(!x, !7);
	return;
}

void func(int x, int y)
{
        if (x == y)
                return;
        else
                ASSERT (0);
}

