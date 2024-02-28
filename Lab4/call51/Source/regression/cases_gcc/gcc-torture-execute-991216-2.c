/*
   991216-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 184
#endif

// Some ports do not support long long yet.
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)

#include <stdarg.h>

#define VALUE 0x123456789abcdefLL
#define AFTER 0x55

void
test (int n, ...)
{
  va_list ap;
  int i;

  va_start (ap, n);
  for (i = 2; i <= n; i++)
    {
      if (va_arg (ap, int) != i)
	ASSERT (0);
    }

  if (va_arg (ap, long long) != VALUE)
    ASSERT (0);

  if (va_arg (ap, int) != AFTER)
    ASSERT (0);

  va_end (ap);
}
#endif

void
testTortureExecute (void)
{
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  test (1, VALUE, AFTER);
  test (2, 2, VALUE, AFTER);
  test (3, 2, 3, VALUE, AFTER);
  test (4, 2, 3, 4, VALUE, AFTER);
  test (5, 2, 3, 4, 5, VALUE, AFTER);
  test (6, 2, 3, 4, 5, 6, VALUE, AFTER);
  test (7, 2, 3, 4, 5, 6, 7, VALUE, AFTER);
  test (8, 2, 3, 4, 5, 6, 7, 8, VALUE, AFTER);
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
  return "cases_gcc\\gcc-torture-execute-991216-2";
}
