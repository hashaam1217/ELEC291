/*-------------------------------------------------------------------------
  C51main.c - main file

             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1999)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!
-------------------------------------------------------------------------*/

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#include <libgen.h>
#endif

#include <signal.h>
#include "common.h"
#include <ctype.h>
#include "newalloc.h"
#include "dbuf_string.h"
#include "C51err.h"
#include "BuildCmd.h"
#include "MySystem.h"
#include "C51macro.h"
#include "C51util.h"
#include "C51debug.h"
#include "C51args.h"

#ifdef _WIN32
#include <process.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

extern int yyparse (void);

FILE *srcFile;                  /* source file          */
char *fullSrcFileName;          /* full name for the source file; */
/* can be NULL while c1mode or linking without compiling */
char *fullDstFileName;          /* full name for the output file; */
/* only given by -o, otherwise NULL */
char *dstFileName;              /* destination file name without extension */
char *dstPath = "";             /* path for the output files; */
/* "" is equivalent with cwd */
char *moduleNameBase;           /* module name base is source file without path and extension */
/* can be NULL while linking without compiling */
char *moduleName;               /* module name is same as module name base, but with all */
/* non-alphanumeric characters replaced with underscore */
int currRegBank = 0;
int RegBankUsed[4] = {1, 0, 0, 0}; /*Reg Bank 0 used by default*/
int BitBankUsed;                /* MB: overlayable bit bank */
struct optimize optimize;
struct options options;
int preProcOnly = 0;
int noAssemble = 0;
set *preArgvSet = NULL;         /* pre-processor arguments  */
set *asmOptionsSet = NULL;      /* set of assembler options */
set *linkOptionsSet = NULL;     /* set of linker options */
set *libFilesSet = NULL;
set *libPathsSet = NULL;
set *objFilesSet = NULL;
set *dataDirsSet = NULL;        /* list of data search directories */
set *includeDirsSet = NULL;     /* list of include search directories */
set *userIncDirsSet = NULL;     /* list of user include directories */
set *libDirsSet = NULL;         /* list of lib search directories */

/* Globally accessible scratch buffer for file names.
   TODO: replace them with local buffers */
char scratchFileName[PATH_MAX];
char buffer[PATH_MAX * 2];

int source_has_main_function=0;

#define LENGTH(_a)      (sizeof(_a)/sizeof(*(_a)))

#define OPTION_HELP             "--help"
#define OPTION_OUT_FMT_IHX      "--out-fmt-ihx"
#define OPTION_OUT_FMT_S19      "--out-fmt-s19"
#define OPTION_LARGE_MODEL      "--model-large"
#define OPTION_MEDIUM_MODEL     "--model-medium"
#define OPTION_SMALL_MODEL      "--model-small"
#define OPTION_DUMP_ALL         "--dumpall"
#define OPTION_PEEP_FILE        "--peep-file"
#define OPTION_LIB_PATH         "--lib-path"
#define OPTION_CALLEE_SAVES     "--callee-saves"
#define OPTION_STACK_LOC        "--stack-loc"
#define OPTION_XSTACK_LOC       "--xstack-loc"
#define OPTION_DATA_LOC         "--data-loc"
#define OPTION_IDATA_LOC        "--idata-loc"
#define OPTION_XRAM_LOC         "--xram-loc"
#define OPTION_CODE_LOC         "--code-loc"
#define OPTION_IRAM_SIZE        "--iram-size"
#define OPTION_XRAM_SIZE        "--xram-size"
#define OPTION_CODE_SIZE        "--code-size"
#define OPTION_VERSION          "--version"
#define OPTION_NO_LABEL_OPT     "--nolabelopt"
#define OPTION_NO_LOOP_INV      "--noinvariant"
#define OPTION_NO_LOOP_IND      "--noinduction"
#define OPTION_LESS_PEDANTIC    "--less-pedantic"
#define OPTION_DISABLE_WARNING  "--disable-warning"
#define OPTION_WERROR           "--Werror"
#define OPTION_NO_GCSE          "--nogcse"
#define OPTION_SHORT_IS_8BITS   "--short-is-8bits"
#define OPTION_NO_XINIT_OPT     "--no-xinit-opt"
#define OPTION_NO_CCODE_IN_ASM  "--no-c-code-in-asm"
#define OPTION_ICODE_IN_ASM     "--i-code-in-asm"
#define OPTION_PRINT_SEARCH_DIRS "--print-search-dirs"
#define OPTION_MSVC_ERROR_STYLE "--vc"
#define OPTION_USE_STDOUT       "--use-stdout"
#define OPTION_NO_PEEP_COMMENTS "--no-peep-comments"
#define OPTION_VERBOSE_ASM      "--fverbose-asm"
#define OPTION_OPT_CODE_SPEED   "--opt-code-speed"
#define OPTION_OPT_CODE_SIZE    "--opt-code-size"
#define OPTION_STD_C89          "--std-c89"
#define OPTION_STD_C99          "--std-c99"
#define OPTION_STD_C51_89       "--std-c51-89"
#define OPTION_STD_C51_99       "--std-c51-99"
#define OPTION_CODE_SEG         "--codeseg"
#define OPTION_CONST_SEG        "--constseg"
#define OPTION_OVERLAY_TO       "--overlayto"
#define OPTION_DOLLARS_IN_IDENT "--fdollars-in-identifiers"
#define OPTION_UNSIGNED_CHAR    "--funsigned-char"
#define OPTION_PRINTF_FLOAT     "--printf-float"

static const OPTION
optionsTable[] =
{
    { 0,    NULL,                   NULL, "General options" },
    { 0,    OPTION_HELP,            NULL, "Display this help" },
    { 'v',  OPTION_VERSION,         NULL, "Display c51's version" },
    { 0,    "--verbose",            &options.verbose, "Trace calls to the preprocessor, assembler, and linker" },
    { 'V',  NULL,                   &options.verboseExec, "Execute verbosely.  Show sub commands as they are run" },
    { 'd',  NULL,                   NULL, NULL },
    { 'D',  NULL,                   NULL, "Define macro as in -Dmacro" },
    { 'I',  NULL,                   NULL, "Add to the include (*.h) path, as in -Ipath" },
    { 'A',  NULL,                   NULL, NULL },
    { 'U',  NULL,                   NULL, NULL },
    { 'M',  NULL,                   NULL, "Preprocessor option" },
    { 'W',  NULL,                   NULL, "Pass through options to the pre-processor (p), assembler (a) or linker (l)" },
    { 'S',  NULL,                   &noAssemble, "Compile only; do not assemble or link" },
    { 'c',  "--compile-only",       &options.cc_only, "Compile and assemble, but do not link" },
    { 'E',  "--preprocessonly",     &preProcOnly, "Preprocess only, do not compile" },
    { 0,    "--c1mode",             &options.c1mode, "Act in c1 mode.  The standard input is preprocessed code, the output is assembly code." },
    { 'o',  NULL,                   NULL, "Place the output into the given path resp. file" },
    { 0,    OPTION_PRINT_SEARCH_DIRS, &options.printSearchDirs, "display the directories in the compiler's search path"},
    { 0,    OPTION_MSVC_ERROR_STYLE, &options.vc_err_style, "messages are compatible with Micro$oft visual studio"},
    { 0,    OPTION_USE_STDOUT,      NULL, "send errors to stdout instead of stderr"},
    { 0,    "--nostdlib",           &options.nostdlib, "Do not include the standard library directory in the search path" },
    { 0,    "--nostdinc",           &options.nostdinc, "Do not include the standard include directory in the search path" },
    { 0,    OPTION_LESS_PEDANTIC,   NULL, "Disable some of the more pedantic warnings" },
    { 0,    OPTION_DISABLE_WARNING, NULL, "<nnnn> Disable specific warning" },
    { 0,    OPTION_WERROR,          NULL, "Treat the warnings as errors" },
    { 0,    "--debug",              &options.debug, "Enable debugging symbol output" },
    { 0,    "--cyclomatic",         &options.cyclomatic, "Display complexity of compiled functions" },
    { 0,    OPTION_STD_C89,         NULL, "Use C89 standard only" },
    { 0,    OPTION_STD_C51_89,      NULL, "Use C89 standard with C51 extensions (default)" },
    { 0,    OPTION_STD_C99,         NULL, "Use C99 standard only (incomplete)" },
    { 0,    OPTION_STD_C51_99,      NULL, "Use C99 standard with C51 extensions (incomplete)" },
    { 0,    OPTION_DOLLARS_IN_IDENT, &options.dollars_in_ident, "Permit '$' as an identifier character" },
    { 0,    OPTION_UNSIGNED_CHAR,   &options.unsigned_char, "Make \"char\" unsigned by default" },
    { 0,    OPTION_PRINTF_FLOAT,    &options.printf_float, "Link with float enabled printf" },

    { 0,    NULL,                   NULL, "Code generation options"},
    { 'm',  NULL,                   NULL, "Set the port to use e.g. -mz80." },
    { 'p',  NULL,                   NULL, "Select port specific processor e.g. -mpic14 -p16f84" },
    { 0,    OPTION_LARGE_MODEL,     NULL, "external data space is used" },
    { 0,    OPTION_MEDIUM_MODEL,    NULL, "external paged data space is used" },
    { 0,    OPTION_SMALL_MODEL,     NULL, "internal data space is used (default)" },
    { 0,    "--stack-auto",         &options.stackAuto, "Stack automatic variables" },
    { 0,    "--xstack",             &options.useXstack, "Use external stack" },
    { 0,    "--int-long-reent",     &options.intlong_rent, "Use reentrant calls on the int and long support functions" },
    { 0,    "--float-reent",        &options.float_rent, "Use reentrant calls on the float support functions" },
    { 0,    "--main-return",        &options.mainreturn, "Issue a return after main()" },
    { 0,    "--xram-movc",          &options.xram_movc, "Use movc instead of movx to read xram (xdata)" },
    { 0,    OPTION_CALLEE_SAVES,    &options.calleeSavesSet, "<func[,func,...]> Cause the called function to save registers instead of the caller", CLAT_SET },
    { 0,    "--profile",            &options.profile, "On supported ports, generate extra profiling information" },
    { 0,    "--fomit-frame-pointer", &options.omitFramePtr, "Leave out the frame pointer." },
    { 0,    "--all-callee-saves",   &options.all_callee_saves, "callee will always save registers used" },
    { 0,    "--stack-probe",        &options.stack_probe,"insert call to function __stack_probe at each function prologue"},
    { 0,    OPTION_NO_XINIT_OPT,    &options.noXinitOpt, "don't memcpy initialized xram from code"},
    { 0,    OPTION_NO_CCODE_IN_ASM, &options.noCcodeInAsm, "don't include c-code as comments in the asm file"},
    { 0,    OPTION_NO_PEEP_COMMENTS, &options.noPeepComments, "don't include peephole optimizer comments"},
    { 0,    OPTION_VERBOSE_ASM,     &options.verboseAsm, "include code generator comments"},
    { 0,    OPTION_SHORT_IS_8BITS,  NULL, "Make short 8 bits (for old times sake)" },
    { 0,    OPTION_CODE_SEG,        NULL, "<name> use this name for the code segment" },
    { 0,    OPTION_CONST_SEG,       NULL, "<name> use this name for the const segment" },
    { 0,    OPTION_OVERLAY_TO,      NULL, "<name> put variables into this overlay segment" },

    { 0,    NULL,                   NULL, "Optimization options"},
    { 0,    "--nooverlay",          &options.noOverlay, "Disable overlaying leaf function auto variables" },
    { 0,    OPTION_NO_GCSE,         NULL, "Disable the GCSE optimisation" },
    { 0,    OPTION_NO_LABEL_OPT,    NULL, "Disable label optimisation" },
    { 0,    OPTION_NO_LOOP_INV,     NULL, "Disable optimisation of invariants" },
    { 0,    OPTION_NO_LOOP_IND,     NULL, "Disable loop variable induction" },
    { 0,    "--nojtbound",          &optimize.noJTabBoundary, "Don't generate boundary check for jump tables" },
    { 0,    "--noloopreverse",      &optimize.noLoopReverse, "Disable the loop reverse optimisation" },
    { 0,    "--no-peep",            &options.nopeep, "Disable the peephole assembly file optimisation" },
    { 0,    "--no-reg-params",      &options.noRegParams, "On some ports, disable passing some parameters in registers" },
    { 0,    "--peep-asm",           &options.asmpeep, "Enable peephole optimization on inline assembly" },
    { 0,    OPTION_PEEP_FILE,       &options.peep_file, "<file> use this extra peephole file", CLAT_STRING },
    { 0,    OPTION_OPT_CODE_SPEED,  NULL, "Optimize for code speed rather than size" },
    { 0,    OPTION_OPT_CODE_SIZE,   NULL, "Optimize for code size rather than speed" },

    { 0,    NULL,                   NULL, "Internal debugging options"},
    { 0,    "--dumpraw",            &options.dump_raw, "Dump the internal structure after the initial parse" },
    { 0,    "--dumpgcse",           &options.dump_gcse, NULL },
    { 0,    "--dumploop",           &options.dump_loop, NULL },
    { 0,    "--dumpdeadcode",       &options.dump_kill, NULL },
    { 0,    "--dumpliverange",      &options.dump_range, NULL },
    { 0,    "--dumpregpack",        &options.dump_pack, NULL },
    { 0,    "--dumpregassign",      &options.dump_rassgn, NULL },
    { 0,    "--dumptree",           &options.dump_tree, "dump front-end AST before generating iCode" },
    { 0,    OPTION_DUMP_ALL,        NULL, "Dump the internal structure at all stages" },
    { 0,    OPTION_ICODE_IN_ASM,    &options.iCodeInAsm, "include i-code as comments in the asm file"},

    { 0,    NULL,                   NULL, "Linker options" },
    { 'l',  NULL,                   NULL, "Include the given library in the link" },
    { 'L',  NULL,                   NULL, "Add the next field to the library search path" },
    { 0,    OPTION_LIB_PATH,        &libPathsSet, "<path> use this path to search for libraries", CLAT_ADD_SET },
    { 0,    OPTION_OUT_FMT_IHX,     NULL, "Output in Intel hex format" },
    { 0,    OPTION_OUT_FMT_S19,     NULL, "Output in S19 hex format" },
    { 0,    OPTION_XRAM_LOC,        &options.xdata_loc, "<nnnn> External Ram start location", CLAT_INTEGER },
    { 0,    OPTION_XRAM_SIZE,       NULL, "<nnnn> External Ram size" },
    { 0,    OPTION_IRAM_SIZE,       &options.iram_size, "<nnnn> Internal Ram size", CLAT_INTEGER },
    { 0,    OPTION_XSTACK_LOC,      &options.xstack_loc, "<nnnn> External Stack start location", CLAT_INTEGER },
    { 0,    OPTION_CODE_LOC,        &options.code_loc, "<nnnn> Code Segment Location", CLAT_INTEGER },
    { 0,    OPTION_CODE_SIZE,       &options.code_size, "<nnnn> Code Segment size", CLAT_INTEGER },
    { 0,    OPTION_STACK_LOC,       &options.stack_loc, "<nnnn> Stack pointer initial value", CLAT_INTEGER },
    { 0,    OPTION_DATA_LOC,        &options.data_loc, "<nnnn> Direct data start location", CLAT_INTEGER },
    { 0,    OPTION_IDATA_LOC,       &options.idata_loc, NULL, CLAT_INTEGER },

    /* End of options */
    { 0,    NULL }
};

/** Table of all unsupported options and help text to display when one
    is used.
*/
typedef struct
{
    /** shortOpt as in OPTIONS. */
    char shortOpt;
    /** longOpt as in OPTIONS. */
    const char *longOpt;
    /** Message to display inside W_UNSUPPORTED_OPT when this option
        is used. */
    const char *message;
} UNSUPPORTEDOPT;

static const UNSUPPORTEDOPT
unsupportedOptTable[] =
{
    { 'X',  NULL,       "use --xstack-loc instead" },
    { 'x',  NULL,       "use --xstack instead" },
    { 'i',  NULL,       "use --idata-loc instead" },
    { 'r',  NULL,       "use --xdata-loc instead" },
    { 's',  NULL,       "use --code-loc instead" },
    { 'Y',  NULL,       "use -I instead" },
    { 0,    "--fommit-frame-pointer", "use --fomit-frame-pointer instead" },
};

/** List of all default constant macros.
 */
static const char *_baseValues[] =
{
    "cpp", "c51pp",
    "cppextraopts", "",
    /* Path seperator character */
    "sep", DIR_SEPARATOR_STRING,
    NULL
};

static const char *_preCmd = "{cpp} -nostdinc -Wall {cppstd}{cppextraopts} \"{fullsrcfilename}\" \"{cppoutfilename}\"";

PORT *port;

static PORT *_ports[] =
{
    &mcs51_port
};

#define NUM_PORTS (sizeof(_ports)/sizeof(_ports[0]))

/** Sets the port to the one given by the command line option.
    @param    The name minus the option (eg 'mcs51')
    @return     0 on success.
*/
static void
_setPort (const char *name)
{
    int i;
    for (i = 0; i < NUM_PORTS; i++)
    {
        if (!strcmp (_ports[i]->target, name))
        {
            port = _ports[i];
            return;
        }
    }
    /* Error - didnt find */
    werror (E_UNKNOWN_TARGET, name);
    exit (EXIT_FAILURE);
}

/* Override the default processor with the one specified
 * on the command line */
static void
_setProcessor (char *_processor)
{
    port->processor = _processor;
}

static void
_validatePorts (void)
{
    int i;
    for (i = 0; i < NUM_PORTS; i++)
    {
        if (_ports[i]->magic != PORT_MAGIC)
        {
            /* Uncomment this line to debug which port is causing the problem
             * (the target name is close to the beginning of the port struct
             * and probably can be accessed just fine). */
            fprintf(stderr,"%s :",_ports[i]->target);
            wassertl (0, "Port definition structure is incomplete");
        }
    }
}


static char
*program_name (const char *path)
{
#ifdef _WIN32
    char fname[_MAX_FNAME];

    _splitpath (path, NULL, NULL, fname, NULL);
    return Safe_strdup (fname);
#else
    char *tmpPath = Safe_strdup (path);
    char *res = Safe_strdup (basename (tmpPath));

    free (tmpPath);
    return res;
#endif
}

/* search through the command line for the port */
static void
_findPort (int argc, char **argv)
{
    char *programName = program_name (*argv);
    int found = 0;
    int i;

    _validatePorts ();

    /* try to assign port by command line option */
    while (argc-- && !found)
    {
        if (!strncmp (*argv, "-m", 2))
        {
            _setPort (*argv + 2);
            found = 1;
        }
        argv++;
    }

    /* try to assign port by the name of the executable */
    for (i = 0; i < NUM_PORTS && !found; i++)
    {
        if (strstr (programName, _ports[i]->target))
        {
            _setPort (_ports[i]->target);
            found = 1;
        }
    }

    if (!found)
    {
        /* Use the first in the list as default */
        port = _ports[0];
    }

    Safe_free (programName);
}

/* search through the command line options for the processor */
static void _findProcessor (int argc, char **argv)
{
    while (argc--)
    {
        if (!strncmp (*argv, "-p", 2))
        {
            _setProcessor (*argv + 2);
            return;
        }
        argv++;
    }

    /* no error if processor was not specified. */
}

/*-----------------------------------------------------------------*/
/* printVersionInfo - prints the version info        */
/*-----------------------------------------------------------------*/
void printVersionInfo (FILE *stream)
{
    int i;

    fprintf (stream,
             "C51 : ");
    for (i = 0; i < NUM_PORTS; i++)
        fprintf (stream, "%s%s", i == 0 ? "" : "/", _ports[i]->target);

    fprintf (stream, " " C51_VERSION_STR
#ifdef C51_SUB_VERSION_STR
             "/" C51_SUB_VERSION_STR
#endif
             " #%s (%s) (%s)\n",
             getBuildNumber(), getBuildDate(), getBuildEnvironment() );
}

static void printOptions(const OPTION *optionsTable, FILE *stream)
{
    int i;
    for (i = 0;
            optionsTable[i].shortOpt != 0 || optionsTable[i].longOpt != NULL
            || optionsTable[i].help != NULL;
            i++)
    {
        if (!optionsTable[i].shortOpt && !optionsTable[i].longOpt
                && optionsTable[i].help)
        {
            fprintf (stream, "\n%s:\n", optionsTable[i].help);
        }
        else
        {
            fprintf(stream, "  %c%c  %-20s  %s\n",
                    optionsTable[i].shortOpt !=0 ? '-' : ' ',
                    optionsTable[i].shortOpt !=0 ? optionsTable[i].shortOpt : ' ',
                    optionsTable[i].longOpt != NULL ? optionsTable[i].longOpt : "",
                    optionsTable[i].help != NULL ? optionsTable[i].help : ""
                   );
        }
    }
}

/*-----------------------------------------------------------------*/
/* printUsage - prints command line syntax         */
/*-----------------------------------------------------------------*/
static void printUsage (void)
{
    int i;
    FILE *stream = stderr;

    printVersionInfo (stream);
    fprintf (stream,
             "Usage : c51 [options] filename\n"
             "Options :-\n"
            );

    printOptions (optionsTable, stream);

    for (i = 0; i < NUM_PORTS; i++)
    {
        if (_ports[i]->poptions != NULL)
        {
            fprintf (stream, "\nSpecial options for the %s port:\n", _ports[i]->target);
            printOptions (_ports[i]->poptions, stream);
        }
    }
}

/*-----------------------------------------------------------------*/
/* setParseWithComma - separates string with comma to a set        */
/*-----------------------------------------------------------------*/
void setParseWithComma (set **dest, const char *src)
{
    const char *p, *end;
    struct dbuf_s dbuf;

    /* skip the initial white spaces */
    while (isspace((unsigned char)*src))
        ++src;

    /* skip the trailing white spaces */
    end = &src[strlen(src) - 1];
    while (end >= src && isspace((unsigned char)*end))
        --end;
    ++end;

    p = src;
    while (src < end)
    {
        dbuf_init (&dbuf, 16);

        while (p < end && ',' != *p)
            ++p;
        dbuf_append (&dbuf, src, p - src);

        /* null terminate the buffer */
        dbuf_c_str (&dbuf);
        addSet(dest, dbuf_detach (&dbuf));

        src = ++p;
    }
}

/*-----------------------------------------------------------------*/
/* setDefaultOptions - sets the default options                    */
/*-----------------------------------------------------------------*/
static void setDefaultOptions (void)
{
    /* first the options part */
    options.stack_loc = 0;          /* stack pointer initialised to 0 */
    options.xstack_loc = 0;         /* xternal stack starts at 0 */
    options.code_loc = 0;           /* code starts at 0 */
    options.data_loc = 0;           /* JCF: By default let the linker locate data */
    options.xdata_loc = 0;
    options.idata_loc = 0;          /* MB: No need to limit idata to 0x80-0xFF */
    options.nopeep = 0;
    options.model = port->general.default_model;
    options.nostdlib = 0;
    options.nostdinc = 0;
    options.verbose = 0;
    options.shortis8bits = 0;
    options.std_c51 = 1;           /* enable C51 language extensions */
    options.std_c99 = 0;            /* default to C89 until more C99 support */
    options.code_seg = CODE_NAME ? Safe_strdup(CODE_NAME) : NULL; /* default to CSEG for generated code */
    options.const_seg = CONST_NAME ? Safe_strdup(CONST_NAME) : NULL; /* default to CONST for generated code */
	options.overlay_to = "";
    options.stack10bit=0;

    /* now for the optimizations */
    /* turn on the everything */
    optimize.global_cse = 1;
    optimize.label1 = 1;
    optimize.label2 = 1;
    optimize.label3 = 1;
    optimize.label4 = 1;
    optimize.loopInvariant = 1;
    optimize.loopInduction = 1;

    /* now for the ports */
    port->setDefaultOptions ();
}

/*-----------------------------------------------------------------*/
/* processFile - determines the type of file from the extension    */
/*-----------------------------------------------------------------*/
static void processFile (char *s)
{
    const char *extp;
    struct dbuf_s ext;
    struct dbuf_s path;

    dbuf_init (&ext, 128);
    dbuf_init (&path, 128);

    /* get the file extension.
       If no '.' then we don't know what the file type is
       so give a warning and return */
    if (!dbuf_splitFile (s, &path, &ext))
    {
        werror (W_UNKNOWN_FEXT, s);

        dbuf_destroy (&ext);
        dbuf_destroy (&path);

        return;
    }

    /* otherwise depending on the file type */
    extp = dbuf_c_str (&ext);
    if (STRCASECMP (extp, ".c") == 0)
    {
        char *p;

        dbuf_destroy (&ext);

        /* source file name : not if we already have a
           source file */
        if (fullSrcFileName)
        {
            werror (W_TOO_MANY_SRC, s);

            dbuf_destroy (&path);

            return;
        }

        /* the only source file */
        fullSrcFileName = s;
        if (!(srcFile = fopen (fullSrcFileName, "r")))
        {
            werror (E_FILE_OPEN_ERR, s);

            dbuf_destroy (&path);

            exit (EXIT_FAILURE);
        }

        /* get rid of any path information
           for the module name; */
        dbuf_init (&ext, 128);

        dbuf_splitPath (dbuf_c_str (&path), NULL, &ext);
        dbuf_destroy (&path);

        moduleNameBase = Safe_strdup (dbuf_c_str (&ext));
        moduleName = dbuf_detach (&ext);

        for (p = moduleName; *p; ++p)
            if (!isalnum ((unsigned char)*p))
                *p = '_';
        return;
    }

    /* if the extension is type .obj or .o additional object file will be passed to the linker */
    if ( STRCASECMP (extp, ".o") == 0 || STRCASECMP (extp, ".obj") == 0 )
    {
        dbuf_destroy (&ext);
        dbuf_destroy (&path);

        addSet (&objFilesSet, Safe_strdup (s));
        return;
    }

    if (STRCASECMP (extp, ".l") == 0 || STRCASECMP (extp, ".lib") == 0)
    {
        dbuf_destroy (&ext);
        dbuf_destroy (&path);

        addSet (&libFilesSet, Safe_strdup (s));
        return;
    }

    dbuf_destroy (&ext);
    dbuf_destroy (&path);

    werror (W_UNKNOWN_FEXT, s);
}

static void _setModel (int model, const char *sz)
{
    if (port->general.supported_models & model)
        options.model = model;
    else
        werror (W_UNSUPPORTED_MODEL, sz, port->target);
}

/* Gets the string argument to this option.  If the option is '--opt'
   then for input of '--optxyz' or '--opt xyz' returns xyz. */
char * getStringArg(const char *szStart, char **argv, int *pi, int argc)
{
    if (argv[*pi][strlen(szStart)])
    {
        return &argv[*pi][strlen(szStart)];
    }
    else
    {
        ++(*pi);
        if (*pi >= argc)
        {
            werror (E_ARGUMENT_MISSING, szStart);
            /* Die here rather than checking for errors later. */
            exit (EXIT_FAILURE);
        }
        else
        {
            return argv[*pi];
        }
    }
}

/** Gets the integer argument to this option using the same rules as
    getStringArg.
*/
int getIntArg(const char *szStart, char **argv, int *pi, int argc)
{
    char *p;
    int val;
    char *str = getStringArg(szStart, argv, pi, argc);

    val = strtol(str, &p, 0);
    if (p == str || *p != '\0')
    {
        werror (E_BAD_INT_ARGUMENT, szStart);
        /* Die here rather than checking for errors later. */
        exit (EXIT_FAILURE);
    }
    return val;
}

static void verifyShortOption(const char *opt)
{
    if (strlen(opt) != 2)
    {
        werror (W_EXCESS_SHORT_OPTIONS, opt);
    }
}

static bool tryHandleUnsupportedOpt(char **argv, int *pi)
{
    if (argv[*pi][0] == '-')
    {
        const char *longOpt = "";
        char shortOpt = -1;
        int i;

        if (argv[*pi][1] == '-')
        {
            /* Long option. */
            longOpt = argv[*pi];
        }
        else
        {
            shortOpt = argv[*pi][1];
        }
        for (i = 0; i < LENGTH(unsupportedOptTable); i++)
        {
            if (unsupportedOptTable[i].shortOpt == shortOpt ||
                    (longOpt && unsupportedOptTable[i].longOpt && !strcmp(unsupportedOptTable[i].longOpt, longOpt)))
            {
                /* Found an unsupported opt. */
                char buffer[100];
                SNPRINTF(buffer, sizeof(buffer),
                         "%s%c%c",
                         longOpt ? longOpt : "",
                         shortOpt ? '-' : ' ', shortOpt ? shortOpt : ' ');
                werror (W_UNSUPP_OPTION, buffer, unsupportedOptTable[i].message);
                return 1;
            }
        }
        /* Didn't find in the table */
        return 0;
    }
    else
    {
        /* Not an option, so can't be unsupported :) */
        return 0;
    }
}

static bool
scanOptionsTable(const OPTION *optionsTable, char shortOpt, const char *longOpt, char **argv, int *pi, int argc)
{
    int i;

    for (i = 0;
            optionsTable[i].shortOpt != 0 || optionsTable[i].longOpt != NULL
            || optionsTable[i].help != NULL;
            i++)
    {
        if (optionsTable[i].shortOpt == shortOpt)
        {
            if (optionsTable[i].pparameter != NULL)
            {
                verifyShortOption(argv[*pi]);

                (*(int *)optionsTable[i].pparameter)++;

                return TRUE;
            }
        }
        else
        {
            size_t len = optionsTable[i].longOpt ? strlen (optionsTable[i].longOpt) : 0;

            if (longOpt &&
                    (optionsTable[i].arg_type != CLAT_BOOLEAN ||
                     (optionsTable[i].arg_type == CLAT_BOOLEAN && len == strlen (longOpt) && optionsTable[i].longOpt)) &&
                    strncmp (optionsTable[i].longOpt, longOpt, len) == 0)
            {
                /* If it is a flag then we can handle it here */
                if (optionsTable[i].pparameter != NULL)
                {
                    switch (optionsTable[i].arg_type)
                    {
                    case CLAT_BOOLEAN:
                        (*(int *)optionsTable[i].pparameter)++;
                        break;

                    case CLAT_INTEGER:
                        *(int *)optionsTable[i].pparameter = getIntArg (optionsTable[i].longOpt, argv, pi, argc);
                        break;

                    case CLAT_STRING:
                        if (*(char **)optionsTable[i].pparameter)
                            Safe_free(*(char **)optionsTable[i].pparameter);
                        *(char **)optionsTable[i].pparameter = Safe_strdup (getStringArg (optionsTable[i].longOpt, argv, pi, argc));
                        break;

                    case CLAT_SET:
                        if (*(set **)optionsTable[i].pparameter)
                        {
                            deleteSet ((set **)optionsTable[i].pparameter);
                        }
                        setParseWithComma ((set **)optionsTable[i].pparameter, getStringArg (optionsTable[i].longOpt, argv, pi, argc));
                        break;

                    case CLAT_ADD_SET:
                        addSet((set **)optionsTable[i].pparameter, Safe_strdup (getStringArg (optionsTable[i].longOpt, argv, pi, argc)));
                        break;
                    }
                    return TRUE;
                }
                else
                {
                    /* Not a flag.  Handled manually later. */
                    return FALSE;
                }
            }
        }
    }
    /* Didn't find in the table */
    return FALSE;
}

static bool
tryHandleSimpleOpt(char **argv, int *pi, int argc)
{
    if (argv[*pi][0] == '-')
    {
        const char *longOpt = "";
        char shortOpt = -1;

        if (argv[*pi][1] == '-')
        {
            /* Long option. */
            longOpt = argv[*pi];
        }
        else
        {
            shortOpt = argv[*pi][1];
        }

        if (scanOptionsTable(optionsTable, shortOpt, longOpt, argv, pi, argc))
        {
            return TRUE;
        }
        else if (port && port->poptions &&
                 scanOptionsTable(port->poptions, shortOpt, longOpt, argv, pi, argc))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        /* Not an option, so can't be handled. */
        return FALSE;
    }
}

/*-----------------------------------------------------------------*/
/* parseCmdLine - parses the command line and sets the options     */
/*-----------------------------------------------------------------*/
static int
parseCmdLine (int argc, char **argv)
{
    int i;

    /* go thru all whole command line */
    for (i = 1; i < argc; i++)
    {
        if (i >= argc)
            break;

        /* check port specific options before general ones */
        if (port->parseOption (&argc, argv, &i) == TRUE)
        {
            continue;
        }

        if (tryHandleUnsupportedOpt(argv, &i) == TRUE)
        {
            continue;
        }

        if (tryHandleSimpleOpt(argv, &i, argc) == TRUE)
        {
            continue;
        }

        /* options */
        if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            if (strcmp (argv[i], OPTION_USE_STDOUT) == 0)
            {
                if (options.use_stdout == 0)
                {
                    options.use_stdout = 1;
                    dup2(STDOUT_FILENO, STDERR_FILENO);
                }
                continue;
            }
            if (strcmp (argv[i], OPTION_HELP) == 0)
            {
                printUsage ();
                exit (EXIT_SUCCESS);
            }

            if (strcmp (argv[i], OPTION_OUT_FMT_IHX) == 0)
            {
                options.out_fmt = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_OUT_FMT_S19) == 0)
            {
                options.out_fmt = 1;
                continue;
            }

            if (strcmp (argv[i], OPTION_LARGE_MODEL) == 0)
            {
                _setModel (MODEL_LARGE, argv[i]);
                continue;
            }

            if (strcmp (argv[i], OPTION_MEDIUM_MODEL) == 0)
            {
                _setModel (MODEL_MEDIUM, argv[i]);
                continue;
            }

            if (strcmp (argv[i], OPTION_SMALL_MODEL) == 0)
            {
                _setModel (MODEL_SMALL, argv[i]);
                continue;
            }

            if (strcmp (argv[i], OPTION_DUMP_ALL) == 0)
            {
                options.dump_rassgn =
                    options.dump_pack =
                        options.dump_range =
                            options.dump_kill =
                                options.dump_loop =
                                    options.dump_gcse =
                                        options.dump_raw = 1;
                continue;
            }

            if (strcmp (argv[i], OPTION_VERSION) == 0)
            {
                printVersionInfo (stdout);
                exit (EXIT_SUCCESS);
                continue;
            }

            if (strcmp (argv[i], OPTION_XRAM_SIZE) == 0)
            {
                options.xram_size = getIntArg(OPTION_XRAM_SIZE, argv, &i, argc);
                options.xram_size_set = TRUE;
                continue;
            }

            if (strcmp (argv[i], OPTION_NO_GCSE) == 0)
            {
                optimize.global_cse = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_NO_LOOP_INV) == 0)
            {
                optimize.loopInvariant = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_NO_LABEL_OPT) == 0)
            {
                optimize.label4 = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_NO_LOOP_IND) == 0)
            {
                optimize.loopInduction = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_OPT_CODE_SPEED) == 0)
            {
                optimize.codeSpeed = 1;
                optimize.codeSize = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_OPT_CODE_SIZE) == 0)
            {
                optimize.codeSpeed = 0;
                optimize.codeSize = 1;
                continue;
            }

            if (strcmp (argv[i], OPTION_LESS_PEDANTIC) == 0)
            {
                options.lessPedantic = 1;
                setErrorLogLevel(ERROR_LEVEL_WARNING);
                continue;
            }

            if (strcmp (argv[i], OPTION_DISABLE_WARNING) == 0)
            {
                int w = getIntArg(OPTION_DISABLE_WARNING, argv, &i, argc);
                if (w < MAX_ERROR_WARNING)
                {
                    setWarningDisabled(w);
                }
                continue;
            }

            if (strcmp (argv[i], OPTION_WERROR) == 0)
            {
                setWError(1);
                addSet(&preArgvSet, Safe_strdup("-Werror"));
                continue;
            }

            if (strcmp (&argv[i][1], OPTION_SHORT_IS_8BITS) == 0)
            {
                options.shortis8bits=1;
                continue;
            }

            if (strcmp (argv[i], OPTION_STD_C89) == 0)
            {
                options.std_c99 = 0;
                options.std_c51 = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_STD_C99) == 0)
            {
                options.std_c99 = 1;
                options.std_c51 = 0;
                continue;
            }

            if (strcmp (argv[i], OPTION_STD_C51_89) == 0)
            {
                options.std_c99 = 0;
                options.std_c51 = 1;
                continue;
            }

            if (strcmp (argv[i], OPTION_STD_C51_99) == 0)
            {
                options.std_c99 = 1;
                options.std_c51 = 1;
                continue;
            }

            if (strcmp (argv[i], OPTION_CODE_SEG) == 0)
            {
                struct dbuf_s segname;

                dbuf_init (&segname, 256);
                dbuf_printf (&segname, "%s", getStringArg (OPTION_CODE_SEG, argv, &i, argc));
                if (options.code_seg) Safe_free(options.code_seg);
                options.code_seg = dbuf_detach (&segname);
                continue;
            }

            if (strcmp (argv[i], OPTION_CONST_SEG) == 0)
            {
                struct dbuf_s segname;

                dbuf_init (&segname, 256);
                dbuf_printf (&segname, "%s", getStringArg (OPTION_CONST_SEG, argv, &i, argc));
                if (options.const_seg) Safe_free(options.const_seg);
                options.const_seg = dbuf_detach (&segname);
                continue;
            }

			if (strcmp (argv[i], OPTION_OVERLAY_TO) == 0)
            {
                struct dbuf_s segname;

                dbuf_init (&segname, 256);
                dbuf_printf (&segname, "%s", getStringArg (OPTION_OVERLAY_TO, argv, &i, argc));
                if (options.overlay_to) Safe_free(options.overlay_to);
                options.overlay_to = dbuf_detach (&segname);
                continue;
            }

            werror (W_UNKNOWN_OPTION, argv[i]);
            continue;
        }

        /* if preceded by  '-' then option */
        if (*argv[i] == '-')
        {
            switch (argv[i][1])
            {
            case 'h':
                verifyShortOption(argv[i]);

                printUsage ();
                exit (EXIT_SUCCESS);
                break;

            case 'm':
                /* Used to select the port. But this has already been done. */
                break;

            case 'p':
                /* Used to select the processor in port. But this has
                 * already been done. */
                break;

            case 'c':
                verifyShortOption(argv[i]);

                options.cc_only = 1;
                break;

            case 'L':
                addSet(&libPathsSet, Safe_strdup(getStringArg("-L", argv, &i, argc)));
                break;

            case 'l':
                addSet(&libFilesSet, Safe_strdup(getStringArg("-l", argv, &i, argc)));
                break;

            case 'o':
            {
                char *outName = getStringArg("-o", argv, &i, argc);
                size_t len = strlen(outName);

                /* point to last character */
                if (IS_DIR_SEPARATOR(outName[len - 1]))
                {
                    /* only output path specified */
                    dstPath = Safe_malloc(len);
                    memcpy(dstPath, outName, len - 1);
                    dstPath[len - 1] = '\0';
                    fullDstFileName = NULL;
                }
                else
                {
                    struct dbuf_s path;

                    dbuf_init (&path, 128);
                    fullDstFileName = Safe_strdup (outName);

                    /* get rid of the "."-extension */
                    dbuf_splitFile (outName, &path, NULL);

                    dbuf_c_str (&path);
                    dstFileName = dbuf_detach (&path);

                    dbuf_init (&path, 128);
                    /* strip module name to get path */
                    if (dbuf_splitPath (dstFileName, &path, NULL))
                    {
                        dbuf_c_str (&path);
                        dstPath = dbuf_detach (&path);
                    }
                    else
                        dbuf_destroy (&path);
                }
                break;
            }

            case 'W':
                /* pre-processer options */
                if (argv[i][2] == 'p')
                {
                    setParseWithComma(&preArgvSet, getStringArg("-Wp", argv, &i, argc));
                }
                /* linker options */
                else if (argv[i][2] == 'l')
                {
                    setParseWithComma(&linkOptionsSet, getStringArg("-Wl", argv, &i, argc));
                }
                /* assembler options */
                else if (argv[i][2] == 'a')
                {
                    setParseWithComma(&asmOptionsSet, getStringArg("-Wa", argv, &i, argc));
                }
                else
                {
                    werror (W_UNKNOWN_OPTION, argv[i]);
                }
                break;

            case 'v':
                verifyShortOption(argv[i]);

                printVersionInfo (stdout);
                exit (EXIT_SUCCESS);
                break;

                /* preprocessor options */
            case 'M':
            {
                preProcOnly = 1;
                if (argv[i][2] == 'M')
                    addSet(&preArgvSet, Safe_strdup("-MM"));
                else
                    addSet(&preArgvSet, Safe_strdup("-M"));
                break;
            }

            case 'd':
            case 'D':
            case 'I':
            case 'A':
            case 'U':
            {
                char sOpt = argv[i][1];
                char *rest;

                if (argv[i][2] == ' ' || argv[i][2] == '\0')
                {
                    i++;
                    if (i >= argc)
                    {
                        /* No argument. */
                        werror(E_ARGUMENT_MISSING, argv[i-1]);
                        break;
                    }
                    else
                    {
                        rest = argv[i];
                    }
                }
                else
                    rest = &argv[i][2];

                if (sOpt == 'Y')
                    sOpt = 'I';

                SNPRINTF (buffer, sizeof(buffer),
                          ((sOpt == 'I') ? "-%c\"%s\"": "-%c%s"), sOpt, rest);
                addSet(&preArgvSet, Safe_strdup(buffer));
                if(sOpt == 'I')
                {
                    addSet(&includeDirsSet, Safe_strdup(rest));
                    addSet(&userIncDirsSet, Safe_strdup(rest));
                }
            }
            break;

            default:
                werror (W_UNKNOWN_OPTION, argv[i]);
            }
            continue;
        }

        /* no option must be a filename */
        if (options.c1mode)
        {
            werror (W_NO_FILE_ARG_IN_C1, argv[i]);
        }
        else
        {
            processFile (argv[i]);
        }
    }

    // JCF: check if the .c sourcefile to compile has the main() function
    // JCF: check also if printf() or scanf() has a %[fFeEgG] in the format string.
    if (srcFile!=NULL)
    {
        char buffer[0x1000];
        char * s;
        int quote_match=0, main_match=0, comment1_match=0, comment2_match=0;
        int printf_match=0, bracket_match=0, percent_match=0;
        int j=1;
        fseek(srcFile, 0, SEEK_SET);

        while(fgets(buffer, sizeof(buffer), srcFile)!=NULL)
        {
            comment2_match=0;
            s=buffer;
            while(*s)
            {
                if(strncmp(s, "main", 4)==0)
                {
                    s+=4;
                    //printf("Line: %d, quotematch:%d,  comment1match:%d, comment2match:%d\n",
                    //	       j, quotematch, comment1match, comment2match);

                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        if(isspace(*s) || (*s=='(') || (*s=='/') ) main_match=1;
                    }
                }
                else if(strncmp(s, "printf_tiny", 11)==0)
                {
                    s+=11;
                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        if(isspace(*s) || (*s=='(') || (*s=='/') ) printf_match=1;
                    }
                }
                else if(strncmp(s, "printf", 6)==0)
                {
                    s+=6;
                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        if(isspace(*s) || (*s=='(') || (*s=='/') ) printf_match=1;
                    }
                }
                else if(strncmp(s, "scanf", 5)==0)
                {
                    s+=5;
                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        if(isspace(*s) || (*s=='(') || (*s=='/') ) printf_match=1;
                    }
                }
                else if(*s=='\"')
                {
                    s++;
                    quote_match=(quote_match==0)?1:0;
                    main_match=0;
                }
                else if (strncmp(s, "/*", 2)==0)
                {
                    s+=2;
                    comment1_match=1;
                }
                else if (strncmp(s, "*/", 2)==0)
                {
                    s+=2;
                    comment1_match=0;
                }
                else if (strncmp(s, "//", 2)==0)
                {
                    s+=2;
                    comment2_match=1;
                }
                else if(isspace(*s))
                {
                    s++;
                }
                else if (*s=='(')
                {
                    s++;
                    if ( (main_match==1) && (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        source_has_main_function=1;
                        //printf("Found main function at line %d\n", j);
                    }
                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        bracket_match=1;
                    }
                }
                else if(*s==')')
                {
                    s++;
                    if( (quote_match==0) && (comment1_match==0) && (comment2_match==0) )
                    {
                        bracket_match=0;
                        main_match=0;
                        printf_match=0;
                    }
                }
                else if(*s=='%')
                {
                    s++;
                    if( (bracket_match==1) && (printf_match==1) && (quote_match==1) )
                    {
                        percent_match=1;
                    }
                }
                else if ( (*s=='f') || (*s=='F') || (*s=='e') || (*s=='E') || (*s=='g') || (*s=='G') ) 
                {
                    s++;
                    if(percent_match==1)
                    {
                        options.printf_float=1; // Must link printf with floating point support
                        //printf("Found a float specifier in printf at line %d!\n", j);
                    }
                }
                else
                {
                    if ( ( (*s>='0') && (*s<='9') ) || (*s=='+') || (*s=='-') || (*s=='.') )
                    {
                        // '%' for float detection is still good!
                    }
                    else
                    {
                        percent_match=0;
                    }
                    if (comment1_match==0)
                    {
                        main_match=0;
                    }
                    s++;
                }
            }
            j++;
        }
        fseek(srcFile, 0, SEEK_SET);
    }

    /* some sanity checks in c1 mode */
    if (options.c1mode)
    {
        const char *s;

        if (fullSrcFileName)
        {
            fclose (srcFile);
            werror (W_NO_FILE_ARG_IN_C1, fullSrcFileName);
        }
        fullSrcFileName = NULL;
        for (s = setFirstItem(objFilesSet); s != NULL; s = setNextItem(objFilesSet))
        {
            werror (W_NO_FILE_ARG_IN_C1, s);
        }
        for (s = setFirstItem(libFilesSet); s != NULL; s = setNextItem(libFilesSet))
        {
            werror (W_NO_FILE_ARG_IN_C1, s);
        }
        deleteSet(&objFilesSet);
        deleteSet(&libFilesSet);

        if (options.cc_only || noAssemble || preProcOnly)
        {
            werror (W_ILLEGAL_OPT_COMBINATION);
        }
        options.cc_only = noAssemble = preProcOnly = 0;
        if (!dstFileName)
        {
            werror (E_NEED_OPT_O_IN_C1);
            exit (EXIT_FAILURE);
        }
        else
        {
            char *p;

            moduleName = Safe_strdup(dstFileName);
            for (p = moduleName; *p; ++p)
                if (!isalnum ((unsigned char)*p))
                    *p = '_';
        }
    }
    /* if no dstFileName given with -o, we've to find one: */
    if (!dstFileName)
    {
        const char *s;

        /* use the modulename from the C-source */
        if (fullSrcFileName)
        {
            struct dbuf_s path;

            if (*dstPath != '\0')
            {
                dbuf_init(&path, 128);
                dbuf_makePath (&path, dstPath, moduleNameBase);
                dbuf_c_str (&path);
                dstFileName = dbuf_detach (&path);
            }
            else
                dstFileName = Safe_strdup(moduleNameBase);
        }
        /* use the modulename from the first object file */
        else if ((s = peekSet(objFilesSet)) != NULL)
        {
            struct dbuf_s file;

            dbuf_init(&file, 128);

            /* get rid of the "."-extension */
            dbuf_splitFile (s, &file, NULL);

            dbuf_c_str (&file);
            s = dbuf_detach (&file);

            dbuf_init (&file, 128);

            dbuf_splitPath (s, NULL, &file);

            if (*dstPath != '\0')
            {
                struct dbuf_s path;

                dbuf_init(&path, 128);
                dbuf_makePath (&path, dstPath, dbuf_c_str (&file));
                dbuf_destroy (&file);
                dbuf_c_str (&path);
                dstFileName = dbuf_detach (&path);
            }
            else
            {
                dbuf_c_str (&file);
                dstFileName = dbuf_detach (&file);
            }
        }
        /* else no module given: help text is displayed */
    }

    /* set int, long and float reentrancy based on stack-auto */
    if (options.stackAuto)
    {
        options.intlong_rent++;
        options.float_rent++;
    }

    /* if debug option is set then open the cdbFile */
    if (options.debug && fullSrcFileName)
    {
        SNPRINTF (scratchFileName, sizeof(scratchFileName),
                  "%s.adb", dstFileName); /*JCF: Nov 30, 2002*/
        if(debugFile->openFile(scratchFileName))
            debugFile->writeModule(moduleName);
        else
            werror (E_FILE_OPEN_ERR, scratchFileName);
    }
    MSVC_style(options.vc_err_style);

    return 0;
}

/*-----------------------------------------------------------------*/
/* finalizeOptions - finalize (post-process( options               */
/*-----------------------------------------------------------------*/
static void
finalizeOptions (void)
{
    /* no peephole comments if not verbose asm */
    if (!options.verboseAsm)
        options.noPeepComments = 1;
}

/*-----------------------------------------------------------------*/
/* linkEdit : - calls the linkage editor  with options             */
/*-----------------------------------------------------------------*/
static void linkEdit (char **envp)
{
    FILE *lnkfile;
    char *c;
    int system_ret;
    const char *s;
    char linkerScriptFileName[PATH_MAX];

    linkerScriptFileName[0] = 0;
    c = NULL;

    /* first we need to create the <filename>.lkr file */
    SNPRINTF (linkerScriptFileName, sizeof(linkerScriptFileName), "%s.lkr", dstFileName);
    if (!(lnkfile = fopen (linkerScriptFileName, "w")))
    {
        werror (E_FILE_OPEN_ERR, linkerScriptFileName);
        exit (EXIT_FAILURE);
    }

    if(options.code_loc)
    {
        fprintf (lnkfile, "code_start=0x%04x\n", options.code_loc);
        if (options.code_size)
            fprintf (lnkfile, "code_end=0x%04x\n", options.code_loc+options.code_size);
    }

    if(options.data_loc)
    {
        fprintf (lnkfile, "data_start=0x%04x\n", options.data_loc);
    }

    if(options.idata_loc)
    {
        fprintf (lnkfile, "idata_start=0x%04x\n", options.idata_loc);
        if (options.iram_size)
            fprintf (lnkfile, "idata_end=0x%04x\n", options.idata_loc+options.iram_size);
    }

    if(options.xdata_loc)
    {
        fprintf (lnkfile, "xdata_start=0x%04x\n", options.xdata_loc);
        if (options.xram_size)
            fprintf (lnkfile, "xdata_end=0x%04x\n", options.xdata_loc+options.xram_size);
    }

    // if (options.debug) fprintf (lnkfile, "debug=1\n");


    // command line defined library paths if specified
    for (s = setFirstItem(libPathsSet); s != NULL; s = setNextItem(libPathsSet))
        fprintf (lnkfile, "path=%s\n", s);

    /* standard library path */
    if (!options.nostdlib)
    {
        switch (options.model)
        {
        case MODEL_SMALL:
            if (options.stackAuto)
                c = "small-stack-auto";
            else
                c = "small";
            break;

        case MODEL_MEDIUM:
            if (options.stackAuto)
                c = "medium-stack-auto";
            else
                c = "medium";
            break;

        case MODEL_LARGE:
            if (options.stackAuto)
                c = "large-stack-auto";
            else
                c = "large";
            break;

        default:
            werror (W_UNKNOWN_MODEL, __FILE__, __LINE__);
            c = "unknown";
            break;
        }

        for (s = setFirstItem(libDirsSet); s != NULL; s = setNextItem(libDirsSet))
            mfprintf (lnkfile, getRuntimeVariables(), "path=%s{sep}%s\n", s, c);
    }

    // command line defined library files if specified
    for (s = setFirstItem(libFilesSet); s != NULL; s = setNextItem(libFilesSet))
        fprintf (lnkfile, "lib=%s\n", s);

    // standard library files
	if (!options.nostdlib)
    {
        fprintf (lnkfile, "lib=%s.lib\n", STD_LIB);
        fprintf (lnkfile, "lib=%s.lib\n", STD_INT_LIB);
        fprintf (lnkfile, "lib=%s.lib\n", STD_LONG_LIB);
        fprintf (lnkfile, "lib=%s.lib\n", STD_FP_LIB);
    }

    /* Put in the object file, generated from the C cource */
    if (fullSrcFileName)
    {
        struct dbuf_s path;

        dbuf_init (&path, 128); // Why 128?
        dbuf_printf (&path, "%s.obj", dstFileName);
        addSetHead (&objFilesSet, dbuf_detach (&path));
    }

    // put in all object files
    for (s = setFirstItem(objFilesSet); s != NULL; s = setNextItem(objFilesSet))
        fprintf (lnkfile, "obj=%s\n", s);

    fclose (lnkfile);

    if (options.verbose) printf ("c51: Calling linker...\n");

    /* build linker output filename */
    if (fullDstFileName && !IS_SDASLD)
        strncpyz (scratchFileName, fullDstFileName, sizeof(scratchFileName));
    else
    {
        if (fullSrcFileName && !IS_SDASLD)
        {
            /* the linked file gets the name of the C source file name */
            strncpyz (scratchFileName, dstFileName, sizeof(scratchFileName));
        }
        else
        {
            /* the linked file gets the name of the first module */
            char *p;

            s = peekSet (objFilesSet);

            assert(s);

            strncpyz (scratchFileName, s, sizeof(scratchFileName));
            /* strip the extension */
            if (NULL == (p = strrchr (scratchFileName, '.')))
                p = strlen (scratchFileName) + scratchFileName;;
            *p = 0;
        }
        strncatz (scratchFileName, options.out_fmt ? ".s19" : ".ihx", sizeof(scratchFileName));
    }

    if (port->linker.cmd)
    {
        char buffer2[PATH_MAX];
        char buffer3[PATH_MAX];
        set *tempSet=NULL, *libSet=NULL;

        strcpy(buffer3, linkerScriptFileName);
        buildCmdLine (buffer2, port->linker.cmd, buffer3, scratchFileName, (libSet?joinStrSet(libSet):NULL), linkOptionsSet);

        buildCmdLine2 (buffer, sizeof(buffer), buffer2);
    }
    else
    {
        buildCmdLine2 (buffer, sizeof(buffer), port->linker.mcmd);
    }

    system_ret = my_system (buffer);

    if (system_ret)
    {
        exit (EXIT_FAILURE);
    }
}

/*-----------------------------------------------------------------*/
/* assemble - spawns the assembler with arguments                  */
/*-----------------------------------------------------------------*/
static void
assemble (char **envp)
{
    /* build assembler output filename */
    struct dbuf_s asmName;
    dbuf_init (&asmName, 128);

    /* -o option overrides default name? */
    if (options.cc_only && fullDstFileName)
    {
        dbuf_append_str (&asmName, fullDstFileName);
    }
    else
    {
        /* the assembled file gets the name of the first module */
        dbuf_printf (&asmName, "%s%s", dstFileName, port->linker.rel_ext);
    }

    if (port->assembler.do_assemble)
    {
        port->assembler.do_assemble (asmOptionsSet);
        return;
    }
    else if (port->assembler.cmd)
    {
        buildCmdLine (buffer, port->assembler.cmd, dstFileName, dbuf_c_str (&asmName),
                      options.debug ? port->assembler.debug_opts : port->assembler.plain_opts,
                      asmOptionsSet);
    }
    else
    {
        buildCmdLine2 (buffer, sizeof(buffer), port->assembler.mcmd);
    }

    if (my_system (buffer))
    {
        /* either system() or the assembler itself has reported an error
           perror ("Cannot exec assembler");
        */
        dbuf_destroy (&asmName);
        exit (EXIT_FAILURE);
    }

    if (IS_SDASLD && options.cc_only && fullDstFileName)
    {
        /* make some order in the mess remined behind sdas:
           move generated files to the output directory */
        dbuf_set_length (&asmName, 0);
        dbuf_printf (&asmName, "%s%s", dstFileName, port->linker.rel_ext);

        if (FILENAME_CMP (dbuf_c_str (&asmName), fullDstFileName))
        {
            remove (fullDstFileName);
            rename (dbuf_c_str(&asmName), fullDstFileName);
        }
    }

    dbuf_destroy (&asmName);
}

/*-----------------------------------------------------------------*/
/* preProcess - spawns the preprocessor with arguments             */
/*-----------------------------------------------------------------*/
static int
preProcess (char **envp)
{
    if (options.c1mode)
    {
        yyin = stdin;
    }
    else
    {
        const char *s;
        set *inclList = NULL;

        if (NULL != port->linker.rel_ext)
        {
#define OBJ_EXT_STR     "-obj-ext="
#define OBJ_EXT_LEN     ((sizeof OBJ_EXT_STR) - 1)
            char *buf = Safe_alloc(strlen(port->linker.rel_ext) + (OBJ_EXT_LEN + 1));
            strcpy(buf, OBJ_EXT_STR);
            strcpy(&buf[OBJ_EXT_LEN], port->linker.rel_ext);
            addSet(&preArgvSet, buf);
        }

        /* if using dollar signs in identifiers */
        if (options.dollars_in_ident)
            addSet(&preArgvSet, Safe_strdup("-fdollars-in-identifiers"));

        /* if using external stack define the macro */
        if (options.useXstack)
            addSet(&preArgvSet, Safe_strdup("-DC51_USE_XSTACK"));

        /* set the macro for stack autos  */
        if (options.stackAuto)
            addSet(&preArgvSet, Safe_strdup("-DC51_STACK_AUTO"));

        /* set the macro for stack autos  */
        if (options.stack10bit)
            addSet(&preArgvSet, Safe_strdup("-DC51_STACK_TENBIT"));

        /* set the macro for no overlay  */
        if (options.noOverlay)
            addSet(&preArgvSet, Safe_strdup("-DC51_NOOVERLAY"));

        if (options.unsigned_char)
            addSet(&preArgvSet, Safe_strdup("-DC51_CHAR_UNSIGNED"));

        /* set the macro for large model  */
        switch (options.model)
        {
        case MODEL_LARGE:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_LARGE"));
            break;
        case MODEL_SMALL:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_SMALL"));
            break;
        case MODEL_COMPACT:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_COMPACT"));
            break;
        case MODEL_MEDIUM:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_MEDIUM"));
            break;
        case MODEL_FLAT24:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_FLAT24"));
            break;
        case MODEL_PAGE0:
            addSet(&preArgvSet, Safe_strdup("-DC51_MODEL_PAGE0"));
            break;
        default:
            werror (W_UNKNOWN_MODEL, __FILE__, __LINE__);
            break;
        }

        /* set macro corresponding to compiler option */
        if (options.intlong_rent)
            addSet(&preArgvSet, Safe_strdup("-DC51_INT_LONG_REENT"));

        /* set macro corresponding to compiler option */
        if (options.float_rent)
            addSet(&preArgvSet, Safe_strdup("-DC51_FLOAT_REENT"));

        /* add C51 version number */
        {
            char buf[20];
            SNPRINTF(buf, sizeof(buf), "-DC51=%d%d%d",
                     C51_VERSION_HI, C51_VERSION_LO, C51_VERSION_P);
            addSet(&preArgvSet, Safe_strdup(buf));
            SNPRINTF(buf, sizeof(buf), "-D_C51=%d%d%d",
                     C51_VERSION_HI, C51_VERSION_LO, C51_VERSION_P);
            addSet(&preArgvSet, Safe_strdup(buf));
            SNPRINTF(buf, sizeof(buf), "-D__C51=%d%d%d",
                     C51_VERSION_HI, C51_VERSION_LO, C51_VERSION_P);
            addSet(&preArgvSet, Safe_strdup(buf));
         }

        /* add C51 revision number */
        {
            char buf[25];
            SNPRINTF(buf, sizeof(buf), "-DC51_REVISION=%s", getBuildNumber());
            addSet(&preArgvSet, Safe_strdup(buf));
        }

        /* add port (processor information to processor */
        addSet(&preArgvSet, Safe_strdup("-DC51_{port}"));
        addSet(&preArgvSet, Safe_strdup("-D__{port}"));

        /* tell pre-processor that this source has a main function */
        if(source_has_main_function==1)
            addSet(&preArgvSet, Safe_strdup("-DC51_HAS_MAIN_FUNCTION"));

        if (port && port->processor && TARGET_IS_PIC)
        {
            char proc[512];
            SNPRINTF(&proc[0], 512, "-DC51_PROCESSOR=\"%s\"", port->processor);
            addSet(&preArgvSet, Safe_strdup(proc));
        }

        /* standard include path */
        if (!options.nostdinc)
        {
            inclList = appendStrSet(includeDirsSet, "-isystem \"", "\"");
            mergeSets(&preArgvSet, inclList);
        }

        setMainValue("cppextraopts", (s = joinStrSet(preArgvSet)));
        Safe_free((void *)s);
        if (inclList != NULL)
            deleteSet(&inclList);

        if (preProcOnly && fullDstFileName)
        {
            /* -E and -o given */
            setMainValue ("cppoutfilename", fullDstFileName);
        }
        else
        {
            /* Piping: set cppoutfilename to NULL, to avoid empty quotes */
            setMainValue ("cppoutfilename", NULL);
        }

        if (options.verbose)
            printf ("c51: Calling preprocessor...\n");
        buildCmdLine2 (buffer, sizeof(buffer), _preCmd);

        if (preProcOnly)
        {
            if (my_system (buffer))
            {
                exit (EXIT_FAILURE);
            }

            exit (EXIT_SUCCESS);
        }

        yyin = my_popen (buffer);
        if (yyin == NULL)
        {
            perror ("Preproc file not found");
            exit (EXIT_FAILURE);
        }
    }

    return 0;
}

/* Set bin paths */
static void setBinPaths (const char *argv0)
{
    const char *p;
    char buf[PATH_MAX];

    /*
     * Search logic:
     *
     * 1. - $C51DIR/PREFIX2BIN_DIR
     * 2. - path(argv[0])
     * 3. - $PATH
     */

    /* do it in reverse mode, so that addSetHead() can be used
       instead of slower addSet() */

    if ((p = getBinPath (argv0)) != NULL)
        addSetHead (&binPathSet, (void *)p);

    if ((p = getenv (C51_DIR_NAME)) != NULL)
    {
        SNPRINTF (buf, sizeof buf, "%s" PREFIX2BIN_DIR, p);
        addSetHead (&binPathSet, Safe_strdup (buf));
    }
}

/* Set system include path */
static void setIncludePath (void)
{
    char *p;
    char *p2 = NULL;
    set *tempSet = NULL;

    /*
     * Search logic:
     *
     * 1. - $C51_INCLUDE/target
     * 2. - $C51_HOME/PREFIX2DATA_DIR/INCLUDE_DIR_SUFFIX/target
     * 3. - path(argv[0])/BIN2DATA_DIR/INCLUDE_DIR_SUFFIX/target
     * 4. - DATADIR/INCLUDE_DIR_SUFFIX/target (only on *nix)
     * 5. - $C51_INCLUDE
     * 6. - $C51_HOME/PREFIX2DATA_DIR/INCLUDE_DIR_SUFFIX
     * 7. - path(argv[0])/BIN2DATA_DIR/INCLUDE_DIR_SUFFIX
     * 8. - DATADIR/INCLUDE_DIR_SUFFIX (only on *nix)
     */

    if (options.nostdinc)
        return;

    tempSet = appendStrSet (dataDirsSet, NULL, INCLUDE_DIR_SUFFIX);
    includeDirsSet = appendStrSet (tempSet, NULL, DIR_SEPARATOR_STRING);
    includeDirsSet = appendStrSet (includeDirsSet, NULL, port->target);
    mergeSets (&includeDirsSet, tempSet);

    if ((p = getenv (C51_INCLUDE_NAME)) != NULL)
    {
        addSetHead(&includeDirsSet, p);
        p2=Safe_alloc(strlen(p)+strlen(DIR_SEPARATOR_STRING)+strlen(port->target)+1);
        if (p2 != NULL)
        {
            strcpy (p2, p);
            strcat (p2, DIR_SEPARATOR_STRING);
            strcat (p2, port->target);
            addSetHead (&includeDirsSet, p2);
        }
    }
}

/* Set system lib path */
static void setLibPath (void)
{
    char *p;

    /*
     * Search logic:
     *
     * 1. - $C51_LIB
     * 2. - $C51_HOME/PREFIX2DATA_DIR/LIB_DIR_SUFFIX/<model>
     * 3. - path(argv[0])/BIN2DATA_DIR/LIB_DIR_SUFFIX/<model>
     * 4. - DATADIR/LIB_DIR_SUFFIX/<model> (only on *nix)
     */

    if (options.nostdlib)
        return;

    libDirsSet = appendStrSet (dataDirsSet, NULL, LIB_DIR_SUFFIX);

    if ((p = getenv (C51_LIB_NAME)) != NULL)
        addSetHead (&libDirsSet, p);
}

/* Set data path */
static void setDataPaths (const char *argv0)
{
    const char *p;
    char buf[PATH_MAX];

    /*
     * Search logic:
     *
     * 1. - $C51_HOME/PREFIX2DATA_DIR
     * 2. - path(argv[0])/BIN2DATA_DIR
     * 3. - DATADIR (only on *nix)
     */

    if ((p = getenv (C51_DIR_NAME)) != NULL)
    {
        SNPRINTF (buf, sizeof buf, "%s" PREFIX2DATA_DIR, p);
        addSet (&dataDirsSet, Safe_strdup (buf));
    }

    if ((p = getBinPath (argv0)) != NULL)
    {
        SNPRINTF (buf, sizeof buf, "%s" BIN2DATA_DIR, p);
        Safe_free ((void *)p);
        addSet (&dataDirsSet, Safe_strdup(buf));
    }

#ifdef _WIN32
    if (peekSet (dataDirsSet) == NULL)
    {
        /* this should never happen... */
        wassertl (0, "Can't get binary path");
    }
#else
    addSet (&dataDirsSet, Safe_strdup (DATADIR));
#endif

    setIncludePath ();
    setLibPath ();
}

static void initValues (void)
{
    populateMainValues (_baseValues);
    setMainValue ("port", port->target);
    setMainValue ("objext", port->linker.rel_ext);
    setMainValue ("asmext", port->assembler.file_ext);

    setMainValue ("dstfilename", dstFileName);
    setMainValue ("fullsrcfilename", fullSrcFileName ? fullSrcFileName : "fullsrcfilename");

    if (options.cc_only && fullDstFileName)
        /* compile + assemble and -o given: -o specifies name of object file */
    {
        setMainValue ("objdstfilename", fullDstFileName);
    }
    else
    {
        setMainValue ("objdstfilename", "{stdobjdstfilename}");
    }
    if (fullDstFileName)
        /* if we're linking, -o gives the final file name */
    {
        setMainValue ("linkdstfilename", fullDstFileName);
    }
    else
    {
        setMainValue ("linkdstfilename", "{stdlinkdstfilename}");
    }

    /*
     * Make sure the preprocessor is called with the "-std" option
     * corresponding to the --std used to start c51
     */
    if (options.std_c99)
    {
        if (!options.std_c51)
            setMainValue ("cppstd", "-std=c99 ");
    }
    else
    {
        if (!options.std_c51)
            setMainValue ("cppstd", "-std=c89 ");
    }
}

static void doPrintSearchDirs (void)
{
    printf ("programs:\n");
    fputStrSet (stdout, binPathSet);

    printf ("datadir:\n");
    fputStrSet (stdout, dataDirsSet);

    printf ("includedir:\n");
    fputStrSet (stdout, includeDirsSet);

    printf ("libdir:\n");
    fputStrSet (stdout, libDirsSet);
    fputStrSet (stdout, libPathsSet);
}


static void sig_handler (int signal)
{
    char *sig_string;

    switch (signal)
    {
    case SIGABRT:
        sig_string = "SIGABRT";
        break;
    case SIGTERM:
        sig_string = "SIGTERM";
        break;
    case SIGINT:
        sig_string = "SIGINT";
        break;
    case SIGSEGV:
        sig_string = "SIGSEGV";
        break;
    default:
        sig_string = "Unknown?";
        break;
    }
    fprintf (stderr, "Caught signal %d: %s\n", signal, sig_string);
    exit (EXIT_FAILURE);
}

/*
 * main routine
 * initialises and calls the parser
 */

int main (int argc, char **argv, char **envp)
{
    /* turn all optimizations off by default */
    memset (&optimize, 0, sizeof (struct optimize));

    if (NUM_PORTS == 0)
    {
        fprintf (stderr, "Build error: no ports are enabled.\n");
        exit (EXIT_FAILURE);
    }

    /* install signal handler;
       it's only purpose is to call exit() to remove temp files */
    if (!getenv ("C51_LEAVE_SIGNALS"))
    {
        signal (SIGABRT, sig_handler);
        signal (SIGTERM, sig_handler);
        signal (SIGINT, sig_handler);
        signal (SIGSEGV, sig_handler);
    }

    /* Before parsing the command line options, do a
     * search for the port and processor and initialize
     * them if they're found. (We can't gurantee that these
     * will be the first options specified).
     */

    _findPort (argc, argv);
    _findProcessor (argc, argv);

    /* Initalise the port. */
    if (port->init)
        port->init ();

    setDefaultOptions ();
    parseCmdLine (argc, argv);

    if (options.verbose && NULL != port->processor)
        printf("Processor: %s\n", port->processor);

    initValues ();

    setBinPaths (argv[0]);
    setDataPaths (argv[0]);

    if (port->initPaths)
        port->initPaths();

    if (options.printSearchDirs)
        doPrintSearchDirs();

    /* if no input then printUsage & exit */
    if (!options.c1mode && !fullSrcFileName && peekSet(objFilesSet) == NULL)
    {
        if (options.printSearchDirs)
            exit (EXIT_SUCCESS);
        printUsage();
        exit (EXIT_FAILURE);
    }

    /* initMem() is expensive, but
       initMem() must called before port->finaliseOptions (). */
    initMem ();

    /* finalize target specific options */
    port->finaliseOptions ();

    /* finalize common options */
    finalizeOptions ();

    if (fullSrcFileName || options.c1mode)
    {
        preProcess (envp);

        initSymt ();
        initiCode ();
        initCSupport ();
        initBuiltIns();
        initPeepHole ();

        if (options.verbose) printf ("c51: Generating code...\n");

        yyparse ();

        if (!options.c1mode)
            if (pclose(yyin))
                fatalError = 1;

        if (fatalError)
            exit (EXIT_FAILURE);

        if (port->general.do_glue != NULL)
            (*port->general.do_glue) ();
        else
        {
            /* this shouldn't happen */
            assert (FALSE);
            /* in case of NDEBUG */
            glue ();
        }

        if (fatalError)
            exit (EXIT_FAILURE);

        if (!options.c1mode && !noAssemble)
        {
            if (options.verbose)
                printf ("c51: Calling assembler...\n");
            assemble (envp);
        }
    }
    closeDumpFiles();

    if (options.debug && debugFile)
        debugFile->closeFile ();

    if (!options.cc_only &&
            !fatalError &&
            !noAssemble &&
            !options.c1mode &&
            (fullSrcFileName || peekSet (objFilesSet) != NULL))
    {
        if (options.verbose)
            printf ("c51: Calling linker...\n");

        if (port->linker.do_link)
            port->linker.do_link ();
        else
            linkEdit (envp);
    }

    return 0;
}
