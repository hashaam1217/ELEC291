/*
   bug663539.c
*/

#include "../fwk/include/testfwk.h"

#if defined (__C51_ds390) || defined (__C51_mcs51)
  volatile __xdata __at 0x7654 char x;
#endif

void
test_volatile (void)
{
  ASSERT (1);

#if defined (__C51_ds390) || defined (__C51_mcs51)
  x;         //this should end the simulation

  while (1); //let the "watchdog" bite
#endif
}


void
__runSuite(void)
{
  __prints("Running test_volatile\n");
  test_volatile();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug663539";
}
