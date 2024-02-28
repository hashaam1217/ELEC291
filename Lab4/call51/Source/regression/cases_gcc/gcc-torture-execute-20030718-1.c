/*
   20030718-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR c/10320
   The function temp was not being emitted in a prerelease of 3.4 20030406. 
   Contributed by pinskia@physics.uc.edu */

static inline void temp();
void
testTortureExecute (void)
{
        temp();
        return;
}
static void temp(){}


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20030718-1";
}
