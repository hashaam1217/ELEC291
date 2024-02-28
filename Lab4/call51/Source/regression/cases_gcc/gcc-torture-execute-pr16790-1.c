/*
   pr16790-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR middle-end/16790.  */

extern void abort ();

static void test1(unsigned int u1)
{
  unsigned int y_final_1;
  signed short y_middle;
  unsigned int y_final_2;

  y_final_1 = (unsigned int)( (signed short)(u1 * 2) * 3 );
  y_middle  =                 (signed short)(u1 * 2);
  y_final_2 = (unsigned int)( y_middle * 3 );

  if (y_final_1 != y_final_2)
    ASSERT (0);
}


static void test2(unsigned int u1)
{
  unsigned int y_final_1;
  signed short y_middle;
  unsigned int y_final_2;

  y_final_1 = (unsigned int)( (signed short)(u1 << 1) * 3 );
  y_middle  =                 (signed short)(u1 << 1);
  y_final_2 = (unsigned int)( y_middle * 3 );

  if (y_final_1 != y_final_2)
    ASSERT (0);
}


void
testTortureExecute (void)
{
  test1(0x4000U);
  test2(0x4000U);
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
  return "cases_gcc\\gcc-torture-execute-pr16790-1";
}
