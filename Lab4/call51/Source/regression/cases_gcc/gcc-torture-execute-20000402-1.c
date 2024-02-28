/*
   20000402-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>

// TODO: Enable when C51 supports long long constants!
/*#if ULONG_LONG_MAX != 18446744073709551615ull && ULONG_MAX != 18446744073709551615ull
void
testTortureExecute (void) { return; }
#else
#if ULONG_MAX != 18446744073709551615ull
typedef unsigned long long ull;
#else
typedef unsigned long ull;
#endif

#include <stdio.h>

void checkit(int);*/

void
testTortureExecute (void) {
    /*const ull a = 0x1400000000ULL;
    const ull b = 0x80000000ULL;
    const ull c = a/b;
    const ull d = 0x1400000000ULL / 0x80000000ULL;

    checkit ((int) c);
    checkit ((int) d);

    return;*/
}

/*void checkit (int a)
{
  if (a != 40)
    ASSERT (0);
}
#endif*/


void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 2;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20000402-1";
}
