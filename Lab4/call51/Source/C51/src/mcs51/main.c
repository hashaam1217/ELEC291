/** @file main.c
    mcs51 specific general functions.

    Note that mlh prepended _mcs51_ on the static functions.  Makes
    it easier to set a breakpoint using the debugger.
*/
#include "common.h"
#include "main.h"
#include "ralloc.h"
#include "gen.h"
#include "peep.h"
#include "dbuf_string.h"
#include "../C51util.h"

static char _defaultRules[] =
{
#include "peeph.rul"
};

#define OPTION_STACK_SIZE       "--stack-size"

static OPTION _mcs51_options[] =
{
    { 0, OPTION_STACK_SIZE,  &options.stack_size, "Tells the linker to allocate this space for stack", CLAT_INTEGER },
    { 0, "--parms-in-bank1", &options.parms_in_bank1, "use Bank1 for parameter passing"},
    { 0, "--pack-iram",      NULL, "Tells the linker to pack variables in internal ram (default)"},
    { 0, "--no-pack-iram",   &options.no_pack_iram, "Tells the linker not to pack variables in internal ram"},
    { 0, "--acall-ajmp",     &options.acall_ajmp, "Use acall/ajmp instead of lcall/ljmp" },
    { 0, NULL }
};

/* list of key words used by msc51 */
static char *_mcs51_keywords[] =
{
    "at",
    "banked",
    "bit",
    "code",
    "critical",
    "data",
    "far",
    "idata",
    "interrupt",
    "near",
    "pdata",
    "reentrant",
    "sfr",
    "sfr16",
    "sfr32",
    "sbit",
    "using",
    "xdata",
    "_data",
    "_code",
    "_generic",
    "_near",
    "_xdata",
    "_pdata",
    "_idata",
    "_naked",
    "_overlay",
   NULL
};

void mcs51_assignRegisters (ebbIndex *);

static int regParmFlg = 0;      /* determine if we can register a parameter     */
static int regBitParmFlg = 0;   /* determine if we can register a bit parameter */

static void
_mcs51_init (void)
{
    asm_addTree (&asm_a51_mapping);
}

static void
_mcs51_reset_regparm (void)
{
    regParmFlg = 0;
    regBitParmFlg = 0;
}

static int
_mcs51_regparm (sym_link * l, bool reentrant)
{
    if (IS_SPEC(l) && (SPEC_NOUN(l) == V_BIT))
    {
        /* bit parameters go to b0 thru b7 */
        if (reentrant && (regBitParmFlg < 8))
        {
            regBitParmFlg++;
            return 12 + regBitParmFlg;
        }
        return 0;
    }
    if (options.parms_in_bank1 == 0)
    {
        /* simple can pass only the first parameter in a register */
        if (regParmFlg)
            return 0;

        regParmFlg = 1;
        return 1;
    }
    else
    {
        int size = getSize(l);
        int remain ;

        /* first one goes the usual way to DPTR */
        if (regParmFlg == 0)
        {
            regParmFlg += 4 ;
            return 1;
        }
        /* second one onwards goes to RB1_0 thru RB1_7 */
        remain = regParmFlg - 4;
        if (size > (8 - remain))
        {
            regParmFlg = 12 ;
            return 0;
        }
        regParmFlg += size ;
        return regParmFlg - size + 1;
    }
}

static bool
_mcs51_parseOptions (int *pargc, char **argv, int *i)
{
    /* TODO: allow port-specific command line options to specify
     * segment names here.
     */
    return FALSE;
}

static void
_mcs51_finaliseOptions (void)
{
    if (options.noXinitOpt)
        port->genXINIT=0;

    switch (options.model)
    {
    case MODEL_SMALL:
        port->mem.default_local_map = data;
        port->mem.default_globl_map = data;
        port->s.gptr_size = 3;
        break;
    case MODEL_MEDIUM:
        port->mem.default_local_map = pdata;
        port->mem.default_globl_map = pdata;
        port->s.gptr_size = 3;
        break;
    case MODEL_LARGE:
        port->mem.default_local_map = xdata;
        port->mem.default_globl_map = xdata;
        port->s.gptr_size = 3;
        break;
    default:
        port->mem.default_local_map = data;
        port->mem.default_globl_map = data;
        break;
    }

    if (options.parms_in_bank1)
        addSet(&preArgvSet, Safe_strdup("-DC51_PARMS_IN_BANK1"));

    /* mcs51 has an assembly coded float library that's always reentrant */
    options.float_rent = 1;

    /* set up external stack location if not explicitly specified */
    if (!options.xstack_loc)
        options.xstack_loc = options.xdata_loc;
}

static void
_mcs51_setDefaultOptions (void)
{
}

static const char *
_mcs51_getRegName (struct regs *reg)
{
    if (reg)
        return reg->name;
    return "err";
}

static void
_mcs51_genAssemblerPreamble (FILE * of)
{
    if (options.parms_in_bank1)
    {
        int i;
        for (i=0; i < 8 ; i++ )
            fprintf (of,"b1_%d = 0x%x \n",i,8+i);
    }
}

/* Generate interrupt vector table. */
static int _mcs51_genIVT (struct dbuf_s * oBuf, symbol ** interrupts, int maxInterrupts)
{
    int i;

    for (i = 0; i < maxInterrupts; i++)
    {
        if (interrupts[i])
        {
            if( IFFUNC_HASBODY(interrupts[i]->type) ) // Only if the function is not a prototype!
            {
                dbuf_printf (oBuf, "\tCSEG at 0x%04x\n", (i*8)+3+options.code_loc);
                dbuf_printf (oBuf, "\t%cjmp\t%s\n", options.acall_ajmp?'a':'l', interrupts[i]->rname);
            }
			else
			{
				werror(E_ISR_PROTOTYPE);
			}
        }
    }
    return TRUE;
}


static void
_mcs51_genExtraAreas(FILE *of, bool hasMain)
{
    tfprintf (of, "\t!area\n", HOME_NAME);
    tfprintf (of, "\t!area\n", STATIC_NAME);
    //tfprintf (of, "\t!area\n", port->mem.post_static_name);
    tfprintf (of, "\t!area\n", CODE_NAME);
}

static void
_mcs51_genInitStartup (FILE *of)
{
    tfprintf (of, "\textrn code (%s)\n", "__c51_gsinit_startup");
    //tfprintf (of, "\tpublic (%s)\n", "__c51_program_startup");
    tfprintf (of, "\textrn code (%s)\n", "__start__stack");

    if (options.useXstack)
    {
        tfprintf (of, "\textrn code (%s)\n", "__c51_init_xstack");
        tfprintf (of, "\textrn code (%s)\n", "__start__xstack");
    }

    // if the port can copy the XINIT segment to XISEG
    if (port->genXINIT)
    {
        port->genXINIT(of);
    }

    if (!getenv("C51_NOGENRAMCLEAR"))
        tfprintf (of, "\textrn code (%s)\n", "__mcs51_genRAMCLEAR");
}


/* Generate code to copy XINIT to XISEG */
static void _mcs51_genXINIT (FILE * of)
{
    //tfprintf (of, "\textrn code (%s)\n", "__mcs51_genXINIT");

    //if (!getenv("C51_NOGENRAMCLEAR"))
    //  tfprintf (of, "\textrn code (%s)\n", "__mcs51_genXRAMCLEAR");
}


/* Do CSE estimation */
static bool cseCostEstimation (iCode *ic, iCode *pdic)
{
    operand *result = IC_RESULT(ic);
    sym_link *result_type = operandType(result);

    /* if it is a pointer then return ok for now */
    if (IC_RESULT(ic) && IS_PTR(result_type)) return 1;

    /* if bitwise | add & subtract then no since mcs51 is pretty good at it
       so we will cse only if they are local (i.e. both ic & pdic belong to
       the same basic block */
    if (IS_BITWISE_OP(ic) || ic->op == '+' || ic->op == '-')
    {
        /* then if they are the same Basic block then ok */
        if (ic->eBBlockNum == pdic->eBBlockNum) return 1;
        else return 0;
    }

    /* for others it is cheaper to do the cse */
    return 1;
}

/* Indicate which extended bit operations this port supports */
static bool
hasExtBitOp (int op, int size)
{
    if (op == RRC
            || op == RLC
            || op == GETHBIT
            || op == GETABIT
            || op == GETBYTE
            || op == GETWORD
            || (op == SWAP && size <= 2)
       )
        return TRUE;
    else
        return FALSE;
}

/* Indicate the expense of an access to an output storage class */
static int
oclsExpense (struct memmap *oclass)
{
    if (IN_FARSPACE(oclass))
        return 1;

    return 0;
}

static int
instructionSize(char *inst, char *op1, char *op2)
{
#define ISINST(s) (strncmp(inst, (s), sizeof(s)-1) == 0)
#define IS_A(s) (*(s) == 'a' && *(s+1) == '\0')
#define IS_C(s) (*(s) == 'c' && *(s+1) == '\0')
#define IS_Rn(s) (*(s) == 'r' && *(s+1) >= '0' && *(s+1) <= '7')
#define IS_atRi(s) (*(s) == '@' && *(s+1) == 'r')

    /* Based on the current (2003-08-22) code generation for the
       small library, the top instruction probability is:

         57% mov/movx/movc
          6% push
          6% pop
          4% inc
          4% lcall
          4% add
          3% clr
          2% subb
    */
    /* mov, push, & pop are the 69% of the cases. Check them first! */
    if (ISINST ("mov"))
    {
        if (*(inst+3)=='x') return 1; /* movx */
        if (*(inst+3)=='c') return 1; /* movc */
        if (IS_C (op1) || IS_C (op2)) return 2;
        if (IS_A (op1))
        {
            if (IS_Rn (op2) || IS_atRi (op2)) return 1;
            return 2;
        }
        if (IS_Rn(op1) || IS_atRi(op1))
        {
            if (IS_A(op2)) return 1;
            return 2;
        }
        if (strcmp (op1, "dptr") == 0) return 3;
        if (IS_A (op2) || IS_Rn (op2) || IS_atRi (op2)) return 2;
        return 3;
    }

    if (ISINST ("push")) return 2;
    if (ISINST ("pop")) return 2;

    if (ISINST ("lcall")) return 3;
    if (ISINST ("ret")) return 1;
    if (ISINST ("ljmp")) return 3;
    if (ISINST ("sjmp")) return 2;
    if (ISINST ("rlc")) return 1;
    if (ISINST ("rrc")) return 1;
    if (ISINST ("rl")) return 1;
    if (ISINST ("rr")) return 1;
    if (ISINST ("swap")) return 1;
    if (ISINST ("jc")) return 2;
    if (ISINST ("jnc")) return 2;
    if (ISINST ("jb")) return 3;
    if (ISINST ("jnb")) return 3;
    if (ISINST ("jbc")) return 3;
    if (ISINST ("jmp")) return 1; // always jmp @a+dptr
    if (ISINST ("jz")) return 2;
    if (ISINST ("jnz")) return 2;
    if (ISINST ("cjne")) return 3;
    if (ISINST ("mul")) return 1;
    if (ISINST ("div")) return 1;
    if (ISINST ("da")) return 1;
    if (ISINST ("xchd")) return 1;
    if (ISINST ("reti")) return 1;
    if (ISINST ("nop")) return 1;
    if (ISINST ("acall")) return 2;
    if (ISINST ("ajmp")) return 2;


    if (ISINST ("add") || ISINST ("addc") || ISINST ("subb") || ISINST ("xch"))
    {
        if (IS_Rn(op2) || IS_atRi(op2)) return 1;
        return 2;
    }
    if (ISINST ("inc") || ISINST ("dec"))
    {
        if (IS_A(op1) || IS_Rn(op1) || IS_atRi(op1)) return 1;
        if (strcmp(op1, "dptr") == 0) return 1;
        return 2;
    }
    if (ISINST ("anl") || ISINST ("orl") || ISINST ("xrl"))
    {
        if (IS_C(op1)) return 2;
        if (IS_A(op1))
        {
            if (IS_Rn(op2) || IS_atRi(op2)) return 1;
            return 2;
        }
        else
        {
            if (IS_A(op2)) return 2;
            return 3;
        }
    }
    if (ISINST ("clr") || ISINST ("setb") || ISINST ("cpl"))
    {
        if (IS_A(op1) || IS_C(op1)) return 1;
        return 2;
    }
    if (ISINST ("djnz"))
    {
        if (IS_Rn(op1)) return 2;
        return 3;
    }

    /* If the instruction is unrecognized, we shouldn't try to optimize. */
    /* Return a large value to discourage optimization.                  */
    return 999;
}

static asmLineNode *
newAsmLineNode (void)
{
    asmLineNode *aln;

    aln = Safe_alloc ( sizeof (asmLineNode));
    aln->size = 0;
    aln->regsRead = NULL;
    aln->regsWritten = NULL;

    return aln;
}


typedef struct mcs51operanddata
{
    char name[6];
    int regIdx1;
    int regIdx2;
}
mcs51operanddata;

static mcs51operanddata mcs51operandDataTable[] =
{
    {"a",    A_IDX,   -1},
    {"ab",   A_IDX,   B_IDX},
    {"ac",   CND_IDX, -1},
    {"acc",  A_IDX,   -1},
    {"ar0",  R0_IDX,  -1},
    {"ar1",  R1_IDX,  -1},
    {"ar2",  R2_IDX,  -1},
    {"ar3",  R3_IDX,  -1},
    {"ar4",  R4_IDX,  -1},
    {"ar5",  R5_IDX,  -1},
    {"ar6",  R6_IDX,  -1},
    {"ar7",  R7_IDX,  -1},
    {"b",    B_IDX,   -1},
    {"c",    CND_IDX, -1},
    {"cy",   CND_IDX, -1},
    {"dph",  DPH_IDX, -1},
    {"dpl",  DPL_IDX, -1},
    {"dptr", DPL_IDX, DPH_IDX},
    {"f0",   CND_IDX, -1},
    {"f1",   CND_IDX, -1},
    {"ov",   CND_IDX, -1},
    {"p",    CND_IDX, -1},
    {"psw",  CND_IDX, -1},
    {"r0",   R0_IDX,  -1},
    {"r1",   R1_IDX,  -1},
    {"r2",   R2_IDX,  -1},
    {"r3",   R3_IDX,  -1},
    {"r4",   R4_IDX,  -1},
    {"r5",   R5_IDX,  -1},
    {"r6",   R6_IDX,  -1},
    {"r7",   R7_IDX,  -1},
};

static int
mcs51operandCompare (const void *key, const void *member)
{
    return strcmp((const char *)key, ((mcs51operanddata *)member)->name);
}

static void
updateOpRW (asmLineNode *aln, char *op, char *optype)
{
    mcs51operanddata *opdat;
    char *dot;

    dot = strchr(op, '.');
    if (dot)
        *dot = '\0';

    opdat = bsearch (op, mcs51operandDataTable,
                     sizeof(mcs51operandDataTable)/sizeof(mcs51operanddata),
                     sizeof(mcs51operanddata), mcs51operandCompare);

    if (opdat && strchr(optype,'r'))
    {
        if (opdat->regIdx1 >= 0)
            aln->regsRead = bitVectSetBit (aln->regsRead, opdat->regIdx1);
        if (opdat->regIdx2 >= 0)
            aln->regsRead = bitVectSetBit (aln->regsRead, opdat->regIdx2);
    }
    if (opdat && strchr(optype,'w'))
    {
        if (opdat->regIdx1 >= 0)
            aln->regsWritten = bitVectSetBit (aln->regsWritten, opdat->regIdx1);
        if (opdat->regIdx2 >= 0)
            aln->regsWritten = bitVectSetBit (aln->regsWritten, opdat->regIdx2);
    }
    if (op[0] == '@')
    {
        if (!strcmp(op, "@r0"))
            aln->regsRead = bitVectSetBit (aln->regsRead, R0_IDX);
        if (!strcmp(op, "@r1"))
            aln->regsRead = bitVectSetBit (aln->regsRead, R1_IDX);
        if (strstr(op, "dptr"))
        {
            aln->regsRead = bitVectSetBit (aln->regsRead, DPL_IDX);
            aln->regsRead = bitVectSetBit (aln->regsRead, DPH_IDX);
        }
        if (strstr(op, "a+"))
            aln->regsRead = bitVectSetBit (aln->regsRead, A_IDX);
    }
}

typedef struct mcs51opcodedata
{
    char name[6];
    char class[3];
    char pswtype[3];
    char op1type[3];
    char op2type[3];
}
mcs51opcodedata;

static mcs51opcodedata mcs51opcodeDataTable[] =
{
    {"acall","j", "",   "",   ""},
    {"add",  "",  "w",  "rw", "r"},
    {"addc", "",  "rw", "rw", "r"},
    {"ajmp", "j", "",   "",   ""},
    {"anl",  "",  "",   "rw", "r"},
    {"cjne", "j", "w",  "r",  "r"},
    {"clr",  "",  "",   "w",  ""},
    {"cpl",  "",  "",   "rw", ""},
    {"da",   "",  "rw", "rw", ""},
    {"dec",  "",  "",   "rw", ""},
    {"div",  "",  "w",  "rw", ""},
    {"djnz", "j", "",  "rw",  ""},
    {"inc",  "",  "",   "rw", ""},
    {"jb",   "j", "",   "r",  ""},
    {"jbc",  "j", "",  "rw",  ""},
    {"jc",   "j", "",   "",   ""},
    {"jmp",  "j", "",  "",    ""},
    {"jnb",  "j", "",   "r",  ""},
    {"jnc",  "j", "",   "",   ""},
    {"jnz",  "j", "",  "",    ""},
    {"jz",   "j", "",  "",    ""},
    {"lcall","j", "",   "",   ""},
    {"ljmp", "j", "",   "",   ""},
    {"mov",  "",  "",   "w",  "r"},
    {"movc", "",  "",   "w",  "r"},
    {"movx", "",  "",   "w",  "r"},
    {"mul",  "",  "w",  "rw", ""},
    {"nop",  "",  "",   "",   ""},
    {"orl",  "",  "",   "rw", "r"},
    {"pop",  "",  "",   "w",  ""},
    {"push", "",  "",   "r",  ""},
    {"ret",  "j", "",   "",   ""},
    {"reti", "j", "",   "",   ""},
    {"rl",   "",  "",   "rw", ""},
    {"rlc",  "",  "rw", "rw", ""},
    {"rr",   "",  "",   "rw", ""},
    {"rrc",  "",  "rw", "rw", ""},
    {"setb", "",  "",   "w",  ""},
    {"sjmp", "j", "",   "",   ""},
    {"subb", "",  "rw", "rw", "r"},
    {"swap", "",  "",   "rw", ""},
    {"xch",  "",  "",   "rw", "rw"},
    {"xchd", "",  "",   "rw", "rw"},
    {"xrl",  "",  "",   "rw", "r"},
};

static int
mcs51opcodeCompare (const void *key, const void *member)
{
    return strcmp((const char *)key, ((mcs51opcodedata *)member)->name);
}

static asmLineNode *
asmLineNodeFromLineNode (lineNode *ln)
{
    asmLineNode *aln = newAsmLineNode();
    char *op, op1[256], op2[256];
    int opsize;
    const char *p;
    char inst[8];
    mcs51opcodedata *opdat;

    p = ln->line;

    while (*p && isspace(*p)) p++;
    for (op = inst, opsize=1; *p; p++)
    {
        if (isspace(*p) || *p == ';' || *p == ':' || *p == '=')
            break;
        else if (opsize < sizeof(inst))
            *op++ = tolower(*p), opsize++;
    }
    *op = '\0';

    if (*p == ';' || *p == ':' || *p == '=')
        return aln;

    while (*p && isspace(*p)) p++;
    if (*p == '=')
        return aln;

    for (op = op1, opsize=1; *p && *p != ','; p++)
    {
        if (!isspace(*p) && opsize < sizeof(op1))
            *op++ = tolower(*p), opsize++;
    }
    *op = '\0';

    if (*p == ',') p++;
    for (op = op2, opsize=1; *p && *p != ','; p++)
    {
        if (!isspace(*p) && opsize < sizeof(op2))
            *op++ = tolower(*p), opsize++;
    }
    *op = '\0';

    aln->size = instructionSize(inst, op1, op2);

    aln->regsRead = newBitVect (END_IDX);
    aln->regsWritten = newBitVect (END_IDX);

    opdat = bsearch (inst, mcs51opcodeDataTable,
                     sizeof(mcs51opcodeDataTable)/sizeof(mcs51opcodedata),
                     sizeof(mcs51opcodedata), mcs51opcodeCompare);

    if (opdat)
    {
        updateOpRW (aln, op1, opdat->op1type);
        updateOpRW (aln, op2, opdat->op2type);
        if (strchr(opdat->pswtype,'r'))
            aln->regsRead = bitVectSetBit (aln->regsRead, CND_IDX);
        if (strchr(opdat->pswtype,'w'))
            aln->regsWritten = bitVectSetBit (aln->regsWritten, CND_IDX);
    }

    return aln;
}

static int
getInstructionSize (lineNode *line)
{
    if (!line->aln)
        line->aln = asmLineNodeFromLineNode (line);

    return line->aln->size;
}

static bitVect *
getRegsRead (lineNode *line)
{
    if (!line->aln)
        line->aln = asmLineNodeFromLineNode (line);

    return line->aln->regsRead;
}

static bitVect *
getRegsWritten (lineNode *line)
{
    if (!line->aln)
        line->aln = asmLineNodeFromLineNode (line);

    return line->aln->regsWritten;
}


/** $1 is always the basename.
    $2 is always the output file.
    $3 varies
    $l is the list of extra options that should be there somewhere...
    MUST be terminated with a NULL.
*/
static const char *_linkCmd[] =
{
    "l51", "", "\"$1\"", NULL
};

/* $3 is replaced by assembler.debug_opts resp. port->assembler.plain_opts */
static const char *_asmCmd[] =
{
    //"sdas8051", "$l", "$3", "\"$1.asm\"", NULL
    "a51", "", "-c -i", "\"$1.asm\"", NULL
};

/* Globals */
PORT mcs51_port =
{
    TARGET_ID_MCS51,
    "mcs51",
    "MCU 8051",                   /* Target name */
    NULL,                         /* Processor name */
    {
        glue,
        TRUE,                       /* Emit glue around main */
        MODEL_SMALL | MODEL_MEDIUM | MODEL_LARGE,
        MODEL_SMALL
    },
    {                             /* Assembler */
        _asmCmd,
        NULL,
        "-plosgffwzc",              /* Options with debug */
        "-plosgffwz",               /* Options without debug */
        0,
        ".asm",
        NULL                        /* no do_assemble function */
    },
    {                             /* Linker */
        _linkCmd,
        NULL,
        NULL,
        ".obj",
        1
    },
    {                             /* Peephole optimizer */
        _defaultRules,
        getInstructionSize,
        getRegsRead,
        getRegsWritten,
        mcs51DeadMove,
        0
    },
    {
        /* Sizes: char, short, int, long, ptr, fptr, gptr, bit, float, max */
        1, 2, 2, 4, 1, 2, 3, 1, 4, 4
    },
    /* tags for generic pointers */
    { 0x00, 0x40, 0x60, 0x80 },           /* far, near, xstack, code */
    {
        "R_XSTK",      // xstack_name
        "R_STACK",     // istack_name
        "R_CSEG",      // code_name
        "R_DSEG",      // data_name
        "R_ISEG",      // idata_name
        "R_PSEG",      // pdata_name
        "R_XSEG",      // xdata_name
        "R_BSEG",      // bit_name
        "",			   // reg_name
        "R_GSINIT",    // static_name
        "R_OSEG",      // overlay_name
        "R_GSFINAL",   // post_static_name
        "R_HOME",      // home_name
        "R_XISEG",     // xidata_name - initialized xdata   initialized xdata
        "R_XINIT",     // xinit_name - a code copy of xiseg
        "R_CONST",     // const_name - const data (code or not)
        "CSEG",        // cabs_name - const absolute data (code or not)
        "XSEG",        // xabs_name - absolute xdata/pdata
        "ISEG",        // iabs_name - absolute idata/data
        NULL,
        NULL,
        1
    },
    { _mcs51_genExtraAreas, NULL },
    {
        +1,         /* direction (+1 = stack grows up) */
        0,          /* bank_overhead (switch between register banks) */
        4,          /* isr_overhead */
        1,          /* call_overhead (2 for return address - 1 for pre-incrementing push */
        1,          /* reent_overhead */
        0           /* banked_overhead (switch between code banks) */
    },
    {
        /* mcs51 has an 8 bit mul */
        1, -1
    },
    {
        mcs51_emitDebuggerSymbol
    },
    {
        256,        /* maxCount */
        2,          /* sizeofElement */
        {6,9,15},   /* sizeofMatchJump[] */
        {9,18,36},  /* sizeofRangeCompare[] */
        4,          /* sizeofSubtract */
        6,          /* sizeofDispatch */
    },
    "_",
    _mcs51_init,
    _mcs51_parseOptions,
    _mcs51_options,
    NULL,
    _mcs51_finaliseOptions,
    _mcs51_setDefaultOptions,
    mcs51_assignRegisters,
    _mcs51_getRegName,
    _mcs51_keywords,
    _mcs51_genAssemblerPreamble,
    NULL,                         /* no genAssemblerEnd */
    _mcs51_genIVT,
    _mcs51_genXINIT,
    _mcs51_genInitStartup,
    _mcs51_reset_regparm,
    _mcs51_regparm,
    NULL,
    NULL,
    NULL,
    hasExtBitOp,                  /* hasExtBitOp */
    oclsExpense,                  /* oclsExpense */
    FALSE,
    TRUE,                         /* little_endian */
    0,                            /* leave lt */
    0,                            /* leave gt */
    1,                            /* transform <= to ! > */
    1,                            /* transform >= to ! < */
    1,                            /* transform != to !(a == b) */
    0,                            /* leave == */
    FALSE,                        /* No array initializer support. */
    cseCostEstimation,
    NULL,                         /* no builtin functions */
    GPOINTER,                     /* treat unqualified pointers as "generic" pointers */
    1,                            /* reset labelKey to 1 */
    1,                            /* globals & local static allowed */
    PORT_MAGIC
};
