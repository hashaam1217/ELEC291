/*
   bug3027957.c
 */

#include "../fwk/include/testfwk.h"

void foo(void)
{
  ((unsigned char __xdata *)0xF000)[100] = 0x12;
}

/* bug 3034400: this  should not give a warning/error */
char * correct(void)
{
  return (char __code *) 0x1234;
}

void testBug(void)
{
#ifdef __C51
  foo();
  ASSERT (*(unsigned char __xdata *)(0xF064) == 0x12);
#endif
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
  return "cases_sdcc_bugs\\bug3027957";
}
