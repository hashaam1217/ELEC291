/*
   bug3303325.c
*/

#include "../fwk/include/testfwk.h"

unsigned char a;
void f(unsigned char b)
{	
  a = b;
}

void
testBug (void)
{
  a = 1;
  f(2);
  ASSERT (a == 2);
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
  return "cases_sdcc_bugs\\bug3303325";
}
