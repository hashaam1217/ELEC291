/*
   20000731-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

double
foo (void)
{
  return 0.0;
}

void
do_sibcall (void)
{
  (void) foo ();
}

void
testTortureExecute (void)
{
   double x;

   for (x = 0; x < 20; x++)
      do_sibcall ();
   if (!(x >= 10))
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
  return "cases_gcc\\gcc-torture-execute-20000731-1";
}
