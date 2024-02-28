/*
   20011114-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

char foo(char bar[])
{
  return bar[1];
}
extern char foo(char *);
void
testTortureExecute (void)
{
  if (foo("xy") != 'y')
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
  return "cases_gcc\\gcc-torture-execute-20011114-1";
}
