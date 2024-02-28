/*
   20000403-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

extern unsigned long aa[], bb[];

int seqgt (unsigned long a, unsigned short win, unsigned long b);

int seqgt2 (unsigned long a, unsigned short win, unsigned long b);

void
testTortureExecute (void)
{
  if (! seqgt (*aa, 0x1000, *bb) || ! seqgt2 (*aa, 0x1000, *bb))
    ASSERT (0);

  return;
}

int
seqgt (unsigned long a, unsigned short win, unsigned long b)
{
  return (long) ((a + win) - b) > 0;
}

int
seqgt2 (unsigned long a, unsigned short win, unsigned long b)
{
  long l = ((a + win) - b);
  return l > 0;
}

unsigned long aa[] = { (1UL << (sizeof (long) * 8 - 1)) - 0xfff };
unsigned long bb[] = { (1UL << (sizeof (long) * 8 - 1)) - 0xfff };


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
  return "cases_gcc\\gcc-torture-execute-20000403-1";
}
