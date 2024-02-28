/*
   20001011-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

int foo(const char *a)
{
    return strcmp(a, "testTortureExecute");
}

void
testTortureExecute (void)
{
#if 0
    if(foo(__func__))
        ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20001011-1";
}
