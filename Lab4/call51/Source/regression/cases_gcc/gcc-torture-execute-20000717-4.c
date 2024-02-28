/*
   20000717-4.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Extracted from gas.  Incorrectly generated non-pic code at -O0 for
   IA-64, which produces linker errors on some operating systems.  */

struct
{
  int offset;
  struct slot
  {
    int field[6];
  }
  slot[4];
} s;

int
x ()
{
  int toggle = 0;
  int r = s.slot[0].field[!toggle];
  return r;
}

void
testTortureExecute (void)
{
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
  return "cases_gcc\\gcc-torture-execute-20000717-4";
}
