/*
   bug3559997.c
*/

#include "../fwk/include/testfwk.h"

#pragma disable_warning 85

typedef struct 
{
        long   i_size;
} s1_t;   

typedef struct {
        s1_t s; 
} i_t, *ip_t;

typedef struct
{
	char *m3;
	long m4;
} mydata_t;

mydata_t mydata;

void f1(char *a, char *p, int b)
{
}

char *f2(int a, int b, char c)
{
	return(0);
}

int f3(char *p, int c)
{
	return(1);
}

void rx(ip_t i)
{
	char *bp = 0;
	int dev = 0;


	bp = f2(dev, 0, 1);
	f1(mydata.m3, bp, 1); 
	if (f3(bp, 2) < 0) 
		return;
	if (mydata.m4 > i->s.i_size)
		i->s.i_size = mydata.m4;
			
}

void testBug(void)
{
	i_t i;
	mydata.m4 = 0xaa55;
	i.s.i_size = 0x55aa;
	rx(&i);
	ASSERT(i.s.i_size == 0xaa55);
}

