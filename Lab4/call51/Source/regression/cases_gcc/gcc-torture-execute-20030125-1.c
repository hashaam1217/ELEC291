/*
   20030125-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports double!
#if 0
/* Verify whether math functions are simplified.  */
#include <math.h>

float 
t(float a)
{
	return sin(a);
}
float 
q(float a)
{
	return floor(a);
}
double
q1(float a)
{
	return floor(a);
}
#endif

void
testTortureExecute (void)
{
#if 0
	if (t(0)!=0)
		ASSERT (0);
	if (q(0)!=0)
		ASSERT (0);
	if (q1(0)!=0)
		ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20030125-1";
}
