/*
   930603-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

float fx (float x)
{
  return 1.0 + 3.0 / (2.302585093 * x);
}

float inita ();
float initc ();
void f ();

void
testTortureExecute (void)
{
  float a, b, c;
  a = inita ();
  c = initc ();
  f ();
  b = fx (c) + a;
  f ();
  if (a != 3.0 || b < 4.3257 || b > 4.3258 || c != 4.0)
    ASSERT (0);
  return;
}

float inita () { return 3.0; }
float initc () { return 4.0; }
void f () {}


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
  return "cases_gcc\\gcc-torture-execute-930603-1";
}
