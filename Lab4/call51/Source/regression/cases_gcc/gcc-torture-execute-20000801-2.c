/*
   20000801-2.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int bar(void);
int baz(void);

struct foo {
  struct foo *next;
};

struct foo *test(struct foo *node)
{
  while (node) {
    if (bar() && !baz())
      break;
    node = node->next;
  }
  return node;
}

int bar (void)
{
  return 0;
}

int baz (void)
{
  return 0;
}

void
testTortureExecute (void)
{
  struct foo a, b, *c;

  a.next = &b;
  b.next = (struct foo *)0;
  c = test (&a);
  if (c)
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
  return "cases_gcc\\gcc-torture-execute-20000801-2";
}
