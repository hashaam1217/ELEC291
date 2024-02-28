/* bug1399290.c
 */
#include "../fwk/include/testfwk.h"

unsigned long Left = 0x12345678;

void
testLongPlus(void)
{
	static unsigned long Result;
	static unsigned long Rhs = 0x87654321;
	static unsigned long *Lhs = &Left;

	Result = *Lhs + Rhs;
	ASSERT (Result == 0x99999999);
}

void
__runSuite(void)
{
  __prints("Running testLongPlus\n");
  testLongPlus();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1399290";
}
