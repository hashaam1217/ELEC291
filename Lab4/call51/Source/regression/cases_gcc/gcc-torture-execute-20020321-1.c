/*
   20020321-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#pragma disable_warning 85

/* PR 3177 */
/* Produced a SIGILL on ia64 with sibcall from F to G.  We hadn't
   widened the register window to allow for the fourth outgoing
   argument as an "in" register.  */

float g (void *a, void *b, int e, int c, float d)
{
  return d;
}

float f (void *a, void *b, int c, float d)
{
  return g (a, b, 0, c, d);
}

void
testTortureExecute (void)
{
  f (0, 0, 1, 1);
  return;
}


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
  return "cases_gcc\\gcc-torture-execute-20020321-1";
}
