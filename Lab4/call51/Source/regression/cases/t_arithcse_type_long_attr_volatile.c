/* Test arithmetic CSE with /+-*

    type: char, short, long
    attr: volatile,
 */

#include "../fwk/include/testfwk.h"

void
test_arithCse(void)
{
  volatile long res;
  volatile long i = 10;

  /* addition with 0 */
  res = i + 0;
  ASSERT (i == 10);

  res = 0 + i;
  ASSERT (res == 10);

  /* multiplication with 1 */
  res = 1 * i;
  ASSERT (res == 10);

  res = i * 1;
  ASSERT (res == 10);

  /* multiplication with 0 */
  res = 0 * i;
  ASSERT (res == 0);

  res = i * 0;
  ASSERT (res == 0);

  /* multiplication with -1 */
  res = -1 * i;
  ASSERT (res == (long)-i);

  res = i * -1;
  ASSERT (res == (long)-i);

  /* division by 1 */
  res = i / 1;
  ASSERT (res == i);

  /* division by -1 */
  res = i / -1;
  ASSERT (res == (long)-i);
}

void
__runSuite(void)
{
  __prints("Running test_arithCse\n");
  test_arithCse();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_arithcse_type_long_attr_volatile";
}
