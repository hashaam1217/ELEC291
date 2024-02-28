/*
   991112-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

#include <ctype.h>

/* This code was miscompiled at -O3 on x86.
   Reported by Jim Meyering; distilled from bash.  */

int rl_show_char (int c) { return 0; }

int rl_character_len (int c, int pos) __reentrant
{
  return isprint (c) ? 1 : 2;
}

void
testTortureExecute (void)
{
  int (*x)(int, int) __reentrant = rl_character_len;
  if (x('a', 1) != 1)
    ASSERT (0);
  if (x('\002', 1) != 2)
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
  return "cases_gcc\\gcc-torture-execute-991112-1";
}
