/*
   980506-3.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#ifndef __C51_mcs51
#include <string.h>

unsigned char lookup_table [257];

static int 
build_lookup (unsigned char * pattern)
{
  int m;

  m = strlen (pattern) - 1;
  
  memset (lookup_table, ++m, 257);
  return m;
}
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  if (build_lookup ("bind") != 4)
    ASSERT (0);
  else
    return;
#endif
}
