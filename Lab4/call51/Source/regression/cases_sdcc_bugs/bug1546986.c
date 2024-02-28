/*
   bug1546986.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

#ifdef __bool_true_false_are_defined

static unsigned char __pdata tst1 = 0x01;
static unsigned char __pdata tst2 = 0x00;

static bool test;

#endif //__bool_true_false_are_defined

void
testBug (void)
{
#ifdef __bool_true_false_are_defined
  test = (tst1 | tst2);
  ASSERT (test);
  test = (tst2 | tst1);
  ASSERT (test);
#endif //__bool_true_false_are_defined
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
  return "cases_sdcc_bugs\\bug1546986";
}
