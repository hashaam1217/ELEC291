/*
   20040313-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

/* PR middle-end/14470 */
/* Origin: Lodewijk Voge <lvoge@cs.vu.nl> */

void
testTortureExecute (void)
{
  xdata int t[1025] = { 1024 }, d;

  d = 0;
  d = t[d]++;
  ASSERT(!(t[0] != 1025));
  ASSERT(!(d != 1024));
  return;
}
