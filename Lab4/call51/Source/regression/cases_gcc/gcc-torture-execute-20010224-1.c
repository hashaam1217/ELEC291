/*
   20010224-1.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#pragma disable_warning 85
#endif

#include <stdint.h>

int16_t logadd (int16_t *a, int16_t *b);
void ba_compute_psd (int16_t start);

int16_t masktab[6] = { 1, 2, 3, 4, 5};
int16_t psd[6] = { 50, 40, 30, 20, 10};
int16_t bndpsd[6] = { 1, 2, 3, 4, 5};

void ba_compute_psd (int16_t start)
{
  int i,j,k;
  int16_t lastbin = 4;

  j = start; 
  k = masktab[start]; 

  bndpsd[k] = psd[j]; 
  j++; 

  for (i = j; i < lastbin; i++) { 
    bndpsd[k] = logadd(&bndpsd[k], &psd[j]);
    j++; 
  } 
}

int16_t logadd (int16_t *a, int16_t *b)
{
  return *a + *b;
}

void
testTortureExecute (void)
{
#if !defined (__C51_z80) && !defined (__C51_z180) && !defined (__C51_r2k) && !defined (__C51_r3ka) && !defined (__C51_gbz80)
  int i;

  ba_compute_psd (0);

  if (bndpsd[1] != 140) ASSERT (0);
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
  return "cases_gcc\\gcc-torture-execute-20010224-1";
}
