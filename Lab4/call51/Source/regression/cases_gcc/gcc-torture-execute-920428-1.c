/*
   920428-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

x (const char*s)
{
  char a[1];
  const char *ss = s;
  a[*s++] |= 1;
  return (int)ss + 1 == (int)s;
}

void
testTortureExecute (void)
{
  if (x("") != 1)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-920428-1";
}
