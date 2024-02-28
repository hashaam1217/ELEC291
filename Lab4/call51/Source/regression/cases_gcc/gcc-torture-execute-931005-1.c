/*
   931005-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports struct!
#if 0
typedef struct
{
  char x;
} T;

T
f (s1)
     T s1;
{
  T s1a;
  s1a.x = s1.x;
  return s1a;
}
#endif

void
testTortureExecute (void)
{
#if 0
  T s1a, s1b;
  s1a.x = 100;
  s1b = f (s1a);
  if (s1b.x != 100)
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-931005-1";
}
