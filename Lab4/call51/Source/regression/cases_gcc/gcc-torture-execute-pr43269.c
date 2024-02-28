/*
   pr43269.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int g_21;
int g_211;
int g_261;

static void
func_32 (int b)
{
  if (b) {
lbl_370:
      g_21 = 1;
  }

  for (g_261 = -1; g_261 > -2; g_261--) {
      if (g_211 + 1) {
	  return;
      } else {
	  g_21 = 1;
	  goto lbl_370;
      }
  }
}

void
testTortureExecute (void)
{
  func_32(0);
  if (g_261 != -1)
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
  return "cases_gcc\\gcc-torture-execute-pr43269";
}
