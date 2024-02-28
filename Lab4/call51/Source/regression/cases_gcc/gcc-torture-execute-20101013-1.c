/*
   20101013-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// Some ports do not yet support long long
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)

/* PR rtl-optimization/45912 */

static void*
get_addr_base_and_unit_offset (void *base, long long *i)
{
  *i = 0;
  return base;
}

static void*
build_int_cst (void *base, long long offset)
{
  if (offset != 4)
    ASSERT (0);

  return base;
}

static void*
build_ref_for_offset (void *base, long long offset)
{
  long long base_offset;
  base = get_addr_base_and_unit_offset (base, &base_offset);
  return build_int_cst (base, base_offset + offset / 8);
}
#endif

void
testTortureExecute (void)
{
#if 0 // TODO: Renebale when long long integer constants (the 32 below) work!
//#if !defined(__C51_mcs51) && !defined(__C51_hc08) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
  void *ret = build_ref_for_offset ((void *)0, 32);
  if (ret != (void *)0)
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
  return "cases_gcc\\gcc-torture-execute-20101013-1";
}
