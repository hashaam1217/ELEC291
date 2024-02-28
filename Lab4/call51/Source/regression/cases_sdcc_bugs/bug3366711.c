/*
    bug 3366711
*/

#include "../fwk/include/testfwk.h"

void f(unsigned char c)
{
	unsigned char __xdata * p = (unsigned char __xdata *)8;
	p[3] = c ? 2 : 1; /* Old register allocator crashed in this assignment to a constant address. */
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
  return "cases_sdcc_bugs\\bug3366711";
}
