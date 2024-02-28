/** Simple test for increment

    type: signed char, int, long
    storage: static, 
    attr: volatile
*/
#include "../fwk/include/testfwk.h"

static void
testIncrement(void)
{
    volatile  int i;
    i = 0;
    i--;
    ASSERT(i == -1);
}

void
__runSuite(void)
{
  __prints("Running testIncrement\n");
  testIncrement();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_increment_storage_none_type_int_attr_volatile";
}
