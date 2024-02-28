/*
   bug3183823.c
*/

#include "../fwk/include/testfwk.h"

float neg (float x)
{
	return -x;
}

void testNeg (void)
{
	float x, y;
	char a, b;

	x = neg(0.0);
	y = neg(-0.0);
	ASSERT (x==0.0);
	ASSERT (y==0.0);
	ASSERT (x==-0.0);
	ASSERT (y==-0.0);
	ASSERT (x==y);
	ASSERT (x>=y);
	ASSERT (x<=y);
	ASSERT (y>=x);
	ASSERT (y<=x);

	a = ((char*)&x)[0];
	b = ((char*)&x)[3];
	((char*)&x)[0] = b;
	((char*)&x)[3] = a;
	ASSERT (x!=0.0);
}

void
__runSuite(void)
{
  __prints("Running testNeg\n");
  testNeg();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug3183823";
}
