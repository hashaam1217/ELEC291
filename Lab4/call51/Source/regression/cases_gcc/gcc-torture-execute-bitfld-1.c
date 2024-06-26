/*
   bitfld-1-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c89
#endif

/* Copyright 2002 Free Software Foundation, Inc.

   Tests correct signedness of operations on bitfields; in particular
   that integer promotions are done correctly, including the case when
   casts are present.

   The C front end was eliding the cast of an unsigned bitfield to
   unsigned as a no-op, when in fact it forces a conversion to a
   full-width unsigned int. (At the time of writing, the C++ front end
   has a different bug; it erroneously promotes the uncast unsigned
   bitfield to an unsigned int).

   Source: Neil Booth, 25 Jan 2002, based on PR 3325 (and 3326, which
   is a different manifestation of the same bug).
*/

extern void abort ();

void
testTortureExecute (void)
{
  struct x { signed int i : 7; unsigned int u : 7; } mybit;

  unsigned int u;
  int i;
  unsigned int unsigned_result = -13U % 61;
  int signed_result = -13 % 61;

  mybit.u = 61, u = 61; 
  mybit.i = -13, i = -13;

  if (i % u != unsigned_result)
    ASSERT (0);
  if (i % (unsigned int) u != unsigned_result)
    ASSERT (0);

  /* Somewhat counter-intuitively, mybit.u is promoted to an int, making
     the operands and result an int.  */
  if (i % mybit.u != signed_result)
    ASSERT (0);;

  if (mybit.i % mybit.u != signed_result)
    ASSERT (0);

  /* But with a cast to unsigned int, the unsigned int is promoted to
     itself as a no-op, and the operands and result are unsigned.  */
  if (i % (unsigned int) mybit.u != unsigned_result)
    ASSERT (0);

  if (mybit.i % (unsigned int) mybit.u != unsigned_result)
    ASSERT (0);

  return;
}

void
__runSuite(void)
{
  __prints("Running testTortureExecute\n");
  testTortureExecute();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_gcc\\gcc-torture-execute-bitfld-1";
}
