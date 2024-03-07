/*
   20041112-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stddef.h>

/* This was failing on Alpha because the comparison (p != -1) was rewritten
   as (p+1 != 0) and p+1 isn't allowed to wrap for pointers.  */

int global;

static void *foo(int p)
{
  if (p == 0)
   {
      global++;
      return &global;
   }

  return (void *)(size_t)-1;
}

int bar(void)
{
  void *p;

  p = foo(global);
  if (p != (void *)(size_t)-1)
    return 1;

  global++;
  return 0;
}

void testTortureExecute(void)
{
  global = 1;
  if (bar () != 0)
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
  return "cases_gcc\\gcc-torture-execute-20041112-1";
}