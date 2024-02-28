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

static va_char
returnFirstArg(int marker, ...)
{
    va_list ap;
    va_char i;

    va_start(ap, marker);
    i = va_arg(ap, va_char);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

static va_char
returnSecondArg(int marker, ...)
{
    va_list ap;
    va_char i;

    va_start(ap, marker);
    UNUSED(va_arg(ap, va_char));
    i = va_arg(ap, va_char);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

static int
returnThirdArg(int marker, ...)
{
    va_list ap;
    int i;

    va_start(ap, marker);
    UNUSED(va_arg(ap, va_char));
    UNUSED(va_arg(ap, va_char));
    i = va_arg(ap, int);

    va_end(ap);

    LOG(("Returning %u\n", i));
    return i;
}

void
testArgs(void)
{
    int marker = 12;

    LOG(("First arg: %u\n", returnFirstArg(marker, (va_char)123, (va_char)45, (int)67)));
    ASSERT(returnFirstArg(marker, (va_char)123, (va_char)45, (int)67) == (va_char)123);
    ASSERT(returnFirstArg(marker, (va_char)-123, (va_char)45, (int)67) == (va_char)-123);

    ASSERT(returnSecondArg(marker, (va_char)1, (va_char)-23, (int)64) == (va_char)-23);
    ASSERT(returnSecondArg(marker, (va_char)1, (va_char)8, (int)64) == (va_char)8);

    ASSERT(returnThirdArg(marker, (va_char)-33, (va_char)-34, (int)-35) == (int)-35);
    ASSERT(returnThirdArg(marker, (va_char)-33, (va_char)-34, (int)35) == (int)35);
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
  return "cases\\t_vaargs_type1_va_char_type3_int_type2_va_char";
}
