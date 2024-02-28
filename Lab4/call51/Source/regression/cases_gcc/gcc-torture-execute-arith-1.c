/*
   arith-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c89
#endif

unsigned
sat_add (unsigned i)
{
  unsigned ret = i + 1;
  if (ret < i)
    ret = i;
  return ret;
}

void
testTortureExecute (void)
{
  if (sat_add (~0U) != ~0U)
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
  return "cases_gcc\\gcc-torture-execute-arith-1";
}
