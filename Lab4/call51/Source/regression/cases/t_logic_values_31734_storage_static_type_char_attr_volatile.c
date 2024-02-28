/** Tests the basic logical operations.

    type: char, int, long
    storage: static, 
    attr: volatile
    values: 5, 350, 31734
 */
#include "../fwk/include/testfwk.h"

static char
alwaysTrue(void)
{
    return (char)31734;
}

static char
alwaysFalse(void)
{
    return 0;
}

static char
neverGetHere(void)
{
    FAILM("Shouldn't get here");
    return 0;
}

static int hit;

static void
resetGetHere(void)
{
    hit = 0;
}

static char
alwaysGetHere(void)
{
    hit++;
    return 1;
}

static void
testLogicalAnd(void)
{
    char true = alwaysTrue();
    char false = alwaysFalse();

    ASSERT(true && true && true);
    ASSERT(true && !false);
    ASSERT(!false && true);

    /* Test that the evaluation is aborted on the first false. */
    if (true && false && neverGetHere()) {
        /* Tested using neverGetHere() */
    }

    /* Alternate that is similar. */
    if (true && false) {
        neverGetHere();
        /* Tested using neverGetHere() */
    }

    resetGetHere();
    /* Test that the evaluation is done left to right. */
    if (alwaysGetHere() && true && false) {
        ASSERT(hit == 1);
    }
}

static void
testLogicalOr(void)
{
    char true = alwaysTrue();
    char false = alwaysFalse();

    ASSERT(false || false || true);
    ASSERT(!true || !false);
    ASSERT(false || true);

    /* Test that the evaluation is aborted on the first hit. */
    if (false || true || neverGetHere()) {
        /* Tested using neverGetHere() */
    }

    resetGetHere();
    /* Test that the evaluation is done left to right. */
    if (alwaysGetHere() || true || false) {
        ASSERT(hit == 1);
    }
}

static void
testNot(void)
{
    char true = alwaysTrue();
    char false = alwaysFalse();

    ASSERT(!false);
    ASSERT(!!true);
    ASSERT(!!!false);
}

static void
testFlagToVariable(void)
{
    char true = alwaysTrue();
    char false = alwaysFalse();
    char val = !true;

    ASSERT(!val);
    val = !!false;
    ASSERT(!false);
}

void
__runSuite(void)
{
  __prints("Running testLogicalAnd\n");
  testLogicalAnd();
  __prints("Running testLogicalOr\n");
  testLogicalOr();
  __prints("Running testNot\n");
  testNot();
  __prints("Running testFlagToVariable\n");
  testFlagToVariable();
}

const int __numCases = 4;

__code const char *
__getSuiteName(void)
{
  return "cases\\t_logic_values_31734_storage_static_type_char_attr_volatile";
}
