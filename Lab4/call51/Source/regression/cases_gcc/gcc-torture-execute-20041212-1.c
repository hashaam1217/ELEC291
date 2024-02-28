/*
   20041212-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* A function pointer compared with a void pointer should not be canonicalized.
   See PR middle-end/17564.  */
void *f (void);
void *
f (void)
{
  return f;
}
void
testTortureExecute (void)
{
  if (f () != f)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20041212-1";
}
