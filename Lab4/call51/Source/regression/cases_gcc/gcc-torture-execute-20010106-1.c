/*
   20010106-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright 2001 Free Software Foundation
   Contributed by Alexandre Oliva <aoliva@redhat.com> */

int f(int i) {
  switch (i)
  {
    case -2:
      return 33;
    case -1:
      return 0;
    case 0:
      return 7;
    case 1:
      return 4;
    case 2:
      return 3;
    case 3:
      return 15;
    case 4:
     return 9;
    default:
      ASSERT(0);
  }
}

void
testTortureExecute (void) {
  if (f(-1))
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
  return "cases_gcc\\gcc-torture-execute-20010106-1";
}
