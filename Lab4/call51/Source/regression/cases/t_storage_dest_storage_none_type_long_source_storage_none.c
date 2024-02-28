/** Tests many of the basic operators from each of the storage types to every other.

    source_storage: static, register,
    dest_storage: static, register, 
    type: char, int, long
 */
#include "../fwk/include/testfwk.h"

/** Simple function that spoils c51's optimiser by hiding an assign.
 */
long
spoilAssign(long in)
{
    return in;
}

void
testStorageTypes(void)
{
     long source;
     long dest;

    source = spoilAssign(17);
    // Test compare against a const
    ASSERT(source == 17);

    dest = spoilAssign(126);
    ASSERT(dest == 126);
    ASSERT(dest != source);

    // Test assignment
    dest = source;
    ASSERT(dest == source);

    // Test cmp
    dest--;
    ASSERT(dest == 16);
    ASSERT(dest < source);
    
    dest += 8;
    ASSERT(dest == 24);
    ASSERT(source < dest);
}

void
__runSuite(void)
{
  __prints("Running testStorageTypes\n");
  testStorageTypes();
}

const int __numCases = 1;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_storage_dest_storage_none_type_long_source_storage_none";
}
