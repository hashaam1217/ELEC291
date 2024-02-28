/*
   960419-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#define SIZE 8

void
testTortureExecute (void)
{
  int a[SIZE] = {1};
  int i;

  for (i = 1; i < SIZE; i++)
    if (a[i] != 0)
      ASSERT(0);

  return;
}

