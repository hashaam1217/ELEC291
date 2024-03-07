/*
   20030715-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

#include <string.h>

/* PR optimization/11320 */
/* Origin: Andreas Schwab <schwab@suse.de> */

/* Verify that the scheduler correctly computes the dependencies
   in the presence of conditional instructions.  */

int ap_standalone;

const char *ap_check_cmd_context (void *a, int b)
{
  return 0;
}

const char *server_type (void *a, void *b, char *arg)
{
  const char *err = ap_check_cmd_context (a, 0x01|0x02|0x04|0x08|0x10);
  if (err)
    return err;

  if (!strcmp (arg, "inetd"))
    ap_standalone = 0;
  else if (!strcmp (arg, "standalone"))
      ap_standalone = 1;
  else
    return "ServerType must be either 'inetd' or 'standalone'";

  return 0;
}

void
testTortureExecute (void)
{
  server_type (0, 0, "standalone");
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
  return "cases_gcc\\gcc-torture-execute-20030715-1";
}