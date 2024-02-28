/*
   20020611-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR target/6997.  Missing (set_attr "cc" "none") in sleu pattern in
   cris.md.  Testcase from hp@axis.com.  */

int p;
int k;
unsigned int n;

void x ()
{
  unsigned int h;

  h = n <= 30;
  if (h)
    p = 1;
  else
    p = 0;

  if (h)
    k = 1;
  else
    k = 0;
}

unsigned int n = 30;

void
testTortureExecute (void)
{
  x ();
  if (p != 1 || k != 1)
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
  return "cases_gcc\\gcc-torture-execute-20020611-1";
}
