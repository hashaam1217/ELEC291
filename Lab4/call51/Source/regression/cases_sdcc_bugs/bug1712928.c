/*
   bug1712928.c
*/

#include "../fwk/include/testfwk.h"

#if defined (__C51_mcs51)
unsigned char NakedFunc(void) __naked
{
	__asm
	mov	dpl,#0x01
#if defined (__C51_MODEL_HUGE)
	ljmp	__c51_banked_ret
#else
	ret
#endif
	__endasm;
}
#endif

void
testBug(void)
{
#if defined (__C51_mcs51)
	unsigned char hsum, sum;

	hsum = NakedFunc();
	sum = NakedFunc();
	sum += hsum;

	ASSERT(sum == 2);
#endif
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
  return "cases_sdcc_bugs\\bug1712928";
}