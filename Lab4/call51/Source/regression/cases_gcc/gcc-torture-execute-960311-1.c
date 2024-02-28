/*
   960311-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdio.h>

int count;

void a1() { ++count; }

void
b (unsigned char val)
{
  if (val & 0x80) a1();
  val <<= 1;

  if (val & 0x80) a1();
  val <<= 1;

  if (val & 0x80) a1();
}

void
testTortureExecute (void)
{
  count = 0;
  b (0);
  if (count != 0)
    ASSERT (0);

  count = 0;
  b (0x80);
  if (count != 1)
    ASSERT (0);

  count = 0;
  b (0x40);
  if (count != 1)
    ASSERT (0);

  count = 0;
  b (0x20);
  if (count != 1)
    ASSERT (0);

  count = 0;
  b (0xc0);
  if (count != 2)
    ASSERT (0);

  count = 0;
  b (0xa0);
  if (count != 2)
    ASSERT (0);

  count = 0;
  b (0x60);
  if (count != 2)
    ASSERT (0);

  count = 0;
  b (0xe0);
  if (count != 3)
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
  return "cases_gcc\\gcc-torture-execute-960311-1";
}
