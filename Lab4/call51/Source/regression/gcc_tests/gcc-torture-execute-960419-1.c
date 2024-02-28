/*
   960419-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static int i;

void
check(int x)
{
  if (!x)
    ASSERT(0);
}

void
testTortureExecute (void)
{
  int *p = &i;

  check(p != (void *)0);
  return;
}

