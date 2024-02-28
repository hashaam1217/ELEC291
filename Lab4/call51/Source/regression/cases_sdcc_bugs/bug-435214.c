/* bug-435214.c
 */
#include "../fwk/include/testfwk.h"

unsigned long divide(long a)
{
    return a/512ul;
}

void
testDivide(void)
{
  ASSERT(divide(1300) == 2);
  ASSERT(divide(0x12345678) == 0x91A2B);
}


void
__runSuite(void)
{
  __prints("Running testDivide\n");
  testDivide();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-435214";
}
