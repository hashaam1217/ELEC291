/*
   20081103-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

// TODO: Enable when C51 can pass structures as paramters.

struct S { char c; char arr[4]; float f; };

char A[4] = { '1', '2', '3', '4' };
#if 0
void foo (struct S s)
{
  if (memcmp (s.arr, A, 4))
    ASSERT (0);
}
#endif

void
testTortureExecute (void)
{
#if 0
  struct S s;
  memcpy (s.arr, A, 4);
  foo (s);
  return;
#endif
}

