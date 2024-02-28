/*
   920429-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

typedef unsigned char t;int i,j;
t*f(const t*p){t c;c=*p++;i=((c&2)?1:0);j=(c&7)+1;return p;}

void
testTortureExecute (void){const t*p0="ab",*p1;p1=f(p0);if(p0+1!=p1)ASSERT(0);return;}


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
  return "cases_gcc\\gcc-torture-execute-920429-1";
}
