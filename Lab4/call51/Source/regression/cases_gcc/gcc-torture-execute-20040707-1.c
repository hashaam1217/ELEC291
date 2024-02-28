/*
   20040707-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0 // TODO: enable when struct can be passed!
struct s { char c1, c2; };
void foo (struct s s)
{
  static struct s s1;
  s1 = s;
}
#endif

void
testTortureExecute (void)
{
#if 0
  static struct s s2;
  foo (s2);
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
  return "cases_gcc\\gcc-torture-execute-20040707-1";
}
