/* bug-983491.c
 */

#include "../fwk/include/testfwk.h"

/*
 * test disabled since the fix was reverted 
 */

/*
code struct {
  char* b;
} c[2] = {
  {"abc"},
  {"abc"}
};
*/

void
testMergeStr(void)
{
/*  ASSERT(c[0].b == c[1].b); */
}

void
__runSuite(void)
{
  __prints("Running testMergeStr\n");
  testMergeStr();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-983491";
}
