/*
   980506-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct decision
{
  char enforce_mode;             
  struct decision *next;         
};


static void
clear_modes (register struct decision *p)
{
  goto blah;

foo:
  p->enforce_mode = 0;
blah:
  if (p)
    goto foo;
}

void
testTortureExecute (void)
{
  struct decision *p = 0;
  clear_modes (p);
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
  return "cases_gcc\\gcc-torture-execute-980506-1";
}
