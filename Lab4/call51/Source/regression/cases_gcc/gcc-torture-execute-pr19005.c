/*
   pr19005.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR target/19005 */

int v, s;

void
bar (int a, int b)
{
  unsigned char x = v;

  if (!s)
    {
      if (a != x || b != (unsigned char) (x + 1))
        ASSERT (0);
    }
  else if (a != (unsigned char) (x + 1) || b != x)
    ASSERT (0);
  s ^= 1;
}

int
foo (int x)
{
  unsigned char a = x, b = x + 1;

  bar (a, b);
  a ^= b; b ^= a; a ^= b;
  bar (a, b);
  return 0;
}

void
testTortureExecute (void)
{
  for (v = -10; v < 266; v++)
    foo (v);
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
  return "cases_gcc\\gcc-torture-execute-pr19005";
}
