/*
   20041113-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#pragma disable_warning 85

#include <stdarg.h>

void test (int x, ...)
{
    va_list ap;
    int i;
    va_start (ap, x);
    if (va_arg (ap, int) != 1)
	ASSERT (0);
    if (va_arg (ap, int) != 2)
	ASSERT (0);
    if (va_arg (ap, int) != 3)
	ASSERT (0);
    if (va_arg (ap, int) != 4)
	ASSERT (0);
}

double a = 40.0;

void testTortureExecute (void)
{
    test(0, 1, 2, 3, (int)(a / 10.0));
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
  return "cases_gcc\\gcc-torture-execute-20041113-1";
}
