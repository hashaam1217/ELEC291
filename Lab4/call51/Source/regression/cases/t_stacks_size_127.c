/*
  size: 126, 127, 128, 129
 */
#include "../fwk/include/testfwk.h"

void
spoil(char a)
{
  UNUSED(a);
}

void
spoilPtr(volatile char *p)
{
  UNUSED(p);
}

void
testStack(void)
{
  volatile char above;
  volatile char above2;
#ifndef __mcs51
  volatile char ac[127];
#else
  volatile char ac[127 - 100];
#endif
  volatile char below;
  volatile char * volatile p;

  spoil(ac[0]);
  spoilPtr(&above);
  spoilPtr(&below);

  p = &above2;
  spoilPtr(p);
}

void
__runSuite(void)
{
  __prints("Running testStack\n");
  testStack();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_stacks_size_127";
}
