/*
   bug3190029.c
*/

#include "../fwk/include/testfwk.h"

void bar(void)
{
}

/* No need to call this, threw
   error 20: Undefined identifier 'c' */
void foo(void)
{
	{
		int c;
		c = 0;	//undefined identifier?
	}
	(void (*)(void *))bar;
}

void testBug(void)
{
	ASSERT (1);
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
  return "cases_sdcc_bugs\\bug3190029";
}
