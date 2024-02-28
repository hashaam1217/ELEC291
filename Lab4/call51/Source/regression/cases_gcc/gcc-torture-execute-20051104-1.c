/*
   20051104-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 196
#endif

/* PR rtl-optimization/23567 */

struct
{
  int len;
  char *name;
} s;

void
testTortureExecute (void)
{
  s.len = 0;
  s.name = "";
  if (s.name [s.len] != 0)
    s.name [s.len] = 0;
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
  return "cases_gcc\\gcc-torture-execute-20051104-1";
}
