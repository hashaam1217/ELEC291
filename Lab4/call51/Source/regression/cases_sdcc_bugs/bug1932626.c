/*
 * bug1932626.c
 */

#include "../fwk/include/testfwk.h"
#include <string.h>

void CopyString(char acSource[], char acDestination[])
{
	unsigned char ucCurrentPosition;

	for (ucCurrentPosition = 0; ; ucCurrentPosition++)
	{
		acDestination[ucCurrentPosition]=acSource[ucCurrentPosition];
		if (0==acSource[ucCurrentPosition])
			break;
	}
}

void testBug(void)
{
	char text1[] = "spam";
	char text2[16];
	CopyString(text1, text2);
	ASSERT(!strcmp(text1, text2));
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
  return "cases_sdcc_bugs\\bug1932626";
}
