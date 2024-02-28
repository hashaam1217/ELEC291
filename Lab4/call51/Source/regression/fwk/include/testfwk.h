#ifndef __TESTFWK_H
#define __TESTFWK_H   1

#include <mcs51reg.h>
#include <stdlib.h>
#include <stdio.h>

#define REENTRANT __reentrant
#define reentrant __reentrant
#define __asm _asm
#define __endasm _endasm
#define register

#pragma less_pedantic

#define __C51_mcs51 1
#define __C51_WEIRD_BOOL 1
#define _Bool char

int __numTests = 0;
extern const int __numCases;
int __numFailures = 0;

#ifndef NO_VARARGS
void __printf(const char *szFormat, ...);
#define LOG(_a)     __printf _a
#else
#define LOG(_a)     /* hollow log */
#endif

#include <c51-lib.h>

#if defined(PORT_HOST)
# define __data
# define __idata
# define __pdata
# define __xdata
# define __code
# define __near
# define __far
# define __at(x)
# define __reentrant
#endif

void __fail (__code const char *szMsg, __code const char *szCond, __code const char *szFile, int line);
void __prints (const char *s);
void __printn (int n);
__code const char *__getSuiteName (void);
void __runSuite (void);

#define ASSERT(_a)  (++__numTests, (_a) ? (void)0 : __fail ("Assertion failed", #_a, __FILE__, __LINE__))
#define ASSERT_FAILED(_a)  (++__numTests, (_a) ? 0 : (__fail ("Assertion failed", #_a, __FILE__, __LINE__), 1))
#define FAIL()      FAILM("Failure")
#define FAILM(_a)   __fail(_a, #_a, __FILE__, __LINE__)

#ifndef NULL
#define NULL  0
#endif

#define UNUSED(_a)  if (_a) { }

/** Test framework support functions.
 */

#ifndef NO_VARARGS
#include <stdarg.h>
#endif

#ifdef C51_mcs51
#define MEMSPACE_BUF __idata
#else
#define MEMSPACE_BUF
#endif

/** Define this if the port's div or mod functions are broken.
    A slow loop based method will be substituded.
*/
//#define BROKEN_DIV_MOD		1



#if BROKEN_DIV_MOD
static int
__div(int num, int denom)
{
  int q = 0;
  while (num >= denom)
    {
      q++;
      num -= denom;
    }
  return q;
}

static int
__mod (int num, int denom)
{
  while (num >= denom)
    {
      num -= denom;
    }
  return num;
}
#else
#define __div(num, denom) ((num) / (denom))
#define __mod(num, denom) ((num) % (denom))
#endif

void
__prints (const char *s)
{
  char c;

  while ('\0' != (c = *s))
    {
      putchar(c);
      ++s;
    }
}

void
__printn (int n)
{
  if (0 == n)
    {
      putchar('0');
    }
  else
    {
      static char MEMSPACE_BUF buf[6];
      char MEMSPACE_BUF *p = &buf[sizeof (buf) - 1];
      char neg = 0;

      buf[sizeof(buf) - 1] = '\0';

      if (0 > n)
        {
          n = -n;
          neg = 1;
        }
  
      while (0 != n)
        {
          *--p = '0' + __mod (n, 10);
          n = __div (n, 10);
        }

      if (neg)
        putchar('-');

      __prints(p);
    }
}

/* assume P1 for bankswitching address lines */
__sfr __at(0x90) PSBANK;

unsigned char
_c51_external_startup (void)
{
  /* serial port mode 0 is default */
  /* enable transmission of first byte */
  TI = 1;
  return 0;
}


#ifndef NO_VARARGS
void
__printf (const char *szFormat, ...)
{
  va_list ap;
  va_start (ap, szFormat);

  while (*szFormat)
    {
      if (*szFormat == '%')
        {
          switch (*++szFormat)
            {
            case 's':
              {
                char *sz = va_arg (ap, char *);
                __prints(sz);
                break;
              }

            case 'u':
              {
                int i = va_arg (ap, int);
               __printn (i);
               break;
             }

           case '%':
             putchar ('%');
             break;

           default:
             break;
          }
      }
    else
      {
        putchar (*szFormat);
      }
    szFormat++;
  }
  va_end (ap);
}

void
__fail (code const char *szMsg, code const char *szCond, code const char *szFile, int line)
{
  __printf("--- FAIL: \"%s\" on %s at %s:%u\n", szMsg, szCond, szFile, line);
  __numFailures++;
}

int
main (void)
{
  __printf("--- Running: %s\n", __getSuiteName());

  __runSuite();

  __printf("--- Summary: %u/%u/%u: %u failed of %u tests in %u cases.\n",
     __numFailures, __numTests, __numCases,
     __numFailures, __numTests, __numCases
     );

  IE=0;
  return 0;
}
#else
void
__fail (__code const char *szMsg, __code const char *szCond, __code const char *szFile, int line)
{
  __prints("--- FAIL: \"");
  __prints(szMsg);
  __prints("\" on ");
  __prints(szCond);
  __prints(" at ");
  __prints(szFile);
  putchar(':');
  __printn(line);
  putchar('\n');

  __numFailures++;
}

int
main (void)
{
  _initEmu();

  __prints("--- Running: ");
  __prints(__getSuiteName());
  putchar('\n');

  __runSuite();

  __prints("--- Summary: ");
  __printn(__numFailures);
  putchar('/');
  __printn(__numTests);
  putchar('/');
  __printn(__numCases);
  __prints(": ");
  __printn(__numFailures);
  __prints(" failed of ");
  __printn(__numTests);
  __prints(" tests in ");
  __printn(__numCases);
  __prints(" cases.\n");

  IE=0;
  return 0;
}
#endif


#endif //__TESTFWK_H
