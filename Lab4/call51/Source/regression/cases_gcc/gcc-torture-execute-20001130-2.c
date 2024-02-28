/*
   20001130-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

static int which_alternative = 3;

static const char *i960_output_ldconst (void);

static const char *
output_25 (void)
{
  switch (which_alternative)
    {
    case 0:
      return "mov	%1,%0";
    case 1:
      return i960_output_ldconst ();
    case 2:
      return "ld	%1,%0";
    case 3:
      return "st	%1,%0";      
    }
}

static const char *i960_output_ldconst (void)
{
  return "foo";
}

void
testTortureExecute (void)
{
  const char *s = output_25 () ;
  if (s[0] != 's')
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
  return "cases_gcc\\gcc-torture-execute-20001130-2";
}
