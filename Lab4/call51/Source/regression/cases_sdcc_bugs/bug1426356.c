/*
   bug1426356.c
*/

#include "../fwk/include/testfwk.h"

const union pu {
  unsigned char t1;
  unsigned char t2;
} tst[2] = {{ 1 }, { 2 }};

void
test_1426356(void)
{
  ASSERT( tst[0].t1 == 1 );
  ASSERT( tst[0].t2 == 1 );
  ASSERT( tst[1].t1 == 2 );
  ASSERT( tst[1].t2 == 2 );
}

void
__runSuite(void)
{
  __prints("Running test_1426356\n");
  test_1426356();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1426356";
}
