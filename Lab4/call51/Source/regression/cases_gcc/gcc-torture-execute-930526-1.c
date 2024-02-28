/*
   930526-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0
inline
void f (int x)
{
  int *(p[25]);
  int m[25*7];
  int i;

  for (i = 0; i < 25; i++)
    p[i] = m + x*i;

  p[1][0] = 0;
}
#endif

void
testTortureExecute (void)
{
#if 0
  f (7);
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-930526-1";
}
