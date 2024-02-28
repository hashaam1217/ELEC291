/*
   930513-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"
#include <stdio.h>

char buf[12];

void f (int (*fp)(char *, const char *, ...))
{
  (*fp)(buf, "%.0f", 5.0);
}

void
testTortureExecute (void)
{
  f (&sprintf);
  ASSERT ((buf[0] == '<' && buf[1] == 'N') ||   // "<NO FLOAT>""
          (buf[0] == '5' && buf[1] == 0));      // "5"
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
  return "cases_gcc\\gcc-torture-execute-930513-1";
}
