/** Tests argument passing to functions via va_args.
    Assumes that up to the first two arguments can be passed in registers.

    type1: va_char, int
    type2: va_char, int
    type3: va_char, int
 */
#include "../fwk/include/testfwk.h"
#include <stdarg.h>

/* gcc 3.3 throws a warning, if char is in '...' */
#if defined(PORT_HOST)
# define va_char int
#else
# define va_char char
#endif

static int
returnFirstArg(int marker, ...)
{
    va_list ap;
    int i;

    va_start(ap, marker);
    i = va_arg(ap, int);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

static int
returnSecondArg(int marker, ...)
{
    va_list ap;
    int i;

    va_start(ap, marker);
    UNUSED(va_arg(ap, int));
    i = va_arg(ap, int);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

static va_char
returnThirdArg(int marker, ...)
{
    va_list ap;
    va_char i;

    va_start(ap, marker);
    UNUSED(va_arg(ap, int));
    UNUSED(va_arg(ap, int));
    i = va_arg(ap, va_char);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

void
testArgs(void)
{
    int marker = 12;

    LOG(("First arg: %u\n", returnFirstArg(marker, (int)123, (int)45, (va_char)67)));
    ASSERT(returnFirstArg(marker, (int)123, (int)45, (va_char)67) == (int)123);
    ASSERT(returnFirstArg(marker, (int)-123, (int)45, (va_char)67) == (int)-123);

    ASSERT(returnSecondArg(marker, (int)1, (int)-23, (va_char)64) == (int)-23);
    ASSERT(returnSecondArg(marker, (int)1, (int)8, (va_char)64) == (int)8);

    ASSERT(returnThirdArg(marker, (int)-33, (int)-34, (va_char)-35) == (va_char)-35);
    ASSERT(returnThirdArg(marker, (int)-33, (int)-34, (va_char)35) == (va_char)35);
}

void
__runSuite(void)
{
  __prints("Running testArgs\n");
  testArgs();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_vaargs_type1_int_type3_va_char_type2_int";
}
