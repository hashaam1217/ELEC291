/*
   bug1065458.c
*/

#include "../fwk/include/testfwk.h"

unsigned short f()
{
  return 0xff00;
}

unsigned short g()
{
  return f() ? 1 : 0;
}

void
test_1065458(void)
{
  ASSERT( 1 == g() );
}

void
__runSuite(void)
{
  __prints("Running test_1065458\n");
  test_1065458();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1065458";
}
