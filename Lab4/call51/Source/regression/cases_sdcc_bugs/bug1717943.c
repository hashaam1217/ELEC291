/*
   bug1717943c.c
     an error in the detection of loopinvariants,
      will move the foo=0 initialisation out of the loops.
 */

#include "../fwk/include/testfwk.h"

char foo, firstcall;

char check(void)
{
  if(!firstcall)
    return 1;

  firstcall=0;
  foo = 42;
  return 0;
}

void bug(void)
{
  while(1) {
    foo = 0;
    while(check())
      if(check())
        return;
  }
}


void
testBug(void)
{
  firstcall = 1;
  bug();
  ASSERT(foo == 0);
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
  return "cases_sdcc_bugs\\bug1717943";
}
