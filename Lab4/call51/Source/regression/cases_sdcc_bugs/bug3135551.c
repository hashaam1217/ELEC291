/*
   bug3135551.c
*/

#include "../fwk/include/testfwk.h"

char test1[] = {3};
char test2[1] = {1 + 2};
char test3[] = {1 + 2, 1 + 2};
char test4[] = {1 + 2}; //this line failed with error 2: Initializer element is not constant
char test5[] = "a";

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
  return "cases_sdcc_bugs\\bug3135551";
}
