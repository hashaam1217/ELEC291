/* Tests a commit problem.
 */
#include "../fwk/include/testfwk.h"



int foo = 16;

void f( int x )
{
  UNUSED(x);
}

void g(int bar)
{
  int a = 0;
  int b = 0;

  while(1) {
    switch(bar) {
    case 0:
      --foo;
      f(foo);
      break;
    case 1:
      ++foo;
      f(foo);
      break;
    case 2:
      ++a;
      f(a);
      break;
    case 3:
      ++b;
      f(b);
      break;
    }
  }
}

void testBug(void)
{
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
  return "cases_sdcc_bugs\\bug-478094";
}
