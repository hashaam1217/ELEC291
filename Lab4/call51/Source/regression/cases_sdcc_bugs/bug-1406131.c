/* bug-1406131.c

   always false while-loop
*/
#include "../fwk/include/testfwk.h"

void
testwhile(void)
{
  do
    ;
  while (0);
  
  while (0)
    ;
  
  for (; 0; )
    ;
}

void
__runSuite(void)
{
  __prints("Running testwhile\n");
  testwhile();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1406131";
}
