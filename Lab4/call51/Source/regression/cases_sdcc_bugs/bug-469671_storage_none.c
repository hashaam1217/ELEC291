/* bug 469671.c

   storage: static, 
 */
#include "../fwk/include/testfwk.h"

void
testMul(void)
{
   volatile int a, b;

  a = 5;
  b = a*2;
  ASSERT(b == 10);

  a = -33;
  b = a*2;
  ASSERT(b == -66);
}

void
__runSuite(void)
{
  __prints("Running testMul\n");
  testMul();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-469671_storage_none";
}
