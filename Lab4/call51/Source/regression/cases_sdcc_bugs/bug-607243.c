/* bad shift right 12 */

#include "../fwk/include/testfwk.h"

typedef unsigned int u16_t;

struct myhdr { u16_t x; } h, *p;

#define NTOHS(n) (((((u16_t)(n) & 0xff)) << 8) | (((u16_t)(n) & 0xff00) >> 8))
#define IPH_V(hdr) ((u16_t)NTOHS((hdr)->x) >> 12)

void testBug(void) {
  p = &h;
  p->x = 0x45;
  ASSERT(IPH_V(p)==4);
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
  return "cases_sdcc_bugs\\bug-607243";
}
