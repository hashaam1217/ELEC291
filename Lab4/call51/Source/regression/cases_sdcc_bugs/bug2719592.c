/*
 * bug2719592.c
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

bool foo(char i, bool bv)
{
	bv &= (i == 1);
	return bv;
}

void
testBug(void)
{
	ASSERT( !foo(0,0) );
	ASSERT( !foo(0,1) );
	ASSERT( !foo(1,0) );
	ASSERT( foo(1,1) );
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
  return "cases_sdcc_bugs\\bug2719592";
}
