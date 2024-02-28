/*  An assignment inside a functioncall changed the type of the parameter.
    See bug description 1273984 for details.

    Bug detected and fixed by Guenther Jehle

    sign: unsigned,
 */

#include "../fwk/include/testfwk.h"

void foo( int val) {
  val; //make the compiler happy
}

void fooInt( int val) {
  ASSERT(val==3);
}

void fooChar( char val) {
  ASSERT(val==6);
}

void
testAssignInFunctioncall(void)
{
  volatile  char charVal=3;
  volatile  int intVal=0x4040;

  fooInt(intVal=charVal); // should cast charVal to int for function call.
                          // without patch #1645121, a char is put on the stack
                          // (or hold in registers)
  foo(0xAAAA);
  fooInt(intVal=charVal);

  intVal=6;

  fooChar(charVal=intVal); // without patch, a int is put on the stack
  foo(0xAAAA);
  fooChar(charVal=intVal);

}



void
__runSuite(void)
{
  __prints("Running testAssignInFunctioncall\n");
  testAssignInFunctioncall();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug1273984_sign_none";
}
