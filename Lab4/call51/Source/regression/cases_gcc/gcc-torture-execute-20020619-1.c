/*
   20020619-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdint.h>
#include <string.h>

typedef int32_t int32;

static int32 ref(void)
{
  union {
    char c[5];
    int32 i;
  } u;

  memset (&u, 0, sizeof(u));
  u.c[0] = 1;
  u.c[1] = 2;
  u.c[2] = 3;
  u.c[3] = 4;

  return u.i;
}

void
testTortureExecute (void)
{
  int32 b = ref();
  if (b != 0x01020304
      && b != 0x04030201)
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
  return "cases_gcc\\gcc-torture-execute-20020619-1";
}
