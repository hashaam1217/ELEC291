/*
   loop-15.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Bombed with a segfault on powerpc-linux.  doloop.c generated wrong
   loop count.  */
void
foo (unsigned long *start, unsigned long *end)
{
  unsigned long *temp = end - 1;

  while (end > start)
    *end-- = *temp--;
}

void
testTortureExecute (void)
{
  unsigned long a[5];
  int start, end, k;

  for (start = 0; start < 5; start++)
    for (end = 0; end < 5; end++)
      {
	for (k = 0; k < 5; k++)
	  a[k] = k;

	foo (a + start, a + end);

	for (k = 0; k <= start; k++)
	  if (a[k] != k)
	    ASSERT (0);

	for (k = start + 1; k <= end; k++)
	  if (a[k] != k - 1)
	    ASSERT (0);

	for (k = end + 1; k < 5; k++)
	  if (a[k] != k)
	    ASSERT (0);
      }

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
  return "cases_gcc\\gcc-torture-execute-loop-15";
}
