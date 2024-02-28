/*
   20000010-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright (C) 2000  Free Software Foundation  */
/* by Alexandre Oliva <aoliva@redhat.com> */

#include <stdlib.h>
#include <string.h>

const char *list[] = { "*", "e" };

static int bar (const char *fmt) {
  return (strchr (fmt, '*') != 0);
}

static void foo () {
  int i;
  for (i = 0; i < sizeof (list) / sizeof (*list); i++) {
    const char *fmt = list[i];
    if (bar (fmt))
      continue;
    if (i == 0)
      ASSERT (0);
    else
      return;
  }
}

void
testTortureExecute (void) {
  foo ();
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
  return "cases_gcc\\gcc-torture-execute-20000910-2";
}
