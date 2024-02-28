/*  bug1477149.c
    multiple definition of local symbol both normal and debug
    second module is fwk/lib/statics.c
    type: long, float
*/

#include "../fwk/include/testfwk.h"

static long long_1 = 2;

static long s_get_long_1(void)
{
	long alfa = long_1;
	long beta = long_1 + alfa;
	long gamma = long_1 + beta;
	return alfa + beta + gamma;
}

/* bug 3038028 */
static char s_get_indexed(char index, char *msg)
{
	/* "float" will put _s_get_indexed_PARM_2 in DSEG,
	 * "long" will put _s_get_indexed_PARM_2 in OSEG
	 */
	long idx = index;
	return msg[(char)(idx+1)];
}

//long get_long_1(void);
//char get_indexed(char index, char *msg);

void testBug(void)
{
	ASSERT (s_get_long_1() == 12);
	//ASSERT (get_long_1() == 6);
	ASSERT (s_get_indexed(1, "One") == 'e');
	//ASSERT (get_indexed(1, "One") == 'n');
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
  return "cases_sdcc_bugs\\bug1477149_type_long";
}
