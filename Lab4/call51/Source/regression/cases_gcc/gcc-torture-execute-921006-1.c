/*
   921006-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

/* REPRODUCED:RUN:SIGNAL MACHINE:i386 OPTIONS:-O */
void
testTortureExecute (void)
{
if(strcmp("X","")<0)ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-921006-1";
}
