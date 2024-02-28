/** Null character in string tests.

     storage: __data, __xdata, __code,
*/
#include "../fwk/include/testfwk.h"

#ifndef PORT_HOST
#pragma disable_warning 147 //no warning about excess elements in array of chars initializer
#endif

 char string1[] = "";
 char string2[] = "a\0b\0c";
 char string3[5] = "a\0b\0c";

void
testStringArray (void)
{
  /* Make sure the strings are the correct size */
  /* and have the terminating null character */
  ASSERT (sizeof (string1) == 1);
  ASSERT (sizeof (string2) == 6);
  ASSERT (sizeof (string3) == 5);
  ASSERT (string1[0] == 0);
  ASSERT (string2[5] == 0);

  ASSERT (string2[0]== 'a');
  ASSERT (string2[2]== 'b');
  ASSERT (string2[4]== 'c');

}

void
testStringConst (void)
{
  const char * constStr1 = "";
  const char * constStr2 = "a\0b\0c";

  ASSERT (constStr1[0] == 0);
  ASSERT (constStr2[5] == 0);
}

void
__runSuite(void)
{
  __prints("Running testStringArray\n");
  testStringArray();
  __prints("Running testStringConst\n");
  testStringConst();
}

const int __numCases = 2;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_nullstring_storage_none";
}
