/*
   981130-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports struct!
#if 0
struct s { int a; int b;};
struct s s1;
struct s s2 = { 1, 2, };

void
check (int a, int b)
{
  if (a == b)
    return;
  else
    ASSERT (0);
}
#endif

void
testTortureExecute (void)
{
#if 0
  int * p;
  int x;
  
  s1.a = 9;
  p    = & s1.a;
  s1   = s2;
  x    = * p;
  
  check (x, 1);
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
  return "cases_gcc\\gcc-torture-execute-981130-1";
}
