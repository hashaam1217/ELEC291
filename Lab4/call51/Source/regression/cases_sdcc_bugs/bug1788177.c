/*
    bug 1788177
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

#ifdef __bool_true_false_are_defined

bool var;

// no need to call this, it generates compiler error:
//   Caught signal 11: SIGSEGV
void foo(bool parm) {
	var = parm;
}

#endif

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
  return "cases_sdcc_bugs\\bug1788177";
}
