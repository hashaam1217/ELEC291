/*
   bug3482217.c
*/

#include "../fwk/include/testfwk.h"

unsigned char *p;

void f()
{
  *p++ = 0;
}

void testBug(void)
{
	unsigned char a[2];
	p = a;
	f();
	ASSERT(p == a + 1);
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
  return "cases_sdcc_bugs\\bug3482217";
}
