/*
   20050502-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

/* PR target/21297 */

void
foo (char *x)
{
  int i;
  for (i = 0; i < 2; i++);
  x[i + i] = '\0';
}

void
bar (char *x)
{
  int i;
  for (i = 0; i < 2; i++);
  x[i + i + i + i] = '\0';
}

void
testTortureExecute (void)
{
  char x[] = "IJKLMNOPQR";
  foo (x);
  if (memcmp (x, "IJKL\0NOPQR", sizeof x) != 0)
    ASSERT (0);
  x[4] = 'M';
  bar (x);
  if (memcmp (x, "IJKLMNOP\0R", sizeof x) != 0)
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
  return "cases_gcc\\gcc-torture-execute-20050502-2";
}
