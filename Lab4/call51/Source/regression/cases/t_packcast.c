/* Tests that a cast used as a parameter gets packed into
   HL
*/
#include "../fwk/include/testfwk.h"

void
spoil(int a)
{
  UNUSED(a);
}

void
testCastPack(char x)
{
  int i, j;
  volatile char a = x;

  for (i = 0; i < 5; i++)
    {
      for (j = 0; j < 5; j++)
        {
          spoil(a);
        }
    }
}

void testBug(void)
{
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
  return "cases\\t_packcast";
}
