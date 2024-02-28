/*
   loop-4c.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>

#ifndef __C51_mcs51
void * a[255];

void f (int m)
{
  int i;
  int sh = 0x100;
  i = m;
  do
    {
      a[sh >>= 1] = ((unsigned)i << 3)  + (char*)a;
      i += 4;
    }
  while (i < INT_MAX/2 + 1 + 4 * 4);
}
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  a[0x10] = 0;
  a[0x08] = 0;
  f (INT_MAX/2 + INT_MAX/4 + 2);
  if (a[0x10] || a[0x08])
    ASSERT (0);
  a[0x10] = 0;
  a[0x08] = 0;
  f (INT_MAX/2 + 1);
  if (! a[0x10] || a[0x08])
    ASSERT (0);
#endif
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
  return "cases_gcc\\gcc-torture-execute-loop-3c";
}
