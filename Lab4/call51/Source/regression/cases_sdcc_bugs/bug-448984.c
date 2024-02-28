/* bug-448984.c
 */
#include "../fwk/include/testfwk.h"

void
testRshRem(void)
{
  volatile int rem, quot;

  quot = 4;
  rem = 5000;

  rem = rem - (quot*1024);

  ASSERT(rem == 904);
}

void
__runSuite(void)
{
  __prints("Running testRshRem\n");
  testRshRem();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-448984";
}
