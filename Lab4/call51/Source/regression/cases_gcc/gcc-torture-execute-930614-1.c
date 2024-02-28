/*
   930614-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#pragma disable_warning 85
#endif

void f (double *ty)
{
  *ty = -1.0;
}

void
testTortureExecute (void)
{
  double foo[6];
  double tx = 0.0, ty, d;

  f (&ty);

  if (ty < 0)
    ty = -ty;
  d = (tx > ty) ? tx : ty;
  if (ty != d)
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
  return "cases_gcc\\gcc-torture-execute-930614-1";
}
