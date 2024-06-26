/*
    bug 1721024
*/

#include "../fwk/include/testfwk.h"

static unsigned char temp1;
static unsigned char temp2;

void tst(unsigned long acc)
{
	UNUSED(acc);
	temp1--;
	if (temp1==0)
	{
		temp2=0;
	}
}

void
testBug(void)
{
	temp1 = 1;
	temp2 = 2;
	tst(0xFFFFFFFF);	//make sure acc!=0
	ASSERT(temp2 == 0);
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
  return "cases_sdcc_bugs\\bug1721024";
}
