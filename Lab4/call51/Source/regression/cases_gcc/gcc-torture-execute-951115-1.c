/*
   951115-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int var = 0;

void g ()
{
  var = 1;
}

void f ()
{
  int f2 = 0;

  if (f2 == 0)
    ;

  g ();
}

void
testTortureExecute (void)
{
  f ();
  if (var != 1)
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
  return "cases_gcc\\gcc-torture-execute-951115-1";
}
