/*
   pr49768.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/49768 */

void
testTortureExecute (void)
{
  static struct { unsigned int : 1; unsigned int s : 1; } s;
  
  s.s = 1 ;
  if (s.s != 1)
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
  return "cases_gcc\\gcc-torture-execute-pr49768";
}
