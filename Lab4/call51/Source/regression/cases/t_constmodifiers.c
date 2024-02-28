/* Tests usage of constant modifiers.
 */
#include "../fwk/include/testfwk.h"

void
testUMod(void)
{
  volatile unsigned char a = 0;

  ASSERT((a |= 0xFFL) == 0xFFL);
}

void
__runSuite(void)
{
  __prints("Running testUMod\n");
  testUMod();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_constmodifiers";
}
