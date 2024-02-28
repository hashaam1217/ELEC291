/** Shows segfault.
    type: int
 */
#include "../fwk/include/testfwk.h"

void
spoil(int f)
{
  UNUSED(f);
}

void
testDivBySelf(void)
{
  volatile int left, result;

  left = 17;
  result = left/left;

  spoil(result);
}

void
__runSuite(void)
{
  __prints("Running testDivBySelf\n");
  testDivBySelf();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-485362_type_int";
}
