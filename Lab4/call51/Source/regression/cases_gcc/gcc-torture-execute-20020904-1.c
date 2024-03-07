/*
   20020904-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR c/7102 */

/* Verify that GCC zero-extends integer constants
   in unsigned binary operations. */

typedef unsigned char u8;

u8 fun(u8 y)
{
  u8 x=((u8)255)/y;
  return x;
}

void testTortureExecute(void)
{
  if (fun((u8)2) != 127)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-20020904-1";
}