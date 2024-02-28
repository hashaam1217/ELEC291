/*
   20050826-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

#ifndef __C51_mcs51
/* PR rtl-optimization/23561 */

struct A
{
  char a1[1];
  char a2[5];
  char a3[1];
  char a4[2048 - 7];
} a;

void
bar (struct A *x)
{
  size_t i;
  if (memcmp (x, "\1HELLO\1", sizeof "\1HELLO\1"))
    ASSERT (0);
  for (i = 0; i < sizeof (x->a4); i++)
    if (x->a4[i])
      ASSERT (0);
}

int
foo (void)
{
  memset (&a, 0, sizeof (a));
  a.a1[0] = 1;
  memcpy (a.a2, "HELLO", sizeof "HELLO");
  a.a3[0] = 1;
  bar (&a);
  return 0;
}
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  foo ();
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
  return "cases_gcc\\gcc-torture-execute-20050826-1";
}
