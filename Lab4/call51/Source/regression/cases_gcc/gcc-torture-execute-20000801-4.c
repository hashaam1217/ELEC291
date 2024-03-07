/*
   20000801-4.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Origin: PR c/128 from Martin Sebor <sebor@roguewave.com>, adapted
   as a testcase by Joseph Myers <jsm28@cam.ac.uk>.
*/
/* Character arrays initialized by a string literal must have
   uninitialized elements zeroed.  This isn't clear in the 1990
   standard, but was fixed in TC2 and C99; see DRs #060, #092.
*/

int
foo (void)
{
  char s[2] = "";
  return 0 == s[1];
}

char *t;

void
testTortureExecute (void)
{
#if 0
  {
    char s[] = "x";
    t = s;
  }
  if (foo ())
    return;
  else
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20000801-4";
}