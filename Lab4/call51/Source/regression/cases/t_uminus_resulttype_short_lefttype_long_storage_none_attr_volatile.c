/* Test unary minus

    lefttype: signed char, short, long
    resulttype: signed char, short, long
    storage: static,
    attr: volatile,
 */
#include "../fwk/include/testfwk.h"

void
testUMinus(void)
{
   volatile long left;
   volatile short result;

  left = 53;
  result = -left;

  ASSERT(result == -53);

  left = -76;
  result = -left;

  ASSERT(result == 76);
}

void
__runSuite(void)
{
  __prints("Running testUMinus\n");
  testUMinus();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_uminus_resulttype_short_lefttype_long_storage_none_attr_volatile";
}
