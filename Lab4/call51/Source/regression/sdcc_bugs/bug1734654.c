/* bug1734654.c
 */
#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif

#include <stdbool.h>

#ifdef __bool_true_false_are_defined

volatile bool b;
volatile unsigned char c = 1;

static void foo (void)
{
  b = (c<2);
}

#endif //__bool_true_false_are_defined

void
testMyFunc(void)
{
#ifdef __bool_true_false_are_defined
  foo ();
  ASSERT (b);
#endif //__bool_true_false_are_defined
}
