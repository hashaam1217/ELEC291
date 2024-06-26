/*
   20051110-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

void add_unwind_adjustsp (long);

unsigned char bytes[5];

int flag;

void
add_unwind_adjustsp (long offset)
{
  int n;
  unsigned long o;

  o = (long) ((offset - 0x204) >> 2);

  n = 0;
  do
    {
a:
      bytes[n] = o & 0x7f;
      o >>= 7;
      if (o)
        {
	  bytes[n] |= 0x80;
	  if (flag)
	    goto a;
	}
      n++;
    }
  while (o);
}

void testTortureExecute(void)
{
  add_unwind_adjustsp (4132);
  if (bytes[0] != 0x88 || bytes[1] != 0x07)
    ASSERT (0);
  return;
}
