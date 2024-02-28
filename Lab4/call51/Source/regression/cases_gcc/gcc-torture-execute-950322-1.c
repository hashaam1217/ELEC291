/*
   950322-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

f (unsigned char *a)
{
  int i, j;
  int x, y;

  j = a[1];
  i = a[0] - j;
  if (i < 0)
    {
      x = 1;
      y = -i;
    }
  else
    {
      x = 0;
      y =  i;
    }
  return x + y;
}


void
testTortureExecute (void)
{
  unsigned char a[2];
  a[0] = 8;
  a[1] = 9;
  if (f (a) != 2)
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
  return "cases_gcc\\gcc-torture-execute-950322-1";
}
