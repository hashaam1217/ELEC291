/*
   pr15262.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int j;

void bla (int *r)
{
  int *p, *q;

  p = q = r;
  if (!p)
    p = &j;
  
  if (p != q)
    j = 1;
}

void
testTortureExecute (void)
{
  bla (0);
  if (!j)
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
  return "cases_gcc\\gcc-torture-execute-pr22630";
}
