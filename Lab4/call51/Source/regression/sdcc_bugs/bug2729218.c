/** bug2729218.c
*/

#include "../fwk/include/testfwk.h"

/*
  
c51 appears to compile the following file incorrectly.  I have attached
the C source code, and the generated assembly code, with some comments
that explain the bug.

The basic problem is that a memory location is post-incremented, but
the register variable that shadows that memory location is NOT
increment, and this incorrect value is used in later calculations.

I compiled it with these options:

    c51 -mmcs51 --model-small --std-c5199 --code-loc 0xf000 -c bug.c

Here is the "c51 -v" output:

    C51 : mcs51/gbz80/z80/avr/ds390/pic16/pic14/TININative/xa51/ds400/hc08 2.9.1 #5422 (Apr  3 2009) (UNIX)

*/

struct iglobals
{
  unsigned char rx_byte;
  unsigned char input_cnt;
};

#ifndef __C51_gbz80
#define ig (*(__idata struct iglobals *) 0xf0)
#else
struct iglobals ig;
#endif

unsigned char count;

unsigned char
do_command(void)
{
  // In the following statement, the post-increment is saved in
  // memory, but not in the value stored in the r7 register
  count = ig.input_cnt++;

  // In the following statement, the value of "input_cnt" stored in
  // the r7 register is used, but it is wrong (never incremented).
  return ig.input_cnt;
}

void testBug(void)
{
#ifdef __C51
	ig.rx_byte = 0;
	ig.input_cnt = 1;

	ASSERT (do_command() == 2);
	ASSERT (ig.input_cnt == 2);
	ASSERT (count == 1);
#endif
}
