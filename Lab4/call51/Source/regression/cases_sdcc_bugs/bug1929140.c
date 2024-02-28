/*
   bug1929140.c
 */

#include "../fwk/include/testfwk.h"

// no need to call this, it generates parser error:
//   syntax error: token -> 'foo' ; column 10
extern void (* P1032E)(void);

extern void (* P1032E)(void);


void
testBug (void)
{
	ASSERT (1);
}

void
__runSuite(void)
{
  __prints("Running testBug\n");
  testBug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1929140";
}
