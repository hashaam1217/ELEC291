/*
    bug 2077267
*/

#include "../fwk/include/testfwk.h"

#ifndef __C51
#define __critical
#endif

void bug(char* x)
{
    *x = *x + 1;
}

void
testBug(void)
{
    char x = 1;

    bug(&x);

    __critical {
        bug(&x);
    }

    ASSERT (x == 3);
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
  return "cases_sdcc_bugs\\bug2077267";
}
