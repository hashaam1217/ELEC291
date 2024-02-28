/*
   20030913-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Assignments via pointers pointing to global variables were being killed
   by SSA-DCE.  Test contributed by Paul Brook <paul@nowt.org>  */

int glob; 
 
void 
fn2(int ** q) 
{ 
  *q = &glob; 
} 
 
void test() 
{ 
  int *p; 
 
  fn2(&p); 
 
  *p=42; 
} 
 
void
testTortureExecute (void)
{ 
  test(); 
  if (glob != 42) ASSERT(0); 
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
  return "cases_gcc\\gcc-torture-execute-20030913-1";
}
