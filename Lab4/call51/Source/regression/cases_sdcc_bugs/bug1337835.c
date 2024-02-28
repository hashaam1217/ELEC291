/*
   bug1337835.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

char e;

void foo (unsigned long ul, bool b, char c) REENTRANT
{
	if (b && (long) ul < 0)
		e = 0;
	if (ul && b && c)
		e = 1;
}

void
test_1337835(void)
{
  e = 2;
  foo(0, 1, 0);
  ASSERT( e == 2 );
}

void
__runSuite(void)
{
  __prints("Running test_1337835\n");
  test_1337835();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1337835";
}
