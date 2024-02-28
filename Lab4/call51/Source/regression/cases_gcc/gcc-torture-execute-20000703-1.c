/*
   20000703-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <string.h>

struct baz 
{
  char a[17];
  char b[3];
  unsigned int c;
  unsigned int d;
};

void foo(struct baz *p, unsigned int c, unsigned int d)
{
  memcpy (p->b, "abc", 3);
  p->c = c;
  p->d = d;
}

void bar(struct baz *p, unsigned int c, unsigned int d)
{
  { void *s = (p);
     memset (s, '\0', sizeof (struct baz));
     s; };
  memcpy (p->a, "01234567890123456", 17);
  memcpy (p->b, "abc", 3);
  p->c = c;
  p->d = d;
}

void
testTortureExecute (void)
{
  struct baz p;
  foo(&p, 71, 18);
  if (p.c != 71 || p.d != 18)
    ASSERT (0);
  bar(&p, 59, 26);
  if (p.c != 59 || p.d != 26)
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
  return "cases_gcc\\gcc-torture-execute-20000703-1";
}
