/** Test long OR.
    Was a bug where 1 was turned into 0x10000 on PPC.
 */
#include "../fwk/include/testfwk.h"

void
testLongOR(void)
{
  volatile unsigned long l;

  l = 0;
  l |= 1L;
  ASSERT(l == 1);

  l = 0;
  l |= 1;
  ASSERT(l == 1);
}

void
__runSuite(void)
{
  __prints("Running testLongOR\n");
  testLongOR();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_longor";
}
