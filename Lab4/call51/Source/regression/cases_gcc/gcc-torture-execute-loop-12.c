/*
   loop-12.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif


/* Checks that pure functions are not treated as const.  */

const char *p;

static int
is_end_of_statement (void)
{
  return *p == '\n' || *p == ';' || *p == '!';
}

void foo (void)
{
  /* The is_end_of_statement call was moved out of the loop at one stage,
     resulting in an endless loop.  */
  while (!is_end_of_statement ())
    p++;
}

void
testTortureExecute (void)
{
  p = "abc\n";
  foo ();
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
  return "cases_gcc\\gcc-torture-execute-loop-12";
}
