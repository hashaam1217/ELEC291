/*
   20010403-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

void b (int *);
void c (int, int);
void d (int);

int e;

void a (int x, int y)
{
  int f = x ? e : 0;
  int z = y;

  b (&y);
  c (z, y);
  d (f);
}

void b (int *y)
{
  (*y)++;
}

void c (int x, int y)
{
  if (x == y)
    ASSERT (0);
}

void d (int x)
{
}

void
testTortureExecute (void)
{
  a (0, 0);
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
  return "cases_gcc\\gcc-torture-execute-20010403-1";
}
