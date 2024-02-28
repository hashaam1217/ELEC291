/*
    bug 1838000
*/

#include "../fwk/include/testfwk.h"

typedef struct { char b:1; } t;
t glbl = { 0 };
t _STATMEM * gp = &glbl;

void func(char _AUTOMEM *p)
{
	*p++ = gp->b ? 'A' : 'B';
	*p   = 'C';
}

void
testBug(void)
{
	char x[2];
	func(x);
	ASSERT(x[0]=='B');
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
  return "cases_sdcc_bugs\\bug1838000";
}
