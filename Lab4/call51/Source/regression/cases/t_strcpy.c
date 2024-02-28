/** tests for strcpy
*/
#include "../fwk/include/testfwk.h"
#include <string.h>

static void 
teststrcpy(void)
{
  static char empty[] = "";
  static char string[] = "\1\2\0\3";
  char buf[40] = "abcdefghijklmnopqrstuvwxyz";

  char * result = strcpy(buf, empty);
  ASSERT( strlen(buf) == 0);
  ASSERT( result == buf);

  result = strcpy(buf, string);
  ASSERT( result == buf);
  ASSERT( strlen(buf) == 2);
  ASSERT( buf[0] == '\1');
  ASSERT( buf[1] == '\2');
  ASSERT( buf[3] == 'd');
}

void
__runSuite(void)
{
  __prints("Running teststrcpy\n");
  teststrcpy();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_strcpy";
}
