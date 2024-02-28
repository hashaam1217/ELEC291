/*
   930408-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

typedef enum foo E;
enum foo { e0, e1 };

struct {
  E eval;
} s;

void p()
{
  ASSERT(0);
}

void f()
{
  switch (s.eval)
    {
    case e0:
      p();
    }
}

void
testTortureExecute (void)
{
  s.eval = e1;
  f();
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
  return "cases_gcc\\gcc-torture-execute-930408-1";
}
