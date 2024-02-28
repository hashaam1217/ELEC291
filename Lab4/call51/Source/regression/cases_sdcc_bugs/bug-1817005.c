/* bug-1817005.c
 */

#include "../fwk/include/testfwk.h"

/* this is an assemble time test, so it doesn't have to be executed */

int
function_with_really_long_name(void)
{
  return 0;
}

/* dummy test function */

void
testDummy(void)
{
}

void
__runSuite(void)
{
  __prints("Running testDummy\n");
  testDummy();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1817005";
}
