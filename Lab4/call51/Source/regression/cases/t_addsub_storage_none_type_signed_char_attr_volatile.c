/** Add, sub tests.

    type: signed char, int, long
    storage: static, 
    attr: volatile
*/
#include "../fwk/include/testfwk.h"

void 
testAdd(void)
{
   volatile signed char left, right, result;

  left = 5;
  right = 26;

  result = left+right;
  ASSERT(result == 31);
  
  left = 39;
  right = -120;
  
  result = left+right;
  ASSERT(result == (39-120));

  left = -39;
  right = 80;
  
  result = left+right;
  ASSERT(result == (-39+80));

  left = -39;
  right = -70;
  
  result = left+right;
  ASSERT(result == (-39-70));

  result += 0xab00;
  ASSERT(result == (signed char)(0xab00-39-70));
}

void 
testSub(void)
{
   volatile signed char left, right, result;

  left = 5;
  right = 26;

  result = left-right;
  ASSERT(result == (5-26));
  
  left = 39;
  right = -76;
  
  result = left-right;
  ASSERT(result == (39+76));

  left = -12;
  right = 56;
  
  result = left-right;
  ASSERT(result == (-12-56));
  
  left = -39;
  right = -20;
  
  result = left-right;
  ASSERT(result == (-39+20));

  result = left-(signed)0x1200;
  ASSERT(result == (signed char)(-39-(signed)0x1200));
}

void
__runSuite(void)
{
  __prints("Running testAdd\n");
  testAdd();
  __prints("Running testSub\n");
  testSub();
}

const int __numCases = 2;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_addsub_storage_none_type_signed_char_attr_volatile";
}
