/*
   930208-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports union!
#if 0
typedef union {
  long l;
  struct { char b3, b2, b1, b0; } c;
} T;

f (T u)
{
  ++u.c.b0;
  ++u.c.b3;
  return (u.c.b1 != 2 || u.c.b2 != 2);
}
#endif

void
testTortureExecute (void)
{
#if 0
  T u;
  u.c.b1 = 2;
  u.c.b2 = 2;
  u.c.b0 = ~0;
  u.c.b3 = ~0;
  if (f (u))
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-930208-1";
}
