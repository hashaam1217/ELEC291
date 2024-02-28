/*
   cmpsf-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <limits.h>
#include <float.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (x == y)
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (x != y)
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (x < y)
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (x >= y)
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (x > y)
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (x <= y)
    return T;
  else
    return F;
}

float args[] =
{
  0.0F,
  1.0F,
  -1.0F, 
  FLT_MAX,
  FLT_MIN,
  0.0000000000001F,
  123456789.0F,
  -987654321.0F
};

#ifndef __C51_mcs51

int correct_results[] =
{
 T, F, F, T, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, F, T, T, F,                                             
 T, F, F, T, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, T, F, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, F, T, T, F,                                             
 F, T, T, F, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 T, F, F, T, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, T, F, F, T,                                             
 F, T, F, T, T, F,                                             
 F, T, F, T, T, F,                                             
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 T, F, F, T, F, T,
};
#endif

void
testTortureExecute (void)
{
#ifndef __C51_mcs51
  int i, j, *res = correct_results;

  for (i = 0; i < 8; i++)
    {
      float arg0 = args[i];
      for (j = 0; j < 8; j++)
	{
	  float arg1 = args[j];

	  if (feq (arg0, arg1) != *res++)
	    ASSERT (0);
	  if (fne (arg0, arg1) != *res++)
	    ASSERT (0);
	  if (flt (arg0, arg1) != *res++)
	    ASSERT (0);
	  if (fge (arg0, arg1) != *res++)
	    ASSERT (0);
	  if (fgt (arg0, arg1) != *res++)
	    ASSERT (0);
	  if (fle (arg0, arg1) != *res++)
	    ASSERT (0);
	}
    }
#endif
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
  return "cases_gcc\\gcc-torture-execute-cmpsf-1";
}
