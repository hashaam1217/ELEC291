/*
   bug2823963.c
 */

#include "../fwk/include/testfwk.h"

typedef struct xLIST_ITEM
{
	unsigned short xItemValue;
	volatile struct xLIST_ITEM * pxNext;
	volatile struct xLIST_ITEM * pxPrevious;
	void * pvOwner;
	void * pvContainer;
}xListItem;

typedef struct xMINI_LIST_ITEM
{
	unsigned short xItemValue;
	volatile struct xLIST_ITEM *pxNext;
	volatile struct xLIST_ITEM *pxPrevious;
}xMiniListItem;

typedef struct xLIST
{
	volatile unsigned char uxNumberOfItems;
	volatile xListItem * pxIndex;
	volatile xMiniListItem xListEnd;
} xList;

static xList xDelayedTaskList1;

void vListInitialise( xList *pxList )
{
	pxList->pxIndex = ( xListItem * ) &( pxList->xListEnd );
}

void
testBug(void)
{
	void * p = &xDelayedTaskList1.xListEnd;
	vListInitialise( &xDelayedTaskList1 );
	ASSERT (xDelayedTaskList1.pxIndex == p);
}

void
__runSuite(void)
{
  __prints("Running testBug\n");
  testBug();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases_sdcc_bugs\\bug2823963";
}
