/** Bug 868103 tests.

    storage1: __near, __far, __code,
    storage2: __near, __far,
*/

#ifndef STORAGE1
#define STORAGE1 __code
#endif

#ifndef STORAGE2
#define STORAGE2 __far
#endif

#include "../fwk/include/testfwk.h"

typedef struct {
  STORAGE1 char * bar[2];
} foo;

STORAGE1 char c = 'x';
STORAGE2 foo f;

void
testBug868103 (void)
{
  f.bar[1] = &c;
  ASSERT (f.bar[1] == &c);
}

void
__runSuite(void)
{
  __prints("Running testBug868103\n");
  testBug868103();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-868103_storage1___code_storage2___far";
}
