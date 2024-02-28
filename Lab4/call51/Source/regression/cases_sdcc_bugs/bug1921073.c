/*
    bug 1921073
*/

#include "../fwk/include/testfwk.h"

void
f1 (char c, const void * p)
{
  unsigned long v = (unsigned long)p;
  c;
  v;
#if defined(__C51_mcs51)
  ASSERT ((unsigned char)(v >> 16) == 0x80);
#endif
}

void
f2 (const void * p)
{
  unsigned long v = (unsigned long)p;
  v;
#if defined(__C51_mcs51)
  ASSERT ((unsigned char)(v>>16)==0x80);
#endif
}

void
testBug (void)
{
  f1(5, (__code void *)0x1234);
  f2((__code void *)0x1234);
}


void
__runSuite(void)
{
  __prints("Running testBug\n");
  testBug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1921073";
}
