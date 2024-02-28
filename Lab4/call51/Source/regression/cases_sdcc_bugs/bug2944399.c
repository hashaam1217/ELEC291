/*
   bug2944399.c
 */

#include "../fwk/include/testfwk.h"

unsigned short Addr1(void)
{
  return (0x1234);
 }

unsigned short func16(unsigned short Dummy)
{
  return Dummy;
}

void testBug1(void)
{
  unsigned short a;

  a = 0x0101 | Addr1();
  ASSERT (func16(a) == (0x0101 | 0x1234));
}

void testBug2(void)
{
  unsigned short a;

  a = 0x0101 & Addr1();
  ASSERT (func16(a) == (0x0101 & 0x1234));
}

void testBug3(void)
{
  unsigned short a;

  a = 0x0101 ^ Addr1();
  ASSERT (func16(a) == (0x0101 ^ 0x1234));
}

void testBug4(void)
{
  unsigned short a;

  a = Addr1();
  a |= 0x0101;
  ASSERT (func16(a) == (0x0101 | 0x1234));
}

void
__runSuite(void)
{
  __prints("Running testBug1\n");
  testBug1();
  __prints("Running testBug2\n");
  testBug2();
  __prints("Running testBug3\n");
  testBug3();
  __prints("Running testBug4\n");
  testBug4();
}

const int __numCases = 4;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug2944399";
}
