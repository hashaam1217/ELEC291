/*
   20001101-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 88
#endif
			 
typedef struct
{
  unsigned int unchanging : 1;
} struc, *rtx;

rtx dummy ( int *a, rtx *b)
{
  *a = 1;
  *b = (rtx)7;
  return (rtx)1;
}

void bogus (rtx insn, rtx thread, rtx delay_list)
{
  rtx new_thread;
  int must_annul;

  delay_list = dummy ( &must_annul, &new_thread);
  if (delay_list == 0 &&  new_thread )
    {
      thread = new_thread;
    }
  if (delay_list && must_annul)
    insn->unchanging = 1;
  if (new_thread != thread )
    ASSERT (0);
}

void
testTortureExecute (void)
{
  struc baz;
  bogus (&baz, (rtx)7, 0);
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
  return "cases_gcc\\gcc-torture-execute-20001101";
}
