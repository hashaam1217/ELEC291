/** tests for strcmp
*/
#include "../fwk/include/testfwk.h"
#include <string.h>

static void 
teststrcmp(void)
{
  int result = strcmp("", "");
  ASSERT( result == 0);
  
  result = strcmp("", "a");
  ASSERT( result < 0);

  result = strcmp("a", "");
  ASSERT( result > 0);

  result = strcmp("ab", "ab");
  ASSERT( result == 0);

  result = strcmp("aa", "ab");
  ASSERT( result < 0);
}

void
__runSuite(void)
{
  __prints("Running teststrcmp\n");
  teststrcmp();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_strcmp";
}
