/* bug-221168.c
 */
#include "../fwk/include/testfwk.h"

__xdata static char x[10][20];

__xdata char *
getAddrOfCell (unsigned char y, unsigned char z)
{
  return &x[y][z];
}

static void
testMultiDimensionalAddress (void)
{
  ASSERT (getAddrOfCell (5, 6) == (char __xdata *)x + 106);
}

void
__runSuite(void)
{
  __prints("Running testMultiDimensionalAddress\n");
  testMultiDimensionalAddress();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-221168";
}
