/*
   divcmp-3.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int test1(char x)
{
  return x/100 == 3;
}

int test1u(unsigned char x)
{
  return x/100 == 3;
}

int test2(char x)
{
  return x/100 != 3;
}

int test2u(unsigned char x)
{
  return x/100 != 3;
}

int test3(char x)
{
  return x/100 < 3;
}

int test3u(unsigned char x)
{
  return x/100 < 3;
}

int test4(char x)
{
  return x/100 <= 3;
}

int test4u(unsigned char x)
{
  return x/100 <= 3;
}

int test5(char x)
{
  return x/100 > 3;
}

int test5u(unsigned char x)
{
  return x/100 > 3;
}

int test6(char x)
{
  return x/100 >= 3;
}

int test6u(unsigned char x)
{
  return x/100 >= 3;
}

void
testTortureExecute (void)
{
  int c;

  for (c=-128; c<256; c++)
  {
    if (test1(c) != 0)
      ASSERT (0);
    if (test1u(c) != 0)
      ASSERT (0);
    if (test2(c) != 1)
      ASSERT (0);
    if (test2u(c) != 1)
      ASSERT (0);
    if (test3(c) != 1)
      ASSERT (0);
    if (test3u(c) != 1)
      ASSERT (0);
    if (test4(c) != 1)
      ASSERT (0);
    if (test4u(c) != 1)
      ASSERT (0);
    if (test5(c) != 0)
      ASSERT (0);
    if (test5u(c) != 0)
      ASSERT (0);
    if (test6(c) != 0)
      ASSERT (0);
    if (test6u(c) != 0)
      ASSERT (0);
  }
  return;
}


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-divcmp-3";
}
