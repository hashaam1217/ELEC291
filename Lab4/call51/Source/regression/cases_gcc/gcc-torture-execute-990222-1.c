/*
   990222-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

char line[4] = { '1', '9', '9', '\0' };

void
testTortureExecute (void)
{
  char *ptr = line + 3;

  while ((*--ptr += 1) > '9') *ptr = '0';
  if (line[0] != '2' || line[1] != '0' || line[2] != '0')
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-990222-1";
}
