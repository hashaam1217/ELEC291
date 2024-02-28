/*
   20000715-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void
test1(void)
{
  int x = 3, y = 2;

  if ((x < y ? x++ : y++) != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

void
test2(void)
{
  int x = 3, y = 2, z;

  z = (x < y) ? x++ : y++;
  if (z != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

void
test3(void)
{
  int x = 3, y = 2;
  int xx = 3, yy = 2;

  if ((xx < yy ? x++ : y++) != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

int x, y;

static void
init_xy(void)
{
  x = 3;
  y = 2;
}

void
test4(void)
{
  init_xy();
  if ((x < y ? x++ : y++) != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

void
test5(void)
{
  int z;

  init_xy();
  z = (x < y) ? x++ : y++;
  if (z != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

void
test6(void)
{
  int xx = 3, yy = 2;
  int z;

  init_xy();
  z = (xx < y) ? x++ : y++;
  if (z != 2)
    ASSERT (0);

  if (x != 3)
    ASSERT (0);

  if (y != 3)
    ASSERT (0);
}

void
testTortureExecute (void){
  test1 ();
  test2 ();
  test3 ();
  test4 ();
  test5 ();
  test6 ();
  return;
}


void
__runSuite(void)
{
  __prints("Running test1\n");
  test1();
  __prints("Running test2\n");
  test2();
  __prints("Running test3\n");
  test3();
  __prints("Running test4\n");
  test4();
  __prints("Running test5\n");
  test5();
  __prints("Running test6\n");
  test6();
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 7;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20000715-1";
}
