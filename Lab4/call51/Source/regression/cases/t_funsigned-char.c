/*
 * check for the correct signness of a char constant
 *   (signed versus unsigned)
 *   (indirect via integer promotion)
 *
 * Note, the check for the --funsigned-char must be invoked by hand
 *   see the following emacs sexp
 *     (compile "C51FLAGS=--funsigned-char make -C .. ALL_TESTS='./tests/funsigned-char.c'")
 *     (compile "make -C .. ALL_TESTS='./tests/funsigned-char.c'")
 *
 */

#include "../fwk/include/testfwk.h"
#include <stdint.h>
#include <limits.h>

int glb_schar_to_int = ~ (signed char)   '\200';
int glb_uchar_to_int = ~ (unsigned char) '\200';
int glb_char_to_int  = ~                 '\200';

int tst_schar_to_int()  { return ~ (signed char)   '\200'; }
int tst_uchar_to_int()  { return ~ (unsigned char) '\200'; }
int tst_char_to_int()   { return ~                 '\200'; }


void
testBug(void)
{
#ifdef C51_CHAR_UNSIGNED
  ASSERT(CHAR_MAX ==  255);
  ASSERT(CHAR_MIN ==    0);
#else
  ASSERT(CHAR_MAX ==  127);
  ASSERT(CHAR_MIN == -128);
#endif

  ASSERT(tst_uchar_to_int() == -129);
  ASSERT(glb_uchar_to_int   == -129);

  ASSERT(tst_schar_to_int() ==  127);
  ASSERT(glb_schar_to_int   ==  127);

#ifdef C51_CHAR_UNSIGNED
  ASSERT(tst_char_to_int() == -129);
  ASSERT(glb_char_to_int   == -129);
#else
  ASSERT(tst_char_to_int() ==  127);
  ASSERT(glb_char_to_int   ==  127);
#endif
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
  return "cases\\t_funsigned-char";
}
