/*
   20000511-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void f (int value, int expect)
{
  if (value != expect)
    ASSERT (0);
}

void
testTortureExecute (void)
{
  int a = 7, b = 6, c = 4, d = 7, e = 2;
	
  f (a||b%c,   1);
  f (a?b%c:0,  2);
  f (a=b%c,    2);
  f (a*=b%c,   4);
  f (a/=b%c,   2);
  f (a%=b%c,   0);
  f (a+=b%c,   2);
  f (d||c&&e,  1);
  f (d?c&&e:0, 1);
  f (d=c&&e,   1);
  f (d*=c&&e,  1);
  f (d%=c&&e,  0);
  f (d+=c&&e,  1);
  f (d-=c&&e,  0);
  f (d||c||e,  1);
  f (d?c||e:0, 0);
  f (d=c||e,   1);
  f (d*=c||e,  1);
  f (d%=c||e,  0);
  f (d+=c||e,  1);
  f (d-=c||e,  0);
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
  return "cases_gcc\\gcc-torture-execute-20000511-1";
}