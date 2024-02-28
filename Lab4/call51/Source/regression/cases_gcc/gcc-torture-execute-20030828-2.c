/*
   20030828-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

struct rtx_def
{
  int mycode;
};

void
testTortureExecute (void)
{
  int tmp[2];
  struct rtx_def *r, s;
  int *p, *q;

  /* The alias analyzer was creating the same memory tag for r, p and q
     because 'struct rtx_def *' is type-compatible with 'int *'.  However,
     the alias set of 'int[2]' is not the same as 'int *', so variable
     'tmp' was deemed not aliased with anything.  */
  r = &s;
  r->mycode = 39;

  /* If 'r' wasn't declared, then q and tmp would have had the same memory
     tag.  */
  p = tmp;
  q = p + 1;
  *q = 0;
  tmp[1] = 39;
  if (*q != 39)
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
  return "cases_gcc\\gcc-torture-execute-20030828-2";
}
