/*
   20021111-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

/* Origin: PR c/8467 */

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type);

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type)
{
  static int i = 0;

  if (!conn)
    return 0;

  if (type == 0xffff)
    {
      return 0;
    }

  if (i >= 1)
    ASSERT (0);

  i++;
  return aim_callhandler(sess, conn, family, (unsigned short) 0xffff);
}

void testTortureExecute (void)
{
  aim_callhandler (0, 1, 0, 0);
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
  return "cases_gcc\\gcc-torture-execute-20021111-1";
}
