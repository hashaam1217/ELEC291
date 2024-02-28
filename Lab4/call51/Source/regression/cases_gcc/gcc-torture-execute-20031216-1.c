/*
   20031216-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR optimization/13313 */
/* Origin: Mike Lerwill <mike@ml-solutions.co.uk> */

void DisplayNumber (unsigned long v)
{
  if (v != 0x9aL)
    ASSERT (0);
}

unsigned long ReadNumber (void)
{
  return 0x009a0000L;
}

void
testTortureExecute (void)
{
  unsigned long tmp;
  tmp = (ReadNumber() & 0x00ff0000L) >> 16;
  DisplayNumber (tmp);
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
  return "cases_gcc\\gcc-torture-execute-20031216-1";
}
