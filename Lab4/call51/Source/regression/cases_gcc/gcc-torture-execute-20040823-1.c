/*
   20040823-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Ensure that we create VUSE operands also for noreturn functions.  */

#include <stdlib.h>
#include <string.h>

int *pwarn;

void bla (void);

void bla (void)
{
  if (!*pwarn)
    ASSERT (0);
    
  return;
}

void testTortureExecute (void)
{
  int warn;

  memset (&warn, 0, sizeof (warn));

  pwarn = &warn;

  warn = 1;

  bla ();
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
  return "cases_gcc\\gcc-torture-execute-20040823-1";
}
