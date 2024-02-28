/*
   bug3564649.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma disable_warning 85

void g(void *p)
{
}

_Noreturn void e(void)
{
  while (1) {}
}

void f(int i)
{
	void *p;

	if(i == 7)
		p = 0;
	else
		e();

	g(p); /* False "may be used before initialization" warning occoured here. */
}
#endif

void testBug(void)
{
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
  return "cases_sdcc_bugs\\bug3564649";
}
