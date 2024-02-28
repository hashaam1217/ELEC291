/* Bad addition for adding a length and char[]
 */
#include "../fwk/include/testfwk.h"

#if defined(__C51_mcs51)
#define SZ_SIZE 89
#else
#define SZ_SIZE 90
#endif

typedef struct _Foo
{
  char sz[SZ_SIZE];
} Foo;

typedef struct _Bar
{
  unsigned int uLen;
} Bar;

char *getOffset(Foo *pFoo, Bar *pBar)
{
  return pFoo->sz + pBar->uLen;
}

void
testOffset(void)
{
  Foo foo = {
    "Foo"
  };
  Bar bar = {
    3
  };

  ASSERT(getOffset(&foo, &bar) 
	 == (((char *)&foo) + 3));
}

void
__runSuite(void)
{
  __prints("Running testOffset\n");
  testOffset();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-524697";
}
