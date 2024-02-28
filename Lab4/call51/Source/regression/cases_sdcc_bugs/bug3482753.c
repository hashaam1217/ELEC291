/*
   bug3482753.c
*/

#include "../fwk/include/testfwk.h"

struct {char a;} x;
volatile char d = 7;

int f(void)
{
  char t = d;
  
  x.a = t;
  t = x.a + 2;
  d = t;
  t = x.a + 3;  /* bug: x.a was optimized to t, dispite redefinition of t */
  return t;
}

void testBug(void)
{
  ASSERT(f() == 10);
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
  return "cases_sdcc_bugs\\bug3482753";
}
