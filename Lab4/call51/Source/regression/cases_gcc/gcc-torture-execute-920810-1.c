/*
   920810-1.c from the execute part of the gcc torture suite.
 */

#include "../fwk/include/testfwk.h"

#ifdef __C51
#pragma std_c99
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{void*super;int name;int size;}t;
t*f(t*clas,int size)
{
  t*child=(t*)malloc(size);
  memcpy(child,clas,clas->size);
  child->super=clas;
  child->name=0;
  child->size=size;
  return child;
}
void
testTortureExecute (void)
{
  t foo,*bar;
  memset(&foo,37,sizeof(t));
  foo.size=sizeof(t);
  bar=f(&foo,sizeof(t));
  if(bar->super!=&foo||bar->name!=0||bar->size!=sizeof(t))ASSERT(0);
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
  return "cases_gcc\\gcc-torture-execute-920810-1";
}
