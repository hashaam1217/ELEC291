/*
   bug1065458.c
*/

#include "../fwk/include/testfwk.h"

unsigned short f()
{
  return 0xff00;
}

unsigned short g()
{
  return f() ? 1 : 0;
}

void
test_1065458(void)
{
  ASSERT( 1 == g() );
}
