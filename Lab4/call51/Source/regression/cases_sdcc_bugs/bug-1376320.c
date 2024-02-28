/* bug-1376320.c

   copy signedness while replacing operands
 */
#include "../fwk/include/testfwk.h"

static void
testSign(void)
{
  signed long l;

  l = 3;
  l -= 5ul;
  ASSERT(l < 0);
}

void
__runSuite(void)
{
  __prints("Running testSign\n");
  testSign();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1376320";
}
