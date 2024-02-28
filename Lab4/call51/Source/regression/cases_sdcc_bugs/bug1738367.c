/*
   bug1738367.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

#ifdef __bool_true_false_are_defined

bool ternary(unsigned char status)
{
	return (status == 0) ? 0 : 1;
}

bool ternary_inv(unsigned char status)
{
	return (status == 0) ? 1 : 0;
}


bool ternary1(unsigned char status)
{
	return status ? 1 : 0;
}

bool ternary1_inv(unsigned char status)
{
	return status ? 0 : 1;
}


bool ternary2(unsigned char status)
{
	return !status ? 0 : 1;
}

bool ternary2_inv(unsigned char status)
{
	return !status ? 1 : 0;
}

#endif //__bool_true_false_are_defined


void
testBug(void)
{
#ifdef __bool_true_false_are_defined
	ASSERT(!ternary(0x00));
	ASSERT( ternary(0x10));

	ASSERT( ternary_inv(0x00));
	ASSERT(!ternary_inv(0x10));

	ASSERT(!ternary1(0x00));
	ASSERT( ternary1(0x10));

	ASSERT( ternary1_inv(0x00));
	ASSERT(!ternary1_inv(0x10));

	ASSERT(!ternary2(0x00));
	ASSERT( ternary2(0x10));

	ASSERT( ternary2_inv(0x00));
	ASSERT(!ternary2_inv(0x10));
	ASSERT(!ternary2_inv(1==1));
#endif //__bool_true_false_are_defined
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
  return "cases_sdcc_bugs\\bug1738367";
}
