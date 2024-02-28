/** Test register bank allocation for the "using" keyword.
*/
#include "../fwk/include/testfwk.h"

#if defined (C51_mcs51) && defined (C51_MODEL_SMALL)
  __data char array[8];

  void
  my_isr (void) __interrupt (1) __using (1)
  {
    array[array[0]] = 1; //generate some register pressure
  }
#endif

void
testUsing (void)
{
#if defined (C51_mcs51) && defined (C51_MODEL_SMALL)
  ASSERT ((unsigned char)(&array[0]) >= 0x10);
  ASSERT ((unsigned char)&__numTests >= 0x10);
#endif
}
