/* Test power of 2 based shifts.
   sign: signed, unsigned
 */
#include "../fwk/include/testfwk.h"

void
testIntShift(void)
{
  volatile unsigned int left;

  left = 4;
  ASSERT(left * 1024 == 4096);
  ASSERT(left * 2048 == 8192);
  ASSERT(left * 256 == 1024);
  ASSERT(left * 64 == 256);

  left = 4096;
  ASSERT(left / 1024 == 4);
  ASSERT(left / 2048 == 2);
  ASSERT(left / 256 == 16);
  ASSERT(left / 4 == 1024);
}

void
__runSuite(void)
{
  __prints("Running testIntShift\n");
  testIntShift();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_pow2shifts_sign_unsigned";
}
