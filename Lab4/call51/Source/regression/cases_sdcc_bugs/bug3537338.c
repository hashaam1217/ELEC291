/*
   bug3537338.c
*/

#include "../fwk/include/testfwk.h"

#if defined (__C51)
 #include <c51-lib.h> /* just to get _AUTOMEM or _STATMEM */
#else
 #define _STATMEM
#endif

int globals[3] = {1, 2, 3};
int _STATMEM * ptr = &globals[1];

int get_signed(signed char index)
{
	return *(ptr+index);
}

int get_unsigned(unsigned char index)
{
	return *(ptr+index);
}

void testBug(void)
{
    ASSERT (get_signed(-1) == globals[0]);
    ASSERT (get_signed(1) == globals[2]);
    ASSERT (get_unsigned(1) == globals[2]);
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
  return "cases_sdcc_bugs\\bug3537338";
}
