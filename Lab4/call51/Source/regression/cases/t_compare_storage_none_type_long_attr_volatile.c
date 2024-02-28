/** Test the comparison operators.

    type: char, int, long
    storage: static, 
    attr: volatile
 */
#include "../fwk/include/testfwk.h"

static void
testCmpAroundZero(void)
{
    volatile  signed long i;

    i = 5;

    ASSERT(0 < i);
    ASSERT(i > 0);
    ASSERT(0 <= i);
    ASSERT(i >= 0);
    
    i = -33;
    ASSERT(0 > i);
    ASSERT(i < 0);
    ASSERT(0 >= i);
    ASSERT(i <= 0);

    i = 0;
    ASSERT(0 == i);
    ASSERT(0 <= i);
    ASSERT(0 >= i);
}

static void
testCompareConstants(void)
{
    volatile  signed long i;

    i = 12;
    ASSERT(i < 23);
    ASSERT(i > 3);
    ASSERT(i > -14);
    ASSERT(i <= 23);
    ASSERT(i >= 3);
    ASSERT(i >= -14);
    ASSERT(i <= 12);
    ASSERT(i >= 12);
    ASSERT(i == 12);

    i = -34;
    ASSERT(i > -126);
    ASSERT(i < -3);
    ASSERT(i < 47);
    ASSERT(i >= -126);
    ASSERT(i <= -3);
    ASSERT(i <= 47);
    ASSERT(i <= -34);
    ASSERT(i >= -34);
    ASSERT(i == -34);
}

static void
testCompareVariables(void)
{
    volatile  signed long left, right;

    left = 12;
    right = 47;
    ASSERT(left < right);
    ASSERT(left <= right);
    ASSERT(right > left);
    ASSERT(right >= left);

    right = -8;
    ASSERT(left > right);
    ASSERT(left >= right);
    ASSERT(right < left);
    ASSERT(right <= left);

    right = 0;
    ASSERT(left > right);
    ASSERT(left >= right);
    ASSERT(right < left);
    ASSERT(right <= left);

    right = left;
    ASSERT(left == right);
    ASSERT(left <= right);
    ASSERT(left >= right);
}

static void
testUnsignedCompare(void)
{
    volatile  unsigned long left, right;

    left = 0;
    right = (unsigned long)-1;

    ASSERT(left < right);
    ASSERT(left <= right);
    ASSERT(right > left);
    ASSERT(right >= left);
}
/*
                Common cases:
                        Around zero
                        Constants on either side (reversal)
                <=
                >=
                ==
                !=
                <
                >
*/

void
__runSuite(void)
{
  __prints("Running testCmpAroundZero\n");
  testCmpAroundZero();
  __prints("Running testCompareConstants\n");
  testCompareConstants();
  __prints("Running testCompareVariables\n");
  testCompareVariables();
  __prints("Running testUnsignedCompare\n");
  testUnsignedCompare();
}

const int __numCases = 4;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_compare_storage_none_type_long_attr_volatile";
}
