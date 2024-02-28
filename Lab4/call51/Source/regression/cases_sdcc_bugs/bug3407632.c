/** bug 3407632
 */

#include "../fwk/include/testfwk.h"

int y;

void f(unsigned int x)
{
	if(x > 0x3fff)
		y = 0;
}

void g(unsigned int x)
{
	if(x > 0x4000)
		y = 0;
}

void
testBug (void)
{
	y = 1;
	f(1);
	ASSERT(y == 1);
	g(1);
	ASSERT(y == 1);
	g(0x4000);
	ASSERT(y == 1);
	f(0x4000);
	ASSERT(y == 0);
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
  return "cases_sdcc_bugs\\bug3407632";
}
