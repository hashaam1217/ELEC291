/*
   bug1496419.c
*/

#include "../fwk/include/testfwk.h"
#include <stddef.h>

typedef struct _NODE
{
  const struct _NODE * enter;
  const struct _NODE * down;
}NODE;

const NODE node1 = {NULL, NULL};

//c51 loops allocating space for new symbols node1 and
//zzz until there is no more memory, then segfaults
//
//The reference to zzz inside the declaration of zzz
//triggers a loop allocating space for symbols node1
//and zzz
const NODE zzz = {&node1, &zzz};

void testBug(void)
{
}
