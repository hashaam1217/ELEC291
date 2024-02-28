/*
   switch-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright (C) 2003  Free Software Foundation.

   Test that switch statements suitable using case bit tests are
   implemented correctly.

   Written by Roger Sayle, 01/25/2001.  */

int
foo (int x)
{
  switch (x)
    {
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    }
  return 31;
}

void
testTortureExecute (void)
{
  int i, r;

  for (i=-1; i<66; i++)
    {
      r = foo (i);
      if (i == 4)
        {
          if (r != 30)
            ASSERT (0);
        }
      else if (i == 6)
        {
          if (r != 30)
            ASSERT (0);
        }
      else if (i == 9)
        {
          if (r != 30)
            ASSERT (0);
        }
      else if (i == 11)
        {
          if (r != 30)
            ASSERT (0);
        }
      else if (r != 31)
        ASSERT (0);
    }
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
  return "cases_gcc\\gcc-torture-execute-switch-1";
}
