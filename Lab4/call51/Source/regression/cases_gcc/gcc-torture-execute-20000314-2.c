/*
   20000314-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// C51 cannot return long long yet.
#if 0

typedef unsigned long long uint64;
const uint64 bigconst = 1ULL << 34;

int a = 1;

static
uint64 getmask(void)
{
    if (a)
      return bigconst;
    else
      return 0;
}
#endif

void
testTortureExecute (void)
{
#if 0
    uint64 f = getmask();
    if (sizeof (long long) == 8
	&& f != bigconst) ASSERT (0);
    return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-20000314-2";
}
