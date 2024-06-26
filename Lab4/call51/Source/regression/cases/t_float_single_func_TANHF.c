/** Test of float functions with a single float argument

   func: SINF, SINHF, ASINF, COSF, COSHF, ACOSF, TANF, TANHF, ATANF, SQRTF, EXPF, LOGF, LOG10F, FLOORF, CEILF, FABSF
*/

#include "../fwk/include/testfwk.h"
#include <math.h>

#if 0
#   include <stdio.h>
#   define DEBUG(x) x      /* only for "make test-host" */
#   ifdef C51
        void _putchar(char c);
        void putchar(char c)
        {
            _putchar(c);
        }
#   endif
#else
#   define DEBUG(x)
#endif

#define TANHF (1)

#define TOLERANCE (1e-5)

/* now exceptions for targets/functions which would not pass */
#if defined(C51_hc08)
#   define EXPF_DISABLED  (1)
#   define SINHF_DISABLED (1)
#   define TANF_DISABLED  (1)
#endif

#if defined(C51_z80) || defined(C51_gbz80)
#   define ACOSF_DISABLED (1)
#   define ASINF_DISABLED (1)
#   define ATANF_DISABLED (1)
#endif


static float
dummy (float a)
{
  return a;
}

typedef float (*float_test_func)(float) __reentrant;

/* the table with functions, their argument, expected result, tolerance.
   For most 8-bitters each testpoint uses 14 bytes so we could have a few:) */
struct
{
    float_test_func f;
    float arg, result, tolerance;
}
static const testpoint[] =
{

    #if SINF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { sinf,       1.0,                    0.841470984,    TOLERANCE },
    { sinf,      -2.0,                   -0.909297426,    TOLERANCE },
    { sinf,       3.14159265/6.0,         0.5,            TOLERANCE },
    { sinf,       3.14159265+2.0,        -0.909297426,    TOLERANCE },
    #   endif
    #endif
    #if SINHF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { sinhf,      1.0,                    1.175201193,    TOLERANCE },
    { sinhf,     -2.0,                   -3.626860407,    TOLERANCE },
    { sinhf,      3.14159265/6.0,         0.547853473,    TOLERANCE },
    { sinhf,      3.14159265+2.0,        85.49101383,     TOLERANCE },
    #   endif
    #endif
    #if ASINF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { asinf,      0.5,                    3.14159265/6.0, TOLERANCE },
    { asinf,      0.99749498,             1.5,            TOLERANCE },
    { asinf,     -0.84147098,            -1.0,            TOLERANCE },
    { asinf,      0.29552020,             0.3,            TOLERANCE },
    #   endif
    #endif


    #if COSF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { cosf,       1.0,                    0.540302305,    TOLERANCE },
    { cosf,       2.0,                   -0.416146836,    TOLERANCE },
    { cosf,       3.14159265/3.0,         0.5,            TOLERANCE },
    { cosf,       3.14159265+2.0,        +0.416146836,    TOLERANCE },
    #    endif
    #endif
    #if COSHF
    { coshf,      1.0,                    1.543080634,    TOLERANCE },
    { coshf,      2.0,                    3.7621956910,   TOLERANCE },
    { coshf,      3.0,                   10.06766199,     TOLERANCE },
    { coshf,      4.0,                   27.30823283,     TOLERANCE },
    #endif
    #if ACOSF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { acosf,      0.1,                    1.470628905,    TOLERANCE },
    { acosf,      0.5,                    1.047197551,    TOLERANCE },
    { acosf,     -0.9,                    2.690565841,    TOLERANCE },
    { acosf,      0.999,                  0.044725087,    TOLERANCE },
    #   endif
    #endif


    #if TANF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { tanf,       1.0,                    1.557407724,    TOLERANCE },
    { tanf,       2.0,                   -2.18503986,     TOLERANCE },
    { tanf,       -1.5,                 -14.10141994,     TOLERANCE },
    #   endif
    #endif
    #if TANHF
    { tanhf,      1.0,                    0.761594155,    TOLERANCE },
    { tanhf,      3.800201167,            0.999,          TOLERANCE },
    { tanhf,      1.5,                    0.905148253,    TOLERANCE },
    #endif
    #if ATANF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { atanf,      1.0,                    0.7853981633,   TOLERANCE },
    { atanf,      -2.0,                  -1.1071487177,   TOLERANCE },
    { atanf,      42.0,                   1.5469913006,   TOLERANCE },
    #   endif
    #endif


    #if SQRTF
    { sqrtf,      5.0,                    2.23606801,     TOLERANCE },
    { sqrtf,      1522756.0,           1234.0,            TOLERANCE },
    { sqrtf,      10000.0,              100.0,            TOLERANCE },
    #endif


    #if EXPF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { expf,       2.30258509,            10.0,            TOLERANCE },
    { expf,       4.82028150,           124.0,            TOLERANCE },
    { expf,      10.0,                22026.46579,        TOLERANCE },
    #   endif
    #endif
    #if LOGF
    { logf,       2.06115362e-9,        -20.0,            TOLERANCE },
    { logf,      10.0,                    2.30258509,     TOLERANCE },
    { logf,     124.0,                    4.82028150,     TOLERANCE },
    { logf,   22026.46579,               10.0,            TOLERANCE },
    #endif
    #if LOG10F
    { log10f,     0.000001,              -6.0,            TOLERANCE },
    { log10f,     3.16227766e-4,         -3.5,            TOLERANCE },
    { log10f,     3.16227766,             0.5,            TOLERANCE },
    { log10f,    10.0,                    1.0,            TOLERANCE },
    { log10f,    1E6,                     6.0,            TOLERANCE },
    #endif


    #if FLOORF
    #   if TANHF_DISABLED
    #       warning TANHF disabled
    { dummy,      0.0,                    0.0,            TOLERANCE },
    #   else
    { floorf,     1.0+0.000001,           1.0,            TOLERANCE },
    { floorf,     1.0-0.000001,           0.0,            TOLERANCE },
    //{ floorf,   1.0-0.000001,          -0.0,            TOLERANCE }, /* oops */
    //{ dummy,    0.0,                   -0.0,            TOLERANCE }, /* oops */
    { floorf,    -1.0+0.000001,          -1.0,            TOLERANCE },
    { floorf,    -1.0-0.000001,          -2.0,            TOLERANCE },
    #   endif
    #endif


    #if CEILF
    { ceilf,      1.0+0.000001,           2.0,            TOLERANCE },
    { ceilf,      1.0-0.000001,           1.0,            TOLERANCE },
    { ceilf,     -1.0+0.000001,           0.0,            TOLERANCE },
    { ceilf,     -1.0-0.000001,          -1.0,            TOLERANCE },
    #endif


    #if FABSF
    { fabsf,     -1.0e-20,                1.0e-20,        TOLERANCE },
    { fabsf,      9999999,                9999999,        TOLERANCE },
    #endif

};


void
testFloat (void)
{
  unsigned char i;
  float result, rel_error;

  for ( i = 0; i < sizeof testpoint / sizeof testpoint[0]; i++ )
    {
      result = testpoint[i].f (testpoint[i].arg);

      rel_error = testpoint[i].result ? result/testpoint[i].result - 1.0 : result;

      DEBUG (printf ("Test No: %d f(%f) = %f should: %f rel_error: %f %s\n",
                     i, testpoint[i].arg, result, testpoint[i].result, rel_error,
                     (fabsf (rel_error) < testpoint[i].tolerance) ? "Ok" : "Fail");)

      ASSERT (fabsf (rel_error) < testpoint[i].tolerance);
    }
}


void
__runSuite(void)
{
  __prints("Running testFloat\n");
  testFloat();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_float_single_func_TANHF";
}
