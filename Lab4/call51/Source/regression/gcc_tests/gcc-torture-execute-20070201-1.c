/*
   20070201-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdio.h>

/* PR middle-end/30473 */

char *
foo (char *buf, char *p)
{
  sprintf (buf, "abcde", p++);
  return p;
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && (__GNUC__ < 5))
  char buf[6];
  if (foo (buf, &buf[2]) != &buf[3])
    ASSERT (0);
  return;
#endif
}
