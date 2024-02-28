/*
   20000412-3.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when struct passing is supported.
#if 0
typedef struct {
  char y;
  char x[32];
} X;

int f(X x, X y);

int z (void)
{
  X xxx;
  xxx.x[0] =
  xxx.x[31] = '0';
  xxx.y = 0xf;
  return f (xxx, xxx);
}
#endif

void
testTortureExecute (void)
{
#if 0
  int val;

  val = z ();
  if (val != 0x60)
    ASSERT (0);
  return;
#endif
}

#if 0
int f(X x, X y)
{
  if (x.y != y.y)
    return 'F';

  return x.x[0] + y.x[0];
}
#endif


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
  return "cases_gcc\\gcc-torture-execute-20000412-3";
}
