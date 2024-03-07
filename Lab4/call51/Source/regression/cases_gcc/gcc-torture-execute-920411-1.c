/*
   920411-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

long f (char *w)
{
  long k, i, c = 0, x;
  char *p = (char*) &x;
  for (i = 0; i < 1; i++)
    {
      for (k = 0; k < sizeof (long); k++)
	p[k] = w[k];
      c += x;
    }
  return c;
}

void
testTortureExecute (void)
{
  int i;
  char a[sizeof (long)];

  for (i = sizeof (long); --i >= 0;) a[i] = ' ';
  if (f (a) != ~0UL / (unsigned char) ~0 * ' ')
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
  return "cases_gcc\\gcc-torture-execute-920411-1";
}