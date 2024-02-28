/*
   bug-1699804.c
*/

#include "../fwk/include/testfwk.h"

static __code const char Str_global[] = "Hello1";
char s1, s2;

void
testFoo (void)
{
  static __code const char str_local[] = "Hello2";

  static char str1[sizeof (Str_global)];
  static char str2[sizeof (str_local)]; // causes error 20: Undefined identifier 'str_local'

  s1 = sizeof (Str_global);
  s2 = sizeof (str_local);              // no error and proper result when line causing error (above) is removed

  ASSERT (s1 == 7);
  ASSERT (s2 == 7);
}

void
__runSuite(void)
{
  __prints("Running testFoo\n");
  testFoo();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1699804";
}
