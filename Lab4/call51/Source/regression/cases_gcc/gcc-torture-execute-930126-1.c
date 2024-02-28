/*
   930126-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo: Enable when C51 supports bitfields alrger than int
#if 0
struct s {
  unsigned long long a:8, b:32;
};

struct s
f(struct s x)
{
  x.b = 0xcdef1234;
  return x;
}
#endif

void
testTortureExecute (void)
{
#if 0
  static struct s i;
  i.a = 12;
  i = f(i);
  if (i.a != 12 || i.b != 0xcdef1234)
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
  return "cases_gcc\\gcc-torture-execute-930126-1";
}
