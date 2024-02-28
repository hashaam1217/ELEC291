/*
   string-opt-17.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Copyright (C) 2003  Free Software Foundation.

   Test strcpy optimizations don't evaluate side-effects twice.
      
   Written by Jakub Jelinek, June 23, 2003.  */

#include <string.h>

size_t
test1 (char *s, size_t i)
{
  strcpy (s, "foobarbaz" + i++);
  return i;
}

size_t
check2 (void)
{
  static size_t r = 5;
  if (r != 5)
    ASSERT (0);
  return ++r;
}

void
test2 (char *s)
{
  strcpy (s, "foobarbaz" + check2 ());
}

void
testTortureExecute (void)
{
  char buf[10];
  if (test1 (buf, 7) != 8 || memcmp (buf, "az", 3))
    ASSERT (0);
  test2 (buf);
  if (memcmp (buf, "baz", 4))
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
  return "cases_gcc\\gcc-torture-execute-string-opt-17";
}
