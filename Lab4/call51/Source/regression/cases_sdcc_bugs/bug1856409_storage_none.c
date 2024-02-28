/*
    bug 1856409
    storage: static __code,
*/

#include <stdint.h>
#include "../fwk/include/testfwk.h"

#ifndef PORT_HOST
#pragma disable_warning 158 //no warning about overflow in constant (W_LIT_OVERFLOW)
#endif

typedef struct {
  unsigned int e:2;
  unsigned int f:3;
  unsigned int g:3;
} Ta;

void
testBug (void)
{
   Ta aa = {1, 29, 0};
   uint16_t xx = 100000;
  char t;

  t = aa.e;
  ASSERT (t == (1 & 3));
  t = aa.f;
  ASSERT (t == (29 & 7));
  t = aa.g;
  ASSERT (t ==  (0 & 7));

  ASSERT (xx == (uint16_t)(100000 & 65535));
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
  return "cases_sdcc_bugs\\bug1856409_storage_none";
}
