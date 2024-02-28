/*
   bug-136564.c0

   loop induction
*/

#include "../fwk/include/testfwk.h"


void
testBackPatchLabel(void)
{
  volatile unsigned char c0 = 0, c1 = 1;
  unsigned char r;

  if (     (c0 == 0)) r = 1; else r = 0; ASSERT(r == 1);
  if (    !(c0 == 0)) r = 1; else r = 0; ASSERT(r == 0);
  if (   !!(c0 == 0)) r = 1; else r = 0; ASSERT(r == 1);
  if (  !!!(c0 == 0)) r = 1; else r = 0; ASSERT(r == 0);
  if ( !!!!(c0 == 0)) r = 1; else r = 0; ASSERT(r == 1);
  if (!!!!!(c0 == 0)) r = 1; else r = 0; ASSERT(r == 0);

  if (     ((c0 == 0) && (c1 == 1))) r = 1; else r = 0; ASSERT(r == 1);
  if (    !((c0 == 0) && (c1 == 1))) r = 1; else r = 0; ASSERT(r == 0);
  if (   !!((c0 == 0) && (c1 == 1))) r = 1; else r = 0; ASSERT(r == 1);

  if (     (  (c0 == 0) &&   (c1 == 1))) r = 1; else r = 0; ASSERT(r == 1);
  if (    !( !(c0 == 1) &&  !(c1 == 0))) r = 1; else r = 0; ASSERT(r == 0);
  if (   !!(!!(c0 == 0) && !!(c1 == 1))) r = 1; else r = 0; ASSERT(r == 1);
}

void
__runSuite(void)
{
  __prints("Running testBackPatchLabel\n");
  testBackPatchLabel();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1408066";
}
