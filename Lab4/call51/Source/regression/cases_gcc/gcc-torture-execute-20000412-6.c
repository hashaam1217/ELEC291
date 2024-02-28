/*
   20000412-6.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

unsigned bug (unsigned short value, unsigned short *buffer,
              unsigned short *bufend);

unsigned short buf[] = {1, 4, 16, 64, 256};

void
testTortureExecute (void)
{
  if (bug (512, buf, buf + 3) != 491)
    ASSERT (0);

  return;
}

unsigned
bug (unsigned short value, unsigned short *buffer, unsigned short *bufend)
{
  unsigned short *tmp;

  for (tmp = buffer; tmp < bufend; tmp++)
    value -= *tmp;

  return value;
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
  return "cases_gcc\\gcc-torture-execute-20000412-6";
}
