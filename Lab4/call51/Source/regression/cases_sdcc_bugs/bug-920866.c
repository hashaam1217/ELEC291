/* replace optimized parameter tree returned by decorateType */

#include "../fwk/include/testfwk.h"

char
foo(char c)
{
  return c;
}

void
testReplaceParameterTree(void)
{
  ASSERT(foo (0 ? 1 : 2) == 2);
}

void
__runSuite(void)
{
  __prints("Running testReplaceParameterTree\n");
  testReplaceParameterTree();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-920866";
}
