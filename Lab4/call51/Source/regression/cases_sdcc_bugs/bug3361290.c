/*
    bug 3361290
*/

#include "../fwk/include/testfwk.h"

unsigned volatile char rWatchDog, _bTimer;
#define FALSE 0

void KickDog()
{
rWatchDog |= 0x08; // kick dog
}


void _MiniRun()
{
if (_bTimer)
{
_bTimer = FALSE;
}
KickDog();
}

void
testBug(void)
{
	ASSERT(1);
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
  return "cases_sdcc_bugs\\bug3361290";
}
