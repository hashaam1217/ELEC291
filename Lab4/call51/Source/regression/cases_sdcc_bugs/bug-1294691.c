/*
   bug-1294691.c
*/

#include "../fwk/include/testfwk.h"

unsigned char x = 1;
unsigned char y = 5;
int ret;


void
testBug(void)
{
  ret = 1;

  if (x)
  {
    if (y > 3)
    {
      if (y < 8)
      {
      }
    }
    else
    {
    }
  }
  else
  {
    ret = 0;
  }

  ASSERT(ret == 1);
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
  return "cases_sdcc_bugs\\bug-1294691";
}
