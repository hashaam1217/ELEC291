/*
   pr34415.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 84
#endif

const char *
foo (const char *p)
{
  const char *end;
  int len = 1;
  for (;;)
    {
      int c = *p;
      c = (c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c);
      if (c == 'B')
	end = p;
      else if (c == 'A')
	{
	  end = p;
	  do
	    p++;
	  while (*p == '+');
	}
      else
	break;
      p++;
      len++;
    }
  if (len > 2 && *p == ':')
    p = end;
  return p;
}

void
testTortureExecute (void)
{
  const char *input = "Bbb:";
  ASSERT (!(foo (input) != input + 2));
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
  return "cases_gcc\\gcc-torture-execute-pr34415";
}
