/*
   990804-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int gfbyte ( void ) 
{
 return 0;
} 

void
testTortureExecute (void)
{
 int i,j,k ;

 i = gfbyte();

 i = i + 1 ;

 if ( i == 0 ) 
     k = -0 ;
 else
     k = i + 0 ;

 if (i != 1)
   ASSERT (0);

 k = 1 ;
 if ( k <= i)
     do 
	 j = gfbyte () ;
     while ( k++ < i ) ;

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
  return "cases_gcc\\gcc-torture-execute-990804-1";
}
