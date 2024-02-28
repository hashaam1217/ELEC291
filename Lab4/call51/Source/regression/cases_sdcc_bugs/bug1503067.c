/* bug1503067.c
 */
#include "../fwk/include/testfwk.h"

const int SPRITE = 0;
int sprite = 1;

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
  return "cases_sdcc_bugs\\bug1503067";
}
