/*
   20000412-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0
short int i = -1;
const char * const wordlist[207];

const char * const *
foo(void)
{
  register const char * const *wordptr = &wordlist[207u + i];
  return wordptr;
}
#endif

void
testTortureExecute (void)
{
#if 0
  if (foo() != &wordlist[206])
    ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20000412-1";
}
