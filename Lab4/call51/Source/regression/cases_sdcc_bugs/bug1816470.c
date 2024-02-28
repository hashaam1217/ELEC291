/*
    bug 1816470
*/

#include "../fwk/include/testfwk.h"

int CalculatedConst(void)
{
	return (unsigned char)(0x100 - 4000000 / 307200.0 + .5);
}

void
testConst(void)
{
	ASSERT(CalculatedConst() == 0xF3);
}

void
__runSuite(void)
{
  __prints("Running testConst\n");
  testConst();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1816470";
}
