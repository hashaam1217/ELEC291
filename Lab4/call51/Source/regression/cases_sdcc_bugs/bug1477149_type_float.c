/*  bug1477149.c
    multiple definition of local symbol both normal and debug
    second module is fwk/lib/statics.c
    type: long, float
*/

#include "../fwk/include/testfwk.h"

static float float_1 = 2;

static float s_get_float_1(void)
{
	float alfa = float_1;
	float beta = float_1 + alfa;
	float gamma = float_1 + beta;
	return alfa + beta + gamma;
}

/* bug 3038028 */
static char s_get_indexed(char index, char *msg)
{
	/* "float" will put _s_get_indexed_PARM_2 in DSEG,
	 * "long" will put _s_get_indexed_PARM_2 in OSEG
	 */
	float idx = index;
	return msg[(char)(idx+1)];
}

//float get_float_1(void);
//char get_indexed(char index, char *msg);

void testBug(void)
{
	ASSERT (s_get_float_1() == 12);
	//ASSERT (get_float_1() == 6);
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
  return "cases_sdcc_bugs\\bug1477149_type_float";
}
