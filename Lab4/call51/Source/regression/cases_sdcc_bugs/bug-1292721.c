/*
        bugs 1292721.
*/

#include "../fwk/include/testfwk.h"

char bar(void)
{
  static char ret = 0;
  if(!ret) {
    ret = 1;
    return(0);
  }
  return(1);
}

void
testBug156270(void)
{
  char aa, bb;

  aa = bar();

  for (;;) {

    bb = bar();

    if (!bb)
      break;
    
    if (aa == 0)
      return;

    ASSERT(0);
  }
  ASSERT(0);
}


void
__runSuite(void)
{
  __prints("Running testBug156270\n");
  testBug156270();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1292721";
}
