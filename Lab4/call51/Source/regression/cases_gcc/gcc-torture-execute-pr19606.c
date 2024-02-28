/*
   pr19606.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Todo: Enable when C51 supports long long modulo!
#if 0

/* PR c/19606
   The C front end used to shorten the type of a division to a type
   that does not preserve the semantics of the original computation.
   Make sure that won't happen.  */

signed char a = -4;

int
foo (void)
{
  return ((unsigned int) (signed int) a) / 2LL;
}

int
bar (void)
{
  return ((unsigned int) (signed int) a) % 5LL;
}
#endif
void
testTortureExecute (void)
{
#if 0
  int r;

  r = foo ();
  if (r != ((unsigned int) (signed int) (signed char) -4) / 2LL)
    ASSERT (0);

  r = bar ();
  if (r != ((unsigned int) (signed int) (signed char) -4) % 5LL)
    ASSERT (0);

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
  return "cases_gcc\\gcc-torture-execute-pr19606";
}
