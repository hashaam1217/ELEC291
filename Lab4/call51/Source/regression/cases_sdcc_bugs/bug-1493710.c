/*
   bug-1493710.c

   cse
   findPointerSet with signed/unsigned operands
*/

#include "../fwk/include/testfwk.h"

struct
  {
    unsigned char a;
  } st = { 0xff };

signed char c = -1;

unsigned char f (void)
{
  st.a += c;
  return st.a > 8;
}

void
testFindPointerSet(void)
{
  ASSERT(f() == 1);
}

void
__runSuite(void)
{
  __prints("Running testFindPointerSet\n");
  testFindPointerSet();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1493710";
}
