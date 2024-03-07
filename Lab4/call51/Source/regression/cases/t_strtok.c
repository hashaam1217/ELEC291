/** tests for strtok
*/
#include "../fwk/include/testfwk.h"
#include <string.h>

static void
teststrtok(void)
{
  static char str[] = "?a???b,,,#c";
  char str2[] = "axaaba";
  char *token = strtok(str, "?"); // 'token' points to the token "a"
  ASSERT( token == &str[1] && 0 == strcmp(token,"a"));
  token = strtok(NULL, ","); // 'token' points to the token "??b"
  ASSERT( token == &str[3]&& 0 == strcmp(token,"??b"));
  token = strtok(NULL, "#,"); // 'token' points to the token "c"
  ASSERT( token == &str[10] && 0 == strcmp(token,"c"));
  token = strtok(NULL, "?"); // 'token' is a null pointer
  ASSERT( token == NULL);

  token = strtok (str2, "ab");
  ASSERT( token && 0 == strcmp (token, "x"));
  token = strtok(NULL, "ab");
  ASSERT( token == NULL);
#ifndef __SUNPRO_C
  /* SunPro C compiler has problem with strtok-ing after NULL */
  token = strtok(NULL, "a");
  ASSERT( token == NULL);
#endif
}

void
__runSuite(void)
{
  __prints("Running teststrtok\n");
  teststrtok();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_strtok";
}