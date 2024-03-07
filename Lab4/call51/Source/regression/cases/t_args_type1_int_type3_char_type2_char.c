/** Tests argument passing to functions.
    Assumes that up to the first two arguments can be passed in registers.

    type1: char, int, long
    type2: char, int, long
    type3: char, int, long
 */
#include "../fwk/include/testfwk.h"

static int
returnFirstArg(int arg1, char arg2, char arg3)
{
    UNUSED(arg2);
    UNUSED(arg3);
    return arg1;
}

static char
returnSecondArg(int arg1, char arg2, char arg3)
{
    UNUSED(arg1);
    UNUSED(arg3);
    return arg2;
}

static char
returnThirdArg(int arg1, char arg2, char arg3)
{
    UNUSED(arg1);
    UNUSED(arg2);
    return arg3;
}

static void
testArgs(void)
{
    ASSERT(returnFirstArg(123, 45, 67) == (int)123);
    ASSERT(returnFirstArg(-123, 45, 67) == (int)-123);

    ASSERT(returnSecondArg(1, -23, 64) == (char)-23);
    ASSERT(returnSecondArg(1, 8, 64) == (char)8);

    ASSERT(returnThirdArg(-33, -34, -35) == (char)-35);
    ASSERT(returnThirdArg(-33, -34, 35) == (char)35);
}

void
__runSuite(void)
{
  __prints("Running testArgs\n");
  testArgs();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_args_type1_int_type3_char_type2_char";
}