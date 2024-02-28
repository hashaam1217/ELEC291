/*
   20030914-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports struct assignment!
#if 0
/* On IRIX 6, PA is passed partially in registers and partially on the
   stack.  We therefore have two potential uses of pretend_args_size:
   one for the partial argument and one for the varargs save area.
   Make sure that these uses don't conflict.  */

struct s { int i[18]; };

int f (struct s pa, int pb, ...)
{
  return pb;
}

struct s gs;
#endif

void
testTortureExecute (void)
{
#if 0
  if (f (gs, 0x1234) != 0x1234)
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
  return "cases_gcc\\gcc-torture-execute-20030914-2";
}
