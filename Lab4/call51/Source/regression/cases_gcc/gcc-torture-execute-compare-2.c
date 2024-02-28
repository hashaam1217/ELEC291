/*
   compare-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright (C) 2002 Free Software Foundation.

   Ensure that the composite comparison optimization doesn't misfire
   and attempt to combine a signed comparison with an unsigned one.

   Written by Roger Sayle, 3rd June 2002.  */

extern void abort (void);

int
foo (int x, int y)
{
  /* If miscompiled the following may become "x == y".  */
  return (x<=y) && ((unsigned int)x >= (unsigned int)y);
}

void
testTortureExecute (void)
{
  if (! foo (-1,0))
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
  return "cases_gcc\\gcc-torture-execute-compare-2";
}
