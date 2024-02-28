/*
   20030203-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

void f(int);
int do_layer3(int single)
{
  int stereo1;

  if(single >= 0) /* stream is stereo, but force to mono */
    stereo1 = 1;
  else
    stereo1 = 2;
  f(single);

  return stereo1;
}

void
testTortureExecute (void)
{
  if (do_layer3(-1) != 2)
    ASSERT (0);
  return;
}

void f(int i) {}


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
  return "cases_gcc\\gcc-torture-execute-20030203-1";
}
