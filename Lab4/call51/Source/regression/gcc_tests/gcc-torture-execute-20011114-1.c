/*
   20011114-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

char foo(char bar[])
{
  return bar[1];
}
extern char foo(char *);
void
testTortureExecute (void)
{
  if (foo("xy") != 'y')
    ASSERT (0);
  return;
}

