/*
   bug1348008.c
*/

#include "../fwk/include/testfwk.h"

#ifndef PORT_HOST

void
foo (void)
{
}

void
IRQ_ISR (void) __interrupt
{
  foo();
}

#endif

void
testBug (void)
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
  return "cases_sdcc_bugs\\bug1348008";
}
