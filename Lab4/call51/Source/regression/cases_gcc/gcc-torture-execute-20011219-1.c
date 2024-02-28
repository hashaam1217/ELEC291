/*
   20011219-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#pragma disable_warning 84
#endif

/* This testcase failed on IA-32 at -O and above, because combine attached
   a REG_LABEL note to jump instruction already using JUMP_LABEL.  */

enum X { A, BB, C, D, E, F, G, H, I, J, K, L, M, N, O, PP, Q }; // B and P are 8051 SFRs

void
bar (const char *x, int y, const char *z)
{
	x; y; z;
}

long
foo (enum X x, const void *y)
{
  long a=0;

  switch (x)
    {
    case K:
      a = *(long *)y;
      break;
    case L:
      a = *(long *)y;
      break;
    case M:
      a = *(long *)y;
      break;
    case N:
      a = *(long *)y;
      break;
    case O:
      a = *(long *)y;
      break;
    default:
      bar ("foo", 1, "bar");
    }
  return a;
}

void
testTortureExecute (void)
{
  long i = 24;
  if (foo (N, &i) != 24)
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
  return "cases_gcc\\gcc-torture-execute-20011219-1";
}
