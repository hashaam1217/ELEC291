/*
    bug 1579949
*/

#include "../fwk/include/testfwk.h"

struct st_s
{
	char el;
};

// no need to call this, it generates compiler error for z80, hc08, stack-auto
//   error 9: FATAL Compiler Internal Error
char foo (int x, struct st_s *arg)
{
	x;
	return ((struct st_s *) arg) -> el;
}

void
testBug(void)
{
	ASSERT(1);
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
  return "cases_sdcc_bugs\\bug1579949";
}
