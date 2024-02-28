/*
   enum-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright (C) 2000 Free Software Foundation */
/* by Alexandre Oliva  <aoliva@redhat.com> */

enum foo { FOO, BAR };

/* Even though the underlying type of an enum is unspecified, the type
   of enumeration constants is explicitly defined as int (6.4.4.3/2 in
   the C99 Standard).  Therefore, `i' must not be promoted to
   `unsigned' in the comparison below; we must exit the loop when it
   becomes negative. */

void
testTortureExecute (void)
{
  int i;
  for (i = BAR; i >= FOO; --i)
    if (i == -1)
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
  return "cases_gcc\\gcc-torture-execute-enum-2";
}
