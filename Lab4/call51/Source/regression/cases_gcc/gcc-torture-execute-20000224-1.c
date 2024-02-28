/*
   20000224-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

int loop_1 = 100;
int loop_2 = 7;
int flag = 0;

int test (void)
{
    int i;
    int counter  = 0;

    while (loop_1 > counter) {
        if (flag & 1) {
            for (i = 0; i < loop_2; i++) {
                counter++;
            }
        }
        flag++;
    }
    return 1;
}

void
testTortureExecute (void)
{
    if (test () != 1)
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
  return "cases_gcc\\gcc-torture-execute-20000224-1";
}
