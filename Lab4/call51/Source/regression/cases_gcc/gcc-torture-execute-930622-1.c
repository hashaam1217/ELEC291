/*
   930622-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

int a = 1, b;

int g () { return 0; }
void h (int x) {}

int f ()
{
  if (g () == -1)
    return 0;
  a = g ();
  if (b >= 1)
    h (a);
  return 0;
}

void
testTortureExecute (void)
{
  f ();
  if (a != 0)
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
  return "cases_gcc\\gcc-torture-execute-930622-1";
}
