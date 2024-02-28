/*
   20010925-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

int foo (void *, void *, unsigned int c);

int src[10];
int dst[10];

void
testTortureExecute (void)
{
   if (foo (dst, src, 10) != 0)
     ASSERT (0);
   return;
}

int foo (void *a, void *b, unsigned int c)
{
  if (c == 0)
    return 1;

  memcpy (a, b, c);
  return 0;
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
  return "cases_gcc\\gcc-torture-execute-20010925-1";
}
