/*
   20010409-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

#include <string.h>

typedef struct _A {
  int a, b;
} _A;

typedef struct _B {
  struct _A **a;
  int b;
} _B;

_A *a;
int b = 1, c;
_B d[1];

void foo (_A *x, const char *y, int z)
{
  c = y[4] + z * 25;
}

_A *bar (const char *v, int w, int x, const char *y, int z)
{
  if (w)
    ASSERT (0);
  return 0;
}

void test (const char *x, int *y)
{
  foo (d->a[d->b], "test", 200);
  d->a[d->b] = bar (x, b ? 0 : 65536, strlen (x), "test", 201);
  d->a[d->b]->a++;
  if (y)
    d->a[d->b]->b = *y;
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && defined (__GNUC_MINOR__) && (__GNUC__ < 5))
  d->b = 0;
  d->a = &a;
  test ("", 0);
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
  return "cases_gcc\\gcc-torture-execute-20010409-1";
}
