/*
   20020911-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned short c = 0x8000;
void
testTortureExecute (void)
{
  if ((c-0x8000) < 0 || (c-0x8000) > 0x7fff)
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
  return "cases_gcc\\gcc-torture-execute-20020911-1";
}
