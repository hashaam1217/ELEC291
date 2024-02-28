/*
   20021015-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#pragma disable_warning 85

/* PR opt/7409.  */

char g_list[] = { '1' };

void g (void *p, char *list, int length, char **elementPtr, char **nextPtr)
{
  if (*nextPtr != g_list)
    ASSERT (0);

  **nextPtr = 0;
}

void testTortureExecute (void)
{
  char *list = g_list;
  char *element;
  int i, length = 100;

  for (i = 0; *list != 0; i++) 
    {
      char *prevList = list;
      g (0, list, length, &element, &list);
      length -= (list - prevList);
    }

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
  return "cases_gcc\\gcc-torture-execute-20021015-1";
}
