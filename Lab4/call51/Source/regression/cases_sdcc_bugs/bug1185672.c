/*
   bug1057979.c
*/

#include "../fwk/include/testfwk.h"

int srlen;

int l_regrd(int ad)
{
  return ad;
}

void head_send(int i)
{
  srlen= i;
  if ((l_regrd(0x1234) & 0x0200) == 0)
  {
    srlen= 0;
  }
}

void
test_1185672(void)
{
  head_send(1);
  ASSERT( srlen == 1 );
}

void
__runSuite(void)
{
  __prints("Running test_1185672\n");
  test_1185672();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1185672";
}
