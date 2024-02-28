/* bug-971834.c

   Life Range problem with
   - uninitialized variable
   - loop

   LR problem hits all ports, but this test is mcs51 specific
 */

#include "../fwk/include/testfwk.h"

unsigned char ttt[] = {0xff, 1};
unsigned char b;

#if !defined(PORT_HOST)
#  pragma disable_warning 84
#endif

unsigned char orsh (void)
{
  unsigned char a, i;
  for (i = 0; i < sizeof(ttt); i++)
    a |= ttt[i];
  return a;
}

unsigned char orsh1 (void)
{
  unsigned char i, j;
  unsigned char a;
  for (j = 0; j < sizeof(ttt); j++)
    {
      for (i = 0; i < sizeof(ttt); i++)
        {
          a |= ttt[i];
          b = a;
        }
    }
  return b;
}

void
testLR(void)
{
  ASSERT(orsh()  == 0xff);
  ASSERT(orsh1() == 0xff);
}

void
__runSuite(void)
{
  __prints("Running testLR\n");
  testLR();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-971834";
}
