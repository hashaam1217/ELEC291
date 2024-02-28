/*
   990106-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

foo(char *bufp)
{
    int x = 80;
    return (*bufp++ = x ? 'a' : 'b');
}

void
testTortureExecute (void)
{
  char x;

  if (foo (&x) != 'a')
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
  return "cases_gcc\\gcc-torture-execute-990106-1";
}
