/*
   20020810-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#if 0 // TODO: enable when support for struct is complete!
/* PR target/7559
   This testcase was miscompiled on x86-64, because classify_argument
   wrongly computed the offset of nested structure fields.  */

struct A
{
  long x;
};

struct R
{
  struct A a, b;
};

struct R R = { 100, 200 };

void f (struct R r)
{
  if (r.a.x != R.a.x || r.b.x != R.b.x)
    ASSERT (0);
}

struct R g (void)
{
  return R;
}
#endif

void testTortureExecute (void)
{
#if 0
  struct R r;
  f(R);
  r = g();
  if (r.a.x != R.a.x || r.b.x != R.b.x)
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
  return "cases_gcc\\gcc-torture-execute-20020810-1";
}
