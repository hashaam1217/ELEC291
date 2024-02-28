/*
   pr43236.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

void
testTortureExecute (void)
{
  char A[30], B[30], C[30];
  int i;

  /* prepare arrays */
  memset(A, 1, 30);
  memset(B, 1, 30);

  for (i = 20; i-- > 10;) {
    A[i] = 0;
    B[i] = 0;
  }

  /* expected result */
  memset(C, 1, 30);
  memset(C + 10, 0, 10);

  /* show result */
/*  for (i = 0; i < 30; i++)
    printf("%d %d %d\n", A[i], B[i], C[i]); */

  /* compare results */
  if (memcmp(A, C, 30) || memcmp(B, C, 30)) ASSERT(0);

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
  return "cases_gcc\\gcc-torture-execute-pr43236";
}
