/* Division by powers of two.
 */
#include "../fwk/include/testfwk.h"

void
testDivPow2(void)
{
  volatile int left;

  left = -18;
  ASSERT(left/4 == (-18/4));
}

void
__runSuite(void)
{
  __prints("Running testDivPow2\n");
  testDivPow2();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-524685";
}
