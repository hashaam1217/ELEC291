/*
   920829-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo: Enable when C51 supports long long constants!
#if 0
long long c=2863311530LL,c3=2863311530LL*3;
#endif

void
testTortureExecute (void)
{
#if 0
  if(c*3!=c3)
    ASSERT(0);
  return;
#endif
}

