/*
    bug 1670148.c
*/

#include "../fwk/include/testfwk.h"

// no need to call this, it generates compiler error for xstack-auto
//   error 9: FATAL Compiler Internal Error
struct str {
  long  aa;
  long  bb;
};

struct str *v1;

void foo(void)
{
	struct str v2;
	struct str loc;

	v2.aa = 0;
	loc.bb  =  v1->bb;
	loc.aa  =  v1->aa - v2.aa;

	loc.bb += 0;
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
  return "cases_sdcc_bugs\\bug1670148";
}
