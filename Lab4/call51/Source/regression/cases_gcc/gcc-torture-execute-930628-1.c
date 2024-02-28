/*
   930628-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 93
#endif

void f (double x[2], double y[2])
{
  if (x == y)
    ASSERT (0);
}

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  struct { int f[3]; double x[1][2]; } tp[4][2];
  int i, j, ki, kj, mi, mj;
  float bdm[4][2][4][2];

  for (i = 0; i < 4; i++)
    for (j = i; j < 4; j++)
      for (ki = 0; ki < 2; ki++)
	for (kj = 0; kj < 2; kj++)
	  if ((j == i) && (ki == kj))
	    bdm[i][ki][j][kj] = 1000.0;
	  else
	    {
	      for (mi = 0; mi < 1; mi++)
		for (mj = 0; mj < 1; mj++)
		  f (tp[i][ki].x[mi], tp[j][kj].x[mj]);
	      bdm[i][ki][j][kj] = 1000.0;
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
  return "cases_gcc\\gcc-torture-execute-930628-1";
}
