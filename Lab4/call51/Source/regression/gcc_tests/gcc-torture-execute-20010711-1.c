/*
   20010711-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

void foo (int *a) {}

void
testTortureExecute (void)
{
  int a;
  if (&a == 0)
    ASSERT (0);
  else
    {
      foo (&a);
      return;
    }
}

