/*
   960416-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when C51 can pass struct!
#if 0
typedef unsigned long int st;
typedef unsigned long long dt;
typedef union
{
  dt d;
  struct
  {
    st h, l;
  }
  s;
} t_be;

typedef union
{
  dt d;
  struct
  {
    st l, h;
  }
  s;
} t_le;

#define df(f, t) \
int \
f (t afh, t bfh) \
{ \
  t hh; \
  t hp, lp, dp, m; \
  st ad, bd; \
  int s; \
  s = 0; \
  ad = afh.s.h - afh.s.l; \
  bd = bfh.s.l - bfh.s.h; \
  if (bd > bfh.s.l) \
    { \
      bd = -bd; \
      s = ~s; \
    } \
  lp.d = (dt) afh.s.l * bfh.s.l; \
  hp.d = (dt) afh.s.h * bfh.s.h; \
  dp.d = (dt) ad *bd; \
  dp.d ^= s; \
  hh.d = hp.d + hp.s.h + lp.s.h + dp.s.h; \
  m.d = (dt) lp.s.h + hp.s.l + lp.s.l + dp.s.l; \
  return hh.s.l + m.s.l; \
}

df(f_le, t_le)
df(f_be, t_be)
#endif

void
testTortureExecute (void)
{
#if 0
  t_be x;
  x.s.h = 0x10000000U;
  x.s.l = 0xe0000000U;
  if (x.d == 0x10000000e0000000ULL
      && f_be ((t_be) 0x100000000ULL, (t_be) 0x100000000ULL) != -1)
    ASSERT (0);
  if (x.d == 0xe000000010000000ULL
      && f_le ((t_le) 0x100000000ULL, (t_le) 0x100000000ULL) != -1)
    ASSERT (0);
  return;
#endif
}

