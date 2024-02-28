/* Tests an uninitalised variable bug.
   t is not initalised in all paths in the do loop, causing the while
   conditional to fail unpredictably.

   Doesn't actually test, is really an example.
 */
#include "../fwk/include/testfwk.h"

typedef unsigned char UBYTE;

UBYTE
randish(void)
{
  static int count;

  if ((++count)&3) {
    return 1;
  }
  else {
    return 0;
  }
}

void
spoil(UBYTE ignored)
{
  UNUSED(ignored);
}

UBYTE accu[2];

#if !defined(PORT_HOST)
#  pragma disable_warning 84
#endif

void 
testLoopInit(void)
{
  UBYTE t, r;

  do {
    r = randish();

    if(r != 1) {
      t = ++accu[r];
      spoil(t);
    }
  }
  while(t != 3);
}

void
__runSuite(void)
{
  __prints("Running testLoopInit\n");
  testLoopInit();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-477927";
}
