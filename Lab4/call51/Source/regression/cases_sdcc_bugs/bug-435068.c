/* bug-435068.c
 */
#include "../fwk/include/testfwk.h"

char c, d; 

static void
testQuestion(void)
{
    volatile char c, d;

    c = (0x100 & 0x100) ? 4 : 8; // ok 
    d = ((0x100 & 0x100) ? 4 : 8) + 1; 

    ASSERT(c == 4);
    ASSERT(d == 5);
} 

void
__runSuite(void)
{
  __prints("Running testQuestion\n");
  testQuestion();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-435068";
}
