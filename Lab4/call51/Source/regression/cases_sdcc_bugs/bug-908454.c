/* promoting bit to char */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

#if !defined(__bool_true_false_are_defined)
volatile int a = 1, b = 1;
#else
volatile bool a = 1, b = 1;
#endif

char
foo (void)
{
  return (a << 1) | b;
}

static void
testBitToCharPromotion(void)
{
  ASSERT(foo() == 3);
}

void
__runSuite(void)
{
  __prints("Running testBitToCharPromotion\n");
  testBitToCharPromotion();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-908454";
}
