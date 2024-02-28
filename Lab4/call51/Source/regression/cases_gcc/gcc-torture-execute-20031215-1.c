/*
   20031215-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* PR middle-end/13400 */
/* The following test used to fail at run-time with a write to read-only
   memory, caused by if-conversion converting a conditional write into an
   unconditional write.  */

typedef struct {int c, l; char ch[3];} pstr;
const pstr ao = {2, 2, "OK"};
const pstr * const a = &ao;

void test1(void)
{
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = 0;
    }
}

void test2(void)
{
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = -1;
    }
}

void test3(void)
{
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = 1;
    }
}

void
testTortureExecute (void)
{
    test1();
    test2();
    test3();
    return;
}


void
__runSuite(void)
{
  __prints("Running test1\n");
  test1();
  __prints("Running test2\n");
  test2();
  __prints("Running test3\n");
  test3();
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 4;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-20031215-1";
}
