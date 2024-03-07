/*
   const-addr-expr-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include        <stdio.h>
#include        <stdlib.h>

#if 0
typedef struct foo
{
        int     uaattrid;
        const char    *name;
} FOO;

FOO     Upgrade_items[] =
{
        {1, "1"},
        {2, "2"},
        {0, NULL}
};

int     *Upgd_minor_ID = 
        (int *) &((Upgrade_items + 1)->uaattrid);

int     *Upgd_minor_ID1 = 
        (int *) &((Upgrade_items)->uaattrid);
#endif

void
testTortureExecute (void)
{
#if 0
	if (*Upgd_minor_ID != 2)
	  ASSERT (0);

	if (*Upgd_minor_ID1 != 1)
	  ASSERT (0);
	return;
#endif
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
  return "cases_gcc\\gcc-torture-execute-const-addr-expr-1";
}