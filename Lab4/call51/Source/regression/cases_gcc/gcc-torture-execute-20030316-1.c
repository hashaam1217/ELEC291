/*
   20030316-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR target/9164 */
/* The comparison operand was sign extended erraneously.  */

void
testTortureExecute (void)
{
    long j = 0x40000000;
    if ((unsigned int) (0x40000000 + j) < 0L)
 	ASSERT (0);

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
  return "cases_gcc\\gcc-torture-execute-20030316-1";
}
