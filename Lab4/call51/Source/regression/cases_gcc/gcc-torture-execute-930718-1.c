/*
   930718-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

typedef struct rtx_def
{
  int f1 :1;
  int f2 :1;
} *rtx;

static rtx
f (register rtx orig)
{
  if (orig->f1 || orig->f2)
    return orig;
  orig->f2 = 1;
  return orig;
}

void
f2 ()
{
  ASSERT (0);
}

void
testTortureExecute (void)
{
  struct rtx_def foo;
  rtx bar;

  foo.f1 = 1;
  foo.f2 = 0;
  bar = f (&foo);
  if (bar != &foo || bar->f2 != 0)
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
  return "cases_gcc\\gcc-torture-execute-930718-1";
}
