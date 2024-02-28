/*  Make sure global common subexpression optimization does not
    inappropriately cache values across function calls.

    sign1: signed, unsigned
    sign2: signed, unsigned
    type: int

 */
#include "../fwk/include/testfwk.h"

typedef struct
{
  unsigned int field1;
  unsigned int *field2;
  unsigned int field3;
} struct1;
  

void
spoil(unsigned int val)
{
  UNUSED(val);
}

void
inc1(unsigned int *valptr)
{
  (*valptr)++;
}

signed
gcse1(signed int target)
{
  spoil(target);
  inc1(&target);
  return target;
}


void
inc2(struct1 *s)
{
  (*s->field2)++;
}

signed
gcse2(signed int target)
{
  struct1 s;
  
  s.field2 = &s.field3;
  *s.field2 = target;
  spoil(s.field3);
  inc2(&s);
  return s.field3;
}


void
testgcse(void)
{
  ASSERT(gcse1(1)==2);
  ASSERT(gcse2(1)==2);
}

void
__runSuite(void)
{
  __prints("Running testgcse\n");
  testgcse();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug-1029883_type_int_sign1_unsigned_sign2_signed";
}
