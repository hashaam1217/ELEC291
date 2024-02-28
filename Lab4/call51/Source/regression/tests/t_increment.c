/** Simple test for increment

    type: signed char, int, long
    storage: static, 
    attr: volatile
*/
#include "../fwk/include/testfwk.h"

static void
testIncrement(void)
{
    {attr} {storage} {type} i;
    i = 0;
    i--;
    ASSERT(i == -1);
}
