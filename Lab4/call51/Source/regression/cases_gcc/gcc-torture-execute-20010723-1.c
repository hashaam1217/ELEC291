/*
   200107231.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int
f ()
{
  int biv,giv;
  for (biv = 0, giv = 0; giv != 8; biv++)
      giv = biv*8;
  return giv;
}

void
testTortureExecute (void)
{
  if (f () != 8)
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
  return "cases_gcc\\gcc-torture-execute-20010723-1";
}
