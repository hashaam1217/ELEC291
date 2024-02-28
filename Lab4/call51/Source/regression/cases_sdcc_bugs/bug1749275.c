/*
    bug 1749275
*/

#include "../fwk/include/testfwk.h"

__xdata char baz;

// no need to call this, it generates compiler error:
//   Internal error: validateOpType failed in
//   OP_SYM_TYPE(IC_LEFT(pl->ic)) @ peep.c:226:
//   expected symbol, got value
void
foo(void)
{
  baz |= 5;
  (*(void (*) ()) 0) ();
}

void
testBug (void)
{
  ASSERT (1);
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
  return "cases_sdcc_bugs\\bug1749275";
}
