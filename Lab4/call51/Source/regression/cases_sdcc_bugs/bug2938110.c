/*
   bug2938110.c
 */

#include "../fwk/include/testfwk.h"

// no need to call this, it generates compiler error:
//   Internal error: validateOpType failed in
//   OP_SYMBOL(IC_LEFT(ic)) @ src/ds390/ralloc.c:2660:
//   expected symbol, got value
int
foo (int b)
{
	int a = 10;
	a += b;
	return a;
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
  return "cases_sdcc_bugs\\bug2938110";
}
