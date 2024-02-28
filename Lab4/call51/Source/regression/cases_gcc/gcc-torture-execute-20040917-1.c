/*
   20040917-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* submitted by kenneth zadeck */

static int test_var;

/* the idea here is that not only is inlinable, inlinable but since it
   is static, the cgraph node will not be marked as output.  The
   current version of the code ignores these cgraph nodes.  */

void not_inlinable();

static void  
inlinable ()
{
  test_var = -10;
}

void 
not_inlinable ()
{
  inlinable();
}

void
testTortureExecute (void)
{
  test_var = 10;
  /* Variable test_var should be considered call-clobbered by the call
     to not_inlinable().  */
  not_inlinable ();
  if (test_var == 10)
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
  return "cases_gcc\\gcc-torture-execute-20040917-1";
}
