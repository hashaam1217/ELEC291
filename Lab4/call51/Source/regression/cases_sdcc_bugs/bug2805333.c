/*
   bug2805333.c
*/

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

void g(char c)
{
  c;
}

bool b;

void test_bug(void)
{
  g(!b); /* Causes C51 2.9.0 to segfault.. */
}

void
__runSuite(void)
{
  __prints("Running test_bug\n");
  test_bug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug2805333";
}
