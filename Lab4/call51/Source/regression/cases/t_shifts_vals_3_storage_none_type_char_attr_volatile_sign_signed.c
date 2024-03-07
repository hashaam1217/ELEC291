/** Tests covering the shift operators.

    sign: signed, unsigned
    type: char, int, long
    storage: static,
    attr: volatile

    vals: 3

    pending - 1792, 851968, 1560281088, -3, -1792, -851968, -1560000000
*/
#include "../fwk/include/testfwk.h"

void
test1ShiftClasses(void)
{
    volatile  signed char i, result;

    i = 30;
    ASSERT(i>>3 == 3);
    ASSERT(i<<2 == 120);

    result = i;
    result >>= 2;
    ASSERT(result == 7);

    result = i;
    result <<= 2;
    ASSERT(result == 120);
}

void
test2ShiftRight(void)
{
    volatile  signed char i, result;

    i = -120;
    ASSERT(i>>1 == -60);
    ASSERT(i>>2 == -30);
    ASSERT(i>>3 == -15);
    ASSERT(i>>4 == -8);
    ASSERT(i>>5 == -4);
    ASSERT(i>>6 == -2);
    ASSERT(i>>7 == -1);
    ASSERT(i>>8 == -1);
    result = i;
    result >>= 3;
    ASSERT(result == -15);
}

void
test3ShiftByteMultiples(void)
{
    volatile  char i;

    i = (char)3;
    ASSERT(i>>8  == (char)(3 >> 8));
    ASSERT(i>>16 == (char)(3 >> 16));
    ASSERT(i>>24 == (char)(3 >> 24));

    i = (char)3;
    ASSERT( (char)(i<<8)  ==  (char)(3 << 8));;
    ASSERT(((char) i<<16) == ((char) 3 << 16));
    ASSERT(((char) i<<24) == ((char) 3 << 24));
}

void
test4ShiftOne(void)
{
    volatile  signed char i;
    signed char result;

    i = (char)3;

    result = i >> 1;
    ASSERT(result == (char)((char)3 >> 1));

    result = i;
    result >>= 1;
    ASSERT(result == (char)((char)3 >> 1));

    result = i << 1;
    ASSERT(result == (char)((char)3 << 1));

    result = i;
    result <<= 1;
    ASSERT(result == (char)((char)3 << 1));
}

static char ShiftLeftByParam (char count)
{
    volatile  char i;
    i = (char)3;
    return (i << count);
}

static char ShiftRightByParam (char count)
{
    volatile  char i;
    i = (char)3;
    return (i >> count);
}

void
testShiftByParam(void)
{
    ASSERT(ShiftLeftByParam(2)  == (char)(3 << 2));
    ASSERT(ShiftRightByParam(2) == (char)(3 >> 2));
}

void
__runSuite(void)
{
  __prints("Running test1ShiftClasses\n");
  test1ShiftClasses();
  __prints("Running test2ShiftRight\n");
  test2ShiftRight();
  __prints("Running test3ShiftByteMultiples\n");
  test3ShiftByteMultiples();
  __prints("Running test4ShiftOne\n");
  test4ShiftOne();
  __prints("Running testShiftByParam\n");
  testShiftByParam();
}

const int __numCases = 5;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_shifts_vals_3_storage_none_type_char_attr_volatile_sign_signed";
}