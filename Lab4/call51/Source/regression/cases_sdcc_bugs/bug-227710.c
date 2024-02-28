/* bug-227710.c
 */
#include "../fwk/include/testfwk.h"

static unsigned char dataset[] = {
    1, 2, 3, 4
};

unsigned char *p; 

struct { 
    unsigned char index; 
} s; 

unsigned char 
foo(void) 
{ 
    // BUG, there will be a PRE-increment 
    return p[s.index++];
}

void
testPostIncrement(void)
{
    p = dataset;
    ASSERT(foo() == 1);
    ASSERT(foo() == 2);
    ASSERT(foo() == 3);
    ASSERT(foo() == 4);
}

void
__runSuite(void)
{
  __prints("Running testPostIncrement\n");
  testPostIncrement();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-227710";
}
