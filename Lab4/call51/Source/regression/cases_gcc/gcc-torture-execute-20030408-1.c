/*
   20030408-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

/* PR optimization/8634 */
/* Contributed by Glen Nakamura <glen at imodulo dot com> */

struct foo {
  char a, b, c, d, e, f, g, h, i, j;
};

int test1 ()
{
  const char X[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
  char buffer[8];
  memcpy (buffer, X, 8);
  if (buffer[0] != 'A' || buffer[1] != 'B'
      || buffer[2] != 'C' || buffer[3] != 'D'
      || buffer[4] != 'E' || buffer[5] != 'F'
      || buffer[6] != 'G' || buffer[7] != 'H')
    ASSERT (0);
  return 0;
}

int test2 ()
{
  const char X[10] = { 'A', 'B', 'C', 'D', 'E' };
  char buffer[10];
  memcpy (buffer, X, 10);
  if (buffer[0] != 'A' || buffer[1] != 'B'
      || buffer[2] != 'C' || buffer[3] != 'D'
      || buffer[4] != 'E' || buffer[5] != '\0'
      || buffer[6] != '\0' || buffer[7] != '\0'
      || buffer[8] != '\0' || buffer[9] != '\0')
    ASSERT (0);
  return 0;
}

int test4 ()
{
/*Not suuported in C51
  const struct foo X = { .b = 'B', .d = 'D', .f = 'F', .h = 'H' , .j = 'J' };
  char buffer[10];
  memcpy (buffer, &X, 10);
  if (buffer[0] != '\0' || buffer[1] != 'B'
      || buffer[2] != '\0' || buffer[3] != 'D'
      || buffer[4] != '\0' || buffer[5] != 'F'
      || buffer[6] != '\0' || buffer[7] != 'H'
      || buffer[8] != '\0' || buffer[9] != 'J')
    ASSERT (0);
  return 0;
*/
}

void
testTortureExecute (void)
{
  test1 (); test2 (); test4 ();
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
  return "cases_gcc\\gcc-torture-execute-20030408-1";
}
