/*
   20020423-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR c/5430 */
/* Verify that the multiplicative folding code is not fooled
   by the mix between signed variables and unsigned constants. */

void testTortureExecute (void)
{
  int my_int = 924;
  unsigned int result;

  result = ((my_int*2 + 4) - 8U) / 2;
  if (result != 922U)
    ASSERT (0);
         
  result = ((my_int*2 - 4U) + 2) / 2;
  if (result != 923U)
    ASSERT (0);

  result = (((my_int + 2) * 2) - 8U - 4) / 2;
  if (result != 920U)
    ASSERT (0);
  result = (((my_int + 2) * 2) - (8U + 4)) / 2;
  if (result != 920U)
    ASSERT (0);

  result = ((my_int*4 + 2U) - 4U) / 2;
  if (result != 1847U)
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
  return "cases_gcc\\gcc-torture-execute-20020423-1";
}
