/*
   20020402-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* derived from PR c/2100 */

#define SMALL_N  2
#define NUM_ELEM 4

void testTortureExecute(void)
{
  int listElem[NUM_ELEM]={30,2,10,5};
  int listSmall[SMALL_N];
  int i, j;
  int posGreatest=-1, greatest=-1;

  for (i=0; i<SMALL_N; i++) { 
    listSmall[i] = listElem[i];
    if (listElem[i] > greatest) {
      posGreatest = i;
      greatest = listElem[i];
    }
  }
  
  for (i=SMALL_N; i<NUM_ELEM; i++) { 
    if (listElem[i] < greatest) {
      listSmall[posGreatest] = listElem[i];
      posGreatest = 0;
      greatest = listSmall[0];
      for (j=1; j<SMALL_N; j++) 
	if (listSmall[j] > greatest) {
	  posGreatest = j;
	  greatest = listSmall[j];
	}
    }
  }

  if (listSmall[0] != 5 || listSmall[1] != 2)
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
  return "cases_gcc\\gcc-torture-execute-20020402-1";
}
