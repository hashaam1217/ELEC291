/*
   string-opt-5.c from the execute part of the gcc torture tests.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c5199
#endif


/* Copyright (C) 2000  Free Software Foundation.

   Ensure builtin strlen, strcmp, strchr, strrchr and strncpy
   perform correctly.

   Written by Jakub Jelinek, 11/7/2000.  */

#include <string.h>

int x = 6;
int y = 1;
const char *bar = "hi world";
idata char buf [64];

void
testTortureExecute (void)
{
  const char *const foo = "hello world";
  idata char dst [64];

  ASSERT (!(strlen (bar) != 8));
  ASSERT (! (strlen (bar + (++x & 2)) != 6));
  ASSERT (! (x != 7));
  ASSERT (! (strlen (foo + (x++, 6)) != 5));
  ASSERT (! (x != 8));
  ASSERT (! (strlen (foo + (++x & 1)) != 10));
  ASSERT (! (x != 9));
  ASSERT (! (strcmp (foo + (x -= 6), "lo world")));
  ASSERT (! (x != 3));
  ASSERT (! (strcmp (foo, bar) >= 0));
  ASSERT (! (strcmp (foo, bar + (x++ & 1)) >= 0));
  ASSERT (! (x != 4));
  ASSERT (! (strchr (foo + (x++ & 7), 'l') != foo + 9));
  ASSERT (! (x != 5));
  ASSERT (! (strchr (bar, 'o') != bar + 4));
  ASSERT (! (strchr (bar, '\0')  != bar + 8));
  ASSERT (! (strrchr (bar, 'x')));
  ASSERT (! (strrchr (bar, 'o') != bar + 4));
  ASSERT (! (strcmp (foo + (x++ & 1), "ello world" + (--y & 1))));
  ASSERT (! (x != 6 || y != 0));
  dst[5] = ' ';
  dst[6] = '\0';
  x = 5;
  y = 1;
  ASSERT (! (strncpy (dst + 1, foo + (x++ & 3), 4) != dst + 1
      || x != 6
      || strcmp (dst + 1, "ello ")) );
  memset (dst, ' ', sizeof dst);
  ASSERT (! (strncpy (dst + (++x & 1), (y++ & 3) + "foo", 10) != dst + 1
      || x != 7
      || y != 2
      || memcmp (dst, " oo\0\0\0\0\0\0\0\0 ", 12)) );
  memset (dst, ' ', sizeof dst);
  ASSERT (! (strncpy (dst, "hello", 8) != dst || memcmp (dst, "hello\0\0\0 ", 9)));
  x = '!';
  memset (buf, ' ', sizeof buf);
  ASSERT (! (memset (buf, x++, ++y) != buf
      || x != '!' + 1
      || y != 3
      || memcmp (buf, "!!!", 3)));
  ASSERT (! (memset (buf + y++, '-', 8) != buf + 3
      || y != 4
      || memcmp (buf, "!!!--------", 11)));
  x = 10;
  ASSERT (! (memset (buf + ++x, 0, y++) != buf + 11
      || x != 11
      || y != 5
      || memcmp (buf + 8, "---\0\0\0", 7)));

  ASSERT (! (memset (buf + (x += 4), 0, 6) != buf + 15
      || x != 15
      || memcmp (buf + 10, "-\0\0\0\0\0\0\0\0\0", 11)));

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
  return "cases_gcc\\gcc-torture-execute-string-opt-5";
}
