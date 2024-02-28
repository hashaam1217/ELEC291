/*
   20030221-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

/* PR optimization/8613 */
/* Contributed by Glen Nakamura */
 
void
testTortureExecute (void)
{
  char buf[16] = "1234567890";
  char *p = buf;

  *p++ = (char) strlen (buf);

  if ((buf[0] != 10) || (p - buf != 1))
    ASSERT (0);

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
  return "cases_gcc\\gcc-torture-execute-20030221-1";
}
