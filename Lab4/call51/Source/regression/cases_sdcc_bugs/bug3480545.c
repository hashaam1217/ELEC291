/*
   bug3480545.c
*/

#include "../fwk/include/testfwk.h"

unsigned char var = 1;

char do_switch(void)
{
    switch( var )
    {
        case 0  : return 0;
        case 1  : return 1;
        case 2  : return 2;
        case 3  : return 3;
        case 4  : return 3;
        case 5  : return 3;
        case 6  : return 3;
        case 7  : return 3;
        case 8  : return 0;
        case 9  : return 1;
        case 10 : return 2;
        case 11 : return 3;
        case 12 : return 3;
        case 13 : return 3;
        case 14 : return 3;
        case 15 : return 3;
        case 16 : return 3;
        case 17 : return 3;
    }

    return 0;
}

void
testBug (void)
{
  ASSERT (do_switch() == 1);
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
  return "cases_sdcc_bugs\\bug3480545";
}
