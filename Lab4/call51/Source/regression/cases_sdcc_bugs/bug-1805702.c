/* bug-1805702.c
 */

#include "../fwk/include/testfwk.h"

int foo;
extern int foo;

void
test(void)
{
  foo = 10;

  ASSERT(foo == 10);
}

/* compile time check for compiler defined functions (cdef) */

float __fsmul (float, float);

float __fsmul (float a1, float a2) {
  /* just for tesing... */
  return (a1 + a2);
}

void
__runSuite(void)
{
  __prints("Running test\n");
  test();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1805702";
}
