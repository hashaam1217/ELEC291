/*
   bug3037889.c
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma disable_warning 88 //no warning about casting LITERAL value to 'generic' pointer
#endif

/* causes error 9: FATAL Compiler Internal Error in file 'C51icode.c' line number '2939' : code generator internal error
   Contact Author with source code
   Internal error: validateLink failed in DCL_TYPE(ptr) @ C51icode.c:2887: expected DECLARATOR, got SPECIFIER
   And on ds390 this further on caused also:
   Internal error: validateOpType failed in OP_SYMBOL(result) @ gen.c:11914: expected symbol, got value */
void Bug3037889 (void)
{
  *((char __xdata *) 0x42e0 - 1) = 1;     /* compiler crashes */
  *((char __xdata *) 0x42e0 + 0) = 1;     /* works fine */
  *((char __xdata *) 0x42e0 + 1) = 1;     /* works fine */
  *((char __xdata *) (0x42e0 + 1)) = 1;     /* works fine */
  *((char __xdata *) (0x42e0 - 1)) = 1;   /* works fine */
}

/* Infinite loop should not be executed, caused:
   Internal error: validateOpType failed in OP_SYMBOL(IC_RESULT (ic)) @ C51loop.c:1024: expected symbol, got value */
void Bug3034976 (void)
{
  while (1)
    {
      *(unsigned char __data *)0 = 0;
    }
}

/* caused error 9: FATAL Compiler Internal Error in file '/C51icode.c' line number '2865' : code generator internal error
   Contact Author with source code
   Internal error: validateLink failed in DCL_TYPE(ptr) @ C51icode.c:2813: expected DECLARATOR, got SPECIFIER */
void Bug3153956 (void)
{
  ((char volatile __xdata *)0)[1] = 0;
}

/*
 * dummy test to be executed, to get rid of regression test warning:
 * Empty function list in ../../../c51/support/regression/tests/bug3037889.c!
 */
void testDummy (void)
{
}

void
__runSuite(void)
{
  __prints("Running testDummy\n");
  testDummy();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug3037889";
}
