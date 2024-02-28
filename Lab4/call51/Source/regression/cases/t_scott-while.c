/*
 */
#include "../fwk/include/testfwk.h"

unsigned int aint0 = 0;
unsigned int aint1 = 0;
unsigned char achar0 = 0;
unsigned char achar1 = 0;

void
while1 (void)
{
  unsigned char i = 10;

  do
    {
      achar0++;
    }
  while (--i);

  ASSERT (!(achar0 != 10));

}


void
testWhile (void)
{
  while1 ();
}

void
__runSuite(void)
{
  __prints("Running testWhile\n");
  testWhile();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_scott-while";
}
