/*
   pr21331.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int bar (void) {  return -1;  }

unsigned long
foo ()
{ unsigned long retval;
  retval = bar ();
  if (retval == -1)  return 0;
  return 3;  }

void
testTortureExecute (void)
{
  if (foo () != 0)
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
  return "cases_gcc\\gcc-torture-execute-pr21331";
}
