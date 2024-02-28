/** Test the bitwise operators.

    type: char, short, long
    attr: volatile,
    storage: static,
 */
#include "../fwk/include/testfwk.h"

static void
testTwoOpBitwise(void)
{
  static  short left, right;

  left = (short)0x3df7;
  right = (short)0xc1ec;

  ASSERT((short)(left & right) == (short)0x1E4);
  ASSERT((short)(right & left) == (short)0x1E4);
  ASSERT((short)(left & 0xc1ec) == (short)0x1E4);
  ASSERT((short)(0x3df7 & right) == (short)0x1E4);

  ASSERT((short)(left | right) == (short)0xFDFF);
  ASSERT((short)(right | left) == (short)0xFDFF);
  ASSERT((short)(left | 0xc1ec) == (short)0xFDFF);
  ASSERT((short)(0x3df7 | right) == (short)0xFDFF);

  ASSERT((short)(left ^ right) == (short)0xFC1B);
  ASSERT((short)(right ^ left) == (short)0xFC1B);
  ASSERT((short)(left ^ 0xc1ec) == (short)0xFC1B);
  ASSERT((short)(0x3df7 ^ right) == (short)0xFC1B);

#if defined (__alpha__) || defined (__x86_64__)
  /* long is 64 bits on 64 bit machines */
  ASSERT((short)(~left) == (short)0xFFFFFFFFFFFFC208);
#else
  ASSERT((short)(~left) == (short)0xFFFFC208);
#endif
}

void
testAnd(void)
{
  char res;
   int a;

  /* always false if right literal == 0 */
#if 0
  // fails on pic16
  if (a & 0)
    res = 1;
  else
    res = 0;
  ASSERT(res = 0);

  a = 0x1234;

  if (a & 0)
    res = 1;
  else
    res = 0;
  ASSERT(res = 0);
#endif

  /*
   * result: if, left: var, right: literal
   */
  a = 0x1234;

  if (a & 0x4321)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (a & 0x4321)
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a & 0x4321))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  if (!(a & 0x4321))
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 0);

  /* bitmask literal */
  a = 0xffff;

  if (a & 0x1004)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a & 0x1004))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  a = 0x0000;

  if (a & 0x1004)
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  if (!(a & 0x1004))
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  a = 0x00ff;

  if (a & 0x1004)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a & 0x1004))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  a = 0xff00;

  if (a & 0x1004)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a & 0x1004))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  /* literal with zero bytes */
  a = 0x1234;

  if (a & 0x4300)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (a & 0x0012)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a & 0x4300))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  if (!(a & 0x0012))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  /*
   * result: bit, left: var, right: literal
   */
}

void
testOr(void)
{
  char res;
   int a = 0x1234;

  /*
   * result: if, left: var, right: literal
   */
  res = 1;
  if (a | 0x4321)
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a | 0x4321))
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 0);

  if (a | 0x4321)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a | 0x4321))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  /* or with zero: result is left */
  res = 1;

  if (a | 0)
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 1);

  res = 1;

  if (!(a | 0))
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 0);

  if (a | 0)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a | 0))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);
}

void
testXor(void)
{
  char res;
   int a = 0x1234;

  /*
   * result: if, left: var, right: literal
   */
  if (a ^ 0x4321)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (a ^ 0x4321)
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a ^ 0x4321))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  if (!(a ^ 0x4321))
    /* nothing for true */
    ;
  else
    res = 0;
  ASSERT(res == 0);

  /* literal with 0xff bytes */
  if (a ^ 0xff04)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a ^ 0xff04))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);

  /* literal with zero bytes */
  if (a ^ 0x0004)
    res = 1;
  else
    res = 0;
  ASSERT(res == 1);

  if (!(a ^ 0x0004))
    res = 1;
  else
    res = 0;
  ASSERT(res == 0);
}

static void
testBug_1777758(void)
{
  char ep = -1;

  ep &= ~0x80;

  ASSERT(ep == 127);
}

void
__runSuite(void)
{
  __prints("Running testTwoOpBitwise\n");
  testTwoOpBitwise();
  __prints("Running testAnd\n");
  testAnd();
  __prints("Running testOr\n");
  testOr();
  __prints("Running testXor\n");
  testXor();
  __prints("Running testBug_1777758\n");
  testBug_1777758();
}

const int __numCases = 5;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_bitwise_storage_static_type_short_attr_none";
}
