/*
   20000605-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

typedef struct _RenderInfo RenderInfo;
struct _RenderInfo
{
    int y;
    float scaley;
    int src_y;
};

static void bar(void) { }

static int
render_image_rgb_a (RenderInfo * info)
{
  int y, ye;
  float error;
  float step;

  y = info->y;
  ye = 256;

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (error >= 1.0) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

void
testTortureExecute (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0;
    info.scaley = 1.0;

    if (render_image_rgb_a(&info) != 256)
       ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20000605-1";
}
