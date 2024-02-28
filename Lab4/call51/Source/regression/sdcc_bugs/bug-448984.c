/* bug-448984.c
 */
#include "../fwk/include/testfwk.h"

void
testRshRem(void)
{
  volatile int rem, quot;

  quot = 4;
  rem = 5000;

  rem = rem - (quot*1024);

  ASSERT(rem == 904);
}
