/*
   bug1198642.c
*/

#include "../fwk/include/testfwk.h"

void
test_cse_generic_ptr (void)
{
#if defined(__C51_mcs51)
  volatile void *p1;
  volatile void *p2;

  p1 = (__data char *)1;
  p2 = (__idata char *)1;
  ASSERT (p1 == p2);

  p1 = (__data char *)1;
  p2 = (__xdata char *)1;
  ASSERT (p1 != p2);

  p1 = (__data char *)1;
  p2 = (__idata char *)2;
  ASSERT (p1 != p2);
#endif
}

void
__runSuite(void)
{
  __prints("Running test_cse_generic_ptr\n");
  test_cse_generic_ptr();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1198642";
}
