/*
   20020716-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int sub1 (int val)
{
  return val;
}

int testcond (int val)
{
  int flag1;

    {
      int t1 = val;
        {
          int t2 = t1;
            {
              flag1 = sub1 (t2) ==0;
              goto lab1;
            };
        }
      lab1: ;
    }

  if (flag1 != 0)
    return 0x4d0000;
  else
    return 0;
}

void testTortureExecute (void)
{
  if (testcond (1))
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
  return "cases_gcc\\gcc-torture-execute-20020716-1";
}
