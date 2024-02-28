/*
   bug3004918.c
 */

#include "../fwk/include/testfwk.h"
#include <stdint.h>

#ifdef __C51_STACK_AUTO
 #define XDATA
#else
 #define XDATA __xdata
#endif

uint16_t foo (uint16_t a, XDATA uint8_t b)
{
  return a + b;
}

volatile uint8_t p = 0x56;
volatile uint8_t q = 0x78;

void testBug(void)
{
  ASSERT (foo(p + 0x1234, q) == 0x1302);
}

void
__runSuite(void)
{
  __prints("Running testBug\n");
  testBug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug3004918";
}
