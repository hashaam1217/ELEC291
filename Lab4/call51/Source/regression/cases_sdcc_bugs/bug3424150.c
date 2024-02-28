/*
   bug3424150.c
*/

#include "../fwk/include/testfwk.h"

unsigned char _pInputBuf[80];
unsigned char _iInputPos;

void OnEditCancel()
{
	if (!_pInputBuf[_iInputPos] && _iInputPos)	
	{
		_iInputPos --;
	}
	_pInputBuf[_iInputPos] = 0;
}

void
testBug(void)
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
  return "cases_sdcc_bugs\\bug3424150";
}
