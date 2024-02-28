/*
   func-ptr-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93 // Using float for double.
#endif

static double f (float a);
static double (*fp) (float a);

void
testTortureExecute (void)
{
#if !defined(__C51_hc08) && !defined(__C51_s08)
  fp = f;
  if (fp ((float) 1) != 1.0)
    ASSERT (0);
  return;
#endif
}

static double
f (float a)
{
  return a;
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
  return "cases_gcc\\gcc-torture-execute-func-ptr-1";
}
