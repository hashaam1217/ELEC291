/*
 * bug3117721.c
 */

#include "../fwk/include/testfwk.h"

/* should not generate:
   warning 185: comparison of 'signed char' with 'unsigned char' requires promotion to int */
char GenerateBug(unsigned char iKey)
{
	if (iKey == 'T')
	{
		return 1;
	}
	else if (iKey != 't')
	{
		return 2;
	}
	return 0;
}

void testBug(void)
{
	ASSERT(1);
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
  return "cases_sdcc_bugs\\bug3117721";
}
