/* Floats
 */
#include "../fwk/include/testfwk.h"

const float a = 0.0;

float f(void)
{
  return a * 5;
}

void testBug(void)
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
  return "cases_sdcc_bugs\\bug-499644";
}
