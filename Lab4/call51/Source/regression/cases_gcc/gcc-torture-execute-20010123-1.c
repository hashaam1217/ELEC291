/*
   20010123-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when supported by C51!

struct s
{
    int value;
    char *string;
};

void
testTortureExecute (void)
{
#if 0
  int i;
  for (i = 0; i < 4; i++)
    {
      struct s *t = & (struct s) { 3, "hey there" };
      if (t->value != 3)
	ASSERT (0);
      t->value = 4;
      if (t->value != 4)
	ASSERT (0);
    }
  return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-20010123-1";
}
