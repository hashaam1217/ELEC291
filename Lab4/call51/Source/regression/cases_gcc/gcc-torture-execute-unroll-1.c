/*
   unroll-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

inline int
f (int x)
{
  return (x + 1);
}
 
void
testTortureExecute (void)
{
  int a = 0 ;
 
  while ( (f(f(f(f(f(f(f(f(f(f(1))))))))))) + a < 12 )
    {
      a++;
      return;
    }
  if (a != 1)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-unroll-1";
}
