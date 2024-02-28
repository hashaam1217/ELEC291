/*
   950607-2.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 supports struct parameters!
#if 0
typedef struct {
  long int p_x, p_y;
} Point;

int
f (Point basePt, Point pt1, Point pt2)
{
  long long vector;

  vector =
    (long long) (pt1.p_x - basePt.p_x) * (long long) (pt2.p_y - basePt.p_y) -
      (long long) (pt1.p_y - basePt.p_y) * (long long) (pt2.p_x - basePt.p_x);

  if (vector > (long long) 0)
    return 0;
  else if (vector < (long long) 0)
    return 1;
  else
    return 2;
}
#endif

void
testTortureExecute (void)
{
#if 0
  Point b, p1, p2;
  int answer;

  b.p_x = -23250;
  b.p_y = 23250;

  p1.p_x = 23250;
  p1.p_y = -23250;

  p2.p_x = -23250;
  p2.p_y = -23250;

  answer = f (b, p1, p2);

  if (answer != 1)
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
  return "cases_gcc\\gcc-torture-execute-950607-2";
}
