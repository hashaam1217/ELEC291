/*
   990106-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

foo(char *bufp)
{
    int x = 80;
    return (*bufp++ = x ? 'a' : 'b');
}

void
testTortureExecute (void)
{
  char x;

  if (foo (&x) != 'a')
    ASSERT (0);

  return;
}
