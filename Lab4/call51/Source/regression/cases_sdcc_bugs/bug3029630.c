/*
   bug3029630.c
 */

#include "../fwk/include/testfwk.h"

struct a
{
	void *a;
} s;

/* should not give 
   warning 196: pointer target lost const qualifier */
void foo(const struct a *x)
{
	void *const y = x->a;
	(void)y;
}

void testBug(void)
{
	foo(&s);
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
  return "cases_sdcc_bugs\\bug3029630";
}
