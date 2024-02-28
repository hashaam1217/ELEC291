/*
   920501-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

int s[2];

int
x(int parm)
{
  if(!s[0])
    {
      s[1+s[1]]=s[1];
      return 1;
    }
}

void
testTortureExecute (void){s[0]=s[1]=0;if(x(0)!=1)ASSERT(0);return;}


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
  return "cases_gcc\\gcc-torture-execute-920501-1";
}
