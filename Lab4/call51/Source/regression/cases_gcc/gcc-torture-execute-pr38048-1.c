/*
   pr38048-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int foo ()
{
  int mat[2][1];
  int (*a)[1] = mat;
  int det = 0;
  int i;
  mat[0][0] = 1;
  mat[1][0] = 2;
  for (i = 0; i < 2; ++i)
    det += a[i][0];
  return det;
}

void
testTortureExecute (void)
{
  if (foo () != 3)
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
  return "cases_gcc\\gcc-torture-execute-pr38048-1";
}
