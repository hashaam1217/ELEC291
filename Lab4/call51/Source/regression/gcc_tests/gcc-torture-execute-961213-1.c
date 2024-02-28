/*
   961213-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

// TODO: Enable when long long constants are supported!
#if !defined(__C51_mcs51) && !defined(__C51_ds390) && !defined(__C51_pic14) && !defined(__C51_pic16)
int
g (unsigned long long int *v, int n, unsigned int a[], int b)
{
  int cnt;
  *v = 0;
  for (cnt = 0; cnt < n; ++cnt)
    *v = *v * b + a[cnt];
  return n;
}
#endif

void
testTortureExecute (void)
{
#if 0
  int res;
  unsigned int ar[] = { 10, 11, 12, 13, 14 };
  unsigned long long int v;

  res = g (&v, sizeof(ar)/sizeof(ar[0]), ar, 16);
  if (v != 0xabcdeUL)
    ASSERT (0);

  return;
#endif
}

