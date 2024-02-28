/* bug-436632.c
   PENDING
*/
#include "../fwk/include/testfwk.h"

typedef struct {
    unsigned char year; /* Current year (with offset 1900) */
    unsigned char month; /* Month (1 = Jan., ..., 12 = Dec.) */
    unsigned char day; /* Day of month (1 to 31) */
} DATE_STRUCT;

unsigned char year;
unsigned char month;
unsigned char day;

void *__main()
{
    float i;
    float y;
    void *p;
    DATE_STRUCT d;
    DATE_STRUCT *date_ptr;

    date_ptr = &d;

    year = date_ptr->year;
    month = date_ptr->month;
    day = date_ptr->day;

    i = 1.35;
    i += 2;
    y = 1;
    y = y+i;
    i = y;
    p = &y;
    return p;
}

void testBug(void)
{
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
  return "cases_sdcc_bugs\\bug-426632";
}
