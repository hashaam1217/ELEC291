/*
   bug3166064.c
*/

#include "../fwk/include/testfwk.h"

int print (const char * fmt, ...)
{
	ASSERT (*fmt == '%');
	return 5;
}

void bug3166064(unsigned char x)
{
	ASSERT (x == 5);
}

unsigned long l;

unsigned long *f(int * pi, unsigned char * pc)
{
	pi;
	pc;
	return &l;
}

void bug3394118(void * p)
{
	ASSERT (p == &l);
}

void testBug(void)
{
	bug3166064(print("%d", 1));
	bug3394118(f(0, 0));
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
  return "cases_sdcc_bugs\\bug3166064";
}
