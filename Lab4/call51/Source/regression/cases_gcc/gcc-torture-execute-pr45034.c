/*
   pr45034.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

static void fixnum_neg(signed char x, signed char *py, int *pv)
{
  unsigned char ux, uy;

  ux = (unsigned char)x;
  uy = -ux;
  *py = (uy <= 127) ? (signed char)uy : (-(signed char)(255 - uy) - 1);
  *pv = (x == -128) ? 1 : 0;
}

void foo(int x, int y, int v)
{
  if (y < -128 || y > 127)
    ASSERT(0);
}

int ftest_neg(void)
{
  signed char x, y;
  int v, err;

  err = 0;
  x = -128;
  for (;;) {
      fixnum_neg(x, &y, &v);
      foo((int)x, (int)y, v);
      if ((v && x != -128) || (!v && x == -128))
	++err;
      if (x == 127)
	break;
      ++x;
  }
  return err;
}

void
testTortureExecute (void)
{
#if !(defined (__GNUC__) && defined (__GNUC_MINOR__) && (__GNUC__ < 5 && __GNUC_MINOR__ < 6))
  if (sizeof (char) != 1)
    return;
  if (ftest_neg() != 0)
    ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-pr45034";
}
