/* bug-223113.c
   PENDING
 */
#include "../fwk/include/testfwk.h"

int putch( int Ch )
{
  return( Ch );
}

int puts( const char *Str )
{
  const char *Ptr;

  for( Ptr = Str; *Ptr != '\0'; Ptr++ ) {
    putch( *Ptr );
  }

  return( (Ptr - Str) );
}

void __main( void )
{
  puts( "hello world\n" );
}

void testBug(void)
{
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
  return "cases_sdcc_bugs\\bug-223113";
}
