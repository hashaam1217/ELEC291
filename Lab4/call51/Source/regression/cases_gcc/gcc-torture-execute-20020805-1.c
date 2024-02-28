/*
   20020805-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* This testcase was miscompiled on IA-32, because fold-const
   assumed associate_trees is always done on PLUS_EXPR.  */

void check (unsigned int m)
{
  if (m != (unsigned int) -1)
    ASSERT (0);
}

unsigned int n = 1;

void testTortureExecute (void)
{
  unsigned int m;
  m = (1 | (2 - n)) | (-n);
  check (m);
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
  return "cases_gcc\\gcc-torture-execute-20020805-1";
}
