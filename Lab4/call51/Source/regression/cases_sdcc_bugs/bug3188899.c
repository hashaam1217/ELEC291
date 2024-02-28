/*
 * bug3188899.c
 */

#include "../fwk/include/testfwk.h"

/* bug 3188899
   ?ASlink-Warning-Undefined Global '_s1' referenced by module
   _s1 should be _testBug3188899_s1_1_1 */
void * testBug3188899 (void)
{
  static char s1;
  static void * const __code s2 = &s1;
  return s2;
}

void
__runSuite(void)
{
  __prints("Running testBug3188899\n");
  testBug3188899();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug3188899";
}
