/*
   pr47155.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR tree-optimization/47155 */

unsigned int a;
static signed char b = -127;
int c = 1;

void
testTortureExecute (void)
{
  a = b <= (unsigned char) (-6 * c);
  if (!a)
    ASSERT (0);
  return;
}
