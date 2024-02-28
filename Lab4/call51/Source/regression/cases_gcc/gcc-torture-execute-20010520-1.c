/*
   20010520-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static unsigned int expr_hash_table_size = 1;

void
testTortureExecute (void)
{
  int del = 1;
  unsigned int i = 0;

  if (i < expr_hash_table_size && del)
    return;
  ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20010520-1";
}
