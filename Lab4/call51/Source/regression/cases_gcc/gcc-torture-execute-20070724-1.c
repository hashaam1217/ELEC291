/*
   20070724-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static unsigned char magic[] = "\235";
static unsigned char value = '\235';

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && __GNUC__ < 5)
  if (value != magic[0])
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
  return "cases_gcc\\gcc-torture-execute-20070724-1";
}
