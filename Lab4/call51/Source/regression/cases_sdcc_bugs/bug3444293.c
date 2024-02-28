/*
   bug3444293.c
*/

#include "../fwk/include/testfwk.h"

void __code* s[3];

void f(void)
{
	s[0] = 0;
	s[1] = 0; // Access to s is off by one byte here.
}

void testBug(void)
{
	s[0] = (void __code*)(0xffff);
	s[1] = (void __code*)(0xffff);
	f();
	ASSERT(!s[0]);
	ASSERT(!s[1]);
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
  return "cases_sdcc_bugs\\bug3444293";
}
