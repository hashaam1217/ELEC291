/** Tests the basic logical operations.

    type: char, int, long
    storage: static, 
    attr: volatile
    values: 5, 350, 31734
 */
#include "../fwk/include/testfwk.h"

static int
alwaysTrue(void)
{
    return (int)350;
}

static int
alwaysFalse(void)
{
    return 0;
}

static int
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

static int
alwaysGetHere(void)
{
    hit++;
    return 1;
}

static void
testLogicalAnd(void)
{
    int true = alwaysTrue();
    int false = alwaysFalse();

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
    int true = alwaysTrue();
    int false = alwaysFalse();

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
    int true = alwaysTrue();
    int false = alwaysFalse();

    ASSERT(!false);
    ASSERT(!!true);
    ASSERT(!!!false);
}

static void
testFlagToVariable(void)
{
    int true = alwaysTrue();
    int false = alwaysFalse();
    int val = !true;

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
  return "cases\\t_logic_values_350_storage_static_type_int_attr_volatile";
}
