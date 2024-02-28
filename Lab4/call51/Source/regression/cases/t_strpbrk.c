/** tests for strpbrk
 * related to bug #2908537
*/
#include "../fwk/include/testfwk.h"
#include <string.h>

static void
teststrpbrk(void)
{
  const char *a = "test";

  ASSERT( strpbrk(a, "e")  == &a[1] );
  ASSERT( strpbrk(a, "z")  == NULL );
  ASSERT( strpbrk(a, "et") == &a[0] );
  ASSERT( strpbrk(a, "ze") == &a[1] );
  ASSERT( strpbrk(a, "")   == NULL );
  ASSERT( strpbrk("", "e") == NULL );
  ASSERT( *strpbrk("test2", "s") == 's' );
}

void
__runSuite(void)
{
  __prints("Running teststrpbrk\n");
  teststrpbrk();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_strpbrk";
}
