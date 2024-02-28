/*
   930614-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  int i, j, k, l;
  float x[8][2][8][2];

  for (i = 0; i < 8; i++)
    for (j = i; j < 8; j++)
      for (k = 0; k < 2; k++)
	for (l = 0; l < 2; l++)
	  {
	    if ((i == j) && (k == l))
	      x[i][k][j][l] = 0.8;
	    else
	      x[i][k][j][l] = 0.8;
	    if (x[i][k][j][l] < 0.0)
	      ASSERT (0);
	  }

  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-930614-2";
}
